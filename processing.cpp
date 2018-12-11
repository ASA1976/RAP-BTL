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

using namespace ::location;
using namespace ::ration::contraction;
using namespace ::procession;

using FunctionDemonstrative = void( void );
using FunctionSituational = Locational< FunctionDemonstrative >;

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

auto&
EventVisitor = WriteIncrementDirection< unsigned, MaximumEvents, Contextual< unsigned > >;

static void
PrintString(
    const Locational< void >
        locality,
    unsigned
        identifier
) {
    using Specific = const Locational< const char >;
    printf( "PrintString( '%s', %u )\n", static_cast< Specific >(locality), identifier );
}

static void
PrintNatural(
    const Locational< void >
        locality,
    unsigned 
        identifier
) {
    using Specific = const Locational< const unsigned >;
    printf( "PrintNatural( %u, %u )\n", Refer( static_cast< Specific >(locality) ).to, identifier );
}

static void
RunFunction(
    const Locational< void >
        locality,
    unsigned
        identifier
) {
    using Specific = const Locational< const FunctionSituational >;
    const FunctionSituational
        function = Refer( static_cast< Specific >(locality) ).to;
    printf( "RunFunction( " );
    if (function)
        function();
    else
        printf( "null" );
    printf( ", %u )\n", identifier );
}

static void
Function1( void ) {
    printf( "Function1" );
}

static void
Function2( void ) {
    printf( "Function2" );
}

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

static inline auto
PrepareCoordinator(
    Referential< EventSchedular >
        schedule
) {
    static auto&
        PreparePrintString = PrepareScheduleNullRefused< EventSchedular, unsigned, unsigned, const char, EventContractor, unsigned >;
    static auto&
        PreparePrintNatural = PrepareScheduleNullRefused< EventSchedular, unsigned, unsigned, const unsigned, EventContractor, unsigned >;
    static auto&
        PrepareRunFunction = PrepareScheduleNullRefused< EventSchedular, unsigned, unsigned, const FunctionSituational, EventContractor, unsigned >;
    auto
        print_string = PreparePrintString( EventVisitor, schedule, PrintString );
    auto
        print_natural = PreparePrintNatural( EventVisitor, schedule, PrintNatural );
    auto
        run_function = PrepareRunFunction( EventVisitor, schedule, RunFunction );
    return InitializeCoordinator( print_string, print_natural, run_function );
}

template <
    typename ...LambdaTypical
>
static inline void
Demonstrate(
    Referential< const Coordinate< LambdaTypical... > >
        coordinator
) {
    static const Locational< const char >
        HelloLocality = "Hello world!",
        GoodbyeLocality = "Goodbye";
    static const FunctionSituational
        FirstObjective = Function1,
        SecondObjective = Function2;
    static const unsigned
        QueueSize = sizeof(EventSchedular);
    coordinator.schedule_print_string( HelloLocality );
    coordinator.schedule_run_function( Locate( FirstObjective ).at );
    coordinator.schedule_print_natural( Locate( QueueSize ).at );
    coordinator.schedule_run_function( Locate( SecondObjective ).at );
    coordinator.schedule_print_string( GoodbyeLocality );
}

int 
main() {
    static auto&
        ProcessEvent = ProcessOneEvent< EventSchedular, unsigned, unsigned, EventContractor, unsigned >;
    EventSchedular
        event_queue;
    unsigned
        count;
    const auto
        coordinator = PrepareCoordinator( event_queue );
    Initialize( event_queue );
    Demonstrate( coordinator );
    puts( "Processing event(s):" );
    puts( "--------------------" );
    for (count = 0; ProcessEvent( EventVisitor, event_queue, count ); count++);
    puts( "--------------------" );
    printf( "Processed %u event(s).\n", count );
}
