// � 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_ASSOCIATION_MODULE
#define RATION_ASSOCIATION_MODULE
#include <association.hpp>
#include <ration/consecution.hpp>
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

/**
 * @brief
 *     Array map management and trajection implementation.
 * @details
 *     Array map management and trajection implementation.
 */
namespace association {

    using ::association::Associative;
    using ::association::Complementary;
    using ::comparison::Comparison;
    using consecution::Account;
    using consecution::BeginReadIncrement;
    using consecution::BeginReadDecrement;
    using consecution::BeginWriteIncrement;
    using consecution::BeginWriteDecrement;
    using consecution::Begins;
    using consecution::CountReadIncrement;
    using consecution::CountWriteIncrement;
    using consecution::CountReadDecrement;
    using consecution::CountWriteDecrement;
    using consecution::ReadDecrementTraverses;
    using consecution::WriteDecrementTraverses;
    using consecution::GoRead;
    using consecution::GoWrite;
    using consecution::ReadIncrementTraverses;
    using consecution::WriteIncrementTraverses;
    using consecution::ReadMeets;
    using consecution::WriteMeets;
    using consecution::TraverseReadIncrement;
    using consecution::TraverseReadDecrement;
    using consecution::TraverseWriteIncrement;
    using consecution::TraverseWriteDecrement;
    using ::location::Conferential;
    using ::location::Referential;
    using ::trajection::Axial;
    using ::trajection::Directional;
    using ::trajection::Lineal;
    using ::trajection::Scalar;

    template <
        typename Natural,
        Natural Length,
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
        Natural Length,
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
        Natural Length,
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
        Natural Length,
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
        Natural Length,
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
        Natural Length,
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
        Natural Length,
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
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementDecrementScale = {
            Comparison<AssociativeReadPositional<Correlative, Evaluative>>,
            BeginReadDecrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            TraverseReadDecrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            GoReadElement<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Scalar<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeWritePositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementIncrementScale = {
            Comparison<AssociativeWritePositional<Correlative, Evaluative>>,
            BeginWriteIncrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            TraverseWriteIncrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            GoWriteElement<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural
            Length,
        typename Correlative,
        typename Evaluative>
    constexpr Scalar<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeWritePositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementDecrementScale = {
            Comparison<AssociativeWritePositional<Correlative, Evaluative>>,
            BeginWriteDecrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            TraverseWriteDecrement<Natural, Length, Complementary<Correlative, Evaluative>>,
            GoWriteElement<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Lineal<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorLiner = {
            ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>,
            ReadRelatorDecrementScale<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Lineal<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementLiner = {
            ReadElementIncrementScale<Natural, Length, Correlative, Evaluative>,
            ReadElementDecrementScale<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Lineal<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeWritePositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementLiner = {
            WriteElementIncrementScale<Natural, Length, Correlative, Evaluative>,
            WriteElementDecrementScale<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorIncrementDirection = {
            ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            ReadIncrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            ReadMeets<Natural, Length, Complementary<Correlative, Evaluative>>,
            Account<Natural, Length, Complementary<Correlative, Evaluative>>,
            CountReadIncrement<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorDecrementDirection = {
            ReadRelatorDecrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            ReadDecrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            ReadMeets<Natural, Length, Complementary<Correlative, Evaluative>>,
            Account<Natural, Length, Complementary<Correlative, Evaluative>>,
            CountReadDecrement<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementIncrementDirection = {
            ReadElementIncrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            ReadIncrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            ReadMeets<Natural, Length, Complementary<Correlative, Evaluative>>,
            Account<Natural, Length, Complementary<Correlative, Evaluative>>,
            CountReadIncrement<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementDecrementDirection = {
            ReadElementDecrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            ReadDecrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            ReadMeets<Natural, Length, Complementary<Correlative, Evaluative>>,
            Account<Natural, Length, Complementary<Correlative, Evaluative>>,
            CountReadDecrement<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeWritePositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementIncrementDirection = {
            WriteElementIncrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            WriteIncrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            WriteMeets<Natural, Length, Complementary<Correlative, Evaluative>>,
            Account<Natural, Length, Complementary<Correlative, Evaluative>>,
            CountWriteIncrement<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Directional<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeWritePositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementDecrementDirection = {
            WriteElementDecrementScale<Natural, Length, Correlative, Evaluative>,
            Begins<Natural, Length, Complementary<Correlative, Evaluative>>,
            WriteDecrementTraverses<Natural, Length, Complementary<Correlative, Evaluative>>,
            WriteMeets<Natural, Length, Complementary<Correlative, Evaluative>>,
            Account<Natural, Length, Complementary<Correlative, Evaluative>>,
            CountWriteDecrement<Natural, Length, Complementary<Correlative, Evaluative>>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Axial<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>
        ReadRelatorAxis = {
            ReadRelatorIncrementDirection<Natural, Length, Correlative, Evaluative>,
            ReadRelatorDecrementDirection<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Axial<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Evaluative>
        ReadElementAxis = {
            ReadElementIncrementDirection<Natural, Length, Correlative, Evaluative>,
            ReadElementDecrementDirection<Natural, Length, Correlative, Evaluative>
        };

    template <
        typename Natural,
        Natural Length,
        typename Correlative,
        typename Evaluative>
    constexpr Axial<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeWritePositional<Correlative, Evaluative>, Natural, Evaluative>
        WriteElementAxis = {
            WriteElementIncrementDirection<Natural, Length, Correlative, Evaluative>,
            WriteElementDecrementDirection<Natural, Length, Correlative, Evaluative>
        };

}

}

#endif
