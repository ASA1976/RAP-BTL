// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_ASSOCIATION_COLLECTION_MODULE
#define JUNCTION_ASSOCIATION_COLLECTION_MODULE
#include "../association.hpp"
#include "../consecution.hpp"
#include "../../sortation.hpp"

namespace junction {

    namespace association {

        /**
         * @brief         
         *     Linked list sorted map management implementation.
         * @details       
         *     Association
         *     -----------
         *     Linked list sorted map management implementation.
         */
        namespace collection {

            using ::sortation::Assortive;
            using ::sortation::SearchBisection;
            using ::sortation::SearchBisectionIteratively;
            using ::sortation::SearchScalarBisection;
            using ::junction::consecution::Precedent;
            using ::junction::consecution::Consequent;
            using ::junction::consecution::Concessive;
            using ::junction::consecution::Precede;
            using ::junction::consecution::Cede;
            using ::junction::consecution::Proceed;
            using ::junction::consecution::Concede;

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Correlative > >
                    Scale
            >
            static inline bool
            Correspond(
                Referential< const AssociativelySingleJunctive< Natural, Correlative, Evaluative > >
                    map,
                Referential< const Correlative >
                    relator
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                static auto&
					Search = SearchScalarBisection< 
                        AssociativelySingleJunctive< Natural, Correlative, Evaluative >, 
                        AssociativelySinglePositional< Correlative, Evaluative >, 
                        Natural, 
                        Correlative, 
                        Equate,
                        Order,
                        Scale
                    >;
                AssociativelySinglePositional< Correlative, Evaluative >
                    position;
                if (!map.first)
                    return false;
                Scale.begin( map, position, 0 );
                return Search( map, relator, position, Account( map ) - 1 );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const Lineal< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative > >
                    Liner
            >
            static inline bool
            Correspond(
                Referential< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative > >
                    map,
                Referential< const Correlative >
                    relator
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                static auto&
					Search = SearchBisection< 
                        AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, 
                        AssociativelyDoublePositional< Correlative, Evaluative >, 
                        Natural, 
                        Correlative, 
                        Equate,
                        Order,
                        Liner
                    >;
                AssociativelyDoublePositional< Correlative, Evaluative >
                    position;
                if (!map.first)
                    return false;
                Liner.increment.begin( map, position, 0 );
                return Search( map, relator, position, 0, Account( map ) - 1 );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Precedent< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > > >
                    Precede,
                Referential< Precedent< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > > >
                    Cede,
                Referential< Consequent< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > > >
                    Proceed,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Correlative > >
                    Scale
            >
            static inline bool
            Associate(
                Referential< AssociativelySingleJunctive< Natural, Correlative, Evaluative > >
                    map,
                Referential< const Correlative >
                    relator,
                Referential< const Evaluative >
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
					Search = SearchScalarBisection< 
                        AssociativelySingleJunctive< Natural, Correlative, Evaluative >, 
                        AssociativelySinglePositional< Correlative, Evaluative >, 
                        Natural, 
                        Correlative, 
                        Equate,
                        Order,
                        Scale
                    >;
				const Complementary< Correlative, Evaluative >
                    pair = {relator, value};
                AssociativelySinglePositional< Correlative, Evaluative >
                    position;
                if (!map.first)
                    return Proceed( map, pair );
                Scale.begin( map, position, 0 );
                if (Search( map, relator, position, Account( map ) - 1 ))
                    return false;
                if (Order( Scale.go( map, position ).to, relator ))
                    return Cede( map, position, pair );
                return Precede( map, position, pair );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Precedent< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > > >
                    Precede,
                Referential< Precedent< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > > >
                    Cede,
                Referential< Consequent< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > > >
                    Proceed,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const Lineal< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative > >
                    Liner
            >
            static inline bool
            Associate(
                Referential< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative > >
                    map,
                Referential< const Correlative >
                    relator,
                Referential< const Evaluative >
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
					Search = SearchBisection< 
                        AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, 
                        AssociativelyDoublePositional< Correlative, Evaluative >, 
                        Natural, 
                        Correlative, 
                        Equate,
                        Order,
                        Liner
                    >;
				const Complementary< Correlative, Evaluative >
                    pair = {relator, value};
                AssociativelyDoublePositional< Correlative, Evaluative >
                    position;
                if (!map.first)
                    return Proceed( map, pair );
                Liner.increment.begin( map, position, 0 );
                if (Search( map, relator, position, 0, Account( map ) - 1 ))
                    return false;
                if (Order( Liner.increment.go( map, position ).to, relator ))
                    return Cede( map, position, pair );
                return Precede( map, position, pair );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Correlative > >
                    Scale,
                Referential< const AssociativelySingleAdjunctive< Natural, Correlative, Evaluative > >
                    Adjunct
            >
            static inline bool
            Reassociate(
                Referential< AssociativelySingleJunctive< Natural, Correlative, Evaluative > >
                    map,
                Referential< const Correlative >
                    original,
                Referential< const Correlative >
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
					Search = SearchScalarBisection< 
                        AssociativelySingleJunctive< Natural, Correlative, Evaluative >, 
                        AssociativelySinglePositional< Correlative, Evaluative >, 
                        Natural, 
                        Correlative, 
                        Equate,
                        Order,
                        Scale
                    >;
                AssociativelySinglePositional< Correlative, Evaluative >
                    original_position,
                    replacement_position,
                    previous;
                Locational< AssociativelySingleNodal< Correlative, Evaluative > >
                    result;
                Natural
                    extent;
                if (!map.first)
                    return false;
                extent = Account( map ) - 1;
                Scale.begin( map, original_position, 0 );
                if (!Search( map, original, original_position, extent ))
                    return false;
                Scale.begin( map, replacement_position, 0 );
                if (Search( map, replacement, replacement_position, extent ))
                    return false;
                result = Adjunct.proclaim( map, replacement );
                if (!result)
                    return false;
                if (original_position.at != map.first) {
                    Scale.begin( map, previous, 0 );
                    while (GetNext( previous.at ) != original_position)
                        previous.at = GetNext( previous.at );
                    SetNext( previous.at, GetNext( original_position.at ) );
                    if (!GetNext( previous.at ))
                        map.last = previous.at;
                } else {
                    map.first = GetNext( original_position.at );
                }
                SetNext( original_position.at, map.unused );
                map.unused = original_position.at;
                if (Order( Scale.go( map, replacement_position ).to, replacement )) {
                    SetNext( result, GetNext( replacement_position.at ) );
                    SetNext( replacement_position.at, result );
                    if (!GetNext( result ))
                        map.last = result;
                } else {
                    if (replacement_position != map.first) {
                        Scale.begin( map, previous, 0 );
                        while (GetNext( previous.at ) != replacement_position)
                            previous.at = GetNext( previous.at );
                        SetNext( previous.at, result );
                    } else {
                        map.first = result;
                    }
                    SetNext( result, replacement_position.at );
                }
                return true;
            }

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const Lineal< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative > >
                    Liner,
                Referential< const AssociativelyDoubleAdjunctive< Natural, Correlative, Evaluative > >
                    Adjunct
            >
            static inline bool
            Reassociate(
                Referential< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative > >
                    map,
                Referential< const Correlative >
                    original,
                Referential< const Correlative >
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
					Search = SearchBisection< 
                        AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, 
                        AssociativelyDoublePositional< Correlative, Evaluative >, 
                        Natural, 
                        Correlative, 
                        Equate,
                        Order,
                        Liner
                    >;
                AssociativelyDoublePositional< Correlative, Evaluative >
                    original_position,
                    replacement_position;
                Locational< AssociativelyDoubleNodal< Correlative, Evaluative > >
                    result;
                Natural
                    extent;
                if (!map.first)
                    return false;
                Liner.increment.begin( map, original_position, 0 );
                Liner.increment.begin( map, replacement_position, 0 );
                extent = Account( map ) - 1;
                if (!Search( map, original, original_position, 0, extent ))
                    return false;
                if (Search( map, replacement, replacement_position, 0, extent ))
                    return false;
                const Complementary< Correlative, Evaluative >
                    pair = {replacement, original_position.at->element.value};
                result = Adjunct.proclaim( map, pair );
                if (!result)
                    return false;
                if (GetPrevious( original_position.at ))
                    SetNext( GetPrevious( original_position.at ), GetNext( original_position.at ) );
                else
                    map.first = GetNext( original_position.at );
                if (GetNext( original_position.at ))
                    SetPrevious( GetNext( original_position.at ), GetPrevious( original_position.at ) );
                else
                    map.last = GetPrevious( original_position.at );
                UnsetPrevious( original_position.at );
                SetNext( original_position.at, map.unused );
                if (map.unused)
                    SetPrevious( map.unused, original_position.at );
                map.unused = original_position.at;
                if (Order( Liner.increment.go( map, replacement_position ).to, replacement )) {
                    SetNext( result, GetNext( replacement_position.at ) );
                    SetPrevious( result, replacement_position.at );
                    if (GetNext( result ))
                        SetPrevious( GetNext( result ), result );
                    else
                        map.last = result;
                    SetNext( replacement_position.at, result );
                } else {
                    SetNext( result, replacement_position.at );
                    SetPrevious( result, GetPrevious( replacement_position.at ) );
                    if (GetPrevious( result ))
                        SetNext( GetPrevious( result ), result );
                    else
                        map.first = result;
                    SetPrevious( replacement_position.at, result );
                }
                return true;
            }

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Concessive< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > > >
                    Concede,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Correlative > >
                    Scale
            >
            static inline bool
            Disassociate(
                Referential< AssociativelySingleJunctive< Natural, Correlative, Evaluative > >
                    map,
                Referential< const Correlative >
                    relator
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                static auto&
					Search = SearchScalarBisection< 
                        AssociativelySingleJunctive< Natural, Correlative, Evaluative >, 
                        AssociativelySinglePositional< Correlative, Evaluative >, 
                        Natural, 
                        Correlative, 
                        Equate,
                        Order,
                        Scale
                    >;
                AssociativelySinglePositional< Correlative, Evaluative >
                    position;
                if (!map.first)
                    return false;
                Scale.begin( map, position, 0 );
                if (!Search( map, relator, position, Account( map ) - 1 ))
                    return false;
                return Concede( map, position, 1 );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Concessive< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > > >
                    Concede,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const Lineal< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative > >
                    Liner
            >
            static inline bool
            Disassociate(
                Referential< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative > >
                    map,
                Referential< const Correlative >
                    relator
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                static auto&
					Search = SearchBisection< 
                        AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, 
                        AssociativelyDoublePositional< Correlative, Evaluative >, 
                        Natural, 
                        Correlative, 
                        Equate,
                        Order,
                        Liner
                    >;
                AssociativelyDoublePositional< Correlative, Evaluative >
                    position;
                if (!map.first)
                    return false;
                Liner.increment.begin( map, position, 0 );
                if (!Search( map, relator, position, 0, Account( map ) - 1 ))
                    return false;
                return Concede( map, position, 1 );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const AssociativelySingleAdjunctive< Natural, Correlative, Evaluative > >
                    Adjunct
            >
            constexpr Associative< AssociativelySingleJunctive< Natural, Correlative, Evaluative >, Natural, Correlative, Evaluative >
                SingleAssociator = {
                    Instantiate< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, Adjunct >,
                    Account< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >,
                    Correspond< Natural, Correlative, Evaluative, Equate, Order, ReadRelatorIncrementSingleScale< Natural, Correlative, Evaluative > >,
                    Associate< Natural, Correlative, Evaluative, Precede< Natural, Complementary< Correlative, Evaluative >, Adjunct >, Cede< Natural, Complementary< Correlative, Evaluative >, Adjunct >, Proceed< Natural, Complementary< Correlative, Evaluative >, Adjunct >, Equate, Order, ReadRelatorIncrementSingleScale< Natural, Correlative, Evaluative > >,
                    Reassociate< Natural, Correlative, Evaluative, Equate, Order, ReadRelatorIncrementSingleScale< Natural, Correlative, Evaluative >, Adjunct >,
                    Disassociate< Natural, Correlative, Evaluative, Concede< Natural, Complementary< Correlative, Evaluative > >, Equate, Order, ReadRelatorIncrementSingleScale< Natural, Correlative, Evaluative > >,
                    RemoveAll< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >,
                    DeleteOneNode< Natural, Complementary< Correlative, Evaluative >, Adjunct >
                };

            template <
                typename Natural,
                typename Correlative,
                typename Evaluative,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order,
                Referential< const AssociativelyDoubleAdjunctive< Natural, Correlative, Evaluative > >
                    Adjunct
            >
            constexpr Associative< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, Natural, Correlative, Evaluative >
                DoubleAssociator = {
                    Instantiate< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, Adjunct >,
                    Account< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >,
                    Correspond< Natural, Correlative, Evaluative, Equate, Order, ReadRelatorDoubleLiner< Natural, Correlative, Evaluative > >,
                    Associate< Natural, Correlative, Evaluative, Precede< Natural, Complementary< Correlative, Evaluative >, Adjunct >, Cede< Natural, Complementary< Correlative, Evaluative >, Adjunct >, Proceed< Natural, Complementary< Correlative, Evaluative >, Adjunct >, Equate, Order, ReadRelatorDoubleLiner< Natural, Correlative, Evaluative > >,
                    Reassociate< Natural, Correlative, Evaluative, Equate, Order, ReadRelatorDoubleLiner< Natural, Correlative, Evaluative >, Adjunct >,
                    Disassociate< Natural, Correlative, Evaluative, Concede< Natural, Complementary< Correlative, Evaluative > >, Equate, Order, ReadRelatorDoubleLiner< Natural, Correlative, Evaluative > >,
                    RemoveAll< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >,
                    DeleteOneNode< Natural, Complementary< Correlative, Evaluative >, Adjunct >
                };

        }

    }

}

#endif
