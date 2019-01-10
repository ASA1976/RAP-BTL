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

using FunctionTypical = void( unsigned );
using LambdaTypical = decltype(Lambda);
using MethodLocational = void(ClassTypical::*)( unsigned ) const;

auto&
    AssignFunction = AssignInvokeProcedure< FunctionTypical, void, unsigned >;
auto&
    AssignFunctor = AssignInvokeProcedure< const ClassTypical, void, unsigned >;
auto&
    AssignInstance = AssignInvokeMethod< const ClassTypical, MethodLocational, void, unsigned >;
auto&
    AssignLambda = AssignInvokeProcedure< LambdaTypical, void, unsigned >;
auto&
    AssignMethod = AssignMethodObjective< const ClassTypical, MethodLocational, void, unsigned >;
const ClassTypical
    Object;
const Locational< FunctionTypical >
    MangledObjective = Locate( Mangled ).at;
const Locational< const ClassTypical >
    FunctorObjective = Locate( Object ).at;
const Locational< FunctionTypical >
    StaticObjective = Locate( ClassTypical::Static ).at;
const Methodic< const ClassTypical, MethodLocational, void, unsigned >
    InstanceObjective = AssignMethod( &ClassTypical::instance, Object );
const Locational< LambdaTypical >
    LambdaObjective = Locate( Lambda ).at;
extern "C" const Invocative< void, unsigned >
    mangled_invocation = AssignFunction( MangledObjective ),
    functor_invocation = AssignFunctor( FunctorObjective ),
    static_invocation = AssignFunction( StaticObjective ),
    instance_invocation = AssignInstance( InstanceObjective ),
    lambda_invocation = AssignLambda( LambdaObjective );
