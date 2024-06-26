// � 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_CONSECUTION_MODULE
#define RATION_CONSECUTION_MODULE
#include <consecution.hpp>
#include <ration.hpp>
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

/**
 * @brief         
 *     Array sequence management implementation.
 * @details       
 *     Array sequence management implementation.
 */
namespace consecution {

    using ::comparison::Comparison;
    using ::consecution::Conjoint;
    using ::consecution::Sequent;
    using ::location::Conferential;
    using ::location::Locational;
    using ::location::Referential;
    using ::trajection::Axial;
    using ::trajection::Directional;
    using ::trajection::Lineal;
    using ::trajection::Scalar;

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    using Consequent = bool(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Elemental>
            value);

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    using Precedent = bool(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            rank,
        Referential<const Elemental>
            value);

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    using Recessive = bool(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Natural>
            count);

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    using Concessive = bool(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            rank,
        Referential<const Natural>
            count);

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Referential<Resourceful<Natural, Length, Elemental>>
    Initialize(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        sequence.allotment = 0;
        return sequence;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Natural
    Account(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return sequence.allotment;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Natural
    CountReadIncrement(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            position)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return static_cast<Natural>(sequence.source + sequence.allotment - 1 - position);
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Natural
    CountWriteIncrement(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const WritePositional<Elemental>>
            position)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return static_cast<Natural>(sequence.source + sequence.allotment - 1 - position);
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Natural
    CountReadDecrement(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            position)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return static_cast<Natural>(position - sequence.source);
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Natural
    CountWriteDecrement(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const WritePositional<Elemental>>
            position)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return static_cast<Natural>(position - sequence.source);
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline bool
    Begins(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return count < sequence.allotment;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline bool
    ReadMeets(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            position)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return sequence.allotment > 0
            && sequence.source <= position
            && position <= sequence.source + sequence.allotment - 1;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline bool
    WriteMeets(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const WritePositional<Elemental>>
            position)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return sequence.allotment > 0
            && sequence.source <= position
            && position <= sequence.source + sequence.allotment - 1;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Conferential<Elemental>
    GoWrite(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const WritePositional<Elemental>>
            position)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return Refer(position);
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Conferential<const Elemental>
    GoRead(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            position)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return Refer(position);
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Referential<const ReadPositional<Elemental>>
    BeginReadIncrement(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<ReadPositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return position = sequence.source + count;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Referential<const WritePositional<Elemental>>
    BeginWriteIncrement(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<WritePositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return position = sequence.source + count;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline bool
    ReadIncrementTraverses(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (sequence.allotment < 1)
            return false;
        return position + count <= sequence.source + sequence.allotment - 1;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline bool
    WriteIncrementTraverses(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const WritePositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (sequence.allotment < 1)
            return false;
        return position + count <= sequence.source + sequence.allotment - 1;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Referential<const ReadPositional<Elemental>>
    TraverseReadIncrement(
        Referential<const Resourceful<Natural, Length, Elemental>>
            stack,
        Referential<ReadPositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return position += count;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Referential<const WritePositional<Elemental>>
    TraverseWriteIncrement(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<WritePositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return position += count;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Referential<const ReadPositional<Elemental>>
    BeginReadDecrement(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<ReadPositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return position = sequence.source + sequence.allotment - count - 1;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Referential<const WritePositional<Elemental>>
    BeginWriteDecrement(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<WritePositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return position = sequence.source + sequence.allotment - count - 1;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline bool
    ReadDecrementTraverses(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (sequence.allotment < 1)
            return false;
        return sequence.source <= position - count;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline bool
    WriteDecrementTraverses(
        Referential<const Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const WritePositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (sequence.allotment < 1)
            return false;
        return sequence.source <= position - count;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Referential<const ReadPositional<Elemental>>
    TraverseReadDecrement(
        Referential<const Resourceful<Natural, Length, Elemental>>
            stack,
        Referential<ReadPositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return position -= count;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline Referential<const WritePositional<Elemental>>
    TraverseWriteDecrement(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<WritePositional<Elemental>>
            position,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        return position -= count;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        const bool Safety>
    static inline bool
    Antecede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Natural>
            count)
    {
        if (Safety && sequence.allotment >= Length)
            return false;
        return Length - sequence.allotment >= count;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    Accede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Elemental>
            value)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!Move(sequence.source, sequence.source + 1, sequence.allotment) && Safety)
            return false;
        if (Safety && sequence.allotment >= Length)
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
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    Accede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Directional<const Relative, Appositional, RelativeNatural, const Elemental>>
            direction,
        Referential<const Relative>
            space,
        Referential<const Appositional>
            from,
        Referential<const Appositional>
            to)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
        static_assert(
            is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
            "RelativeNatural:  Unsigned integer type required");
#endif
        Appositional apposition = from;
        Natural count = 1;
        while (direction.scale.order.equality.is_not_equal(apposition, to)) {
            if (Safety && !direction.traverses(space, apposition, 1))
                return false;
            direction.scale.traverse(space, apposition, 1);
            count++;
        }
        if (Safety && sequence.allotment + count > Length)
            return false;
        if (!Move(sequence.source, sequence.source + count, sequence.allotment) && Safety)
            return false;
        apposition = from;
        for (Natural offset = 0; offset < count; offset++) {
            sequence.source[offset] = direction.scale.go(space, apposition).to;
            direction.scale.traverse(space, apposition, 1);
        }
        sequence.allotment += count;
        return true;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    Precede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            rank,
        Referential<const Elemental>
            value)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (Safety && (rank < sequence.source || rank >= sequence.source + sequence.allotment))
            return false;
        if (Safety && sequence.allotment >= Length)
            return false;
        const Natural index = static_cast<Natural>(rank - sequence.source);
        const WritePositional<Elemental> position = const_cast<WritePositional<Elemental>>(rank);
        if (!Move(position, position + 1, sequence.allotment - index) && Safety)
            return false;
        Refer(position).to = value;
        sequence.allotment++;
        return true;
    }

    template <
        typename Relative,
        typename Appositional,
        typename RelativeNatural,
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    Precede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            rank,
        Referential<const Directional<const Relative, Appositional, RelativeNatural, const Elemental>>
            direction,
        Referential<const Relative>
            space,
        Referential<const Appositional>
            from,
        Referential<const Appositional>
            to)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
        static_assert(
            is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
            "RelativeNatural:  Unsigned integer type required");
#endif
        if (Safety && (rank < sequence.source || rank >= sequence.source + sequence.allotment))
            return false;
        Appositional apposition = from;
        Natural count = 1;
        const Natural remaining = sequence.allotment - static_cast<Natural>(rank - sequence.source);
        while (direction.scale.order.equality.is_not_equal(apposition, to)) {
            if (Safety && !direction.traverses(space, apposition, 1))
                return false;
            direction.scale.traverse(space, apposition, 1);
            count++;
        }
        if (Safety && sequence.allotment + count > Length)
            return false;
        const WritePositional<Elemental> position = const_cast<WritePositional<Elemental>>(rank);
        if (!Move(position, position + count, remaining) && Safety)
            return false;
        apposition = from;
        for (Natural offset = 0; offset < count; offset++) {
            position[offset] = direction.scale.go(space, apposition).to;
            direction.scale.traverse(space, apposition, 1);
        }
        sequence.allotment += count;
        return true;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    Cede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            rank,
        Referential<const Elemental>
            value)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (Safety && (rank < sequence.source || rank >= sequence.source + sequence.allotment))
            return false;
        const WritePositional<Elemental> position = const_cast<WritePositional<Elemental>>(rank + 1);
        const Natural index = static_cast<Natural>(position - sequence.source);
        if (!Move(position, position + 1, sequence.allotment - index) && Safety)
            return false;
        Refer(position).to = value;
        sequence.allotment++;
        return true;
    }

    template <
        typename Relative,
        typename Appositional,
        typename RelativeNatural,
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    Cede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            rank,
        Referential<const Directional<const Relative, Appositional, RelativeNatural, const Elemental>>
            direction,
        Referential<const Relative>
            space,
        Referential<const Appositional>
            from,
        Referential<const Appositional>
            to)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
        static_assert(
            is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
            "RelativeNatural:  Unsigned integer type required");
#endif
        if (Safety && (rank < sequence.source || rank >= sequence.source + sequence.allotment))
            return false;
        Appositional apposition = from;
        Natural count = 1;
        const WritePositional<Elemental> first = const_cast<WritePositional<Elemental>>(rank) + 1;
        const Natural remaining = sequence.allotment - static_cast<Natural>(first - sequence.source);
        while (direction.scale.order.equality.is_not_equal(apposition, to)) {
            if (Safety && !direction.traverses(space, apposition, 1))
                return false;
            direction.scale.traverse(space, apposition, 1);
            count++;
        }
        if (!Move(first, first + count, remaining) && Safety)
            return false;
        apposition = from;
        for (Natural offset = 0; offset < count; offset++) {
            first[offset] = direction.scale.go(space, apposition).to;
            direction.scale.traverse(space, apposition, 1);
        }
        sequence.allotment += count;
        return true;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        const bool Safety>
    static inline bool
    Proceed(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Elemental>
            value)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (Safety && sequence.allotment >= Length)
            return false;
        sequence.source[sequence.allotment++] = value;
        return true;
    }

    template <
        typename Relative,
        typename Appositional,
        typename RelativeNatural,
        typename Natural,
        Natural Length,
        typename Elemental,
        const bool Safety>
    static inline bool
    Proceed(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Directional<const Relative, Appositional, RelativeNatural, const Elemental>>
            direction,
        Referential<const Relative>
            space,
        Referential<const Appositional>
            from,
        Referential<const Appositional>
            to)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
        static_assert(
            is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
            "RelativeNatural:  Unsigned integer type required");
#endif
        Appositional apposition = from;
        if (Safety && sequence.allotment >= Length)
            return false;
        sequence.source[sequence.allotment++] = direction.scale.go(space, apposition).to;
        while (direction.scale.order.equality.is_not_equal(apposition, to)) {
            if (Safety && !direction.traverses(space, apposition, 1))
                return false;
            direction.scale.traverse(space, apposition, 1);
            if (Safety && sequence.allotment >= Length)
                return false;
            sequence.source[sequence.allotment++] = direction.scale.go(space, apposition).to;
        }
        return true;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    Succeed(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (Safety && count > sequence.allotment)
            return false;
        const Natural remaining = sequence.allotment - count;
        if (remaining > 0)
            if (!Move(sequence.source + count, sequence.source, remaining) && Safety)
                return false;
        sequence.allotment -= count;
        return true;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    Supersede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            rank,
        Referential<const Natural>
            count)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (Safety && (rank < sequence.source || rank >= sequence.source + sequence.allotment))
            return false;
        const WritePositional<Elemental> first = const_cast<WritePositional<Elemental>>(rank) + 1;
        if (Safety && first < sequence.source + count)
            return false;
        const Natural remaining = sequence.allotment - static_cast<Natural>(first - sequence.source);
        if (remaining > 0)
            if (!Move(first, first - count, remaining) && Safety)
                return false;
        sequence.allotment -= count;
        return true;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move,
        const bool Safety>
    static inline bool
    Concede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const ReadPositional<Elemental>>
            rank,
        Referential<const Natural>
            count)
    {
        using namespace ::location;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (Safety && (rank < sequence.source || rank >= sequence.source + sequence.allotment))
            return false;
        const WritePositional<Elemental> position = const_cast<WritePositional<Elemental>>(rank),
                                         first = position + count;
        if (Safety && first > sequence.source + sequence.allotment)
            return false;
        const Natural remaining = sequence.allotment - static_cast<Natural>(first - sequence.source);
        if (remaining > 0)
            if (!Move(first, position, remaining) && Safety)
                return false;
        sequence.allotment -= count;
        return true;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        const bool Safety>
    static inline bool
    Recede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (Safety && count > sequence.allotment)
            return false;
        sequence.allotment -= count;
        return true;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline bool
    Condense(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence)
    {
        return false;
    }

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    static inline bool
    Secede(
        Referential<Resourceful<Natural, Length, Elemental>>
            sequence)
    {
        const bool actioned = sequence.allotment != 0;
        sequence.allotment = 0;
        return actioned;
    }

    template <
        typename Relative,
        typename Appositional,
        typename RelativeNatural,
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Conjoint<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Relative, Appositional, RelativeNatural, Elemental>
        FastConjoiner = {
            Accede<Relative, Appositional, RelativeNatural, Natural, Length, Elemental, Move, false>,
            Precede<Relative, Appositional, RelativeNatural, Natural, Length, Elemental, Move, false>,
            Cede<Relative, Appositional, RelativeNatural, Natural, Length, Elemental, Move, false>,
            Proceed<Relative, Appositional, RelativeNatural, Natural, Length, Elemental, false>
        };

    template <
        typename Relative,
        typename Appositional,
        typename RelativeNatural,
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>>
            Move>
    constexpr Conjoint<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Relative, Appositional, RelativeNatural, Elemental>
        SureConjoiner = {
            Accede<Relative, Appositional, RelativeNatural, Natural, Length, Elemental, Move, true>,
            Precede<Relative, Appositional, RelativeNatural, Natural, Length, Elemental, Move, true>,
            Cede<Relative, Appositional, RelativeNatural, Natural, Length, Elemental, Move, true>,
            Proceed<Relative, Appositional, RelativeNatural, Natural, Length, Elemental, true>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Sequent<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Elemental>
        FastSequencer = {
            Antecede<Natural, Length, Elemental, false>,
            Account<Natural, Length, Elemental>,
            Accede<Natural, Length, Elemental, Move, false>,
            Precede<Natural, Length, Elemental, Move, false>,
            Cede<Natural, Length, Elemental, Move, false>,
            Proceed<Natural, Length, Elemental, false>,
            Succeed<Natural, Length, Elemental, Move, false>,
            Supersede<Natural, Length, Elemental, Move, false>,
            Concede<Natural, Length, Elemental, Move, false>,
            Recede<Natural, Length, Elemental, false>,
            Secede<Natural, Length, Elemental>,
            Condense<Natural, Length, Elemental>,
            FastConjoiner<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Natural, Length, Elemental, Move>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental,
        Referential<MemoryMoving<Natural, Elemental>> Move>
    constexpr Sequent<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Elemental>
        SureSequencer = {
            Antecede<Natural, Length, Elemental, true>,
            Account<Natural, Length, Elemental>,
            Accede<Natural, Length, Elemental, Move, true>,
            Precede<Natural, Length, Elemental, Move, true>,
            Cede<Natural, Length, Elemental, Move, true>,
            Proceed<Natural, Length, Elemental, true>,
            Succeed<Natural, Length, Elemental, Move, true>,
            Supersede<Natural, Length, Elemental, Move, true>,
            Concede<Natural, Length, Elemental, Move, true>,
            Recede<Natural, Length, Elemental, true>,
            Secede<Natural, Length, Elemental>,
            Condense<Natural, Length, Elemental>,
            SureConjoiner<Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, Natural, Length, Elemental, Move>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Scalar<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>
        ReadIncrementScale = {
            Comparison<ReadPositional<Elemental>>,
            BeginReadIncrement<Natural, Length, Elemental>,
            TraverseReadIncrement<Natural, Length, Elemental>,
            GoRead<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Scalar<Resourceful<Natural, Length, Elemental>, WritePositional<Elemental>, Natural, Elemental>
        WriteIncrementScale = {
            Comparison<WritePositional<Elemental>>,
            BeginWriteIncrement<Natural, Length, Elemental>,
            TraverseWriteIncrement<Natural, Length, Elemental>,
            GoWrite<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Scalar<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>
        ReadDecrementScale = {
            Comparison<ReadPositional<Elemental>>,
            BeginReadDecrement<Natural, Length, Elemental>,
            TraverseReadDecrement<Natural, Length, Elemental>,
            GoRead<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Scalar<Resourceful<Natural, Length, Elemental>, WritePositional<Elemental>, Natural, Elemental>
        WriteDecrementScale = {
            Comparison<WritePositional<Elemental>>,
            BeginWriteDecrement<Natural, Length, Elemental>,
            TraverseWriteDecrement<Natural, Length, Elemental>,
            GoWrite<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Lineal<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>
        ReadLiner = {
            ReadIncrementScale<Natural, Length, Elemental>,
            ReadDecrementScale<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Lineal<Resourceful<Natural, Length, Elemental>, WritePositional<Elemental>, Natural, Elemental>
        WriteLiner = {
            WriteIncrementScale<Natural, Length, Elemental>,
            WriteDecrementScale<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Directional<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>
        ReadIncrementDirection = {
            ReadIncrementScale<Natural, Length, Elemental>,
            Begins<Natural, Length, Elemental>,
            ReadIncrementTraverses<Natural, Length, Elemental>,
            ReadMeets<Natural, Length, Elemental>,
            Account<Natural, Length, Elemental>,
            CountReadIncrement<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Directional<Resourceful<Natural, Length, Elemental>, WritePositional<Elemental>, Natural, Elemental>
        WriteIncrementDirection = {
            WriteIncrementScale<Natural, Length, Elemental>,
            Begins<Natural, Length, Elemental>,
            WriteIncrementTraverses<Natural, Length, Elemental>,
            WriteMeets<Natural, Length, Elemental>,
            Account<Natural, Length, Elemental>,
            CountWriteIncrement<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Directional<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>
        ReadDecrementDirection = {
            ReadDecrementScale<Natural, Length, Elemental>,
            Begins<Natural, Length, Elemental>,
            ReadDecrementTraverses<Natural, Length, Elemental>,
            ReadMeets<Natural, Length, Elemental>,
            Account<Natural, Length, Elemental>,
            CountReadDecrement<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Directional<Resourceful<Natural, Length, Elemental>, WritePositional<Elemental>, Natural, Elemental>
        WriteDecrementDirection = {
            WriteDecrementScale<Natural, Length, Elemental>,
            Begins<Natural, Length, Elemental>,
            WriteDecrementTraverses<Natural, Length, Elemental>,
            WriteMeets<Natural, Length, Elemental>,
            Account<Natural, Length, Elemental>,
            CountWriteDecrement<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Axial<const Resourceful<Natural, Length, Elemental>, ReadPositional<Elemental>, Natural, const Elemental>
        ReadAxis = {
            ReadIncrementDirection<Natural, Length, Elemental>,
            ReadDecrementDirection<Natural, Length, Elemental>
        };

    template <
        typename Natural,
        Natural Length,
        typename Elemental>
    constexpr Axial<Resourceful<Natural, Length, Elemental>, WritePositional<Elemental>, Natural, Elemental>
        WriteAxis = {
            WriteIncrementDirection<Natural, Length, Elemental>,
            WriteDecrementDirection<Natural, Length, Elemental>
        };

}

}

#endif
