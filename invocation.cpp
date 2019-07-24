// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include "invocation.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::invocation;

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

};

void
Function( 
    unsigned 
        value 
) {
    printf( "Function( %u )\n", value );
}

static inline void
Demonstrate(
    Referential< const Invocative< void, unsigned > >
        invoke
) {
    static unsigned 
        count = 0;
    invoke( ++count );
}

int 
main() {
    static auto
        lambda = []( 
            unsigned 
                value 
        ) -> void {
            printf( "main::lambda( %u )\n", value );
        };
    const Class
        object;
    using ObjectTypical = decltype(object);
    using MethodLocational = decltype(&Class::method);
    using LambdaTypical = decltype(lambda);
    static auto&
        AssignLambda = AssignInvokeProcedure< LambdaTypical, void, unsigned >;
    static auto&
        AssignFunctor = AssignInvokeProcedure< ObjectTypical, void, unsigned >;
    static auto&
        AssignMethod = AssignInvokeMethod< ObjectTypical, MethodLocational, void, unsigned >;
    static auto&
        AssignObject = AssignClassMethod< ObjectTypical, MethodLocational, void, unsigned >;
    Demonstrate( AssignFunctor( &object ) );
    Demonstrate( AssignInvokeFunction( &Class::Static ) );
    Demonstrate( AssignMethod( AssignObject( &Class::method, object ) ) );
    Demonstrate( AssignInvokeFunction( &Function ) );
    Demonstrate( AssignLambda( &lambda ) );
}
