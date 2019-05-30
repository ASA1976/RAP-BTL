// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_COLLECTION_MODULE
#define SAFE_JUNCTION_COLLECTION_MODULE
#include "../collection.hpp"
#include "../consecution/safe.hpp"

namespace junction {

    namespace collection {

        using ::junction::consecution::PrecedeSafely;
        using ::junction::consecution::CedeSafely;
        using ::junction::consecution::ConcedeSafely;

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< SinglyJunctive< Natural, Elemental >, Natural, Elemental >
            SafeOrderedSingleComposer = {
                Instantiate< SinglyLinked< Elemental >, Natural, Elemental, Adjunct >,
                AccreditCollection< Natural, Elemental, Equate, Order, SafeReadIncrementSingleScale< Natural, Elemental > >,
                ComposeCollection<
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order, 
                    SafeReadIncrementSingleScale< Natural, Elemental > 
                >,
                RecomposeCollection<
                    Natural, 
                    Elemental, 
                    Equate, 
                    Order, 
                    SafeReadIncrementSingleScale< Natural, Elemental >,
                    Adjunct
                >,
                DiscomposeCollection<
                    Natural, 
                    Elemental, 
                    ConcedeSafely< Natural, Elemental >, 
                    Equate, 
                    Order, 
                    SafeReadIncrementSingleScale< Natural, Elemental > 
                >,
                RemoveAll< SinglyLinked< Elemental >, Natural, Elemental >,
                DeleteOneNode< Natural, Elemental, Adjunct >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Compositional< DoublyJunctive< Natural, Elemental >, Natural, Elemental >
            SafeOrderedDoubleComposer = {
                Instantiate< DoublyLinked< Elemental >, Natural, Elemental, Adjunct >,
                AccreditCollection< Natural, Elemental, Equate, Order, SafeReadDoubleLiner< Natural, Elemental > >,
                ComposeCollection<
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order, 
                    SafeReadDoubleLiner< Natural, Elemental > 
                >,
                RecomposeCollection<
                    Natural, 
                    Elemental, 
                    Equate, 
                    Order, 
                    SafeReadDoubleLiner< Natural, Elemental >,
                    Adjunct
                >,
                DiscomposeCollection< 
                    Natural, 
                    Elemental, 
                    ConcedeSafely< Natural, Elemental >, 
                    Equate, 
                    Order, 
                    SafeReadDoubleLiner< Natural, Elemental > 
                >,
                RemoveAll< DoublyLinked< Elemental >, Natural, Elemental >,
                DeleteOneNode< Natural, Elemental, Adjunct >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< SinglyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
            SafeOrderedSingleSection = {
                ComplementSelections<
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadIncrementSingleScale< Natural, Elemental >
                >,
                DifferentiateSelections< 
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadIncrementSingleScale< Natural, Elemental >
                >,
                IntersectSelections< 
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >,
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadIncrementSingleScale< Natural, Elemental >
                >,
                UniteSelections< 
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >,
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadIncrementSingleScale< Natural, Elemental >
                >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sectional< DoublyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
            SafeOrderedDoubleSection = {
                ComplementSelections<
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadDoubleLiner< Natural, Elemental >
                >,
                DifferentiateSelections< 
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadDoubleLiner< Natural, Elemental >
                >,
                IntersectSelections< 
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >,
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadDoubleLiner< Natural, Elemental >
                >,
                UniteSelections< 
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >,
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadDoubleLiner< Natural, Elemental >
                >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
            SafeOrderedSingleSelector = {
                SafeOrderedSingleComposer< Natural, Elemental, Equate, Order, Adjunct >,
                SafeOrderedSingleSection< 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Equate, 
                    Order, 
                    Adjunct 
                >,
                CollateSelection< 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadIncrementSingleScale< Natural, Elemental >
                >,
                EquateSelections< 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Elemental, 
                    Equate 
                >,
                Account< SinglyLinked< Elemental >, Natural, Elemental >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Selective< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
            SafeOrderedDoubleSelector = {
                SafeOrderedDoubleComposer< Natural, Elemental, Equate, Order, Adjunct >,
                SafeOrderedDoubleSection< 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Equate, 
                    Order, 
                    Adjunct 
                >,
                CollateSelection< 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    PrecedeSafely< Natural, Elemental, Adjunct >, 
                    CedeSafely< Natural, Elemental, Adjunct >, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order,
                    SafeReadDoubleLiner< Natural, Elemental >
                >,
                EquateSelections< 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Elemental, 
                    Equate 
                >,
                Account< DoublyLinked< Elemental >, Natural, Elemental >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Bisectional< SinglyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
            SafeSingleBisection = {
                ComplementCollections< 
                    SinglyLinked< Elemental >,
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                    Equate, 
                    Order 
                >,
                DifferentiateCollections< 
                    SinglyLinked< Elemental >,
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, true >,
                    Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                    Equate, 
                    Order 
                >,
                IntersectCollections< 
                    SinglyLinked< Elemental >,
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order 
                >,
                UniteCollections< 
                    SinglyLinked< Elemental >,
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, true >, 
                    Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                    Equate, 
                    Order 
                >
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
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Bisectional< DoublyJunctive< Natural, Elemental >, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental >
            SafeDoubleBisection = {
                ComplementCollections< 
                    DoublyLinked< Elemental >,
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                    Equate, 
                    Order 
                >,
                DifferentiateCollections< 
                    DoublyLinked< Elemental >,
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, true >,
                    Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                    Equate, 
                    Order 
                >,
                IntersectCollections< 
                    DoublyLinked< Elemental >,
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Equate, 
                    Order 
                >,
                UniteCollections< 
                    DoublyLinked< Elemental >,
                    Basic, 
                    BasicPositional, 
                    BasicNatural, 
                    Relative, 
                    RelativePositional, 
                    RelativeNatural, 
                    Natural, 
                    Elemental, 
                    Proceed< Natural, Elemental, Adjunct >, 
                    Proceed< Basic, BasicPositional, BasicNatural, Natural, Elemental, Adjunct, true >, 
                    Proceed< Relative, RelativePositional, RelativeNatural, Natural, Elemental, Adjunct, true >, 
                    Equate, 
                    Order 
                >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Collective< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
            SafeSingleCollector = {
                SafeOrderedSingleSelector< Natural, Elemental, Equate, Order, Adjunct >,
                SafeSingleBisection<
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Equate, 
                    Order, 
                    Adjunct 
                >,
                CollateCollection<
                    SinglyLinked< Elemental >,
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Proceed< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Natural, Elemental, Adjunct, true > 
                >,
                EquateCollections< 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    SinglyJunctive< Natural, Elemental >, 
                    SinglyPositional< Elemental >, 
                    Natural, 
                    Elemental, 
                    Equate 
                >
            };

        template <
            typename Natural,
            typename Elemental,
            Referential< Assortive< Elemental > >
                Equate,
            Referential< Assortive< Elemental > >
                Order,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Collective< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
            SafeDoubleCollector = {
                SafeOrderedDoubleSelector< Natural, Elemental, Equate, Order, Adjunct >,
                SafeDoubleBisection<
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Equate, 
                    Order, 
                    Adjunct 
                >,
                CollateCollection<
                    DoublyLinked< Elemental >,
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Natural, 
                    Elemental, 
                    Proceed< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Natural, Elemental, Adjunct, true > 
                >,
                EquateCollections< 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    DoublyJunctive< Natural, Elemental >, 
                    DoublyPositional< Elemental >, 
                    Natural, 
                    Elemental, 
                    Equate 
                >
            };

    }

}

#endif
