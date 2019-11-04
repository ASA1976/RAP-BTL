// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_ASSOCIATION_SELECTION_MODULE
#define JUNCTION_ASSOCIATION_SELECTION_MODULE
#include "../../sortation.hpp"
#include "../association.hpp"
#include "../consecution.hpp"

namespace junction {

namespace association {

/**
 * @brief         
 *     Linked list unsorted map management implementation.
 * @details       
 *     Linked list unsorted map management implementation.
 */
namespace selection {

using ::junction::consecution::Concede;
using ::junction::consecution::Concessive;
using ::junction::consecution::Consequent;
using ::junction::consecution::Proceed;
using ::junction::consecution::Recessive;
using ::junction::consecution::Succeed;
using ::sortation::Assortive;
using ::sortation::SearchSection;

template <
    typename Connective,
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<const Scalar<const AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>, AssociativelyPositional<Connective, Correlative, Evaluative>, Natural, const Correlative>> Scale>
static inline bool
Correspond(
    Referential<const AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>>
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
    AssociativelyPositional<Connective, Correlative, Evaluative> position;
    if (!map.first)
        return false;
    Scale.begin(map, position, 0);
    return SearchSection(map, Scale, relator, position, Account(map) - 1, Equate);
}

template <
    typename Connective,
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Consequent<Connective, Natural, Complementary<Correlative, Evaluative>>> Proceed,
    Referential<Assortive<Correlative>> Equate,
    Referential<const Scalar<const AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>, AssociativelyPositional<Connective, Correlative, Evaluative>, Natural, const Correlative>> Scale>
static inline bool
Associate(
    Referential<AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>>
        map,
    Referential<const Correlative>
        relator,
    Referential<const Evaluative>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    static auto& CorrespondInMap = Correspond<Connective, Natural, Correlative, Evaluative, Equate, Scale>;
    const Complementary<Correlative, Evaluative> pair = { relator, value };
    if (CorrespondInMap(map, relator))
        return false;
    return Proceed(map, pair);
}

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<const Scalar<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Correlative>> Scale,
    Referential<const AssociativelySingleAdjunctive<Natural, Correlative, Evaluative>> Adjunct>
static inline bool
Reassociate(
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
    AssociativelySinglePositional<Correlative, Evaluative> position;
    Locational<AssociativelySingleNodal<Correlative, Evaluative>> previous, found, result;
    Natural count;
    if (!map.first)
        return false;
    previous = result = found = 0;
    Scale.begin(map, position, 0);
    for (count = Account(map); count > 0; count--) {
        const auto&
            relator
            = Scale.go(map, position).to;
        if (Equate(relator, replacement))
            return false;
        if (Equate(relator, original))
            found = position.at;
        else if (!found)
            previous = position.at;
        Scale.traverse(map, position, 1);
    }
    if (!found)
        return false;
    const Complementary<Correlative, Evaluative>
        pair = { replacement, found->element.value };
    result = Adjunct.proclaim(map, pair);
    if (!result)
        return false;
    if (previous)
        SetNext(previous, GetNext(found));
    else
        map.first = GetNext(found);
    SetNext(found, map.unused);
    map.unused = found;
    UnsetNext(result);
    if (map.first)
        SetNext(map.last, result);
    else
        map.first = result;
    map.last = result;
    return true;
}

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<const Scalar<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>> Scale,
    Referential<const AssociativelyDoubleAdjunctive<Natural, Correlative, Evaluative>> Adjunct>
static inline bool
Reassociate(
    Referential<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>>
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
    AssociativelyDoublePositional<Correlative, Evaluative> position;
    Locational<AssociativelyDoubleNodal<Correlative, Evaluative>> found, result;
    Natural count;
    if (!map.first)
        return false;
    result = found = 0;
    Scale.begin(map, position, 0);
    for (count = Account(map); count > 0; count--) {
        const auto& relator = Scale.go(map, position).to;
        if (Equate(relator, replacement))
            return false;
        if (Equate(relator, original))
            found = position.at;
        Scale.traverse(map, position, 1);
    }
    if (!found)
        return false;
    const Complementary<Correlative, Evaluative> pair = { replacement, found->element.value };
    result = Adjunct.proclaim(map, pair);
    if (!result)
        return false;
    if (GetPrevious(found))
        SetNext(GetPrevious(found), GetNext(found));
    else
        map.first = GetNext(found);
    if (GetNext(found))
        SetPrevious(GetNext(found), GetPrevious(found));
    else
        map.last = GetPrevious(found);
    UnsetPrevious(found);
    SetNext(found, map.unused);
    if (map.unused)
        SetPrevious(map.unused, found);
    map.unused = found;
    UnsetNext(result);
    SetPrevious(result, map.last);
    if (map.last)
        SetNext(map.last, result);
    else
        map.first = result;
    map.last = result;
    return true;
}

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Recessive<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>> Succeed,
    Referential<Assortive<Correlative>> Equate,
    Referential<const Scalar<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Correlative>> Scale>
static inline bool
Disassociate(
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
    AssociativelySinglePositional<Correlative, Evaluative> position;
    Locational<AssociativelySingleNodal<Correlative, Evaluative>> previous;
    Natural count;
    if (!map.first)
        return false;
    previous = 0;
    Scale.begin(map, position, 0);
    for (count = Account(map); count > 0; count--) {
        if (Equate(Scale.go(map, position).to, relator)) {
            if (!previous)
                return Succeed(map, 1);
            SetNext(previous, GetNext(position.at));
            SetNext(position.at, map.unused);
            if (!GetNext(previous))
                map.last = previous;
            map.unused = position.at;
            map.count--;
            return true;
        }
        previous = position.at;
        Scale.traverse(map, position, 1);
    }
    return false;
}

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Concessive<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>> Concede,
    Referential<Assortive<Correlative>> Equate,
    Referential<const Scalar<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>> Scale>
static inline bool
Disassociate(
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
    AssociativelyDoublePositional<Correlative, Evaluative> position;
    if (!map.first)
        return false;
    Scale.begin(map, position, 0);
    if (!SearchSection(map, Scale, relator, position, Account(map) - 1, Equate))
        return false;
    return Concede(map, position, 1);
}

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<const AssociativelySingleAdjunctive<Natural, Correlative, Evaluative>> Adjunct>
constexpr Associative<AssociativelySingleJunctive<Natural, Correlative, Evaluative>, Natural, Correlative, Evaluative>
    SingleCorrelator = {
        Instantiate<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, Adjunct>,
        Account<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
        Correspond<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
        Associate<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Proceed<Natural, Complementary<Correlative, Evaluative>, Adjunct>, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
        Reassociate<Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>, Adjunct>,
        Disassociate<Natural, Correlative, Evaluative, Succeed<Natural, Complementary<Correlative, Evaluative>>, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
        RemoveAll<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
        DeleteOneNode<Natural, Complementary<Correlative, Evaluative>, Adjunct>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative,
    Referential<Assortive<Correlative>> Equate,
    Referential<const AssociativelyDoubleAdjunctive<Natural, Correlative, Evaluative>> Adjunct>
constexpr Associative<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, Natural, Correlative, Evaluative>
    DoubleCorrelator = {
        Instantiate<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, Adjunct>,
        Account<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
        Correspond<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>,
        Associate<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Proceed<Natural, Complementary<Correlative, Evaluative>, Adjunct>, Equate, ReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>,
        Reassociate<Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>, Adjunct>,
        Disassociate<Natural, Correlative, Evaluative, Concede<Natural, Complementary<Correlative, Evaluative>>, Equate, ReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>,
        RemoveAll<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
        DeleteOneNode<Natural, Complementary<Correlative, Evaluative>, Adjunct>
    };

}

}

}

#endif
