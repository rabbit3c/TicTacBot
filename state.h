#pragma once
#include <iostream>
using namespace std;

enum state {
    NONE,
    CROSS,
    CIRCLE
};

state reverse(state state);

string stateToString(state state);