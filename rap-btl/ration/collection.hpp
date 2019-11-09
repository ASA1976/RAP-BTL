// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_COLLECTION_MODULE
#define RATION_COLLECTION_MODULE
#include <collection.hpp>
#include <ration/consecution.hpp>
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

/**
 * @brief
 *     Array sorted set management implementation.
 * @details
 *     Array sorted set management implementation.
 */
namespace collection {

    using ::collection::Bisectional;
    using ::collection::Collective;
    using ::collection::EquateCollections;
    using ::composition::Compositional;
    using consecution::Account;
    using consecution::Antecede;
    using consecution::Cede;
    using consecution::Concede;
    using consecution::Concessive;
    using consecution::Condense;
    using ::consecution::ConjointlyConsequent;
    using consecution::Consequent;
    using consecution::Precede;
    using consecution::Precedent;
    using consecution::Proceed;
    using consecution::ReadLiner;
    using consecution::Secede;
    using ::location::Referential;
    using ::selection::EquateSelections;
    using ::selection::Sectional;
    using ::selection::Selective;
    using ::sortation::Assortive;
    using ::sortation::SearchBisection;
    using ::sortation::SearchBisectionIteratively;
    using ::sortation::SearchSection;
    using ::trajection::Axial;
    using ::trajection::Directional;
    using ::trajection::Lineal;

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<const Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Liner,
        const bool Safety>
    static inline bool
    AccreditCollection(
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
        static const Natural Before = 0;
        ReadPositional<Elemental> position;
        if (Safety && Account(set) < 1)
            return false;
        Liner.increment.begin(set, position, 0);
        return SearchBisection(set, Liner, value, position, Before, Account(set) - 1, Equate, Order);
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Precedent<Natural, Length, Elemental>> Precede,
        Referential<Precedent<Natural, Length, Elemental>> Cede,
        Referential<Consequent<Natural, Length, Elemental>> Proceed,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<const Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Liner,
        const bool Safety>
    static inline bool
    ComposeCollection(
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
        static const Natural Before = 0;
        ReadPositional<Elemental> position;
        if (Safety && Account(set) >= Length)
            return false;
        if (Account(set) < 1)
            return Proceed(set, value);
        Liner.increment.begin(set, position, 0);
        if (SearchBisection(set, Liner, value, position, Before, Account(set) - 1, Equate, Order) && Safety)
            return false;
        if (Order(Liner.increment.go(set, position).to, value))
            return Cede(set, position, value);
        return Precede(set, position, value);
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Concessive<Natural, Length, Elemental>> Concede,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<const Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Liner,
        const bool Safety>
    static inline bool
    DiscomposeCollection(
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
        static const Natural Before = 0;
        ReadPositional<Elemental> position;
        if (Safety && Account(set) < 1)
            return false;
        Liner.increment.begin(set, position, 0);
        if (!SearchBisection(set, Liner, value, position, Before, Account(set) - 1, Equate, Order) && Safety)
            return false;
        return Concede(set, position, 1);
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<const Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Liner,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    RecomposeCollection(
        Referential<Resourceful<Natural, Length, Elemental>>
            set,
        Referential<const Elemental>
            original,
        Referential<const Elemental>
            replacement)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        static const Natural Before = 0;
        ReadPositional<Elemental> original_position, replacement_position;
        if (Safety && Account(set) < 1)
            return false;
        const Natural extent = Account(set) - 1;
        Liner.increment.begin(set, original_position, 0);
        if (!SearchBisection(set, Liner, original, original_position, Before, extent, Equate, Order) && Safety)
            return false;
        Liner.increment.begin(set, replacement_position, 0);
        if (SearchBisection(set, Liner, replacement, replacement_position, Before, extent, Equate, Order) && Safety)
            return false;
        const WritePositional<Elemental> write_position = const_cast<WritePositional<Elemental>>(replacement_position);
        if (replacement_position < original_position) {
            const Natural delta = static_cast<Natural>(original_position - replacement_position);
            if (!Move(write_position, write_position + 1, delta) && Safety)
                return false;
        } else {
            const WritePositional<Elemental> first = const_cast<WritePositional<Elemental>>(original_position);
            const Natural delta = static_cast<Natural>(replacement_position - original_position);
            if (!Move(first + 1, first, delta) && Safety)
                return false;
        }
        Refer(write_position).to = replacement;
        return true;
    }

    template <
        typename Basic,
        typename BasicPositional,
        typename BasicNatural,
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Precedent<Natural, Length, Elemental>> Precede,
        Referential<Precedent<Natural, Length, Elemental>> Cede,
        Referential<Consequent<Natural, Length, Elemental>> Proceed,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<const Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Liner,
        const bool Safety>
    static inline bool
    CollateSelection(
        Referential<Resourceful<Natural, Length, Elemental>>
            operand,
        Referential<const Directional<const Basic, BasicPositional, BasicNatural, const Elemental>>
            basis,
        Referential<const Basic>
            base)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        using ElementReferential = Referential<const Elemental>;
        ReadPositional<Elemental> operand_position;
        BasicPositional base_position;
        Natural before, after;
        Secede(operand);
        if (!basis.begins(base, 0))
            return true;
        basis.scale.begin(base, base_position, 0);
        if (!Proceed(operand, basis.scale.go(base, base_position).to) && Safety)
            return false;
        Liner.increment.begin(operand, operand_position, 0);
        before = after = 0;
        while (true) {
            ElementReferential base_value = basis.scale.go(base, base_position).to;
            if (!SearchBisectionIteratively(operand, Liner, base_value, operand_position, before, after, Equate, Order)) {
                if (Order(Liner.increment.go(operand, operand_position).to, base_value)) {
                    if (!Cede(operand, operand_position, base_value) && Safety)
                        return false;
                } else {
                    if (!Precede(operand, operand_position, base_value) && Safety)
                        return false;
                }
                after++;
            }
            if (!basis.traverses(base, base_position, 1))
                break;
            basis.scale.traverse(base, base_position, 1);
        }
        return true;
    }

    template <
        typename Basic,
        typename BasicPositional,
        typename BasicNatural,
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<ConjointlyConsequent<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Basic, BasicPositional, BasicNatural, Elemental>> ProceedMany>
    static inline bool
    CollateCollection(
        Referential<Resourceful<Natural, Length, Elemental>>
            operand,
        Referential<const Axial<const Basic, BasicPositional, BasicNatural, const Elemental>>
            basis,
        Referential<const Basic>
            base)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
        static_assert(
            is_integral<BasicNatural>::value && is_unsigned<BasicNatural>::value,
            "BasicNatural:  Unsigned integer type required");
#endif
        BasicPositional first, last;
        Secede(operand);
        if (!basis.increment.begins(base, 0))
            return true;
        basis.increment.scale.begin(base, first, 0);
        basis.decrement.scale.begin(base, last, 0);
        return ProceedMany(operand, basis.increment, base, first, last);
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
        Referential<Precedent<Natural, Length, Elemental>> Precede,
        Referential<Precedent<Natural, Length, Elemental>> Cede,
        Referential<Consequent<Natural, Length, Elemental>> Proceed,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<const Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Liner,
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
        using ElementReferential = Referential<const Elemental>;
        static auto& CollateRelative = CollateSelection<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, Precede, Cede, Proceed, Equate, Order, Liner, Safety>;
        ReadPositional<Elemental> operand_position;
        BasicPositional base_position;
        RelativePositional relative_position;
        BasicNatural extent;
        Natural before, after;
        if (relativity.begins(relative_set, 0)) {
            if (basis.begins(base_set, 0)) {
                Secede(operand);
                extent = basis.survey(base_set) - 1;
                relativity.scale.begin(relative_set, relative_position, 0);
                while (true) {
                    ElementReferential relative_value = relativity.scale.go(relative_set, relative_position).to;
                    basis.scale.begin(base_set, base_position, 0);
                    if (!SearchSection(base_set, basis.scale, relative_value, base_position, extent, Equate)) {
                        if (Account(operand) > 0) {
                            if (!SearchBisectionIteratively(operand, Liner, relative_value, operand_position, before, after, Equate, Order)) {
                                if (Order(Liner.increment.go(operand, operand_position).to, relative_value)) {
                                    if (!Cede(operand, operand_position, relative_value) && Safety)
                                        return false;
                                } else {
                                    if (!Precede(operand, operand_position, relative_value) && Safety)
                                        return false;
                                }
                                after++;
                            }
                        } else {
                            if (!Proceed(operand, relative_value) && Safety)
                                return false;
                            Liner.increment.begin(operand, operand_position, 0);
                            before = after = 0;
                        }
                    }
                    if (!relativity.traverses(relative_set, relative_position, 1))
                        break;
                    relativity.scale.traverse(relative_set, relative_position, 1);
                }
            } else {
                CollateRelative(operand, relativity, relative_set);
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
        Referential<Precedent<Natural, Length, Elemental>> Precede,
        Referential<Precedent<Natural, Length, Elemental>> Cede,
        Referential<Consequent<Natural, Length, Elemental>> Proceed,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<const Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Liner,
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
        using ElementReferential = Referential<const Elemental>;
        static auto& CollateBase = CollateSelection<Basic, BasicPositional, BasicNatural, Natural, Length, Elemental, Precede, Cede, Proceed, Equate, Order, Liner, Safety>;
        static auto& CollateRelative = CollateSelection<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, Precede, Cede, Proceed, Equate, Order, Liner, Safety>;
        ReadPositional<Elemental> operand_position;
        BasicPositional base_position;
        RelativePositional relative_position;
        BasicNatural base_extent;
        RelativeNatural relative_extent;
        Natural before, after;
        if (basis.begins(base_set, 0)) {
            if (relativity.begins(relative_set, 0)) {
                Secede(operand);
                relative_extent = relativity.survey(relative_set) - 1;
                basis.scale.begin(base_set, base_position, 0);
                while (true) {
                    ElementReferential base_value = basis.scale.go(base_set, base_position).to;
                    relativity.scale.begin(relative_set, relative_position, 0);
                    if (!SearchSection(relative_set, relativity.scale, base_value, relative_position, relative_extent, Equate)) {
                        if (Account(operand) > 0) {
                            if (!SearchBisectionIteratively(operand, Liner, base_value, operand_position, before, after, Equate, Order)) {
                                if (Order(Liner.increment.go(operand, operand_position).to, base_value)) {
                                    if (!Cede(operand, operand_position, base_value) && Safety)
                                        return false;
                                } else {
                                    if (!Precede(operand, operand_position, base_value) && Safety)
                                        return false;
                                }
                                after++;
                            }
                        } else {
                            if (!Proceed(operand, base_value) && Safety)
                                return false;
                            before = after = 0;
                            Liner.increment.begin(operand, operand_position, 0);
                        }
                    }
                    if (!basis.traverses(base_set, base_position, 1))
                        break;
                    basis.scale.traverse(base_set, base_position, 1);
                }
                base_extent = basis.survey(base_set) - 1;
                relativity.scale.begin(relative_set, relative_position, 0);
                while (true) {
                    ElementReferential relative_value = relativity.scale.go(relative_set, relative_position).to;
                    basis.scale.begin(base_set, base_position, 0);
                    if (!SearchSection(base_set, basis.scale, relative_value, base_position, base_extent, Equate)) {
                        if (Account(operand) > 0) {
                            if (!SearchBisectionIteratively(operand, Liner, relative_value, operand_position, before, after, Equate, Order)) {
                                if (Order(Liner.increment.go(operand, operand_position).to, relative_value)) {
                                    if (!Cede(operand, operand_position, relative_value) && Safety)
                                        return false;
                                } else {
                                    if (!Precede(operand, operand_position, relative_value) && Safety)
                                        return false;
                                }
                                after++;
                            }
                        } else {
                            if (!Proceed(operand, relative_value) && Safety)
                                return false;
                            before = after = 0;
                            Liner.increment.begin(operand, operand_position, 0);
                        }
                    }
                    if (!relativity.traverses(relative_set, relative_position, 1))
                        break;
                    relativity.scale.traverse(relative_set, relative_position, 1);
                }
            } else {
                return CollateBase(operand, basis, base_set);
            }
        } else if (relativity.begins(relative_set, 0)) {
            return CollateRelative(operand, relativity, relative_set);
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
        Referential<Precedent<Natural, Length, Elemental>> Precede,
        Referential<Precedent<Natural, Length, Elemental>> Cede,
        Referential<Consequent<Natural, Length, Elemental>> Proceed,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<const Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Liner,
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
        using ElementReferential = Referential<const Elemental>;
        ReadPositional<Elemental> operand_position;
        BasicPositional base_position;
        RelativePositional relative_position;
        BasicNatural extent;
        Natural before, after;
        Secede(operand);
        if (relativity.begins(relative_set, 0) && basis.begins(base_set, 0)) {
            extent = basis.survey(base_set) - 1;
            relativity.scale.begin(relative_set, relative_position, 0);
            while (true) {
                ElementReferential relative_value = relativity.scale.go(relative_set, relative_position).to;
                basis.scale.begin(base_set, base_position, 0);
                if (SearchSection(base_set, relativity.scale, relative_value, base_position, extent, Equate)) {
                    if (Account(operand) > 0) {
                        if (!SearchBisectionIteratively(operand, Liner, relative_value, operand_position, before, after, Equate, Order)) {
                            if (Order(Liner.increment.go(operand, operand_position).to, relative_value)) {
                                if (!Cede(operand, operand_position, relative_value) && Safety)
                                    return false;
                            } else {
                                if (!Precede(operand, operand_position, relative_value) && Safety)
                                    return false;
                            }
                            after++;
                        }
                    } else {
                        if (!Proceed(operand, relative_value) && Safety)
                            return false;
                        before = after = 0;
                        Liner.increment.begin(operand, operand_position, 0);
                    }
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
        Referential<Precedent<Natural, Length, Elemental>> Precede,
        Referential<Precedent<Natural, Length, Elemental>> Cede,
        Referential<Consequent<Natural, Length, Elemental>> Proceed,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<const Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>> Liner,
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
        using ElementReferential = Referential<const Elemental>;
        static auto& CollateBase = CollateSelection<Basic, BasicPositional, BasicNatural, Natural, Length, Elemental, Precede, Cede, Proceed, Equate, Order, Liner, Safety>;
        static auto& CollateRelative = CollateSelection<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, Precede, Cede, Proceed, Equate, Order, Liner, Safety>;
        ReadPositional<Elemental> operand_position;
        BasicPositional base_position;
        RelativePositional relative_position;
        Natural before, after;
        if (basis.begins(base_set, 0)) {
            if (relativity.begins(relative_set, 0)) {
                Secede(operand);
                basis.scale.begin(base_set, base_position, 0);
                while (true) {
                    ElementReferential base_value = basis.scale.go(base_set, base_position).to;
                    if (Account(operand) > 0) {
                        SearchBisectionIteratively(operand, Liner, base_value, operand_position, before, after, Equate, Order);
                        if (Order(Liner.increment.go(operand, operand_position).to, base_value)) {
                            if (!Cede(operand, operand_position, base_value) && Safety)
                                return false;
                        } else {
                            if (!Precede(operand, operand_position, base_value) && Safety)
                                return false;
                        }
                        after++;
                    } else {
                        if (!Proceed(operand, base_value) && Safety)
                            return false;
                        before = after = 0;
                        Liner.increment.begin(operand, operand_position, 0);
                    }
                    if (!basis.traverses(base_set, base_position, 1))
                        break;
                    basis.scale.traverse(base_set, base_position, 1);
                }
                relativity.scale.begin(relative_set, relative_position, 0);
                while (true) {
                    ElementReferential relative_value = relativity.scale.go(relative_set, relative_position).to;
                    if (Account(operand) > 0) {
                        if (!SearchBisectionIteratively(operand, Liner, relative_value, operand_position, before, after, Equate, Order)) {
                            if (Order(Liner.increment.go(operand, operand_position).to, relative_value)) {
                                if (!Cede(operand, operand_position, relative_value) && Safety)
                                    return false;
                            } else {
                                if (!Precede(operand, operand_position, relative_value) && Safety)
                                    return false;
                            }
                            after++;
                        }
                    } else {
                        if (!Proceed(operand, relative_value) && Safety)
                            return false;
                        before = after = 0;
                        Liner.increment.begin(operand, operand_position, 0);
                    }
                    if (!relativity.traverses(relative_set, relative_position, 1))
                        break;
                    relativity.scale.traverse(relative_set, relative_position, 1);
                }
            } else {
                return CollateBase(operand, basis, base_set);
            }
        } else if (relativity.begins(relative_set, 0)) {
            return CollateRelative(operand, relativity, relative_set);
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
        Referential<Consequent<Natural, Length, Elemental>> ProceedOne,
        Referential<ConjointlyConsequent<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Relative, RelativePositional, RelativeNatural, Elemental>> ProceedMany,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        const bool Safety>
    static inline bool
    ComplementCollections(
        Referential<Resourceful<Natural, Length, Elemental>>
            operand,
        Referential<const Axial<const Basic, BasicPositional, BasicNatural, const Elemental>>
            basis,
        Referential<const Basic>
            base_set,
        Referential<const Axial<const Relative, RelativePositional, RelativeNatural, const Elemental>>
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
        using ElementReferential = Referential<const Elemental>;
        BasicPositional position;
        RelativePositional opposition, last;
        Secede(operand);
        if (relativity.increment.begins(relative_set, 0)) {
            relativity.increment.scale.begin(relative_set, opposition, 0);
            if (basis.increment.begins(base_set, 0)) {
                basis.increment.scale.begin(base_set, position, 0);
                while (true) {
                    ElementReferential base_value = basis.increment.scale.go(base_set, position).to;
                    ElementReferential relative_value = basis.increment.scale.go(relative_set, opposition).to;
                    if (Equate(base_value, relative_value)) {
                        if (!relativity.increment.traverses(relative_set, opposition, 1))
                            return true;
                        relativity.increment.scale.traverse(relative_set, opposition, 1);
                        if (!basis.increment.traverses(base_set, position, 1))
                            break;
                        basis.increment.scale.traverse(base_set, position, 1);
                    } else if (Order(base_value, relative_value)) {
                        if (!basis.increment.traverses(base_set, position, 1))
                            break;
                        basis.increment.scale.traverse(base_set, position, 1);
                    } else {
                        if (!ProceedOne(operand, relative_value) && Safety)
                            return false;
                        if (!relativity.increment.traverses(relative_set, opposition, 1))
                            return true;
                        relativity.increment.scale.traverse(relative_set, opposition, 1);
                    }
                }
            }
            relativity.decrement.scale.begin(relative_set, last, 0);
            if (!ProceedMany(operand, relativity.increment, relative_set, opposition, last) && Safety)
                return false;
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
        Referential<Consequent<Natural, Length, Elemental>> ProceedOne,
        Referential<ConjointlyConsequent<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Basic, BasicPositional, BasicNatural, Elemental>> ProceedManyFromBase,
        Referential<ConjointlyConsequent<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Relative, RelativePositional, RelativeNatural, Elemental>> ProceedManyFromRelative,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        const bool Safety>
    static inline bool
    DifferentiateCollections(
        Referential<Resourceful<Natural, Length, Elemental>>
            operand,
        Referential<const Axial<const Basic, BasicPositional, BasicNatural, const Elemental>>
            basis,
        Referential<const Basic>
            base_set,
        Referential<const Axial<const Relative, RelativePositional, RelativeNatural, const Elemental>>
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
        using ElementReferential = Referential<const Elemental>;
        BasicPositional position;
        RelativePositional opposition;
        auto find_base_last = [&] {
            BasicPositional last;
            basis.decrement.scale.begin(base_set, last, 0);
            return ProceedManyFromBase(operand, basis.increment, base_set, position, last);
        };
        auto find_relative_last = [&] {
            RelativePositional last;
            relativity.decrement.scale.begin(relative_set, last, 0);
            return ProceedManyFromRelative(operand, relativity.increment, relative_set, opposition, last);
        };
        Secede(operand);
        if (!basis.increment.begins(base_set, 0)) {
            if (relativity.increment.begins(relative_set, 0)) {
                relativity.increment.scale.begin(relative_set, opposition, 0);
                return find_relative_last();
            }
        } else if (!relativity.increment.begins(relative_set, 0)) {
            if (basis.increment.begins(base_set, 0)) {
                basis.increment.scale.begin(base_set, position, 0);
                return find_base_last();
            }
        } else {
            basis.increment.scale.begin(base_set, position, 0);
            relativity.increment.scale.begin(relative_set, opposition, 0);
            while (true) {
                ElementReferential base_value = basis.increment.scale.go(base_set, position).to;
                ElementReferential relative_value = relativity.increment.scale.go(relative_set, opposition).to;
                if (Equate(base_value, relative_value)) {
                    if (!basis.increment.traverses(base_set, position, 1)) {
                        if (!relativity.increment.traverses(relative_set, opposition, 1))
                            break;
                        relativity.increment.scale.traverse(relative_set, opposition, 1);
                        return find_relative_last();
                    } else if (!relativity.increment.traverses(relative_set, opposition, 1)) {
                        basis.increment.scale.traverse(base_set, position, 1);
                        return find_base_last();
                    }
                    basis.increment.scale.traverse(base_set, position, 1);
                    relativity.increment.scale.traverse(relative_set, opposition, 1);
                } else if (Order(base_value, relative_value)) {
                    if (!ProceedOne(operand, base_value) && Safety)
                        return false;
                    if (!basis.increment.traverses(base_set, position, 1))
                        return find_relative_last();
                    basis.increment.scale.traverse(base_set, position, 1);
                } else {
                    if (!ProceedOne(operand, relative_value) && Safety)
                        return false;
                    if (!relativity.increment.traverses(relative_set, opposition, 1))
                        return find_base_last();
                    relativity.increment.scale.traverse(relative_set, opposition, 1);
                }
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
        Referential<Assortive<Elemental>> Order,
        const bool Safety>
    static inline bool
    IntersectCollections(
        Referential<Resourceful<Natural, Length, Elemental>>
            operand,
        Referential<const Axial<const Basic, BasicPositional, BasicNatural, const Elemental>>
            basis,
        Referential<const Basic>
            base_set,
        Referential<const Axial<const Relative, RelativePositional, RelativeNatural, const Elemental>>
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
        using ElementReferential = Referential<const Elemental>;
        BasicPositional position;
        RelativePositional opposition;
        Secede(operand);
        if (!basis.increment.begins(base_set, 0) || !relativity.increment.begins(relative_set, 0))
            return true;
        basis.increment.scale.begin(base_set, position, 0);
        relativity.increment.scale.begin(relative_set, opposition, 0);
        while (true) {
            ElementReferential base_value = basis.increment.scale.go(base_set, position).to;
            ElementReferential relative_value = relativity.increment.scale.go(relative_set, opposition).to;
            if (Equate(base_value, relative_value)) {
                if (!Proceed(operand, base_value) && Safety)
                    return false;
                if (!basis.increment.traverses(base_set, position, 1))
                    return true;
                if (!relativity.increment.traverses(relative_set, opposition, 1))
                    return true;
                basis.increment.scale.traverse(base_set, position, 1);
                relativity.increment.scale.traverse(relative_set, opposition, 1);
            } else if (Order(base_value, relative_value)) {
                if (!basis.increment.traverses(base_set, position, 1))
                    return true;
                basis.increment.scale.traverse(base_set, position, 1);
            } else {
                if (!relativity.increment.traverses(relative_set, opposition, 1))
                    return true;
                relativity.increment.scale.traverse(relative_set, opposition, 1);
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
        Referential<Consequent<Natural, Length, Elemental>> ProceedOne,
        Referential<ConjointlyConsequent<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Basic, BasicPositional, BasicNatural, Elemental>> ProceedManyFromBase,
        Referential<ConjointlyConsequent<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Relative, RelativePositional, RelativeNatural, Elemental>> ProceedManyFromRelative,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        const bool Safety>
    static inline bool
    UniteCollections(
        Referential<Resourceful<Natural, Length, Elemental>>
            operand,
        Referential<const Axial<const Basic, BasicPositional, BasicNatural, const Elemental>>
            basis,
        Referential<const Basic>
            base_set,
        Referential<const Axial<const Relative, RelativePositional, RelativeNatural, const Elemental>>
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
        using ElementReferential = Referential<const Elemental>;
        BasicPositional position;
        RelativePositional apposition;
        auto find_base_last = [&] {
            BasicPositional last;
            basis.decrement.scale.begin(base_set, last, 0);
            return ProceedManyFromBase(operand, basis.increment, base_set, position, last);
        };
        auto find_relative_last = [&] {
            RelativePositional last;
            relativity.decrement.scale.begin(relative_set, last, 0);
            return ProceedManyFromRelative(operand, relativity.increment, relative_set, apposition, last);
        };
        Secede(operand);
        if (!basis.increment.begins(base_set, 0)) {
            if (!relativity.increment.begins(relative_set, 0))
                return true;
            relativity.increment.scale.begin(relative_set, apposition, 0);
            return find_relative_last();
        } else if (!relativity.increment.begins(relative_set, 0)) {
            basis.increment.scale.begin(base_set, position, 0);
            return find_base_last();
        }
        basis.increment.scale.begin(base_set, position, 0);
        relativity.increment.scale.begin(relative_set, apposition, 0);
        while (true) {
            ElementReferential base_value = basis.increment.scale.go(base_set, position).to;
            ElementReferential relative_value = relativity.increment.scale.go(relative_set, apposition).to;
            if (Equate(base_value, relative_value)) {
                if (!ProceedOne(operand, base_value) && Safety)
                    return false;
                if (!basis.increment.traverses(base_set, position, 1)) {
                    if (!relativity.increment.traverses(relative_set, apposition, 1))
                        return true;
                    relativity.increment.scale.traverse(relative_set, apposition, 1);
                    return find_relative_last();
                } else if (!relativity.increment.traverses(relative_set, apposition, 1)) {
                    basis.increment.scale.traverse(base_set, position, 1);
                    return find_base_last();
                }
                basis.increment.scale.traverse(base_set, position, 1);
                relativity.increment.scale.traverse(relative_set, apposition, 1);
            } else if (Order(base_value, relative_value)) {
                if (!ProceedOne(operand, base_value) && Safety)
                    return false;
                if (!basis.increment.traverses(base_set, position, 1))
                    return find_relative_last();
                basis.increment.scale.traverse(base_set, position, 1);
            } else {
                if (!ProceedOne(operand, relative_value) && Safety)
                    return false;
                if (!relativity.increment.traverses(relative_set, apposition, 1))
                    return find_base_last();
                relativity.increment.scale.traverse(relative_set, apposition, 1);
            }
        }
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Compositional<Resourceful<Natural, Length, Elemental>, Natural, Elemental>
        FastOrderedComposer = {
            Antecede<Natural, Length, Elemental, false>,
            AccreditCollection<
                Natural,
                Length,
                Elemental,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
                false>,
            ComposeCollection<
                Natural,
                Length,
                Elemental,
                Precede<Natural, Length, Elemental, Move, false>,
                Cede<Natural, Length, Elemental, Move, false>,
                Proceed<Natural, Length, Elemental, false>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
                false>,
            RecomposeCollection<
                Natural,
                Length,
                Elemental,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
                Move,
                false>,
            DiscomposeCollection<
                Natural,
                Length,
                Elemental,
                Concede<Natural, Length, Elemental, Move, false>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
                false>,
            Secede<Natural, Length, Elemental>,
            Condense<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Compositional<Resourceful<Natural, Length, Elemental>, Natural, Elemental>
        SureOrderedComposer = {
            Antecede<Natural, Length, Elemental, true>,
            AccreditCollection<
                Natural,
                Length,
                Elemental,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
                true>,
            ComposeCollection<
                Natural,
                Length,
                Elemental,
                Precede<Natural, Length, Elemental, Move, true>,
                Cede<Natural, Length, Elemental, Move, true>,
                Proceed<Natural, Length, Elemental, true>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
                true>,
            RecomposeCollection<
                Natural,
                Length,
                Elemental,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
                Move,
                true>,
            DiscomposeCollection<
                Natural,
                Length,
                Elemental,
                Concede<Natural, Length, Elemental, Move, true>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Sectional<Resourceful<Natural, Length, Elemental>, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental>
        FastOrderedSection = {
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
                Precede<Natural, Length, Elemental, Move, false>,
                Cede<Natural, Length, Elemental, Move, false>,
                Proceed<Natural, Length, Elemental, false>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
                Precede<Natural, Length, Elemental, Move, false>,
                Cede<Natural, Length, Elemental, Move, false>,
                Proceed<Natural, Length, Elemental, false>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
                Precede<Natural, Length, Elemental, Move, false>,
                Cede<Natural, Length, Elemental, Move, false>,
                Proceed<Natural, Length, Elemental, false>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
                Precede<Natural, Length, Elemental, Move, false>,
                Cede<Natural, Length, Elemental, Move, false>,
                Proceed<Natural, Length, Elemental, false>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Sectional<Resourceful<Natural, Length, Elemental>, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental>
        SureOrderedSection = {
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
                Precede<Natural, Length, Elemental, Move, true>,
                Cede<Natural, Length, Elemental, Move, true>,
                Proceed<Natural, Length, Elemental, true>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
                Precede<Natural, Length, Elemental, Move, true>,
                Cede<Natural, Length, Elemental, Move, true>,
                Proceed<Natural, Length, Elemental, true>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
                Precede<Natural, Length, Elemental, Move, true>,
                Cede<Natural, Length, Elemental, Move, true>,
                Proceed<Natural, Length, Elemental, true>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
                Precede<Natural, Length, Elemental, Move, true>,
                Cede<Natural, Length, Elemental, Move, true>,
                Proceed<Natural, Length, Elemental, true>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
                true>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Selective<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Elemental>
        FastOrderedSelector = {
            FastOrderedComposer<Natural, Length, Elemental, Equate, Order, Move>,
            FastOrderedSection<
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
                Order,
                Move>,
            CollateSelection<
                Resourceful<Natural, Length, Elemental>,
                ReadPositional<Elemental>,
                Natural,
                Natural,
                Length,
                Elemental,
                Precede<Natural, Length, Elemental, Move, false>,
                Cede<Natural, Length, Elemental, Move, false>,
                Proceed<Natural, Length, Elemental, false>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Selective<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Elemental>
        SureOrderedSelector = {
            SureOrderedComposer<Natural, Length, Elemental, Equate, Order, Move>,
            SureOrderedSection<
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
                Order,
                Move>,
            CollateSelection<
                Resourceful<Natural, Length, Elemental>,
                ReadPositional<Elemental>,
                Natural,
                Natural,
                Length,
                Elemental,
                Precede<Natural, Length, Elemental, Move, true>,
                Cede<Natural, Length, Elemental, Move, true>,
                Proceed<Natural, Length, Elemental, true>,
                Equate,
                Order,
                ReadLiner<Natural, Length, Elemental>,
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
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Bisectional<Resourceful<Natural, Length, Elemental>, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental>
        FastBisection = {
            ComplementCollections<
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
                Proceed<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, false>,
                Equate,
                Order,
                false>,
            DifferentiateCollections<
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
                Proceed<Basic, BasicPositional, BasicNatural, Natural, Length, Elemental, false>,
                Proceed<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, false>,
                Equate,
                Order,
                false>,
            IntersectCollections<
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
                Order,
                false>,
            UniteCollections<
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
                Proceed<Basic, BasicPositional, BasicNatural, Natural, Length, Elemental, false>,
                Proceed<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, false>,
                Equate,
                Order,
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
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Bisectional<Resourceful<Natural, Length, Elemental>, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental>
        SureBisection = {
            ComplementCollections<
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
                Proceed<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, true>,
                Equate,
                Order,
                true>,
            DifferentiateCollections<
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
                Proceed<Basic, BasicPositional, BasicNatural, Natural, Length, Elemental, true>,
                Proceed<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, true>,
                Equate,
                Order,
                true>,
            IntersectCollections<
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
                Order,
                true>,
            UniteCollections<
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
                Proceed<Basic, BasicPositional, BasicNatural, Natural, Length, Elemental, true>,
                Proceed<Relative, RelativePositional, RelativeNatural, Natural, Length, Elemental, true>,
                Equate,
                Order,
                true>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Collective<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Elemental>
        FastCollector = {
            FastOrderedSelector<Natural, Length, Elemental, Equate, Order, Move>,
            FastBisection<
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
                Order,
                Move>,
            CollateCollection<
                Resourceful<Natural, Length, Elemental>,
                ReadPositional<Elemental>,
                Natural,
                Natural,
                Length,
                Elemental,
                Proceed<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Natural, Length, Elemental, false>>,
            EquateCollections<
                Resourceful<Natural, Length, Elemental>,
                ReadPositional<Elemental>,
                Natural,
                Resourceful<Natural, Length, Elemental>,
                ReadPositional<Elemental>,
                Natural,
                Elemental,
                Equate>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<Assortive<Elemental>> Equate,
        Referential<Assortive<Elemental>> Order,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Collective<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Elemental>
        SureCollector = {
            SureOrderedSelector<Natural, Length, Elemental, Equate, Order, Move>,
            SureBisection<
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
                Order,
                Move>,
            CollateCollection<
                Resourceful<Natural, Length, Elemental>,
                ReadPositional<Elemental>,
                Natural,
                Natural,
                Length,
                Elemental,
                Proceed<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Natural, Length, Elemental, true>>,
            EquateCollections<
                Resourceful<Natural, Length, Elemental>,
                ReadPositional<Elemental>,
                Natural,
                Resourceful<Natural, Length, Elemental>,
                ReadPositional<Elemental>,
                Natural,
                Elemental,
                Equate>
        };

}

}

#endif
