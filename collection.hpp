// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef COLLECTION_MODULE
#define COLLECTION_MODULE
#include "selection.hpp"

namespace collection {

    using namespace ::selection;

    template <
        typename Consolidative,
        typename Basic,
        typename BasicPositional,
        typename Elemental
    >
    using Collative = bool(
        Referential< Consolidative >,
        Referential< const Axial< const Basic, BasicPositional, const Elemental > >,
        Referential< const Basic >
    );

    template <
        typename Consolidative,
        typename Basic,
        typename BasicPositional,
        typename Relative,
        typename RelativePositional,
        typename Elemental
    >
    struct Bisectional {

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Axial< const Basic, BasicPositional, const Elemental > >,
            Referential< const Basic >,
            Referential< const Axial< const Relative, RelativePositional, const Elemental > >,
            Referential< const Relative >
        ) >
            complement,
            differentiate,
            intersect,
            unite;

    };

    template <
        typename Consolidative,
        typename Positional,
        typename Natural,
        typename Elemental
    >
    struct Collective {

        Referential< const Selective< Consolidative, Positional, Natural, Elemental > >
            selector;

        Referential< const Bisectional< Consolidative, Consolidative, Positional, Consolidative, Positional, Elemental > >
            bisection;

        Referential< Collative< Consolidative, Consolidative, Positional, Elemental > >
            collate;

        Referential< Equipollent< Consolidative, Positional, Consolidative, Positional, Elemental > >
            correlate;

    };

    template <
        typename Basic,
        typename BasicPositional,
        typename Relative,
        typename RelativePositional,
        typename Elemental,
        Referential< Assortive< Elemental > >
            Equate
    >
    static inline bool
    EquateCollections(
        Referential< const Directional< const Basic, BasicPositional, const Elemental > >
            basis,
        Referential< const Basic >
            base_set,
        Referential< const Directional< const Relative, RelativePositional, const Elemental > >
            relativity,
        Referential< const Relative >
            relative_set
    ) {
        BasicPositional
            base_position;
        RelativePositional
            relative_position;
        if (basis.begins( base_set )) {
            if (!relativity.begins( relative_set ))
                return false;
            basis.scale.begin( base_set, base_position );
            relativity.scale.begin( relative_set, relative_position );
            while (true) {
                if (!Equate( basis.scale.go( base_set, base_position ).to, relativity.scale.go( relative_set, relative_position ).to ))
                    return false;
                if (!basis.traversable( base_set, base_position )) {
                    if (relativity.traversable( relative_set, relative_position ))
                        return false;
                    break;
                }
                basis.scale.traverse( base_set, base_position );
                relativity.scale.traverse( relative_set, relative_position );
            }
        } else if (relativity.begins( relative_set ))
            return false;
        return true;
    }

}

#endif
