// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "invocation.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::invocation;

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
    using FunctionTypical = decltype(Function);
    using LambdaTypical = decltype(Lambda);
    using MethodLocational = decltype(&ClassTypical::instance);
    static auto&
        AssignFunction = AssignInvokeProcedure< FunctionTypical, void, unsigned >;
    static auto&
        AssignLambda = AssignInvokeProcedure< LambdaTypical, void, unsigned >;
    static auto&
        AssignFunctor = AssignInvokeProcedure< ClassTypical, void, unsigned >;
    static auto&
        AssignMethod = AssignClassMethod< ClassTypical, MethodLocational, void, unsigned >;
    static auto&
        AssignInstance = AssignInvokeMethod< ClassTypical, MethodLocational, void, unsigned >;
    Demonstrate( AssignFunction( Locate( Function ).at ) );
    Demonstrate( AssignLambda( Locate( Lambda ).at ) );
    Demonstrate( AssignFunctor( Locate( Object ).at ) );
    Demonstrate( AssignFunction( Locate( ClassTypical::Static ).at ) );
    Demonstrate( AssignInstance( AssignMethod( &ClassTypical::instance, Object ) ) );
}
