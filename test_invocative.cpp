// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "test_conditions.hpp"
#include "invocation.hpp"

using namespace ::invocation;

using TestInvocative = Invocative< void >;

static inline void 
TestStatic(
    Referential< const TestInvocative >
        invoke
) {
    invoke();
}

void
TestExtern(
    Referential< const TestInvocative >
);

int
main() {
    static auto&
        AssignTest1 = AssignInvokeProcedure< decltype(Test1), void >;
    static auto&
        AssignTest2 = AssignInvokeProcedure< decltype(Test2), void >;
    static auto&
        AssignTest3 = AssignInvokeProcedure< decltype(Test3), void >;
    TestStatic( AssignTest1( Locate( Test1 ).at ) );
    TestStatic( AssignTest2( Locate( Test2 ).at ) );
    TestStatic( AssignTest3( Locate( Test3 ).at ) );
    TestExtern( AssignTest1( Locate( Test1 ).at ) );
    TestExtern( AssignTest2( Locate( Test2 ).at ) );
    TestExtern( AssignTest3( Locate( Test3 ).at ) );
}
