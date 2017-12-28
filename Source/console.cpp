//
// Created by jeandsmith on 12/28/17.
//

#include <cstdio>
#include "../Headers/console.h"


const void console::log(const char * msg){
    puts(msg);
    fflush(stdout);
}