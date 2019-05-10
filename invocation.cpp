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
DemonstrateInvocation(
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
        AssignInvokeFunction = AssignInvokeProcedure< FunctionTypical, void, unsigned >;
    static auto&
        AssignInvokeLambda = AssignInvokeProcedure< LambdaTypical, void, unsigned >;
    static auto&
        AssignInvokeFunctor = AssignInvokeProcedure< ClassTypical, void, unsigned >;
    static auto&
        AssignInstanceMethod = AssignClassMethod< ClassTypical, MethodLocational, void, unsigned >;
    static auto&
        AssignInvokeInstance = AssignInvokeMethod< ClassTypical, MethodLocational, void, unsigned >;
    static const Locational< FunctionTypical >
        FunctionLocation = Locate( Function ).at;
    static const Locational< LambdaTypical >
        LambdaLocation = Locate( Lambda ).at;
    static const Locational< ClassTypical >
        FunctorLocation = Locate( Object ).at;
    static const Locational< FunctionTypical >
        StaticLocation = Locate( ClassTypical::Static ).at;
    static const Methodic< ClassTypical, MethodLocational, void, unsigned >
        MethodInstance = AssignInstanceMethod( &ClassTypical::instance, Object );
    DemonstrateInvocation( AssignInvokeFunction( FunctionLocation ) );
    DemonstrateInvocation( AssignInvokeLambda( LambdaLocation ) );
    DemonstrateInvocation( AssignInvokeFunctor( FunctorLocation ) );
    DemonstrateInvocation( AssignInvokeFunction( StaticLocation ) );
    DemonstrateInvocation( AssignInvokeInstance( MethodInstance ) );
}
