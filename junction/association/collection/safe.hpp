// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_ASSOCIATION_COLLECTION_MODULE
#define SAFE_JUNCTION_ASSOCIATION_COLLECTION_MODULE
#include "../../consecution/safe.hpp"
#include "../collection.hpp"

namespace junction {

namespace association {

namespace collection {

using ::junction::consecution::CedeSafely;
using ::junction::consecution::ConcedeSafely;
using ::junction::consecution::PrecedeSafely;

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order,
    Referential<const Scalar<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Correlative>> Scale,
    Referential<const AssociativelySingleAdjunctive<Natural, Correlative, Evaluative>> Adjunct>
static inline bool
ReassociateSafely(
    Referential<AssociativelySingleJunctive<Natural, Correlative, Evaluative>>
        map,
    Referential<const Correlative>
        original,
    Referential<const Correlative>
        replacement)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using MapPositional = AssociativelySinglePositional<Correlative, Evaluative>;
    using NodeLocational = Locational<AssociativelySingleNodal<Correlative, Evaluative>>;
    MapPositional original_position, replacement_position, previous;
    NodeLocational result;
    Natural extent;
    if (!map.first)
        return false;
    extent = Account(map) - 1;
    Scale.begin(map, original_position, 0);
    if (!SearchScalarBisection(map, Scale, original, original_position, extent, Equate, Order))
        return false;
    Scale.begin(map, replacement_position, 0);
    if (SearchScalarBisection(map, Scale, replacement, replacement_position, extent, Equate, Order))
        return false;
    if (original_position.at != map.first) {
        Scale.begin(map, previous, 0);
        if (!previous.at)
            throw map;
        while (GetNext(previous.at) != original_position) {
            previous.at = GetNext(previous.at);
            if (!previous.at)
                throw map;
        }
        result = Adjunct.proclaim(map, replacement);
        if (!result)
            return false;
        SetNext(previous.at, GetNext(original_position.at));
        if (!GetNext(previous.at))
            map.last = previous.at;
    } else {
        result = Adjunct.proclaim(map, replacement);
        if (!result)
            return false;
        map.first = GetNext(original_position.at);
    }
    SetNext(original_position.at, map.unused);
    map.unused = original_position.at;
    if (Order(Scale.go(map, replacement_position).to, replacement)) {
        SetNext(result, GetNext(replacement_position.at));
        SetNext(replacement_position.at, result);
        if (!GetNext(result))
            map.last = result;
    } else {
        if (replacement_position != map.first) {
            Scale.begin(map, previous, 0);
            if (!previous.at) {
                SetNext(result, map.unused);
                map.unused = result;
                throw map;
            }
            while (GetNext(previous.at) != replacement_position) {
                previous.at = GetNext(previous.at);
                if (!previous.at) {
                    SetNext(result, map.unused);
                    map.unused = result;
                    throw map;
                }
            }
            SetNext(previous.at, result);
        } else {
            map.first = result;
        }
        SetNext(result, replacement_position.at);
    }
    return true;
}

// This function template throws an exception if the relator (key)
// does not exist in the map.
template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order,
    Referential<const Scalar<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Correlative>> Scale>
static inline Conferential<const Evaluative>
RelateReadElement(
    Referential<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>>
        map,
    Referential<const Correlative>
        relator)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using MapPositional = AssociativelySinglePositional<Correlative, Evaluative>;
    MapPositional position;
    if (!map.first)
        throw relator;
    Scale.begin(map, position, 0);
    if (!SearchScalarBisection(map, Scale, relator, position, Account(map) - 1, Equate, Order))
        throw relator;
    return GoReadElement(map, position);
}

// This function template throws an exception if the relator (key)
// does not exist in the map.
template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order,
    Referential<const Lineal<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>> Liner>
static inline Conferential<const Evaluative>
RelateReadElement(
    Referential<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>>
        map,
    Referential<const Correlative>
        relator)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using MapPositional = AssociativelyDoublePositional<Correlative, Evaluative>;
    static const Natural Before = 0;
    MapPositional position;
    if (!map.first)
        throw relator;
    Liner.increment.begin(map, position, 0);
    if (!SearchBisection(map, Liner, relator, position, Before, Account(map) - 1, Equate, Order))
        throw relator;
    return GoReadElement(map, position);
}

// This function template throws an exception if the relator (key)
// does not exist in the map.
template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order,
    Referential<const Scalar<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Correlative>> Scale>
static inline Conferential<Evaluative>
RelateWriteElement(
    Referential<AssociativelySingleJunctive<Natural, Correlative, Evaluative>>
        map,
    Referential<const Correlative>
        relator)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using MapPositional = AssociativelySinglePositional<Correlative, Evaluative>;
    MapPositional position;
    if (!map.first)
        throw relator;
    Scale.begin(map, position, 0);
    if (!SearchScalarBisection(map, Scale, relator, position, Account(map) - 1, Equate, Order))
        throw relator;
    return GoWriteElement(map, position);
}

// This function template throws an exception if the relator (key)
// does not exist in the map.
template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order,
    Referential<const Lineal<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>> Liner>
static inline Conferential<Evaluative>
RelateWriteElement(
    Referential<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>>
        map,
    Referential<const Correlative>
        relator)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using MapPositional = AssociativelyDoublePositional<Correlative, Evaluative>;
    static const Natural Before = 0;
    MapPositional position;
    if (!map.first)
        throw relator;
    Liner.increment.begin(map, position, 0);
    if (!SearchBisection(map, Liner, relator, position, Before, Account(map) - 1, Equate, Order))
        throw relator;
    return GoWriteElement(map, position);
}

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order>
constexpr Vectorial<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, Correlative, const Evaluative>
    RelateReadSingleVector = {
        Correspond<Natural, Correlative, Evaluative, Equate, Order, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
        RelateReadElement<Natural, Correlative, Evaluative, Equate, Order, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order>
constexpr Vectorial<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, Correlative, const Evaluative>
    RelateReadDoubleVector = {
        Correspond<Natural, Correlative, Evaluative, Equate, Order, ReadRelatorDoubleLiner<Natural, Correlative, Evaluative>>,
        RelateReadElement<Natural, Correlative, Evaluative, Equate, Order, ReadRelatorDoubleLiner<Natural, Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order>
constexpr Vectorial<AssociativelySingleJunctive<Natural, Correlative, Evaluative>, Correlative, Evaluative>
    RelateWriteSingleVector = {
        Correspond<Natural, Correlative, Evaluative, Equate, Order, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
        RelateWriteElement<Natural, Correlative, Evaluative, Equate, Order, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>>
        Equate,
    Referential<Assortive<Correlative>>
        Order>
constexpr Vectorial<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, Correlative, Evaluative>
    RelateWriteDoubleVector = {
        Correspond<Natural, Correlative, Evaluative, Equate, Order, ReadRelatorDoubleLiner<Natural, Correlative, Evaluative>>,
        RelateWriteElement<Natural, Correlative, Evaluative, Equate, Order, ReadRelatorDoubleLiner<Natural, Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order,
    Referential<const AssociativelySingleAdjunctive<Natural, Correlative, Evaluative>> Adjunct>
constexpr Associative<AssociativelySingleJunctive<Natural, Correlative, Evaluative>, Natural, Correlative, Evaluative>
    SafeSingleAssociator = {
        Instantiate<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, Adjunct>,
        Account<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
        Correspond<Natural, Correlative, Evaluative, Equate, Order, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
        Associate<Natural, Correlative, Evaluative, PrecedeSafely<Natural, Complementary<Correlative, Evaluative>, Adjunct>, CedeSafely<Natural, Complementary<Correlative, Evaluative>, Adjunct>, Proceed<Natural, Complementary<Correlative, Evaluative>, Adjunct>, Equate, Order, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
        ReassociateSafely<Natural, Correlative, Evaluative, Equate, Order, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>, Adjunct>,
        Disassociate<Natural, Correlative, Evaluative, ConcedeSafely<Natural, Complementary<Correlative, Evaluative>>, Equate, Order, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
        RemoveAll<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
        DeleteOneNode<Natural, Complementary<Correlative, Evaluative>, Adjunct>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<Assortive<Correlative>> Order,
    Referential<const AssociativelyDoubleAdjunctive<Natural, Correlative, Evaluative>> Adjunct>
constexpr Associative<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, Natural, Correlative, Evaluative>
    SafeDoubleAssociator = {
        Instantiate<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, Adjunct>,
        Account<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
        Correspond<Natural, Correlative, Evaluative, Equate, Order, SafeReadRelatorDoubleLiner<Natural, Correlative, Evaluative>>,
        Associate<Natural, Correlative, Evaluative, PrecedeSafely<Natural, Complementary<Correlative, Evaluative>, Adjunct>, CedeSafely<Natural, Complementary<Correlative, Evaluative>, Adjunct>, Proceed<Natural, Complementary<Correlative, Evaluative>, Adjunct>, Equate, Order, SafeReadRelatorDoubleLiner<Natural, Correlative, Evaluative>>,
        Reassociate<Natural, Correlative, Evaluative, Equate, Order, SafeReadRelatorDoubleLiner<Natural, Correlative, Evaluative>, Adjunct>,
        Disassociate<Natural, Correlative, Evaluative, ConcedeSafely<Natural, Complementary<Correlative, Evaluative>>, Equate, Order, SafeReadRelatorDoubleLiner<Natural, Correlative, Evaluative>>,
        RemoveAll<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
        DeleteOneNode<Natural, Complementary<Correlative, Evaluative>, Adjunct>
    };

}

}

}

#endif
