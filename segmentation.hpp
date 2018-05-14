// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SEGMENTATION_MODULE
#define SEGMENTATION_MODULE
#include "localization.hpp"
#include <type_traits>

namespace segmentation {

    using namespace ::localization;

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    ContainsIndex(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Indexical >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        return index >= 0 && index < Length;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    ContainsIndexChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Indexical >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< bool(
            Referential< const Locational< Elemental > >,
            Referential< const Indexical >
        ) >
            Contains = ContainsIndex< Indexical, Length, Elemental >;
        if (!locality)
            throw locality;
        return Contains( locality, index );
    }

    template <
        typename Indexical,
        typename Elemental
    >
    static inline Conferential< Elemental >
    IndexicalGo(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Indexical >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        return Confer( locality[index] );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Conferential< Elemental >
    IndexicalGoSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Indexical >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< bool(
            Referential< const Locational< Elemental > >,
            Referential< const Indexical >
        ) >
            Contains = ContainsIndexChecksForNull< Indexical, Length, Elemental >;
        if (!locality)
            throw locality;
        if (!Contains( locality, index ))
            throw index;
        return IndexicalGo( locality, index );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    ContainsPosition(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        Locational< Elemental >
            current;
        Indexical
            index;
        current = locality;
        for (index = 0; index < Length; index++)
            if (current == position)
                return true;
            else
                current++;
        return false;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    ContainsPositionChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< bool(
            Referential< const Locational< Elemental > >,
            Referential< const Locational< Elemental > >
        ) >
            Contains = ContainsPosition< Indexical, Length, Elemental >;
        if (!locality)
            throw locality;
        if (!position)
            throw position;
        return Contains( locality, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Conferential< Elemental >
    PositionalGoSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< bool(
            Referential< const Locational< Elemental > >,
            Referential< const Locational< Elemental > >
        ) >
            Contains = ContainsPositionChecksForNull< Indexical, Length, Elemental >;
        if (!Contains( locality, position ))
            throw position;
        return PositionalGo( locality, position );
    }

    template <
        typename Indexical,
        Indexical
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
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        return Length > 0;
    }

    template <
        typename Indexical,
        Indexical
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
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< bool(
            Referential< const Locational< Elemental > >
        ) >
            SegmentBegins = Begins< Indexical, Length, Elemental >;
        if (!locality)
            throw locality;
        return SegmentBegins( locality );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginIncrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        if (Length <= 0)
            throw Length;
        if (!locality)
            throw locality;
        return Begin( locality, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginDecrement(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        position = locality + (Length <= 0 ? 0 : Length - 1);
        return position;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginDecrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< Referential< const Locational< Elemental > >(
            Referential< const Locational< Elemental > >,
            Referential< Locational< Elemental > >
        ) >
            Descend = BeginDecrement< Indexical, Length, Elemental >;
        if (Length <= 0)
            throw Length;
        if (!locality)
            throw locality;
        return Descend( locality, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraversable(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        return position != locality + (Length <= 0 ? 0 : Length - 1);
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraversableChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< bool(
            Referential< const Locational< Elemental > >,
            Referential< const Locational< Elemental > >
        ) >
            Traversable = IncrementTraversable< Indexical, Length, Elemental >;
        if (!locality)
            throw locality;
        if (!position)
            throw position;
        return Traversable( locality, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraversable(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        return position != locality;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraversableChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< bool(
            Referential< const Locational< Elemental > >,
            Referential< const Locational< Elemental > >
        ) >
            Traversable = DecrementTraversable< Indexical, Length, Elemental >;
        if (!locality)
            throw locality;
        if (!position)
            throw position;
        return Traversable( locality, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseIncrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< bool(
            Referential< const Locational< Elemental > >,
            Referential< const Locational< Elemental > >
        ) >
            Traversable = IncrementTraversableChecksForNull< Indexical, Length, Elemental >;
        if (!Traversable( locality, position ))
            throw position;
        return TraverseIncrement( locality, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseDecrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Indexical >::value,
            "Indexical:  Integer type required"
        );
        static Referential< bool(
            Referential< const Locational< Elemental > >,
            Referential< const Locational< Elemental > >
        ) >
            Traversable = DecrementTraversableChecksForNull< Indexical, Length, Elemental >;
        if (!Traversable( locality, position ))
            throw position;
        return TraverseDecrement( locality, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< const Elemental >, Indexical, const Elemental >
    ReadVector = {
        ContainsIndex< Indexical, Length, const Elemental >,
        IndexicalGo< Indexical, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< const Elemental >, Indexical, const Elemental >
    SafeReadVector = {
        ContainsIndexChecksForNull< Indexical, Length, const Elemental >,
        IndexicalGoSafely< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< Elemental >, Indexical, Elemental >
    WriteVector = {
        ContainsIndex< Indexical, Length, Elemental >,
        IndexicalGo< Indexical, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< Elemental >, Indexical, Elemental >
    SafeWriteVector = {
        ContainsIndexChecksForNull< Indexical, Length, Elemental >,
        IndexicalGoSafely< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    SafeReadIncrementScale = {
        BeginIncrementSafely< Indexical, Length, const Elemental >,
        TraverseIncrementSafely< Indexical, Length, const Elemental >,
        PositionalGoSafely< Indexical, Length, const Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Locational< Elemental >, Elemental >
    SafeWriteIncrementScale = {
        BeginIncrementSafely< Indexical, Length, Elemental >,
        TraverseIncrementSafely< Indexical, Length, Elemental >,
        PositionalGoSafely< Indexical, Length, Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadDecrementScale = {
        BeginDecrement< Indexical, Length, const Elemental >,
        TraverseDecrement< const Elemental >,
        PositionalGo< const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    SafeReadDecrementScale = {
        BeginDecrementSafely< Indexical, Length, const Elemental >,
        TraverseDecrementSafely< Indexical, Length, const Elemental >,
        PositionalGoSafely< Indexical, Length, const Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteDecrementScale = {
        BeginDecrement< Indexical, Length, Elemental >,
        TraverseDecrement< Elemental >,
        PositionalGo< Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Locational< Elemental >, Elemental >
    SafeWriteDecrementScale = {
        BeginDecrementSafely< Indexical, Length, Elemental >,
        TraverseDecrementSafely< Indexical, Length, Elemental >,
        PositionalGoSafely< Indexical, Length, Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    SafeReadLiner = {
        SafeReadIncrementScale< Indexical, Length, Elemental >,
        SafeReadDecrementScale< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Locational< Elemental >, Elemental >
    SafeWriteLiner = {
        SafeWriteIncrementScale< Indexical, Length, Elemental >,
        SafeWriteDecrementScale< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadIncrementDirection = {
        ReadIncrementScale< Elemental >,
        Begins< Indexical, Length, const Elemental >,
        IncrementTraversable< Indexical, Length, const Elemental >,
        ContainsPosition< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    SafeReadIncrementDirection = {
        SafeReadIncrementScale< Indexical, Length, Elemental >,
        BeginsChecksForNull< Indexical, Length, const Elemental >,
        IncrementTraversableChecksForNull< Indexical, Length, const Elemental >,
        ContainsPositionChecksForNull< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteIncrementDirection = {
        WriteIncrementScale< Elemental >,
        Begins< Indexical, Length, Elemental >,
        IncrementTraversable< Indexical, Length, Elemental >,
        ContainsPosition< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Locational< Elemental >, Elemental >
    SafeWriteIncrementDirection = {
        SafeWriteIncrementScale< Indexical, Length, Elemental >,
        BeginsChecksForNull< Indexical, Length, Elemental >,
        IncrementTraversableChecksForNull< Indexical, Length, Elemental >,
        ContainsPositionChecksForNull< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadDecrementDirection = {
        ReadDecrementScale< Indexical, Length, Elemental >,
        Begins< Indexical, Length, const Elemental >,
        DecrementTraversable< Indexical, Length, const Elemental >,
        ContainsPosition< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    SafeReadDecrementDirection = {
        SafeReadDecrementScale< Indexical, Length, Elemental >,
        BeginsChecksForNull< Indexical, Length, const Elemental >,
        DecrementTraversableChecksForNull< Indexical, Length, const Elemental >,
        ContainsPositionChecksForNull< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteDecrementDirection = {
        WriteDecrementScale< Indexical, Length, Elemental >,
        Begins< Indexical, Length, Elemental >,
        DecrementTraversable< Indexical, Length, Elemental >,
        ContainsPosition< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Locational< Elemental >, Elemental >
    SafeWriteDecrementDirection = {
        SafeWriteDecrementScale< Indexical, Length, Elemental >,
        BeginsChecksForNull< Indexical, Length, Elemental >,
        DecrementTraversableChecksForNull< Indexical, Length, Elemental >,
        ContainsPositionChecksForNull< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadAxis = {
        ReadIncrementDirection< Indexical, Length, Elemental >,
        ReadDecrementDirection< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    SafeReadAxis = {
        SafeReadIncrementDirection< Indexical, Length, Elemental >,
        SafeReadDecrementDirection< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteAxis = {
        WriteIncrementDirection< Indexical, Length, Elemental >,
        WriteDecrementDirection< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< Elemental >, Locational< Elemental >, Elemental >
    SafeWriteAxis = {
        SafeWriteIncrementDirection< Indexical, Length, Elemental >,
        SafeWriteDecrementDirection< Indexical, Length, Elemental >
    };

}

#endif
