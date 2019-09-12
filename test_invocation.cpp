// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "invocation.hpp"

using namespace ::invocation;

// Link with test_extern.cpp (only)
void Invoke( const Invocative<void>& );

template <typename Typical, typename Classificatory>
struct Conditional final {
    using Designative = Invocative<void>( const Classificatory& );
    Classificatory objective;
    Invocative<void> invoke;
    Conditional( const Classificatory objective, Designative& assign ) 
    {
        this->objective = objective;
        invoke = assign( this->objective );
    }
    Conditional( const Conditional<Typical, Classificatory>& copy ) 
    {
        objective = copy.objective;
        invoke.locality = &objective;
        invoke.interface = copy.invoke.interface;
    }
    constexpr operator const Invocative<void>&() const {return invoke;}
};

template <typename Typical>
static inline auto Produce( Typical& object ) 
{
    using Classificatory = Typical*;
    using Specific = Conditional<Typical, Classificatory>;
    static auto& Assign = AssignInvokeProcedure<Typical, void>;
    return Specific( &object, Assign );
}

template <typename Typical, typename MethodLocational>
static inline auto Produce( Typical& object, MethodLocational method ) 
{
    using Classificatory = Methodic<Typical, MethodLocational, void>;
    using Specific = Conditional<Typical, Classificatory>;
    static auto& Consign = AssignClassMethod<Typical, MethodLocational, void>;
    static auto& Assign = AssignInvokeMethod<Typical, MethodLocational, void>;
    return Specific( Consign( method, object ), Assign );
}

#include "test.conditions"
int main()
{
    static auto& Produce1 = Produce<Test1Typical>;
    static auto& Produce2 = Produce<Test2Typical>;
    static auto& Produce3 = Produce<Test3Typical>;
    static auto& Produce4 = Produce<Test4Typical, Test4Methodic>;
    RunTests( Invoke, Produce1, Produce2, Produce3, Produce4 );
}
