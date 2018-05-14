// � 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ORDINATION_MODULE
#define ORDINATION_MODULE
#include "trajection.hpp"
#include <type_traits>

namespace ordination {

    using namespace ::trajection;

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    using WriteOrdinal = Elemental[Length];

    template <
        typename Natural,
        Natural
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
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    ContainsIndex(
        Referential< const Elemental[Length] >
            array,
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
    static inline Conferential< Elemental >
    NaturalGo(
        Referential< Elemental[Length] >
            array,
        Referential< const Natural >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return Confer( array[index] );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Conferential< Elemental >
    NaturalGoSafely(
        Referential< Elemental[Length] >
            array,
        Referential< const Natural >
            index
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        if (!ContainsIndex( array, index ))
            throw index;
        return NaturalGo( array, index );
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return position >= array && position <= array + Length - 1;
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static Referential< bool(
            Referential< const Elemental[Length] >,
            Referential< const Locational< Elemental > >
        ) >
            Contains = ContainsPosition< Natural, Length, Elemental >;
        if (!position)
            throw position;
        return Contains( array, position );
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return Refer( position );
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static Referential< bool(
            Referential< const Elemental[Length] >,
            Referential< const Locational< Elemental > >
        ) >
            Contains = ContainsPositionChecksForNull< Natural, Length, Elemental >;
        static Referential< Conferential< Elemental >(
            Referential< Elemental[Length] >,
            Referential< const Locational< Elemental > >
        ) >
            Go = PositionalGo< Natural, Length, Elemental >;
        if (!Contains( array, position ))
            throw position;
        return Go( array, position );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    Begins(
        Referential< const Elemental[Length] >
            array
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
    static inline Referential< const Locational< Elemental > >
    BeginIncrement(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position = array;
        return position;
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position = array + Length - 1;
        return position;
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return position < array + Length - 1;
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static Referential< bool(
            Referential< const Elemental[Length] >,
            Referential< const Locational< Elemental > >
        ) >
            Traversable = IncrementTraversable< Natural, Length, Elemental >;
        if (!position)
            throw position;
        return Traversable( array, position );
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return position > array;
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static Referential< bool(
            Referential< const Elemental[Length] >,
            Referential< const Locational< Elemental > >
        ) >
            Traversable = DecrementTraversable< Natural, Length, Elemental >;
        if (!position)
            throw position;
        return Traversable( array, position );
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position++;
        return position;
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static Referential< bool(
            Referential< const Elemental[Length] >,
            Referential< const Locational< Elemental > >
        ) >
            Traversable = IncrementTraversableChecksForNull< Natural, Length, Elemental >;
        static Referential< Referential< const Locational< Elemental > >(
            Referential< Elemental[Length] >,
            Referential< Locational< Elemental > >
        ) >
            Traverse = TraverseIncrement< Natural, Length, Elemental >;
        if (!Traversable( array, position ))
            throw position;
        return Traverse( array, position );
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        position--;
        return position;
    }

    template <
        typename Natural,
        Natural
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
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static Referential< bool(
            Referential< const Elemental[Length] >,
            Referential< const Locational< Elemental > >
        ) >
            Traversable = DecrementTraversableChecksForNull< Natural, Length, Elemental >;
        static Referential< Referential< const Locational< Elemental > >(
            Referential< Elemental[Length] >,
            Referential< Locational< Elemental > >
        ) >
            Traverse = TraverseDecrement< Natural, Length, Elemental >;
        if (!Traversable( array, position ))
            throw position;
        return Traverse( array, position );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Elemental[Length], Natural, const Elemental >
    ReadVector = {
        ContainsIndex< Natural, Length, const Elemental >,
        NaturalGo< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Elemental[Length], Natural, const Elemental >
    SafeReadVector = {
        ContainsIndex< Natural, Length, const Elemental >,
        NaturalGoSafely< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< Elemental[Length], Natural, Elemental >
    WriteVector = {
        ContainsIndex< Natural, Length, Elemental >,
        NaturalGo< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< Elemental[Length], Natural, Elemental >
    SafeWriteVector = {
        ContainsIndex< Natural, Length, Elemental >,
        NaturalGoSafely< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, const Elemental >
    ReadIncrementScale = {
        BeginIncrement< Natural, Length, const Elemental >,
        TraverseIncrement< Natural, Length, const Elemental >,
        PositionalGo< Natural, Length, const Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, const Elemental >
    SafeReadIncrementScale = {
        BeginIncrement< Natural, Length, const Elemental >,
        TraverseIncrementSafely< Natural, Length, const Elemental >,
        PositionalGoSafely< Natural, Length, const Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Elemental >
    WriteIncrementScale = {
        BeginIncrement< Natural, Length, Elemental >,
        TraverseIncrement< Natural, Length, Elemental >,
        PositionalGo< Natural, Length, Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteIncrementScale = {
        BeginIncrement< Natural, Length, Elemental >,
        TraverseIncrementSafely< Natural, Length, Elemental >,
        PositionalGoSafely< Natural, Length, Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, const Elemental >
    ReadDecrementScale = {
        BeginDecrement< Natural, Length, const Elemental >,
        TraverseDecrement< Natural, Length, const Elemental >,
        PositionalGo< Natural, Length, const Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, const Elemental >
    SafeReadDecrementScale = {
        BeginDecrement< Natural, Length, const Elemental >,
        TraverseDecrementSafely< Natural, Length, const Elemental >,
        PositionalGoSafely< Natural, Length, const Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Elemental >
    WriteDecrementScale = {
        BeginDecrement< Natural, Length, Elemental >,
        TraverseDecrement< Natural, Length, Elemental >,
        PositionalGo< Natural, Length, Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteDecrementScale = {
        BeginDecrement< Natural, Length, Elemental >,
        TraverseDecrementSafely< Natural, Length, Elemental >,
        PositionalGoSafely< Natural, Length, Elemental >,
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Elemental[Length], Locational< const Elemental >, const Elemental >
    ReadLiner = {
        ReadIncrementScale< Natural, Length, Elemental >,
        ReadDecrementScale< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Elemental[Length], Locational< const Elemental >, const Elemental >
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
    constexpr Lineal< Elemental[Length], Locational< Elemental >, Elemental >
    WriteLiner = {
        WriteIncrementScale< Natural, Length, Elemental >,
        WriteDecrementScale< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< Elemental[Length], Locational< Elemental >, Elemental >
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
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, const Elemental >
    ReadIncrementDirection = {
        ReadIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        IncrementTraversable< Natural, Length, const Elemental >,
        ContainsPosition< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, const Elemental >
    SafeReadIncrementDirection = {
        SafeReadIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        IncrementTraversableChecksForNull< Natural, Length, const Elemental >,
        ContainsPositionChecksForNull< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Elemental >
    WriteIncrementDirection = {
        WriteIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        IncrementTraversable< Natural, Length, Elemental >,
        ContainsPosition< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteIncrementDirection = {
        SafeWriteIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        IncrementTraversableChecksForNull< Natural, Length, Elemental >,
        ContainsPositionChecksForNull< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, const Elemental >
    ReadDecrementDirection = {
        ReadDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        DecrementTraversable< Natural, Length, const Elemental >,
        ContainsPosition< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, const Elemental >
    SafeReadDecrementDirection = {
        SafeReadDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        DecrementTraversableChecksForNull< Natural, Length, const Elemental >,
        ContainsPositionChecksForNull< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Elemental >
    WriteDecrementDirection = {
        WriteDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        DecrementTraversable< Natural, Length, Elemental >,
        ContainsPosition< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteDecrementDirection = {
        SafeWriteDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        DecrementTraversableChecksForNull< Natural, Length, Elemental >,
        ContainsPositionChecksForNull< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Elemental[Length], Locational< const Elemental >, const Elemental >
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
    constexpr Axial< const Elemental[Length], Locational< const Elemental >, const Elemental >
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
    constexpr Axial< Elemental[Length], Locational< Elemental >, Elemental >
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
    constexpr Axial< Elemental[Length], Locational< Elemental >, Elemental >
    SafeWriteAxis = {
        SafeWriteIncrementDirection< Natural, Length, Elemental >,
        SafeWriteDecrementDirection< Natural, Length, Elemental >
    };

}

#endif
