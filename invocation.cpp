// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "abstraction.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::abstraction;

static void
Function( 
    unsigned 
        value 
) {
    printf( "Function( %u )\n", value );
}

auto
Lambda = []( 
    unsigned 
        value 
) -> void {
    printf( "Lambda( %u )\n", value );
};

class ClassTypical {

public:

    void operator()(
        unsigned 
            value
    ) {
        printf( "Object( %u )\n", value );
    }

    static void Static(
        unsigned
            value
    ) {
        printf( "ClassTypical::Static( %u )\n", value );
    }

    void instance(
        unsigned
            value
    ) {
        printf( "Object.instance( %u )\n", value );
    }

}
Object;

using FunctionTypical = Abstract< void, unsigned >;
using LambdaTypical = decltype(Lambda);

auto&
CreateInvokeFunction = CreateInvokeProcedure< FunctionTypical, void, unsigned >;

auto&
CreateInvokeLambda = CreateInvokeProcedure< LambdaTypical, void, unsigned >;

auto&
CreateInvokeFunctor = CreateInvokeProcedure< ClassTypical, void, unsigned >;

auto&
CreateInvokeInstance = CreateInvokeMethod< ClassTypical, void, unsigned >;

auto&
CreateInstanceObjective = CreateMethodObjective< ClassTypical, void, unsigned >;

const Locational< FunctionTypical >
FunctionObjective = Locate( Function ).at;

const Locational< LambdaTypical >
LambdaObjective = Locate( Lambda ).at;

const Locational< ClassTypical >
FunctorObjective = Locate( Object ).at;

const Locational< FunctionTypical >
StaticObjective = Locate( ClassTypical::Static ).at;

const Methodic< ClassTypical, void, unsigned >
InstanceObjective = CreateInstanceObjective( &ClassTypical::instance, Object );

const auto
FunctionCall = PrepareInvocation( CreateInvokeFunction( FunctionObjective ) ),
LambdaCall = PrepareInvocation( CreateInvokeLambda( LambdaObjective ) ),
FunctorCall = PrepareInvocation( CreateInvokeFunctor( FunctorObjective ) ),
StaticCall = PrepareInvocation( CreateInvokeFunction( StaticObjective ) ),
InstanceCall = PrepareInvocation( CreateInvokeInstance( InstanceObjective ) );

using CallTypical = decltype(FunctionCall);

static inline void
Demonstrate(
    Referential< const CallTypical >
        call
) {
    static unsigned 
        count = 0;
    call( ++count );
}

int 
main() {
    Demonstrate( FunctionCall );
    Demonstrate( LambdaCall );
    Demonstrate( FunctorCall );
    Demonstrate( StaticCall );
    Demonstrate( InstanceCall );
}
