// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include <invocation.hpp>
#include <procession.hpp>
#include <ration/contraction.hpp>
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::location;
using namespace ::procession;
using namespace ::invocation;
using namespace ::ration::contraction;
constexpr unsigned MaximumEvents = 127;
using EventSchedular = Contractional<unsigned, MaximumEvents, Contextual<unsigned>>;
using Demonstrative = Abstract<void>;
using EventTractile = Tractile<EventSchedular, unsigned, unsigned>;
constexpr auto& EventVisitor = WriteIncrementDirection<unsigned, MaximumEvents, Contextual<unsigned>>;
constexpr EventTractile EventContractor = SureContractor<unsigned, MaximumEvents, Contextual<unsigned>>;
auto& PreparePrintString = PrepareSchedule<EventSchedular, unsigned, unsigned, const char, EventContractor, unsigned>;
auto& PreparePrintNatural = PrepareSchedule<EventSchedular, unsigned, unsigned, const unsigned, EventContractor, unsigned>;
auto& PrepareRunFunction = PrepareSchedule<EventSchedular, unsigned, unsigned, Demonstrative, EventContractor, unsigned>;
auto& PrepareProcessEvent = PrepareProcessOneEvent<EventSchedular, unsigned, unsigned, EventContractor, unsigned>;

struct Coordinate {

    Invocative<bool, Referential<const Locational<const char>>>
        schedule_print_string;

    Invocative<bool, Referential<const Locational<const unsigned>>>
        schedule_print_natural;

    Invocative<bool, Referential<const Locational<Demonstrative>>>
        schedule_run_function;
};

static void
PrintString(
    const Locational<const void>
        locality,
    unsigned
        identifier)
{
    using Specific = Locational<const Locational<const char>>;
    const Locational<const char> text = Refer(static_cast<Specific>(locality)).to;
    printf("PrintString( \"%s\", %u )\n", text, identifier);
}

static void
PrintNatural(
    const Locational<const void>
        locality,
    unsigned
        identifier)
{
    using Specific = Locational<const Locational<const unsigned>>;
    Referential<const unsigned> value = Refer(Refer(static_cast<Specific>(locality)).to).to;
    printf("PrintNatural( %u, %u )\n", value, identifier);
}

static void
RunFunction(
    const Locational<const void>
        locality,
    unsigned
        identifier)
{
    using Specific = Locational<const Locational<Demonstrative>>;
    const Locational<Demonstrative> function = Refer(Refer(static_cast<Specific>(locality)).to).to;
    printf("RunFunction( ");
    if (function)
        function();
    else
        printf("null");
    printf(", %u )\n", identifier);
}

static void
Function1()
{
    printf("Function1()");
}

static void
Function2()
{
    printf("Function2()");
}

static inline void
ScheduleSampleEvents(
    Referential<const Coordinate>
        coordinator)
{
    using namespace ::location;
    static const Locational<const char>
        HelloLocality = "Hello world!",
        GoodbyeLocality = "Goodbye";
    static const Locational<Demonstrative>
        FirstObjective = Function1,
        SecondObjective = Function2,
        NullObjective = 0;
    static const unsigned QueueSize = sizeof(EventSchedular);
    static const Locational<const unsigned> QueueLocality = Locate(QueueSize).at;
    printf("Scheduling sample event(s), ");
    coordinator.schedule_print_string(HelloLocality);
    coordinator.schedule_run_function(FirstObjective);
    coordinator.schedule_print_natural(QueueLocality);
    coordinator.schedule_run_function(SecondObjective);
    coordinator.schedule_print_string(GoodbyeLocality);
    coordinator.schedule_run_function(NullObjective);
    puts("finished.");
}

static inline void
ProcessSampleEvents(
    Referential<const Invocative<bool, unsigned>>
        process_event)
{
    unsigned count;
    puts("Processing event(s):");
    puts("--------------------");
    for (count = 0; process_event(count); count++)
        ;
    puts("--------------------");
    printf("Processed %u event(s).\n", count);
}

int main()
{
    EventSchedular event_queue;
    auto print_string_lambda = PreparePrintString(EventVisitor, event_queue, PrintString);
    auto print_natural_lambda = PreparePrintNatural(EventVisitor, event_queue, PrintNatural);
    auto run_function_lambda = PrepareRunFunction(EventVisitor, event_queue, RunFunction);
    auto process_event_lambda = PrepareProcessEvent(EventVisitor, event_queue);
    using PrintStringTypical = decltype(print_string_lambda);
    using PrintNaturalTypical = decltype(print_natural_lambda);
    using RunFunctionTypical = decltype(run_function_lambda);
    using ProcessEventTypical = decltype(process_event_lambda);
    static auto& AssignPrintString = AssignInvokeProcedure<PrintStringTypical, bool, Referential<const Locational<const char>>>;
    static auto& AssignPrintNatural = AssignInvokeProcedure<PrintNaturalTypical, bool, Referential<const Locational<const unsigned>>>;
    static auto& AssignRunFunction = AssignInvokeProcedure<RunFunctionTypical, bool, Referential<const Locational<Demonstrative>>>;
    static auto& AssignProcessEvent = AssignInvokeProcedure<ProcessEventTypical, bool, unsigned>;
    const Locational<PrintStringTypical> print_string_locality = &print_string_lambda;
    const Locational<PrintNaturalTypical> print_natural_locality = &print_natural_lambda;
    const Locational<RunFunctionTypical> run_function_locality = &run_function_lambda;
    const Locational<ProcessEventTypical> process_event_locality = &process_event_lambda;
    const Coordinate coordinator = {
        AssignPrintString(print_string_locality),
        AssignPrintNatural(print_natural_locality),
        AssignRunFunction(run_function_locality)
    };
    Initialize(event_queue);
    ScheduleSampleEvents(coordinator);
    ProcessSampleEvents(AssignProcessEvent(process_event_locality));
}
