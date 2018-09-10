// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_ASSOCIATION_SELECTION_MODULE
#define JUNCTION_ASSOCIATION_SELECTION_MODULE
#include "../association.hpp"
#include "../consecution.hpp"
#include "../../sortation.hpp"

namespace junction {

    namespace association {

        namespace selection {

            using ::sortation::Assortive;
            using ::sortation::SearchLinearly;
            using ::junction::consecution::Consequent;
            using ::junction::consecution::Concessive;
            using ::junction::consecution::Proceed;
            using ::junction::consecution::Concede;

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate
            >
            Referential< bool(
                Referential< const AssociativelyJunctive< Natural, Correlative, Elemental > >,
                Referential< const Correlative >,
                Referential< AssociativelyPositional< Correlative, Elemental > >,
                Natural
            ) >
            SearchCorrelation = SearchLinearly< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorIncrementScale< Natural, Correlative, Elemental >, Equate >;

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate
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
                    Search = SearchCorrelation< Natural, Correlative, Elemental, Equate >;
#else
                    // Problem 286153 filed July 3 2018
					Search = SearchLinearly< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorIncrementScale< Natural, Correlative, Elemental >, Equate >;
#endif
                static const Natural
                    Zero = 0;
                AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map, Zero ))
                    return false;
                BeginReadIncrement( map, position, Zero );
                return Search( map, relator, position, Account( map ) - 1 );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Consequent< Natural, Associational< Correlative, Elemental > > >
                    Proceed,
                Referential< Assortive< Correlative > >
                    Equate
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
                    CorrespondInMap = Correspond< Natural, Correlative, Elemental, Equate >;
                const Associational< Correlative, Elemental >
                    associate = {relator, value};
                if (CorrespondInMap( map, relator ))
                    return false;
                return Proceed( map, associate );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Consequent< Natural, Associational< Correlative, Elemental > > >
                    Proceed,
                Referential< Concessive< Natural, Associational< Correlative, Elemental > > >
                    Concede,
                Referential< Assortive< Correlative > >
                    Equate
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
					Search = SearchCorrelation< Natural, Correlative, Elemental, Equate >;
#else
                    // Problem 286153 filed July 3 2018
                    Search = SearchLinearly< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorIncrementScale< Natural, Correlative, Elemental >, Equate >;
#endif
                static auto&
                    CorrespondInMap = Correspond< Natural, Correlative, Elemental, Equate >;
                static const Natural
                    Zero = 0,
                    One = 1;
                AssociativelyPositional< Correlative, Elemental >
                    position;
                if (CorrespondInMap( map, replacement ))
                    return false;
                if (!IncrementBegins( map, Zero ))
                    return false;
                BeginWriteIncrement( map, position, Zero );
                if (Search( map, original, position, Account( map ) - 1 )) {
                    const Associational< Correlative, Elemental >
                        associate = {replacement, GoWriteElement( map, position ).to};
                    return Concede( map, position, One ) && Proceed( map, associate );
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
                    Equate
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
					Search = SearchCorrelation< Natural, Correlative, Elemental, Equate >;
#else
                    // Problem 286153 filed July 3 2018
                    Search = SearchLinearly< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorIncrementScale< Natural, Correlative, Elemental >, Equate >;
#endif
				static const Natural
                    Zero = 0,
                    One = 1;
                AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map, Zero ))
                    return false;
                BeginWriteIncrement( map, position, Zero );
                return Search( map, relator, position, Account( map ) - 1 )
                    && Concede( map, position, One );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate
            >
            static inline Conferential< const Elemental >
            RelateReadElement(
                Referential< const AssociativelyJunctive< Natural,  Correlative, Elemental > >
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
					Search = SearchCorrelation< Natural, Correlative, Elemental, Equate >;
#else
                    // Problem 286153 filed July 3 2018
                    Search = SearchLinearly< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorIncrementScale< Natural, Correlative, Elemental >, Equate >;
#endif
                static const Natural
                    Zero = 0;
				AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map, Zero ))
                    throw relator;
                BeginReadIncrement( map, position, Zero );
                if (!Search( map, relator, position, Account( map ) - 1 ))
                    throw relator;
                return GoReadElement( map, position );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate
            >
            static inline Conferential< Elemental >
            RelateWriteElement(
                Referential< AssociativelyJunctive< Natural,  Correlative, Elemental > >
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
					Search = SearchCorrelation< Natural, Correlative, Elemental, Equate >;
#else
                    // Problem 286153 filed July 3 2018
                    Search = SearchLinearly< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Correlative, ReadRelatorIncrementScale< Natural, Correlative, Elemental >, Equate >;
#endif
                static const Natural
                    Zero = 0;
				AssociativelyPositional< Correlative, Elemental >
                    position;
                if (!IncrementBegins( map, Zero ))
                    throw relator;
                BeginWriteIncrement( map, position, Zero );
                if (!Search( map, relator, position, Account( map ) - 1 ))
                    throw relator;
                return GoWriteElement( map, position );
            }

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate
            >
            constexpr Vectorial< const AssociativelyJunctive< Natural, Correlative, Elemental >, Correlative, const Elemental >
            RelateReadVector = {
                Correspond< Natural, Correlative, Elemental, Equate >,
                RelateReadElement< Natural, Correlative, Elemental, Equate >
            };

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< Assortive< Correlative > >
                    Equate
            >
            constexpr Vectorial< AssociativelyJunctive< Natural, Correlative, Elemental >, Correlative, Elemental >
            RelateWriteVector = {
                Correspond< Natural, Correlative, Elemental, Equate >,
                RelateWriteElement< Natural, Correlative, Elemental, Equate >
            };

            template <
                typename Natural,
                typename Correlative,
                typename Elemental,
                Referential< const Adjunctive< Natural, Associational< Correlative, Elemental > > >
                    Adjunct,
                Referential< Assortive< Correlative > >
                    Equate
            >
            constexpr Associative< AssociativelyJunctive< Natural, Correlative, Elemental >, Natural, Correlative, Elemental >
            JunctionCorrelator = {
                Instantiate< Natural, Associational< Correlative, Elemental >, Adjunct >,
                Account< Natural, Associational< Correlative, Elemental > >,
                Correspond< Natural, Correlative, Elemental, Equate >,
                Associate< Natural, Correlative, Elemental, Proceed< Natural, Associational< Correlative, Elemental >, Adjunct >, Equate >,
                Reassociate< Natural, Correlative, Elemental, Proceed< Natural, Associational< Correlative, Elemental >, Adjunct >, Concede, Equate >,
                Disassociate< Natural, Correlative, Elemental, Concede, Equate >,
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
                    Equate
            >
            constexpr Associative< AssociativelyJunctive< Natural, Correlative, Elemental >, Natural, Correlative, Elemental >
            SafeJunctionCorrelator = {
                Instantiate< Natural, Associational< Correlative, Elemental >, Adjunct >,
                Correspond< Natural, Correlative, Elemental, Equate >,
                Associate< Natural, Correlative, Elemental, Proceed< Natural, Associational< Correlative, Elemental >, Adjunct >, Equate >,
                Reassociate< Natural, Correlative, Elemental, Proceed< Natural, Associational< Correlative, Elemental >, Adjunct >, Concede, Equate >,
                Disassociate< Natural, Correlative, Elemental, Concede, Equate >,
                Empty< Natural, Associational< Correlative, Elemental > >,
                Free< Natural, Associational< Correlative, Elemental >, Adjunct >
            };

        }

    }

}

#endif
