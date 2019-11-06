// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_ASSOCIATION_SELECTION_MODULE
#define RATION_ASSOCIATION_SELECTION_MODULE
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
     *     Array map management implementation.
     * @details
     *     Array map management implementation.
     */
    namespace selection {

        using consecution::Account;
        using consecution::Antecede;
        using consecution::Concede;
        using consecution::Concessive;
        using consecution::Condense;
        using consecution::Consequent;
        using consecution::Proceed;
        using consecution::Secede;
        using ::location::Locational;
        using ::location::Referential;
        using ::sortation::Assortive;
        using ::sortation::SearchSection;

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<const Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>> Scale,
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
            MapPositional position;
            if (Safety && Account(map) < 1)
                return false;
            Scale.begin(map, position, 0);
            return SearchSection(map, Scale, relator, position, Account(map) - 1, Equate);
        }

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Consequent<Natural, Length, Complementary<Correlative, Evaluative>>> Proceed,
            Referential<Assortive<Correlative>> Equate,
            Referential<const Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>> Scale,
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
            static auto& CorrespondInMap = Correspond<Natural, Length, Correlative, Evaluative, Equate, Scale, Safety>;
            const MapComplementary pair = { relator, value };
            if (Safety && Account(map) >= Length)
                return false;
            if (Safety && CorrespondInMap(map, relator))
                return false;
            return Proceed(map, pair);
        }

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<const Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>> Scale,
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
            ReadMapPositional position;
            WriteMapPositional found;
            Natural count;
            if (Safety && Account(map) < 1)
                return false;
            found = 0;
            Scale.begin(map, position, 0);
            for (count = Account(map); count > 0; count--) {
                const auto& relator = Scale.go(map, position).to;
                if (Equate(relator, replacement))
                    return false;
                if (Equate(relator, original))
                    found = const_cast<AssociativeWritePositional<Correlative, Evaluative>>(position);
                Scale.traverse(map, position, 1);
            }
            if (Safety && !found)
                return false;
            found->relator = replacement;
            return true;
        }

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Concessive<Natural, Length, Complementary<Correlative, Evaluative>>> Concede,
            Referential<Assortive<Correlative>> Equate,
            Referential<const Scalar<const AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, AssociativeReadPositional<Correlative, Evaluative>, Natural, const Correlative>> Scale,
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
            MapPositional position;
            if (Safety && Account(map) < 1)
                return false;
            Scale.begin(map, position, 0);
            if (!SearchSection(map, Scale, relator, position, Account(map) - 1, Equate) && Safety)
                return false;
            return Concede(map, position, 1);
        }

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<MemoryMoving<Natural, Complementary<Correlative, Evaluative>>> Move>
        constexpr Associative<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, Natural, Correlative, Evaluative>
            FastCorrelator = {
                Antecede<Natural, Length, Complementary<Correlative, Evaluative>, false>,
                Account<Natural, Length, Complementary<Correlative, Evaluative>>,
                Correspond<Natural, Length, Correlative, Evaluative, Equate, ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>, false>,
                Associate<Natural, Length, Correlative, Evaluative, Proceed<Natural, Length, Complementary<Correlative, Evaluative>, false>, Equate, ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>, false>,
                Reassociate<Natural, Length, Correlative, Evaluative, Equate, ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>, false>,
                Disassociate<Natural, Length, Correlative, Evaluative, Concede<Natural, Length, Complementary<Correlative, Evaluative>, Move, false>, Equate, ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>, false>,
                Secede<Natural, Length, Complementary<Correlative, Evaluative>>,
                Condense<Natural, Length, Complementary<Correlative, Evaluative>>
            };

        template <
            typename Natural,
            Natural Length,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<MemoryMoving<Natural, Complementary<Correlative, Evaluative>>> Move>
        constexpr Associative<AssociativelyResourceful<Natural, Length, Correlative, Evaluative>, Natural, Correlative, Evaluative>
            SureCorrelator = {
                Antecede<Natural, Length, Complementary<Correlative, Evaluative>, true>,
                Account<Natural, Length, Complementary<Correlative, Evaluative>>,
                Correspond<Natural, Length, Correlative, Evaluative, Equate, ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>, true>,
                Associate<Natural, Length, Correlative, Evaluative, Proceed<Natural, Length, Complementary<Correlative, Evaluative>, true>, Equate, ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>, true>,
                Reassociate<Natural, Length, Correlative, Evaluative, Equate, ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>, true>,
                Disassociate<Natural, Length, Correlative, Evaluative, Concede<Natural, Length, Complementary<Correlative, Evaluative>, Move, true>, Equate, ReadRelatorIncrementScale<Natural, Length, Correlative, Evaluative>, true>,
                Secede<Natural, Length, Complementary<Correlative, Evaluative>>,
                Condense<Natural, Length, Complementary<Correlative, Evaluative>>
            };

    }

}

}

#endif
