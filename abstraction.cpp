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

void
Function( 
    unsigned 
        value 
) {
    printf( "Function( %u )\n", value );
}

const auto
    Lambda = []( 
        unsigned 
            value 
    ) -> void {
        printf( "Lambda( %u )\n", value );
    };

class ClassTypical {

public:

    void
    operator()(
        unsigned 
            value
    ) {
        printf( "ClassTypical::operator()( %u )\n", value );
    }

    static void 
    Static(
        unsigned
            value
    ) {
        printf( "ClassTypical::Static( %u )\n", value );
    }

    void 
    instance(
        unsigned
            value
    ) {
        printf( "ClassTypical::instance( %u )\n", value );
    }

}
    Object;

static inline void
DemonstrateAbstraction(
    Referential< Abstract< void, unsigned > >
        invoke
) {
    static unsigned 
        count = 0;
    invoke( ++count );
}

int 
main() {
    using FunctionTypical = decltype(Function);
    using LambdaTypical = decltype(Lambda);
    using MethodLocational = decltype(&ClassTypical::instance);
    static auto&
        LambdaProcedure = AbstractProcedure< LambdaTypical, Lambda, void, unsigned >;
    static auto&
        FunctorProcedure = AbstractProcedure< ClassTypical, Object, void, unsigned >;
    static auto&
        InstanceMethod = AbstractMethod< ClassTypical, MethodLocational, Object, &ClassTypical::instance, void, unsigned >;
    DemonstrateAbstraction( Function );
    DemonstrateAbstraction( LambdaProcedure );
    DemonstrateAbstraction( FunctorProcedure );
    DemonstrateAbstraction( ClassTypical::Static );
    DemonstrateAbstraction( InstanceMethod );
}
