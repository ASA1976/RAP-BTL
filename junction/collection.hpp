// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_COLLECTION_MODULE
#define JUNCTION_COLLECTION_MODULE
#include "consecution.hpp"
#include "../collection.hpp"

namespace junction {

    /**
     * @brief         
     *     Linked list sorted set management implementation.
     * @details       
     *     Association
     *     -----------
     *     Linked list sorted set management implementation.
     */
    namespace collection {

        using ::consecution::ConjointlyConsequent;
        using ::composition::Compositional;
        using ::selection::Selective;
        using ::selection::Sectional;
        using ::selection::EquateSelections;
        using ::collection::Collective;
        using ::collection::Bisectional;
        using ::collection::EquateCollections;
        using ::sortation::Assortive;
        using ::sortation::SearchSection;
        using ::sortation::SearchBisection;
        using ::sortation::SearchBisectionIteratively;
        using ::sortation::SearchScalarBisection;
        using ::junction::consecution::Precedent;
        using ::junction::consecution::Consequent;
        using ::junction::consecution::Concessive;
        using ::junction::consecution::Precede;
        using ::junction::consecution::PrecedeSafely;
        using ::junction::consecution::Cede;
        using ::junction::consecution::CedeSafely;
        using ::junction::consecution::Proceed;
        using ::junction::consecution::Concede;
        using ::junction::consecution::ConcedeSafely;

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        AccreditCollection(
            Referential< const SinglyJunctive< Natural, Elemental > >
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
				Search = SearchScalarBisection< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental, Equate, Order, Scale >;
            SinglyPositional< Elemental >
                position;
            if (!set.first)
                return false;
            Scale.begin( set, position, 0 );
            return Search( set, value, position, Account( set ) - 1 );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Lineal< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Liner
        >
        static inline bool
        AccreditCollection(
            Referential< const DoublyJunctive< Natural, Elemental > >
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
				Search = SearchBisection< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Order, Liner >;
            DoublyPositional< Elemental >
                position;
            if (!set.first)
                return false;
            Liner.increment.begin( set, position, 0 );
            return Search( set, value, position, 0, Account( set ) - 1 );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< SinglyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        ComposeCollection(
            Referential< SinglyJunctive< Natural, Elemental > >
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
				Search = SearchScalarBisection< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental, Equate, Order, Scale >;
			SinglyPositional< Elemental >
                position;
            if (!set.first)
                return Proceed( set, value );
            Scale.begin( set, position, 0 );
            if (Search( set, value, position, Account( set ) - 1 ))
                return false;
            if (Order( Scale.go( set, position ).to, value ))
                return Cede( set, position, value );
            return Precede( set, position, value );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< DoublyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Lineal< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Liner
        >
        static inline bool
        ComposeCollection(
            Referential< DoublyJunctive< Natural, Elemental > >
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
				Search = SearchBisection< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Order, Liner >;
			DoublyPositional< Elemental >
                position;
            if (!set.first)
                return Proceed( set, value );
            Liner.increment.begin( set, position, 0 );
            if (Search( set, value, position, 0, Account( set ) - 1 ))
                return false;
            if (Order( Liner.increment.go( set, position ).to, value ))
                return Cede( set, position, value );
            return Precede( set, position, value );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Concessive< SinglyLinked< Elemental >, Natural, Elemental > >
                Concede,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        DiscomposeCollection(
            Referential< SinglyJunctive< Natural, Elemental > >
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
				Search = SearchScalarBisection< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental, Equate, Order, Scale >;
            SinglyPositional< Elemental >
                position;
            if (!set.first)
                return false;
            Scale.begin( set, position, 0 );
            if (!Search( set, value, position, Account( set ) - 1 ))
                return false;
            return Concede( set, position, 1 );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Concessive< DoublyLinked< Elemental >, Natural, Elemental > >
                Concede,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Lineal< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Liner
        >
        static inline bool
        DiscomposeCollection(
            Referential< DoublyJunctive< Natural, Elemental > >
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
				Search = SearchBisection< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Order, Liner >;
            DoublyPositional< Elemental >
                position;
            if (!set.first)
                return false;
            Liner.increment.begin( set, position, 0 );
            if (!Search( set, value, position, 0, Account( set ) - 1 ))
                return false;
            return Concede( set, position, 1 );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        RecomposeCollection(
            Referential< SinglyJunctive< Natural, Elemental > >
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
				Search = SearchScalarBisection< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental, Equate, Order, Scale >;
            SinglyPositional< Elemental >
                original_position,
                replacement_position,
                previous;
            Locational< SinglyNodal< Elemental > >
                result;
            Natural
                extent;
            if (!set.first)
                return false;
            extent = Account( set ) - 1;
            Scale.begin( set, original_position, 0 );
            if (!Search( set, original, original_position, extent ))
                return false;
            Scale.begin( set, replacement_position, 0 );
            if (Search( set, replacement, replacement_position, extent ))
                return false;
            result = Adjunct.proclaim( set, replacement );
            if (!result)
                return false;
            if (original_position.at != set.first) {
                Scale.begin( set, previous, 0 );
                while (GetNext( previous.at ) != original_position.at)
                    Scale.traverse( set, previous, 1 );
                SetNext( previous.at, GetNext( original_position.at ) );
                if (!GetNext( previous.at ))
                    set.last = previous.at;
            } else {
                set.first = GetNext( original_position.at );
            }
            SetNext( original_position.at, set.unused );
            set.unused = original_position.at;
            if (Order( Scale.go( set, replacement_position ).to, replacement )) {
                SetNext( result, GetNext( replacement_position.at ) );
                SetNext( replacement_position.at, result );
                if (!GetNext( result ))
                    set.last = result;
            } else {
                if (replacement_position.at != set.first) {
                    Scale.begin( set, previous, 0 );
                    while (GetNext( previous.at ) != replacement_position.at)
                        Scale.traverse( set, previous, 1 );
                    SetNext( previous.at, result );
                } else {
                    set.first = result;
                }
                SetNext( result, replacement_position.at );
            }
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Lineal< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Liner,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        RecomposeCollection(
            Referential< DoublyJunctive< Natural, Elemental > >
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
				Search = SearchBisection< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Order, Liner >;
            DoublyPositional< Elemental >
                original_position,
                replacement_position;
            Locational< DoublyNodal< Elemental > >
                result;
            Natural
                extent;
            if (!set.first)
                return false;
            extent = Account( set ) - 1;
            Liner.increment.begin( set, original_position, 0 );
            if (!Search( set, original, original_position, 0, extent ))
                return false;
            Liner.increment.begin( set, replacement_position, 0 );
            if (Search( set, replacement, replacement_position, 0, extent ))
                return false;
            result = Adjunct.proclaim( set, replacement );
            if (!result)
                return false;
            if (GetPrevious( original_position.at ))
                SetNext( GetPrevious( original_position.at ), GetNext( original_position.at ) );
            else
                set.first = GetNext( original_position.at );
            if (GetNext( original_position.at ))
                SetPrevious( GetNext( original_position.at ), GetPrevious( original_position.at ) );
            else
                set.last = GetPrevious( original_position.at );
            UnsetPrevious( original_position.at );
            SetNext( original_position.at, set.unused );
            if (set.unused)
                SetPrevious( set.unused, original_position.at );
            set.unused = original_position.at;
            if (Order( Liner.increment.go( set, replacement_position ).to, replacement )) {
                SetPrevious( result, replacement_position.at );
                SetNext( result, GetNext( replacement_position.at ) );
                SetNext( replacement_position.at, result );
                if (GetNext( result ))
                    SetPrevious( GetNext( result ), result );
                else
                    set.last = result;
            } else {
                SetPrevious( result, GetPrevious( replacement_position.at ) );
                SetNext( result, replacement_position.at );
                SetPrevious( replacement_position.at, result );
                if (GetPrevious( result ))
                    SetNext( GetPrevious( result ), result );
                else
                    set.first = result;
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Natural,
            typename Elemental,
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< SinglyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        CollateSelection(
            Referential< SinglyJunctive< Natural, Elemental > >
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
				Search = SearchScalarBisection< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental, Equate, Order, Scale >;
            SinglyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            Natural
                extent;
            RemoveAll( operand );
            if (!basis.begins( base, 0 ))
                return true;
            basis.scale.begin( base, base_position, 0 );
            if (!Proceed( operand, basis.scale.go( base, base_position ).to ))
                return false;
            extent = 1;
            while (true) {
                Referential< const Elemental >
                    base_value = basis.scale.go( base, base_position ).to;
                Scale.begin( operand, operand_position, 0 );
                if (!Search( operand, base_value, operand_position, extent )) {
                    if (Order( Scale.go( operand, operand_position ).to, base_value )) {
                        if (!Cede( operand, operand_position, base_value ))
                            return false;
                    } else {
                        if (!Precede( operand, operand_position, base_value ))
                            return false;
                    }
                    extent++;
                }
                if (!basis.traverses( base, base_position, 1 ))
                    break;
                basis.scale.traverse( base, base_position, 1 );
            }
            return true;
        }

        template <
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Natural,
            typename Elemental,
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< DoublyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Lineal< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Liner
        >
        static inline bool
        CollateSelection(
            Referential< DoublyJunctive< Natural, Elemental > >
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
				Search = SearchBisectionIteratively< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Order, Liner >;
            DoublyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            Natural
                before, after;
            RemoveAll( operand );
            if (!basis.begins( base, 0 ))
                return true;
            basis.scale.begin( base, base_position, 0 );
            if (!Proceed( operand, basis.scale.go( base, base_position ).to ))
                return false;
            Liner.increment.begin( operand, operand_position, 0 );
            before = after = 0;
            while (true) {
                Referential< const Elemental >
                    base_value = basis.scale.go( base, base_position ).to;
                if (!Search( operand, base_value, operand_position, before, after )) {
                    if (Order( Liner.increment.go( operand, operand_position ).to, base_value )) {
                        if (!Cede( operand, operand_position, base_value ))
                            return false;
                        after++;
                    } else {
                        if (!Precede( operand, operand_position, base_value ))
                            return false;
                        before++;
                    }
                }
                if (!basis.traverses( base, base_position, 1 ))
                    break;
                basis.scale.traverse( base, base_position, 1 );
            }
            return true;
        }

        template <
            typename Communicative,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Natural,
            typename Elemental,
            Referential< ConjointlyConsequent< Junctive< Communicative, Natural, Elemental >, Positional< Communicative, Elemental >, Basic, BasicPositional, BasicNatural, Elemental > >
                ProceedMany
        >
        static inline bool
        CollateCollection(
            Referential< Junctive< Communicative, Natural, Elemental > >
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
            RemoveAll( operand );
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
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< SinglyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        ComplementSelections(
            Referential< SinglyJunctive< Natural, Elemental > >
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
				SearchInOperand = SearchScalarBisection< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental, Equate, Order, Scale >;
            static auto&
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            static auto&
                CollateRelative = CollateSelection< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Scale >;
            SinglyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                base_extent;
            Natural
                operand_extent;
            if (relativity.begins( relative_set, 0 )) {
                if (basis.begins( base_set, 0 )) {
                    RemoveAll( operand );
                    base_extent = basis.survey( base_set ) - 1;
                    relativity.scale.begin( relative_set, relative_position, 0 );
                    while (true) {
                        Referential< const Elemental >
                            relative_value = relativity.scale.go( relative_set, relative_position ).to;
                        basis.scale.begin( base_set, base_position, 0 );
                        if (!SearchInBase( base_set, basis.scale, relative_value, base_position, base_extent )) {
                            if (Account( operand ) > 0) {
                                Scale.begin( operand, operand_position, 0 );
                                if (!SearchInOperand( operand, relative_value, operand_position, operand_extent )) {
                                    if (Order( Scale.go( operand, operand_position ).to, relative_value )) {
                                        if (!Cede( operand, operand_position, relative_value ))
                                            return false;
                                    } else {
                                        if (!Precede( operand, operand_position, relative_value ))
                                            return false;
                                    }
                                    operand_extent++;
                                }
                            } else {
                                if (!Proceed( operand, relative_value ))
                                    return false;
                                operand_extent = 0;
                            }
                        }
                        if (!relativity.traverses( relative_set, relative_position, 1 ))
                            break;
                        relativity.scale.traverse( relative_set, relative_position, 1 );
                    }
                } else {
                    CollateRelative( operand, relativity, relative_set );
                }
            } else {
                RemoveAll( operand );
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
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< DoublyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Lineal< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Liner
        >
        static inline bool
        ComplementSelections(
            Referential< DoublyJunctive< Natural, Elemental > >
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
				SearchInOperand = SearchBisectionIteratively< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Order, Liner >;
            static auto&
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            static auto&
                CollateRelative = CollateSelection< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Liner >;
            DoublyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                extent;
            Natural
                before, after;
            if (relativity.begins( relative_set, 0 )) {
                if (basis.begins( base_set, 0 )) {
                    RemoveAll( operand );
                    extent = basis.survey( base_set ) - 1;
                    relativity.scale.begin( relative_set, relative_position, 0 );
                    while (true) {
                        Referential< const Elemental >
                            relative_value = relativity.scale.go( relative_set, relative_position ).to;
                        basis.scale.begin( base_set, base_position, 0 );
                        if (!SearchInBase( base_set, basis.scale, relative_value, base_position, extent )) {
                            if (Account( operand ) > 0) {
                                if (!SearchInOperand( operand, relative_value, operand_position, before, after )) {
                                    if (Order( Liner.increment.go( operand, operand_position ).to, relative_value )) {
                                        if (!Cede( operand, operand_position, relative_value ))
                                            return false;
                                        after++;
                                    } else {
                                        if (!Precede( operand, operand_position, relative_value ))
                                            return false;
                                        before++;
                                    }
                                }
                            } else {
                                if (!Proceed( operand, relative_value ))
                                    return false;
                                Liner.increment.begin( operand, operand_position, 0 );
                                before = after = 0;
                            }
                        }
                        if (!relativity.traverses( relative_set, relative_position, 1 ))
                            break;
                        relativity.scale.traverse( relative_set, relative_position, 1 );
                    }
                } else {
                    CollateRelative( operand, relativity, relative_set );
                }
            } else {
                RemoveAll( operand );
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
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< SinglyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        DifferentiateSelections(
            Referential< SinglyJunctive< Natural, Elemental > >
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
				SearchInOperand = SearchScalarBisection< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental, Equate, Order, Scale >;
            static auto&
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            static auto&
                SearchInRelative = SearchSection< Relative, RelativePositional, RelativeNatural, Elemental, Equate >;
            static auto&
                CollateBase = CollateSelection< Basic, BasicPositional, BasicNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Scale >;
            static auto&
                CollateRelative = CollateSelection< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Scale >;
            SinglyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                base_extent;
            RelativeNatural
                relative_extent;
            Natural
                operand_extent;
            if (basis.begins( base_set, 0 )) {
                if (relativity.begins( relative_set, 0 )) {
                    RemoveAll( operand );
                    relative_extent = relativity.survey( relative_set ) - 1;
                    basis.scale.begin( base_set, base_position, 0 );
                    while (true) {
                        Referential< const Elemental >
                            base_value = basis.scale.go( base_set, base_position ).to;
                        relativity.scale.begin( relative_set, relative_position, 0 );
                        if (!SearchInRelative( relative_set, relativity.scale, base_value, relative_position, relative_extent )) {
                            if (Account( operand ) > 0) {
                                Scale.begin( operand, operand_position, 0 );
                                if (!SearchInOperand( operand, base_value, operand_position, operand_extent )) {
                                    if (Order( Scale.go( operand, operand_position ).to, base_value )) {
                                        if (!Cede( operand, operand_position, base_value ))
                                            return false;
                                    } else {
                                        if (!Precede( operand, operand_position, base_value ))
                                            return false;
                                    }
                                    operand_extent++;
                                }
                            } else {
                                if (!Proceed( operand, base_value ))
                                    return false;
                                operand_extent = 0;
                            }
                        }
                        if (!basis.traverses( base_set, base_position, 1 ))
                            break;
                        basis.scale.traverse( base_set, base_position, 1 );
                    }
                    base_extent = basis.survey( base_set ) - 1;
                    relativity.scale.begin( relative_set, relative_position, 0 );
                    while (true) {
                        Referential< const Elemental >
                            relative_value = relativity.scale.go( relative_set, relative_position ).to;
                        basis.scale.begin( base_set, base_position, 0 );
                        if (!SearchInBase( base_set, basis.scale, relative_value, base_position, base_extent )) {
                            if (Account( operand ) > 0) {
                                Scale.begin( operand, operand_position, 0 );
                                if (!SearchInOperand( operand, relative_value, operand_position, operand_extent )) {
                                    if (Order( Scale.go( operand, operand_position ).to, relative_value )) {
                                        if (!Cede( operand, operand_position, relative_value ))
                                            return false;
                                    } else {
                                        if (!Precede( operand, operand_position, relative_value ))
                                            return false;
                                    }
                                    operand_extent++;
                                }
                            } else {
                                if (!Proceed( operand, relative_value ))
                                    return false;
                                operand_extent = 0;
                            }
                        }
                        if (!relativity.traverses( relative_set, relative_position, 1 ))
                            break;
                        relativity.scale.traverse( relative_set, relative_position, 1 );
                    }
                } else {
                    return CollateBase( operand, basis, base_set );
                }
            } else if (relativity.begins( relative_set, 0 )) {
                return CollateRelative( operand, relativity, relative_set );
            } else {
                RemoveAll( operand );
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
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< DoublyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Lineal< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Liner
        >
        static inline bool
        DifferentiateSelections(
            Referential< DoublyJunctive< Natural, Elemental > >
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
				SearchInOperand = SearchBisectionIteratively< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Order, Liner >;
            static auto&
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            static auto&
                SearchInRelative = SearchSection< Relative, RelativePositional, RelativeNatural, Elemental, Equate >;
            static auto&
                CollateBase = CollateSelection< Basic, BasicPositional, BasicNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Liner >;
            static auto&
                CollateRelative = CollateSelection< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Liner >;
            DoublyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                base_extent;
            RelativeNatural
                relative_extent;
            Natural
                before, after;
            if (basis.begins( base_set, 0 )) {
                if (relativity.begins( relative_set, 0 )) {
                    RemoveAll( operand );
                    relative_extent = relativity.survey( relative_set ) - 1;
                    basis.scale.begin( base_set, base_position, 0 );
                    while (true) {
                        Referential< const Elemental >
                            base_value = basis.scale.go( base_set, base_position ).to;
                        relativity.scale.begin( relative_set, relative_position, 0 );
                        if (!SearchInRelative( relative_set, relativity.scale, base_value, relative_position, relative_extent )) {
                            if (Account( operand ) > 0) {
                                if (!SearchInOperand( operand, base_value, operand_position, before, after )) {
                                    if (Order( Liner.increment.go( operand, operand_position ).to, base_value )) {
                                        if (!Cede( operand, operand_position, base_value ))
                                            return false;
                                        after++;
                                    } else {
                                        if (!Precede( operand, operand_position, base_value ))
                                            return false;
                                        before++;
                                    }
                                }
                            } else {
                                if (!Proceed( operand, base_value ))
                                    return false;
                                before = after = 0;
                                Liner.increment.begin( operand, operand_position, 0 );
                            }
                        }
                        if (!basis.traverses( base_set, base_position, 1 ))
                            break;
                        basis.scale.traverse( base_set, base_position, 1 );
                    }
                    base_extent = basis.survey( base_set ) - 1;
                    relativity.scale.begin( relative_set, relative_position, 0 );
                    while (true) {
                        Referential< const Elemental >
                            relative_value = relativity.scale.go( relative_set, relative_position ).to;
                        basis.scale.begin( base_set, base_position, 0 );
                        if (!SearchInBase( base_set, basis.scale, relative_value, base_position, base_extent )) {
                            if (Account( operand ) > 0) {
                                if (!SearchInOperand( operand, relative_value, operand_position, before, after )) {
                                    if (Order( Liner.increment.go( operand, operand_position ).to, relative_value )) {
                                        if (!Cede( operand, operand_position, relative_value ))
                                            return false;
                                        after++;
                                    } else {
                                        if (!Precede( operand, operand_position, relative_value ))
                                            return false;
                                        before++;
                                    }
                                }
                            } else {
                                if (!Proceed( operand, relative_value ))
                                    return false;
                                before = after = 0;
                                Liner.increment.begin( operand, operand_position, 0 );
                            }
                        }
                        if (!relativity.traverses( relative_set, relative_position, 1 ))
                            break;
                        relativity.scale.traverse( relative_set, relative_position, 1 );
                    }
                } else {
                    return CollateBase( operand, basis, base_set );
                }
            } else if (relativity.begins( relative_set, 0 )) {
                return CollateRelative( operand, relativity, relative_set );
            } else {
                RemoveAll( operand );
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
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< SinglyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        IntersectSelections(
            Referential< SinglyJunctive< Natural, Elemental > >
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
				SearchInOperand = SearchScalarBisection< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental, Equate, Order, Scale >;
            static auto&
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            SinglyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                base_extent;
            Natural
                operand_extent;
            RemoveAll( operand );
            if (relativity.begins( relative_set, 0 ) && basis.begins( base_set, 0 )) {
                base_extent = basis.survey( base_set ) - 1;
                relativity.scale.begin( relative_set, relative_position, 0 );
                while (true) {
                    Referential< const Elemental >
                        relative_value = relativity.scale.go( relative_set, relative_position ).to;
                    basis.scale.begin( base_set, base_position, 0 );
                    if (SearchInBase( base_set, relativity.scale, relative_value, base_position, base_extent )) {
                        if (Account( operand ) > 0) {
                            Scale.begin( operand, operand_position, 0 );
                            if (!SearchInOperand( operand, relative_value, operand_position, operand_extent )) {
                                if (Order( Scale.go( operand, operand_position ).to, relative_value )) {
                                    if (!Cede( operand, operand_position, relative_value ))
                                        return false;
                                } else {
                                    if (!Precede( operand, operand_position, relative_value ))
                                        return false;
                                }
                                operand_extent++;
                            }
                        } else {
                            if (!Proceed( operand, relative_value ))
                                return false;
                            operand_extent = 0;
                        }
                    }
                    if (!relativity.traverses( relative_set, relative_position, 1 ))
                        break;
                    relativity.scale.traverse( relative_set, relative_position, 1 );
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
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< DoublyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Lineal< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Liner
        >
        static inline bool
        IntersectSelections(
            Referential< DoublyJunctive< Natural, Elemental > >
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
				SearchInOperand = SearchBisectionIteratively< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Order, Liner >;
            static auto&
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            DoublyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                extent;
            Natural
                before, after;
            RemoveAll( operand );
            if (relativity.begins( relative_set, 0 ) && basis.begins( base_set, 0 )) {
                extent = basis.survey( base_set ) - 1;
                relativity.scale.begin( relative_set, relative_position, 0 );
                while (true) {
                    Referential< const Elemental >
                        relative_value = relativity.scale.go( relative_set, relative_position ).to;
                    basis.scale.begin( base_set, base_position, 0 );
                    if (SearchInBase( base_set, relativity.scale, relative_value, base_position, extent )) {
                        if (Account( operand ) > 0) {
                            if (!SearchInOperand( operand, relative_value, operand_position, before, after )) {
                                if (Order( Liner.increment.go( operand, operand_position ).to, relative_value )) {
                                    if (!Cede( operand, operand_position, relative_value ))
                                        return false;
                                    after++;
                                } else {
                                    if (!Precede( operand, operand_position, relative_value ))
                                        return false;
                                    before++;
                                }
                            }
                        } else {
                            if (!Proceed( operand, relative_value ))
                                return false;
                            before = after = 0;
                            Liner.increment.begin( operand, operand_position, 0 );
                        }
                    }
                    if (!relativity.traverses( relative_set, relative_position, 1 ))
                        break;
                    relativity.scale.traverse( relative_set, relative_position, 1 );
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
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< SinglyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< SinglyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        UniteSelections(
            Referential< SinglyJunctive< Natural, Elemental > >
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
				SearchInOperand = SearchScalarBisection< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental, Equate, Order, Scale >;
            static auto&
                CollateBase = CollateSelection< Basic, BasicPositional, BasicNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Scale >;
            static auto&
                CollateRelative = CollateSelection< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Scale >;
            SinglyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Natural
                extent;
            if (basis.begins( base_set, 0 )) {
                if (relativity.begins( relative_set, 0 )) {
                    RemoveAll( operand );
                    basis.scale.begin( base_set, base_position, 0 ); 
                    while (true) {
                        Referential< const Elemental >
                            base_value = basis.scale.go( base_set, base_position ).to;
                        if (Account( operand ) > 0) {
                            Scale.begin( operand, operand_position, 0 );
                            SearchInOperand( operand, base_value, operand_position, extent );
                            if (Order( Scale.go( operand, operand_position ).to, base_value )) {
                                if (!Cede( operand, operand_position, base_value ))
                                    return false;
                            } else {
                                if (!Precede( operand, operand_position, base_value ))
                                    return false;
                            }
                            extent++;
                        } else {
                            if (!Proceed( operand, base_value ))
                                return false;
                            extent = 0;
                        }
                        if (!basis.traverses( base_set, base_position, 1 ))
                            break;
                        basis.scale.traverse( base_set, base_position, 1 );
                    }
                    relativity.scale.begin( relative_set, relative_position, 0 ); 
                    while (true) {
                        Referential< const Elemental >
                            relative_value = relativity.scale.go( relative_set, relative_position ).to;
                        if (Account( operand ) > 0) {
                            Scale.begin( operand, operand_position, 0 );
                            if (!SearchInOperand( operand, relative_value, operand_position, extent )) {
                                if (Order( Scale.go( operand, operand_position ).to, relative_value )) {
                                    if (!Cede( operand, operand_position, relative_value ))
                                        return false;
                                } else {
                                    if (!Precede( operand, operand_position, relative_value ))
                                        return false;
                                }
                                extent++;
                            }
                        } else {
                            if (!Proceed( operand, relative_value ))
                                return false;
                            extent = 0;
                        }
                        if (!relativity.traverses( relative_set, relative_position, 1 ))
                            break;
                        relativity.scale.traverse( relative_set, relative_position, 1 );
                    }
                } else {
                    return CollateBase( operand, basis, base_set );
                }
            } else if (relativity.begins( relative_set, 0 )) {
                return CollateRelative( operand, relativity, relative_set );
            } else {
                RemoveAll( operand );
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
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Precede,
            Referential< Precedent< DoublyLinked< Elemental >, Natural, Elemental > >
                Cede,
            Referential< Consequent< DoublyLinked< Elemental >, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const Lineal< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Liner
        >
        static inline bool
        UniteSelections(
            Referential< DoublyJunctive< Natural, Elemental > >
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
				SearchInOperand = SearchBisectionIteratively< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Order, Liner >;
            static auto&
                CollateBase = CollateSelection< Basic, BasicPositional, BasicNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Liner >;
            static auto&
                CollateRelative = CollateSelection< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Precede, Cede, Proceed, Equate, Order, Liner >;
            DoublyPositional< Elemental >
                operand_position;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            Natural
                before, after;
            if (basis.begins( base_set, 0 )) {
                if (relativity.begins( relative_set, 0 )) {
                    RemoveAll( operand );
                    basis.scale.begin( base_set, base_position, 0 ); 
                    while (true) {
                        Referential< const Elemental >
                            base_value = basis.scale.go( base_set, base_position ).to;
                        if (Account( operand ) > 0) {
                            SearchInOperand( operand, base_value, operand_position, before, after );
                            if (Order( Liner.increment.go( operand, operand_position ).to, base_value )) {
                                if (!Cede( operand, operand_position, base_value ))
                                    return false;
                                after++;
                            } else {
                                if (!Precede( operand, operand_position, base_value ))
                                    return false;
                                before++;
                            }
                        } else {
                            if (!Proceed( operand, base_value ))
                                return false;
                            before = after = 0;
                            Liner.increment.begin( operand, operand_position, 0 );
                        }
                        if (!basis.traverses( base_set, base_position, 1 ))
                            break;
                        basis.scale.traverse( base_set, base_position, 1 );
                    }
                    relativity.scale.begin( relative_set, relative_position, 0 ); 
                    while (true) {
                        Referential< const Elemental >
                            relative_value = relativity.scale.go( relative_set, relative_position ).to;
                        if (Account( operand ) > 0) {
                            if (!SearchInOperand( operand, relative_value, operand_position, before, after )) {
                                if (Order( Liner.increment.go( operand, operand_position ).to, relative_value )) {
                                    if (!Cede( operand, operand_position, relative_value ))
                                        return false;
                                    after++;
                                } else {
                                    if (!Precede( operand, operand_position, relative_value ))
                                        return false;
                                    before++;
                                }
                            }
                        } else {
                            if (!Proceed( operand, relative_value ))
                                return false;
                            before = after = 0;
                            Liner.increment.begin( operand, operand_position, 0 );
                        }
                        if (!relativity.traverses( relative_set, relative_position, 1 ))
                            break;
                        relativity.scale.traverse( relative_set, relative_position, 1 );
                    }
                } else {
                    return CollateBase( operand, basis, base_set );
                }
            } else if (relativity.begins( relative_set, 0 )) {
                return CollateRelative( operand, relativity, relative_set );
            } else {
                RemoveAll( operand );
            }
            return true;
        }

        template <
            typename Communicative,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Communicative, Natural, Elemental > >
                ProceedOne,
            Referential< ConjointlyConsequent< Junctive< Communicative, Natural, Elemental >, Positional< Communicative, Elemental >, Relative, RelativePositional, RelativeNatural, Elemental > >
                ProceedMany,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        ComplementCollections(
            Referential< Junctive< Communicative, Natural, Elemental > >
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
            BasicPositional
                position;
            RelativePositional
                opposition, last;
            RemoveAll( operand );
            if (relativity.increment.begins( relative_set, 0 )) {
                relativity.increment.scale.begin( relative_set, opposition, 0 );
                if (basis.increment.begins( base_set, 0 )) {
                    basis.increment.scale.begin( base_set, position, 0 );
                    while (true) {
                        Referential< const Elemental >
                            base_value = basis.increment.scale.go( base_set, position ).to,
                            relative_value = basis.increment.scale.go( relative_set, opposition ).to;
                        if (Equate( base_value, relative_value )) {
                            if (!relativity.increment.traverses( relative_set, opposition, 1 ))
                                return true;
                            relativity.increment.scale.traverse( relative_set, opposition, 1 );
                            if (!basis.increment.traverses( base_set, position, 1 ))
                                break;
                            basis.increment.scale.traverse( base_set, position, 1 );
                        } else if (Order( base_value, relative_value )) {
                            if (!basis.increment.traverses( base_set, position, 1 ))
                                break;
                            basis.increment.scale.traverse( base_set, position, 1 );
                        } else {
                            if (!ProceedOne( operand, relative_value ) )
                                return false;
                            if (!relativity.increment.traverses( relative_set, opposition, 1 ))
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
            typename Communicative,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Communicative, Natural, Elemental > >
                ProceedOne,
            Referential< ConjointlyConsequent< Junctive< Communicative, Natural, Elemental >, Positional< Communicative, Elemental >, Basic, BasicPositional, BasicNatural, Elemental > >
                ProceedManyFromBase,
            Referential< ConjointlyConsequent< Junctive< Communicative, Natural, Elemental >, Positional< Communicative, Elemental >, Relative, RelativePositional, RelativeNatural, Elemental > >
                ProceedManyFromRelative,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        DifferentiateCollections(
            Referential< Junctive< Communicative, Natural, Elemental > >
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
            RemoveAll( operand );
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
                    Referential< const Elemental >
                        base_value = basis.increment.scale.go( base_set, position ).to,
                        relative_value = relativity.increment.scale.go( relative_set, opposition ).to;
                    if (Equate( base_value, relative_value )) {
                        if (!basis.increment.traverses( base_set, position, 1 )) {
                            if (!relativity.increment.traverses( relative_set, opposition, 1 ))
                                break;
                            relativity.increment.scale.traverse( relative_set, opposition, 1 );
                            return RemainingRelative();
                        } else if (!relativity.increment.traverses( relative_set, opposition, 1 )) {
                            basis.increment.scale.traverse( base_set, position, 1 );
                            return RemainingBase();
                        }
                        basis.increment.scale.traverse( base_set, position, 1 );
                        relativity.increment.scale.traverse( relative_set, opposition, 1 );
                    } else if (Order( base_value, relative_value )) {
                        if (!ProceedOne( operand, base_value ))
                            return false;
                        if (!basis.increment.traverses( base_set, position, 1 ))
                            return RemainingRelative();
                        basis.increment.scale.traverse( base_set, position, 1 );
                    } else {
                        if (!ProceedOne( operand, relative_value ))
                            return false;
                        if (!relativity.increment.traverses( relative_set, opposition, 1 ))
                            return RemainingBase();
                        relativity.increment.scale.traverse( relative_set, opposition, 1 );
                    }
                }
            }
            return true;
        }

        template <
            typename Communicative,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Communicative, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        IntersectCollections(
            Referential< Junctive< Communicative, Natural, Elemental > >
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
            BasicPositional
                position;
            RelativePositional
                opposition;
            RemoveAll( operand );
            if (!basis.increment.begins( base_set, 0 ) || !relativity.increment.begins( relative_set, 0 ))
                return true;
            basis.increment.scale.begin( base_set, position, 0 );
            relativity.increment.scale.begin( relative_set, opposition, 0 );
            while (true) {
                Referential< const Elemental >
                    base_value = basis.increment.scale.go( base_set, position ).to,
                    relative_value = relativity.increment.scale.go( relative_set, opposition ).to;
                if (Equate( base_value, relative_value )) {
                    if (!Proceed( operand, base_value ))
                        return false;
                    if (!basis.increment.traverses( base_set, position, 1 ))
                        return true;
                    if (!relativity.increment.traverses( relative_set, opposition, 1 ))
                        return true;
                    basis.increment.scale.traverse( base_set, position, 1 );
                    relativity.increment.scale.traverse( relative_set, opposition, 1 );
                } else if (Order( base_value, relative_value )) {
                    if (!basis.increment.traverses( base_set, position, 1 ))
                        return true;
                    basis.increment.scale.traverse( base_set, position, 1 );
                } else {
                    if (!relativity.increment.traverses( relative_set, opposition, 1 ))
                        return true;
                    relativity.increment.scale.traverse( relative_set, opposition, 1 );
                }
            }
            return true;
        }

        template <
            typename Communicative,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Communicative, Natural, Elemental > >
                ProceedOne,
            Referential< ConjointlyConsequent< Junctive< Communicative, Natural, Elemental >, Positional< Communicative, Elemental >, Basic, BasicPositional, BasicNatural, Elemental > >
                ProceedManyFromBase,
            Referential< ConjointlyConsequent< Junctive< Communicative, Natural, Elemental >, Positional< Communicative, Elemental >, Relative, RelativePositional, RelativeNatural, Elemental > >
                ProceedManyFromRelative,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order
        >
        static inline bool
        UniteCollections(
            Referential< Junctive< Communicative, Natural, Elemental > >
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
            RemoveAll( operand );
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
                Referential< const Elemental >
                    base_value = basis.increment.scale.go( base_set, position ).to,
                    relative_value = relativity.increment.scale.go( relative_set, apposition ).to;
                if (Equate( base_value, relative_value )) {
                    if (!ProceedOne( operand, base_value ))
                        return false;
                    if (!basis.increment.traverses( base_set, position, 1 )) {
                        if (!relativity.increment.traverses( relative_set, apposition, 1 ))
                            return true;
                        relativity.increment.scale.traverse( relative_set, apposition, 1 );
                        return RemainingRelative();
                    } else if (!relativity.increment.traverses( relative_set, apposition, 1 )) {
                        basis.increment.scale.traverse( base_set, position, 1 );
                        return RemainingBase();
                    }
                    basis.increment.scale.traverse( base_set, position, 1 );
                    relativity.increment.scale.traverse( relative_set, apposition, 1 );
                } else if (Order( base_value, relative_value )) {
                    if (!ProceedOne( operand, base_value ))
                        return false;
                    if (!basis.increment.traverses( base_set, position, 1 ))
                        return RemainingRelative();
                    basis.increment.scale.traverse( base_set, position, 1 );
                } else {
                    if (!ProceedOne( operand, relative_value ))
                        return false;
                    if (!relativity.increment.traverses( relative_set, apposition, 1 ))
                        return RemainingBase();
                    relativity.increment.scale.traverse( relative_set, apposition, 1 );
                }
            }
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< SinglyJunctive< Natural, Elemental >, Natural, Elemental >
        OrderedSingleComposer = {
            Instantiate< SinglyLinked< Elemental >, Natural, Elemental, Adjunct >,
            AccreditCollection< Natural, Elemental, Equate, Order, ReadIncrementSingleScale< Natural, Elemental > >,
            ComposeCollection<
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order, 
                ReadIncrementSingleScale< Natural, Elemental > 
            >,
            RecomposeCollection<
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                ReadIncrementSingleScale< Natural, Elemental >,
                Adjunct
            >,
            DiscomposeCollection<
                Natural, 
                Elemental, 
                Concede< Natural, Elemental >, 
                Equate, 
                Order, 
                ReadIncrementSingleScale< Natural, Elemental > 
            >,
            RemoveAll< SinglyLinked< Elemental >, Natural, Elemental >,
            DeleteOneNode< Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< DoublyJunctive< Natural, Elemental >, Natural, Elemental >
        OrderedDoubleComposer = {
            Instantiate< DoublyLinked< Elemental >, Natural, Elemental, Adjunct >,
            AccreditCollection< Natural, Elemental, Equate, Order, ReadDoubleLiner< Natural, Elemental > >,
            ComposeCollection<
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order, 
                ReadDoubleLiner< Natural, Elemental > 
            >,
            RecomposeCollection<
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                ReadDoubleLiner< Natural, Elemental >,
                Adjunct
            >,
            DiscomposeCollection< 
                Natural, 
                Elemental, 
                Concede< Natural, Elemental >, 
                Equate, 
                Order, 
                ReadDoubleLiner< Natural, Elemental > 
            >,
            RemoveAll< DoublyLinked< Elemental >, Natural, Elemental >,
            DeleteOneNode< Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< SinglyJunctive< Natural, Elemental >, Natural, Elemental >
        SafeOrderedSingleComposer = {
            Instantiate< SinglyLinked< Elemental >, Natural, Elemental, Adjunct >,
            AccreditCollection< Natural, Elemental, Equate, Order, SafeReadIncrementSingleScale< Natural, Elemental > >,
            ComposeCollection<
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order, 
                SafeReadIncrementSingleScale< Natural, Elemental > 
            >,
            RecomposeCollection<
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                SafeReadIncrementSingleScale< Natural, Elemental >,
                Adjunct
            >,
            DiscomposeCollection<
                Natural, 
                Elemental, 
                ConcedeSafely< Natural, Elemental >, 
                Equate, 
                Order, 
                SafeReadIncrementSingleScale< Natural, Elemental > 
            >,
            RemoveAll< SinglyLinked< Elemental >, Natural, Elemental >,
            DeleteOneNode< Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< DoublyJunctive< Natural, Elemental >, Natural, Elemental >
        SafeOrderedDoubleComposer = {
            Instantiate< DoublyLinked< Elemental >, Natural, Elemental, Adjunct >,
            AccreditCollection< Natural, Elemental, Equate, Order, SafeReadDoubleLiner< Natural, Elemental > >,
            ComposeCollection<
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order, 
                SafeReadDoubleLiner< Natural, Elemental > 
            >,
            RecomposeCollection<
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                SafeReadDoubleLiner< Natural, Elemental >,
                Adjunct
            >,
            DiscomposeCollection< 
                Natural, 
                Elemental, 
                ConcedeSafely< Natural, Elemental >, 
                Equate, 
                Order, 
                SafeReadDoubleLiner< Natural, Elemental > 
            >,
            RemoveAll< DoublyLinked< Elemental >, Natural, Elemental >,
            DeleteOneNode< Natural, Elemental, Adjunct >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< SinglyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        OrderedSingleSection = {
            ComplementSelections<
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadIncrementSingleScale< Natural, Elemental >
            >,
            DifferentiateSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadIncrementSingleScale< Natural, Elemental >
            >,
            IntersectSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >,
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadIncrementSingleScale< Natural, Elemental >
            >,
            UniteSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >,
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadIncrementSingleScale< Natural, Elemental >
            >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< DoublyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        OrderedDoubleSection = {
            ComplementSelections<
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadDoubleLiner< Natural, Elemental >
            >,
            DifferentiateSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadDoubleLiner< Natural, Elemental >
            >,
            IntersectSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >,
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadDoubleLiner< Natural, Elemental >
            >,
            UniteSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >,
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadDoubleLiner< Natural, Elemental >
            >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< SinglyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        SafeOrderedSingleSection = {
            ComplementSelections<
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadIncrementSingleScale< Natural, Elemental >
            >,
            DifferentiateSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadIncrementSingleScale< Natural, Elemental >
            >,
            IntersectSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >,
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadIncrementSingleScale< Natural, Elemental >
            >,
            UniteSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >,
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadIncrementSingleScale< Natural, Elemental >
            >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< DoublyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        SafeOrderedDoubleSection = {
            ComplementSelections<
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadDoubleLiner< Natural, Elemental >
            >,
            DifferentiateSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadDoubleLiner< Natural, Elemental >
            >,
            IntersectSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >,
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadDoubleLiner< Natural, Elemental >
            >,
            UniteSelections< 
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >,
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadDoubleLiner< Natural, Elemental >
            >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
        OrderedSingleSelector = {
            OrderedSingleComposer< Natural, Elemental, Equate, Order, Adjunct >,
            OrderedSingleSection< 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                Adjunct 
            >,
            CollateSelection< 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadIncrementSingleScale< Natural, Elemental >
            >,
            EquateSelections< 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Elemental, 
                Equate 
            >,
            Account< SinglyLinked< Elemental >, Natural, Elemental >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
        OrderedDoubleSelector = {
            OrderedDoubleComposer< Natural, Elemental, Equate, Order, Adjunct >,
            OrderedDoubleSection< 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                Adjunct 
            >,
            CollateSelection< 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Precede< Natural, Elemental, Adjunct >, 
                Cede< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                ReadDoubleLiner< Natural, Elemental >
            >,
            EquateSelections< 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Elemental, 
                Equate 
            >,
            Account< DoublyLinked< Elemental >, Natural, Elemental >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
        SafeOrderedSingleSelector = {
            SafeOrderedSingleComposer< Natural, Elemental, Equate, Order, Adjunct >,
            SafeOrderedSingleSection< 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                Adjunct 
            >,
            CollateSelection< 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadIncrementSingleScale< Natural, Elemental >
            >,
            EquateSelections< 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Elemental, 
                Equate 
            >,
            Account< SinglyLinked< Elemental >, Natural, Elemental >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
        SafeOrderedDoubleSelector = {
            SafeOrderedDoubleComposer< Natural, Elemental, Equate, Order, Adjunct >,
            SafeOrderedDoubleSection< 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                Adjunct 
            >,
            CollateSelection< 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                PrecedeSafely< Natural, Elemental, Adjunct >, 
                CedeSafely< Natural, Elemental, Adjunct >, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order,
                SafeReadDoubleLiner< Natural, Elemental >
            >,
            EquateSelections< 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Elemental, 
                Equate 
            >,
            Account< DoublyLinked< Elemental >, Natural, Elemental >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Bisectional< SinglyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        SingleBisection = {
            ComplementCollections< 
                SinglyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct, false >, 
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, false >, 
                Equate, 
                Order 
            >,
            DifferentiateCollections< 
                SinglyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct, false >, 
                Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, false >,
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, false >, 
                Equate, 
                Order 
            >,
            IntersectCollections< 
                SinglyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct, false >, 
                Equate, 
                Order 
            >,
            UniteCollections< 
                SinglyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct, false >, 
                Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, false >, 
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, false >, 
                Equate, 
                Order 
            >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Bisectional< DoublyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        DoubleBisection = {
            ComplementCollections< 
                DoublyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, false >, 
                Equate, 
                Order 
            >,
            DifferentiateCollections< 
                DoublyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, false >,
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, false >, 
                Equate, 
                Order 
            >,
            IntersectCollections< 
                DoublyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order 
            >,
            UniteCollections< 
                DoublyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, false >, 
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, false >, 
                Equate, 
                Order 
            >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Bisectional< SinglyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        SafeSingleBisection = {
            ComplementCollections< 
                SinglyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                Equate, 
                Order 
            >,
            DifferentiateCollections< 
                SinglyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, true >,
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                Equate, 
                Order 
            >,
            IntersectCollections< 
                SinglyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order 
            >,
            UniteCollections< 
                SinglyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, true >, 
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                Equate, 
                Order 
            >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Bisectional< DoublyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
        SafeDoubleBisection = {
            ComplementCollections< 
                DoublyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                Equate, 
                Order 
            >,
            DifferentiateCollections< 
                DoublyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, true >,
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                Equate, 
                Order 
            >,
            IntersectCollections< 
                DoublyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Equate, 
                Order 
            >,
            UniteCollections< 
                DoublyLinked< Elemental >,
                Basic, 
                BasicPositional, 
                BasicNatural, 
                Relative, 
                RelativePositional, 
                RelativeNatural, 
                Natural, 
                Elemental, 
                Proceed< Natural, Elemental, Adjunct >, 
                Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, true >, 
                Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                Equate, 
                Order 
            >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Collective< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
        SingleCollector = {
            OrderedSingleSelector< Natural, Elemental, Equate, Order, Adjunct >,
            SingleBisection<
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                Adjunct 
            >,
            CollateCollection<
                SinglyLinked< Elemental >,
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Proceed< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Natural, Elemental, Adjunct, false > 
            >,
            EquateCollections< 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Elemental, 
                Equate 
            >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Collective< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
        DoubleCollector = {
            OrderedDoubleSelector< Natural, Elemental, Equate, Order, Adjunct >,
            DoubleBisection<
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                Adjunct 
            >,
            CollateCollection<
                DoublyLinked< Elemental >,
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Proceed< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Natural, Elemental, Adjunct, false > 
            >,
            EquateCollections< 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Elemental, 
                Equate 
            >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Collective< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
        SafeSingleCollector = {
            SafeOrderedSingleSelector< Natural, Elemental, Equate, Order, Adjunct >,
            SafeSingleBisection<
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                Adjunct 
            >,
            CollateCollection<
                SinglyLinked< Elemental >,
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Proceed< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Natural, Elemental, Adjunct, true > 
            >,
            EquateCollections< 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                SinglyJunctive< Natural, Elemental >, 
                SinglyPositional< Elemental >, 
                Natural, 
                Elemental, 
                Equate 
            >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Collective< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
        SafeDoubleCollector = {
            SafeOrderedDoubleSelector< Natural, Elemental, Equate, Order, Adjunct >,
            SafeDoubleBisection<
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Equate, 
                Order, 
                Adjunct 
            >,
            CollateCollection<
                DoublyLinked< Elemental >,
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Natural, 
                Elemental, 
                Proceed< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Natural, Elemental, Adjunct, true > 
            >,
            EquateCollections< 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                DoublyJunctive< Natural, Elemental >, 
                DoublyPositional< Elemental >, 
                Natural, 
                Elemental, 
                Equate 
            >
        };

    }

}

#endif
