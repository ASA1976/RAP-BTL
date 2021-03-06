/*
    � 2019 Aaron Sami Abassi
    Licensed under the Academic Free License version 3.0

    Instructions:

    First, compile eloper.c to an object file using a C compiler.
    Then compile and link interloper.cpp and the eloper object file with the C++
    compiler and linker.
    
    Example:

    clang -O -I../rap-btl -c eloper.c
    clang++ -O -I../rap-btl -o elope eloper.o interloper.cpp
    ./elope

*/
#define INVOCATIVE_TYPEDEF invocative_t
#define INVOCATIVE_RESULTANT void
#define INVOCATIVE_PARAMETRIC unsigned
#include <invocative.def>
#include <stdio.h>

void call_from_c(const invocative_t invocation)
{
    static unsigned count = 0;
    invocation.interface(invocation.locality, ++count);
}

void c_function(unsigned value)
{
    printf("c_function(%u), C programming language.\n", value);
}
