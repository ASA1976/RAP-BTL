// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ELEVATION_MODULE
#define ELEVATION_MODULE
#include "../ration.hpp"
#include "../traction.hpp"
#include "../trajection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Deter( stack.source[index] );
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
                stack,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return count < stack.allotment;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index = count;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                StackBegins = Begins< Natural, Maximum, Elemental >;
            static auto&
                Begin = BeginReadIncrement< Natural, Maximum, Elemental >;
            if (!StackBegins( stack, count ))
                throw stack.allotment;
            return Begin( stack, index, count );
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index = count;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                StackBegins = Begins< Natural, Maximum, Elemental >;
            static auto&
                Begin = BeginWriteIncrement< Natural, Maximum, Elemental >;
            if (!StackBegins( stack, count ))
                throw stack.allotment;
            return Begin( stack, index, count );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        IncrementIsTraverses(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index + count < stack.allotment;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index += count;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                IsTraverses = IncrementIsTraverses< Natural, Maximum, Elemental >;
            static auto&
                Traverse = TraverseReadIncrement< Natural, Maximum, Elemental >;
            if (!IsTraverses( stack, index, count ))
                throw index;
            return Traverse( stack, index, count );
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index += count;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                IsTraverses = IncrementIsTraverses< Natural, Maximum, Elemental >;
            static auto&
                Traverse = TraverseWriteIncrement< Natural, Maximum, Elemental >;
            if (!IsTraverses( stack, index, count ))
                throw index;
            return Traverse( stack, index, count );
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index = stack.allotment - 1 - count;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                StackBegins = Begins< Natural, Maximum, Elemental >;
            static auto&
                Begin = BeginReadDecrement< Natural, Maximum, Elemental >;
            if (!StackBegins( stack, count ))
                throw stack.allotment;
            return Begin( stack, index, count );
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index = stack.allotment - 1 - count;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                StackBegins = Begins< Natural, Maximum, Elemental >;
            static auto&
                Begin = BeginWriteDecrement< Natural, Maximum, Elemental >;
            if (!StackBegins( stack, count ))
                throw stack.allotment;
            return Begin( stack, index, count );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        DecrementIsTraverses(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return count <= index;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index -= count;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                IsTraverses = DecrementIsTraverses< Natural, Maximum, Elemental >;
            static auto&
                Traverse = TraverseReadDecrement< Natural, Maximum, Elemental >;
            if (!IsTraverses( stack, index, count ))
                throw index;
            return Traverse( stack, index, count );
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index -= count;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                IsTraverses = DecrementIsTraverses< Natural, Maximum, Elemental >;
            static auto&
                Traverse = TraverseWriteDecrement< Natural, Maximum, Elemental >;
            if (!IsTraverses( stack, index, count ))
                throw index;
            return Traverse( stack, index, count );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< Elevatory< Natural, Maximum, Elemental > >
        Initialize(
            Referential< Elevatory< Natural, Maximum, Elemental > >
                stack
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return stack = InitializedStack< Natural, Maximum, Elemental >;
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return stack.allotment;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        CountIncrement(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return stack.allotment - 1 - index;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        CountDecrement(
            Referential< const Elevatory< Natural, Maximum, Elemental > >
                stack,
            Referential< const Natural >
                index
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return index;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            index = stack.allotment;
            stack.allotment += count;
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
                index,
            Referential< const Natural >
                count
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            static auto&
                IncreaseStack = Increase< Natural, Maximum, Elemental >;
            if (stack.allotment + count > Maximum)
                return false;
            return IncreaseStack( stack, index, count );
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
        constexpr Scalar< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Scalar< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Scalar< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Scalar< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Scalar< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Scalar< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Scalar< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Scalar< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Lineal< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Lineal< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Lineal< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Lineal< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Directional< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
        ReadIncrementDirection = {
            ReadIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementIsTraverses< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            CountIncrement< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
        SafeReadIncrementDirection = {
            SafeReadIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementIsTraverses< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            CountIncrement< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        WriteIncrementDirection = {
            WriteIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementIsTraverses< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            CountIncrement< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        SafeWriteIncrementDirection = {
            SafeWriteIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementIsTraverses< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            CountIncrement< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
        ReadDecrementDirection = {
            ReadDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementIsTraverses< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            CountDecrement< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
        SafeReadDecrementDirection = {
            SafeReadDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementIsTraverses< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            CountDecrement< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        WriteDecrementDirection = {
            WriteDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementIsTraverses< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            CountDecrement< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        SafeWriteDecrementDirection = {
            SafeWriteDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementIsTraverses< Natural, Maximum, Elemental >,
            Contains< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            CountDecrement< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Axial< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Axial< const Elevatory< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Axial< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Axial< Elevatory< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        SafeWriteAxis = {
            SafeWriteIncrementDirection< Natural, Maximum, Elemental >,
            SafeWriteDecrementDirection< Natural, Maximum, Elemental >
        };

    }

}

#endif
