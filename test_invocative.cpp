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
    using Test4Typical = decltype(Test4);
    using RunLocational = decltype(&Test4Typical::run);
    static auto& 
        AssignTest1 = AssignInvokeProcedure< decltype(Test1), void >;
    static auto& 
        AssignTest2 = AssignInvokeProcedure< decltype(Test2), void >;
    static auto& 
        AssignTest3 = AssignInvokeProcedure< decltype(Test3), void >;
    static auto& 
        AssignTest4 = AssignInvokeMethod< Test4Typical, RunLocational, void >;
    static auto& 
        AssignRun = AssignClassMethod< Test4Typical, RunLocational, void >;
    TestStatic( AssignTest1( &Test1 ) );
    TestStatic( AssignTest2( &Test2 ) );
    TestStatic( AssignTest3( &Test3 ) );
    TestStatic( AssignTest4( AssignRun( &Test4Typical::run, Test4 ) ) );
    TestExtern( AssignTest1( &Test1 ) );
    TestExtern( AssignTest2( &Test2 ) );
    TestExtern( AssignTest3( &Test3 ) );
    TestExtern( AssignTest4( AssignRun( &Test4Typical::run, Test4 ) ) );
}
