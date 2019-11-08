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
extern "C" void call_from_c(const Invocative<void, unsigned>);
extern "C" void c_function(unsigned);

struct Class {
    void operator()(unsigned value) const
    {
        printf("Class::operator()(%u), C++ programming language.\n", value);
    }
    static void StaticFunction(unsigned value)
    {
        printf("Class::StaticFunction(%u), C++ programming language\n", value);
    }
    void nonstatic_function(unsigned value) const
    {
        printf("Class::nonstatic_function(%u), C++ programming language.\n", value);
    }
};

void CPPFunction(unsigned value)
{
    printf("CPPFunction(%u), C++ programming language.\n", value);
}

int main()
{
    using MethodLocational = decltype(&Class::nonstatic_function);
    static auto Lambda = [](unsigned value) -> void {
        printf("main::Lambda(%u), C++ programming language.\n", value);
    };
    static const Class Object;
    static auto& AssignFunction = AssignInvokeFunction<void, unsigned>;
    static auto& AssignFunctor = AssignInvokeProcedure<decltype(Object), void, unsigned>;
    static auto& AssignLambda = AssignInvokeProcedure<decltype(Lambda), void, unsigned>;
    static auto& AssignMethod = AssignInvokeMethod<decltype(Object), MethodLocational, void, unsigned>;
    static auto& AssignObject = AssignClassMethod<decltype(Object), MethodLocational, void, unsigned>;
    call_from_c(AssignFunction(&c_function));
    call_from_c(AssignFunctor(&Object));
    call_from_c(AssignFunction(&Class::StaticFunction));
    call_from_c(AssignMethod(AssignObject(&Class::nonstatic_function, Object)));
    call_from_c(AssignFunction(&CPPFunction));
    call_from_c(AssignLambda(&Lambda));
}
