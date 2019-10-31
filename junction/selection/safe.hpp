// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_SELECTION_MODULE
#define SAFE_JUNCTION_SELECTION_MODULE
#include "../consecution/safe.hpp"
#include "../selection.hpp"

namespace junction {

namespace selection {

    using ::junction::consecution::ConcedeSafely;
    using ::junction::consecution::SucceedSafely;

    template <
        typename Natural,
        typename Elemental,
        Referential<Assortive<Elemental>>
            Equate,
        Referential<const SinglyAdjunctive<Natural, Elemental>>
            Adjunct>
    constexpr Compositional<SinglyJunctive<Natural, Elemental>, Natural, Elemental>
        SafeSingleComposer = {
            Instantiate<SinglyLinked<Elemental>, Natural, Elemental, Adjunct>,
            AccreditSelection<
                SinglyLinked<Elemental>,
                Natural,
                Elemental,
                Equate,
                SafeReadIncrementSingleScale<Natural, Elemental>>,
            ComposeSelection<
                SinglyLinked<Elemental>,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate,
                SafeReadIncrementSingleScale<Natural, Elemental>>,
            RecomposeSelection<
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                SucceedSafely<Natural, Elemental>,
                Equate,
                SafeReadIncrementSingleScale<Natural, Elemental>>,
            DiscomposeSelection<
                Natural,
                Elemental,
                SucceedSafely<Natural, Elemental>,
                Equate,
                SafeReadIncrementSingleScale<Natural, Elemental>>,
            RemoveAll<SinglyLinked<Elemental>, Natural, Elemental>,
            DeleteOneNode<Natural, Elemental, Adjunct>
        };

    template <
        typename Natural,
        typename Elemental,
        Referential<Assortive<Elemental>>
            Equate,
        Referential<const DoublyAdjunctive<Natural, Elemental>>
            Adjunct>
    constexpr Compositional<DoublyJunctive<Natural, Elemental>, Natural, Elemental>
        SafeDoubleComposer = {
            Instantiate<DoublyLinked<Elemental>, Natural, Elemental, Adjunct>,
            AccreditSelection<
                DoublyLinked<Elemental>,
                Natural,
                Elemental,
                Equate,
                SafeReadIncrementDoubleScale<Natural, Elemental>>,
            ComposeSelection<
                DoublyLinked<Elemental>,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate,
                SafeReadIncrementDoubleScale<Natural, Elemental>>,
            RecomposeSelection<
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                SucceedSafely<Natural, Elemental>,
                Equate,
                SafeReadIncrementDoubleScale<Natural, Elemental>>,
            DiscomposeSelection<
                Natural,
                Elemental,
                SucceedSafely<Natural, Elemental>,
                Equate,
                SafeReadIncrementDoubleScale<Natural, Elemental>>,
            RemoveAll<DoublyLinked<Elemental>, Natural, Elemental>,
            DeleteOneNode<Natural, Elemental, Adjunct>
        };

    template <
        typename Basic,
        typename BasicPositional,
        typename BasicNatural,
        typename Relative,
        typename RelativePositional,
        typename RelativeNatural,
        typename Natural,
        typename Elemental,
        Referential<Assortive<Elemental>>
            Equate,
        Referential<const SinglyAdjunctive<Natural, Elemental>>
            Adjunct>
    constexpr Sectional<SinglyJunctive<Natural, Elemental>, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental>
        SafeSingleSection = {
            ComplementSelections<
                SinglyLinked<Elemental>,
                Basic,
                BasicPositional,
                BasicNatural,
                Relative,
                RelativePositional,
                RelativeNatural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate>,
            DifferentiateSelections<
                SinglyLinked<Elemental>,
                Basic,
                BasicPositional,
                BasicNatural,
                Relative,
                RelativePositional,
                RelativeNatural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate>,
            IntersectSelections<
                SinglyLinked<Elemental>,
                Basic,
                BasicPositional,
                BasicNatural,
                Relative,
                RelativePositional,
                RelativeNatural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate>,
            UniteSelections<
                SinglyLinked<Elemental>,
                Basic,
                BasicPositional,
                BasicNatural,
                Relative,
                RelativePositional,
                RelativeNatural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate>
        };

    template <
        typename Basic,
        typename BasicPositional,
        typename BasicNatural,
        typename Relative,
        typename RelativePositional,
        typename RelativeNatural,
        typename Natural,
        typename Elemental,
        Referential<Assortive<Elemental>>
            Equate,
        Referential<const DoublyAdjunctive<Natural, Elemental>>
            Adjunct>
    constexpr Sectional<DoublyJunctive<Natural, Elemental>, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental>
        SafeDoubleSection = {
            ComplementSelections<
                DoublyLinked<Elemental>,
                Basic,
                BasicPositional,
                BasicNatural,
                Relative,
                RelativePositional,
                RelativeNatural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate>,
            DifferentiateSelections<
                DoublyLinked<Elemental>,
                Basic,
                BasicPositional,
                BasicNatural,
                Relative,
                RelativePositional,
                RelativeNatural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate>,
            IntersectSelections<
                DoublyLinked<Elemental>,
                Basic,
                BasicPositional,
                BasicNatural,
                Relative,
                RelativePositional,
                RelativeNatural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate>,
            UniteSelections<
                DoublyLinked<Elemental>,
                Basic,
                BasicPositional,
                BasicNatural,
                Relative,
                RelativePositional,
                RelativeNatural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>,
                Equate>
        };

    template <
        typename Natural,
        typename Elemental,
        Referential<Assortive<Elemental>>
            Equate,
        Referential<const SinglyAdjunctive<Natural, Elemental>>
            Adjunct>
    constexpr Selective<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural, Elemental>
        SafeSingleSelector = {
            SafeSingleComposer<Natural, Elemental, Equate, Adjunct>,
            SafeSingleSection<
                SinglyJunctive<Natural, Elemental>,
                SinglyPositional<Elemental>,
                Natural,
                SinglyJunctive<Natural, Elemental>,
                SinglyPositional<Elemental>,
                Natural,
                Natural,
                Elemental,
                Equate,
                Adjunct>,
            DuplicateSelection<
                SinglyLinked<Elemental>,
                SinglyJunctive<Natural, Elemental>,
                SinglyPositional<Elemental>,
                Natural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>>,
            EquateSelections<
                SinglyJunctive<Natural, Elemental>,
                SinglyPositional<Elemental>,
                Natural,
                SinglyJunctive<Natural, Elemental>,
                SinglyPositional<Elemental>,
                Natural,
                Elemental,
                Equate>,
            Account<SinglyLinked<Elemental>, Natural, Elemental>
        };

    template <
        typename Natural,
        typename Elemental,
        Referential<Assortive<Elemental>>
            Equate,
        Referential<const DoublyAdjunctive<Natural, Elemental>>
            Adjunct>
    constexpr Selective<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural, Elemental>
        SafeDoubleSelector = {
            SafeDoubleComposer<Natural, Elemental, Equate, Adjunct>,
            SafeDoubleSection<
                DoublyJunctive<Natural, Elemental>,
                DoublyPositional<Elemental>,
                Natural,
                DoublyJunctive<Natural, Elemental>,
                DoublyPositional<Elemental>,
                Natural,
                Natural,
                Elemental,
                Equate,
                Adjunct>,
            DuplicateSelection<
                DoublyLinked<Elemental>,
                DoublyJunctive<Natural, Elemental>,
                DoublyPositional<Elemental>,
                Natural,
                Natural,
                Elemental,
                Proceed<Natural, Elemental, Adjunct>>,
            EquateSelections<
                DoublyJunctive<Natural, Elemental>,
                DoublyPositional<Elemental>,
                Natural,
                DoublyJunctive<Natural, Elemental>,
                DoublyPositional<Elemental>,
                Natural,
                Elemental,
                Equate>,
            Account<DoublyLinked<Elemental>, Natural, Elemental>
        };

}

}

#endif
