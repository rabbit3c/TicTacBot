#include "state.h"

void reverse(state &state) {
    switch (state) {
        case CROSS:
            state = CIRCLE;
            return;
        case CIRCLE:
            state = CROSS;
            return;
        default:
            return;
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
