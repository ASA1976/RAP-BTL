// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_CONSECUTION_MODULE
#define RATION_CONSECUTION_MODULE
#include "../consecution.hpp"
#include "../ration.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

    /**
     * @brief         
     *     Array sequence management implementation.
     * @details       
     *     Association
     *     -----------
     *     Array sequence management implementation.
     */
    namespace consecution {

        using ::location::Referential;
        using ::location::Locational;
        using ::location::Conferential;
        using ::trajection::Scalar;
        using ::trajection::Lineal;
        using ::trajection::Directional;
        using ::trajection::Axial;
        using ::consecution::Conjoint;
        using ::consecution::Sequent;
        using ::comparison::Comparison;

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental
        >
        using Compact = Resourceful< Natural, Length, Elemental >;

        template <
            typename Elemental
        >
        using ReadPositional = Locational< const Elemental >;

        template <
            typename Elemental
        >
        using WritePositional = Locational< Elemental >;

        template <
            typename Natural,
            typename Elemental
        >
        using MemoryMoving = bool(
            Locational< Elemental >,
            Locational< Elemental >,
            Natural
        );

        template <
            typename Natural,
            typename Elemental
        >
        static inline bool
        MoveElements(
            WritePositional< Elemental >
                from,
            WritePositional< Elemental >
                to,
            Natural
                count
        ) {
            Natural 
                index;
            if (from < to)
                for (index = count; index > 0; index--) {
                    const Natural offset = index - 1;
                    to[offset] = from[offset];
                }
            else
                for (index = 0; index < count; index++)
                    to[index] = from[index];
            return true;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental
        >
        static inline Referential< Compact< Natural, Length, Elemental >>
        Initialize(
            Referential< Compact< Natural, Length, Elemental > >
                sequence
        ) {
            sequence.allotment = 0;
            return sequence;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental
        >
        static inline bool
        Instantiate(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const Natural >
                count
        ) {
            return false;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental
        >
        static inline Natural
        Account(
            Referential< const Compact< Natural, Length, Elemental > >
                sequence
        ) {
            return sequence.allotment;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        CountIncrement(
            Referential< const Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< const ReadPositional< Elemental > >
                position
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return static_cast<Natural>(sequence.source + sequence.allotment - 1 - position);
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        CountDecrement(
            Referential< const Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< const ReadPositional< Elemental > >
                position
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return static_cast<Natural>(position - sequence.source);
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Begins(
            Referential< const Compact< Natural, Maximum, Elemental > >
                sequence,
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
            return count < sequence.allotment;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Meets(
            Referential< const Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< const ReadPositional< Elemental > >
                position
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (sequence.allotment < 1)
                return false;
            return sequence.source <= position && position <= sequence.source + sequence.allotment - 1;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< Elemental >
        GoWrite(
            Referential< Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< const WritePositional< Elemental > >
                position
        ) {
            using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Refer( position );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< const Elemental >
        GoRead(
            Referential< const Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< const ReadPositional< Elemental > >
                position
        ) {
            using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Refer( position );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const ReadPositional< Elemental > >
        BeginReadIncrement(
            Referential< const Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< ReadPositional< Elemental > >
                position,
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
            return position = sequence.source + count;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const WritePositional< Elemental > >
        BeginWriteIncrement(
            Referential< Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< WritePositional< Elemental > >
                position,
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
            return position = sequence.source + count;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        IncrementTraverses(
            Referential< const Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< const ReadPositional< Elemental > >
                position,
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
            if (sequence.allotment < 1)
                return false;
            return position + count <= sequence.source + sequence.allotment - 1;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const ReadPositional< Elemental > >
        TraverseReadIncrement(
            Referential< const Compact< Natural, Maximum, Elemental > >
                stack,
            Referential< ReadPositional< Elemental > >
                position,
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
            return position += count;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const WritePositional< Elemental > >
        TraverseWriteIncrement(
            Referential< Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< WritePositional< Elemental > >
                position,
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
            return position += count;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const ReadPositional< Elemental > >
        BeginReadDecrement(
            Referential< const Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< ReadPositional< Elemental > >
                position,
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
            return position = sequence.source + sequence.allotment - count - 1;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const WritePositional< Elemental > >
        BeginWriteDecrement(
            Referential< Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< WritePositional< Elemental > >
                position,
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
            return position = sequence.source + sequence.allotment - count - 1;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        DecrementTraverses(
            Referential< const Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< const ReadPositional< Elemental > >
                position,
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
            if (sequence.allotment < 1)
                return false;
            return sequence.source <= position - count;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const ReadPositional< Elemental > >
        TraverseReadDecrement(
            Referential< const Compact< Natural, Maximum, Elemental > >
                stack,
            Referential< ReadPositional< Elemental > >
                position,
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
            return position -= count;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< const WritePositional< Elemental > >
        TraverseWriteDecrement(
            Referential< Compact< Natural, Maximum, Elemental > >
                sequence,
            Referential< WritePositional< Elemental > >
                position,
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
            return position -= count;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        static inline bool
        Accede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const Elemental >
                value
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!Move( sequence.source, sequence.source + 1, sequence.allotment ))
                return false;
            sequence.source[0] = value;
            sequence.allotment++;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        static inline bool
        Accede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const Directional< const Relative, Appositional, RelativeNatural, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
                "RelativeNatural:  Unsigned integer type required"
            );
#endif
            Appositional
                apposition = from;
            Natural
                count = 1;
            while (direction.scale.order.equality.is_not_equal( apposition, to )) {
                direction.scale.traverse( space, apposition, 1 );
                count++;
            }
            if (!Move( sequence.source, sequence.source + count, sequence.allotment ))
                return false;
            apposition = from;
            for (Natural offset = 0; offset < count; offset++) {
                sequence.source[offset] = direction.scale.go( space, apposition ).to;
                direction.scale.traverse( space, apposition, 1 );
            }
            sequence.allotment += count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        static inline bool
        Precede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const WritePositional< Elemental > >
                rank,
            Referential< const Elemental >
                value
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            using namespace ::location;
            const Natural
                index = static_cast<Natural>(rank - sequence.source);
            if (index < sequence.allotment)
                if (!Move( rank, rank + 1, sequence.allotment - index ))
                    return false;
            Refer( rank ).to = value;
            sequence.allotment++;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        static inline bool
        Precede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const WritePositional< Elemental > >
                rank,
            Referential< const Directional< const Relative, Appositional, RelativeNatural, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
                "RelativeNatural:  Unsigned integer type required"
            );
#endif
            Appositional
                apposition = from;
            Natural
                count = 1;
            const Natural
                remaining = sequence.allotment - static_cast<Natural>(rank - sequence.source);
            while (direction.scale.order.equality.is_not_equal( apposition, to )) {
                direction.scale.traverse( space, apposition, 1 );
                count++;
            }
            if (!Move( rank, rank + count, remaining ))
                return false;
            apposition = from;
            for (Natural offset = 0; offset < count; offset++) {
                rank[offset] = direction.scale.go( space, apposition ).to;
                direction.scale.traverse( space, apposition, 1 );
            }
            sequence.allotment += count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        static inline bool
        Cede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const WritePositional< Elemental > >
                rank,
            Referential< const Elemental >
                value
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            using namespace ::location;
            const Natural
                index = static_cast<Natural>(rank + 1 - sequence.source);
            if (index < sequence.allotment)
                if (!Move( rank + 1, rank + 2, sequence.allotment - index ))
                    return false;
            Refer( rank ).to = value;
            sequence.allotment++;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        static inline bool
        Cede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const WritePositional< Elemental > >
                rank,
            Referential< const Directional< const Relative, Appositional, RelativeNatural, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
                "RelativeNatural:  Unsigned integer type required"
            );
#endif
            Appositional
                apposition = from;
            Natural
                count = 1;
            const WritePositional< Elemental >
                first = rank + 1;
            const Natural
                remaining = sequence.allotment - static_cast<Natural>(first - sequence.source);
            while (direction.scale.order.equality.is_not_equal( apposition, to )) {
                direction.scale.traverse( space, apposition, 1 );
                count++;
            }
            if (!Move( first, first + count, remaining ))
                return false;
            apposition = from;
            for (Natural offset = 0; offset < count; offset++) {
                first[offset] = direction.scale.go( space, apposition ).to;
                direction.scale.traverse( space, apposition, 1 );
            }
            sequence.allotment += count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental
        >
        static inline bool
        Proceed(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const Elemental >
                value
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            sequence.source[sequence.allotment++] = value;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            Natural
                Length,
            typename Elemental
        >
        static inline bool
        Proceed(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const Directional< const Relative, Appositional, RelativeNatural, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static_assert(
                is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
                "RelativeNatural:  Unsigned integer type required"
            );
#endif
            Appositional
                apposition = from;
            sequence.source[sequence.allotment++] = direction.scale.go( space, apposition ).to;
            while (direction.scale.order.equality.is_not_equal( apposition, to )) {
                direction.scale.traverse( space, apposition, 1 );
                sequence.source[sequence.allotment++] = direction.scale.go( space, apposition ).to;
            }
            return true;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        static inline bool
        Succeed(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
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
            const Natural
                remaining = sequence.allotment - count;
            if (remaining > 0) {
                if (!Move( sequence.source + count, sequence.source, remaining ))
                    return false;
            }
            sequence.allotment -= count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        static inline bool
        Supersede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const WritePositional< Elemental > >
                rank,
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
            using namespace ::location;
            const WritePositional< Elemental >
                first = rank + count;
            const Natural
                remaining = sequence.allotment - static_cast<Natural>(first - sequence.source);
            if (remaining > 0)
                if (!Move( first, rank, remaining ))
                    return false;
            sequence.allotment -= count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        static inline bool
        Concede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
            Referential< const WritePositional< Elemental > >
                rank,
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
            using namespace ::location;
            const WritePositional< Elemental >
                first = rank + 1 + count;
            const Natural
                remaining = sequence.allotment - static_cast<Natural>(first - sequence.source);
            if (remaining > 0)
                if (!Move( first, rank, remaining ))
                    return false;
            sequence.allotment -= count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental
        >
        static inline bool
        Recede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence,
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
            sequence.allotment -= count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental
        >
        static inline bool
        Condense(
            Referential< Compact< Natural, Length, Elemental > >
                sequence
        ) {
            return false;
        }

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental
        >
        static inline bool
        Secede(
            Referential< Compact< Natural, Length, Elemental > >
                sequence
        ) {
            const bool actioned = sequence.allotment;
            sequence.allotment = 0;
            return actioned;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        constexpr Conjoint< Compact< Natural, Length, Elemental >, WritePositional< Elemental >, Relative, Appositional, RelativeNatural, Elemental >
            Conjoiner = {
                Accede< Relative, Appositional, RelativeNatural, Natural, Length, Elemental, Move >,
                Precede< Relative, Appositional, RelativeNatural, Natural, Length, Elemental, Move >,
                Cede< Relative, Appositional, RelativeNatural, Natural, Length, Elemental, Move >,
                Proceed< Relative, Appositional, RelativeNatural, Natural, Length, Elemental >
            };

        template <
            typename Natural,
            Natural
                Length,
            typename Elemental,
            Referential< MemoryMoving< Natural, Elemental > >
                Move
        >
        constexpr Sequent< Compact< Natural, Length, Elemental >, WritePositional< Elemental >, Natural, Elemental >
            Sequencer = {
                Instantiate< Natural, Length, Elemental >,
                Account< Natural, Length, Elemental >,
                Accede< Natural, Length, Elemental, Move >,
                Precede< Natural, Length, Elemental, Move >,
                Cede< Natural, Length, Elemental, Move >,
                Proceed< Natural, Length, Elemental >,
                Succeed< Natural, Length, Elemental, Move >,
                Supersede< Natural, Length, Elemental, Move >,
                Concede< Natural, Length, Elemental, Move >,
                Recede< Natural, Length, Elemental >,
                Secede< Natural, Length, Elemental >,
                Condense< Natural, Length, Elemental >,
                Conjoiner< Compact< Natural, Length, Elemental >, WritePositional< Elemental >, Natural, Natural, Length, Elemental, Move >
            };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Scalar< const Compact< Natural, Maximum, Elemental >, ReadPositional< Elemental >, Natural, const Elemental >
            ReadIncrementScale = {
                Comparison< ReadPositional< Elemental > >,
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
        constexpr Scalar< Compact< Natural, Maximum, Elemental >, WritePositional< Elemental >, Natural, Elemental >
            WriteIncrementScale = {
                Comparison< WritePositional< Elemental > >,
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
        constexpr Scalar< const Compact< Natural, Maximum, Elemental >, ReadPositional< Elemental >, Natural, const Elemental >
            ReadDecrementScale = {
                Comparison< ReadPositional< Elemental > >,
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
        constexpr Scalar< Compact< Natural, Maximum, Elemental >, WritePositional< Elemental >, Natural, Elemental >
            WriteDecrementScale = {
                Comparison< WritePositional< Elemental > >,
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
        constexpr Lineal< const Compact< Natural, Maximum, Elemental >, ReadPositional< Elemental >, Natural, const Elemental >
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
        constexpr Lineal< Compact< Natural, Maximum, Elemental >, WritePositional< Elemental >, Natural, Elemental >
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
        constexpr Directional< const Compact< Natural, Maximum, Elemental >, ReadPositional< Elemental >, Natural, const Elemental >
            ReadIncrementDirection = {
                ReadIncrementScale< Natural, Maximum, Elemental >,
                Begins< Natural, Maximum, Elemental >,
                IncrementTraverses< Natural, Maximum, Elemental >,
                Meets< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                CountIncrement< Natural, Maximum, Elemental >
            };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Compact< Natural, Maximum, Elemental >, WritePositional< Elemental >, Natural, Elemental >
            WriteIncrementDirection = {
                WriteIncrementScale< Natural, Maximum, Elemental >,
                Begins< Natural, Maximum, Elemental >,
                IncrementTraverses< Natural, Maximum, Elemental >,
                Meets< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                CountIncrement< Natural, Maximum, Elemental >
            };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< const Compact< Natural, Maximum, Elemental >, ReadPositional< Elemental >, Natural, const Elemental >
            ReadDecrementDirection = {
                ReadDecrementScale< Natural, Maximum, Elemental >,
                Begins< Natural, Maximum, Elemental >,
                DecrementTraverses< Natural, Maximum, Elemental >,
                Meets< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                CountDecrement< Natural, Maximum, Elemental >
            };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Directional< Compact< Natural, Maximum, Elemental >, WritePositional< Elemental >, Natural, Elemental >
            WriteDecrementDirection = {
                WriteDecrementScale< Natural, Maximum, Elemental >,
                Begins< Natural, Maximum, Elemental >,
                DecrementTraverses< Natural, Maximum, Elemental >,
                Meets< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                CountDecrement< Natural, Maximum, Elemental >
            };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Axial< const Compact< Natural, Maximum, Elemental >, ReadPositional< Elemental >, Natural, const Elemental >
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
        constexpr Axial< Compact< Natural, Maximum, Elemental >, WritePositional< Elemental >, Natural, Elemental >
            WriteAxis = {
                WriteIncrementDirection< Natural, Maximum, Elemental >,
                WriteDecrementDirection< Natural, Maximum, Elemental >
            };

    }

}

#endif
