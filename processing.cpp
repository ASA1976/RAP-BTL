// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "procession.hpp"
#include "ration/contraction.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::location;
using namespace ::ration::contraction;
using namespace ::procession;

using Demonstrative = void();

constexpr unsigned
    MaximumEvents = 127;

using EventSchedular = Contractional< unsigned, MaximumEvents, Contextual< unsigned > >;

template <
    typename PrintStringTypical,
    typename PrintNaturalTypical,
    typename RunFunctionTypical
>
struct Coordinate {

    PrintStringTypical
        schedule_print_string;

    PrintNaturalTypical
        schedule_print_natural;

    RunFunctionTypical
        schedule_run_function;

};

constexpr Tractile< EventSchedular, unsigned, unsigned >
    EventContractor = Contractor< unsigned, MaximumEvents, Contextual< unsigned > >;

constexpr auto&
    EventVisitor = WriteIncrementDirection< unsigned, MaximumEvents, Contextual< unsigned > >;

constexpr auto&
    PrepareProcessEvent = PrepareProcessOneEvent< EventSchedular, unsigned, unsigned, EventContractor, unsigned >;

template <
    typename ...LambdaTypical
>
static inline Coordinate< LambdaTypical... >
InitializeCoordinator(
    LambdaTypical...
        lambdas
) {
    const Coordinate< LambdaTypical... >
        coordinator = {lambdas...};
    return coordinator;
}

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

static inline auto
PrepareCoordinator(
    Referential< EventSchedular >
        schedule
) {
    static auto&
        PreparePrintString = PrepareSchedule< EventSchedular, unsigned, unsigned, const char, EventContractor, unsigned >;
    static auto&
        PreparePrintNatural = PrepareSchedule< EventSchedular, unsigned, unsigned, const unsigned, EventContractor, unsigned >;
    static auto&
        PrepareRunFunction = PrepareSchedule< EventSchedular, unsigned, unsigned, Demonstrative, EventContractor, unsigned >;
    auto
        print_string = PreparePrintString( EventVisitor, schedule, PrintString );
    auto
        print_natural = PreparePrintNatural( EventVisitor, schedule, PrintNatural );
    auto
        run_function = PrepareRunFunction( EventVisitor, schedule, RunFunction );
    return InitializeCoordinator( print_string, print_natural, run_function );
}

static void
Function1( void ) {
    printf( "Function1()" );
}

static void
Function2( void ) {
    printf( "Function2()" );
}

template <
    typename ...LambdaTypical
>
static inline void
ScheduleEvents(
    Referential< const Coordinate< LambdaTypical... > >
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
    printf( "Scheduling event(s), " );
    coordinator.schedule_print_string( HelloLocality );
    coordinator.schedule_run_function( FirstObjective );
    coordinator.schedule_print_natural( QueueLocality );
    coordinator.schedule_run_function( SecondObjective );
    coordinator.schedule_print_string( GoodbyeLocality );
    coordinator.schedule_run_function( NullObjective );
    puts( "finished." );
}

template <
    typename ProcessEventTypical
>
static inline void
ProcessEvents(
    Referential< const ProcessEventTypical >
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
    const auto
        coordinator = PrepareCoordinator( event_queue );
    const auto
        process_event = PrepareProcessEvent( EventVisitor, event_queue );
    Initialize( event_queue );
    ScheduleEvents( coordinator );
    ProcessEvents( process_event );
}
