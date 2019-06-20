// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include <stdio.h>

/* 

    Instructions:

    First, compile eloper.c to an object file using a C compiler.
    Then compile and link interloper.cpp and the eloper object file with the C++
    compiler and linker.
    
    Example:

    clang -O -c eloper.c
    clang++ -O -o elope eloper.o interloper.cpp
    ./elope

*/

struct invocative_s {

    void (*interface)( const void* const, unsigned );
    const void* locality;

};

void call_from_c( const struct invocative_s invocation )
{
    static unsigned count = 0;
    invocation.interface( invocation.locality, ++count );
}

void c_function( unsigned value )
{
    printf( "c_function( %u ), C programming language.\n", value );
}
