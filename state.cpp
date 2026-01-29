#include "state.h"

void reverse(state &state) {
    state = inverse(state);
}

state inverse(state state) {
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
