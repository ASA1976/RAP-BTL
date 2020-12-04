// © 2020 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include <invocation.hpp>
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::invocation;

struct Class {
    void operator()(unsigned value) const
    {
        printf("Class::operator()(%u)\n", value);
    }
    static void StaticFunction(unsigned value)
    {
        printf("Class::StaticFunction(%u)\n", value);
    }
    void nonstatic_function(unsigned value) const
    {
        printf("Class::nonstatic_function(%u)\n", value);
    }
};

void Function(unsigned value)
{
    printf("Function(%u)\n", value);
}

static inline void
Demonstrate(Referential<const Invocative<void, unsigned>> invoke)
{
    static unsigned count = 0;
    invoke(++count);
}

int main()
{
    using MemberLocational = decltype(&Class::nonstatic_function);
    static auto Lambda = [](unsigned value) -> void {
        printf("main::lambda(%u)\n", value);
    };
    static const Class Object;
    static auto& AssignFunction = AssignInvokeFunction<void, unsigned>;
    static auto& AssignLambda = AssignInvokeProcedure<decltype(Lambda), void, unsigned>;
    static auto& AssignFunctor = AssignInvokeProcedure<const Class, void, unsigned>;
    static auto& AssignMethod = AssignInvokeMethod<const Class, MemberLocational, void, unsigned>;
    static auto& AssignObject = AssignClassMethod<const Class, MemberLocational>;
    // These durations are sufficient for immediate callback
    Demonstrate(AssignFunctor(&Object));
    Demonstrate(AssignFunction(&Class::StaticFunction));
    Demonstrate(AssignMethod(AssignObject(&Class::nonstatic_function, Object)));
    Demonstrate(AssignFunction(&Function));
    Demonstrate(AssignLambda(&Lambda));
}
