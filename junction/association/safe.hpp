// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_ASSOCIATION_MODULE
#define SAFE_JUNCTION_ASSOCIATION_MODULE
#include "../safe.hpp"
#include "../association.hpp"

namespace junction {

namespace association {

template <
    typename Connective,
    typename Natural,
    typename Correlative,
    typename Evaluative>
static inline Conferential<const Correlative>
GoReadRelatorSafely(
    Referential<const AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>>
        map,
    Referential<const AssociativelyPositional<Connective, Correlative, Evaluative>>
        position)
{
    using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    if (!ContainsCheckSafely(map, position))
        throw position;
    return GoReadRelator(map, position);
}

template <
    typename Connective,
    typename Natural,
    typename Correlative,
    typename Evaluative>
static inline Conferential<const Evaluative>
GoReadElementSafely(
    Referential<const AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>>
        map,
    Referential<const AssociativelyPositional<Connective, Correlative, Evaluative>>
        position)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    if (!ContainsCheckSafely(map, position))
        throw position;
    return GoReadElement(map, position);
}

template <
    typename Connective,
    typename Natural,
    typename Correlative,
    typename Evaluative>
static inline Conferential<Evaluative>
GoWriteElementSafely(
    Referential<AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>>
        map,
    Referential<const AssociativelyPositional<Connective, Correlative, Evaluative>>
        position)
{
    using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    if (!ContainsCheckSafely(map, position))
        throw position;
    return GoWriteElement(map, position);
}

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Scalar<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Correlative>
    SafeReadRelatorIncrementSingleScale = {
        SingleComparison<Complementary<Correlative, Evaluative>>,
        BeginReadScaleSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        TraverseReadScaleSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        GoReadRelatorSafely<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Scalar<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>
    SafeReadRelatorIncrementDoubleScale = {
        DoubleComparison<Complementary<Correlative, Evaluative>>,
        BeginReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        TraverseReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        GoReadRelatorSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Scalar<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>
    SafeReadRelatorDecrementDoubleScale = {
        DoubleComparison<Complementary<Correlative, Evaluative>>,
        BeginReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetLast<Natural, Complementary<Correlative, Evaluative>>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        TraverseReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        GoReadRelatorSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Scalar<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeReadElementIncrementSingleScale = {
        SingleComparison<Complementary<Correlative, Evaluative>>,
        BeginReadScaleSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        TraverseReadScaleSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        GoReadElementSafely<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Scalar<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeReadElementIncrementDoubleScale = {
        DoubleComparison<Complementary<Correlative, Evaluative>>,
        BeginReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        TraverseReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        GoReadElementSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Scalar<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeReadElementDecrementDoubleScale = {
        DoubleComparison<Complementary<Correlative, Evaluative>>,
        BeginReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetLast<Natural, Complementary<Correlative, Evaluative>>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        TraverseReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        GoReadElementSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Scalar<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeWriteElementIncrementSingleScale = {
        SingleComparison<Complementary<Correlative, Evaluative>>,
        BeginReadScaleSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        TraverseReadScaleSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        GoWriteElementSafely<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Scalar<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeWriteElementIncrementDoubleScale = {
        DoubleComparison<Complementary<Correlative, Evaluative>>,
        BeginReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        TraverseReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        GoWriteElementSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Scalar<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeWriteElementDecrementDoubleScale = {
        DoubleComparison<Complementary<Correlative, Evaluative>>,
        BeginReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetLast<Natural, Complementary<Correlative, Evaluative>>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        TraverseReadScaleSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        GoWriteElementSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Lineal<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>
    SafeReadRelatorDoubleLiner = {
        SafeReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>,
        SafeReadRelatorDecrementDoubleScale<Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Lineal<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeReadElementDoubleLiner = {
        SafeReadElementIncrementDoubleScale<Natural, Correlative, Evaluative>,
        SafeReadElementDecrementDoubleScale<Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Lineal<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, Evaluative>
    SafeWriteElementDoubleLiner = {
        SafeWriteElementIncrementDoubleScale<Natural, Correlative, Evaluative>,
        SafeWriteElementDecrementDoubleScale<Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Directional<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Correlative>
    SafeReadRelatorIncrementSingleDirection = {
        SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>,
        DirectionBegins<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        DirectionTraversesCheckSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        ContainsCheckSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Directional<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>
    SafeReadRelatorIncrementDoubleDirection = {
        SafeReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>,
        DirectionBegins<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        DirectionTraversesCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        ContainsCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Directional<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>
    SafeReadRelatorDecrementDoubleDirection = {
        SafeReadRelatorDecrementDoubleScale<Natural, Correlative, Evaluative>,
        DirectionBegins<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetLast<Natural, Complementary<Correlative, Evaluative>>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        DirectionTraversesCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        ContainsCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Directional<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeReadElementIncrementSingleDirection = {
        SafeReadElementIncrementSingleScale<Natural, Correlative, Evaluative>,
        DirectionBegins<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        DirectionTraversesCheckSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        ContainsCheckSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Directional<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeReadElementIncrementDoubleDirection = {
        SafeReadElementIncrementDoubleScale<Natural, Correlative, Evaluative>,
        DirectionBegins<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        DirectionTraversesCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        ContainsCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Directional<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeReadElementDecrementDoubleDirection = {
        SafeReadElementDecrementDoubleScale<Natural, Correlative, Evaluative>,
        DirectionBegins<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetLast<Natural, Complementary<Correlative, Evaluative>>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        DirectionTraversesCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        ContainsCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Directional<AssociativelySingleJunctive<Natural, Correlative, Evaluative>, AssociativelySinglePositional<Correlative, Evaluative>, Natural, Evaluative>
    SafeWriteElementIncrementSingleDirection = {
        SafeWriteElementIncrementSingleScale<Natural, Correlative, Evaluative>,
        DirectionBegins<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        DirectionTraversesCheckSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        ContainsCheckSafely<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Directional<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, Evaluative>
    SafeWriteElementIncrementDoubleDirection = {
        SafeWriteElementIncrementDoubleScale<Natural, Correlative, Evaluative>,
        DirectionBegins<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetFirst<Natural, Complementary<Correlative, Evaluative>>, GetNext<Complementary<Correlative, Evaluative>>>,
        DirectionTraversesCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetNext<Complementary<Correlative, Evaluative>>>,
        ContainsCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Directional<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, Evaluative>
    SafeWriteElementDecrementDoubleDirection = {
        SafeWriteElementDecrementDoubleScale<Natural, Correlative, Evaluative>,
        DirectionBegins<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetLast<Natural, Complementary<Correlative, Evaluative>>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        DirectionTraversesCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, GetPrevious<Complementary<Correlative, Evaluative>>>,
        ContainsCheckSafely<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Axial<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Correlative>
    SafeReadRelatorDoubleAxis = {
        SafeReadRelatorIncrementDoubleDirection<Natural, Correlative, Evaluative>,
        SafeReadRelatorDecrementDoubleDirection<Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Axial<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, const Evaluative>
    SafeReadElementDoubleAxis = {
        SafeReadElementIncrementDoubleDirection<Natural, Correlative, Evaluative>,
        SafeReadElementDecrementDoubleDirection<Natural, Correlative, Evaluative>
    };

template <
    typename Natural,
    typename Correlative,
    typename Evaluative>
constexpr Axial<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, AssociativelyDoublePositional<Correlative, Evaluative>, Natural, Evaluative>
    SafeWriteElementDoubleAxis = {
        SafeWriteElementIncrementDoubleDirection<Natural, Correlative, Evaluative>,
        SafeWriteElementDecrementDoubleDirection<Natural, Correlative, Evaluative>
    };

}

}

#endif
