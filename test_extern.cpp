// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include <functional>
#include "invocation.hpp"

using namespace ::std;
using namespace ::invocation;

void
TestExtern(
    Referential< const Invocative< void > >
        invoke
) {
    invoke();
}

void
TestExtern(
    Referential< const function< void() > >
        invoke
) {
    invoke();
}
