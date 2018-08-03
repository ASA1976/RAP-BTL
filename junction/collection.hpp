// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_COLLECTION_MODULE
#define JUNCTION_COLLECTION_MODULE
#include "consecution.hpp"
#include "../collection.hpp"

namespace junction {

    namespace collection {

        using namespace ::collection;
        using namespace ::sortation;
        using namespace ::junction::consecution;

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        Referential< bool(
            Referential< const Junctive< Natural, Elemental > >,
            Referential< const Elemental >,
            Referential< Positional< Elemental > >,
            Natural,
            Natural
        ) >
        SearchCollection = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadLiner< Natural, Elemental >, Equate, Order >;

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        AccreditCollection(
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
				Search = SearchCollection< Natural, Elemental, Equate, Order >;
#else
                // Problem 286153 filed July 3 2018
				Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadLiner< Natural, Elemental >, Equate, Order >;
#endif
            static const Natural
                Zero = 0;
            Positional< Elemental >
                position;
            if (!IncrementBegins( set, Zero ))
                return false;
            BeginReadIncrement( set, position, Zero );
            return Search( set, value, position, Zero, Account( set ) - 1 );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Precedent< Natural, Elemental > >
                Precede,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        ComposeCollection(
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
				Search = SearchCollection< Natural, Elemental, Equate, Order >;
#else
                // Problem 286153 filed July 3 2018
                Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadLiner< Natural, Elemental >, Equate, Order >;
#endif
            static const Natural
                Zero = 0,
                One = 1;
			Positional< Elemental >
                position;
            if (!IncrementBegins( set, Zero ))
                return Proceed( set, value );
            BeginWriteIncrement( set, position, Zero );
            if (Search( set, value, position, Zero, Account( set ) - 1 ))
                return false;
            if (Order( GoRead( set, position ).to, value )) {
                if (!IncrementTraversable( set, position, One ))
                    return Proceed( set, value );
                TraverseWriteIncrement( set, position, One );
            }
            return Precede( set, position, value );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Concessive< Natural, Elemental > >
                Concede,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        DiscomposeCollection(
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
				Search = SearchCollection< Natural, Elemental, Equate, Order >;
#else
                // Problem 286153 filed July 3 2018
                Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadLiner< Natural, Elemental >, Equate, Order >;
#endif
			static const Natural
                Zero = 0,
                One = 1;
            Positional< Elemental >
                position;
            if (!IncrementBegins( set, Zero ))
                return false;
            BeginWriteIncrement( set, position, Zero );
            if (!Search( set, value, position, Zero, Account( set ) - 1 ))
                return false;
            return Concede( set, position, One );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Precedent< Natural, Elemental > >
                Precede,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Concessive< Natural, Elemental > >
                Concede,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        RecomposeCollection(
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
#ifndef _MSC_VER
				Search = SearchCollection< Natural, Elemental, Equate, Order >;
#else
                // Problem 286153 filed July 3 2018
                Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadLiner< Natural, Elemental >, Equate, Order >;
#endif
            static const Natural
                Zero = 0,
                One = 1;
            Positional< Elemental >
                original_position,
                replacement_position;
            Natural
                last;
            if (!IncrementBegins( set, Zero ))
                return false;
            BeginWriteIncrement( set, original_position, Zero );
            BeginWriteIncrement( set, replacement_position, Zero );
            last = Account( set ) - 1;
            if (!Search( set, original, original_position, Zero, last ))
                return false;
            if (Search( set, replacement, replacement_position, Zero, last ))
                return false;
            if (Order( GoRead( set, replacement_position ).to, replacement )) {
                if (IncrementTraversable( set, replacement_position, One )) {
                    TraverseWriteIncrement( set, replacement_position, One );
                    if (!Precede( set, replacement_position, replacement ))
                        return false;
                } else if (!Proceed( set, replacement )) {
                    return false;
                }
            } else if (!Precede( set, replacement_position, replacement )) {
                return false;
            }
            return Concede( set, original_position, One );
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Natural,
            typename Elemental,
            Referential< Precedent< Natural, Elemental > >
                Precede,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        CollateSelection(
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
#endif
            static auto&
#ifndef _MSC_VER
				Search = SearchCollection< Natural, Elemental, Equate, Order >;
#else
                // Problem 286153 filed July 3 2018
                Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadLiner< Natural, Elemental >, Equate, Order >;
#endif
            static const Natural
                Zero = 0,
                One = 1;
			auto&
                scale = basis.scale;
            Positional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            Empty( operand );
            if (!basis.begins( base, 0 ))
                return true;
            scale.begin( base, base_position, 0 );
            if (!Proceed( operand, scale.go( base, base_position ).to ))
                return false;
            BeginWriteIncrement( operand, operand_position, Zero );
            while (true) {
                if (!Search( operand, scale.go( base, base_position ).to, operand_position, Zero, Account( operand ) - 1 )) {
                    if (Order( GoRead( operand, operand_position ).to, scale.go( base, base_position ).to )) {
                        if (!IncrementTraversable( operand, operand_position, One )) {
                            TraverseWriteIncrement( operand, operand_position, One );
                            if (!Precede( operand, operand_position, scale.go( base, base_position ).to ))
                                return false;
                        } else if (!Proceed( operand, scale.go( base, base_position ).to )) {
                            return false;
                        }
                    } else {
                        if (!Precede( operand, operand_position, scale.go( base, base_position ).to ))
                            return false;
                    }
                }
                if (!basis.traversable( base, base_position, 1 ))
                    return true;
                scale.traverse( base, base_position, 1 );
            }
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Natural,
            typename Elemental,
            Referential< ConjointlyConsequent< Basic, BasicPositional, BasicNatural, Natural, Elemental > >
                ProceedMany
        >
        static inline bool
        CollateCollection(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Axial< const Basic, BasicPositional, BasicNatural, const Elemental > >
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
            BasicPositional
                first, last;
            Empty( operand );
            if (!basis.increment.begins( base, 0 ))
                return true;
            basis.increment.scale.begin( base, first, 0 );
            basis.decrement.scale.begin( base, last, 0 );
            return ProceedMany( operand, basis.increment, base, first, last );
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
            Referential< Precedent< Natural, Elemental > >
                Precede,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
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
            static auto&
                ComposeComplement = ComposeCollection< Natural, Elemental, Precede, Proceed, Equate, Order >;
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
                    if (!SearchInBase( base_set, basis.scale, scale.go( relative_set, relative_position ).to, base_position, extent ))
                        ComposeComplement( operand, scale.go( relative_set, relative_position ).to );
                    if (!relativity.traversable( relative_set, relative_position, 1 ))
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
            Referential< Precedent< Natural, Elemental > >
                Precede,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
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
            static auto&
                ComposeDifference = ComposeCollection< Natural, Elemental, Precede, Proceed, Equate, Order >;
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
                    if (!SearchInRelative( relative_set, relativity.scale, basis.scale.go( base_set, base_position ).to, relative_position, relative_extent ))
                        if (!Proceed( operand, basis.scale.go( base_set, base_position ).to ))
                            return false;
                    if (!basis.traversable( base_set, base_position, 1 ))
                        break;
                }
            }
            if (relativity.begins( relative_set, 0 )) {
                base_extent = basis.survey( base_set ) - 1;
                for (relativity.scale.begin( relative_set, relative_position, 0 ); true; relativity.scale.traverse( relative_set, relative_position, 1 )) {
                    if (!SearchInBase( base_set, basis.scale, relativity.scale.go( relative_set, relative_position ).to, base_position, base_extent ))
                        ComposeDifference( operand, relativity.scale.go( relative_set, relative_position ).to );
                    if (!relativity.traversable( relative_set, relative_position, 1 ))
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
            Referential< Precedent< Natural, Elemental > >
                Precede,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
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
            static auto&
                ComposeIntersection = ComposeCollection< Natural, Elemental, Precede, Proceed, Equate, Order >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                extent;
            Empty( operand );
            if (relativity.begins( relative_set, 0 )) {
                extent = basis.survey( base_set ) - 1;
                for (relativity.scale.begin( relative_set, relative_position, 0 ); true; relativity.scale.traverse( relative_set, relative_position, 1 )) {
                    if (SearchInBase( base_set, relativity.scale, relativity.scale.go( relative_set, relative_position ).to, base_position, extent ))
                        ComposeIntersection( operand, relativity.scale.go( relative_set, relative_position ).to );
                    if (!relativity.traversable( relative_set, relative_position, 1 ))
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
            Referential< Precedent< Natural, Elemental > >
                Precede,
            Referential< Consequent< Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
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
                ComposeUnion = ComposeCollection< Natural, Elemental, Precede, Proceed, Equate, Order >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Empty( operand );
            if (basis.begins( base_set, 0 )) {
                for (basis.scale.begin( base_set, base_position, 0 ); true; basis.scale.traverse( base_set, base_position, 1 )) {
                    if (!Proceed( operand, basis.scale.go( base_set, base_position ).to ))
                        return false;
                    if (!basis.traversable( base_set, base_position, 1 ))
                        break;
                }
            }
            if (relativity.begins( relative_set, 0 )) {
                for (relativity.scale.begin( relative_set, relative_position, 0 ); true; relativity.scale.traverse( relative_set, relative_position, 1 )) {
                    ComposeUnion( operand, relativity.scale.go( relative_set, relative_position ).to );
                    if (!relativity.traversable( relative_set, relative_position, 1 ))
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
                ProceedOne,
            Referential< ConjointlyConsequent< Relative, RelativePositional, RelativeNatural, Natural, Elemental > >
                ProceedMany,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        ComplementCollections(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Axial< const Basic, BasicPositional, BasicNatural, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Axial< const Relative, RelativePositional, RelativeNatural, const Elemental > >
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
            Referential< Expositive< const Basic, BasicPositional, const Elemental > >
                go_basis = basis.increment.scale.go;
            Referential< Expositive< const Relative, RelativePositional, const Elemental > >
                go_relativity = relativity.increment.scale.go;
            BasicPositional
                position;
            RelativePositional
                opposition, last;
            Empty( operand );
            if (relativity.increment.begins( relative_set, 0 )) {
                relativity.increment.scale.begin( relative_set, opposition, 0 );
                if (basis.increment.begins( base_set, 0 )) {
                    basis.increment.scale.begin( base_set, position, 0 );
                    while (true) {
                        if (Equate( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                            if (!relativity.increment.traversable( relative_set, opposition, 1 ))
                                return true;
                            relativity.increment.scale.traverse( relative_set, opposition, 1 );
                            if (!basis.increment.traversable( base_set, position, 1 ))
                                break;
                            basis.increment.scale.traverse( base_set, position, 1 );
                        } else if (Order( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                            if (!basis.increment.traversable( base_set, position, 1 ))
                                break;
                            basis.increment.scale.traverse( base_set, position, 1 );
                        } else {
                            if (!ProceedOne( operand, go_relativity( relative_set, opposition ).to ) )
                                return false;
                            if (!relativity.increment.traversable( relative_set, opposition, 1 ))
                                return true;
                            relativity.increment.scale.traverse( relative_set, opposition, 1 );
                        }
                    }
                }
                relativity.decrement.scale.begin( relative_set, last, 0 );
                if (!ProceedMany( operand, relativity.increment, relative_set, opposition, last ))
                    return false;
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
                ProceedOne,
            Referential< ConjointlyConsequent< Basic, BasicPositional, BasicNatural, Natural, Elemental > >
                ProceedManyFromBase,
            Referential< ConjointlyConsequent< Relative, RelativePositional, RelativeNatural, Natural, Elemental > >
                ProceedManyFromRelative,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        DifferentiateCollections(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Axial< const Basic, BasicPositional, BasicNatural, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Axial< const Relative, RelativePositional, RelativeNatural, const Elemental > >
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
            Referential< Expositive< const Basic, BasicPositional, const Elemental > >
                go_basis = basis.increment.scale.go;
            Referential< Expositive< const Relative, RelativePositional, const Elemental > >
                go_relativity = relativity.increment.scale.go;
            BasicPositional
                position;
            RelativePositional
                opposition;
            auto
                RemainingBase = [&]{
                    BasicPositional
                        last;
                    basis.decrement.scale.begin( base_set, last, 0 );
                    return ProceedManyFromBase( operand, basis.increment, base_set, position, last );
                };
            auto
                RemainingRelative = [&]{
                    RelativePositional
                        last;
                    relativity.decrement.scale.begin( relative_set, last, 0 );
                    return ProceedManyFromRelative( operand, relativity.increment, relative_set, opposition, last );
                };
            Empty( operand );
            if (!basis.increment.begins( base_set, 0 )) {
                if (relativity.increment.begins( relative_set, 0 )) {
                    relativity.increment.scale.begin( relative_set, opposition, 0 );
                    return RemainingRelative();
                }
            } else if (!relativity.increment.begins( relative_set, 0 )) {
                if (basis.increment.begins( base_set, 0 )) {
                    basis.increment.scale.begin( base_set, position, 0 );
                    return RemainingBase();
                }
            } else {
                basis.increment.scale.begin( base_set, position, 0 );
                relativity.increment.scale.begin( relative_set, opposition, 0 );
                while (true) {
                    if (Equate( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                        if (!basis.increment.traversable( base_set, position, 1 )) {
                            if (!relativity.increment.traversable( relative_set, opposition, 1 ))
                                return true;
                            relativity.increment.scale.traverse( relative_set, opposition, 1 );
                            return RemainingRelative();
                        } else if (!relativity.increment.traversable( relative_set, opposition, 1 )) {
                            basis.increment.scale.traverse( base_set, position, 1 );
                            return RemainingBase();
                        }
                        basis.increment.scale.traverse( base_set, position, 1 );
                        relativity.increment.scale.traverse( relative_set, opposition, 1 );
                    } else if (Order( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                        if (!ProceedOne( operand, go_basis( base_set, position ).to ))
                            return false;
                        if (!basis.increment.traversable( base_set, position, 1 ))
                            return RemainingRelative();
                        basis.increment.scale.traverse( base_set, position, 1 );
                    } else {
                        if (!ProceedOne( operand, go_relativity( relative_set, opposition ).to ))
                            return false;
                        if (!relativity.increment.traversable( relative_set, opposition, 1 ))
                            return RemainingBase();
                        relativity.increment.scale.traverse( relative_set, opposition, 1 );
                    }
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
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        IntersectCollections(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Axial< const Basic, BasicPositional, BasicNatural, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Axial< const Relative, RelativePositional, RelativeNatural, const Elemental > >
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
            Referential< Expositive< const Basic, BasicPositional, const Elemental > >
                go_basis = basis.increment.scale.go;
            Referential< Expositive< const Relative, RelativePositional, const Elemental > >
                go_relativity = relativity.increment.scale.go;
            BasicPositional
                position;
            RelativePositional
                opposition;
            Empty( operand );
            if (!basis.increment.begins( base_set, 0 ) || !relativity.increment.begins( relative_set, 0 ))
                return true;
            basis.increment.scale.begin( base_set, position, 0 );
            relativity.increment.scale.begin( relative_set, opposition, 0 );
            while (true) {
                if (Equate( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                    if (!Proceed( operand, go_basis( base_set, position ).to ))
                        return false;
                    if (!basis.increment.traversable( base_set, position, 1 ))
                        return true;
                    if (!relativity.increment.traversable( relative_set, opposition, 1 ))
                        return true;
                    basis.increment.scale.traverse( base_set, position, 1 );
                    relativity.increment.scale.traverse( relative_set, opposition, 1 );
                } else if (Order( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                    if (!basis.increment.traversable( base_set, position, 1 ))
                        return true;
                    basis.increment.scale.traverse( base_set, position, 1 );
                } else {
                    if (!relativity.increment.traversable( relative_set, opposition, 1 ))
                        return true;
                    relativity.increment.scale.traverse( relative_set, opposition, 1 );
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
                ProceedOne,
            Referential< ConjointlyConsequent< Basic, BasicPositional, BasicNatural, Natural, Elemental > >
                ProceedManyFromBase,
            Referential< ConjointlyConsequent< Relative, RelativePositional, RelativeNatural, Natural, Elemental > >
                ProceedManyFromRelative,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        UniteCollections(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Axial< const Basic, BasicPositional, BasicNatural, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Axial< const Relative, RelativePositional, RelativeNatural, const Elemental > >
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
            Referential< Expositive< const Basic, BasicPositional, const Elemental > >
                go_basis = basis.increment.scale.go;
            Referential< Expositive< const Relative, RelativePositional, const Elemental > >
                go_relativity = relativity.increment.scale.go;
            BasicPositional
                position;
            RelativePositional
                apposition;
            auto
                RemainingBase = [&]{
                    BasicPositional
                        last;
                    basis.decrement.scale.begin( base_set, last, 0 );
                    return ProceedManyFromBase( operand, basis.increment, base_set, position, last );
                };
            auto
                RemainingRelative = [&]{
                    RelativePositional
                        last;
                    relativity.decrement.scale.begin( relative_set, last, 0 );
                    return ProceedManyFromRelative( operand, relativity.increment, relative_set, apposition, last );
                };
            Empty( operand );
            if (!basis.increment.begins( base_set, 0 )) {
                if (!relativity.increment.begins( relative_set, 0 ))
                    return true;
                relativity.increment.scale.begin( relative_set, apposition, 0 );
                return RemainingRelative();
            } else if (!relativity.increment.begins( relative_set, 0 )) {
                basis.increment.scale.begin( base_set, position, 0 );
                return RemainingBase();
            }
            basis.increment.scale.begin( base_set, position, 0 );
            relativity.increment.scale.begin( relative_set, apposition, 0 );
            while (true) {
                if (Equate( go_basis( base_set, position ).to, go_relativity( relative_set, apposition ).to )) {
                    if (!ProceedOne( operand, go_basis( base_set, position ).to ))
                        return false;
                    if (!basis.increment.traversable( base_set, position, 1 )) {
                        if (!relativity.increment.traversable( relative_set, apposition, 1 ))
                            return true;
                        relativity.increment.scale.traverse( relative_set, apposition, 1 );
                        return RemainingRelative();
                    } else if (!relativity.increment.traversable( relative_set, apposition, 1 )) {
                        basis.increment.scale.traverse( base_set, position, 1 );
                        return RemainingBase();
                    }
                    basis.increment.scale.traverse( base_set, position, 1 );
                    relativity.increment.scale.traverse( relative_set, apposition, 1 );
                } else if (Order( go_basis( base_set, position ).to, go_relativity( relative_set, apposition ).to )) {
                    if (!ProceedOne( operand, go_basis( base_set, position ).to ))
                        return false;
                    if (!basis.increment.traversable( base_set, position, 1 ))
                        return RemainingRelative();
                    basis.increment.scale.traverse( base_set, position, 1 );
                } else {
                    if (!ProceedOne( operand, go_relativity( relative_set, apposition ).to ))
                        return false;
                    if (!relativity.increment.traversable( relative_set, apposition, 1 ))
                        return RemainingBase();
                    relativity.increment.scale.traverse( relative_set, apposition, 1 );
                }
            }
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Compositional< Junctive< Natural, Elemental >, Natural, Elemental >
        JunctionOrderComposer = {
            Instantiate< Natural, Elemental, Adjunct >,
            AccreditCollection< Natural, Elemental, Equate, Order >,
            ComposeCollection< Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            RecomposeCollection< Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Concede, Equate, Order >,
            DiscomposeCollection< Natural, Elemental, Concede, Equate, Order >,
            Empty< Natural, Elemental >,
            Free< Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Compositional< Junctive< Natural, Elemental >, Natural, Elemental >
        SafeJunctionOrderComposer = {
            Instantiate< Natural, Elemental, Adjunct >,
            AccreditCollection< Natural, Elemental, Equate, Order >,
            ComposeCollection< Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            RecomposeCollection< Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, ConcedeSafely, Equate, Order >,
            DiscomposeCollection< Natural, Elemental, ConcedeSafely, Equate, Order >,
            Empty< Natural, Elemental >,
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
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Sectional< Junctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        JunctionOrderSection = {
            ComplementSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            DifferentiateSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            IntersectSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            UniteSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >
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
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Sectional< Junctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        SafeJunctionOrderSection = {
            ComplementSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            DifferentiateSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            IntersectSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            UniteSelections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Selective< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental >
        JunctionOrderSelector = {
            JunctionOrderComposer< Natural, Elemental, Adjunct, Equate, Order >,
            JunctionOrderSection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Adjunct, Equate, Order >,
            CollateSelection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            EquateSelections< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Equate >,
            Account< Natural, Elemental >
       };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Selective< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental >
        SafeJunctionOrderSelector = {
            SafeJunctionOrderComposer< Natural, Elemental, Adjunct, Equate, Order >,
            SafeJunctionOrderSection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Adjunct, Equate, Order >,
            CollateSelection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            EquateSelections< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Equate >,
            Account< Natural, Elemental >
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
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Bisectional< Junctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        JunctionBisection = {
            ComplementCollections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct >, Equate, Order >,
            DifferentiateCollections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct >, Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct >, Equate, Order >,
            IntersectCollections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            UniteCollections< Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct >, Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct >, Equate, Order >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Collective< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental >
        JunctionCollector = {
            JunctionOrderSelector< Natural, Elemental, Adjunct, Equate, Order >,
            JunctionBisection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Adjunct, Equate, Order >,
            CollateCollection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Proceed< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Adjunct > >,
            EquateCollections< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Equate >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Collective< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental >
        SafeJunctionCollector = {
            SafeJunctionOrderSelector< Natural, Elemental, Adjunct, Equate, Order >,
            JunctionBisection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Adjunct, Equate, Order >,
            CollateCollection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Natural, Elemental, Proceed< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct > >,
            EquateCollections< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Equate >
        };

    }

}

#endif
