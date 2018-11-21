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
    using Contractual = void(
        const Locational< void >
            locality
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
    using Contextual = Complementary< Locational< Contractual >, Locational< void > >;

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
        Referential< const Directional< Schedular, Positional, Natural, Contextual > >
            Visitor,
        Referential< Contractual >
            Function
    >
    static inline bool
    ScheduleNullAccepted(
        Referential< Schedular >
            schedule,
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
        Referential< Contextual >
            event = Visitor.scale.go( schedule, position ).to;
        event.value = (Locational< void >) subject;
        event.relator = Function;
        return true;
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
        Referential< const Directional< Schedular, Positional, Natural, Contextual > >
            Visitor,
        Referential< Contractual >
            Function
    >
    static inline bool
    ScheduleNullRefused(
        Referential< Schedular >
            schedule,
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
            Schedule = ScheduleNullAccepted< Schedular, Positional, Natural, Subjective, Contractor, Visitor, Function >;
        if (subject == 0)
            return false;
        return Schedule( schedule, subject );
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
        Referential< const Directional< Schedular, Positional, Natural, Contextual > >
            Visitor
    >
    static inline bool
    ProcessOneEvent(
        Referential< Schedular >
            schedule
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
        Contextual
            event;
        if (!Visitor.begins( schedule, 0 ))
            return false;
        Visitor.scale.begin( schedule, position, 0 );
        event = Visitor.scale.go( schedule, position ).to;
        Contractor.retract( schedule, 1 );
        event.relator( event.value );
        return true;
    }

};

#endif
