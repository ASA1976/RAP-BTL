// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include <stdio.h>

/* 

    Instructions:

    First, compile interloper.cpp to an object file using a C++ compiler.
    Then compile and link eloper.c and the interloper object file with the C 
    compiler.
    
    Example:

    clang++ -O -c interloper.cpp
    clang -O -o elope interloper.o eloper.c
    ./elope

*/

typedef void(*abstract_t)( unsigned ) ;

static inline void demonstrate( const abstract_t procedure )
{
    static unsigned count = 0;
    procedure( ++count );
}

extern const abstract_t
mangled_abstraction, 
functor_abstraction, 
static_abstraction, 
instance_abstraction, 
lambda_abstraction;

int main() {
    puts( "Start of main function, C programming language." );
    demonstrate( mangled_abstraction );
    demonstrate( functor_abstraction );
    demonstrate( static_abstraction );
    demonstrate( instance_abstraction );
    demonstrate( lambda_abstraction );
    puts( "End of main function, C programming language." );
}
