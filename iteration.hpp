// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ITERATION_MODULE
#define ITERATION_MODULE
#include "trajection.hpp"
#include "comparison.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace iteration {

    using namespace ::trajection;
    using ::comparison::Comparison;

    template <
        typename Integral,
        typename Subjective
    >
    using Operative = void(
        Referential< Subjective >,
        Referential< const Integral >,
        Referential< const Integral >,
        Referential< const Integral >
    );

    template <
        typename Integral,
        typename Subjective
    >
    struct Iterative {

        Referential< const Integral >
            lower,
            upper;

        Referential< Subjective >
            subject;

    };

    template <
        typename Integral,
        typename Subjective
    >
    static inline Conferential< const Subjective >
    GoTo(
        Referential< Iterative< Integral, Subjective > >
            space,
        Referential< const Integral >
            index
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
#endif
        return Deter( space.subject );
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective
    >
    static inline bool
    Begins(
        Referential< const Iterative< Integral, Subjective > >
            space,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return space.lower + static_cast< Integral >(count) <= space.upper;
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective
    >
    static inline bool
    IncrementTraverses(
        Referential< const Iterative< Integral, Subjective > >
            space,
        Referential< const Integral >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return index + static_cast< Integral >(count) <= space.upper;
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective
    >
    static inline bool
    DecrementTraverses(
        Referential< const Iterative< Integral, Subjective > >
            space,
        Referential< const Integral >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return index >= space.lower + static_cast< Integral >(count);
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    static inline Referential< const Integral >
    BeginIncrement(
        Referential< Iterative< Integral, Subjective > >
            space,
        Referential< Integral >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        const Integral
            to = space.lower + static_cast< Integral >(count);
        for (index = space.lower; index < to; index++)
            Operate( space.subject, index, space.lower, space.upper );
        Operate( space.subject, index, space.lower, space.upper );
        return index;
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    static inline Referential< const Integral >
    BeginDecrement(
        Referential< Iterative< Integral, Subjective > >
            space,
        Referential< Integral >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        const Integral
            to = space.upper - static_cast< Integral >(count);
        for (index = space.upper; index > to; index++)
            Operate( space.subject, index, space.lower, space.upper );
        Operate( space.subject, index, space.lower, space.upper );
        return index;
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    static inline Referential< const Integral >
    TraverseIncrement(
        Referential< Iterative< Integral, Subjective > >
            space,
        Referential< Integral >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        const Integral
            to = index + static_cast< Integral >(count);
        while (index < to)
            Operate( space.subject, ++index, space.lower, space.upper );
        return index;
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    static inline Referential< const Integral >
    TraverseDecrement(
        Referential< Iterative< Integral, Subjective > >
            space,
        Referential< Integral >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        const Integral
            to = index - static_cast< Integral >(count);
        while (index > to)
            Operate( space.subject, --index, space.lower, space.upper );
        return index;
    }

    template <
        typename Integral,
        typename Subjective
    >
    static inline bool
    Meets(
        Referential< const Iterative< Integral, Subjective > >
            space,
        Referential< const Integral >
            index
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
#endif
        return index >= space.lower && index <= space.upper;
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective
    >
    static inline Natural
    Survey(
        Referential< const Iterative< Integral, Subjective > >
            space
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return static_cast< Natural>(space.upper - space.lower + 1);
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective
    >
    static inline Natural
    CountIncrement(
        Referential< const Iterative< Integral, Subjective > >
            space,
        Referential< const Integral >
            index
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return static_cast< Natural >(space.upper - index);
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective
    >
    static inline Natural
    CountDecrement(
        Referential< const Iterative< Integral, Subjective > >
            space,
        Referential< const Integral >
            index
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return static_cast< Natural >(index - space.lower);
    }

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    constexpr Scalar< Iterative< Integral, Subjective >, Integral, Natural, const Subjective >
    IncrementIteratingScale = {
        Comparison< Integral >, 
        BeginIncrement< Integral, Natural, Subjective, Operate >, 
        TraverseIncrement< Integral, Natural, Subjective, Operate >, 
        GoTo< Integral, Subjective >
    };

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    constexpr Scalar< Iterative< Integral, Subjective >, Integral, Natural, const Subjective >
    DecrementIteratingScale = {
        Comparison< Integral >,
        BeginDecrement< Integral, Natural, Subjective, Operate >, 
        TraverseDecrement< Integral, Natural, Subjective, Operate >, 
        GoTo< Integral, Subjective >
    };

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    constexpr Lineal< Iterative< Integral, Subjective >, Integral, Natural, const Subjective >
    IteratingLiner = {
        IncrementIteratingScale< Integral, Natural, Subjective, Operate >, 
        DecrementIteratingScale< Integral, Natural, Subjective, Operate >
    };

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    constexpr Directional< Iterative< Integral, Subjective >, Integral, Natural, const Subjective >
    IncrementIteratingDirection = {
        IncrementIteratingScale< Integral, Natural, Subjective, Operate >,
        Begins< Integral, Natural, Subjective >,
        IncrementTraverses< Integral, Natural, Subjective >,
        Meets< Integral, Subjective >,
        Survey< Integral, Natural, Subjective >,
        CountIncrement< Integral, Natural, Subjective >
    };

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    constexpr Directional< Iterative< Integral, Subjective >, Integral, Natural, const Subjective >
    DecrementIteratingDirection = {
        DecrementIteratingScale< Integral, Natural, Subjective, Operate >,
        Begins< Integral, Natural, Subjective >,
        DecrementTraverses< Integral, Natural, Subjective >,
        Meets< Integral, Subjective >,
        Survey< Integral, Natural, Subjective >,
        CountDecrement< Integral, Natural, Subjective >
    };

    template <
        typename Integral,
        typename Natural,
        typename Subjective,
        Operative< Integral, Subjective >
            Operate
    >
    constexpr Axial< Iterative< Integral, Subjective >, Integral, Natural, const Subjective >
    IteratingAxis = {
        IncrementIteratingDirection< Integral, Natural, Subjective, Operate >,
        DecrementIteratingDirection< Integral, Natural, Subjective, Operate >
    };

}

#endif
