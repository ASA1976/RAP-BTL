// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ORDINATION_MODULE
#define ORDINATION_MODULE
#include "trajection.hpp"

namespace ordination {

    using namespace ::trajection;

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    using WriteOrdinal = Elemental[Length];

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    using ReadOrdinal = const Elemental[Length];

    template <
        typename Elemental
    >
    using WritePositional = Locational< Elemental >;

    template <
        typename Elemental
    >
    using ReadPositional = Locational< const Elemental >;

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    ContainsIndex(
        Referential< const Elemental[Length] >
            array,
        Referential< const Indexical >
            index
    ) {
        return index >= 0 && index < Length;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Conferential< Elemental >
    IndexicalGo(
        Referential< Elemental[Length] >
            array,
        Referential< const Indexical >
            index
    ) {
        return Confer( array[index] );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Conferential< Elemental >
    IndexicalGoSafely(
        Referential< Elemental[Length] >
            array,
        Referential< const Indexical >
            index
    ) {
        if (!ContainsIndex( array, index ))
            throw index;
        return IndexicalGo( array, index );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    ContainsPosition(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
        return position >= array && position <= array + Length - 1;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    ContainsPositionChecksForNull(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
        static auto
            Contains = ContainsPosition< Indexical, Length, Elemental >;
        if (!position)
            throw position;
        return Contains( array, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Conferential< Elemental >
    PositionalGo(
        Referential< Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
        return Refer( position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Conferential< Elemental >
    PositionalGoSafely(
        Referential< Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
        static auto
            Contains = ContainsPositionChecksForNull< Indexical, Length, Elemental >;
        static auto
            Go = PositionalGo< Indexical, Length, Elemental >;
        if (!Contains( array, position ))
            throw position;
        return Go( array, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    Begins(
        Referential< const Elemental[Length] >
            array
    ) {
        return Length > 0;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginIncrement(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position
    ) {
        position = array;
        return position;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginDecrement(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position
    ) {
        position = array + Length - 1;
        return position;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraversable(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
        return position < array + Length - 1;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraversableChecksForNull(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
        static auto
            Traversable = IncrementTraversable< Indexical, Length, Elemental >;
        if (!position)
            throw position;
        return Traversable( array, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraversable(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
        return position > array;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraversableChecksForNull(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
        static auto
            Traversable = DecrementTraversable< Indexical, Length, Elemental >;
        if (!position)
            throw position;
        return Traversable( array, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseIncrement(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position
    ) {
        position++;
        return position;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseIncrementSafely(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position
    ) {
        static auto
            Traversable = IncrementTraversableChecksForNull< Indexical, Length, Elemental >;
        static auto
            Traverse = TraverseIncrement< Indexical, Length, Elemental >;
        if (!Traversable( array, position ))
            throw position;
        return Traverse( array, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseDecrement(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position
    ) {
        position--;
        return position;
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseDecrementSafely(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position
    ) {
        static auto
            Traversable = DecrementTraversableChecksForNull< Indexical, Length, Elemental >;
        static auto
            Traverse = TraverseDecrement< Indexical, Length, Elemental >;
        if (!Traversable( array, position ))
            throw position;
        return Traverse( array, position );
    }

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Elemental[Length], Indexical, const Elemental >
    ReadVector = {
        ContainsIndex< Indexical, Length, const Elemental >,
        IndexicalGo< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Elemental[Length], Indexical, const Elemental >
    SafeReadVector = {
        ContainsIndex< Indexical, Length, const Elemental >,
        IndexicalGoSafely< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Vectorial< Elemental[Length], Indexical, Elemental >
    WriteVector = {
        ContainsIndex< Indexical, Length, Elemental >,
        IndexicalGo< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Vectorial< Elemental[Length], Indexical, Elemental >
    SafeWriteVector = {
        ContainsIndex< Indexical, Length, Elemental >,
        IndexicalGoSafely< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, const Elemental >
    ReadIncrementScale = {
        BeginIncrement< Indexical, Length, const Elemental >,
        TraverseIncrement< Indexical, Length, const Elemental >,
        PositionalGo< Indexical, Length, const Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, const Elemental >
    SafeReadIncrementScale = {
        BeginIncrement< Indexical, Length, const Elemental >,
        TraverseIncrementSafely< Indexical, Length, const Elemental >,
        PositionalGoSafely< Indexical, Length, const Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Elemental >
    WriteIncrementScale = {
        BeginIncrement< Indexical, Length, Elemental >,
        TraverseIncrement< Indexical, Length, Elemental >,
        PositionalGo< Indexical, Length, Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteIncrementScale = {
        BeginIncrement< Indexical, Length, Elemental >,
        TraverseIncrementSafely< Indexical, Length, Elemental >,
        PositionalGoSafely< Indexical, Length, Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, const Elemental >
    ReadDecrementScale = {
        BeginDecrement< Indexical, Length, const Elemental >,
        TraverseDecrement< Indexical, Length, const Elemental >,
        PositionalGo< Indexical, Length, const Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, const Elemental >
    SafeReadDecrementScale = {
        BeginDecrement< Indexical, Length, const Elemental >,
        TraverseDecrementSafely< Indexical, Length, const Elemental >,
        PositionalGoSafely< Indexical, Length, const Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Elemental >
    WriteDecrementScale = {
        BeginDecrement< Indexical, Length, Elemental >,
        TraverseDecrement< Indexical, Length, Elemental >,
        PositionalGo< Indexical, Length, Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteDecrementScale = {
        BeginDecrement< Indexical, Length, Elemental >,
        TraverseDecrementSafely< Indexical, Length, Elemental >,
        PositionalGoSafely< Indexical, Length, Elemental >,
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Lineal< const Elemental[Length], Locational< const Elemental >, const Elemental >
    ReadLiner = {
        ReadIncrementScale< Indexical, Length, Elemental >,
        ReadDecrementScale< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Lineal< const Elemental[Length], Locational< const Elemental >, const Elemental >
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
    constexpr Lineal< Elemental[Length], Locational< Elemental >, Elemental >
    WriteLiner = {
        WriteIncrementScale< Indexical, Length, Elemental >,
        WriteDecrementScale< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Lineal< Elemental[Length], Locational< Elemental >, Elemental >
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
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, const Elemental >
    ReadIncrementDirection = {
        ReadIncrementScale< Indexical, Length, Elemental >,
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
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, const Elemental >
    SafeReadIncrementDirection = {
        SafeReadIncrementScale< Indexical, Length, Elemental >,
        Begins< Indexical, Length, const Elemental >,
        IncrementTraversableChecksForNull< Indexical, Length, const Elemental >,
        ContainsPositionChecksForNull< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Elemental >
    WriteIncrementDirection = {
        WriteIncrementScale< Indexical, Length, Elemental >,
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
    constexpr Directional< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteIncrementDirection = {
        SafeWriteIncrementScale< Indexical, Length, Elemental >,
        Begins< Indexical, Length, Elemental >,
        IncrementTraversableChecksForNull< Indexical, Length, Elemental >,
        ContainsPositionChecksForNull< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, const Elemental >
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
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, const Elemental >
    SafeReadDecrementDirection = {
        SafeReadDecrementScale< Indexical, Length, Elemental >,
        Begins< Indexical, Length, const Elemental >,
        DecrementTraversableChecksForNull< Indexical, Length, const Elemental >,
        ContainsPositionChecksForNull< Indexical, Length, const Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Elemental >
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
    constexpr Directional< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteDecrementDirection = {
        SafeWriteDecrementScale< Indexical, Length, Elemental >,
        Begins< Indexical, Length, Elemental >,
        DecrementTraversableChecksForNull< Indexical, Length, Elemental >,
        ContainsPositionChecksForNull< Indexical, Length, Elemental >
    };

    template <
        typename Indexical,
        Indexical
            Length,
        typename Elemental
    >
    constexpr Axial< const Elemental[Length], Locational< const Elemental >, const Elemental >
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
    constexpr Axial< const Elemental[Length], Locational< const Elemental >, const Elemental >
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
    constexpr Axial< Elemental[Length], Locational< Elemental >, Elemental >
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
    constexpr Axial< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteAxis = {
        SafeWriteIncrementDirection< Indexical, Length, Elemental >,
        SafeWriteDecrementDirection< Indexical, Length, Elemental >
    };

}

#endif
