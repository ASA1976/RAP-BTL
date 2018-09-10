// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef CONTRACTION_MODULE
#define CONTRACTION_MODULE
#include "../ration.hpp"
#include "../traction.hpp"
#include "../trajection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

    namespace contraction {

        using ::location::Referential;
        using ::location::Conferential;
        using ::trajection::Vectorial;
        using ::trajection::Scalar;
        using ::trajection::Lineal;
        using ::trajection::Directional;
        using ::trajection::Axial;
        using ::traction::Tractile;
        using ::comparison::Comparison;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        struct Contractional {

            Natural
                first;

            Resourceful< Natural, Maximum, Elemental >
                resource;

        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Contractional< Natural, Maximum, Elemental >
        InitializedQueue = {
            0,
            InitializedResource< Natural, Maximum, Elemental >
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
            using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
            using ::location::Deter;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Deter( queue.resource.source[index] );
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!Contains( queue, index ))
                throw index;
            return GoRead( queue, index );
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
                queue,
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
            return count < queue.resource.allotment;
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
            index = queue.first + count;
            if (index >= Maximum)
                index -= Maximum;
            return index;
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
            if (!Begins( queue, count ))
                throw queue.allotment;
            return BeginReadIncrement( queue, index, count );
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
            index = queue.first + count;
            if (index >= Maximum)
                index -= Maximum;
            return index;
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
            if (!Begins( queue, count ))
                throw queue.allotment;
            return BeginWriteIncrement( queue, index, count );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        IncrementTraverses(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            Natural
                extent;
            extent = queue.first + queue.resource.allotment;
            if (index < queue.first) {
                if (extent <= Maximum)
                    return false;
                return index + count < extent - Maximum;
            } else {
                return index + count < extent;
            }
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
            Natural
                offset;
            offset = index + count;
            return index = offset < Maximum ? offset : offset - Maximum;
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
            if (!IncrementTraverses( queue, index, count ))
                throw count;
            return TraverseReadIncrement( queue, index, count );
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
            Natural
                offset;
            offset = index + count;
            return index = offset < Maximum ? offset : offset - Maximum;
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
            if (!IncrementTraverses( queue, index, count ))
                throw index;
            return TraverseWriteIncrement( queue, index, count );
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
            Natural
                extent;
            extent = queue.first + queue.resource.allotment;
            if (extent > Maximum)
                return index = extent - Maximum - 1 - count;
            return extent - 1 - count;
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
            if (!Begins( queue, count ))
                throw queue.allotment;
            return BeginReadDecrement( queue, index, count );
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
            Natural
                extent;
            extent = queue.first + queue.resource.allotment;
            if (extent > Maximum)
                return index = extent - Maximum - 1 - count;
            return extent - 1 - count;
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
            if (!Begins( queue, count ))
                throw queue.allotment;
            return BeginWriteDecrement( queue, index, count );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        DecrementTraverses(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (count > index)
                return Maximum + index - count >= queue.first;
            return index - count >= queue.first;
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
            return index = count > index ? Maximum + index - count : index - count;
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
            if (!DecrementTraverses( queue, index, count ))
                throw index;
            return TraverseReadDecrement( queue, index, count );
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
            return index = count > index ? Maximum + index - count : index - count;
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
            if (!DecrementTraverses( queue, index, count ))
                throw index;
            return TraverseWriteDecrement( queue, index, count );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< Contractional< Natural, Maximum, Elemental > >
        Initialize(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return queue = InitializedQueue< Natural, Maximum, Elemental >;
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return queue.resource.allotment;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        CountIncrement(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            return queue.resource.allotment - 1 - index;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        CountDecrement(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
        Protract(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            index = queue.first + queue.resource.allotment;
            if (index >= Maximum)
                index -= Maximum;
            queue.resource.allotment += count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        ProtractSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (queue.resource.allotment + count > Maximum)
                return false;
            return Protract( queue, index, count );
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
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
            Protract< Natural, Maximum, Elemental >,
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
            ProtractSafely< Natural, Maximum, Elemental >,
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
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Lineal< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Lineal< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Lineal< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Lineal< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
        ReadIncrementDirection = {
            ReadIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementTraverses< Natural, Maximum, Elemental >,
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
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
        SafeReadIncrementDirection = {
            SafeReadIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementTraverses< Natural, Maximum, Elemental >,
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
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        WriteIncrementDirection = {
            WriteIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementTraverses< Natural, Maximum, Elemental >,
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
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        SafeWriteIncrementDirection = {
            SafeWriteIncrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            IncrementTraverses< Natural, Maximum, Elemental >,
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
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
        ReadDecrementDirection = {
            ReadDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementTraverses< Natural, Maximum, Elemental >,
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
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
        SafeReadDecrementDirection = {
            SafeReadDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementTraverses< Natural, Maximum, Elemental >,
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
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        WriteDecrementDirection = {
            WriteDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementTraverses< Natural, Maximum, Elemental >,
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
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        SafeWriteDecrementDirection = {
            SafeWriteDecrementScale< Natural, Maximum, Elemental >,
            Begins< Natural, Maximum, Elemental >,
            DecrementTraverses< Natural, Maximum, Elemental >,
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
        constexpr Axial< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Axial< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
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
        constexpr Axial< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
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
        constexpr Axial< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
        SafeWriteAxis = {
            SafeWriteIncrementDirection< Natural, Maximum, Elemental >,
            SafeWriteDecrementDirection< Natural, Maximum, Elemental >
        };

    }

}

#endif
