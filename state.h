#pragma once
#include <iostream>
using namespace std;

enum state {
    NONE,
    CROSS,
    CIRCLE
};

void reverse(state &state);

string stateToString(state state);