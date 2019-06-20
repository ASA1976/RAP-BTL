// � 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "invocation.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::invocation;

extern "C" Abstract< void, const Invocative< void, unsigned > >
    call_from_c;
extern "C" Abstract< void, unsigned >
    c_function;

struct Class {

    void
    operator()(
        unsigned 
            value
    ) const {
        printf( "Class::operator()( %u ), C++ programming language.\n", value );
    }

    static void 
    Static(
        unsigned
            value
    ) {
        printf( "Class::Static( %u ), C++ programming language\n", value );
    }

    void 
    method(
        unsigned
            value
    ) const {
        printf( "Class::method( %u ), C++ programming language.\n", value );
    }

};

void
Function(
    unsigned
        value
) {
    printf( "Function( %u ), C++ programming language.\n", value );
}

int 
main() {
    const Class
        object;
    const char
        letter = 'A';
    auto
        lambda = [letter]( 
            unsigned 
                value 
        ) -> void {
            printf( "main::lambda['%c']( %u ), C++ programming language.\n", letter, value );
        };
    using ObjectTypical = decltype(object);
    using MethodLocational = decltype(&Class::method);
    using FunctionTypical = decltype(Function);
    using LambdaTypical = decltype(lambda);
    static auto&
        AssignFunction = AssignInvokeProcedure< FunctionTypical, void, unsigned >;
    static auto&
        AssignFunctor = AssignInvokeProcedure< ObjectTypical, void, unsigned >;
    static auto&
        AssignLambda = AssignInvokeProcedure< LambdaTypical, void, unsigned >;
    static auto&
        AssignMethod = AssignInvokeMethod< ObjectTypical, MethodLocational, void, unsigned >;
    static auto&
        AssignObject = AssignClassMethod< ObjectTypical, MethodLocational, void, unsigned >;
    call_from_c( AssignFunction( &c_function ) );
    call_from_c( AssignFunctor( &object ) );
    call_from_c( AssignFunction( &Class::Static ) );
    call_from_c( AssignMethod( AssignObject( &Class::method, object ) ) );
    call_from_c( AssignFunction( &Function ) );
    call_from_c( AssignLambda( &lambda ) );
}
