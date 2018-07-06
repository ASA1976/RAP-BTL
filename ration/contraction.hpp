// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef CONTRACTION_MODULE
#define CONTRACTION_MODULE
#include "../ration.hpp"
#include "../traction.hpp"
#include "../trajection.hpp"

namespace ration {

    namespace contraction {

        using namespace ::traction;
        using namespace ::trajection;
        using namespace ::comparison;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        struct Contractional {

            Resourceful< Natural, Maximum, Elemental >
                resource;

            Natural
                first;

        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Contractional< Natural, Maximum, Elemental >
        InitializedQueue = {
            InitializedResource< Natural, Maximum, Elemental >,
            0
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Contains(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            const Natural
                terminal = queue.first + queue.resource.allotment;
            if (index < queue.first) {
                if (terminal <= Maximum)
                    return false;
                if (index >= terminal - Maximum)
                    return false;
            } else {
                if (index >= terminal)
                    return false;
            }
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< Elemental >
        GoWrite(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return Confer( queue.resource.source[index] );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< Elemental >
        GoWriteSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!Contains( queue, index ))
                throw index;
            return GoWrite( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< const Elemental >
        GoRead(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return Defer( queue.resource.source[index] );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< const Elemental >
        GoReadSafely(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!Contains( queue, index ))
                throw index;
            return Go( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Begins(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return queue.resource.allotment > 0;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadIncrement(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return index = queue.first;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadIncrementSafely(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!Begins( queue ))
                throw queue.allotment;
            return BeginReadIncrement( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteIncrement(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return index = queue.first;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteIncrementSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!Begins( queue ))
                throw queue.allotment;
            return BeginWriteIncrement( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        IncrementIsTraversable(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (index + 1 >= Maximum)
                return queue.first + queue.resource.allotment > Maximum;
            return index + 1 < queue.resource.allotment;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseReadIncrement(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (index + 1 >= Maximum && queue.first + queue.resource.allotment > Maximum)
                return index = 0;
            return ++index;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseReadIncrementSafely(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!IncrementIsTraversable( queue, index ))
                throw index;
            return TraverseReadIncrement( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseWriteIncrement(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (index + 1 >= Maximum && queue.first + queue.resource.allotment > Maximum)
                return index = 0;
            return ++index;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseWriteIncrementSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!IncrementIsTraversable( queue, index ))
                throw index;
            return TraverseWriteIncrement( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadDecrement(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (queue.first + queue.resource.allotment > Maximum)
                return index = queue.first + queue.resource.allotment - Maximum - 1;
            return queue.first + queue.resource.allotment - 1;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadDecrementSafely(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!Begins( queue ))
                throw queue.allotment;
            return BeginReadDecrement( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteDecrement(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (queue.first + queue.resource.allotment > Maximum)
                return index = queue.first + queue.resource.allotment - Maximum - 1;
            return queue.first + queue.resource.allotment - 1;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteDecrementSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!Begins( queue ))
                throw queue.allotment;
            return BeginWriteDecrement( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        DecrementIsTraversable(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (index == 0)
                return queue.first + queue.resource.allotment > Maximum;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseReadDecrement(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (index == 0 && queue.first + queue.resource.allotment > Maximum)
                return index = Maximum - 1;
            return --index;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseReadDecrementSafely(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!DecrementIsTraversable( queue, index ))
                throw index;
            return TraverseReadDecrement( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseWriteDecrement(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (index == 0 && queue.first + queue.resource.allotment > Maximum)
                return index = Maximum - 1;
            return --index;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseWriteDecrementSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!DecrementIsTraversable( queue, index ))
                throw index;
            return TraverseWriteDecrement( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline void
        Initialize(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            queue = InitializedQueue< Natural, Maximum, Elemental >;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Empty(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!queue.resource.allotment)
                return false;
            Initialize( queue );
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        Survey(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return Maximum;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        Account(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return queue.resource.allotment;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Contract(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            index = queue.first + queue.resource.allotment++;
            if (index >= Maximum)
                index -= Maximum;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        ContractSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (queue.resource.allotment >= Maximum)
                return false;
            return Contract( queue, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Retract(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< const Natural >
                count
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            queue.resource.allotment -= count;
            queue.first += count;
            if (queue.first >= Maximum)
                queue.first -= Maximum;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        RetractSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
            Referential< const Natural >
                count
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (count > queue.resource.allotment)
                return false;
            return Retract( queue, count );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Tractile< Contractional< Natural, Maximum, Elemental >, Natural, Natural >
        Contractor = {
            Survey< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            Contract< Natural, Maximum, Elemental >,
            Retract< Natural, Maximum, Elemental >,
            Empty< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Tractile< Contractional< Natural, Maximum, Elemental >, Natural, Natural >
        SafeContractor = {
            Survey< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            ContractSafely< Natural, Maximum, Elemental >,
            RetractSafely< Natural, Maximum, Elemental >,
            Empty< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Vectorial< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        ReadVector = {
            Comparison< Natural >,
            Contains< Natural, Maximum, Elemental >,
            GoRead< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Vectorial< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        SafeReadVector = {
            Comparison< Natural >,
            Contains< Natural, Maximum, Elemental >,
            GoReadSafely< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Vectorial< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        WriteVector = {
            Comparison< Natural >,
            Contains< Natural, Maximum, Elemental >,
            GoWrite< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Vectorial< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        SafeWriteVector = {
            Comparison< Natural >,
            Contains< Natural, Maximum, Elemental >,
            GoWriteSafely< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        ReadIncrementScale = {
            Comparison< Natural >,
            BeginReadIncrement< Natural, Maximum, Elemental >,
            TraverseReadIncrement< Natural, Maximum, Elemental >,
            GoRead< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        SafeReadIncrementScale = {
            Comparison< Natural >,
            BeginReadIncrementSafely< Natural, Maximum, Elemental >,
            TraverseReadIncrementSafely< Natural, Maximum, Elemental >,
            GoReadSafely< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        WriteIncrementScale = {
            Comparison< Natural >,
            BeginWriteIncrement< Natural, Maximum, Elemental >,
            TraverseWriteIncrement< Natural, Maximum, Elemental >,
            GoWrite< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        SafeWriteIncrementScale = {
            Comparison< Natural >,
            BeginWriteIncrementSafely< Natural, Maximum, Elemental >,
            TraverseWriteIncrementSafely< Natural, Maximum, Elemental >,
            GoWriteSafely< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        ReadDecrementScale = {
            Comparison< Natural >,
            BeginReadDecrement< Natural, Maximum, Elemental >,
            TraverseReadDecrement< Natural, Maximum, Elemental >,
            GoRead< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        SafeReadDecrementScale = {
            Comparison< Natural >,
            BeginReadDecrementSafely< Natural, Maximum, Elemental >,
            TraverseReadDecrementSafely< Natural, Maximum, Elemental >,
            GoReadSafely< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        WriteDecrementScale = {
            Comparison< Natural >,
            BeginWriteDecrement< Natural, Maximum, Elemental >,
            TraverseWriteDecrement< Natural, Maximum, Elemental >,
            GoWrite< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        SafeWriteDecrementScale = {
            Comparison< Natural >,
            BeginWriteDecrementSafely< Natural, Maximum, Elemental >,
            TraverseWriteDecrementSafely< Natural, Maximum, Elemental >,
            GoWriteSafely< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Lineal< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        ReadLiner = {
            ReadIncrementScale< Natural, Maximum, Elemental >,
            ReadDecrementScale< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Lineal< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        SafeReadLiner = {
            SafeReadIncrementScale< Natural, Maximum, Elemental >,
            SafeReadDecrementScale< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Lineal< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        WriteLiner = {
            WriteIncrementScale< Natural, Maximum, Elemental >,
            WriteDecrementScale< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Lineal< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        SafeWriteLiner = {
            SafeWriteIncrementScale< Natural, Maximum, Elemental >,
            SafeWriteDecrementScale< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        ReadIncrementDirection = {
            ReadIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementIsTraversable< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        SafeReadIncrementDirection = {
            SafeReadIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementIsTraversable< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        WriteIncrementDirection = {
            WriteIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementIsTraversable< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        SafeWriteIncrementDirection = {
            SafeWriteIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementIsTraversable< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        ReadDecrementDirection = {
            ReadDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementIsTraversable< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        SafeReadDecrementDirection = {
            SafeReadDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementIsTraversable< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        WriteDecrementDirection = {
            WriteDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementIsTraversable< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        SafeWriteDecrementDirection = {
            SafeWriteDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementIsTraversable< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Axial< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        ReadAxis = {
            ReadIncrementDirection< Natural, Maximum, Elemental >,
            ReadDecrementDirection< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Axial< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
        SafeReadAxis = {
            SafeReadIncrementDirection< Natural, Maximum, Elemental >,
            SafeReadDecrementDirection< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Axial< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        WriteAxis = {
            WriteIncrementDirection< Natural, Maximum, Elemental >,
            WriteDecrementDirection< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Axial< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
        SafeWriteAxis = {
            SafeWriteIncrementDirection< Natural, Maximum, Elemental >,
            SafeWriteDecrementDirection< Natural, Maximum, Elemental >
        };

    }

}

#endif
