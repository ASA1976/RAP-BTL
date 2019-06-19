// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "procession.hpp"
#include "invocation.hpp"
#include "ration/contraction.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::procession;
using namespace ::invocation;
using namespace ::ration::contraction;

constexpr unsigned
    MaximumEvents = 127;

using EventSchedular = Contractional< unsigned, MaximumEvents, Contextual< unsigned > >;
using Demonstrative = void();

constexpr auto&
    EventVisitor = WriteIncrementDirection< unsigned, MaximumEvents, Contextual< unsigned > >;
constexpr Tractile< EventSchedular, unsigned, unsigned >
    EventContractor = Contractor< unsigned, MaximumEvents, Contextual< unsigned > >;

struct Coordinate {

    Invocative< bool, Referential< const Locational< const char > > >
        schedule_print_string;

    Invocative< bool, Referential< const Locational< const unsigned > > >
        schedule_print_natural;

    Invocative< bool, Referential< const Locational< Demonstrative > > >
        schedule_run_function;

};

static void
PrintString(
    const Locational< const void >
        locality,
    unsigned
        identifier
) {
    using Specific = Locational< const Locational< const char > >;
    const Locational< const char >
        text = Refer( static_cast< Specific >(locality) ).to;
    printf( "PrintString( '%s', %u )\n", text, identifier );
}

static void
PrintNatural(
    const Locational< const void >
        locality,
    unsigned 
        identifier
) {
    using Specific = Locational< const Locational< const unsigned > >;
    Referential< const unsigned >
        value = Refer( Refer( static_cast< Specific >(locality) ).to ).to;
    printf( "PrintNatural( %u, %u )\n", value, identifier );
}

static void
RunFunction(
    const Locational< const void >
        locality,
    unsigned
        identifier
) {
    using Specific = Locational< const Locational< Demonstrative > >;
    const Locational< Demonstrative >
        function = Refer( Refer( static_cast< Specific >(locality) ).to ).to;
    printf( "RunFunction( " );
    if (function)
        function();
    else
        printf( "null" );
    printf( ", %u )\n", identifier );
}

static void
Function1( void ) {
    printf( "Function1()" );
}

static void
Function2( void ) {
    printf( "Function2()" );
}

static inline void
ScheduleSampleEvents(
    Referential< const Coordinate >
        coordinator
) {
    static const Locational< const char >
        HelloLocality = "Hello world!",
        GoodbyeLocality = "Goodbye";
    static const Locational< Demonstrative >
        FirstObjective = Function1,
        SecondObjective = Function2,
        NullObjective = 0;
    static const unsigned
        QueueSize = sizeof(EventSchedular);
    static const Locational< const unsigned >
        QueueLocality = Locate( QueueSize ).at;
    printf( "Scheduling sample event(s), " );
    coordinator.schedule_print_string( HelloLocality );
    coordinator.schedule_run_function( FirstObjective );
    coordinator.schedule_print_natural( QueueLocality );
    coordinator.schedule_run_function( SecondObjective );
    coordinator.schedule_print_string( GoodbyeLocality );
    coordinator.schedule_run_function( NullObjective );
    puts( "finished." );
}

static inline void
ProcessEvents(
    Referential< const Invocative< bool, unsigned > >
        process_event
) {
    unsigned
        count;
    puts( "Processing event(s):" );
    puts( "--------------------" );
    for (count = 0; process_event( count ); count++);
    puts( "--------------------" );
    printf( "Processed %u event(s).\n", count );
}

int 
main() {
    EventSchedular
        event_queue;
    static auto&
        PreparePrintString = PrepareSchedule< EventSchedular, unsigned, unsigned, const char, EventContractor, unsigned >;
    static auto&
        PreparePrintNatural = PrepareSchedule< EventSchedular, unsigned, unsigned, const unsigned, EventContractor, unsigned >;
    static auto&
        PrepareRunFunction = PrepareSchedule< EventSchedular, unsigned, unsigned, Demonstrative, EventContractor, unsigned >;
    static auto&
        PrepareProcessEvent = PrepareProcessOneEvent< EventSchedular, unsigned, unsigned, EventContractor, unsigned >;
    auto
        PrintStringLambda = PreparePrintString( EventVisitor, event_queue, PrintString );
    auto
        PrintNaturalLambda = PreparePrintNatural( EventVisitor, event_queue, PrintNatural );
    auto
        RunFunctionLambda = PrepareRunFunction( EventVisitor, event_queue, RunFunction );
    auto
        ProcessEventLambda = PrepareProcessEvent( EventVisitor, event_queue );
    using PrintStringTypical = decltype(PrintStringLambda);
    using PrintNaturalTypical = decltype(PrintNaturalLambda);
    using RunFunctionTypical = decltype(RunFunctionLambda);
    using ProcessEventTypical = decltype(ProcessEventLambda);
    static auto&
        AssignPrintString = AssignInvokeProcedure< PrintStringTypical, bool, Referential< const Locational< const char > > >;
    static auto&
        AssignPrintNatural = AssignInvokeProcedure< PrintNaturalTypical, bool, Referential< const Locational< const unsigned > > >;
    static auto&
        AssignRunFunction = AssignInvokeProcedure< RunFunctionTypical, bool, Referential< const Locational< Demonstrative > > >;
    static auto&
        AssignProcessEvent = AssignInvokeProcedure< ProcessEventTypical, bool, unsigned >;
    const Locational< PrintStringTypical >
        PrintStringLocation = Locate( PrintStringLambda ).at;
    const Locational< PrintNaturalTypical >
        PrintNaturalLocation = Locate( PrintNaturalLambda ).at;
    const Locational< RunFunctionTypical >
        RunFunctionLocation = Locate( RunFunctionLambda ).at;
    const Locational< ProcessEventTypical >
        ProcessEventLocation = Locate( ProcessEventLambda ).at;
    const Coordinate
        coordinator = {
            AssignPrintString( PrintStringLocation ),
            AssignPrintNatural( PrintNaturalLocation ),
            AssignRunFunction( RunFunctionLocation )
        };
    Initialize( event_queue );
    ScheduleSampleEvents( coordinator );
    ProcessEvents( AssignProcessEvent( ProcessEventLocation ) );
}
