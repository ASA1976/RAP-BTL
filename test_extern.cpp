// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "invocation.hpp"
#include <functional>

using TestInvocative = ::invocation::Invocative<void>;
using TestFunctional = ::std::function<void()>;

void CallInvocation(const TestInvocative& call)
{
    call();
}

void CallFunction(const TestFunctional& call)
{
    call();
}
