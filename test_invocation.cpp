// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "invocation.hpp"

using namespace ::invocation;

// Link with test_extern.cpp (only)
void CallInvocation( const Invocative<void>& );

template <typename Typical, typename Classificatory>
struct Conditional final {
    using Designative = Invocative<void>( const Classificatory& );
    Classificatory objective;
    Invocative<void> invoke;
    Conditional( const Classificatory objective, Designative& assign ) :
        objective{objective}, invoke{assign( this->objective )} {}
    Conditional( const Conditional<Typical, Classificatory>& copy ) : 
        objective{copy.objective}, invoke{copy.invoke.interface, &objective} {}
    constexpr operator const Invocative<void>&() const {return invoke;}
};

template <typename Typical>
static inline auto Produce( Typical& object ) 
{
    using Specific = Conditional<Typical, Typical*>;
    static auto& Assign = AssignInvokeProcedure<Typical, void>;
    return Specific( &object, Assign );
}

template <typename Typical, typename MethodLocational>
static inline auto Produce( Typical& object, MethodLocational method ) 
{
    using Specific = Conditional<Typical, Methodic<Typical, MethodLocational, void>>;
    static auto& Consign = AssignClassMethod<Typical, MethodLocational, void>;
    static auto& Assign = AssignInvokeMethod<Typical, MethodLocational, void>;
    return Specific( Consign( method, object ), Assign );
}

#define TEST_CALL CallInvocation
#define TEST_PRODUCE1 Produce<Test1Typical>
#define TEST_PRODUCE2 Produce<Test2Typical>
#define TEST_PRODUCE3 Produce<Test3Typical>
#define TEST_PRODUCE4 Produce<Test4Typical, Test4Methodic>
#include "test.conditions"
