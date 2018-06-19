// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef LOCALIZATION_MODULE
#define LOCALIZATION_MODULE
#include "trajection.hpp"
#include "comparison.hpp"

namespace localization {

    using namespace ::trajection;
    using ::comparison::Comparison;

    template <
        typename Elemental
    >
    using WriteLocal = const Locational< Elemental >;

    template <
        typename Elemental
    >
    using ReadLocal = const Locational< const Elemental >;

    template <
        typename Integral,
        typename Elemental
    >
    static inline Conferential< Elemental >
    IndexicalGo(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Integral >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        return Confer( locality[index] );
    }

    template <
        typename Integral,
        typename Elemental
    >
    static inline Conferential< Elemental >
    IndexicalGoChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Integral >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        if (!locality)
            throw locality;
        return IndexicalGo( locality, index );
    }

    template <
        typename Integral,
        typename Elemental
    >
    static inline Referential< const Integral >
    Begin(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Integral >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        return index = 0;
    }

    template <
        typename Integral,
        typename Elemental
    >
    static inline Referential< const Integral >
    TraverseIncrement(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Integral >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        return ++index;
    }

    template <
        typename Integral,
        typename Elemental
    >
    static inline Referential< const Integral >
    TraverseDecrement(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Integral >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
        return --index;
    }

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Integral, const Elemental >
    ReadIncrementScale = {
        Comparison< Integral >,
        Begin< Integral, const Elemental >,
        TraverseIncrement< Integral, const Elemental >,
        IndexicalGo< Integral, const Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Integral, const Elemental >
    ReadIncrementScaleChecksForNull = {
        Comparison< Integral >,
        Begin< Integral, const Elemental >,
        TraverseIncrement< Integral, const Elemental >,
        IndexicalGoChecksForNull< Integral, const Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Integral, Elemental >
    WriteIncrementScale = {
        Comparison< Integral >,
        Begin< Integral, Elemental >,
        TraverseIncrement< Integral, Elemental >,
        IndexicalGo< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Integral, Elemental >
    WriteIncrementScaleChecksForNull = {
        Comparison< Integral >,
        Begin< Integral, Elemental >,
        TraverseIncrement< Integral, Elemental >,
        IndexicalGoChecksForNull< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Integral, const Elemental >
    ReadDecrementScale = {
        Comparison< Integral >,
        Begin< Integral, const Elemental >,
        TraverseDecrement< Integral, const Elemental >,
        IndexicalGo< Integral, const Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Integral, const Elemental >
    ReadDecrementScaleChecksForNull = {
        Comparison< Integral >,
        Begin< Integral, const Elemental >,
        TraverseDecrement< Integral, const Elemental >,
        IndexicalGoChecksForNull< Integral, const Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Integral, Elemental >
    WriteDecrementScale = {
        Comparison< Integral >,
        Begin< Integral, Elemental >,
        TraverseDecrement< Integral, Elemental >,
        IndexicalGo< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Integral, Elemental >
    WriteDecrementScaleChecksForNull = {
        Comparison< Integral >,
        Begin< Integral, Elemental >,
        TraverseDecrement< Integral, Elemental >,
        IndexicalGoChecksForNull< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Integral, const Elemental >
    ReadLiner = {
        ReadIncrementScale< Integral, Elemental >,
        ReadDecrementScale< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Integral, const Elemental >
    ReadLinerChecksForNull = {
        ReadIncrementScaleChecksForNull< Integral, Elemental >,
        ReadDecrementScaleChecksForNull< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Integral, Elemental >
    WriteLiner = {
        WriteIncrementScale< Integral, Elemental >,
        WriteDecrementScale< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Integral, Elemental >
    WriteLinerChecksForNull = {
        WriteIncrementScaleChecksForNull< Integral, Elemental >,
        WriteDecrementScaleChecksForNull< Integral, Elemental >
    };

}

#endif
