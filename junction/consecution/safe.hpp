// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_CONSECUTION_MODULE
#define SAFE_JUNCTION_CONSECUTION_MODULE
#include "../consecution.hpp"

namespace junction {

namespace consecution {

template <
    typename Natural,
    typename Elemental,
    Referential<const SinglyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
PrecedeSafely(
    Referential<SinglyJunctive<Natural, Elemental>>
        sequence,
    Referential<const SinglyPositional<Elemental>>
        rank,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<SinglyNodal<Elemental>>;
    NodeLocational  result, previous;
    if (!rank.at)
        throw rank;
    previous = sequence.first;
    if (!previous)
        throw rank;
    if (previous == rank.at) {
        result = Adjunct.proclaim(sequence, value);
        if (!result)
            return false;
        sequence.first = result;
    } else {
        while (GetNext(previous) != rank.at) {
            previous = GetNext(previous);
            if (!previous)
                throw rank;
        }
        result = Adjunct.proclaim(sequence, value);
        if (!result)
            return false;
        SetNext(previous, result);
    }
    SetNext(result, rank.at);
    sequence.count++;
    return true;
}

template <
    typename Natural,
    typename Elemental,
    Referential<const DoublyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
PrecedeSafely(
    Referential<DoublyJunctive<Natural, Elemental>>
        sequence,
    Referential<const DoublyPositional<Elemental>>
        rank,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    static auto& CallPrecede = Precede<Natural, Elemental, Adjunct>;
    if (!ContainsCheckSafely(sequence, rank))
        throw rank;
    return CallPrecede(sequence, rank, value);
}

template <
    typename Relative,
    typename Appositional,
    typename RelativeNatural,
    typename Natural,
    typename Elemental,
    Referential<const SinglyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
PrecedeSafely(
    Referential<SinglyJunctive<Natural, Elemental>>
        sequence,
    Referential<const SinglyPositional<Elemental>>
        rank,
    Referential<const Directional<const Relative, Appositional, RelativeNatural, const Elemental>>
        direction,
    Referential<const Relative>
        space,
    Referential<const Appositional>
        from,
    Referential<const Appositional>
        to)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
    static_assert(
        is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
        "RelativeNatural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<SinglyNodal<Elemental>>;
    static auto& SequenceList = Sequence<SinglyLinked<Elemental>, Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, true>;
    NodeLocational first, last, previous;
    Natural length;
    if (!rank.at || !sequence.first)
        throw rank;
    previous = sequence.first;
    if (previous == rank.at) {
        if (!SequenceList(sequence, first, last, length, direction, space, from, to))
            return false;
        sequence.first = first;
    } else {
        while (GetNext(previous) != rank.at) {
            previous = GetNext(previous);
            if (!previous)
                throw rank;
        }
        if (!SequenceList(sequence, first, last, length, direction, space, from, to))
            return false;
        SetNext(previous, first);
    }
    SetNext(last, rank.at);
    sequence.count += length;
    return true;
}

template <
    typename Relative,
    typename Appositional,
    typename RelativeNatural,
    typename Natural,
    typename Elemental,
    Referential<const DoublyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
PrecedeSafely(
    Referential<DoublyJunctive<Natural, Elemental>>
        sequence,
    Referential<const DoublyPositional<Elemental>>
        rank,
    Referential<const Directional<const Relative, Appositional, RelativeNatural, const Elemental>>
        direction,
    Referential<const Relative>
        space,
    Referential<const Appositional>
        from,
    Referential<const Appositional>
        to)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
    static_assert(
        is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
        "RelativeNatural:  Unsigned integer type required");
#endif
    static auto& CallPrecede = Precede<Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct>;
    if (!rank.at || !sequence.first)
        throw rank;
    return CallPrecede(sequence, rank, direction, space, from, to);
}

template <
    typename Natural,
    typename Elemental,
    Referential<const SinglyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
CedeSafely(
    Referential<SinglyJunctive<Natural, Elemental>>
        sequence,
    Referential<const SinglyPositional<Elemental>>
        rank,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    static auto& CallCede = Cede<Natural, Elemental, Adjunct>;
    if (!rank.at)
        throw rank;
    return CallCede(sequence, rank, value);
}

template <
    typename Natural,
    typename Elemental,
    Referential<const DoublyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
CedeSafely(
    Referential<DoublyJunctive<Natural, Elemental>>
        sequence,
    Referential<const DoublyPositional<Elemental>>
        rank,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    static auto& CallCede = Cede<Natural, Elemental, Adjunct>;
    if (!rank.at)
        throw rank;
    return CallCede(sequence, rank, value);
}

template <
    typename Relative,
    typename Appositional,
    typename RelativeNatural,
    typename Natural,
    typename Elemental,
    Referential<const SinglyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
CedeSafely(
    Referential<SinglyJunctive<Natural, Elemental>>
        sequence,
    Referential<const SinglyPositional<Elemental>>
        rank,
    Referential<const Directional<const Relative, Appositional, RelativeNatural, const Elemental>>
        direction,
    Referential<const Relative>
        space,
    Referential<const Appositional>
        from,
    Referential<const Appositional>
        to)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
    static_assert(
        is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
        "RelativeNatural:  Unsigned integer type required");
#endif
    static auto& CallCede = Cede<Relative, Positional, RelativeNatural, Natural, Elemental, Adjunct>;
    if (!rank.at)
        throw rank;
    return CallCede(sequence, rank, direction, space, from, to);
}

template <
    typename Relative,
    typename Appositional,
    typename RelativeNatural,
    typename Natural,
    typename Elemental,
    Referential<const DoublyAdjunctive<Natural, Elemental>> Adjunct>
static inline bool
CedeSafely(
    Referential<DoublyJunctive<Natural, Elemental>>
        sequence,
    Referential<const DoublyPositional<Elemental>>
        rank,
    Referential<const Directional<const Relative, Appositional, RelativeNatural, const Elemental>>
        direction,
    Referential<const Relative>
        space,
    Referential<const Appositional>
        from,
    Referential<const Appositional>
        to)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
    static_assert(
        is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
        "RelativeNatural:  Unsigned integer type required");
#endif
    static auto& CallCede = Cede<Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct>;
    if (!rank.at)
        throw rank;
    return CallCede(sequence, rank, direction, space, from, to);
}

template <
    typename Natural,
    typename Elemental>
static inline bool
SucceedSafely(
    Referential<SinglyJunctive<Natural, Elemental>>
        sequence,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<SinglyNodal<Elemental>>;
    NodeLocational first, last;
    Natural index;
    if (count <= 0)
        return false;
    if (!sequence.first)
        throw count;
    first = last = sequence.first;
    for (index = 1; index < count; index++) {
        last = GetNext(last);
        if (!last)
            throw count;
    }
    sequence.first = GetNext(last);
    if (!sequence.first)
        sequence.last = 0;
    SetNext(last, sequence.unused);
    sequence.unused = first;
    sequence.count -= count;
    return true;
}

template <
    typename Natural,
    typename Elemental>
static inline bool
SucceedSafely(
    Referential<DoublyJunctive<Natural, Elemental>>
        sequence,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<DoublyNodal<Elemental>>;
    NodeLocational first, last;
    Natural index;
    if (count <= 0)
        return false;
    if (!sequence.first)
        throw count;
    first = last = sequence.first;
    for (index = 1; index < count; index++) {
        last = GetNext(last);
        if (!last)
            throw count;
    }
    sequence.first = GetNext(last);
    if (sequence.first)
        UnsetPrevious(sequence.first);
    else
        sequence.last = 0;
    SetNext(last, sequence.unused);
    if (sequence.unused)
        SetPrevious(sequence.unused, last);
    sequence.unused = first;
    sequence.count -= count;
    return true;
}

template <
    typename Natural,
    typename Elemental>
static inline bool
SupersedeSafely(
    Referential<SinglyJunctive<Natural, Elemental>>
        sequence,
    Referential<const SinglyPositional<Elemental>>
        rank,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<SinglyNodal<Elemental>>;
    NodeLocational first, last, previous;
    Natural index;
    if (count <= 0)
        return false;
    if (!rank.at)
        throw rank;
    previous = sequence.first;
    last = previous;
    for (index = 1; index < count; index++) {
        if (!last || last == rank.at)
            throw count;
        last = GetNext(last);
    }
    if (last == rank.at) {
        sequence.first = GetNext(rank.at);
        if (!sequence.first)
            sequence.last = 0;
        SetNext(rank.at, sequence.unused);
        sequence.unused = previous;
    } else {
        while (GetNext(last) != rank.at) {
            previous = GetNext(previous);
            last = GetNext(last);
            if (!last)
                throw rank;
        }
        first = GetNext(previous);
        SetNext(previous, GetNext(rank.at));
        SetNext(rank.at, sequence.unused);
        sequence.unused = first;
    }
    sequence.count -= count;
    return true;
}

template <
    typename Natural,
    typename Elemental>
static inline bool
SupersedeSafely(
    Referential<DoublyJunctive<Natural, Elemental>>
        sequence,
    Referential<const DoublyPositional<Elemental>>
        rank,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<DoublyNodal<Elemental>>;
    NodeLocational first;
    Natural index;
    if (count <= 0)
        return false;
    if (!ContainsCheckSafely(sequence, rank))
        throw rank;
    first = rank.at;
    for (index = 1; index < count; index++) {
        first = GetPrevious(first);
        if (!first)
            throw count;
    }
    if (first == sequence.first) {
        sequence.first = GetNext(rank.at);
    } else {
        SetNext(GetPrevious(first), GetNext(rank.at));
        UnsetPrevious(first);
    }
    if (GetNext(rank.at))
        SetPrevious(GetNext(rank.at), GetPrevious(first));
    else
        sequence.last = GetPrevious(first);
    SetNext(rank.at, sequence.unused);
    if (sequence.unused)
        SetPrevious(sequence.unused, rank.at);
    sequence.unused = first;
    sequence.count -= count;
    return true;
}

template <
    typename Natural,
    typename Elemental>
static inline bool
ConcedeSafely(
    Referential<SinglyJunctive<Natural, Elemental>>
        sequence,
    Referential<const SinglyPositional<Elemental>>
        rank,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<SinglyNodal<Elemental>>;
    NodeLocational last, previous;
    Natural index;
    if (count <= 0)
        return false;
    if (!rank.at)
        throw rank;
    last = rank.at;
    for (index = 1; index < count; index++) {
        last = GetNext(last);
        if (!last)
            throw count;
    }
    if (rank.at == sequence.first) {
        previous = 0;
        sequence.first = GetNext(last);
    } else {
        previous = sequence.first;
        while (GetNext(previous) != rank.at) {
            previous = GetNext(previous);
            if (!previous)
                throw rank;
        }
        SetNext(previous, GetNext(last));
    }
    if (!GetNext(last))
        sequence.last = previous;
    SetNext(last, sequence.unused);
    sequence.unused = rank.at;
    sequence.count -= count;
    return true;
}

template <
    typename Natural,
    typename Elemental>
static inline bool
ConcedeSafely(
    Referential<DoublyJunctive<Natural, Elemental>>
        sequence,
    Referential<const DoublyPositional<Elemental>>
        rank,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<DoublyNodal<Elemental>>;
    NodeLocational last;
    Natural index;
    if (count <= 0)
        return false;
    if (!ContainsCheckSafely(sequence, rank))
        throw rank;
    last = rank.at;
    for (index = 1; index < count; index++) {
        last = GetNext(last);
        if (!last)
            throw count;
    }
    if (GetPrevious(rank.at))
        SetNext(GetPrevious(rank.at), GetNext(last));
    else
        sequence.first = GetNext(last);
    if (GetNext(last))
        SetPrevious(GetNext(last), GetPrevious(rank.at));
    else
        sequence.last = GetPrevious(rank.at);
    SetNext(last, sequence.unused);
    if (sequence.unused)
        SetPrevious(sequence.unused, last);
    sequence.unused = rank.at;
    sequence.count -= count;
    return true;
}

template <
    typename Natural,
    typename Elemental>
static inline bool
RecedeSafely(
    Referential<SinglyJunctive<Natural, Elemental>>
        sequence,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<SinglyNodal<Elemental>>;
    NodeLocational previous;
    Natural index, offset;
    if (count <= 0)
        return false;
    if (!sequence.first)
        throw count;
    if (count == sequence.count)
        return RemoveAll(sequence);
    offset = sequence.count - count;
    previous = sequence.first;
    for (index = 1; index < offset; index++) {
        previous = GetNext(previous);
        if (!previous)
            throw count;
    }
    SetNext(sequence.last, sequence.unused);
    sequence.unused = GetNext(previous);
    UnsetNext(previous);
    sequence.count -= count;
    return true;
}

template <
    typename Natural,
    typename Elemental>
static inline bool
RecedeSafely(
    Referential<DoublyJunctive<Natural, Elemental>>
        sequence,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<SinglyNodal<Elemental>>;
    NodeLocational first, last;
    Natural index;
    if (count <= 0)
        return false;
    if (!sequence.last)
        throw count;
    first = last = sequence.last;
    for (index = 1; index < count; index++) {
        first = GetPrevious(first);
        if (!first)
            throw count;
    }
    sequence.last = GetPrevious(first);
    if (sequence.last) {
        UnsetNext(sequence.last);
        UnsetPrevious(first);
    } else
        sequence.first = 0;
    SetNext(last, sequence.unused);
    if (sequence.unused)
        SetPrevious(sequence.unused, last);
    sequence.unused = first;
    sequence.count -= count;
    return true;
}

template <
    typename Relative,
    typename Appositional,
    typename RelativeNatural,
    typename Natural,
    typename Elemental,
    Referential<const SinglyAdjunctive<Natural, Elemental>> Adjunct>
constexpr Conjoint<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Relative, Appositional, RelativeNatural, Elemental>
    SafeSingleConjoiner = {
        Accede<Relative, Appositional, RelativeNatural, Elemental, Adjunct, true>,
        PrecedeSafely<Relative, Appositional, RelativeNatural, Elemental, Adjunct>,
        CedeSafely<Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct>,
        Proceed<Relative, Appositional, RelativeNatural, Elemental, Adjunct, true>
    };

template <
    typename Relative,
    typename Appositional,
    typename RelativeNatural,
    typename Natural,
    typename Elemental,
    Referential<const DoublyAdjunctive<Natural, Elemental>> Adjunct>
constexpr Conjoint<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Relative, Appositional, RelativeNatural, Elemental>
    SafeDoubleConjoiner = {
        Accede<Relative, Appositional, RelativeNatural, Elemental, Adjunct, true>,
        PrecedeSafely<Relative, Appositional, RelativeNatural, Elemental, Adjunct>,
        CedeSafely<Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct>,
        Proceed<Relative, Appositional, RelativeNatural, Elemental, Adjunct, true>
    };

template <
    typename Natural,
    typename Elemental,
    Referential<const SinglyAdjunctive<Natural, Elemental>> Adjunct>
constexpr Sequent<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, Elemental>
    SafeSingleSequencer = {
        Instantiate<SinglyLinked<Elemental>, Natural, Elemental, Adjunct>,
        Account<SinglyLinked<Elemental>, Natural, Elemental>,
        Accede<Natural, Elemental, Adjunct>,
        PrecedeSafely<Natural, Elemental, Adjunct>,
        CedeSafely<Natural, Elemental, Adjunct>,
        Proceed<Natural, Elemental, Adjunct>,
        SucceedSafely<Natural, Elemental>,
        SupersedeSafely<Natural, Elemental>,
        ConcedeSafely<Natural, Elemental>,
        RecedeSafely<Natural, Elemental>,
        RemoveAll<SinglyLinked<Elemental>, Natural, Elemental>,
        DeleteOneNode<Natural, Elemental, Adjunct>,
        SafeSingleConjoiner<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, Natural, Elemental, Adjunct>
    };

template <
    typename Natural,
    typename Elemental,
    Referential<const DoublyAdjunctive<Natural, Elemental>> Adjunct>
constexpr Sequent<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    SafeDoubleSequencer = {
        Instantiate<DoublyLinked<Elemental>, Natural, Elemental, Adjunct>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Accede<Natural, Elemental, Adjunct>,
        PrecedeSafely<Natural, Elemental, Adjunct>,
        CedeSafely<Natural, Elemental, Adjunct>,
        Proceed<Natural, Elemental, Adjunct>,
        SucceedSafely<Natural, Elemental>,
        SupersedeSafely<Natural, Elemental>,
        ConcedeSafely<Natural, Elemental>,
        RecedeSafely<Natural, Elemental>,
        RemoveAll<DoublyLinked<Elemental>, Natural, Elemental>,
        DeleteOneNode<Natural, Elemental, Adjunct>,
        SafeDoubleConjoiner<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Natural, Elemental, Adjunct>
    };

}

}

#endif
