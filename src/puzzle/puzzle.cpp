#include "puzzle.h"

PuzzleStatus get_status(int progress) {
    switch (progress) {
        case 1: return START;
        case 2: return BLACKBIRD;
        case 3: return DEAD_EYE;
        case 4: return NOTHING_IS_WHAT_IT_SEEMS;
        case 5: return HALLUCINATIONS;
        case 6: return SHE_IS_HERE;
        case 7: return GRAVESTONE;
        case 8: return SUSPICION;
        case 9: return FORGOTTEN;
        case 10: return LOGON;
        case 11: return LIES;
        case 12: return STALKER;
        case 13: return SIX_FEET;
        case 14: return MOSAIC_PREVALENCE;
        case 15: return THERE_IS_NOTHING_FOR_ME_TO_WANT;
        case 16: return RED_SNOW;
        case 17: return SOMEONE_IS_WAITING;
        case 18: return NO_SENSE_OF_SELF;
        case 19: return YOU_DO_NOT_MAKE_SENSE;
        case 20: return I_FOUND_HER_QUESTION_MARK;
        case 21: return WHO_IS_SHE;
        case 22: return WHAT_ARE_YOU;
        case 23: return WHERE_IS_SHE;
        case 24: return WHY_WOULD_YOU_DO_THIS;
        case 25: return YOU_HAVE_GOT_TO_STOP;
        case 26: return DO_NOT_LET_HIM_ESCAPE;
        case 27: return NICOLE_DIES;
        case 28: return ONE_LAST_PUZZLE;
        case 29: return FINAL_CONFRONTATION_PT_1;
        case 30: return FINAL_CONFRONTATION_PT_2;
        case 31: return FINAL_CONFRONTATION_PT_3;
        case 32: return FINAL_CONFRONTATION_PT_4;
        case 33: return FINAL_CONFRONTATION_PT_5;
        case 34: return FINAL_CONFRONTATION_PT_6;
        case 35: return NICOLE_IS_SAVED;
        case 36: return THIS_IS_NOT_THE_LAST_OF_ME;
        case 37: return THERE_IS_ANOTHER;
        default: return NOT_STARTED;
    }
}