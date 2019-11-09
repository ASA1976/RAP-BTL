// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include "abstraction.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::abstraction;
using namespace ::location;

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

static auto Bind(const Locational<const char> identifier)
{
    auto lambda = [identifier](unsigned value) -> void {
        printf("Bind::lambda[");
        if (identifier)
            printf("\"%s\"", identifier);
        else
            printf("null");
        printf("](%u)\n", value);
    };
    return lambda;
}

void Function(unsigned value)
{
    printf("Function(%u)\n", value);
}

static inline void
Demonstrate(Referential<Abstract<void, unsigned>> invoke)
{
    static unsigned count = 0;
    invoke(++count);
}

const Class Object;
auto LambdaNull = Bind(0), LambdaNamed = Bind("Named");

int main()
{
    using MemberLocational = decltype(&Class::nonstatic_function);
    static auto& WrapFunctor = AbstractProcedure<decltype(Object), Object, void, unsigned>;
    static auto& WrapMethod = AbstractMethod<decltype(Object), MemberLocational, Object, &Class::nonstatic_function, void, unsigned>;
    static auto& WrapLambdaNull = AbstractProcedure<decltype(LambdaNull), LambdaNull, void, unsigned>;
    static auto& WrapLambdaNamed = AbstractProcedure<decltype(LambdaNamed), LambdaNamed, void, unsigned>;
    Demonstrate(WrapFunctor);
    Demonstrate(Class::StaticFunction);
    Demonstrate(WrapMethod);
    Demonstrate(WrapLambdaNull);
    Demonstrate(WrapLambdaNamed);
    Demonstrate(Function);
}
