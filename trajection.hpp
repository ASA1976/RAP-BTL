// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef TRAJECTION_MODULE
#define TRAJECTION_MODULE
#include "comparison.hpp"

namespace trajection {

    using namespace ::location;
    using ::comparison::Comparative;

    template <
        typename Spatial,
        typename Natural
    >
    using Enterable = bool(
        Referential< const Spatial >,
        Referential< const Natural >
    );

    template <
        typename Spatial,
        typename Positional
    >
    using Attainable = bool(
        Referential< const Spatial >,
        Referential< const Positional >
    );

    template <
        typename Spatial,
        typename Positional,
        typename Natural
    >
    using Traversable = bool(
        Referential< const Spatial >,
        Referential< const Positional >,
        Referential< const Natural >
    );

    template <
        typename Spatial,
        typename Positional,
        typename Natural
    >
    using Trajectile = Referential< const Positional >(
        Referential< Spatial >,
        Referential< Positional >,
        Referential< const Natural >
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
        typename Natural
    >
    using Aggregate = Natural(
        Referential< const Spatial >
    );

    template <
        typename Spatial,
        typename Positional,
        typename Natural
    >
    using Cumulative = Natural(
        Referential< const Spatial >,
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

        Referential< Attainable< Spatial, Positional > >
            contains;

        Referential< Expositive< Spatial, Positional, Endemical > >
            go;

    };

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Endemical
    >
    struct Scalar {

        Referential< const Comparative< Positional > >
            order;

        Referential< Trajectile< Spatial, Positional, Natural > >
            begin,
            traverse;

        Referential< Expositive< Spatial, Positional, Endemical > >
            go;

    };

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Endemical
    >
    struct Lineal {

        Referential< const Scalar< Spatial, Positional, Natural, Endemical > >
            increment,
            decrement;

    };

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Endemical
    >
    struct Directional {

        Referential< const Scalar< Spatial, Positional, Natural, Endemical > >
            scale;

        Referential< Enterable< Spatial, Natural > >
            begins;

        Referential< Traversable< Spatial, Positional, Natural > >
            traversable;

        Referential< Attainable< Spatial, Positional > >
            meets;

        Referential< Aggregate< Spatial, Natural > >
            survey;

        Referential< Cumulative< Spatial, Positional, Natural > >
            count;

    };

    template <
        typename Spatial,
        typename Positional,
        typename Natural,
        typename Endemical
    >
    struct Axial {

        Referential< const Directional< Spatial, Positional, Natural, Endemical > >
            increment,
            decrement;

    };

}

#endif
