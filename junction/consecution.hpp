// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_CONSECUTION_MODULE
#define JUNCTION_CONSECUTION_MODULE
#include "../junction.hpp"
#include "../consecution.hpp"

namespace junction {

    namespace consecution {

        using namespace ::consecution;

        template <
            typename Natural,
            typename Elemental
        >
        using Consequent = bool(
            Referential< Junctive< Natural, Elemental > >,
            Referential< const Elemental >
        );

        template <
            typename Natural,
            typename Elemental
        >
        using Precedent = bool(
            Referential< Junctive< Natural, Elemental > >,
            Referential< const Positional< Elemental > >,
            Referential< const Elemental >
        );

        template <
            typename Natural,
            typename Elemental
        >
        using Concessive = bool(
            Referential< Junctive< Natural, Elemental > >,
            Referential< const Positional< Elemental > >,
            Referential< const Natural >
        );

        template <
            typename Relative,
            typename Appositional,
            typename Natural,
            typename Elemental
        >
        using ConjointlyConsequent = bool(
            Referential< Junctive< Natural, Elemental > >,
            Referential< const Directional< const Relative, Appositional, const Elemental > >,
            Referential< const Relative >,
            Referential< const Appositional >,
            Referential< const Appositional >
        );

        template <
            typename Relative,
            typename Appositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        Sequence(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< Locational< Junctional< Elemental > > >
                head,
            Referential< Locational< Junctional< Elemental > > >
                tail,
            Referential< Natural >
                length,
            Referential< const Directional< const Relative, Appositional, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            auto
                Finalize = [&](
                    Referential< const Locational< Junctional< Elemental > > >
                        start,
                    Referential< const Locational< Junctional< Elemental > > >
                        finish,
                    Referential< const Natural >
                        counted
                ) -> bool {
                    head = start;
                    tail = finish;
                    length = counted;
                    return length > 0;
                };
            auto&
                scale = direction.scale;
            Appositional
                current;
            Locational< Junctional< Elemental > >
                first, last;
            Natural
                count;
            current = from;
            first = Adjunct.proclaim( sequence, scale.go( space, current ).to );
            if (!first)
                return Finalize( 0, 0, 0 );
            last = first;
            count = 1;
            while (scale.order.equality.is_not_equal( current, to )) {
                direction.scale.traverse( space, current );
                last->next = Adjunct.proclaim( sequence, scale.go( space, current ).to );
                if (!last->next) {
                    if (sequence.unused)
                        sequence.unused->previous = last;
                    last->next = sequence.unused;
                    sequence.unused = first;
                    return Finalize( 0, 0, 0 );
                }
                last->next->previous = last;
                last = last->next;
                count++;
            }
            return Finalize( first, last, count );
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline Natural
        Account(
            Referential< const Junctive< Natural, Elemental > >
                sequence
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return sequence.count;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        Accede(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Elemental >
                value
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Locational< Junctional< Elemental > >
                result;
            result = Adjunct.proclaim( sequence, value );
            if (!result)
                return false;
            result->previous = 0;
            result->next = sequence.first;
            if (sequence.first)
                sequence.first->previous = result;
            else
                sequence.last = result;
            sequence.first = result;
            sequence.count++;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        Accede(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Directional< const Relative, Appositional, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                SequenceList = Sequence< Relative, Appositional, Natural, Elemental, Adjunct >;
            Locational< Junctional< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            last->next = sequence.first;
            if (sequence.first)
                sequence.first->previous = last;
            else
                sequence.last = last;
            sequence.first = first;
            sequence.count += length;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        Precede(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Elemental >
                value
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Locational< Junctional< Elemental > >
                result;
            result = Adjunct.proclaim( sequence, value );
            if (!result)
                return false;
            if (rank.at->previous)
                rank.at->previous->next = result;
            else
                sequence.first = result;
            result->previous = rank.at->previous;
            result->next = rank.at;
            rank.at->previous = result;
            sequence.count++;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        PrecedeSafely(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Elemental >
                value
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                PrecedeList = Precede< Natural, Elemental, Adjunct >;
            if (!rank.at)
                throw rank;
            return PrecedeList( sequence, rank, value );
        }

        template <
            typename Relative,
            typename Appositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        Precede(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Directional< const Relative, Appositional, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                SequenceList = Sequence< Relative, Appositional, Natural, Elemental, Adjunct >;
            Locational< Junctional< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            first->previous = rank.at->previous;
            if (first->previous)
                first->previous->next = first;
            else
                sequence.first = first;
            last->next = rank.at;
            rank.at->previous = last;
            sequence.count += length;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        PrecedeSafely(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Directional< const Relative, Appositional, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                PrecedeList = Precede< Relative, Appositional, Natural, Elemental, Adjunct >;
            if (!rank.at)
                throw rank;
            return PrecedeList( sequence, rank, direction, space, from, to );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        Proceed(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Elemental >
                value
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Locational< Junctional< Elemental > >
                result;
            result = Adjunct.proclaim( sequence, value );
            if (!result)
                return false;
            result->previous = sequence.last;
            result->next = 0;
            if (sequence.last)
                sequence.last->next = result;
            else
                sequence.first = result;
            sequence.last = result;
            sequence.count++;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        static inline bool
        Proceed(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Directional< const Relative, Appositional, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            static auto&
                SequenceList = Sequence< Relative, Appositional, Natural, Elemental, Adjunct >;
            Locational< Junctional< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            first->previous = sequence.last;
            if (sequence.last)
                sequence.last->next = first;
            else
                sequence.first = first;
            sequence.last = last;
            sequence.count += length;
            return true;
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline bool
        Succeed(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Natural >
                count
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Positional< Elemental >
                first, last;
            Natural
                index;
            if (!sequence.first)
                return false;
            first.at = last.at = sequence.first;
            for (index = 1; index < count; index++) {
                if (!last.at->next)
                    return false;
                last.at = last.at->next;
            }
            sequence.first = last.at->next;
            if (sequence.first)
                sequence.first->previous = 0;
            else
                sequence.last = 0;
            last.at->next = sequence.unused;
            if (sequence.unused)
                sequence.unused->previous = last.at;
            sequence.unused = first.at;
            sequence.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline bool
        Concede(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Natural >
                count
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Positional< Elemental >
                last;
            Natural
                index;
            last = rank;
            for (index = 1; index < count; index++) {
                if (!last.at->next)
                    return false;
                last.at = last.at->next;
            }
            if (rank.at->previous)
                rank.at->previous->next = last.at->next;
            else
                sequence.first = last.at->next;
            if (last.at->next)
                last.at->next->previous = rank.at->previous;
            else
                sequence.last = rank.at->previous;
            last.at->next = sequence.unused;
            if (sequence.unused)
                sequence.unused->previous = last.at;
            sequence.unused = rank.at;
            sequence.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline bool
        ConcedeSafely(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Natural >
                count
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!rank.at)
                throw rank;
            return Concede( sequence, rank, count );
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline bool
        Recede(
            Referential< Junctive< Natural, Elemental > >
                sequence,
            Referential< const Natural >
                count
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Positional< Elemental >
                first, last;
            Natural
                index;
            if (!sequence.last)
                return false;
            first.at = last.at = sequence.last;
            for (index = 1; index < count; index++) {
                if (!first.at->previous)
                    return false;
                first.at = first.at->previous;
            }
            sequence.last = first.at->previous;
            if (sequence.last) {
                sequence.last->next = 0;
                first.at->previous = 0;
            } else
                sequence.first = 0;
            last.at->next = sequence.unused;
            if (sequence.unused)
                sequence.unused->previous = last.at;
            sequence.unused = first.at;
            sequence.count -= count;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Conjoint< Junctive< Natural, Elemental >, Positional< Elemental >, Relative, Appositional, Elemental >
        JunctionConjoiner = {
            Accede< Relative, Appositional, Natural, Elemental, Adjunct >,
            Precede< Relative, Appositional, Natural, Elemental, Adjunct >,
            Proceed< Relative, Appositional, Natural, Elemental, Adjunct >
        };

        template <
            typename Relative,
            typename Appositional,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Conjoint< Junctive< Natural, Elemental >, Positional< Elemental >, Relative, Appositional, Elemental >
        SafeJunctionConjoiner = {
            Accede< Relative, Appositional, Natural, Elemental, Adjunct >,
            PrecedeSafely< Relative, Appositional, Natural, Elemental, Adjunct >,
            Proceed< Relative, Appositional, Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sequent< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental >
        JunctionSequencer = {
            Instantiate< Natural, Elemental, Adjunct >,
            Account< Natural, Elemental >,
            Accede< Natural, Elemental, Adjunct >,
            Precede< Natural, Elemental, Adjunct >,
            Proceed< Natural, Elemental, Adjunct >,
            Succeed< Natural, Elemental >,
            Concede< Natural, Elemental >,
            Recede< Natural, Elemental >,
            Empty< Natural, Elemental >,
            Free< Natural, Elemental, Adjunct >,
            JunctionConjoiner< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sequent< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental >
        SafeJunctionSequencer = {
            Instantiate< Natural, Elemental, Adjunct >,
            Account< Natural, Elemental >,
            Accede< Natural, Elemental, Adjunct >,
            PrecedeSafely< Natural, Elemental, Adjunct >,
            Proceed< Natural, Elemental, Adjunct >,
            Succeed< Natural, Elemental >,
            ConcedeSafely< Natural, Elemental >,
            Recede< Natural, Elemental >,
            Empty< Natural, Elemental >,
            Free< Natural, Elemental, Adjunct >,
            SafeJunctionConjoiner< Junctive< Natural, Elemental >, Positional< Elemental >, Natural, Elemental, Adjunct >
        };

    }

}

#endif
