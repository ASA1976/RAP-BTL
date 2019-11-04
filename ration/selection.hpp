// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_SELECTION_MODULE
#define RATION_SELECTION_MODULE
#include "../selection.hpp"
#include "consecution.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

/**
 * @brief
 *     Array set management implementation.
 * @details
 *     Array set management implementation.
 */
namespace selection {

using ::composition::Compositional;
using consecution::Account;
using consecution::Antecede;
using consecution::Concede;
using consecution::Concessive;
using consecution::Condense;
using consecution::Consequent;
using consecution::Proceed;
using consecution::ReadIncrementScale;
using consecution::Secede;
using ::location::Referential;
using ::selection::EquateSelections;
using ::selection::Sectional;
using ::selection::Selective;
using ::sortation::Assortive;
using ::sortation::SearchSection;
using ::trajection::Directional;
using ::trajection::Scalar;

template <
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Assortive<Elemental>> Equate,
    Referential<const Scalar<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Scale,
    const bool Safety>
static inline bool
AccreditSelection(
    Referential<const Resourceful<Natural, Length, Elemental>>
        set,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    ReadPositional<Elemental> position;
    if (Safety && Account(set) < 1)
        return false;
    Scale.begin(set, position, 0);
    return SearchSection(set, Scale, value, position, Account(set) - 1, Equate);
}

template <
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Consequent<Natural, Length, Elemental>> Proceed,
    Referential<Assortive<Elemental>> Equate,
    Referential<const Scalar<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Scale,
    const bool Safety>
static inline bool
ComposeSelection(
    Referential<Resourceful<Natural, Length, Elemental>>
        set,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    ReadPositional<Elemental> position;
    if (Safety && Account(set) >= Length)
        return false;
    if (Safety && Account(set) > 0) {
        Scale.begin(set, position, 0);
        if (SearchSection(set, Scale, value, position, Account(set) - 1, Equate))
            return false;
    }
    return Proceed(set, value);
}

template <
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Concessive<Natural, Length, Elemental>> Concede,
    Referential<Assortive<Elemental>> Equate,
    Referential<const Scalar<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Scale,
    const bool Safety>
static inline bool
DiscomposeSelection(
    Referential<Resourceful<Natural, Length, Elemental>>
        set,
    Referential<const Elemental>
        value)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    ReadPositional<Elemental> position;
    if (Safety && Account(set) < 1)
        return false;
    Scale.begin(set, position, 0);
    if (SearchSection(set, Scale, value, position, Account(set) - 1, Equate))
        return Concede(set, position, 1);
    return false;
}

template <
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Consequent<Natural, Length, Elemental>> Proceed,
    Referential<Concessive<Natural, Length, Elemental>> Concede,
    Referential<Assortive<Elemental>> Equate,
    Referential<const Scalar<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Scale,
    const bool Safety>
static inline bool
RecomposeSelection(
    Referential<Resourceful<Natural, Length, Elemental>>
        set,
    Referential<const Elemental>
        original,
    Referential<const Elemental>
        replacement)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    ReadPositional<Elemental> position, previous;
    if (Safety && Account(set) < 1)
        return false;
    previous = 0;
    Scale.begin(set, position, 0);
    for (Natural count = Account(set); count > 0; count--) {
        if (Equate(replacement, Scale.go(set, position).to))
            return false;
        if (Equate(original, Scale.go(set, position).to))
            previous = position;
    }
    if (Safety && !previous)
        return false;
    if (!Concede(set, previous, 1) && Safety)
        return false;
    return Proceed(set, replacement);
}

template <
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Natural,
    Natural Length,
    typename Elemental,
    const bool Safety>
static inline bool
DuplicateSelection(
    Referential<Resourceful<Natural, Length, Elemental>>
        operand,
    Referential<const Directional<const Basic, BasicPositional, BasicNatural, const Elemental>>
        basis,
    Referential<const Basic>
        base)
{
    using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
    static_assert(
        is_integral<BasicNatural>::value && is_unsigned<BasicNatural>::value,
        "BasicNatural:  Unsigned integer type required");
#endif
    WritePositional<Elemental> write_position;
    BasicPositional read_position;
    Secede(operand);
    if (!basis.begins(base, 0))
        return true;
    write_position = operand.source;
    basis.scale.begin(base, read_position, 0);
    while (true) {
        Refer(write_position).to = basis.scale.go(base, read_position).to;
        write_position++;
        if (Safety && write_position > operand.source + Length)
            return false;
        if (!basis.traverses(base, read_position, 1))
            break;
        basis.scale.traverse(base, read_position, 1);
    }
    operand.allotment = static_cast<Natural>(write_position - operand.source);
    return true;
}

template <
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Relative,
    typename RelativePositional,
    typename RelativeNatural,
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Consequent<Natural, Length, Elemental>> Proceed,
    Referential<Assortive<Elemental>> Equate,
    const bool Safety>
static inline bool
ComplementSelections(
    Referential<Resourceful<Natural, Length, Elemental>>
        operand,
    Referential<const Directional<const Basic, BasicPositional, BasicNatural, const Elemental>>
        basis,
    Referential<const Basic>
        base_set,
    Referential<const Directional<const Relative, RelativePositional, RelativeNatural, const Elemental>>
        relativity,
    Referential<const Relative>
        relative_set)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
    static_assert(
        is_integral<BasicNatural>::value && is_unsigned<BasicNatural>::value,
        "BasicNatural:  Unsigned integer type required");
    static_assert(
        is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
        "RelativeNatural:  Unsigned integer type required");
#endif
    static auto& DuplicateRelative = DuplicateSelection<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, Safety>;
    BasicPositional base_position;
    RelativePositional relative_position;
    BasicNatural extent;
    if (relativity.begins(relative_set, 0)) {
        if (basis.begins(base_set, 0)) {
            Secede(operand);
            extent = basis.survey(base_set) - 1;
            relativity.scale.begin(relative_set, relative_position, 0);
            while (true) {
                const auto& value = relativity.scale.go(relative_set, relative_position).to;
                basis.scale.begin(base_set, base_position, 0);
                if (!SearchSection(base_set, basis.scale, value, base_position, extent, Equate))
                    if (!Proceed(operand, value))
                        return false;
                if (!relativity.traverses(relative_set, relative_position, 1))
                    break;
                relativity.scale.traverse(relative_set, relative_position, 1);
            }
        } else {
            return DuplicateRelative(operand, relativity, relative_set);
        }
    } else {
        Secede(operand);
    }
    return true;
}

template <
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Relative,
    typename RelativePositional,
    typename RelativeNatural,
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Consequent<Natural, Length, Elemental>> Proceed,
    Referential<Assortive<Elemental>> Equate,
    const bool Safety>
static inline bool
DifferentiateSelections(
    Referential<Resourceful<Natural, Length, Elemental>>
        operand,
    Referential<const Directional<const Basic, BasicPositional, BasicNatural, const Elemental>>
        basis,
    Referential<const Basic>
        base_set,
    Referential<const Directional<const Relative, RelativePositional, RelativeNatural, const Elemental>>
        relativity,
    Referential<const Relative>
        relative_set)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
    static_assert(
        is_integral<BasicNatural>::value && is_unsigned<BasicNatural>::value,
        "BasicNatural:  Unsigned integer type required");
    static_assert(
        is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
        "RelativeNatural:  Unsigned integer type required");
#endif
    static auto& DuplicateBase = DuplicateSelection<Basic, BasicPositional, BasicNatural, Natural, Length, Elemental, Safety>;
    static auto& DuplicateRelative = DuplicateSelection<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, Safety>;
    BasicPositional base_position;
    RelativePositional relative_position;
    BasicNatural base_extent;
    RelativeNatural relative_extent;
    if (basis.begins(base_set, 0)) {
        if (!relativity.begins(relative_set, 0))
            return DuplicateBase(operand, basis, base_set);
    } else if (relativity.begins(relative_set, 0)) {
        return DuplicateRelative(operand, relativity, relative_set);
    } else {
        Secede(operand);
        return true;
    }
    Secede(operand);
    relative_extent = relativity.survey(relative_set) - 1;
    basis.scale.begin(base_set, base_position, 0);
    while (true) {
        const auto& value = basis.scale.go(base_set, base_position).to;
        relativity.scale.begin(relative_set, relative_position, 0);
        if (!SearchSection(relative_set, relativity.scale, value, relative_position, relative_extent, Equate)) {
            if (!Proceed(operand, value))
                return false;
        }
        if (!basis.traverses(base_set, base_position, 1))
            break;
        basis.scale.traverse(base_set, base_position, 1);
    }
    base_extent = basis.survey(base_set) - 1;
    relativity.scale.begin(relative_set, relative_position, 0);
    while (true) {
        const auto& value = relativity.scale.go(relative_set, relative_position).to;
        basis.scale.begin(base_set, base_position, 0);
        if (!SearchSection(base_set, basis.scale, value, base_position, base_extent, Equate)) {
            if (!Proceed(operand, value))
                return false;
        }
        if (!relativity.traverses(relative_set, relative_position, 1))
            break;
        relativity.scale.traverse(relative_set, relative_position, 1);
    }
    return true;
}

template <
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Relative,
    typename RelativePositional,
    typename RelativeNatural,
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Consequent<Natural, Length, Elemental>> Proceed,
    Referential<Assortive<Elemental>> Equate,
    const bool Safety>
static inline bool
IntersectSelections(
    Referential<Resourceful<Natural, Length, Elemental>>
        operand,
    Referential<const Directional<const Basic, BasicPositional, BasicNatural, const Elemental>>
        basis,
    Referential<const Basic>
        base_set,
    Referential<const Directional<const Relative, RelativePositional, RelativeNatural, const Elemental>>
        relativity,
    Referential<const Relative>
        relative_set)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
    static_assert(
        is_integral<BasicNatural>::value && is_unsigned<BasicNatural>::value,
        "BasicNatural:  Unsigned integer type required");
    static_assert(
        is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
        "RelativeNatural:  Unsigned integer type required");
#endif
    BasicPositional base_position;
    RelativePositional relative_position;
    BasicNatural base_extent;
    Secede(operand);
    if (relativity.begins(relative_set, 0) && basis.begins(base_set, 0)) {
        base_extent = basis.survey(base_set) - 1;
        relativity.scale.begin(relative_set, relative_position, 0);
        while (true) {
            const auto& value = relativity.scale.go(relative_set, relative_position).to;
            basis.scale.begin(base_set, base_position, 0);
            if (SearchSection(base_set, basis.scale, value, base_position, base_extent, Equate)) {
                if (!Proceed(operand, value))
                    return false;
            }
            if (!relativity.traverses(relative_set, relative_position, 1))
                break;
            relativity.scale.traverse(relative_set, relative_position, 1);
        }
    }
    return true;
}

template <
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Relative,
    typename RelativePositional,
    typename RelativeNatural,
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Consequent<Natural, Length, Elemental>> Proceed,
    Referential<Assortive<Elemental>> Equate,
    const bool Safety>
static inline bool
UniteSelections(
    Referential<Resourceful<Natural, Length, Elemental>>
        operand,
    Referential<const Directional<const Basic, BasicPositional, BasicNatural, const Elemental>>
        basis,
    Referential<const Basic>
        base_set,
    Referential<const Directional<const Relative, RelativePositional, RelativeNatural, const Elemental>>
        relativity,
    Referential<const Relative>
        relative_set)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
    static_assert(
        is_integral<BasicNatural>::value && is_unsigned<BasicNatural>::value,
        "BasicNatural:  Unsigned integer type required");
    static_assert(
        is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
        "RelativeNatural:  Unsigned integer type required");
#endif
    static auto& DuplicateBase = DuplicateSelection<Basic, BasicPositional, BasicNatural, Natural, Length, Elemental, Safety>;
    static auto& DuplicateRelative = DuplicateSelection<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, Safety>;
    BasicPositional base_position;
    RelativePositional relative_position;
    BasicNatural base_extent;
    if (basis.begins(base_set, 0)) {
        if (!DuplicateBase(operand, basis, base_set))
            return false;
        if (relativity.begins(relative_set, 0)) {
            base_extent = basis.survey(base_set) - 1;
            relativity.scale.begin(relative_set, relative_position, 0);
            while (true) {
                const auto& value = relativity.scale.go(relative_set, relative_position).to;
                basis.scale.begin(base_set, base_position, 0);
                if (!SearchSection(base_set, basis.scale, value, base_position, base_extent, Equate)) {
                    if (!Proceed(operand, value))
                        return false;
                }
                if (!relativity.traverses(relative_set, relative_position, 1))
                    break;
                relativity.scale.traverse(relative_set, relative_position, 1);
            }
        }
    } else if (relativity.begins(relative_set, 0)) {
        if (!DuplicateRelative(operand, relativity, relative_set))
            return false;
    } else {
        Secede(operand);
    }
    return true;
}

template <
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Assortive<Elemental>> Equate,
    Referential<MemoryMoving<Natural, Elemental>> Move>
constexpr Compositional<Resourceful<Natural, Length, Elemental>, Natural, Elemental>
    FastComposer = {
        Antecede<Natural, Length, Elemental, false>,
        AccreditSelection<
            Natural,
            Length,
            Elemental,
            Equate,
            ReadIncrementScale<Natural, Length, Elemental>,
            false>,
        ComposeSelection<
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, false>,
            Equate,
            ReadIncrementScale<Natural, Length, Elemental>,
            false>,
        RecomposeSelection<
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, false>,
            Concede<Natural, Length, Elemental, Move, false>,
            Equate,
            ReadIncrementScale<Natural, Length, Elemental>,
            false>,
        DiscomposeSelection<
            Natural,
            Length,
            Elemental,
            Concede<Natural, Length, Elemental, Move, false>,
            Equate,
            ReadIncrementScale<Natural, Length, Elemental>,
            false>,
        Secede<Natural, Length, Elemental>,
        Condense<Natural, Length, Elemental>
    };

template <
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Assortive<Elemental>> Equate,
    Referential<MemoryMoving<Natural, Elemental>> Move>
constexpr Compositional<Resourceful<Natural, Length, Elemental>, Natural, Elemental>
    SureComposer = {
        Antecede<Natural, Length, Elemental, true>,
        AccreditSelection<
            Natural,
            Length,
            Elemental,
            Equate,
            ReadIncrementScale<Natural, Length, Elemental>,
            true>,
        ComposeSelection<
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, true>,
            Equate,
            ReadIncrementScale<Natural, Length, Elemental>,
            true>,
        RecomposeSelection<
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, true>,
            Concede<Natural, Length, Elemental, Move, true>,
            Equate,
            ReadIncrementScale<Natural, Length, Elemental>,
            true>,
        DiscomposeSelection<
            Natural,
            Length,
            Elemental,
            Concede<Natural, Length, Elemental, Move, false>,
            Equate,
            ReadIncrementScale<Natural, Length, Elemental>,
            true>,
        Secede<Natural, Length, Elemental>,
        Condense<Natural, Length, Elemental>
    };

template <
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Relative,
    typename RelativePositional,
    typename RelativeNatural,
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Assortive<Elemental>> Equate,
    Referential<MemoryMoving<Natural, Elemental>> Move>
constexpr Sectional<Resourceful<Natural, Length, Elemental>, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental>
    FastSection = {
        ComplementSelections<
            Basic,
            BasicPositional,
            BasicNatural,
            Relative,
            RelativePositional,
            RelativeNatural,
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, false>,
            Equate,
            false>,
        DifferentiateSelections<
            Basic,
            BasicPositional,
            BasicNatural,
            Relative,
            RelativePositional,
            RelativeNatural,
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, false>,
            Equate,
            false>,
        IntersectSelections<
            Basic,
            BasicPositional,
            BasicNatural,
            Relative,
            RelativePositional,
            RelativeNatural,
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, false>,
            Equate,
            false>,
        UniteSelections<
            Basic,
            BasicPositional,
            BasicNatural,
            Relative,
            RelativePositional,
            RelativeNatural,
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, false>,
            Equate,
            false>
    };

template <
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Relative,
    typename RelativePositional,
    typename RelativeNatural,
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Assortive<Elemental>> Equate,
    Referential<MemoryMoving<Natural, Elemental>> Move>
constexpr Sectional<Resourceful<Natural, Length, Elemental>, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental>
    SureSection = {
        ComplementSelections<
            Basic,
            BasicPositional,
            BasicNatural,
            Relative,
            RelativePositional,
            RelativeNatural,
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, true>,
            Equate,
            true>,
        DifferentiateSelections<
            Basic,
            BasicPositional,
            BasicNatural,
            Relative,
            RelativePositional,
            RelativeNatural,
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, true>,
            Equate,
            true>,
        IntersectSelections<
            Basic,
            BasicPositional,
            BasicNatural,
            Relative,
            RelativePositional,
            RelativeNatural,
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, true>,
            Equate,
            true>,
        UniteSelections<
            Basic,
            BasicPositional,
            BasicNatural,
            Relative,
            RelativePositional,
            RelativeNatural,
            Natural,
            Length,
            Elemental,
            Proceed<Natural, Length, Elemental, true>,
            Equate,
            true>
    };

template <
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Assortive<Elemental>> Equate,
    Referential<MemoryMoving<Natural, Elemental>> Move>
constexpr Selective<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Elemental>
    FastSelector = {
        FastComposer<Natural, Length, Elemental, Equate, Move>,
        FastSection<
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Natural,
            Length,
            Elemental,
            Equate,
            Move>,
        DuplicateSelection<
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Natural,
            Length,
            Elemental,
            false>,
        EquateSelections<
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Elemental,
            Equate>,
        Account<Natural, Length, Elemental>
    };

template <
    typename Natural,
    Natural Length,
    typename Elemental,
    Referential<Assortive<Elemental>> Equate,
    Referential<MemoryMoving<Natural, Elemental>> Move>
constexpr Selective<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Elemental>
    SureSelector = {
        SureComposer<Natural, Length, Elemental, Equate, Move>,
        SureSection<
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Natural,
            Length,
            Elemental,
            Equate,
            Move>,
        DuplicateSelection<
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Natural,
            Length,
            Elemental,
            true>,
        EquateSelections<
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Resourceful<Natural, Length, Elemental>,
            ReadPositional<Elemental>,
            Natural,
            Elemental,
            Equate>,
        Account<Natural, Length, Elemental>
    };

}

}

#endif
