// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_ASSOCIATION_MODULE
#define JUNCTION_ASSOCIATION_MODULE
#include "consecution.hpp"
#include "../association.hpp"
#include "../sortation.hpp"

namespace junction {

    namespace association {

        using namespace ::association;
        using namespace ::sortation;
        using namespace ::junction::consecution;

        template <
            typename Correlative,
            typename Elemental
        >
        using AssociativelyJunctional = Junctional< Associational< Correlative, Elemental > >;

        template <
            typename Correlative,
            typename Elemental
        >
        using AssociativelyPositional = Positional< Associational< Correlative, Elemental > >;

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        using AssociativelyJunctive = Junctive< Natural, Associational< Correlative, Elemental > >;

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        static inline Conferential< const Correlative >
        GoReadRelator(
            Referential< const AssociativelyJunctive< Natural, Correlative, Elemental > >
                map,
            Referential< const AssociativelyPositional< Correlative, Elemental > >
                position
        ) {
            return Confer( GoRead( map, position ).to.relator );
        }

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        static inline Conferential< const Correlative >
        GoReadRelatorSafely(
            Referential< const AssociativelyJunctive< Natural, Correlative, Elemental > >
                map,
            Referential< const AssociativelyPositional< Correlative, Elemental > >
                position
        ) {
            if (!ContainsChecksForNull( map, position ))
                throw position;
            return GoReadRelator( map, position );
        }

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        static inline Conferential< const Elemental >
        GoReadElement(
            Referential< const AssociativelyJunctive< Natural, Correlative, Elemental > >
                map,
            Referential< const AssociativelyPositional< Correlative, Elemental > >
                position
        ) {
            return Confer( GoRead( map, position ).to.value );
        }

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        static inline Conferential< const Elemental >
        GoReadElementSafely(
            Referential< const AssociativelyJunctive< Natural, Correlative, Elemental > >
                map,
            Referential< const AssociativelyPositional< Correlative, Elemental > >
                position
        ) {
            if (!ContainsChecksForNull( map, position ))
                throw position;
            return GoReadElement( map, position );
        }

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        static inline Conferential< Elemental >
        GoWriteElement(
            Referential< AssociativelyJunctive< Natural, Correlative, Elemental > >
                map,
            Referential< const AssociativelyPositional< Correlative, Elemental > >
                position
        ) {
            return Confer( GoWrite( map, position ).to.value );
        }

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        static inline Conferential< Elemental >
        GoWriteElementSafely(
            Referential< AssociativelyJunctive< Natural, Correlative, Elemental > >
                map,
            Referential< const AssociativelyPositional< Correlative, Elemental > >
                position
        ) {
            if (!ContainsChecksForNull( map, position ))
                throw position;
            return GoWriteElement( map, position );
        }

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        ReadRelatorIncrementScale = {
            BeginReadIncrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrement< Natural, Associational< Correlative, Elemental > >,
            GoReadRelator< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        SafeReadRelatorIncrementScale = {
            BeginReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoReadRelatorSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        ReadRelatorDecrementScale = {
            BeginReadDecrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrement< Natural, Associational< Correlative, Elemental > >,
            GoReadRelator< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        SafeReadRelatorDecrementScale = {
            BeginReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoReadRelatorSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        ReadElementIncrementScale = {
            BeginReadIncrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrement< Natural, Associational< Correlative, Elemental > >,
            GoReadElement< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        SafeReadElementIncrementScale = {
            BeginReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoReadElementSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        ReadElementDecrementScale = {
            BeginReadDecrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrement< Natural, Associational< Correlative, Elemental > >,
            GoReadElement< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        SafeReadElementDecrementScale = {
            BeginReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoReadElementSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        WriteElementIncrementScale = {
            BeginReadIncrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrement< Natural, Associational< Correlative, Elemental > >,
            GoWriteElement< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        SafeWriteElementIncrementScale = {
            BeginReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoWriteElementSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        WriteElementDecrementScale = {
            BeginReadDecrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrement< Natural, Associational< Correlative, Elemental > >,
            GoWriteElement< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        SafeWriteElementDecrementScale = {
            BeginReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoWriteElementSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        ReadRelatorLiner = {
            ReadRelatorIncrementScale< Natural, Correlative, Elemental >,
            ReadRelatorDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        SafeReadRelatorLiner = {
            SafeReadRelatorIncrementScale< Natural, Correlative, Elemental >,
            SafeReadRelatorDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        ReadElementLiner = {
            ReadElementIncrementScale< Natural, Correlative, Elemental >,
            ReadElementDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        SafeReadElementLiner = {
            SafeReadElementIncrementScale< Natural, Correlative, Elemental >,
            SafeReadElementDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Elemental >
        WriteElementLiner = {
            WriteElementIncrementScale< Natural, Correlative, Elemental >,
            WriteElementDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Elemental >
        SafeWriteElementLiner = {
            SafeWriteElementIncrementScale< Natural, Correlative, Elemental >,
            SafeWriteElementDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        ReadRelatorIncrementDirection = {
            ReadRelatorIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraversable< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        SafeReadRelatorIncrementDirection = {
            SafeReadRelatorIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraversableChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        ReadRelatorDecrementDirection = {
            ReadRelatorDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraversable< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        SafeReadRelatorDecrementDirection = {
            SafeReadRelatorDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraversableChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        ReadElementIncrementDirection = {
            ReadElementIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraversable< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        SafeReadElementIncrementDirection = {
            SafeReadElementIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraversableChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        ReadElementDecrementDirection = {
            ReadElementDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraversable< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        SafeReadElementDecrementDirection = {
            SafeReadElementDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraversableChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Elemental >
        WriteElementIncrementDirection = {
            WriteElementIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraversable< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Elemental >
        SafeWriteElementIncrementDirection = {
            SafeWriteElementIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraversableChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Elemental >
        WriteElementDecrementDirection = {
            WriteElementDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraversable< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Elemental >
        SafeWriteElementDecrementDirection = {
            SafeWriteElementDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraversableChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        ReadRelatorAxis = {
            ReadRelatorIncrementDirection< Natural, Correlative, Elemental >,
            ReadRelatorDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Correlative >
        SafeReadRelatorAxis = {
            SafeReadRelatorIncrementDirection< Natural, Correlative, Elemental >,
            SafeReadRelatorDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        ReadElementAxis = {
            ReadElementIncrementDirection< Natural, Correlative, Elemental >,
            ReadElementDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, const Elemental >
        SafeReadElementAxis = {
            SafeReadElementIncrementDirection< Natural, Correlative, Elemental >,
            SafeReadElementDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Elemental >
        WriteElementAxis = {
            WriteElementIncrementDirection< Natural, Correlative, Elemental >,
            WriteElementDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Elemental >
        SafeWriteElementAxis = {
            SafeWriteElementIncrementDirection< Natural, Correlative, Elemental >,
            SafeWriteElementDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr auto
        DefaultNewAssociativeAdjunct = DefaultNewAdjunct< Natural, Associational< Correlative, Elemental > >;

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr auto
        CopyNewAssociativeAdjunct = CopyNewAdjunct< Natural, Associational< Correlative, Elemental > >;

    }

}

#endif
