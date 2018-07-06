// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ELEVATION_MODULE
#define ELEVATION_MODULE
#include "../ration.hpp"
#include "../traction.hpp"
#include "../trajection.hpp"

namespace ration {

    namespace elevation {

        using namespace ::traction;
        using namespace ::trajection;
        using namespace ::comparison;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        using Elevatory = Resourceful< Natural, Maximum, Elemental >;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Elevatory< Natural, Maximum, Elemental >
        InitializedStack = InitializedResource< Natural, Maximum, Elemental >;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Contains(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return index < stack.allotment;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< Elemental >
        GoWrite(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return Confer( stack.source[index] );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< Elemental >
        GoWriteSafely(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                StackContains = Contains< Natural, Maximum, Elemental >;
            static auto&
                Go = GoWrite< Natural, Maximum, Elemental >;
            if (!StackContains( stack, index ))
                throw index;
            return Go( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< const Elemental >
        GoRead(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return Defer( stack.source[index] );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< const Elemental >
        GoReadSafely(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                StackContains = Contains< Natural, Maximum, Elemental >;
            static auto&
                Go = GoRead< Natural, Maximum, Elemental >;
            if (!StackContains( stack, index ))
                throw index;
            return Go( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Begins(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return stack.allotment > 0;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadIncrement(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return index = 0;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadIncrementSafely(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                StackBegins = Begins< Natural, Maximum, Elemental >;
            static auto&
                Begin = BeginReadIncrement< Natural, Maximum, Elemental >;
            if (!StackBegins( stack ))
                throw stack.allotment;
            return Begin( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteIncrement(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return index = 0;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteIncrementSafely(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                StackBegins = Begins< Natural, Maximum, Elemental >;
            static auto&
                Begin = BeginWriteIncrement< Natural, Maximum, Elemental >;
            if (!StackBegins( stack ))
                throw stack.allotment;
            return Begin( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        IncrementIsTraversable(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return index + 1 < stack.allotment;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseReadIncrement(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
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
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                IsTraversable = IncrementIsTraversable< Natural, Maximum, Elemental >;
            static auto&
                Traverse = TraverseReadIncrement< Natural, Maximum, Elemental >;
            if (!IsTraversable( stack, index ))
                throw index;
            return Traverse( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseWriteIncrement(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
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
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                IsTraversable = IncrementIsTraversable< Natural, Maximum, Elemental >;
            static auto&
                Traverse = TraverseWriteIncrement< Natural, Maximum, Elemental >;
            if (!IsTraversable( stack, index ))
                throw index;
            return Traverse( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadDecrement(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return index = stack.allotment - 1;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadDecrementSafely(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                StackBegins = Begins< Natural, Maximum, Elemental >;
            static auto&
                Begin = BeginReadDecrement< Natural, Maximum, Elemental >;
            if (!StackBegins( stack ))
                throw stack.allotment;
            return Begin( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteDecrement(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return index = stack.allotment - 1;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteDecrementSafely(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                StackBegins = Begins< Natural, Maximum, Elemental >;
            static auto&
                Begin = BeginWriteDecrement< Natural, Maximum, Elemental >;
            if (!StackBegins( stack ))
                throw stack.allotment;
            return Begin( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        DecrementIsTraversable(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return index > 0;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseReadDecrement(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
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
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                IsTraversable = DecrementIsTraversable< Natural, Maximum, Elemental >;
            static auto&
                Traverse = TraverseReadDecrement< Natural, Maximum, Elemental >;
            if (!IsTraversable( stack, index ))
                throw index;
            return Traverse( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseWriteDecrement(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
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
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                IsTraversable = DecrementIsTraversable< Natural, Maximum, Elemental >;
            static auto&
                Traverse = TraverseWriteDecrement< Natural, Maximum, Elemental >;
            if (!IsTraversable( stack, index ))
                throw index;
            return Traverse( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline void
        Initialize(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            stack = InitializedStack< Natural, Maximum, Elemental >;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Empty(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!stack.allotment)
                return false;
            Initialize( stack );
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
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack
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
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return stack.allotment;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Increase(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            index = stack.allotment++;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        IncreaseSafely(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                IncreaseStack = Increase< Natural, Maximum, Elemental >;
            if (stack.allotment >= Maximum)
                return false;
            return IncreaseStack( stack, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Decrease(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                count
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            stack.allotment -= count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        DecreaseSafely(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                count
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                DecreaseStack = Decrease< Natural, Maximum, Elemental >;
            if (count > stack.allotment)
                return false;
            return DecreaseStack( stack, count );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Tractile< Elevatory< Natural, Maximum, Elemental >, Natural, Natural >
        Elevator = {
            Survey< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            Increase< Natural, Maximum, Elemental >,
            Decrease< Natural, Maximum, Elemental >,
            Empty< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Tractile< Elevatory< Natural, Maximum, Elemental >, Natural, Natural >
        SafeElevator = {
            Survey< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            IncreaseSafely< Natural, Maximum, Elemental >,
            DecreaseSafely< Natural, Maximum, Elemental >,
            Empty< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Vectorial< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Vectorial< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Vectorial< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Vectorial< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Scalar< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Scalar< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Scalar< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Scalar< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Scalar< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Scalar< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Scalar< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Scalar< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Lineal< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Lineal< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Lineal< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Lineal< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Directional< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Directional< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Directional< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Directional< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Directional< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Directional< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Directional< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Directional< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Axial< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Axial< const Elevatory< Natural, Maximum, Elemental >, Natural, const Elemental >
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
        constexpr Axial< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
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
        constexpr Axial< Elevatory< Natural, Maximum, Elemental >, Natural, Elemental >
        SafeWriteAxis = {
            SafeWriteIncrementDirection< Natural, Maximum, Elemental >,
            SafeWriteDecrementDirection< Natural, Maximum, Elemental >
        };

    }

}

#endif
