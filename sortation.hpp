// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SORTATION_MODULE
#define SORTATION_MODULE
#include "trajection.hpp"

// Documentation Notes
// -------------------
// Equate:  Returns true if and only if both values are to be considered equivalent
// Order:    Return true if and only if the parametric order of the values is in sorted order

namespace sortation {

    using namespace ::trajection;

    template <
        typename Evaluative
    >
    using Assortive = bool(
		Referential< const Evaluative >,
		Referential< const Evaluative >
    );

    template <
        typename Relational
    >
    static inline bool
    EquateRelationally(
        Referential< const Relational >
            base,
        Referential< const Relational >
            relative
    ) {
        return base == relative;
    }

    template <
        typename Relational
    >
    static inline bool
    OrderRelationally(
        Referential< const Relational >
            base,
        Referential< const Relational >
            relative
    ) {
        return base < relative;
    }

    template <
        typename Relational
    >
    static inline bool
    OrderInversely(
        Referential< const Relational >
            base,
        Referential< const Relational >
            relative
    ) {
        return base > relative;
    }

    template <
        typename Spatial,
        typename Positional,
        typename Evaluative,
        Referential< Assortive< Evaluative > >
            Equate
    >
    static inline bool
    SearchLinearly(
        Referential< const Spatial >
            space,
        Referential< const Directional< const Spatial, Positional, const Evaluative > >
            direction,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position
    ) {
        auto
            scale = direction.scale;
        if (!direction.begins( space ))
            return false;
        for (scale.begin( space, position ); true; scale.traverse( space, position ))
            if (Equate( scale.go( space, position ).to, value ))
                return true;
            else if (!direction.traversable( space, position ))
                return false;
    }

    template <
        typename Spatial,
        typename Positional,
        typename Evaluative,
        Referential< const Directional< const Spatial, Positional, const Evaluative > >
            Direction,
        Referential< Assortive< Evaluative > >
            Equate
    >
    static inline bool
    SearchLinearly(
        Referential< const Spatial >
            space,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position
    ) {
        static auto
            Search = SearchLinearly< Spatial, Positional, Evaluative, Equate >;
        return Search( space, Direction, value, position );
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< Assortive< Evaluative > >
            Equate,
        Referential< Assortive< Evaluative > >
            Order
    >
    static inline bool
    SearchBisectionally(
        Referential< const Spatial >
            space,
        Referential< const Axial< const Spatial, Positional, const Evaluative > >
            axis,
        Referential< const Natural >
            count,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position
    ) {
        static auto
            go = axis.increment.scale.go;
        Natural
            remaining, move, offset;
        if (count <= 0 || !axis.increment.begins( space ))
            return false;
        axis.increment.scale.begin( space, position );
        for (remaining = count; remaining > 0; remaining -= move) {
            if (Equate( go( space, position ).to, value ))
                return true;
            move = remaining / 2;
            move = move ? move : 1;
            if (Order( go( space, position ).to, value ))
                for (offset = 0; offset < move; offset++)
                    if (axis.increment.traversable( space, position ))
                        axis.increment.scale.traverse( space, position );
                    else
                        break;
            else
                for (offset = 0; offset < move; offset++)
                    if (axis.decrement.traversable( space, position ))
                        axis.decrement.scale.traverse( space, position );
                    else
                        break;
        }
        if (Order( go( space, position ).to, value ))
            if (axis.increment.traversable( space, position ))
                axis.increment.scale.traverse( space, position );
        return false;
    }

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Evaluative,
        Referential< const Axial< const Spatial, Positional, const Evaluative > >
            Axis,
        Referential< Assortive< Evaluative > >
            Equate,
        Referential< Assortive< Evaluative > >
            Order
    >
    static inline bool
    SearchBisectionally(
        Referential< const Spatial >
            space,
        Referential< const Natural >
            count,
        Referential< const Evaluative >
            value,
        Referential< Positional >
            position
    ) {
        static auto
            Search = SearchBisectionally< Spatial, Positional, Natural, Evaluative, Equate, Order >;
        return Search( space, Axis, count, value, position );
    }

}

#endif
