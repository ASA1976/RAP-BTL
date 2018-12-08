// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef PROCESSION_MODULE
#define PROCESSION_MODULE
#include "traction.hpp"
#include "trajection.hpp"
#include "association.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

/**
 * @brief   
 *     Trivial event processing facilitation.
 * @details 
 *     Association
 *     -----------
 *     Trivial event processing abstracts, classifier and management 
 *     facilitation functions.  Both stacks and queues can be used with the 
 *     facilitator functions.  If a queue is used, the increment direction 
 *     should be specified as the visitor.  If a stack is used, the decrement 
 *     direction should be specified as the visitor.
 */
namespace procession {

    using ::location::Locational;
    using ::location::Referential;
    using ::trajection::Directional;
    using ::traction::Tractile;
    using ::association::Complementary;

    /**
     * @brief 
     *     Function type which represents an event function.
     * @details 
     *     Abstraction
     *     -----------
     *     Function type alias used as the event call interface.  Functions
     *     which implement this contract receive their event data as a void
     *     pointer and are expected to run the event when called.
     */
    template <
        typename ...Parametric
    >
    using Contractual = void(
        const Locational< void >
            locality,
        Parametric...
            arguments
    );

    /**
     * @brief   
     *     Event schedule classifier.
     * @details 
     *     Classification
     *     --------------
     *     This type alias is used to represent an event in a schedule.  It 
     *     associates the event function (relator) with the event data (value) 
     *     using their respective memory locations.  Care should be used to 
     *     ensure the event data remains in scope until after the event function
     *     has been invoked.
     */
    template <
        typename ...Parametric
    >
    using Contextual = Complementary< Locational< Contractual< Parametric... > >, Locational< void > >;

    /**
     * @brief
     *     Event scheduling abstract.
     * @details 
     *     Abstraction Template
     *     --------------------
     *     This function type alias is used to declare functions which schedule
     *     events for later processing.
     * @tparam Schedular
     *     Type of the event schedule.
     * @tparam Subjective 
     *     Type of the event data.
     */
    template <
        typename Schedular,
        typename Subjective
    >
    using Programmatic = bool(
        Referential< Schedular >
            schedule,
        const Locational< Subjective >
            locality
    );

    /**
     * @brief 
     *     Function type which simplifies declaration syntax.
     * @details 
     *     Abstraction Template
     *     --------------------
     *     Function type alias used to declare functions which process 
     *     scheduled events.
     * @tparam Schedular
     *     Type of the event schedule.
     */
    template <
        typename Schedular
    >
    using Processive = bool(
        Referential< Schedular >
            schedule
    );

    /**
     * @brief 
     *     Schedules an event which can omit a data location.
     * @details
     *     Function Template
     *     -----------------
     *     Schedules an event which may omit event data, in a container space 
     *     using the provided contractor objective.
     * @tparam Schedular
     *     Type of the schedule.
     * @tparam Positional
     *     Type of positions to events in the schedule.
     * @tparam Natural
     *     Type of natural integer used by the schedule.
     * @tparam Subjective 
     *     Type of the event data (function type not allowed).
     * @tparam Contractor 
     *     Objective reference used to add events into the schedule.
     * @tparam Visitor
     *     Objective reference used to retrieve events from the schedule.
     * @tparam Function
     *     Function reference to the function invoked during the event.
     * @param[in,out] schedule 
     *     Reference to the schedule. 
     * @param[in] subject
     *     Optional location of the event data passed to the event function.
     * @return
     *     True if the event was successfully scheduled.
     */
    template <
        typename Schedular,
        typename Positional,
        typename Natural,
        typename Subjective,
        Referential< const Tractile< Schedular, Positional, Natural > >
            Contractor,
        typename ...Parametric
    >
    static inline bool
    ScheduleNullAccepted(
        Referential< const Directional< Schedular, Positional, Natural, Contextual< Parametric... > > >
            visitor,
        Referential< Schedular >
            schedule,
        Referential< Contractual< Parametric... > >
            function,
        const Locational< Subjective >
            subject
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static_assert(
            !is_function< Subjective >::value,
            "Subjective:  Function type not allowed, use pointer to function type instead"
        );
#endif
        Positional
            position;
        if (!Contractor.protract( schedule, position, 1 ))
            return false;
        Referential< Contextual< Parametric... > >
            event = visitor.scale.go( schedule, position ).to;
        event.value = (Locational< void >) subject;
        event.relator = function;
        return true;
    }

    /**
     * @brief 
     *     Prepares a lambda expression which schedules an event which can omit
     *     a data location.
     * @details
     *     Function Template
     *     -----------------
     *     Prepares a lambda expression which schedules an event which may omit 
     *     event data, in a container space using the provided contractor 
     *     objective.
     * @tparam Schedular
     *     Type of the schedule.
     * @tparam Positional
     *     Type of positions to events in the schedule.
     * @tparam Natural
     *     Type of natural integer used by the schedule.
     * @tparam Subjective 
     *     Type of the event data (function type not allowed).
     * @tparam Contractor 
     *     Objective reference used to add events into the schedule.
     * @tparam Visitor
     *     Objective reference used to retrieve events from the schedule.
     * @tparam Function
     *     Function reference to the function invoked during the event.
     * @param[in] schedule 
     *     Reference to the schedule. 
     * @return
     *     The instance of the lambda expression.
     */
    template <
        typename Schedular,
        typename Positional,
        typename Natural,
        typename Subjective,
        Referential< const Tractile< Schedular, Positional, Natural > >
            Contractor,
        typename ...Parametric
    >
    static inline auto
    PrepareScheduleNullAccepted(
        Referential< const Directional< Schedular, Positional, Natural, Contextual< Parametric... > > >
            visitor,
        Referential< Schedular >
            schedule,
        Referential< Contractual< Parametric... > >
            function
    ) {
        static auto&
            ScheduleEvent = ScheduleNullAccepted< Schedular, Positional, Natural, Subjective, Contractor, Parametric... >;
        auto 
            Lambda = [&visitor, &schedule, &function]( 
                const Locational< Subjective > 
                    subject 
            ) {
                return ScheduleEvent( visitor, schedule, function, subject );
            };
        return Lambda;
    }

    /**
     * @brief 
     *     Schedules an event which can not omit a data location.
     * @details
     *     Function Template
     *     -----------------
     *     Schedules an event which may not omit event data, in a container 
     *     space using the provided contractor objective.
     * @tparam Schedular
     *     Type of the schedule.
     * @tparam Positional
     *     Type of positions to events in the schedule.
     * @tparam Natural
     *     Type of natural integer used by the schedule.
     * @tparam Subjective 
     *     Type of the event data (function type not allowed).
     * @tparam Contractor 
     *     Objective reference used to add events into the schedule.
     * @tparam Visitor
     *     Objective reference used to retrieve events from the schedule.
     * @tparam Function
     *     Function reference to the function invoked during the event.
     * @param[in,out] schedule 
     *     Reference to the schedule. 
     * @param[in] subject
     *     Optional location of the event data passed to the event function.
     * @return
     *     True if the event was successfully scheduled.
     */
    template <
        typename Schedular,
        typename Positional,
        typename Natural,
        typename Subjective,
        Referential< const Tractile< Schedular, Positional, Natural > >
            Contractor,
        typename ...Parametric
    >
    static inline bool
    ScheduleNullRefused(
        Referential< const Directional< Schedular, Positional, Natural, Contextual< Parametric... > > >
            visitor,
        Referential< Schedular >
            schedule,
        Referential< Contractual< Parametric... > >
            function,
        const Locational< Subjective >
            subject
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static_assert(
            !is_function< Subjective >::value,
            "Subjective:  Function type not allowed, use pointer to function type instead"
        );
#endif
        static auto&
            Schedule = ScheduleNullAccepted< Schedular, Positional, Natural, Subjective, Contractor, Parametric... >;
        if (subject == 0)
            return false;
        return Schedule( visitor, schedule, function, subject );
    }

    /**
     * @brief 
     *     Prepares a lambda expression which schedules an event which can not 
     *     omit a data location.
     * @details
     *     Function Template
     *     -----------------
     *     Prepares a lambda expression which schedules an event which may not 
     *     omit event data, in a container space using the provided contractor 
     *     objective.
     * @tparam Schedular
     *     Type of the schedule.
     * @tparam Positional
     *     Type of positions to events in the schedule.
     * @tparam Natural
     *     Type of natural integer used by the schedule.
     * @tparam Subjective 
     *     Type of the event data (function type not allowed).
     * @tparam Contractor 
     *     Objective reference used to add events into the schedule.
     * @tparam Visitor
     *     Objective reference used to retrieve events from the schedule.
     * @tparam Function
     *     Function reference to the function invoked during the event.
     * @param[in] schedule 
     *     Reference to the schedule. 
     * @return
     *     The instance of the lambda expression.
     */
    template <
        typename Schedular,
        typename Positional,
        typename Natural,
        typename Subjective,
        Referential< const Tractile< Schedular, Positional, Natural > >
            Contractor,
        typename ...Parametric
    >
    static inline auto
    PrepareScheduleNullRefused(
        Referential< const Directional< Schedular, Positional, Natural, Contextual< Parametric... > > >
            visitor,
        Referential< Schedular >
            schedule,
        Referential< Contractual< Parametric... > >
            function
    ) {
        static auto&
            ScheduleEvent = ScheduleNullRefused< Schedular, Positional, Natural, Subjective, Contractor, Parametric... >;
        auto 
            Lambda = [&visitor, &schedule, &function]( 
                const Locational< Subjective > 
                    subject 
            ) {
                return ScheduleEvent( visitor, schedule, function, subject );
            };
        return Lambda;
    }

    /**
     * @brief
     *     Processes a single scheduled event.
     * @details
     *     Function Template
     *     -----------------
     *     Processes a single event by first removing it from the schedule 
     *     schedule and then invoking the event function while passing the event
     *     data.
     * @tparam Schedular
     *     Type of the schedule.
     * @tparam Positional
     *     Type of positions to events in the schedule.
     * @tparam Natural
     *     Type of natural integer used by the schedule.
     * @tparam Contractor 
     *     Objective reference used to add events into the schedule.
     * @tparam Visitor
     *     Objective reference used to retrieve events from the schedule.
     * @param[in,out] schedule 
     *     Reference to the schedule. 
     * @return
     *     True if an event was processed.
     */
    template <
        typename Schedular,
        typename Positional,
        typename Natural,
        Referential< const Tractile< Schedular, Positional, Natural > >
            Contractor,
        typename ...Parametric
    >
    static inline bool
    ProcessOneEvent(
        Referential< const Directional< Schedular, Positional, Natural, Contextual< Parametric... > > >
            visitor,
        Referential< Schedular >
            schedule,
        Parametric...
            arguments
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        Positional
            position;
        Contextual< Parametric... >
            event;
        if (!visitor.begins( schedule, 0 ))
            return false;
        visitor.scale.begin( schedule, position, 0 );
        event = visitor.scale.go( schedule, position ).to;
        Contractor.retract( schedule, 1 );
        event.relator( event.value, arguments... );
        return true;
    }

    /**
     * @brief
     *     Prepares a lambda expression which processes a single scheduled 
     *     event.
     * @details
     *     Function Template
     *     -----------------
     *     Prepares a lambda expression which processes a single event by first 
     *     removing it from the schedule schedule and then invoking the event 
     *     function while passing the event data.
     * @tparam Schedular
     *     Type of the schedule.
     * @tparam Positional
     *     Type of positions to events in the schedule.
     * @tparam Natural
     *     Type of natural integer used by the schedule.
     * @tparam Contractor 
     *     Objective reference used to add events into the schedule.
     * @tparam Visitor
     *     Objective reference used to retrieve events from the schedule.
     * @param[in] schedule 
     *     Reference to the schedule. 
     * @return
     *     The instance of the lambda expression.
     */
    template <
        typename Schedular,
        typename Positional,
        typename Natural,
        Referential< const Tractile< Schedular, Positional, Natural > >
            Contractor,
        typename ...Parametric
    >
    static inline auto
    PrepareProcessOneEvent(
        Referential< const Directional< Schedular, Positional, Natural, Contextual< Parametric... > > >
            visitor,
        Referential< Schedular >
            schedule
    ) {
        static auto&
            ProcessEvent = ProcessOneEvent< Schedular, Positional, Natural, Contractor, Parametric... >;
        auto 
            Lambda = [&visitor, &schedule]( 
                Parametric... 
                    arguments 
            ) -> bool {
                return ProcessEvent( visitor, schedule, arguments... );
            };
        return Lambda;
    }

}

#endif
