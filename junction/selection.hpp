// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_SELECTION_MODULE
#define JUNCTION_SELECTION_MODULE
#include "consecution.hpp"
#include "../selection.hpp"

namespace junction {

    namespace selection {

        using namespace ::selection;
        using namespace ::sortation;
        using namespace ::junction::consecution;

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate
        >
        Referential< bool(
            Referential< const Junctive< Natural, Elemental > >,
            Referential< const Elemental >,
            Referential< Positional< Elemental > >
        ) >
        SearchSelection = SearchLinearly< Junctive< Natural, Elemental >, Positional< Elemental >, Elemental, ReadIncrementDirection< Natural, Elemental >, Equate >;

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        AccreditSelection(
            Referential< const Junctive< Natural, Elemental > >
                set,
            Referential< const Elemental >
                value
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                Search = SearchSelection< Natural, Elemental, Equate >;
            Positional< Elemental >
                position;
            return Search( set, value, position );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        ComposeSelection(
            Referential< Junctive< Natural, Elemental > >
                set,
            Referential< const Elemental >
                value
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                Search = SearchSelection< Natural, Elemental, Equate >;
            Positional< Elemental >
                position;
            if (Search( set, value, position ))
                return false;
            return Proceed( set, value );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Concessive< Natural, Elemental > >
                Concede,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        DiscomposeSelection(
            Referential< Junctive< Natural, Elemental > >
                set,
            Referential< const Elemental >
                value
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                Search = SearchSelection< Natural, Elemental, Equate >;
            static const Natural
                One = 1;
            Positional< Elemental >
                position;
            if (!Search( set, value, position ))
                return false;
            return Concede( set, position, One );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Concessive< Natural, Elemental > >
                Concede,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        RecomposeSelection(
            Referential< Junctive< Natural, Elemental > >
                set,
            Referential< const Elemental >
                original,
            Referential< const Elemental >
                replacement
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                Accredit = AccreditSelection< Natural, Elemental, Equate >;
            static auto&
                Discompose = DiscomposeSelection< Natural, Elemental, Concede, Equate >;
            if (Accredit( set, replacement ))
                return false;
            if (!Proceed( set, replacement ))
                return false;
            return Discompose( set, original );
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Natural, Elemental > >
                Proceed
        >
        static inline bool
        DuplicateSelection(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            auto&
                scale = basis.scale;
            BasicPositional
                position;
            Empty( operand );
            if (!basis.begins( base ))
                return false;
            for (scale.begin( base, position ); true; scale.traverse( base, position )) {
                if (!Proceed( operand, scale.go( base, position ).to ))
                    return false;
                if (!basis.traversable( base, position ))
                    break;
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename Relative,
            typename RelativePositional,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        ComplementSelections(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Directional< const Relative, RelativePositional, const Elemental > >
                relativity,
            Referential< const Relative >
                relative_set
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                SearchInBase = SearchLinearly< Basic, BasicPositional, Elemental, Equate >;
            auto&
                scale = relativity.scale;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Empty( operand );
            if (relativity.begins( relative_set )) {
                for (scale.begin( relative_set, relative_position ); true; scale.traverse( relative_set, relative_position )) {
                    if (!SearchInBase( base_set, basis, scale.go( relative_set, relative_position ).to, base_position ))
                        if (!Proceed( operand, scale.go( relative_set, relative_position ).to ))
                            return false;
                    if (!relativity.traversable( relative_set, relative_position ))
                        break;
                }
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename Relative,
            typename RelativePositional,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        DifferentiateSelections(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Directional< const Relative, RelativePositional, const Elemental > >
                relativity,
            Referential< const Relative >
                relative_set
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                SearchInBase = SearchLinearly< Basic, BasicPositional, Elemental, Equate >;
            static auto&
                SearchInRelative = SearchLinearly< Relative, RelativePositional, Elemental, Equate >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Empty( operand );
            if (basis.begins( base_set )) {
                for (basis.scale.begin( base_set, base_position ); true; basis.scale.traverse( base_set, base_position )) {
                    if (!SearchInRelative( relative_set, relativity, basis.scale.go( base_set, base_position ).to, relative_position )) {
                        if (!Proceed( operand, basis.scale.go( base_set, base_position ).to ))
                            return false;
                    }
                    if (!basis.traversable( base_set, base_position ))
                        break;
                }
            }
            if (relativity.begins( relative_set )) {
                for (relativity.scale.begin( relative_set, relative_position ); true; relativity.scale.traverse( relative_set, relative_position )) {
                    if (!SearchInBase( base_set, basis, relativity.scale.go( relative_set, relative_position ).to, base_position )) {
                        if (!Proceed( operand, relativity.scale.go( relative_set, relative_position ).to ))
                            return false;
                    }
                    if (!relativity.traversable( relative_set, relative_position ))
                        break;
                }
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename Relative,
            typename RelativePositional,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        IntersectSelections(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Directional< const Relative, RelativePositional, const Elemental > >
                relativity,
            Referential< const Relative >
                relative_set
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                SearchInBase = SearchLinearly< Basic, BasicPositional, Elemental, Equate >;
            auto&
                scale = relativity.scale;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Empty( operand );
            if (relativity.begins( relative_set )) {
                for (scale.begin( relative_set, relative_position ); true; scale.traverse( relative_set, relative_position )) {
                    if (SearchInBase( base_set, basis, scale.go( relative_set, relative_position ).to, base_position)) {
                        if (!Proceed( operand, scale.go( relative_set, relative_position ).to ))
                            return false;
                    }
                    if (!relativity.traversable( relative_set, relative_position ))
                        break;
                }
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename Relative,
            typename RelativePositional,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        UniteSelections(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Directional< const Relative, RelativePositional, const Elemental > >
                relativity,
            Referential< const Relative >
                relative_set
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                ComposeUnion = ComposeSelection< Natural, Elemental, Proceed, Equate >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Empty( operand );
            if (basis.begins( base_set )) {
                for (basis.scale.begin( base_set, base_position ); true; basis.scale.traverse( base_set, base_position )) {
                    if (!Proceed( operand, basis.scale.go( base_set, base_position ).to ))
                        return false;
                    if (!basis.traversable( base_set, base_position ))
                        break;
                }
            }
            if (relativity.begins( relative_set )) {
                for (relativity.scale.begin( relative_set, relative_position ); true; relativity.scale.traverse( relative_set, relative_position )) {
                    ComposeUnion( operand, relativity.scale.go( relative_set, relative_position ).to );
                    if (!relativity.traversable( relative_set, relative_position ))
                        break;
                }
            }
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate
        >
        constexpr Compositional< Junctive< Natural, Elemental >, Natural, Elemental >
        JunctionComposer = {
            Instantiate< Natural, Elemental, Adjunct >,
            AccreditSelection< Natural, Elemental, Equate >,
            ComposeSelection< Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            RecomposeSelection< Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Concede, Equate >,
            DiscomposeSelection< Natural, Elemental, Concede, Equate >,
            Empty,
            Free< Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate
        >
        constexpr Compositional< Junctive< Natural, Elemental >, Natural, Elemental >
        SafeJunctionComposer = {
            Instantiate< Natural, Elemental, Adjunct >,
            AccreditSelection< Natural, Elemental, Equate >,
            ComposeSelection< Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            RecomposeSelection< Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, ConcedeSafely, Equate >,
            DiscomposeSelection< Natural, Elemental, ConcedeSafely, Equate >,
            Empty,
            Free< Natural, Elemental, Adjunct >
        };

        template <
            typename Basic,
            typename BasicPositional,
            typename Relative,
            typename RelativePositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate
        >
        constexpr Sectional< Junctive< Natural, Elemental >, Basic, BasicPositional, Relative, RelativePositional, Elemental >
        JunctionSection = {
            ComplementSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            DifferentiateSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            IntersectSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            UniteSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >
        };

        template <
            typename Basic,
            typename BasicPositional,
            typename Relative,
            typename RelativePositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate
        >
        constexpr Sectional< Junctive< Natural, Elemental >, Basic, BasicPositional, Relative, RelativePositional, Elemental >
        SafeJunctionSection = {
            ComplementSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            DifferentiateSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            IntersectSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            UniteSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate
        >
        constexpr Selective< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental >
        JunctionSelector = {
            JunctionComposer< Natural, Elemental, Adjunct, Equate >,
            JunctionSection< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct, Equate >,
            DuplicateSelection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Proceed< Natural, Elemental, Adjunct > >,
            EquateSelections< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Elemental, Equate >,
            Account< Natural, Elemental >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate
        >
        constexpr Selective< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental >
        SafeJunctionSelector = {
            SafeJunctionComposer< Natural, Elemental, Adjunct, Equate >,
            SafeJunctionSection< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct, Equate >,
            DuplicateSelection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Proceed< Natural, Elemental, Adjunct > >,
            EquateSelections< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Elemental, Equate >,
            Account< Natural, Elemental >
        };

    }

}

#endif
