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
        typename BasicNatural,
        typename Elemental
    >
    using Collative = bool(
        Referential< Consolidative >,
        Referential< const Axial< const Basic, BasicPositional, BasicNatural, const Elemental > >,
        Referential< const Basic >
    );

    template <
        typename Consolidative,
        typename Basic,
        typename BasicPositional,
        typename BasicNatural,
        typename Relative,
        typename RelativePositional,
        typename RelativeNatural,
        typename Elemental
    >
    struct Bisectional {

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Axial< const Basic, BasicPositional, BasicNatural, const Elemental > >,
            Referential< const Basic >,
            Referential< const Axial< const Relative, RelativePositional, RelativeNatural, const Elemental > >,
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

        Referential< const Bisectional< Consolidative, Consolidative, Positional, Natural, Consolidative, Positional, Natural, Elemental > >
            bisection;

        Referential< Collative< Consolidative, Consolidative, Positional, Natural, Elemental > >
            collate;

        Referential< Equipollent< Consolidative, Positional, Natural, Consolidative, Positional, Natural, Elemental > >
            correlate;

    };

    template <
        typename Basic,
        typename BasicPositional,
        typename BasicNatural,
        typename Relative,
        typename RelativePositional,
        typename RelativeNatural,
        typename Elemental,
        Referential< Assortive< Elemental > >
            Equate
    >
    static inline bool
    EquateCollections(
        Referential< const Directional< const Basic, BasicPositional, BasicNatural, const Elemental > >
            basis,
        Referential< const Basic >
            base_set,
        Referential< const Directional< const Relative, RelativePositional, RelativeNatural, const Elemental > >
            relativity,
        Referential< const Relative >
            relative_set
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< BasicNatural >::value && is_unsigned< BasicNatural >::value,
            "BasicNatural:  Unsigned integer type required"
        );
        static_assert(
            is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
            "RelativeNatural:  Unsigned integer type required"
        );
#endif
        BasicPositional
            base_position;
        RelativePositional
            relative_position;
        if (basis.begins( base_set, 0 )) {
            if (!relativity.begins( relative_set, 0 ))
                return false;
            basis.scale.begin( base_set, base_position, 0 );
            relativity.scale.begin( relative_set, relative_position, 0 );
            while (true) {
                if (!Equate( basis.scale.go( base_set, base_position ).to, relativity.scale.go( relative_set, relative_position ).to ))
                    return false;
                if (!basis.traversable( base_set, base_position, 1 )) {
                    if (relativity.traversable( relative_set, relative_position, 1 ))
                        return false;
                    break;
                }
                basis.scale.traverse( base_set, base_position, 1 );
                relativity.scale.traverse( relative_set, relative_position, 1 );
            }
        } else if (relativity.begins( relative_set, 0 ))
            return false;
        return true;
    }

}

#endif
