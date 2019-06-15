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
