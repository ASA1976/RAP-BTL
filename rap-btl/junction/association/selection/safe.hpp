// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_ASSOCIATION_SELECTION_MODULE
#define SAFE_JUNCTION_ASSOCIATION_SELECTION_MODULE
#include <junction/association/selection.hpp>
#include <junction/consecution/safe.hpp>

namespace junction {

namespace association {

    namespace selection {

        using ::junction::consecution::ConcedeSafely;
        using ::junction::consecution::SucceedSafely;

        // This function template throws an exception if the relator (key)
        // does not exist in the map.
        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<const Scalar<const AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>, AssociativelyPositional<Connective, Correlative, Evaluative>, Natural, const Correlative>> Scale>
        static inline Conferential<const Evaluative>
        RelateReadElement(
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
            AssociativelyPositional<Connective, Correlative, Evaluative>
                position;
            if (!map.first)
                throw relator;
            Scale.begin(map, position, 0);
            if (!SearchSection(map, Scale, relator, position, Account(map) - 1, Equate))
                throw relator;
            return GoReadElement(map, position);
        }

        // This function template throws an exception if the relator (key)
        // does not exist in the map.
        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<const Scalar<const AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>, AssociativelyPositional<Connective, Correlative, Evaluative>, Natural, const Correlative>> Scale>
        static inline Conferential<Evaluative>
        RelateWriteElement(
            Referential<AssociativelyJunctive<Connective, Natural, Correlative, Evaluative>>
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
            AssociativelyPositional<Connective, Correlative, Evaluative>
                position;
            if (!map.first)
                throw relator;
            Scale.begin(map, position, 0);
            if (!SearchSection(map, Scale, relator, position, Account(map) - 1, Equate))
                throw relator;
            return GoWriteElement(map, position);
        }

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate>
        constexpr Vectorial<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, Correlative, const Evaluative>
            RelateReadSingleVector = {
                Correspond<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
                RelateReadElement<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>
            };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate>
        constexpr Vectorial<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, Correlative, const Evaluative>
            RelateReadDoubleVector = {
                Correspond<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>,
                RelateReadElement<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>
            };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate>
        constexpr Vectorial<const AssociativelySingleJunctive<Natural, Correlative, Evaluative>, Correlative, const Evaluative>
            SafeRelateReadSingleVector = {
                Correspond<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
                RelateReadElement<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>
            };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate>
        constexpr Vectorial<const AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, Correlative, const Evaluative>
            SafeRelateReadDoubleVector = {
                Correspond<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>,
                RelateReadElement<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>
            };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate>
        constexpr Vectorial<AssociativelySingleJunctive<Natural, Correlative, Evaluative>, Correlative, Evaluative>
            RelateWriteSingleVector = {
                Correspond<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
                RelateWriteElement<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>
            };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate>
        constexpr Vectorial<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, Correlative, Evaluative>
            RelateWriteDoubleVector = {
                Correspond<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
                RelateWriteElement<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, ReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>
            };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate>
        constexpr Vectorial<AssociativelySingleJunctive<Natural, Correlative, Evaluative>, Correlative, Evaluative>
            SafeRelateWriteSingleVector = {
                Correspond<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
                RelateWriteElement<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>
            };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate>
        constexpr Vectorial<AssociativelyDoubleJunctive<Natural, Correlative, Evaluative>, Correlative, Evaluative>
            SafeRelateWriteDoubleVector = {
                Correspond<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
                RelateWriteElement<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>
            };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative,
            Referential<Assortive<Correlative>> Equate,
            Referential<const AssociativelySingleAdjunctive<Natural, Correlative, Evaluative>> Adjunct>
        constexpr Associative<AssociativelySingleJunctive<Natural, Correlative, Evaluative>, Natural, Correlative, Evaluative>
            SafeSingleCorrelator = {
                Instantiate<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, Adjunct>,
                Account<SingleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
                Correspond<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
                Associate<SingleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Proceed<Natural, Complementary<Correlative, Evaluative>, Adjunct>, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
                Reassociate<Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>, Adjunct>,
                Disassociate<Natural, Correlative, Evaluative, SucceedSafely<Natural, Complementary<Correlative, Evaluative>>, Equate, SafeReadRelatorIncrementSingleScale<Natural, Correlative, Evaluative>>,
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
            SafeDoubleCorrelator = {
                Instantiate<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>, Adjunct>,
                Account<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
                Correspond<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>,
                Associate<DoubleComplementary<Correlative, Evaluative>, Natural, Correlative, Evaluative, Proceed<Natural, Complementary<Correlative, Evaluative>, Adjunct>, Equate, SafeReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>,
                Reassociate<Natural, Correlative, Evaluative, Equate, SafeReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>, Adjunct>,
                Disassociate<Natural, Correlative, Evaluative, ConcedeSafely<Natural, Complementary<Correlative, Evaluative>>, Equate, SafeReadRelatorIncrementDoubleScale<Natural, Correlative, Evaluative>>,
                RemoveAll<DoubleComplementary<Correlative, Evaluative>, Natural, Complementary<Correlative, Evaluative>>,
                DeleteOneNode<Natural, Complementary<Correlative, Evaluative>, Adjunct>
            };

    }

}

}

#endif
