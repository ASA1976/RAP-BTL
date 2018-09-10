// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_ASSOCIATION_MODULE
#define JUNCTION_ASSOCIATION_MODULE
//#include "consecution.hpp"
#include "../association.hpp"
//#include "../sortation.hpp"

namespace junction {

    namespace association {

        using ::association::Associative;
        using ::association::Associational;

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
            using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
            using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!ContainsChecksForNull( map, position ))
                throw position;
            return GoWriteElement( map, position );
        }

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        ReadRelatorIncrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadIncrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrement< Natural, Associational< Correlative, Elemental > >,
            GoReadRelator< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        SafeReadRelatorIncrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoReadRelatorSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        ReadRelatorDecrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadDecrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrement< Natural, Associational< Correlative, Elemental > >,
            GoReadRelator< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        SafeReadRelatorDecrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoReadRelatorSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        ReadElementIncrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadIncrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrement< Natural, Associational< Correlative, Elemental > >,
            GoReadElement< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        SafeReadElementIncrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoReadElementSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        ReadElementDecrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadDecrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrement< Natural, Associational< Correlative, Elemental > >,
            GoReadElement< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        SafeReadElementDecrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoReadElementSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        WriteElementIncrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadIncrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrement< Natural, Associational< Correlative, Elemental > >,
            GoWriteElement< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        SafeWriteElementIncrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadIncrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoWriteElementSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        WriteElementDecrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadDecrement< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrement< Natural, Associational< Correlative, Elemental > >,
            GoWriteElement< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Scalar< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        SafeWriteElementDecrementScale = {
            Comparison< Associational< Correlative, Elemental > >,
            BeginReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            TraverseReadDecrementSafely< Natural, Associational< Correlative, Elemental > >,
            GoWriteElementSafely< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        ReadRelatorLiner = {
            ReadRelatorIncrementScale< Natural, Correlative, Elemental >,
            ReadRelatorDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        SafeReadRelatorLiner = {
            SafeReadRelatorIncrementScale< Natural, Correlative, Elemental >,
            SafeReadRelatorDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        ReadElementLiner = {
            ReadElementIncrementScale< Natural, Correlative, Elemental >,
            ReadElementDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        SafeReadElementLiner = {
            SafeReadElementIncrementScale< Natural, Correlative, Elemental >,
            SafeReadElementDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Elemental >
        WriteElementLiner = {
            WriteElementIncrementScale< Natural, Correlative, Elemental >,
            WriteElementDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Lineal< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Elemental >
        SafeWriteElementLiner = {
            SafeWriteElementIncrementScale< Natural, Correlative, Elemental >,
            SafeWriteElementDecrementScale< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        ReadRelatorIncrementDirection = {
            ReadRelatorIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraverses< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        SafeReadRelatorIncrementDirection = {
            SafeReadRelatorIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraversesChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        ReadRelatorDecrementDirection = {
            ReadRelatorDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraverses< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        SafeReadRelatorDecrementDirection = {
            SafeReadRelatorDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraversesChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        ReadElementIncrementDirection = {
            ReadElementIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraverses< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        SafeReadElementIncrementDirection = {
            SafeReadElementIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraversesChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        ReadElementDecrementDirection = {
            ReadElementDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraverses< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        SafeReadElementDecrementDirection = {
            SafeReadElementDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraversesChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Elemental >
        WriteElementIncrementDirection = {
            WriteElementIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraverses< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Elemental >
        SafeWriteElementIncrementDirection = {
            SafeWriteElementIncrementScale< Natural, Correlative, Elemental >,
            IncrementBegins< Natural, Associational< Correlative, Elemental > >,
            IncrementTraversesChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Elemental >
        WriteElementDecrementDirection = {
            WriteElementDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraverses< Natural, Associational< Correlative, Elemental > >,
            Contains< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Directional< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Elemental >
        SafeWriteElementDecrementDirection = {
            SafeWriteElementDecrementScale< Natural, Correlative, Elemental >,
            DecrementBegins< Natural, Associational< Correlative, Elemental > >,
            DecrementTraversesChecksForNull< Natural, Associational< Correlative, Elemental > >,
            ContainsChecksForNull< Natural, Associational< Correlative, Elemental > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        ReadRelatorAxis = {
            ReadRelatorIncrementDirection< Natural, Correlative, Elemental >,
            ReadRelatorDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Correlative >
        SafeReadRelatorAxis = {
            SafeReadRelatorIncrementDirection< Natural, Correlative, Elemental >,
            SafeReadRelatorDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        ReadElementAxis = {
            ReadElementIncrementDirection< Natural, Correlative, Elemental >,
            ReadElementDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< const AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, const Elemental >
        SafeReadElementAxis = {
            SafeReadElementIncrementDirection< Natural, Correlative, Elemental >,
            SafeReadElementDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Elemental >
        WriteElementAxis = {
            WriteElementIncrementDirection< Natural, Correlative, Elemental >,
            WriteElementDecrementDirection< Natural, Correlative, Elemental >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Elemental
        >
        constexpr Axial< AssociativelyJunctive< Natural, Correlative, Elemental >, AssociativelyPositional< Correlative, Elemental >, Natural, Elemental >
        SafeWriteElementAxis = {
            SafeWriteElementIncrementDirection< Natural, Correlative, Elemental >,
            SafeWriteElementDecrementDirection< Natural, Correlative, Elemental >
        };

    }

}

#endif
