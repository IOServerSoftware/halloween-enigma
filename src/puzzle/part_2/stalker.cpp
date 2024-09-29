#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <ctime>
#include <filesystem>
#include <thread>
#include <chrono>
#include <atomic>
#include "../puzzle.h"
#include "../../cfg/config.h"
#include "../../modules/external_functions.h"

namespace fs = std::filesystem;

void stalker(dpp::cluster& bot, const dpp::message_create_t& event, std::string& user_progress_path) {
    static std::atomic<bool> timer_running(false);        // Flag to check if the timer thread is running
    static std::atomic<bool> listener_running(false);     // Flag to check if the command listener thread is running
    static std::thread timer_thread;                      // Timer thread
    static std::thread command_listener_thread;           // Command listener thread

    int current = read_progress(user_progress_path);
    uint64_t seed = static_cast<uint64_t>(event.msg.author.id) + static_cast<uint64_t>(event.msg.channel_id) + static_cast<uint64_t>(std::time(0));

    if (current == 12 && !fs::exists(__user_progress_container(event.msg.author.id) + "_runcount.txt") && !fs::exists(__user_progress_container(event.msg.author.id) + "_requiredruns.txt")) {
        event.send("```Could there be somebody watching you?```");

        std::ofstream run_counter(__user_progress_container(event.msg.author.id) + "_runcount.txt");
        run_counter << "0";
        run_counter.close();

        // Generate required number of "run" commands (between 10 and 30)
        std::mt19937 gen(seed);
        std::uniform_int_distribution<> distr(10, 30);
        int required_runs = distr(gen);

        std::ofstream required_runs_file(__user_progress_container(event.msg.author.id) + "_requiredruns.txt");
        required_runs_file << required_runs;
        required_runs_file.close();
    }

    if (current == 12 && fs::exists(__user_progress_container(event.msg.author.id) + "_runcount.txt") && fs::exists(__user_progress_container(event.msg.author.id) + "_requiredruns.txt")) {
        std::string runcount_file = __user_progress_container(event.msg.author.id) + "_runcount.txt";
        std::string requiredruns_file = __user_progress_container(event.msg.author.id) + "_requiredruns.txt";

        // Read required runs
        std::ifstream required_runs_in(requiredruns_file);
        int required_runs;
        required_runs_in >> required_runs;
        required_runs_in.close();

        // Check if timer and listener threads are already running
        if (!timer_running && !listener_running) {
            // Shared state
            std::atomic<int> runcount(0);
            std::atomic<bool> timer_expired(false);

            // Timer thread (only starts once)
            timer_running = true;  // Set the flag to indicate the timer is running
            timer_thread = std::thread([&bot, &event, &timer_expired]() {
                auto start_time = std::chrono::steady_clock::now();
                while (true) {
                    auto current_time = std::chrono::steady_clock::now();
                    std::chrono::duration<double> elapsed_seconds = current_time - start_time;

                    if (elapsed_seconds.count() > 20.0) {
                        // If 20 seconds pass, expire the timer
                        timer_expired = true;
                        timer_running = false;  // Reset the flag inside the thread, not as argument
                        event.send("```You took too long. The presence fades away...```");
                        break;
                    }

                    std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Sleep to avoid busy-waiting
                }
            });

            // Command listener thread (only starts once)
            listener_running = true;  // Set the flag to indicate the listener is running
            command_listener_thread = std::thread([&bot, &event, runcount_file, required_runs, &runcount, &timer_expired, &user_progress_path]() {
                while (!timer_expired && runcount < required_runs) {
                    std::string message_content = event.msg.content;

                    if (message_content == "run" || message_content == "Run" || message_content == "RUN") {
                        runcount++;

                        // Update the run counter file
                        std::ofstream run_counter(runcount_file, std::ofstream::trunc);
                        run_counter << runcount;
                        run_counter.close();

                        event.send("```You start running...```");

                        if (runcount >= required_runs) {
                            // If the required runs are met, increment progress
                            std::ifstream check_progress(user_progress_path);
                            increment_progress(user_progress_path, check_progress);
                            event.send("```You feel like you outran the presence... for now.```");
                            listener_running = false;  // Reset the flag inside the thread, not as argument
                            break;
                        }
                    }

                    std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Sleep to avoid busy-waiting
                }
            });
        }
    }

    // If the player successfully "runs" away, join the threads to ensure they complete
    if (timer_running && listener_running) {
        timer_thread.join();              // Wait for the timer to finish
        command_listener_thread.join();   // Wait for the command listener to finish
    }
}
