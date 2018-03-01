// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef LOCALIZATION_MODULE
#define LOCALIZATION_MODULE
#include "trajection.hpp"

namespace localization {

    using namespace ::trajection;

    template <
        typename Elemental
    >
    using WriteLocal = const Locational< Elemental >;

    template <
        typename Elemental
    >
    using ReadLocal = const Locational< const Elemental >;

    template <
        typename Elemental
    >
    using WritePositional = Locational< Elemental >;

    template <
        typename Elemental
    >
    using ReadPositional = Locational< const Elemental >;

    template <
        typename Elemental
    >
    static inline Conferential< Elemental >
    PositionalGo(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Locational< Elemental > >
            position
    ) {
        return Refer( position );
    }

    template <
        typename Elemental
    >
    static inline Conferential< Elemental >
    PositionalGoChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Locational< Elemental > >
            position
    ) {
        if (!position)
            throw position;
        return PositionalGo( locality, position );
    }

    template <
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    Begin(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        return position = locality;
    }

    template <
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        if (!locality)
            throw locality;
        return Begin( locality, position );
    }

    template <
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseIncrement(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        position++;
        return position;
    }

    template <
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseIncrementChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        if (!position)
            throw position;
        return TraverseIncrement( locality, position );
    }

    template <
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseDecrement(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        position--;
        return position;
    }

    template <
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseDecrementChecksForNull(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Locational< Elemental > >
            position
    ) {
        if (!position)
            throw position;
        return TraverseDecrement( locality, position );
    }

    template <
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadIncrementScale = {
        Begin< const Elemental >,
        TraverseIncrement< const Elemental >,
        PositionalGo< const Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadIncrementScaleChecksForNull = {
        BeginChecksForNull< const Elemental >,
        TraverseIncrementChecksForNull< const Elemental >,
        PositionalGoChecksForNull< const Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteIncrementScale = {
        Begin< Elemental >,
        TraverseIncrement< Elemental >,
        PositionalGo< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteIncrementScaleChecksForNull = {
        BeginChecksForNull< Elemental >,
        TraverseIncrementChecksForNull< Elemental >,
        PositionalGoChecksForNull< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadDecrementScale = {
        Begin< const Elemental >,
        TraverseDecrement< const Elemental >,
        PositionalGo< const Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadDecrementScaleChecksForNull = {
        BeginChecksForNull< const Elemental >,
        TraverseDecrementChecksForNull< const Elemental >,
        PositionalGoChecksForNull< const Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteDecrementScale = {
        Begin< Elemental >,
        TraverseDecrement< Elemental >,
        PositionalGo< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteDecrementScaleChecksForNull = {
        BeginChecksForNull< Elemental >,
        TraverseDecrementChecksForNull< Elemental >,
        PositionalGoChecksForNull< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadLiner = {
        ReadIncrementScale< Elemental >,
        ReadDecrementScale< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Locational< const Elemental >, const Elemental >
    ReadLinerChecksForNull = {
        ReadIncrementScaleChecksForNull< Elemental >,
        ReadDecrementScaleChecksForNull< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteLiner = {
        WriteIncrementScale< Elemental >,
        WriteDecrementScale< Elemental >
    };

    template <
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Locational< Elemental >, Elemental >
    WriteLinerChecksForNull = {
        WriteIncrementScaleChecksForNull< Elemental >,
        WriteDecrementScaleChecksForNull< Elemental >
    };

}

#endif
