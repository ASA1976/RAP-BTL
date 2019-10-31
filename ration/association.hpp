// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_ASSOCIATION_MODULE
#define RATION_ASSOCIATION_MODULE
#include "../association.hpp"
#include "consecution.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

/**
     * @brief
     *     Array map management and trajection implementation.
     * @details
     *     Association
     *     -----------
     *     Array map management and trajection implementation.
     */
namespace association {

    using ::association::Associative;
    using ::association::Complementary;
    using ::comparison::Comparison;
    using consecution::BeginReadDecrement;
    using consecution::BeginReadIncrement;
    using consecution::Begins;
    using consecution::DecrementTraverses;
    using consecution::GoRead;
    using consecution::IncrementTraverses;
    using consecution::Meets;
    using consecution::TraverseReadDecrement;
    using consecution::TraverseReadIncrement;
    using ::location::Conferential;
    using ::location::Referential;
    using ::trajection::Axial;
    using ::trajection::Directional;
    using ::trajection::Lineal;
    using ::trajection::Scalar;

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    using AssociativelyResourceful = Resourceful<Natural, Length, Complementary<Correlative, Evaluative>>;

    template <
        typename Correlative,
        typename Evaluative>
    using AssociativeReadPositional = ReadPositional<Complementary<Correlative, Evaluative>>;

    template <
        typename Correlative,
        typename Evaluative>
    using AssociativeWritePositional = WritePositional<Complementary<Correlative, Evaluative>>;

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    static inline Conferential<const Correlative>
    GoReadRelator(
        Referential<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>>
            map,
        Referential<const AssociativeReadPositional<Correlative, Evaluative>>
            position)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return Confer(GoRead(map, position).to.relator);
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    static inline Conferential<const Evaluative>
    GoReadElement(
        Referential<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>>
            map,
        Referential<const AssociativeReadPositional<Correlative, Evaluative>>
            position)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return Confer(GoRead(map, position).to.value);
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    static inline Conferential<Evaluative>
    GoWriteElement(
        Referential<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>>
            map,
        Referential<const AssociativeWritePositional<Correlative, Evaluative>>
            position)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return Confer(GoWrite(map, position).to.value);
    }

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorIncrementScale = {
            Comparison<AssociativeReadPositional<Correlative, Evaluative>>,
            BeginReadIncrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            TraverseReadIncrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            GoReadRelator<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorDecrementScale = {
            Comparison<AssociativeReadPositional<Correlative, Evaluative>>,
            BeginReadDecrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            TraverseReadDecrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            GoReadRelator<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementIncrementScale = {
            Comparison<AssociativeReadPositional<Correlative, Evaluative>>,
            BeginReadIncrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            TraverseReadIncrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            GoReadElement<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementDecrementScale = {
            Comparison<AssociativeReadPositional<Correlative, Evaluative>>,
            BeginReadIncrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            TraverseReadDecrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            GoReadElement<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        WriteElementIncrementScale = {
            Comparison<AssociativeReadPositional<Correlative, Evaluative>>,
            BeginReadIncrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            TraverseReadIncrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            GoWriteElement<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        WriteElementDecrementScale = {
            Comparison<AssociativeReadPositional<Correlative, Evaluative>>,
            BeginReadDecrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            TraverseReadDecrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            GoWriteElement<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Lineal<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorLiner = {
            ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>,
            ReadRelatorDecrementScale<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Lineal<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementLiner = {
            ReadElementIncrementScale<Natural, Length, Correlative, Evaluative>,
            ReadElementDecrementScale<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Lineal<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementLiner = {
            WriteElementIncrementScale<Natural, Length, Correlative, Evaluative>,
            WriteElementDecrementScale<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorIncrementDirection = {
            ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            IncrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            Meets<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorDecrementDirection = {
            ReadRelatorDecrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            DecrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            Meets<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementIncrementDirection = {
            ReadElementIncrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            IncrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            Meets<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementDecrementDirection = {
            ReadElementDecrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            DecrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            Meets<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementIncrementDirection = {
            WriteElementIncrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            IncrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            Meets<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementDecrementDirection = {
            WriteElementDecrementScale<Natural, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            DecrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            Meets<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Axial<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorAxis = {
            ReadRelatorIncrementDirection<Natural, Length, Correlative, Evaluative>,
            ReadRelatorDecrementDirection<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Axial<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementAxis = {
            ReadElementIncrementDirection<Natural, Length, Correlative, Evaluative>,
            ReadElementDecrementDirection<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Axial<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementAxis = {
            WriteElementIncrementDirection<Natural, Length, Correlative, Evaluative>,
            WriteElementDecrementDirection<Natural, Length, Correlative, Evaluative>
        };

}

}

#endif
