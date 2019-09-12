// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "invocation.hpp"
#include <functional>

using TestInvocative = ::invocation::Invocative<void>;
using TestFunctional = ::std::function<void()>;

void Invoke( const TestInvocative& invoke ) 
{
    invoke();
}

void Invoke( const TestFunctional& invoke ) 
{
    invoke();
}
