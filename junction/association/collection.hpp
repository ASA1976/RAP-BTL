// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_ASSOCIATION_COLLECTION_MODULE
#define JUNCTION_ASSOCIATION_COLLECTION_MODULE
#include "../association.hpp"

namespace junction {

    namespace association {

        namespace collection {

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            Referential< bool(
                Referential< const AssociativelyJunctive< Natural, Correlative, Elemental > >,
                Referential< const Correlative >,
                Referential< AssociativelyPositional< Correlative, Elemental > >,
                Natural,
                Natural
            ) >
            SearchAssociation = SearchBisectionally< AssociativelyJunctive<  Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorLiner< Natural, Correlative, Elemental >, Equate, Order >;

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            static inline bool
            Correspond(
                Referential< const AssociativelyJunctive< Natural, Correlative, Elemental > >
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
#ifndef _MSC_VER
					Search = SearchAssociation< Natural, Correlative, Elemental, Equate, Order >;
#else
                    // Problem 286153 filed July 3 2018
					Search = SearchBisectionally< AssociativelyJunctive<  Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorLiner< Natural, Correlative, Elemental >, Equate, Order >;
#endif
                static const Natural
                    Zero = 0;
                AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map, Zero ))
                    return false;
                BeginReadIncrement( map, position, Zero );
                return Search( map, relator, position, Zero, Account( map ) - 1 );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Precedent< Natural, Associational< Correlative, Elemental > > >
                    Precede,
                Referential< Consequent< Natural, Associational< Correlative, Elemental > > >
                    Proceed,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            static inline bool
            Associate(
                Referential< AssociativelyJunctive< Natural, Correlative, Elemental > >
                    map,
                Referential< const Correlative >
                    relator,
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
					Search = SearchAssociation< Natural, Correlative, Elemental, Equate, Order >;
#else
                    // Problem 286153 filed July 3 2018
                    Search = SearchBisectionally< AssociativelyJunctive<  Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorLiner< Natural, Correlative, Elemental >, Equate, Order >;
#endif
                static const Natural
                    Zero = 0,
                    One = 1;
				const Associational< Correlative, Elemental >
                    associate = {relator, value};
                AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map, Zero ))
                    return Proceed( map, associate );
                BeginWriteIncrement( map, position, Zero );
                if (Search( map, relator, position, Zero, Account( map ) - 1 ))
                    return false;
                if (Order( GoReadRelator( map, position ).to, relator )) {
                    if (IncrementTraversable( map, position, One )) {
                        TraverseWriteIncrement( map, position, One );
                        return Precede( map, position, associate );
                    } else {
                        return Proceed( map, associate );
                    }
                }
                return Precede( map, position, associate );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Precedent< Natural, Associational< Correlative, Elemental > > >
                    Precede,
                Referential< Consequent< Natural, Associational< Correlative, Elemental > > >
                    Proceed,
                Referential< Concessive< Natural, Associational< Correlative, Elemental > > >
                    Concede,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            static inline bool
            Reassociate(
                Referential< AssociativelyJunctive< Natural, Correlative, Elemental > >
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
#ifndef _MSC_VER
					Search = SearchAssociation< Natural, Correlative, Elemental, Equate, Order >;
#else
                    // Problem 286153 filed July 3 2018
                    Search = SearchBisectionally< AssociativelyJunctive<  Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorLiner< Natural, Correlative, Elemental >, Equate, Order >;
#endif
                static auto&
                    CorrespondInMap = Correspond< Natural, Correlative, Elemental, Equate, Order >;
                static const Natural
                    Zero = 0,
                    One = 1;
                AssociativelyPositional< Correlative, Elemental >
                    original_position,
                    replacement_position;
                Natural
                    last;
                if (!IncrementBegins( map, Zero ))
                    return false;
                BeginWriteIncrement( map, original_position, Zero );
                BeginWriteIncrement( map, replacement_position, Zero );
                last = Account( map ) - 1;
                if (!Search( map, original, original_position, Zero, last ))
                    return false;
                if (Search( map, replacement, replacement_position, Zero, last ))
                    return false;
                if (Order( GoReadRelator( map, replacement_position ).to, replacement )) {
                    const Associational< Correlative, Elemental >
                        associate = {replacement, GoWriteElement( map, original_position ).to};
                    if (IncrementTraversable( map, replacement_position, One )) {
                        TraverseWriteIncrement( map, replacement_position, One );
                        if (!Precede( map, replacement_position, associate ))
                            return false;
                    } else if (!Precede( map, replacement_position, associate )) {
                        return false;
                    }
                }
                return Concede( map, original_position, One );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Concessive< Natural, Associational< Correlative, Elemental > > >
                    Concede,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            static inline bool
            Disassociate(
                Referential< AssociativelyJunctive< Natural, Correlative, Elemental > >
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
#ifndef _MSC_VER
					Search = SearchAssociation< Natural, Correlative, Elemental, Equate, Order >;
#else
                    // Problem 286153 filed July 3 2018
                    Search = SearchBisectionally< AssociativelyJunctive<  Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorLiner< Natural, Correlative, Elemental >, Equate, Order >;
#endif
                static const Natural
                    Zero = 0,
                    One = 1;
                AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map, Zero ))
                    return false;
                BeginWriteIncrement( map, position, Zero );
                if (!Search( map, relator, position, Zero, Account( map ) - 1 ))
                    return false;
                return Concede( map, position, One );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            static inline Conferential< const Elemental >
            RelateReadElement(
                Referential< const AssociativelyJunctive< Natural, Correlative, Elemental > >
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
#ifndef _MSC_VER
					Search = SearchAssociation< Natural, Correlative, Elemental, Equate, Order >;
#else
                    Search = SearchBisectionally< AssociativelyJunctive<  Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorLiner< Natural, Correlative, Elemental >, Equate, Order >;
#endif
                static const Natural
                    Zero = 0;
				AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map, Zero ))
                    throw relator;
                BeginReadIncrement( map, position, Zero );
                if (!Search( map, relator, position, Zero, Account( map ) - 1 ))
                    throw relator;
                return GoReadElement( map, position ).to;
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            static inline Conferential< Elemental >
            RelateWriteElement(
                Referential< AssociativelyJunctive< Natural, Correlative, Elemental > >
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
#ifndef _MSC_VER
					Search = SearchAssociation< Natural, Correlative, Elemental, Equate, Order >;
#else
                    // Problem 286153 filed July 3 2018
                    Search = SearchBisectionally< AssociativelyJunctive<  Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorLiner< Natural, Correlative, Elemental >, Equate, Order >;
#endif
                static const Natural
                    Zero = 0;
				AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map, Zero ))
                    throw relator;
                BeginWriteIncrement( map, position, Zero );
                if (!Search( map, relator, position, Zero, Account( map ) - 1 ))
                    throw relator;
                return GoWriteElement( map, position );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            constexpr Vectorial< const AssociativelyJunctive< Natural, Correlative, Elemental >, Correlative, const Elemental >
            RelateReadVector = {
                Correspond< Natural, Correlative, Elemental, Equate, Order >,
                RelateReadElement< Natural, Correlative, Elemental, Equate, Order >
            };

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            constexpr Vectorial< AssociativelyJunctive< Natural, Correlative, Elemental >, Correlative, Elemental >
            RelateWriteVector = {
                Correspond< Natural, Correlative, Elemental, Equate, Order >,
                RelateWriteElement< Natural, Correlative, Elemental, Equate, Order >
            };

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< const Adjunctive< Natural, Associational< Correlative, Elemental > > >
                    Adjunct,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            constexpr Associative< AssociativelyJunctive< Natural, Correlative, Elemental >, Natural, Correlative, Elemental >
            JunctionAssociator = {
                Instantiate< Natural, Associational< Correlative, Elemental >, Adjunct >,
                Account< Natural, Associational< Correlative, Elemental > >,
                Correspond< Natural, Correlative, Elemental, Equate, Order >,
                Associate< Natural, Correlative, Elemental, Precede< Natural, Associational< Correlative, Elemental >, Adjunct >, Proceed< Natural, Associational< Correlative, Elemental >, Adjunct >, Equate, Order >,
                Reassociate< Natural, Correlative, Elemental, Precede< Natural, Associational< Correlative, Elemental >, Adjunct >, Proceed< Natural, Associational< Correlative, Elemental >, Adjunct >, Concede, Equate, Order >,
                Disassociate< Natural, Correlative, Elemental, Concede, Equate, Order >,
                Empty< Natural, Associational< Correlative, Elemental > >,
                Free< Natural, Associational< Correlative, Elemental >, Adjunct >
            };

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< const Adjunctive< Natural, Associational< Correlative, Elemental > > >
                    Adjunct,
                Referential< Assortive< Correlative > >
                    Equate,
                Referential< Assortive< Correlative > >
                    Order
            >
            constexpr Associative< AssociativelyJunctive< Natural, Correlative, Elemental >, Natural, Correlative, Elemental >
            SafeJunctionAssociator = {
                Instantiate< Natural, Associational< Correlative, Elemental >, Adjunct >,
                Account< Natural, Associational< Correlative, Elemental > >,
                Correspond< Natural, Correlative, Elemental, Equate, Order >,
                Associate< Natural, Correlative, Elemental, PrecedeSafely< Natural, Associational< Correlative, Elemental >, Adjunct >, Proceed< Natural, Associational< Correlative, Elemental >, Adjunct >, Equate, Order >,
                Reassociate< Natural, Correlative, Elemental, PrecedeSafely< Natural, Associational< Correlative, Elemental >, Adjunct >, Proceed< Natural, Associational< Correlative, Elemental >, Adjunct >, ConcedeSafely, Equate, Order >,
                Disassociate< Natural, Correlative, Elemental, ConcedeSafely, Equate, Order >,
                Empty< Natural, Associational< Correlative, Elemental > >,
                Free< Natural, Associational< Correlative, Elemental >, Adjunct >
            };

        }

    }

}

#endif
