// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef PROCESSION_MODULE
#define PROCESSION_MODULE
#include "traction.hpp"
#include "trajection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace procession {

    using ::location::Locational;
    using ::location::Referential;
    using ::trajection::Directional;
    using ::traction::Tractile;

    using Contractual = void(
        const Locational< void >
    );

    struct Contextual {

        Locational< void >
            location;

        Locational< Contractual >
            objective;

    };

    template <
        typename Spatial,
        typename Subjective
    >
    using Schedular = bool(
        Referential< Spatial >,
        const Locational< Subjective >
    );

    template <
        typename Spatial
    >
    using Processive = bool(
        Referential< Spatial >
    );

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Subjective,
        Referential< const Tractile< Spatial, Positional, Natural > >
            Contractor,
        Referential< const Directional< Spatial, Positional, Natural, Contextual > >
            Visitor,
        Referential< Contractual >
            Function
    >
    static inline bool
    ScheduleNullAllowed(
        Referential< Spatial >
            space,
        const Locational< Subjective >
            subject
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
        if (!Contractor.protract( space, position, 1 ))
            return false;
        Visitor.scale.go( space, position ).to.location = (Locational< void >) subject;
        Visitor.scale.go( space, position ).to.objective = Function;
        return true;
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Subjective,
        Referential< const Tractile< Spatial, Positional, Natural > >
            Contractor,
        Referential< const Directional< Spatial, Positional, Natural, Contextual > >
            Visitor,
        Referential< Contractual >
            Function
    >
    static inline bool
    ScheduleNullRefused(
        Referential< Spatial >
            space,
        const Locational< Subjective >
            subject
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Schedule = ScheduleNullAllowed< Spatial, Positional, Natural, Subjective, Contractor, Visitor, Function >;
        if (subject == 0)
            return false;
        return Schedule( space, subject );
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        Referential< const Tractile< Spatial, Positional, Natural > >
            Contractor,
        Referential< const Directional< Spatial, Positional, Natural, Contextual > >
            Visitor
    >
    static inline bool
    Process(
        Referential< Spatial >
            space
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
        if (!Visitor.begins( space, 0 ))
            return false;
        Visitor.scale.begin( space, position, 0 );
        event = Visitor.scale.go( space, position ).to;
        Contractor.retract( space, 1 );
        event.objective( event.location );
        return true;
    }

};

#endif
