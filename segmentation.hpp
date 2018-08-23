// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SEGMENTATION_MODULE
#define SEGMENTATION_MODULE
#include "localization.hpp"

namespace segmentation {

    using namespace ::location;
    using namespace ::trajection;
    using namespace ::comparison;
    using ::localization::IndexicalGo;
    using ::localization::TraverseDecrement;
    using ::localization::ReadIncrementScale;
    using ::localization::WriteIncrementScale;
    using ::localization::ReadLocal;
    using ::localization::WriteLocal;

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    ContainsIndex(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return index < Length;
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    ContainsIndexChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Contains = ContainsIndex< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        return Contains( locality, index );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Conferential< Elemental >
    IndexicalGoSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Contains = ContainsIndexChecksForNull< Natural, Length, Elemental >;
        if (!Contains( locality, index ))
            throw index;
        return IndexicalGo( locality, index );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    Begins(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return Length > 0 && count < Length;
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    BeginsChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            SegmentBegins = Begins< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        return SegmentBegins( locality, count );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    BeginIncrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        if (Length < 1)
            throw Length;
        if (!locality)
            throw locality;
        if (count >= Length)
            throw count;
        return Begin( locality, index, count );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    BeginDecrement(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return index = Length ? Length - 1 - count : 0;
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    BeginDecrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Descend = BeginDecrement< Natural, Length, Elemental >;
        if (Length < 1)
            throw Length;
        if (!locality)
            throw locality;
        if (count >= Length)
            throw count;
        return Descend( locality, index, count );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraversable(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return index + count < Length;
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraversableChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Traversable = IncrementTraversable< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        return Traversable( locality, index, count );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraversable(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return count <= index;
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraversableChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Traversable = DecrementTraversable< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        return Traversable( locality, index, count );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    TraverseIncrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
        Referential< Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Traversable = IncrementTraversableChecksForNull< Natural, Length, Elemental >;
        if (!Traversable( locality, index, count ))
            throw count;
        return TraverseIncrement( locality, index, count );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    TraverseDecrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Traversable = DecrementTraversableChecksForNull< Natural, Length, Elemental >;
        if (!Traversable( locality, index, count ))
            throw count;
        return TraverseDecrement( locality, index, count );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    Account(
        Referential< const Locational< Elemental > >
            locality
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return Length;
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    CountIncrement(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return Length - 1 - index;
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    CountDecrement(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return index;
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< const Elemental >, Natural, const Elemental >
    ReadVector = {
        Comparison< Natural >,
        ContainsIndex< Natural, Length, const Elemental >,
        IndexicalGo< Natural, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< const Elemental >, Natural, const Elemental >
    SafeReadVector = {
        Comparison< Natural >,
        ContainsIndexChecksForNull< Natural, Length, const Elemental >,
        IndexicalGoSafely< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< Elemental >, Natural, Elemental >
    WriteVector = {
        Comparison< Natural >,
        ContainsIndex< Natural, Length, Elemental >,
        IndexicalGo< Natural, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< Elemental >, Natural, Elemental >
    SafeWriteVector = {
        Comparison< Natural >,
        ContainsIndexChecksForNull< Natural, Length, Elemental >,
        IndexicalGoSafely< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadIncrementScale = {
        Comparison< Natural >,
        BeginIncrementSafely< Natural, Length, const Elemental >,
        TraverseIncrementSafely< Natural, Length, const Elemental >,
        IndexicalGoSafely< Natural, Length, const Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteIncrementScale = {
        Comparison< Natural >,
        BeginIncrementSafely< Natural, Length, Elemental >,
        TraverseIncrementSafely< Natural, Length, Elemental >,
        IndexicalGoSafely< Natural, Length, Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadDecrementScale = {
        Comparison< Natural >,
        BeginDecrement< Natural, Length, const Elemental >,
        TraverseDecrement< Natural, Natural, const Elemental >,
        IndexicalGo< Natural, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadDecrementScale = {
        Comparison< Natural >,
        BeginDecrementSafely< Natural, Length, const Elemental >,
        TraverseDecrementSafely< Natural, Length, const Elemental >,
        IndexicalGoSafely< Natural, Length, const Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteDecrementScale = {
        Comparison< Natural >,
        BeginDecrement< Natural, Length, Elemental >,
        TraverseDecrement< Natural, Natural,  Elemental >,
        IndexicalGo< Natural, Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteDecrementScale = {
        Comparison< Natural >,
        BeginDecrementSafely< Natural, Length, Elemental >,
        TraverseDecrementSafely< Natural, Length, Elemental >,
        IndexicalGoSafely< Natural, Length, Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadLiner = {
        ReadIncrementScale< Natural, Natural, Elemental >,
        ReadDecrementScale< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteLiner = {
        WriteIncrementScale< Natural, Natural, Elemental >,
        WriteDecrementScale< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadLiner = {
        SafeReadIncrementScale< Natural, Length, Elemental >,
        SafeReadDecrementScale< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteLiner = {
        SafeWriteIncrementScale< Natural, Length, Elemental >,
        SafeWriteDecrementScale< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadIncrementDirection = {
        ReadIncrementScale< Natural, Natural, Elemental >,
        Begins< Natural, Length, const Elemental >,
        IncrementTraversable< Natural, Length, const Elemental >,
        ContainsIndex< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountIncrement< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadIncrementDirection = {
        SafeReadIncrementScale< Natural, Length, Elemental >,
        BeginsChecksForNull< Natural, Length, const Elemental >,
        IncrementTraversableChecksForNull< Natural, Length, const Elemental >,
        ContainsIndexChecksForNull< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountIncrement< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteIncrementDirection = {
        WriteIncrementScale< Natural, Elemental >,
        Begins< Natural, Length, Elemental >,
        IncrementTraversable< Natural, Length, Elemental >,
        ContainsIndex< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountIncrement< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteIncrementDirection = {
        SafeWriteIncrementScale< Natural, Length, Elemental >,
        BeginsChecksForNull< Natural, Length, Elemental >,
        IncrementTraversableChecksForNull< Natural, Length, Elemental >,
        ContainsIndexChecksForNull< Natural, Length, const Elemental >,
        Account< Natural, Length, Elemental >,
        CountIncrement< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadDecrementDirection = {
        ReadDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        DecrementTraversable< Natural, Length, const Elemental >,
        ContainsIndex< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountDecrement< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadDecrementDirection = {
        SafeReadDecrementScale< Natural, Length, Elemental >,
        BeginsChecksForNull< Natural, Length, const Elemental >,
        DecrementTraversableChecksForNull< Natural, Length, const Elemental >,
        ContainsIndexChecksForNull< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountDecrement< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteDecrementDirection = {
        WriteDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        DecrementTraversable< Natural, Length, Elemental >,
        ContainsIndex< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountDecrement< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteDecrementDirection = {
        SafeWriteDecrementScale< Natural, Length, Elemental >,
        BeginsChecksForNull< Natural, Length, Elemental >,
        DecrementTraversableChecksForNull< Natural, Length, Elemental >,
        ContainsIndexChecksForNull< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountDecrement< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadAxis = {
        ReadIncrementDirection< Natural, Length, Elemental >,
        ReadDecrementDirection< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadAxis = {
        SafeReadIncrementDirection< Natural, Length, Elemental >,
        SafeReadDecrementDirection< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteAxis = {
        WriteIncrementDirection< Natural, Length, Elemental >,
        WriteDecrementDirection< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteAxis = {
        SafeWriteIncrementDirection< Natural, Length, Elemental >,
        SafeWriteDecrementDirection< Natural, Length, Elemental >
    };

}

#endif
