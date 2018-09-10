// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef LOCALIZATION_MODULE
#define LOCALIZATION_MODULE
#include "trajection.hpp"
#include "comparison.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace localization {

    using ::location::Locational;
    using ::location::Referential;
    using ::location::Conferential;
    using ::trajection::Scalar;
    using ::trajection::Lineal;
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
        using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Integral >::value,
            "Integral:  Integer type required"
        );
#endif
        if (!locality)
            throw locality;
        return IndexicalGo( locality, index );
    }

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Integral >
    BeginIncrement(
        Referential< const Locational< Elemental > >
            locality,
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
        return index = static_cast< Integral >(count);
    }

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Integral >
    BeginDecrement(
        Referential< const Locational< Elemental > >
            locality,
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
        return index = -static_cast< Integral >(count);
    }

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Integral >
    TraverseIncrement(
        Referential< const Locational< Elemental > >
            locality,
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
        return index += static_cast< Integral >(count);
    }

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    static inline Referential< const Integral >
    TraverseDecrement(
        Referential< const Locational< Elemental > >
            locality,
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
        return index -= static_cast< Integral >(count);
    }

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Integral, Natural, const Elemental >
    ReadIncrementScale = {
        Comparison< Integral >,
        BeginIncrement< Integral, Natural, const Elemental >,
        TraverseIncrement< Integral, Natural, const Elemental >,
        IndexicalGo< Integral, const Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Integral, Natural, const Elemental >
    ReadIncrementScaleChecksForNull = {
        Comparison< Integral >,
        BeginIncrement< Integral, Natural, const Elemental >,
        TraverseIncrement< Integral, Natural, const Elemental >,
        IndexicalGoChecksForNull< Integral, const Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Integral, Natural, Elemental >
    WriteIncrementScale = {
        Comparison< Integral >,
        BeginIncrement< Integral, Natural, Elemental >,
        TraverseIncrement< Integral, Natural, Elemental >,
        IndexicalGo< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Integral, Natural, Elemental >
    WriteIncrementScaleChecksForNull = {
        Comparison< Integral >,
        BeginIncrement< Integral, Natural, Elemental >,
        TraverseIncrement< Integral, Natural, Elemental >,
        IndexicalGoChecksForNull< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Integral, Natural, const Elemental >
    ReadDecrementScale = {
        Comparison< Integral >,
        BeginDecrement< Integral, Natural, const Elemental >,
        TraverseDecrement< Integral, Natural, const Elemental >,
        IndexicalGo< Integral, const Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Integral, Natural, const Elemental >
    ReadDecrementScaleChecksForNull = {
        Comparison< Integral >,
        BeginDecrement< Integral, Natural, const Elemental >,
        TraverseDecrement< Integral, Natural, const Elemental >,
        IndexicalGoChecksForNull< Integral, const Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Integral, Natural, Elemental >
    WriteDecrementScale = {
        Comparison< Integral >,
        BeginDecrement< Integral, Natural, Elemental >,
        TraverseDecrement< Integral, Natural, Elemental >,
        IndexicalGo< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Integral, Natural, Elemental >
    WriteDecrementScaleChecksForNull = {
        Comparison< Integral >,
        BeginDecrement< Integral, Natural, Elemental >,
        TraverseDecrement< Integral, Natural, Elemental >,
        IndexicalGoChecksForNull< Integral, Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Integral, Natural, const Elemental >
    ReadLiner = {
        ReadIncrementScale< Integral, Natural, Elemental >,
        ReadDecrementScale< Integral, Natural, Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Integral, Natural, const Elemental >
    ReadLinerChecksForNull = {
        ReadIncrementScaleChecksForNull< Integral, Natural, Elemental >,
        ReadDecrementScaleChecksForNull< Integral, Natural, Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Integral, Natural, Elemental >
    WriteLiner = {
        WriteIncrementScale< Integral, Natural, Elemental >,
        WriteDecrementScale< Integral, Natural, Elemental >
    };

    template <
        typename Integral,
        typename Natural,
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Integral, Natural, Elemental >
    WriteLinerChecksForNull = {
        WriteIncrementScaleChecksForNull< Integral, Natural, Elemental >,
        WriteDecrementScaleChecksForNull< Integral, Natural, Elemental >
    };

}

#endif
