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
AssignInvokeFunction = AssignInvokeProcedure< FunctionTypical, void, unsigned >;

auto&
AssignInvokeLambda = AssignInvokeProcedure< LambdaTypical, void, unsigned >;

auto&
AssignInvokeFunctor = AssignInvokeProcedure< ClassTypical, void, unsigned >;

auto&
AssignInvokeInstance = AssignInvokeMethod< ClassTypical, void, unsigned >;

auto&
AssignInstanceObjective = AssignMethodObjective< ClassTypical, void, unsigned >;

const Locational< FunctionTypical >
FunctionObjective = Locate( Function ).at;

const Locational< LambdaTypical >
LambdaObjective = Locate( Lambda ).at;

const Locational< ClassTypical >
FunctorObjective = Locate( Object ).at;

const Locational< FunctionTypical >
StaticObjective = Locate( ClassTypical::Static ).at;

const Methodic< ClassTypical, void, unsigned >
InstanceObjective = AssignInstanceObjective( &ClassTypical::instance, Object );

const Invocative< void, unsigned >
InvokeFunction = AssignInvokeFunction( FunctionObjective ),
InvokeLambda = AssignInvokeLambda( LambdaObjective ),
InvokeFunctor = AssignInvokeFunctor( FunctorObjective ),
InvokeStatic = AssignInvokeFunction( StaticObjective ),
InvokeInstance = AssignInvokeInstance( InstanceObjective );

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
    Demonstrate( InvokeFunction );
    Demonstrate( InvokeLambda );
    Demonstrate( InvokeFunctor );
    Demonstrate( InvokeStatic );
    Demonstrate( InvokeInstance );
}
