// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SELECTION_MODULE
#define SELECTION_MODULE
#include "composition.hpp"
#include "sortation.hpp"

namespace selection {

    using namespace ::composition;
    using namespace ::sortation;

    template <
        typename Consolidative,
        typename Basic,
        typename BasicPositional,
        typename BasicNatural,
        typename Elemental
    >
    using Duplicative = bool(
        Referential< Consolidative >,
        Referential< const Directional< const Basic, BasicPositional, BasicNatural, const Elemental > >,
        Referential< const Basic >
    );

    template <
        typename Basic,
        typename BasicPositional,
        typename BasicNatural,
        typename Relative,
        typename RelativePositional,
        typename RelativeNatural,
        typename Elemental
    >
    using Equipollent = bool(
        Referential< const Directional< const Basic, BasicPositional, BasicNatural, const Elemental > >,
        Referential< const Basic >,
        Referential< const Directional< const Relative, RelativePositional, RelativeNatural, const Elemental > >,
        Referential< const Relative >
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
    struct Sectional {

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Directional< const Basic, BasicPositional, BasicNatural, const Elemental > >,
            Referential< const Basic >,
            Referential< const Directional< const Relative, RelativePositional, RelativeNatural, const Elemental > >,
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
    struct Selective {

        Referential< const Compositional< Consolidative, Natural, Elemental > >
            composer;

        Referential< const Sectional< Consolidative, Consolidative, Positional, Natural, Consolidative, Positional, Natural, Elemental > >
            section;

        Referential< Duplicative< Consolidative, Consolidative, Positional, Natural, Elemental > >
            duplicate;

        Referential< Equipollent< Consolidative, Positional, Natural, Consolidative, Positional, Natural, Elemental > >
            equate;

        Referential< Natural(
            Referential< const Consolidative >
        ) >
            count;

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
    EquateSelections(
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
        bool
            found;
        if (basis.begins( base_set, 0 )) {
            if (!relativity.begins( relative_set, 0 ))
                return false;
            for (basis.scale.begin( base_set, base_position, 0 ); true; basis.scale.traverse( base_set, base_position, 1 )) {
                found = false;
                for (relativity.scale.begin( relative_set, relative_position, 0 ); true; relativity.scale.traverse( relative_set, relative_position, 1 )) {
                    if (Equate( basis.scale.go( base_set, base_position ).to, relativity.scale.go( relative_set, relative_position ).to )) {
                        found = true;
                        break;
                    }
                }
                if (!found) 
                    return false;
            }
        } else if (relativity.begins( relative_set, 0 ))
            return false;
        return true;
    }

}

#endif
