//
// Created by jeandsmith on 12/28/17.
//

#include <string>
#include <streambuf>
#include <iostream>
#include "../Headers/input_check.h"
#include "../Headers/console.h"

std::string input_check::format_string(std::string &input) {
    console::log("formatting()");
    if (input.empty()) { //If the first index is a null ending character
        input = "Null";
        return input;
    }

    // Eliminate all white spaces
    for (size_t i = input.size() - 1; input[i]; --i) {
        if (input[i] != ' ') { break; }
        else {
            puts("Erasing");
            input.erase(static_cast<unsigned long>(input[i]));
        }
    }

    for (char & c : input) {
        if (c == static_cast<char>(toupper(c))) { continue; }
        puts("lowering");
        c = static_cast<char>(tolower(c));
    }

    console::debug_log("Formatted: %s", input.c_str());
    return input;
}
