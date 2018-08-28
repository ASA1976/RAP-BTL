// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "procession.hpp"
#include "ration/contraction.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::procession;
using namespace ::ration::contraction;

using Natural = unsigned short;

const Natural
MaximumEvents = 127;

using EventContractional = Contractional< Natural, MaximumEvents, Contextual >;

constexpr Tractile< EventContractional, Natural, Natural >
EventContractor = Contractor< Natural, MaximumEvents, Contextual >;

constexpr Directional< EventContractional, Natural, Natural, Contextual >
EventVisitor = WriteIncrementDirection< Natural, MaximumEvents, Contextual >;

static inline void
PrintString(
    const Locational< void >
        location
) {
    using Contextual = const Locational< const char >;
    printf( "%s\n", (Contextual) location );
}

static inline void
PrintNatural(
    const Locational< void >
        location
) {
    using Contextual = const Locational< const Natural >;
    printf( "%u\n", *(Contextual) location );
}

int main() {
    static auto&
        SchedulePrintString = ScheduleNullRefused< EventContractional, Natural, Natural, const char, EventContractor, EventVisitor, PrintString >;
    static auto&
        SchedulePrintNatural = ScheduleNullRefused< EventContractional, Natural, Natural, const Natural, EventContractor, EventVisitor, PrintNatural >;
    static auto&
        ProcessEvent = Process< EventContractional, Natural, Natural, EventContractor, EventVisitor >;
    static const Locational< const char >
        Hello = "Hello world!",
        Goodbye = "Goodbye";
    static const Natural
        Size = sizeof( EventContractional );
    EventContractional
        queue;
    Initialize( queue );
    SchedulePrintString( queue, Hello );
    SchedulePrintNatural( queue, Locate( Size ).at );
    SchedulePrintString( queue, Goodbye );
    while (ProcessEvent( queue ));
}
