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
                Referential< const Natural >,
                Referential< const Correlative >,
                Referential< AssociativelyPositional< Correlative, Elemental > >
            ) >
            SearchAssociation = SearchBisectionally< AssociativelyJunctive<  Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorAxis< Natural, Correlative, Elemental >, Equate, Order >;

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
					Search = SearchBisectionally< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorAxis< Natural, Correlative, Elemental >, Equate, Order >;
#endif
                AssociativelyPositional< Correlative, Elemental >
                    position;
                return Search( map, map.count, relator, position );
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
					Search = SearchBisectionally< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorAxis< Natural, Correlative, Elemental >, Equate, Order >;
#endif
				const Associational< Correlative, Elemental >
                    associate = {relator, value};
                AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map ))
                    return Proceed( map, associate );
                else if (Search( map, map.count, relator, position ))
                    return false;
                if (Order( GoReadRelator( map, position ).to, relator )) {
                    if (IncrementTraversable( map, position )) {
                        TraverseWriteIncrement( map, position );
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
                static const Natural
                    One = 1;
                static auto&
                    Scale = ReadRelatorDecrementScale< Natural, Correlative, Elemental >;
                static auto&
#ifndef _MSC_VER
					Search = SearchAssociation< Natural, Correlative, Elemental, Equate, Order >;
#else
                    // Problem 286153 filed July 3 2018
					Search = SearchBisectionally< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorAxis< Natural, Correlative, Elemental >, Equate, Order >;
#endif
				static auto&
                    CorrespondInMap = Correspond< Natural, Correlative, Elemental, Equate, Order >;
                AssociativelyPositional< Correlative, Elemental >
                    position, last;
                if (CorrespondInMap( map, replacement ))
                    return false;
                if (Search( map, map.count, original, position )) {
                    const Associational< Correlative, Elemental >
                        associate = {replacement, GoWrite( map, position ).to.value};
                    if (!Concede( map, position, One ))
                        return false;
                    if (Search( map, map.count, replacement, position ))
                        return false;
                    if (!DecrementBegins( map ) || Order( Scale.go( map, Scale.begin( map, last ) ).to, replacement ))
                        return Proceed( map, associate );
                    return Precede( map, position, associate );
                }
                return false;
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
                static const Natural
                    One = 1;
                static auto&
#ifndef _MSC_VER
					Search = SearchAssociation< Natural, Correlative, Elemental, Equate, Order >;
#else
                    // Problem 286153 filed July 3 2018
					Search = SearchBisectionally< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorAxis< Natural, Correlative, Elemental >, Equate, Order >;
#endif
				AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!Search( map, map.count, relator, position ))
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
					Search = SearchBisectionally< AssociativelyJunctive<  Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorAxis< Natural, Correlative, Elemental >, Equate, Order >;
#endif
				AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!Search( map, map.count, relator, position ))
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
					Search = SearchBisectionally< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorAxis< Natural, Correlative, Elemental >, Equate, Order >;
#endif
				AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!Search( map, map.count, relator, position ))
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
