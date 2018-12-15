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

struct {

    void operator()(
        unsigned 
            value
    ) {
        printf( "Functor( %u )\n", value );
    }

}
Functor;

auto
Lambda = []( 
    unsigned 
        value 
) -> void {
    printf( "Lambda( %u )\n", value );
};

static void
Function( 
    unsigned 
        value 
) {
    printf( "Function( %u )\n", value );
}

using FunctionTypical = Abstract< void, unsigned >;
using LambdaTypical = decltype(Lambda);
using FunctorTypical = decltype(Functor);

const Locational< FunctionTypical >
FunctionObjective = Locate( Function ).at;

const Locational< LambdaTypical >
LambdaObjective = Locate( Lambda ).at;

const Locational< FunctorTypical >
FunctorObjective = Locate( Functor ).at;

auto&
CreateInvokeFunction = CreateInvocation< FunctionTypical, void, unsigned >;

auto&
CreateInvokeLambda = CreateInvocation< LambdaTypical, void, unsigned >;

auto&
CreateInvokeFunctor = CreateInvocation< FunctorTypical, void, unsigned >;

const auto
FunctionCall = PrepareInvocation( CreateInvokeFunction( FunctionObjective ) ),
LambdaCall = PrepareInvocation( CreateInvokeLambda( LambdaObjective ) ),
FunctorCall = PrepareInvocation( CreateInvokeFunctor( FunctorObjective ) );

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

int main() {
    Demonstrate( FunctionCall );
    Demonstrate( LambdaCall );
    Demonstrate( FunctorCall );
    Demonstrate( FunctionCall );
    Demonstrate( LambdaCall );
    Demonstrate( FunctorCall );
}
