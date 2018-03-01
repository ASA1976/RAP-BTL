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
                list,
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
            auto Result = [&head, &tail, &length](
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
            auto
                scale = direction.scale;
            Appositional
                current;
            Locational< Junctional< Elemental > >
                first, last;
            Natural
                count;
            current = from;
            first = Adjunct.proclaim( list, scale.go( space, current ).to );
            if (!first)
                return Result( 0, 0, 0 );
            last = first;
            count = 1;
            while (current != to) {
                direction.scale.traverse( space, current );
                last->next = Adjunct.proclaim( list, scale.go( space, current ).to );
                if (!last->next) {
                    if (list.unused)
                        list.unused->previous = last;
                    last->next = list.unused;
                    list.unused = first;
                    return Result( 0, 0, 0 );
                }
                last->next->previous = last;
                last = last->next;
                count++;
            }
            return Result( first, last, count );
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline Natural
        Account(
            Referential< const Junctive< Natural, Elemental > >
                list
        ) {
            return list.count;
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
                list,
            Referential< const Elemental >
                value
        ) {
            Locational< Junctional< Elemental > >
                result;
            result = Adjunct.proclaim( list, value );
            if (!result)
                return false;
            result->previous = 0;
            result->next = list.first;
            if (list.first)
                list.first->previous = result;
            else
                list.last = result;
            list.first = result;
            list.count++;
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
                list,
            Referential< const Directional< const Relative, Appositional, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
            static auto
                SequenceList = Sequence< Relative, Appositional, Natural, Elemental, Adjunct >;
            Locational< Junctional< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( list, first, last, length, direction, space, from, to ))
                return false;
            last->next = list.first;
            if (list.first)
                list.first->previous = last;
            else
                list.last = last;
            list.first = first;
            list.count += length;
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
                list,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Elemental >
                value
        ) {
            Locational< Junctional< Elemental > >
                result;
            result = Adjunct.proclaim( list, value );
            if (!result)
                return false;
            if (rank.at->previous)
                rank.at->previous->next = result;
            else
                list.first = result;
            result->previous = rank.at->previous;
            result->next = rank.at;
            rank.at->previous = result;
            list.count++;
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
                list,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Elemental >
                value
        ) {
            static auto
                PrecedeList = Precede< Natural, Elemental, Adjunct >;
            if (!rank.at)
                throw rank;
            return PrecedeList( list, rank, value );
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
                list,
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
            static auto
                SequenceList = Sequence< Relative, Appositional, Natural, Elemental, Adjunct >;
            Locational< Junctional< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( list, first, last, length, direction, space, from, to ))
                return false;
            first->previous = rank.at->previous;
            if (first->previous)
                first->previous->next = first;
            else
                list.first = first;
            last->next = rank.at;
            rank.at->previous = last;
            list.count += length;
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
                list,
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
            static auto
                PrecedeList = Precede< Relative, Appositional, Natural, Elemental, Adjunct >;
            if (!rank.at)
                throw rank;
            return PrecedeList( list, rank, direction, space, from, to );
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
                list,
            Referential< const Elemental >
                value
        ) {
            Locational< Junctional< Elemental > >
                result;
            result = Adjunct.proclaim( list, value );
            if (!result)
                return false;
            result->previous = list.last;
            result->next = 0;
            if (list.last)
                list.last->next = result;
            else
                list.first = result;
            list.last = result;
            list.count++;
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
                list,
            Referential< const Directional< const Relative, Appositional, const Elemental > >
                direction,
            Referential< const Relative >
                space,
            Referential< const Appositional >
                from,
            Referential< const Appositional >
                to
        ) {
            static auto
                SequenceList = Sequence< Relative, Appositional, Natural, Elemental, Adjunct >;
            Locational< Junctional< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( list, first, last, length, direction, space, from, to ))
                return false;
            first->previous = list.last;
            if (list.last)
                list.last->next = first;
            else
                list.first = first;
            list.last = last;
            list.count += length;
            return true;
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline bool
        Succeed(
            Referential< Junctive< Natural, Elemental > >
                list,
            Referential< const Natural >
                count
        ) {
            Positional< Elemental >
                first, last;
            Natural
                index;
            first.at = last.at = list.first;
            for (index = 1; index < count; index++) {
                if (!last.at->next)
                    return false;
                last.at = last.at->next;
            }
            list.first = last.at->next;
            if (list.first)
                list.first->previous = 0;
            else
                list.last = 0;
            last.at->next = list.unused;
            if (list.unused)
                list.unused->previous = last.at;
            list.unused = first.at;
            list.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline bool
        Concede(
            Referential< Junctive< Natural, Elemental > >
                list,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Natural >
                count
        ) {
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
                list.first = last.at->next;
            if (last.at->next)
                last.at->next->previous = rank.at->previous;
            else
                list.last = rank.at->previous;
            last.at->next = list.unused;
            if (list.unused)
                list.unused->previous = last.at;
            list.unused = rank.at;
            list.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline bool
        ConcedeSafely(
            Referential< Junctive< Natural, Elemental > >
                list,
            Referential< const Positional< Elemental > >
                rank,
            Referential< const Natural >
                count
        ) {
            if (!rank.at)
                throw rank;
            return Concede( list, rank, count );
        }

        template <
            typename Natural,
            typename Elemental
        >
        static inline bool
        Recede(
            Referential< Junctive< Natural, Elemental > >
                list,
            Referential< const Natural >
                count
        ) {
            Positional< Elemental >
                first, last;
            Natural
                index;
            first.at = last.at = list.last;
            for (index = 1; index < count; index++) {
                if (!first.at->previous)
                    return false;
                first.at = first.at->previous;
            }
            list.last = first.at->previous;
            if (list.last) {
                list.last->next = 0;
                first.at->previous = 0;
            } else
                list.first = 0;
            last.at->next = list.unused;
            if (list.unused)
                list.unused->previous = last.at;
            list.unused = first.at;
            list.count -= count;
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
