// © 2020 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include <automation.hpp>
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::automation;

int main()
{
    const auto automaton = Automate([]{ 
        puts("Now running lambda expression."); 
    });
    puts("Now at the end of main.");
}
