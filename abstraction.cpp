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

struct Class {

    void
    operator()(
        unsigned 
            value
    ) const {
        printf( "Class::operator()( %u )\n", value );
    }

    static void 
    Static(
        unsigned
            value
    ) {
        printf( "Class::Static( %u )\n", value );
    }

    void 
    method(
        unsigned
            value
    ) const {
        printf( "Class::method( %u )\n", value );
    }

}
    const Object;

static auto
Bind(
    const Locational< const char >
        identifier
) {
    auto 
        lambda = [identifier](
            unsigned
                value
        ) -> void {
            printf( "Bind::lambda[\"%s\"]( %u )\n", identifier, value );
        };
    return lambda;
}

auto
    LambdaA = Bind( "LambdaA" ),
    LambdaB = Bind( "LambdaB" );

void
Function( 
    unsigned 
        value 
) {
    printf( "Function( %u )\n", value );
}

static inline void
Demonstrate(
    Referential< Abstract< void, unsigned > >
        invoke
) {
    static unsigned 
        count = 0;
    invoke( ++count );
}

int 
main() {
    using LambdaTypical = decltype(LambdaA);
    using ObjectTypical = decltype(Object);
    using MethodLocational = decltype(&Class::method);
    static auto&
        WrapFunctor = AbstractProcedure< ObjectTypical, Object, void, unsigned >;
    static auto&
        WrapMethod = AbstractMethod< ObjectTypical, MethodLocational, Object, &Class::method, void, unsigned >;
    static auto&
        WrapLambdaA = AbstractProcedure< LambdaTypical, LambdaA, void, unsigned >;
    static auto&
        WrapLambdaB = AbstractProcedure< LambdaTypical, LambdaB, void, unsigned >;
    Demonstrate( WrapFunctor );
    Demonstrate( Class::Static );
    Demonstrate( WrapMethod );
    Demonstrate( WrapLambdaA );
    Demonstrate( WrapLambdaB );
    Demonstrate( Function );
}
