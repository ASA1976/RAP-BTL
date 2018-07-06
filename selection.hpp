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
        typename Elemental
    >
    using Duplicative = bool(
        Referential< Consolidative >,
        Referential< const Directional< const Basic, BasicPositional, const Elemental > >,
        Referential< const Basic >
    );

    template <
        typename Basic,
        typename BasicPositional,
        typename Relative,
        typename RelativePositional,
        typename Elemental
    >
    using Equipollent = bool(
        Referential< const Directional< const Basic, BasicPositional, const Elemental > >,
        Referential< const Basic >,
        Referential< const Directional< const Relative, RelativePositional, const Elemental > >,
        Referential< const Relative >
    );

    template <
        typename Consolidative,
        typename Basic,
        typename BasicPositional,
        typename Relative,
        typename RelativePositional,
        typename Elemental
    >
    struct Sectional {

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >,
            Referential< const Basic >,
            Referential< const Directional< const Relative, RelativePositional, const Elemental > >,
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

        Referential< const Sectional< Consolidative, Consolidative, Positional, Consolidative, Positional, Elemental > >
            section;

        Referential< Duplicative< Consolidative, Consolidative, Positional, Elemental > >
            duplicate;

        Referential< Equipollent< Consolidative, Positional, Consolidative, Positional, Elemental > >
            equate;

        Referential< Natural(
            Referential< const Consolidative >
        ) >
            count;

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
    EquateSelections(
        Referential< const Directional< const Basic, BasicPositional, const Elemental > >
            basis,
        Referential< const Basic >
            base_set,
        Referential< const Directional< const Relative, RelativePositional, const Elemental > >
            relativity,
        Referential< const Relative >
            relative_set
    ) {
        static auto&
            SearchInRelative = SearchLinearly< Relative, RelativePositional, Elemental, Equate >;
        auto&
            scale = basis.scale;
        BasicPositional
            base_position;
        RelativePositional
            relative_position;
        if (basis.begins( base_set )) {
            for (scale.begin( base_set, base_position ); true; scale.traverse( base_set, base_position )) {
                if (!SearchInRelative( relative_set, relativity, scale.go( base_set, base_position ).to, relative_position ))
                    return false;
                if (!basis.traversable( base_set, base_position ))
                    break;
            }
        } else if (relativity.begins( relative_set ))
            return false;
        return true;
    }

}

#endif
