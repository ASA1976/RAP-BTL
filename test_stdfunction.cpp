// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "test_conditions.hpp"
#include "location.hpp"
#include <functional>

using namespace ::location;
using namespace ::std;

using TestFunctional = function< void() >;

static inline void 
TestStatic(
    Referential< const TestFunctional >
        invoke
) {
    invoke();
}

void
TestExtern(
    Referential< const TestFunctional >
);

int
main() {
    TestStatic( TestFunctional( Test1 ) );
    TestStatic( TestFunctional( Test2 ) );
    TestStatic( TestFunctional( Test3 ) );
    TestExtern( TestFunctional( Test1 ) );
    TestExtern( TestFunctional( Test2 ) );
    TestExtern( TestFunctional( Test3 ) );
}
