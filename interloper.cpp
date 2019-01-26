// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "abstraction.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::abstraction;
using namespace ::location;

void
Mangled(
    unsigned
        value
) {
    printf( "Mangled( %u ), C++ programming language.\n", value );
}

class ClassTypical {

public:

    void
    operator()(
        unsigned 
            value
    ) const {
        printf( "Functor( %u ), C++ programming language.\n", value );
    }

    static void 
    Static(
        unsigned
            value
    ) {
        printf( "Static( %u ), C++ programming language.\n", value );
    }

    void 
    instance(
        unsigned
            value
    ) const {
        printf( "instance( %u ), C++ programming language.\n", value );
    }

};

const auto
    Lambda = []( 
        unsigned 
            value 
    ) -> void {
        printf( "Lambda( %u ), C++ programming language.\n", value );
    };

const ClassTypical
    Object;

using LambdaTypical = decltype(Lambda);
using MethodLocational = decltype(&ClassTypical::instance);

extern "C" const Locational< Abstract< void, unsigned > >
    mangled_abstraction = Mangled,
    functor_abstraction = AbstractProcedure< const ClassTypical, Object, void, unsigned >,
    static_abstraction = ClassTypical::Static,
    lambda_abstraction = AbstractProcedure< LambdaTypical, Lambda, void, unsigned >,
    instance_abstraction = AbstractMethod< const ClassTypical, MethodLocational, Object, &ClassTypical::instance, void, unsigned >;
