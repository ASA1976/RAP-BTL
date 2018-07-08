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
            Referential< const Natural >,
            Referential< const Elemental >,
            Referential< Positional< Elemental > >
        ) >
        SearchCollection = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadAxis< Natural, Elemental >, Equate, Order >;

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
				Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadAxis< Natural, Elemental >, Equate, Order >;
#endif
            Positional< Elemental >
                position;
            return Search( set, set.count, value, position );
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
				Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadAxis< Natural, Elemental >, Equate, Order >;
#endif
			Positional< Elemental >
                position;
            if (!set.last)
                return Proceed( set, value );
			if (Search(set, set.count, value, position))
                return false;
            if (Order( GoRead( set, position ).to, value ))
                return Proceed( set, value );
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
				Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadAxis< Natural, Elemental >, Equate, Order >;
#endif
			static const Natural
                One = 1;
            Positional< Elemental >
                position;
            if (!Search( set, set.count, value, position ))
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
				Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadAxis< Natural, Elemental >, Equate, Order >;
#endif
			static auto&
                Discompose = DiscomposeCollection< Natural, Elemental, Concede, Equate, Order >;
            Positional< Elemental >
                position;
            if (Search( set, set.count, replacement, position ))
                return false;
            if (!Precede( set, position, replacement ))
                return false;
            return Discompose( set, original );
        }

        template <
            typename Basic,
            typename BasicPositional,
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
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
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
				Search = SearchBisectionally< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, ReadAxis< Natural, Elemental >, Equate, Order >;
#endif
			auto&
                scale = basis.scale;
            Positional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            Empty( operand );
            scale.begin( base, base_position );
            if (!Proceed( operand, scale.go( base, base_position ).to ))
                return false;
            while (true) {
                if (!Search( operand, operand.count, scale.go( base, base_position ).to, operand_position )) {
                    if (Order( GoRead( operand, operand_position ).to, scale.go( base, base_position ).to )) {
                        if (!Proceed( operand, scale.go( base, base_position ).to ))
                            return false;
                    } else {
                        if (!Precede( operand, operand_position, scale.go( base, base_position ).to ))
                            return false;
                    }
                }
                if (!basis.traversable( base, base_position ))
                    return true;
                scale.traverse( base, base_position );
            }
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename Natural,
            typename Elemental,
            Referential< ConjointlyConsequent< Basic, BasicPositional, Natural, Elemental > >
                ProceedMany
        >
        static inline bool
        CollateCollection(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Axial< const Basic, BasicPositional, const Elemental > >
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
            BasicPositional
                first, last;
            Empty( operand );
            if (!basis.increment.begins( base ))
                return false;
            basis.increment.scale.begin( base, first );
            basis.decrement.scale.begin( base, last );
            return ProceedMany( operand, basis.increment, base, first, last );
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename Relative,
            typename RelativePositional,
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
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Directional< const Relative, RelativePositional, const Elemental > >
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
#endif
            static auto&
                SearchInBase = SearchLinearly< Basic, BasicPositional, Elemental, Equate >;
            static auto&
                ComposeComplement = ComposeCollection< Natural, Elemental, Precede, Proceed, Equate, Order >;
            auto&
                scale = relativity.scale;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Empty( operand );
            if (relativity.begins( relative_set )) {
                for (scale.begin( relative_set, relative_position); true; scale.traverse( relative_set, relative_position )) {
                    if (!SearchInBase( base_set, basis, scale.go( relative_set, relative_position ).to, base_position ))
                        ComposeComplement( operand, scale.go( relative_set, relative_position ).to );
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
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Directional< const Relative, RelativePositional, const Elemental > >
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
#endif
            static auto&
                SearchInBase = SearchLinearly< Basic, BasicPositional, Elemental, Equate >;
            static auto&
                SearchInRelative = SearchLinearly< Relative, RelativePositional, Elemental, Equate >;
            static auto&
                ComposeDifference = ComposeCollection< Natural, Elemental, Precede, Proceed, Equate, Order >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Empty( operand );
            if (basis.begins( base_set )) {
                for (basis.scale.begin( base_set, base_position ); true; basis.scale.traverse( base_set, base_position )) {
                    if (!SearchInRelative( relative_set, relativity, basis.scale.go( base_set, base_position ).to, relative_position ))
                        if (!Proceed( operand, basis.scale.go( base_set, base_position ).to ))
                            return false;
                    if (!basis.traversable( base_set, base_position ))
                        break;
                }
            }
            if (relativity.begins( relative_set )) {
                for (relativity.scale.begin( relative_set, relative_position); true; relativity.scale.traverse( relative_set, relative_position )) {
                    if (!SearchInBase( base_set, basis, relativity.scale.go( relative_set, relative_position ).to, base_position ))
                        ComposeDifference( operand, relativity.scale.go( relative_set, relative_position ).to );
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
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Directional< const Relative, RelativePositional, const Elemental > >
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
#endif
            static auto&
                SearchInBase = SearchLinearly< Basic, BasicPositional, Elemental, Equate >;
            static auto&
                ComposeIntersection = ComposeCollection< Natural, Elemental, Precede, Proceed, Equate, Order >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Empty( operand );
            if (relativity.begins( relative_set )) {
                for (relativity.scale.begin( relative_set, relative_position ); true; relativity.scale.traverse( relative_set, relative_position )) {
                    if (SearchInBase( base_set, relativity, relativity.scale.go( relative_set, relative_position ).to, base_position ))
                        ComposeIntersection( operand, relativity.scale.go( relative_set, relative_position ).to );
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
            Referential< const Directional< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Directional< const Relative, RelativePositional, const Elemental > >
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
#endif
            static auto&
                ComposeUnion = ComposeCollection< Natural, Elemental, Precede, Proceed, Equate, Order >;
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
            typename Basic,
            typename BasicPositional,
            typename Relative,
            typename RelativePositional,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Natural, Elemental > >
                ProceedOne,
            Referential< ConjointlyConsequent< Relative, RelativePositional, Natural, Elemental > >
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
            Referential< const Axial< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Axial< const Relative, RelativePositional, const Elemental > >
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
            if (relativity.increment.begins( relative_set )) {
                relativity.increment.scale.begin( relative_set, opposition );
                if (basis.increment.begins( base_set )) {
                    basis.increment.scale.begin( base_set, position );
                    while (true) {
                        if (Equate( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                            if (!relativity.increment.traversable( relative_set, opposition ))
                                return true;
                            relativity.increment.scale.traverse( relative_set, opposition );
                            if (!basis.increment.traversable( base_set, position ))
                                break;
                            basis.increment.scale.traverse( base_set, position );
                        } else if (Order( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                            if (!basis.increment.traversable( base_set, position ))
                                break;
                            basis.increment.scale.traverse( base_set, position );
                        } else {
                            if (!ProceedOne( operand, go_relativity( relative_set, opposition ).to ) )
                                return false;
                            if (!relativity.increment.traversable( relative_set, opposition ))
                                return true;
                            relativity.increment.scale.traverse( relative_set, opposition );
                        }
                    }
                }
                relativity.decrement.scale.begin( relative_set, last );
                if (!ProceedMany( operand, relativity.increment, relative_set, opposition, last ))
                    return false;
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
                ProceedOne,
            Referential< ConjointlyConsequent< Basic, BasicPositional, Natural, Elemental > >
                ProceedManyFromBase,
            Referential< ConjointlyConsequent< Relative, RelativePositional, Natural, Elemental > >
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
            Referential< const Axial< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Axial< const Relative, RelativePositional, const Elemental > >
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
                    basis.decrement.scale.begin( base_set, last );
                    return ProceedManyFromBase( operand, basis.increment, base_set, position, last );
                };
            auto
                RemainingRelative = [&]{
                    RelativePositional
                        last;
                    relativity.decrement.scale.begin( relative_set, last );
                    return ProceedManyFromRelative( operand, relativity.increment, relative_set, opposition, last );
                };
            Empty( operand );
            if (!basis.increment.begins( base_set )) {
                if (relativity.increment.begins( relative_set )) {
                    relativity.increment.scale.begin( relative_set, opposition );
                    return RemainingRelative();
                }
            } else if (!relativity.increment.begins( relative_set )) {
                if (basis.increment.begins( base_set )) {
                    basis.increment.scale.begin( base_set, position );
                    return RemainingBase();
                }
            } else {
                basis.increment.scale.begin( base_set, position );
                relativity.increment.scale.begin( relative_set, opposition );
                while (true) {
                    if (Equate( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                        if (!basis.increment.traversable( base_set, position )) {
                            if (!relativity.increment.traversable( relative_set, opposition ))
                                return true;
                            basis.increment.scale.traverse( base_set, position );
                            return RemainingBase();
                        } else if (!relativity.increment.traversable( relative_set, opposition )) {
                            if (!basis.increment.traversable( base_set, position ))
                                return true;
                            relativity.increment.scale.traverse( relative_set, opposition );
                            return RemainingRelative();
                        }
                        basis.increment.scale.traverse( base_set, opposition );
                        relativity.increment.scale.traverse( relative_set, opposition );
                    } else if (Order( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                        if (!ProceedOne( operand, go_basis( base_set, position ).to ))
                            return false;
                        if (!basis.increment.traversable( base_set, position ))
                            return RemainingRelative();
                        basis.increment.scale.traverse( base_set, position );
                    } else {
                        if (!ProceedOne( operand, go_relativity( relative_set, opposition ).to ))
                            return false;
                        if (!relativity.increment.traversable( relative_set, opposition ))
                            return RemainingBase();
                        relativity.increment.scale.traverse( relative_set, opposition );
                    }
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
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        IntersectCollections(
            Referential< Junctive< Natural, Elemental > >
                operand,
            Referential< const Axial< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Axial< const Relative, RelativePositional, const Elemental > >
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
            if (!basis.increment.begins( base_set ) || !relativity.increment.begins( relative_set ))
                return true;
            basis.increment.scale.begin( base_set, position );
            relativity.increment.scale.begin( relative_set, opposition );
            while (true) {
                if (Equate( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                    if (!Proceed( operand, go_basis( base_set, position ).to ))
                        return false;
                    if (!basis.increment.traversable( base_set, position ))
                        return true;
                    if (!relativity.increment.traversable( relative_set, opposition ))
                        return true;
                    basis.increment.scale.traverse( base_set, position );
                    relativity.increment.scale.traverse( relative_set, opposition );
                } else if (Order( go_basis( base_set, position ).to, go_relativity( relative_set, opposition ).to )) {
                    if (!basis.increment.traversable( base_set, position ))
                        return true;
                    basis.increment.scale.traverse( base_set, position );
                } else {
                    if (!relativity.increment.traversable( relative_set, opposition ))
                        return true;
                    relativity.increment.scale.traverse( relative_set, opposition );
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
                ProceedOne,
            Referential< ConjointlyConsequent< Basic, BasicPositional, Natural, Elemental > >
                ProceedManyFromBase,
            Referential< ConjointlyConsequent< Relative, RelativePositional, Natural, Elemental > >
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
            Referential< const Axial< const Basic, BasicPositional, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Axial< const Relative, RelativePositional, const Elemental > >
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
                    basis.decrement.scale.begin( base_set, last );
                    return ProceedManyFromBase( operand, basis.increment, base_set, position, last );
                };
            auto
                RemainingRelative = [&]{
                    RelativePositional
                        last;
                    relativity.decrement.scale.begin( relative_set, last );
                    return ProceedManyFromRelative( operand, relativity.increment, relative_set, apposition, last );
                };
            Empty( operand );
            if (!basis.increment.begins( base_set )) {
                if (!relativity.increment.begins( relative_set ))
                    return true;
                relativity.increment.scale.begin( relative_set, apposition );
                return RemainingRelative();
            } else if (!relativity.increment.begins( relative_set )) {
                basis.increment.scale.begin( base_set, position );
                return RemainingBase();
            }
            basis.increment.scale.begin( base_set, position );
            relativity.increment.scale.begin( relative_set, apposition );
            while (true) {
                if (Equate( go_basis( base_set, position ).to, go_relativity( relative_set, apposition ).to )) {
                    if (!ProceedOne( operand, go_basis( base_set, position ).to ))
                        return false;
                    if (!basis.increment.traversable( base_set, position )) {
                        if (!relativity.increment.traversable( relative_set, apposition ))
                            return true;
                        return RemainingRelative();
                    } else if (!relativity.increment.traversable( relative_set, apposition ))
                        return RemainingBase();
                    basis.increment.scale.traverse( base_set, position );
                    relativity.increment.scale.traverse( relative_set, apposition );
                } else if (Order( go_basis( base_set, position ).to, go_relativity( relative_set, apposition ).to )) {
                    if (!ProceedOne( operand, go_basis( base_set, position ).to ))
                        return false;
                    if (!basis.increment.traversable( base_set, position ))
                        return RemainingRelative();
                    basis.increment.scale.traverse( base_set, position );
                } else {
                    if (!ProceedOne( operand, go_relativity( relative_set, apposition ).to ))
                        return false;
                    if (!relativity.increment.traversable( relative_set, apposition ))
                        return RemainingBase();
                    relativity.increment.scale.traverse( relative_set, apposition );
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
            typename Relative,
            typename RelativePositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Sectional< Junctive< Natural, Elemental >, Basic, BasicPositional, Relative, RelativePositional, Elemental >
        JunctionOrderSection = {
            ComplementSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            DifferentiateSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            IntersectSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            UniteSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >
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
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Sectional< Junctive< Natural, Elemental >, Basic, BasicPositional, Relative, RelativePositional, Elemental >
        SafeJunctionOrderSection = {
            ComplementSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            DifferentiateSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            IntersectSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            UniteSelections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >
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
            JunctionOrderSection< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct, Equate, Order >,
            CollateSelection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Precede< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            EquateSelections< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Elemental, Equate >,
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
            SafeJunctionOrderSection< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct, Equate, Order >,
            CollateSelection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, PrecedeSafely< Natural, Elemental, Adjunct >, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            EquateSelections< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Elemental, Equate >,
            Account< Natural, Elemental >
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
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        constexpr Bisectional< Junctive< Natural, Elemental >, Basic, BasicPositional, Relative, RelativePositional, Elemental >
        JunctionBisection = {
            ComplementCollections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Proceed< Relative, RelativePositional, Natural, Elemental, Adjunct >, Equate, Order >,
            DifferentiateCollections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Proceed< Basic, BasicPositional, Natural, Elemental, Adjunct >, Proceed< Relative, RelativePositional, Natural, Elemental, Adjunct >, Equate, Order >,
            IntersectCollections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Equate, Order >,
            UniteCollections< Basic, BasicPositional, Relative, RelativePositional, Natural, Elemental, Proceed< Natural, Elemental, Adjunct >, Proceed< Basic, BasicPositional, Natural, Elemental, Adjunct >, Proceed< Relative, RelativePositional, Natural, Elemental, Adjunct >, Equate, Order >
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
            JunctionBisection< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct, Equate, Order >,
            CollateCollection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Proceed< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct > >,
            EquateCollections< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Elemental, Equate >
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
            JunctionBisection< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct, Equate, Order >,
            CollateCollection< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Proceed< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct > >,
            EquateCollections< Junctive< Natural, Elemental >, Positional< Elemental >, Junctive< Natural, Elemental >, Positional< Elemental >, Elemental, Equate >
        };

    }

}

#endif
