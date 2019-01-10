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

typedef struct {
    void(*interface)( const void* const, unsigned );
    const void* objective;
} invocation_t;

static inline void demonstrate( invocation_t invocation )
{
    static unsigned count = 0;
    invocation.interface( invocation.objective, ++count );
}

extern const invocation_t
mangled_invocation, 
functor_invocation, 
static_invocation, 
instance_invocation, 
lambda_invocation;

int main() {
    puts( "Start of main function, C programming language." );
    demonstrate( mangled_invocation );
    demonstrate( functor_invocation );
    demonstrate( static_invocation );
    demonstrate( instance_invocation );
    demonstrate( lambda_invocation );
    puts( "End of main function, C programming language." );
}
