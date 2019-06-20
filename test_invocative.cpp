// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "test.conditions"
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
        AssignFunctor = AssignInvokeProcedure< decltype(Test1), void >;
    static auto& 
        AssignLambda = AssignInvokeProcedure< decltype(Test2), void >;
    static auto& 
        AssignObject = AssignInvokeMethod< Test4Typical, RunLocational, void >;
    static auto& 
        AssignMethod = AssignClassMethod< Test4Typical, RunLocational, void >;
    TestStatic( AssignFunctor( &Test1 ) );
    TestStatic( AssignLambda( &Test2 ) );
    TestStatic( AssignInvokeFunction( &Test3 ) );
    TestStatic( AssignObject( AssignMethod( &Test4Typical::run, Test4 ) ) );
    TestExtern( AssignFunctor( &Test1 ) );
    TestExtern( AssignLambda( &Test2 ) );
    TestExtern( AssignInvokeFunction( &Test3 ) );
    TestExtern( AssignObject( AssignMethod( &Test4Typical::run, Test4 ) ) );
}
