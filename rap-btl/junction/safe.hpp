// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_MODULE
#define SAFE_JUNCTION_MODULE
#include <junction.hpp>

namespace junction {

template <
    typename Connective,
    typename Elemental>
static inline bool
IsGreaterCheckSafely(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    if (!base.at)
        throw base;
    if (!relative.at)
        throw relative;
    return IsGreater(base, relative);
}

template <
    typename Connective,
    typename Elemental>
static inline bool
IsLesserCheckSafely(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    if (!base.at)
        throw base;
    if (!relative.at)
        throw relative;
    return IsLesser(base, relative);
}

template <
    typename Connective,
    typename Elemental>
static inline bool
IsNotLesserCheckSafely(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    if (!base.at)
        throw base;
    if (!relative.at)
        throw relative;
    return IsNotLesser(base, relative);
}

template <
    typename Connective,
    typename Elemental>
static inline bool
IsNotGreaterCheckSafely(
    Referential<const Positional<Connective, Elemental>>
        base,
    Referential<const Positional<Connective, Elemental>>
        relative)
{
    if (!base.at)
        throw base;
    if (!relative.at)
        throw relative;
    return IsNotGreater(base, relative);
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline bool
ContainsCheckSafely(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Positional<Connective, Elemental>>
        position)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    if (!position.at)
        throw position;
    return Contains(list, position);
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Conferential<const Elemental>
GoReadSafely(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Positional<Connective, Elemental>>
        position)
{
    using ::location::Deter;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    static auto& ContainsPosition = Contains<Connective, Natural, Elemental, true>;
    if (!ContainsPosition(list, position))
        throw position;
    return GoRead(list, position);
}

template <
    typename Connective,
    typename Natural,
    typename Elemental>
static inline Conferential<Elemental>
GoWriteSafely(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Positional<Connective, Elemental>>
        position)
{
    using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    static auto& ContainsPosition = Contains<Connective, Natural, Elemental, true>;
    if (!ContainsPosition(list, position))
        throw position;
    return GoWrite(list, position);
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Original<Connective, Natural, Elemental>> GetOrigin,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline Referential<const Positional<Connective, Elemental>>
BeginReadScaleSafely(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Positional<Connective, Elemental>>
        position,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    current = GetOrigin(list);
    if (!current)
        throw list;
    for (index = 0; index < count; index++) {
        current = GetSubsequent(current);
        if (!current)
            throw count;
    }
    position.at = current;
    return position;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Original<Connective, Natural, Elemental>> GetOrigin,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline Referential<const Positional<Connective, Elemental>>
BeginWriteScaleSafely(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Positional<Connective, Elemental>>
        position,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    current = GetOrigin(list);
    if (!current)
        throw list;
    for (index = 0; index < count; index++) {
        current = GetSubsequent(position.at);
        if (!current)
            throw count;
    }
    position.at = current;
    return position;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline Referential<const Positional<Connective, Elemental>>
TraverseReadScaleSafely(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Positional<Connective, Elemental>>
        position,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    if (!position.at)
        throw position;
    current = position.at;
    for (index = 0; index < count; index++) {
        current = GetSubsequent(current);
        if (!current)
            throw count;
    }
    position.at = current;
    return position;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline Referential<const Positional<Connective, Elemental>>
TraverseWriteScaleSafely(
    Referential<Junctive<Connective, Natural, Elemental>>
        list,
    Referential<Positional<Connective, Elemental>>
        position,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using NodeLocational = Locational<Nodal<Connective, Elemental>>;
    NodeLocational current;
    Natural index;
    if (!position.at)
        throw position;
    current = position.at;
    for (index = 0; index < count; index++) {
        current = GetSubsequent(current);
        if (!current)
            throw count;
    }
    position.at = current;
    return position;
}

template <
    typename Connective,
    typename Natural,
    typename Elemental,
    Referential<Subsequent<Connective, Elemental>> GetSubsequent>
static inline bool
DirectionTraversesCheckSafely(
    Referential<const Junctive<Connective, Natural, Elemental>>
        list,
    Referential<const Positional<Connective, Elemental>>
        position,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    static auto& Traverses = DirectionTraverses<Connective, Natural, Elemental, GetSubsequent>;
    if (!position.at)
        throw position;
    return Traverses(list, position, count);
}

template <typename Elemental>
constexpr Relational<SinglyPositional<Elemental>>
    SafeSingleRelation = {
        IsLesserCheckSafely<SinglyLinked<Elemental>, Elemental>,
        IsGreaterCheckSafely<SinglyLinked<Elemental>, Elemental>,
        IsNotGreaterCheckSafely<SinglyLinked<Elemental>, Elemental>,
        IsNotLesserCheckSafely<SinglyLinked<Elemental>, Elemental>
    };

template <typename Elemental>
constexpr Relational<DoublyPositional<Elemental>>
    SafeDoubleRelation = {
        IsLesserCheckSafely<DoublyLinked<Elemental>, Elemental>,
        IsGreaterCheckSafely<DoublyLinked<Elemental>, Elemental>,
        IsNotGreaterCheckSafely<DoublyLinked<Elemental>, Elemental>,
        IsNotLesserCheckSafely<DoublyLinked<Elemental>, Elemental>
    };

template <typename Elemental>
constexpr Comparative<SinglyPositional<Elemental>>
    SafeSingleComparison = {
        SingleEquality<Elemental>,
        SafeSingleRelation<Elemental>
    };

template <typename Elemental>
constexpr Comparative<DoublyPositional<Elemental>>
    SafeDoubleComparison = {
        DoubleEquality<Elemental>,
        SafeDoubleRelation<Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Vectorial<const SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, const Elemental>
    SafeReadSingleVector = {
        SafeSingleComparison<Elemental>,
        ContainsCheckSafely<SinglyLinked<Elemental>, Natural, Elemental>,
        GoReadSafely<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Vectorial<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, const Elemental>
    SafeReadDoubleVector = {
        SafeDoubleComparison<Elemental>,
        ContainsCheckSafely<DoublyLinked<Elemental>, Natural, Elemental>,
        GoReadSafely<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Vectorial<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Elemental>
    SafeWriteSingleVector = {
        SafeSingleComparison<Elemental>,
        ContainsCheckSafely<SinglyLinked<Elemental>, Natural, Elemental>,
        GoWriteSafely<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Vectorial<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Elemental>
    SafeWriteDoubleVector = {
        SafeDoubleComparison<Elemental>,
        ContainsCheckSafely<DoublyLinked<Elemental>, Natural, Elemental>,
        GoWriteSafely<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<const SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, const Elemental>
    SafeReadIncrementSingleScale = {
        SafeSingleComparison<Elemental>,
        BeginReadScaleSafely<SinglyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        TraverseReadScaleSafely<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        GoReadSafely<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    SafeReadIncrementDoubleScale = {
        SafeDoubleComparison<Elemental>,
        BeginReadScaleSafely<DoublyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        TraverseReadScaleSafely<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        GoReadSafely<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, Elemental>
    SafeWriteIncrementSingleScale = {
        SafeSingleComparison<Elemental>,
        BeginWriteScaleSafely<SinglyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        TraverseWriteScaleSafely<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        GoWriteSafely<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    SafeWriteIncrementDoubleScale = {
        SafeDoubleComparison<Elemental>,
        BeginWriteScaleSafely<DoublyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        TraverseWriteScaleSafely<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        GoWriteSafely<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    SafeReadDecrementDoubleScale = {
        SafeDoubleComparison<Elemental>,
        BeginReadScaleSafely<DoublyLinked<Elemental>, Natural, Elemental, GetLast<Natural, Elemental>, GetPrevious<Elemental>>,
        TraverseReadScaleSafely<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>,
        GoReadSafely<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Scalar<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    SafeWriteDecrementDoubleScale = {
        SafeDoubleComparison<Elemental>,
        BeginWriteScaleSafely<DoublyLinked<Elemental>, Natural, Elemental, GetLast<Natural, Elemental>, GetPrevious<Elemental>>,
        TraverseWriteScaleSafely<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>,
        GoWriteSafely<DoublyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Lineal<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    SafeReadDoubleLiner = {
        SafeReadIncrementDoubleScale<Natural, Elemental>,
        SafeReadDecrementDoubleScale<Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Lineal<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    SafeWriteDoubleLiner = {
        SafeWriteIncrementDoubleScale<Natural, Elemental>,
        SafeWriteDecrementDoubleScale<Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<const SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, const Elemental>
    SafeReadIncrementSingleDirection = {
        SafeReadIncrementSingleScale<Natural, Elemental>,
        DirectionBegins<SinglyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        DirectionTraversesCheckSafely<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        ContainsCheckSafely<SinglyLinked<Elemental>, Natural, Elemental>,
        Account<SinglyLinked<Elemental>, Natural, Elemental>,
        Count<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    SafeReadIncrementDoubleDirection = {
        SafeReadIncrementDoubleScale<Natural, Elemental>,
        DirectionBegins<DoublyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        DirectionTraversesCheckSafely<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        ContainsCheckSafely<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Count<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, Elemental>
    SafeWriteIncrementSingleDirection = {
        SafeWriteIncrementSingleScale<Natural, Elemental>,
        DirectionBegins<SinglyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        DirectionTraversesCheckSafely<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        ContainsCheckSafely<SinglyLinked<Elemental>, Natural, Elemental>,
        Account<SinglyLinked<Elemental>, Natural, Elemental>,
        Count<SinglyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    SafeWriteIncrementDoubleDirection = {
        SafeWriteIncrementDoubleScale<Natural, Elemental>,
        DirectionBegins<DoublyLinked<Elemental>, Natural, Elemental, GetFirst<Natural, Elemental>, GetNext<Elemental>>,
        DirectionTraversesCheckSafely<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>,
        ContainsCheckSafely<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Count<DoublyLinked<Elemental>, Natural, Elemental, GetNext<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    SafeReadDecrementDoubleDirection = {
        SafeReadDecrementDoubleScale<Natural, Elemental>,
        DirectionBegins<DoublyLinked<Elemental>, Natural, Elemental, GetLast<Natural, Elemental>, GetPrevious<Elemental>>,
        DirectionTraversesCheckSafely<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>,
        ContainsCheckSafely<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Count<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Directional<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    SafeWriteDecrementDoubleDirection = {
        SafeWriteDecrementDoubleScale<Natural, Elemental>,
        DirectionBegins<DoublyLinked<Elemental>, Natural, Elemental, GetLast<Natural, Elemental>, GetPrevious<Elemental>>,
        DirectionTraversesCheckSafely<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>,
        ContainsCheckSafely<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Count<DoublyLinked<Elemental>, Natural, Elemental, GetPrevious<Elemental>>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Axial<const DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, const Elemental>
    SafeReadDoubleAxis = {
        SafeReadIncrementDoubleDirection<Natural, Elemental>,
        SafeReadDecrementDoubleDirection<Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Axial<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
    SafeWriteDoubleAxis = {
        SafeWriteIncrementDoubleDirection<Natural, Elemental>,
        SafeWriteDecrementDoubleDirection<Natural, Elemental>
    };

}

#endif
