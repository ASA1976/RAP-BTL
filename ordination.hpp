// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ORDINATION_MODULE
#define ORDINATION_MODULE
#include "trajection.hpp"
#include "comparison.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ordination {

    using namespace ::trajection;
    using ::comparison::Comparison;

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
    static inline Conferential< Elemental >
    NaturalGo(
        Referential< Elemental[Length] >
            array,
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Contains = ContainsPositionChecksForNull< Natural, Length, Elemental >;
        static auto&
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
            array,
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
        return count < Length;
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
            position,
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
        return position = array + count;
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
            position,
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
        return position = array + Length - 1 - count;
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
            position,
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
        return count < Length && position < array + Length - count;
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
            position,
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
        if (!position)
            throw position;
        return Traversable( array, position, count );
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
            position,
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
        return count < Length && position > array + Length - 1 - count;
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
            position,
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
        if (!position)
            throw position;
        return Traversable( array, position, count );
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
            position,
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
        return position += count;
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
            position,
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
            Traversable = IncrementTraversableChecksForNull< Natural, Length, Elemental >;
        static auto&
            Traverse = TraverseIncrement< Natural, Length, Elemental >;
        if (!Traversable( array, position, count ))
            throw count;
        return Traverse( array, position, count );
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
            position,
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
        return position -= count;
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
            position,
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
        static auto&
            Traverse = TraverseDecrement< Natural, Length, Elemental >;
        if (!Traversable( array, position, count ))
            throw count;
        return Traverse( array, position, count );
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    Account(
        Referential< Elemental[Length] >
            array
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
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return (Natural) (array + Length - position);
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    CountDecrement(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return (Natural) (position - array);
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
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    ReadIncrementScale = {
        Comparison< Locational< const Elemental > >,
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
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    SafeReadIncrementScale = {
        Comparison< Locational< const Elemental > >,
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
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    WriteIncrementScale = {
        Comparison< Locational< Elemental > >,
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
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteIncrementScale = {
        Comparison< Locational< Elemental > >,
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
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    ReadDecrementScale = {
        Comparison< Locational< const Elemental > >,
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
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    SafeReadDecrementScale = {
        Comparison< Locational< const Elemental > >,
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
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    WriteDecrementScale = {
        Comparison< Locational< Elemental > >,
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
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteDecrementScale = {
        Comparison< Locational< Elemental > >,
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
    constexpr Lineal< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
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
    constexpr Lineal< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
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
    constexpr Lineal< Elemental[Length], Locational< Elemental >, Natural, Elemental >
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
    constexpr Lineal< Elemental[Length], Locational< Elemental >, Natural, Elemental >
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
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    ReadIncrementDirection = {
        ReadIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        IncrementTraversable< Natural, Length, const Elemental >,
        ContainsPosition< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountIncrement< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    SafeReadIncrementDirection = {
        SafeReadIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        IncrementTraversableChecksForNull< Natural, Length, const Elemental >,
        ContainsPositionChecksForNull< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountIncrement< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    WriteIncrementDirection = {
        WriteIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        IncrementTraversable< Natural, Length, Elemental >,
        ContainsPosition< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountIncrement< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteIncrementDirection = {
        SafeWriteIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        IncrementTraversableChecksForNull< Natural, Length, Elemental >,
        ContainsPositionChecksForNull< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountIncrement< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    ReadDecrementDirection = {
        ReadDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        DecrementTraversable< Natural, Length, const Elemental >,
        ContainsPosition< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountDecrement< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    SafeReadDecrementDirection = {
        SafeReadDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        DecrementTraversableChecksForNull< Natural, Length, const Elemental >,
        ContainsPositionChecksForNull< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountDecrement< Natural, Length, const Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    WriteDecrementDirection = {
        WriteDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        DecrementTraversable< Natural, Length, Elemental >,
        ContainsPosition< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountDecrement< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteDecrementDirection = {
        SafeWriteDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        DecrementTraversableChecksForNull< Natural, Length, Elemental >,
        ContainsPositionChecksForNull< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountDecrement< Natural, Length, Elemental >
    };

    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
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
    constexpr Axial< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
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
    constexpr Axial< Elemental[Length], Locational< Elemental >, Natural, Elemental >
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
    constexpr Axial< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteAxis = {
        SafeWriteIncrementDirection< Natural, Length, Elemental >,
        SafeWriteDecrementDirection< Natural, Length, Elemental >
    };

}

#endif
