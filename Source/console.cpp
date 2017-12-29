//
// Created by jeandsmith on 12/28/17.
//

#include <cstdio>
#include <cstdarg>
#include "../Headers/console.h"


const void console::log(const char *msg) {
    puts(msg);
    fflush(stdout);
}


int console::debug_log(const char *msg, ...) {
    va_list ap; // The macro to hold the list of arguments
    va_start(ap, msg); // Start the list and set is to be after the (msg) argument
    int rc = vfprintf(stdout, msg, ap); // Points to the list of arguments and the msg and pass
                                        // the data trough the stdout.
    puts("");
    va_end(ap); // End the list.
    return rc;
}