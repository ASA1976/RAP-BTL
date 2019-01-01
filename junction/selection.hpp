// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_SELECTION_MODULE
#define JUNCTION_SELECTION_MODULE
#include "consecution.hpp"
#include "../selection.hpp"

namespace junction {

    /**
     * @brief         
     *     Linked list unsorted set management implementation.
     * @details       
     *     Association
     *     -----------
     *     Linked list unsorted set management implementation.
     */
    namespace selection {

        using ::composition::Compositional;
        using ::selection::Selective;
        using ::selection::Sectional;
        using ::selection::EquateSelections;
        using ::sortation::Assortive;
        using ::sortation::SearchSection;
        using ::junction::consecution::Consequent;
        using ::junction::consecution::Concessive;
        using ::junction::consecution::Recessive;
        using ::junction::consecution::Proceed;
        using ::junction::consecution::Succeed;
        using ::junction::consecution::SucceedSafely;
        using ::junction::consecution::Concede;
        using ::junction::consecution::ConcedeSafely;

        template <
            typename Connective,
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const Scalar< const Junctive< Connective, Natural, Elemental >, Positional< Connective, Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        AccreditSelection(
            Referential< const Junctive< Connective, Natural, Elemental > >
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
                Search = SearchSection< Junctive< Connective, Natural, Elemental >, Positional< Connective, Elemental >, Natural, Elemental, Equate, Scale >;
            Positional< Connective, Elemental >
                position;
            if (!set.first)
                return false;
            Scale.begin( set, position, 0 );
            return Search( set, value, position, Account( set ) - 1 );
        }

        template <
            typename Connective,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Connective, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const Scalar< const Junctive< Connective, Natural, Elemental >, Positional< Connective, Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        ComposeSelection(
            Referential< Junctive< Connective, Natural, Elemental > >
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
                Search = SearchSection< Junctive< Connective, Natural, Elemental >, Positional< Connective, Elemental >, Natural, Elemental, Equate, Scale >;
			Positional< Connective, Elemental >
                position;
            if (!set.first)
                return Proceed( set, value );
            Scale.begin( set, position, 0 );
            if (Search( set, value, position, Account( set ) - 1 ))
                return false;
            return Proceed( set, value );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Recessive< SinglyLinked< Elemental >, Natural, Elemental > >
                Succeed,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        DiscomposeSelection(
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
            SinglyPositional< Elemental >
                position;
            Locational< SinglyNodal< Elemental > >
                previous;
            Natural
                count;
            if (!set.first)
                return false;
            previous = 0;
            Scale.begin( set, position, 0 );
            for (count = Account( set ); count > 0; count--) {
                if (Equate( Scale.go( set, position ).to, value )) {
                    if (!previous)
                        return Succeed( set, 1 );
                    SetNext( previous, GetNext( position.at ) );
                    SetNext( position.at, set.unused );
                    if (!GetNext( previous ))
                        set.last = previous;
                    set.unused = position.at;
                    set.count--;
                    return true;
                }
                previous = position.at;
                Scale.traverse( set, position, 1 );
            }
            return false;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Concessive< DoublyLinked< Elemental >, Natural, Elemental > >
                Concede,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const Scalar< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Scale
        >
        static inline bool
        DiscomposeSelection(
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
                Search = SearchSection< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental, Equate, Scale >;
            DoublyPositional< Elemental >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const Scalar< const SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, const Elemental > >
                Scale,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        RecomposeSelection(
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
            SinglyPositional< Elemental >
                position;
            Locational< SinglyNodal< Elemental > >
                previous, found, result;
            Natural
                count;
            if (!set.first)
                return false;
            previous = result = found = 0;
            Scale.begin( set, position, 0 );
            for (count = Account( set ); count > 0; count--) {
                const auto&
                    value = Scale.go( set, position ).to;
                if (Equate( value, replacement ))
                    return false;
                if (Equate( value, original ))
                    found = position.at;
                else if (!found)
                    previous = position.at;
                Scale.traverse( set, position, 1 );
            }
            if (!found)
                return false;
            result = Adjunct.proclaim( set, replacement );
            if (!result)
                return false;
            if (previous)
                SetNext( previous, GetNext( found ) );
            else
                set.first = GetNext( found );
            SetNext( found, set.unused );
            set.unused = found;
            SetNext( result, 0 );
            if (set.first)
                SetNext( set.last, result );
            else
                set.first = result;
            set.last = result;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const Scalar< const DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, const Elemental > >
                Scale,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        RecomposeSelection(
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
            DoublyPositional< Elemental >
                position;
            Locational< DoublyNodal< Elemental > >
                found, result;
            Natural
                count;
            if (!set.first)
                return false;
            result = found = 0;
            Scale.begin( set, position, 0 );
            for (count = Account( set ); count > 0; count--) {
                const auto&
                    value = Scale.go( set, position ).to;
                if (Equate( value, replacement ))
                    return false;
                if (Equate( value, original ))
                    found = position.at;
                Scale.traverse( set, position, 1 );
            }
            if (!found)
                return false;
            result = Adjunct.proclaim( set, replacement );
            if (!result)
                return false;
            if (GetPrevious( found ))
                SetNext( GetPrevious( found ), GetNext( found ) );
            else
                set.first = GetNext( found );
            if (GetNext( found ))
                SetPrevious( GetNext( found ), GetPrevious( found ) );
            else
                set.last = GetPrevious( found );
            UnsetPrevious( found );
            SetNext( found, set.unused );
            if (set.unused)
                SetPrevious( set.unused, found );
            set.unused = found;
            UnsetNext( result );
            SetPrevious( result, set.last );
            if (set.last)
                SetNext( set.last, result );
            else
                set.first = result;
            set.last = result;
            return true;
        }

        template <
            typename Connective,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Connective, Natural, Elemental > >
                Proceed
        >
        static inline bool
        DuplicateSelection(
            Referential< Junctive< Connective, Natural, Elemental > >
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
            BasicPositional
                position;
            RemoveAll( operand );
            if (!basis.begins( base, 0 ))
                return true;
            basis.scale.begin( base, position, 0 );
            while (true) {
                if (!Proceed( operand, basis.scale.go( base, position ).to ))
                    return false;
                if (!basis.traverses( base, position, 1 ))
                    break;
                basis.scale.traverse( base, position, 1 );
            }
            return true;
        }

        template <
            typename Connective,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Connective, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        ComplementSelections(
            Referential< Junctive< Connective, Natural, Elemental > >
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
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            static auto&
                DuplicateRelative = DuplicateSelection< Connective, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                extent;
            if (relativity.begins( relative_set, 0 )) {
                if (basis.begins( base_set, 0 )) {
                    RemoveAll( operand );
                    extent = basis.survey( base_set ) - 1;
                    relativity.scale.begin( relative_set, relative_position, 0 );
                    while (true) {
                        const auto&
                            value = relativity.scale.go( relative_set, relative_position ).to;
                        basis.scale.begin( base_set, base_position, 0 );
                        if (!SearchInBase( base_set, basis.scale, value, base_position, extent ))
                            if (!Proceed( operand, value ))
                                return false;
                        if (!relativity.traverses( relative_set, relative_position, 1 ))
                            break;
                        relativity.scale.traverse( relative_set, relative_position, 1 );
                    }
                } else {
                    return DuplicateRelative( operand, relativity, relative_set );
                }
            } else {
                RemoveAll( operand );
            }
            return true;
        }

        template <
            typename Connective,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Connective, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        DifferentiateSelections(
            Referential< Junctive< Connective, Natural, Elemental > >
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
                DuplicateBase = DuplicateSelection< Connective, Basic, BasicPositional, BasicNatural, Natural, Elemental, Proceed >;
            static auto&
                DuplicateRelative = DuplicateSelection< Connective, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed >;
            static auto&
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            static auto&
                SearchInRelative = SearchSection< Relative, RelativePositional, RelativeNatural, Elemental, Equate >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                base_extent;
            RelativeNatural
                relative_extent;
            if (basis.begins( base_set, 0 )) {
                if (!relativity.begins( relative_set, 0 ))
                    return DuplicateBase( operand, basis, base_set );
            } else if (relativity.begins( relative_set, 0 )) {
                return DuplicateRelative( operand, relativity, relative_set );
            } else {
                RemoveAll( operand );
                return true;
            }
            RemoveAll( operand );
            relative_extent = relativity.survey( relative_set ) - 1;
            basis.scale.begin( base_set, base_position, 0 );
            while (true) {
                const auto&
                    value = basis.scale.go( base_set, base_position ).to;
                relativity.scale.begin( relative_set, relative_position, 0 );
                if (!SearchInRelative( relative_set, relativity.scale, value, relative_position, relative_extent )) {
                    if (!Proceed( operand, value ))
                        return false;
                }
                if (!basis.traverses( base_set, base_position, 1 ))
                    break;
                basis.scale.traverse( base_set, base_position, 1 );
            }
            base_extent = basis.survey( base_set ) - 1;
            relativity.scale.begin( relative_set, relative_position, 0 );
            while (true) {
                const auto&
                    value = relativity.scale.go( relative_set, relative_position ).to;
                basis.scale.begin( base_set, base_position, 0 );
                if (!SearchInBase( base_set, basis.scale, value, base_position, base_extent )) {
                    if (!Proceed( operand, value ))
                        return false;
                }
                if (!relativity.traverses( relative_set, relative_position, 1 ))
                    break;
                relativity.scale.traverse( relative_set, relative_position, 1 );
            }
            return true;
        }

        template <
            typename Connective,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Connective, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        IntersectSelections(
            Referential< Junctive< Connective, Natural, Elemental > >
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
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                base_extent;
            RemoveAll( operand );
            if (relativity.begins( relative_set, 0 ) && basis.begins( base_set, 0 )) {
                base_extent = basis.survey( base_set ) - 1;
                relativity.scale.begin( relative_set, relative_position, 0 );
                while (true) {
                    const auto&
                        value = relativity.scale.go( relative_set, relative_position ).to;
                    basis.scale.begin( base_set, base_position, 0 );
                    if (SearchInBase( base_set, basis.scale, value, base_position, base_extent)) {
                        if (!Proceed( operand, value ))
                            return false;
                    }
                    if (!relativity.traverses( relative_set, relative_position, 1 ))
                        break;
                    relativity.scale.traverse( relative_set, relative_position, 1 );
                }
            }
            return true;
        }

        template <
            typename Connective,
            typename Basic,
            typename BasicPositional,
            typename BasicNatural,
            typename Relative,
            typename RelativePositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< Consequent< Connective, Natural, Elemental > >
                Proceed,
            Referential< Assortive< Elemental > >
                Equate
        >
        static inline bool
        UniteSelections(
            Referential< Junctive< Connective, Natural, Elemental > >
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
                DuplicateBase = DuplicateSelection< Connective, Basic, BasicPositional, BasicNatural, Natural, Elemental, Proceed >;
            static auto&
                DuplicateRelative = DuplicateSelection< Connective, Relative, RelativePositional, RelativeNatural, Natural, Elemental, Proceed >;
            static auto&
                SearchInBase = SearchSection< Basic, BasicPositional, BasicNatural, Elemental, Equate >;
            BasicPositional
                base_position;
            RelativePositional
                relative_position;
            BasicNatural
                base_extent;
            if (basis.begins( base_set, 0 )) {
                if (!DuplicateBase( operand, basis, base_set ))
                    return false;
                if (relativity.begins( relative_set, 0 )) {
                    base_extent = basis.survey( base_set ) - 1;
                    relativity.scale.begin( relative_set, relative_position, 0 );
                    while (true) {
                        const auto&
                            value = relativity.scale.go( relative_set, relative_position ).to;
                        basis.scale.begin( base_set, base_position, 0 );
                        if (!SearchInBase( base_set, basis.scale, value, base_position, base_extent )) {
                            if (!Proceed( operand, value ))
                                return false;
                        }
                        if (!relativity.traverses( relative_set, relative_position, 1 ))
                            break;
                        relativity.scale.traverse( relative_set, relative_position, 1 );
                    }
                }
            } else if (relativity.begins( relative_set, 0 )) {
                if (!DuplicateRelative( operand, relativity, relative_set ))
                    return false;
            } else {
                RemoveAll( operand );
            }
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< SinglyJunctive< Natural, Elemental >, Natural, Elemental >
            SingleComposer = {
                Instantiate< SinglyLinked< Elemental >, Natural, Elemental, Adjunct >,
                AccreditSelection< 
                    SinglyLinked< Elemental >, 
                    Natural, 
                    Elemental, 
                    Equate, 
                    ReadIncrementSingleScale< Natural, Elemental > 
                >,
                ComposeSelection< 
                    SinglyLinked< Elemental >, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    ReadIncrementSingleScale< Natural, Elemental > 
                >,
                RecomposeSelection< 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Succeed< Natural, Elemental >, 
                    Equate, 
                    ReadIncrementSingleScale< Natural, Elemental > 
                >,
                DiscomposeSelection< 
                    Natural, 
                    Elemental, 
                    Succeed< Natural, Elemental >, 
                    Equate, 
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
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< DoublyJunctive< Natural, Elemental >, Natural, Elemental >
            DoubleComposer = {
                Instantiate< DoublyLinked< Elemental >, Natural, Elemental, Adjunct >,
                AccreditSelection< 
                    DoublyLinked< Elemental >, 
                    Natural, 
                    Elemental, 
                    Equate, 
                    ReadIncrementDoubleScale< Natural, Elemental > 
                >,
                ComposeSelection< 
                    DoublyLinked< Elemental >, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    ReadIncrementDoubleScale< Natural, Elemental > 
                >,
                RecomposeSelection< 
                    Natural, 
                    Elemental, 
                    Equate, 
                    ReadIncrementDoubleScale< Natural, Elemental >,
                    Adjunct
                >,
                DiscomposeSelection< 
                    Natural, 
                    Elemental, 
                    Concede< Natural, Elemental >, 
                    Equate, 
                    ReadIncrementDoubleScale< Natural, Elemental >
                >,
                RemoveAll< DoublyLinked< Elemental >, Natural, Elemental >,
                DeleteOneNode< Natural, Elemental, Adjunct >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< SinglyJunctive< Natural, Elemental >, Natural, Elemental >
            SafeSingleComposer = {
                Instantiate< SinglyLinked< Elemental >, Natural, Elemental, Adjunct >,
                AccreditSelection< 
                    SinglyLinked< Elemental >, 
                    Natural, 
                    Elemental, 
                    Equate, 
                    SafeReadIncrementSingleScale< Natural, Elemental > 
                >,
                ComposeSelection< 
                    SinglyLinked< Elemental >, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    SafeReadIncrementSingleScale< Natural, Elemental > 
                >,
                RecomposeSelection< 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    SucceedSafely< Natural, Elemental >, 
                    Equate, 
                    SafeReadIncrementSingleScale< Natural, Elemental >
                >,
                DiscomposeSelection< 
                    Natural, 
                    Elemental, 
                    SucceedSafely< Natural, Elemental >, 
                    Equate, 
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
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< DoublyJunctive< Natural, Elemental >, Natural, Elemental >
            SafeDoubleComposer = {
                Instantiate< DoublyLinked< Elemental >, Natural, Elemental, Adjunct >,
                AccreditSelection< 
                    DoublyLinked< Elemental >, 
                    Natural, 
                    Elemental, 
                    Equate, 
                    SafeReadIncrementDoubleScale< Natural, Elemental > 
                >,
                ComposeSelection< 
                    DoublyLinked< Elemental >, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    SafeReadIncrementDoubleScale< Natural, Elemental > 
                >,
                RecomposeSelection< 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    SucceedSafely< Natural, Elemental >, 
                    Equate, 
                    SafeReadIncrementDoubleScale< Natural, Elemental >
                >,
                DiscomposeSelection< 
                    Natural, 
                    Elemental, 
                    SucceedSafely< Natural, Elemental >, 
                    Equate, 
                    SafeReadIncrementDoubleScale< Natural, Elemental >
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
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< SinglyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
            SingleSection = {
                ComplementSelections< 
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
                    Equate
                >,
                DifferentiateSelections< 
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
                    Equate
                >,
                IntersectSelections< 
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
                    Equate
                >,
                UniteSelections< 
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
                    Equate
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
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< DoublyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
            DoubleSection = {
                ComplementSelections< 
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
                    Equate
                >,
                DifferentiateSelections< 
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
                    Equate
                >,
                IntersectSelections< 
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
                    Equate
                >,
                UniteSelections< 
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
                    Equate
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
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< SinglyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
            SafeSingleSection = {
                ComplementSelections< 
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
                    Equate
                >,
                DifferentiateSelections< 
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
                    Equate
                >,
                IntersectSelections< 
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
                    Equate
                >,
                UniteSelections< 
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
                    Equate
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
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< DoublyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
            SafeDoubleSection = {
                ComplementSelections< 
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
                    Equate
                >,
                DifferentiateSelections< 
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
                    Equate
                >,
                IntersectSelections< 
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
                    Equate
                >,
                UniteSelections< 
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
                    Equate
                >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
            SingleSelector = {
                SingleComposer< Natural, Elemental, Equate, Adjunct >,
                SingleSection< 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Equate,
                    Adjunct
                >,
                DuplicateSelection< 
                    SinglyLinked< Elemental >, 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct > 
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
                Account< SinglyLinked< Elemental >,  Natural, Elemental >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
            DoubleSelector = {
                DoubleComposer< Natural, Elemental, Equate, Adjunct >,
                DoubleSection< 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Equate,
                    Adjunct
                >,
                DuplicateSelection< 
                    DoublyLinked< Elemental >, 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct > 
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
                Account< DoublyLinked< Elemental >,  Natural, Elemental >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
            SafeSingleSelector = {
                SafeSingleComposer< Natural, Elemental, Equate, Adjunct >,
                SafeSingleSection< 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Equate,
                    Adjunct
                >,
                DuplicateSelection< 
                    SinglyLinked< Elemental >, 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct > 
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
                Account< SinglyLinked< Elemental >,  Natural, Elemental >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
            SafeDoubleSelector = {
                SafeDoubleComposer< Natural, Elemental, Equate, Adjunct >,
                SafeDoubleSection< 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Equate,
                    Adjunct 
                >,
                DuplicateSelection< 
                    DoublyLinked< Elemental >, 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct > 
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
                Account< DoublyLinked< Elemental >,  Natural, Elemental >
            };


    }

}

#endif
