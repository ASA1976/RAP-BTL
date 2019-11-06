// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_ASSOCIATION_COLLECTION_MODULE
#define RATION_ASSOCIATION_COLLECTION_MODULE
#include "../../sortation.hpp"
#include "../association.hpp"
#include "../consecution.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

namespace association {

    /**
     * @brief
     *     Array sorted map management implementation.
     * @details
     *     Array sorted map management implementation.
     */
    namespace collection {

        using consecution::Account;
        using consecution::Antecede;
        using consecution::Cede;
        using consecution::Concede;
        using consecution::Concessive;
        using consecution::Condense;
        using consecution::Consequent;
        using consecution::Precede;
        using consecution::Precedent;
        using consecution::Proceed;
        using consecution::Secede;
        using ::location::Locational;
        using ::location::Referential;
        using ::sortation::Assortive;
        using ::sortation::SearchBisection;
        using ::sortation::SearchBisectionIteratively;
        using ::sortation::SearchScalarBisection;

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<Assortive<Correlative>> Order,
            Referential<const Lineal<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>> Liner,
            const bool Safety>
        static inline bool
        Correspond(
            Referential<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>>
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
            using MapPositional = AssociativeReadPositional<Correlative, Evaluative>;
            static const Natural Before = 0;
            MapPositional position;
            if (Safety && Account(map) < 1)
                return false;
            Liner.increment.begin(map, position, 0);
            return SearchBisection(map, Liner, relator, position, Before, Account(map) - 1, Equate, Order);
        }

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Precedent<Natural, Length, Complementary<Correlative, Evaluative>>> Precede,
            Referential<Precedent<Natural, Length, Complementary<Correlative, Evaluative>>> Cede,
            Referential<Consequent<Natural, Length, Complementary<Correlative, Evaluative>>> Proceed,
            Referential<Assortive<Correlative>> Equate,
            Referential<Assortive<Correlative>> Order,
            Referential<const Lineal<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>> Liner,
            const bool Safety>
        static inline bool
        Associate(
            Referential<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>>
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
            using MapComplementary = Complementary<Correlative, Evaluative>;
            using MapPositional = AssociativeReadPositional<Correlative, Evaluative>;
            static const Natural Before = 0;
            const MapComplementary pair = { relator, value };
            MapPositional position;
            if (Safety && Account(map) >= Length)
                return false;
            if (Safety && Account(map) < 1)
                return Proceed(map, pair);
            Liner.increment.begin(map, position, 0);
            if (SearchBisection(map, Liner, relator, position, Before, Account(map) - 1, Equate, Order) && Safety)
                return false;
            if (Order(Liner.increment.go(map, position).to, relator))
                return Cede(map, position, pair);
            return Precede(map, position, pair);
        }

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<Assortive<Correlative>> Order,
            Referential<const Lineal<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>> Liner,
            Referential<MemoryMoving<Natural, Complementary<Correlative, Evaluative>>> Move,
            const bool Safety>
        static inline bool
        Reassociate(
            Referential<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>>
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
            using ReadMapPositional = AssociativeReadPositional<Correlative, Evaluative>;
            using WriteMapPositional = AssociativeWritePositional<Correlative, Evaluative>;
            static const Natural Before = 0;
            ReadMapPositional original_position, replacement_position;
            Natural extent;
            if (Safety && Account(map) < 1)
                return false;
            Liner.increment.begin(map, original_position, 0);
            Liner.increment.begin(map, replacement_position, 0);
            extent = Account(map) - 1;
            if (!SearchBisection(map, Liner, original, original_position, Before, extent, Equate, Order) && Safety)
                return false;
            if (SearchBisection(map, Liner, replacement, replacement_position, Before, extent, Equate, Order) && Safety)
                return false;
            auto& value = original_position->value;
            WriteMapPositional write_position = const_cast<AssociativeWritePositional<Correlative, Evaluative>>(replacement_position);
            if (replacement_position < original_position) {
                const Natural delta = static_cast<Natural>(original_position - replacement_position);
                if (!Move(write_position, write_position + 1, delta) && Safety)
                    return false;
            } else {
                const WriteMapPositional first = const_cast<WriteMapPositional>(original_position);
                const Natural delta = static_cast<Natural>(replacement_position - original_position);
                if (!Move(first + 1, first, delta) && Safety)
                    return false;
            }
            write_position->relator = replacement;
            write_position->value = value;
            return true;
        }

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Concessive<Natural, Length, Complementary<Correlative, Evaluative>>> Concede,
            Referential<Assortive<Correlative>> Equate,
            Referential<Assortive<Correlative>> Order,
            Referential<const Lineal<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>> Liner,
            const bool Safety>
        static inline bool
        Disassociate(
            Referential<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>>
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
            using MapPositional = AssociativeReadPositional<Correlative, Evaluative>;
            static const Natural Before = 0;
            MapPositional position;
            if (Safety && Account(map) < 1)
                return false;
            Liner.increment.begin(map, position, 0);
            if (!SearchBisection(map, Liner, relator, position, Before, Account(map) - 1, Equate, Order) && Safety)
                return false;
            return Concede(map, position, 1);
        }

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<Assortive<Correlative>> Order,
            Referential<MemoryMoving<Natural, Complementary<Correlative, Evaluative>>> Move>
        constexpr Associative<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, Natural, Correlative, Evaluative>
            FastAssociator = {
                Antecede<Natural, Length, Complementary<Correlative, Evaluative>, false>,
                Account<Natural, Length, Complementary<Correlative, Evaluative>>,
                Correspond<Natural, Length, Correlative, Evaluative, Equate, Order, ReadRelatorLiner<Natural, Length, Correlative, Evaluative>, false>,
                Associate<Natural, Length, Correlative, Evaluative, Precede<Natural, Length, Complementary<Correlative, Evaluative>, Move, false>, Cede<Natural, Length, Complementary<Correlative, Evaluative>, Move, false>, Proceed<Natural, Length, Complementary<Correlative, Evaluative>, false>, Equate, Order, ReadRelatorLiner<Natural, Length, Correlative, Evaluative>, false>,
                Reassociate<Natural, Length, Correlative, Evaluative, Equate, Order, ReadRelatorLiner<Natural, Length, Correlative, Evaluative>, Move, false>,
                Disassociate<Natural, Length, Correlative, Evaluative, Concede<Natural, Length, Complementary<Correlative, Evaluative>, Move, false>, Equate, Order, ReadRelatorLiner<Natural, Length, Correlative, Evaluative>, false>,
                Secede<Natural, Length, Complementary<Correlative, Evaluative>>,
                Condense<Natural, Length, Complementary<Correlative, Evaluative>>
            };

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<Assortive<Correlative>> Order,
            Referential<MemoryMoving<Natural, Complementary<Correlative, Evaluative>>> Move>
        constexpr Associative<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, Natural, Correlative, Evaluative>
            SureAssociator = {
                Antecede<Natural, Length, Complementary<Correlative, Evaluative>, true>,
                Account<Natural, Length, Complementary<Correlative, Evaluative>>,
                Correspond<Natural, Length, Correlative, Evaluative, Equate, Order, ReadRelatorLiner<Natural, Length, Correlative, Evaluative>, true>,
                Associate<Natural, Length, Correlative, Evaluative, Precede<Natural, Length, Complementary<Correlative, Evaluative>, Move, true>, Cede<Natural, Length, Complementary<Correlative, Evaluative>, Move, true>, Proceed<Natural, Length, Complementary<Correlative, Evaluative>, true>, Equate, Order, ReadRelatorLiner<Natural, Length, Correlative, Evaluative>, true>,
                Reassociate<Natural, Length, Correlative, Evaluative, Equate, Order, ReadRelatorLiner<Natural, Length, Correlative, Evaluative>, Move, true>,
                Disassociate<Natural, Length, Correlative, Evaluative, Concede<Natural, Length, Complementary<Correlative, Evaluative>, Move, true>, Equate, Order, ReadRelatorLiner<Natural, Length, Correlative, Evaluative>, true>,
                Secede<Natural, Length, Complementary<Correlative, Evaluative>>,
                Condense<Natural, Length, Complementary<Correlative, Evaluative>>
            };

    }

}

}

#endif
