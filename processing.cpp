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

const unsigned
MaximumEvents = 127;

using EventSchedular = Contractional< unsigned, MaximumEvents, Contextual >;

constexpr Tractile< EventSchedular, unsigned, unsigned >
EventContractor = Contractor< unsigned, MaximumEvents, Contextual >;

constexpr Directional< EventSchedular, unsigned, unsigned, Contextual >
EventVisitor = WriteIncrementDirection< unsigned, MaximumEvents, Contextual >;

static void
PrintString(
    const Locational< void >
        location
) {
    using Specific = const Locational< const char >;
    printf( "%s\n", static_cast< Specific >(location) );
}

static void
PrintNatural(
    const Locational< void >
        location
) {
    using Specific = const Locational< const unsigned >;
    printf( "%u\n", Refer( static_cast< Specific >(location) ).to );
}

static void
RunFunction(
    const Locational< void >
        location
) {
    using Specific = const Locational< const FunctionSituational >;
    Refer( static_cast< Specific >(location) ).to();
}

static void
Demonstrate( void ) {
    puts( "Demonstrate()" );
}

struct {

    struct {

        Referential< Programmatic< EventSchedular, const char > >
            print_string;

        Referential< Programmatic< EventSchedular, const unsigned > >
            print_natural;

        Referential< Programmatic< EventSchedular, const FunctionSituational > >
            run_function;

    } schedule;
    
    Referential< Processive< EventSchedular > >
        process;

} Program = {
    {
        ScheduleNullRefused< EventSchedular, unsigned, unsigned, const char, EventContractor, EventVisitor, PrintString >,
        ScheduleNullRefused< EventSchedular, unsigned, unsigned, const unsigned, EventContractor, EventVisitor, PrintNatural >,
        ScheduleNullRefused< EventSchedular, unsigned, unsigned, const FunctionSituational, EventContractor, EventVisitor, RunFunction >
    },
    ProcessOneEvent< EventSchedular, unsigned, unsigned, EventContractor, EventVisitor >
};

int main() {
    static const Locational< const char >
        Hello = "Hello world!",
        Goodbye = "Goodbye";
    static const FunctionSituational
        Objective = Locate( Demonstrate ).at;
    static const unsigned
        QueueLength = sizeof(EventSchedular);
    EventSchedular
        event_queue;
    unsigned
        count;
    Initialize( event_queue );
    Program.schedule.print_string( event_queue, Hello );
    Program.schedule.print_natural( event_queue, Locate( QueueLength ).at );
    Program.schedule.run_function( event_queue, Locate( Objective ).at );
    Program.schedule.print_string( event_queue, Goodbye );
    puts( "Processing event(s):" );
    puts( "--------------------" );
    for (count = 0; Program.process( event_queue ); count++);
    puts( "--------------------" );
    printf( "Processed %u event(s).\n", count );
}
