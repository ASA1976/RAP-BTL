// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef TRAJECTION_MODULE
#define TRAJECTION_MODULE
#include "comparison.hpp"
#include <type_traits>

namespace trajection {

    using namespace ::location;
    using ::comparison::Comparative;

    template <
        typename Spatial
    >
    using Reachable = bool(
        Referential< const Spatial >
    );

    template <
        typename Spatial,
        typename Positional
    >
    using Traversable = bool(
        Referential< const Spatial >,
        Referential< const Positional >
    );

    template <
        typename Spatial,
        typename Positional
    >
    using Trajectile = Referential< const Positional >(
        Referential< Spatial >,
        Referential< Positional >
    );

    template <
        typename Spatial,
        typename Positional,
        typename Endemical
    >
    using Expositive = Conferential< Endemical >(
        Referential< Spatial >,
        Referential< const Positional >
    );

    template <
        typename Spatial,
        typename Positional,
        typename Endemical
    >
    struct Vectorial {

        Referential< const Comparative< Positional > >
            order;

        Referential< Traversable< Spatial, Positional > >
            contains;

        Referential< Expositive< Spatial, Positional, Endemical > >
            go;

    };

    template <
        typename Spatial,
        typename Positional,
        typename Endemical
    >
    struct Scalar {

        Referential< const Comparative< Positional > >
            order;

        Referential< Trajectile< Spatial, Positional > >
            begin,
            traverse;

        Referential< Expositive< Spatial, Positional, Endemical > >
            go;

    };

    template <
        typename Spatial,
        typename Positional,
        typename Endemical
    >
    struct Lineal {

        Referential< const Scalar< Spatial, Positional, Endemical > >
            increment,
            decrement;

    };

    template <
        typename Spatial,
        typename Positional,
        typename Endemical
    >
    struct Directional {

        Referential< const Scalar< Spatial, Positional, Endemical > >
            scale;

        Referential< Reachable< Spatial > >
            begins;

        Referential< Traversable< Spatial, Positional > >
            traversable;

        Referential< Traversable< Spatial, Positional > >
            meets;

    };

    template <
        typename Spatial,
        typename Positional,
        typename Endemical
    >
    struct Axial {

        Referential< const Directional< Spatial, Positional, Endemical > >
            increment,
            decrement;

    };

    template <
        typename Spatial,
        typename Positional,
        typename Endemical,
        typename Natural
    >
    static inline bool
    Count(
        Referential< Spatial >
            space,
        Referential< const Directional< Spatial, Positional, Endemical > >
            direction,
        Referential< Positional >
            position,
        Referential< Natural >
            count
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        static auto&
            scale = direction.scale;
        if (!direction.begins( space ))
            return false;
        count = 0;
        for (scale.begin( space, position ); true; scale.traverse( space, position )) {
            count++;
            if (!direction.traversable( space, position ))
                return true;
        }
    }

    template <
        typename Spatial,
        typename Positional,
        typename Endemical,
        typename Natural,
        Referential< const Directional< Spatial, Positional, Endemical > >
            Direction
    >
    static inline bool
    Count(
        Referential< Spatial >
            space,
        Referential< Positional >
            position,
        Referential< Natural >
            count
    ) {
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
        return Count( space, Direction, position, count );
    }

}

#endif
