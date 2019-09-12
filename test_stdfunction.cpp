// � 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include <functional>

using namespace std;

// Link with test_extern.cpp (only)
void Invoke( const function<void()>& );

template <class Typical>
static inline function<void()> Produce( Typical& object ) 
{
    return object;
}

template <class Typical, class MethodLocational>
static inline function<void()> Produce( Typical& object, MethodLocational method ) 
{
    return bind( method, object );
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
