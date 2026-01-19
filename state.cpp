#include "state.h"

state reverse(state state) {
    switch (state) {
        case CROSS:
            return CIRCLE;
        case CIRCLE:
            return CROSS;
        default:
            return NONE;
    }
}

string stateToString(state state) {
    switch (state) {
        case CROSS:
            return "CROSS";
        case CIRCLE:
            return "CIRCLE";
        default:
            return "NONE";
    }
}
