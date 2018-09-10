// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_SELECTION_MODULE
#define JUNCTION_SELECTION_MODULE
#include "consecution.hpp"
#include "../selection.hpp"

namespace junction {

    namespace selection {

        using ::composition::Compositional;
        using ::selection::Selective;
        using ::selection::Sectional;
        using ::selection::EquateSelections;
        using ::sortation::Assortive;
        using ::sortation::SearchLinearly;
        using ::junction::consecution::Consequent;
        using ::junction::consecution::Concessive;
        using ::junction::consecution::Proceed;
        using ::junction::consecution::Concede;
        using ::junction::consecution::ConcedeSafely;

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate
        >
        Referential< bool(
            Referential< const Junctive< Natural, Elemental > >,
            Referential< const Elemental >,
            Referential< Positional< Elemental > >,
            Natural
        ) >
        SearchSelection = SearchLinearly< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadIncrementScale< Natural, Elemental >, Equate >;

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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
#ifndef _MSC_VER
				Search = SearchSelection< Natural, Elemental, Equate >;
#else
                // Problem 286153 filed July 3 2018
                Search = SearchLinearly< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadIncrementScale< Natural, Elemental >, Equate >;
#endif
            static const Natural
                Zero = 0;
            Positional< Elemental >
                position;
            if (!IncrementBegins( set, Zero ))
                return false;
            BeginReadIncrement( set, position, Zero );
            return Search( set, value, position, Account( set ) - 1 );
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
#ifndef _MSC_VER
				Search = SearchSelection< Natural, Elemental, Equate >;
#else
                // Problem 286153 filed July 3 2018
                Search = SearchLinearly< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadIncrementScale< Natural, Elemental >, Equate >;
#endif
            static const Natural
                Zero = 0;
			Positional< Elemental >
                position;
            if (!IncrementBegins( set, Zero ))
                return Proceed( set, value );
            BeginWriteIncrement( set, position, Zero );
            if (Search( set, value, position, Account( set ) - 1 ))
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
#ifndef _MSC_VER
				Search = SearchSelection< Natural, Elemental, Equate >;
#else
                // Problem 286153 filed July 3 2018
                Search = SearchLinearly< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadIncrementScale< Natural, Elemental >, Equate >;
#endif
			static const Natural
                Zero = 0,
                One = 1;
            Positional< Elemental >
                position;
            if (!IncrementBegins( set, Zero ))
                return false;
            BeginWriteIncrement( set, position, Zero );
            if (!Search( set, value, position, Account( set ) - 1 ))
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                Accredit = AccreditSelection< Natural, Elemental, Equate >;
            static auto&
                Discompose = DiscomposeSelection< Natural, Elemental, Concede, Equate >;
            if (!Accredit( set, original ))
                return false;
            if (Accredit( set, replacement ))
                return false;
            if (!Proceed( set, replacement ))
                return false;
            return Discompose( set, original );
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Natural, Elemental > >
                Proceed
        >
        static inline bool
        DuplicateSelection(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Directional< const Basic, BasicPositional, BasicNatural, const Elemental > >
                basis,
            Referential< const Basic >
                base
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< BasicNatural >::value && is_unsigned< BasicNatural >::value,
                "BasicNatural:  Unsigned integer type required"
            );
#endif
            auto&
                scale = basis.scale;
            BasicPositional
                position;
            Empty( operand );
            if (!basis.begins( base, 0 ))
                return false;
            for (scale.begin( base, position, 0 ); true; scale.traverse( base, position, 1 )) {
                if (!Proceed( operand, scale.go( base, position ).to ))
                    return false;
                if (!basis.traverses( base, position, 1 ))
                    break;
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
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
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< BasicNatural >::value && is_unsigned< BasicNatural >::value,
                "BasicNatural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
                "RelativeNatural:  Unsigned integer type required"
            );
#endif
            static auto&
                SearchInBase = SearchLinearly< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            auto&
                scale = relativity.scale;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                extent;
            Empty( operand );
            if (relativity.begins( relative_set, 0 )) {
                if (!basis.begins( base_set, 0 ))
                    return true;
                extent = basis.survey( base_set ) - 1;
                for (scale.begin( relative_set, relative_position, 0 ); true; scale.traverse( relative_set, relative_position, 1 )) {
                    basis.scale.begin( base_set, base_position, 0 );
                    if (!SearchInBase( base_set, basis.scale, scale.go( relative_set, relative_position ).to, base_position, extent ))
                        if (!Proceed( operand, scale.go( relative_set, relative_position ).to ))
                            return false;
                    if (!relativity.traverses( relative_set, relative_position, 1 ))
                        break;
                }
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
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
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< BasicNatural >::value && is_unsigned< BasicNatural >::value,
                "BasicNatural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
                "RelativeNatural:  Unsigned integer type required"
            );
#endif
            static auto&
                SearchInBase = SearchLinearly< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            static auto&
                SearchInRelative = SearchLinearly< Relative, RelativePositional, RelativeNatural, Elemental, Equate >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                base_extent;
            RelativeNatural
                relative_extent;
            Empty( operand );
            if (basis.begins( base_set, 0 )) {
                relative_extent = relativity.survey( relative_set ) - 1;
                for (basis.scale.begin( base_set, base_position, 0 ); true; basis.scale.traverse( base_set, base_position, 1 )) {
                    relativity.scale.begin( relative_set, relative_position, 0 );
                    if (!SearchInRelative( relative_set, relativity.scale, basis.scale.go( base_set, base_position ).to, relative_position, relative_extent )) {
                        if (!Proceed( operand, basis.scale.go( base_set, base_position ).to ))
                            return false;
                    }
                    if (!basis.traverses( base_set, base_position, 1 ))
                        break;
                }
            }
            if (relativity.begins( relative_set, 0 )) {
                base_extent = basis.survey( base_set ) - 1;
                for (relativity.scale.begin( relative_set, relative_position, 0 ); true; relativity.scale.traverse( relative_set, relative_position, 1 )) {
                    basis.scale.begin( base_set, base_position, 0 );
                    if (!SearchInBase( base_set, basis.scale, relativity.scale.go( relative_set, relative_position ).to, base_position, base_extent )) {
                        if (!Proceed( operand, relativity.scale.go( relative_set, relative_position ).to ))
                            return false;
                    }
                    if (!relativity.traverses( relative_set, relative_position, 1 ))
                        break;
                }
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
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
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< BasicNatural >::value && is_unsigned< BasicNatural >::value,
                "BasicNatural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
                "RelativeNatural:  Unsigned integer type required"
            );
#endif
            static auto&
                SearchInBase = SearchLinearly< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            auto&
                scale = relativity.scale;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                extent;
            Empty( operand );
            if (relativity.begins( relative_set, 0 )) {
                extent = basis.survey( base_set ) - 1;
                for (scale.begin( relative_set, relative_position, 0 ); true; scale.traverse( relative_set, relative_position, 1 )) {
                    basis.scale.begin( base_set, base_position, 0 );
                    if (SearchInBase( base_set, basis.scale, scale.go( relative_set, relative_position ).to, base_position, extent )) {
                        if (!Proceed( operand, scale.go( relative_set, relative_position ).to ))
                            return false;
                    }
                    if (!relativity.traverses( relative_set, relative_position, 1 ))
                        break;
                }
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
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
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< BasicNatural >::value && is_unsigned< BasicNatural >::value,
                "BasicNatural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
                "RelativeNatural:  Unsigned integer type required"
            );
#endif
            static auto&
                ComposeUnion = ComposeSelection< Natural, Elemental, Proceed, Equate >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Empty( operand );
            if (basis.begins( base_set, 0 )) {
                for (basis.scale.begin( base_set, base_position, 0 ); true; basis.scale.traverse( base_set, base_position, 1 )) {
                    if (!Proceed( operand, basis.scale.go( base_set, base_position ).to ))
                        return false;
                    if (!basis.traverses( base_set, base_position, 1 ))
                        break;
                }
            }
            if (relativity.begins( relative_set, 0 )) {
                for (relativity.scale.begin( relative_set, relative_position, 0 ); true; relativity.scale.traverse( relative_set, relative_position, 1 )) {
                    ComposeUnion( operand, relativity.scale.go( relative_set, relative_position ).to );
                    if (!relativity.traverses( relative_set, relative_position, 1 ))
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
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate
        >
        constexpr Sectional< Junctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        JunctionSection = {
            ComplementSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            DifferentiateSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            IntersectSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            UniteSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >
        };

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate
        >
        constexpr Sectional< Junctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        SafeJunctionSection = {
            ComplementSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            DifferentiateSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            IntersectSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >,
            UniteSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate >
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
            JunctionSection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Adjunct, Equate >,
            DuplicateSelection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct > >,
            EquateSelections< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Equate >,
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
            SafeJunctionSection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Adjunct, Equate >,
            DuplicateSelection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct > >,
            EquateSelections< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Equate >,
            Account< Natural, Elemental >
        };

    }

}

#endif
