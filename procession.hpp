// � 2019 Aaron Sami Abassi
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
 *     facilitation functions.
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
     *     Abstraction Template
     *     --------------------
     *     Function type alias used as the event call interface.  Functions
     *     which implement this contract receive their event data as a 
     *     constant void pointer argument as well as zero or more specified 
     *     uniform extra event arguments and are expected to action the event 
     *     when called.
     * @tparam ...Parametric
     *     Parameter pack which represents extra event parameters.
     */
    template <
        typename ...Parametric
    >
    using Contractual = void(
        const Locational< const void >
            locality,
        Parametric...
            arguments
    );

    /**
     * @brief   
     *     Event schedule classifier.
     * @details 
     *     Classification Template
     *     -----------------------
     *     This type alias is used to represent an event in a schedule.  It 
     *     associates the event function (relator) with the event data (value) 
     *     using their respective memory locations.  __Care should be used to 
     *     ensure that the duration of both the event data and the pointer to 
     *     the event data continue to exist until after the event has been
     *     processed__.
     * @tparam ...Parametric
     *     Parameter pack which represents extra event parameters.
     */
    template <
        typename ...Parametric
    >
    using Contextual = Complementary< Locational< Contractual< Parametric... > >, Locational< const void > >;

    /**
     * @brief 
     *     Schedules an event.
     * @details
     *     Function Template
     *     -----------------
     *     Schedules an event, in a container space using the provided 
     *     contractor objective.  Both the event subject and the pointer to the
     *     event subject must have sufficient duration such that they both exist
     *     when the event is run.
     * @tparam Schedular
     *     Type of the schedule.
     * @tparam Positional
     *     Type of positions to events in the schedule.
     * @tparam Natural
     *     Type of natural integer used by the schedule.
     * @tparam Subjective 
     *     Type of the event subject.
     * @tparam Contractor 
     *     Objective reference used to add events into the schedule.
     * @tparam ...Parametric
     *     Parameter pack which represents extra event parameters.
     * @param[in] visitor
     *     Objective reference used to retrieve events from the schedule.
     * @param[in,out] schedule 
     *     Reference to the schedule. 
     * @param[in] function
     *     Objective reference to the event function.
     * @param[in] locality
     *     Pointer to a pointer to the event subject.
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
    Schedule(
        Referential< const Directional< Schedular, Positional, Natural, Contextual< Parametric... > > >
            visitor,
        Referential< Schedular >
            schedule,
        Referential< Contractual< Parametric... > >
            function,
        Referential< const Locational< Subjective > >
            locality
    ) {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        Positional
            position;
        if (!Contractor.protract( schedule, position, 1 ))
            return false;
        Referential< Contextual< Parametric... > >
            event = visitor.scale.go( schedule, position ).to;
        event.value = Locate( locality ).at;
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
     *     Prepares a lambda expression which schedules an event, in a container
     *     space using the provided contractor objective.
     * @tparam Schedular
     *     Type of the schedule.
     * @tparam Positional
     *     Type of positions to events in the schedule.
     * @tparam Natural
     *     Type of natural integer used by the schedule.
     * @tparam Subjective 
     *     Type of the event subject.
     * @tparam Contractor 
     *     Objective reference used to add events into the schedule.
     * @tparam ...Parametric
     *     Parameter pack which represents extra event parameters.
     * @param[in] visitor
     *     Objective reference used to retrieve events from the schedule.
     * @param[in] schedule 
     *     Reference to the schedule. 
     * @param[in] function
     *     Objective reference to the event function.
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
    PrepareSchedule(
        Referential< const Directional< Schedular, Positional, Natural, Contextual< Parametric... > > >
            visitor,
        Referential< Schedular >
            schedule,
        Referential< Contractual< Parametric... > >
            function
    ) {
        static auto&
            RunSchedule = Schedule< Schedular, Positional, Natural, Subjective, Contractor, Parametric... >;
        auto 
            lambda = [&visitor, &schedule, &function]( 
                Referential< const Locational< Subjective > >
                    locality 
            ) {
                return RunSchedule( visitor, schedule, function, locality );
            };
        return lambda;
    }

    /**
     * @brief
     *     Processes a single scheduled event.
     * @details
     *     Function Template
     *     -----------------
     *     Processes a single event by first removing it from the schedule 
     *     and then invoking the event function while passing the event data
     *     and zero or more event parameters.
     * @tparam Schedular
     *     Type of the schedule.
     * @tparam Positional
     *     Type of positions to events in the schedule.
     * @tparam Natural
     *     Type of natural integer used by the schedule.
     * @tparam Contractor 
     *     Objective reference used to add events into the schedule.
     * @tparam ...Parametric
     *     Parameter pack which represents extra event parameters.
     * @param[in] visitor 
     *     Reference to a directional trajection objective. 
     * @param[in,out] schedule 
     *     Reference to the schedule. 
     * @param[in] arguments
     *     Pack of zero or more specified extra event arguments.
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
     * @tparam ...Parametric
     *     Parameter pack which represents extra event parameters.
     * @param[in] visitor 
     *     Reference to a directional trajection objective. 
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
            Process = ProcessOneEvent< Schedular, Positional, Natural, Contractor, Parametric... >;
        auto 
            lambda = [&visitor, &schedule]( 
                Parametric... 
                    arguments 
            ) -> bool {
                return Process( visitor, schedule, arguments... );
            };
        return lambda;
    }

}

#endif
