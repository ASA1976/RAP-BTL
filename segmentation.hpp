// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SEGMENTATION_MODULE
#define SEGMENTATION_MODULE
#include "localization.hpp"

namespace segmentation {

    using namespace ::localization;

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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
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
            locality
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return Length > 0;
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
            locality
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static auto&
            SegmentBegins = Begins< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        return SegmentBegins( locality );
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
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (Length < 1)
            throw Length;
        if (!locality)
            throw locality;
        return Begin( locality, index );
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
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        index = Length - 1;
        return index;
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
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static auto&
            Descend = BeginDecrement< Natural, Length, Elemental >;
        if (Length < 1)
            throw Length;
        if (!locality)
            throw locality;
        return Descend( locality, index );
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
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return index < Length;
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
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static auto&
            Traversable = IncrementTraversable< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        return Traversable( locality, index );
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
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return index > 0;
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
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static auto&
            Traversable = DecrementTraversable< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        return Traversable( locality, index );
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
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static auto&
            Traversable = IncrementTraversableChecksForNull< Natural, Length, Elemental >;
        if (!Traversable( locality, index ))
            throw index;
        return TraverseIncrement( locality, index );
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
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static auto&
            Traversable = DecrementTraversableChecksForNull< Natural, Length, Elemental >;
        if (!Traversable( locality, index ))
            throw index;
        return TraverseDecrement( locality, index );
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
    constexpr Scalar< const Locational< const Elemental >, Natural, const Elemental >
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
    constexpr Scalar< const Locational< Elemental >, Natural, Elemental >
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
    constexpr Scalar< const Locational< const Elemental >, Natural, const Elemental >
    ReadDecrementScale = {
        Comparison< Natural >,
        BeginDecrement< Natural, Length, const Elemental >,
        TraverseDecrement< Natural, const Elemental >,
        IndexicalGo< Natural, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Natural, const Elemental >
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
    constexpr Scalar< const Locational< Elemental >, Natural, Elemental >
    WriteDecrementScale = {
        Comparison< Natural >,
        BeginDecrement< Natural, Length, Elemental >,
        TraverseDecrement< Natural, Elemental >,
        IndexicalGo< Natural, Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Natural, Elemental >
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
    constexpr Lineal< const Locational< const Elemental >, Natural, const Elemental >
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
    constexpr Lineal< const Locational< Elemental >, Natural, Elemental >
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
    constexpr Directional< const Locational< const Elemental >, Natural, const Elemental >
    ReadIncrementDirection = {
        ReadIncrementScale< Natural, Elemental >,
        Begins< Natural, Length, const Elemental >,
        IncrementTraversable< Natural, Length, const Elemental >,
        ContainsIndex< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, const Elemental >
    SafeReadIncrementDirection = {
        SafeReadIncrementScale< Natural, Length, Elemental >,
        BeginsChecksForNull< Natural, Length, const Elemental >,
        IncrementTraversableChecksForNull< Natural, Length, const Elemental >,
        ContainsIndexChecksForNull< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Elemental >
    WriteIncrementDirection = {
        WriteIncrementScale< Natural, Elemental >,
        Begins< Natural, Length, Elemental >,
        IncrementTraversable< Natural, Length, Elemental >,
        ContainsIndex< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Elemental >
    SafeWriteIncrementDirection = {
        SafeWriteIncrementScale< Natural, Length, Elemental >,
        BeginsChecksForNull< Natural, Length, Elemental >,
        IncrementTraversableChecksForNull< Natural, Length, Elemental >,
        ContainsIndexChecksForNull< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, const Elemental >
    ReadDecrementDirection = {
        ReadDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        DecrementTraversable< Natural, Length, const Elemental >,
        ContainsIndex< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, const Elemental >
    SafeReadDecrementDirection = {
        SafeReadDecrementScale< Natural, Length, Elemental >,
        BeginsChecksForNull< Natural, Length, const Elemental >,
        DecrementTraversableChecksForNull< Natural, Length, const Elemental >,
        ContainsIndexChecksForNull< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Elemental >
    WriteDecrementDirection = {
        WriteDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        DecrementTraversable< Natural, Length, Elemental >,
        ContainsIndex< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Elemental >
    SafeWriteDecrementDirection = {
        SafeWriteDecrementScale< Natural, Length, Elemental >,
        BeginsChecksForNull< Natural, Length, Elemental >,
        DecrementTraversableChecksForNull< Natural, Length, Elemental >,
        ContainsIndexChecksForNull< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< const Elemental >, Natural, const Elemental >
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
    constexpr Axial< const Locational< const Elemental >, Natural, const Elemental >
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
    constexpr Axial< const Locational< Elemental >, Natural, Elemental >
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
    constexpr Axial< const Locational< Elemental >, Natural, Elemental >
    SafeWriteAxis = {
        SafeWriteIncrementDirection< Natural, Length, Elemental >,
        SafeWriteDecrementDirection< Natural, Length, Elemental >
    };

}

#endif
