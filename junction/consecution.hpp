// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_CONSECUTION_MODULE
#define JUNCTION_CONSECUTION_MODULE
#include "../junction.hpp"
#include "../consecution.hpp"

namespace junction {

    /**
     * @brief         
     *     Linked list sequence management implementation.
     * @details       
     *     Association
     *     -----------
     *     Linked list sequence management implementation.
     */
    namespace consecution {

        using ::consecution::Conjoint;
        using ::consecution::Sequent;

        /**
         * @brief 
         *     Function abstract used to add an element to either pole.
         * @details  
         *     Abstraction Template
         *     --------------------
         *     This function type alias is used to declare function references 
         *     which add one element either before the first or after the last 
         *     node in the linked list.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Elemental
         *     Type of the elements.
         */
        template <
            typename Connective,
            typename Natural,
            typename Elemental
        >
        using Consequent = bool(
            Referential< Junctive< Connective, Natural, Elemental > >
                sequence, 
            Referential< const Elemental >
                value 
        );

        /**
         * @brief 
         *     Function abstract used to add an element to either pole.
         * @details  
         *     Abstraction Template
         *     --------------------
         *     This function type alias is used to declare function references 
         *     which add one element either before or after the provided position.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Elemental
         *     Type of the elements.
         */
        template <
            typename Connective,
            typename Natural,
            typename Elemental
        >
        using Precedent = bool(
            Referential< Junctive< Connective, Natural, Elemental > >
                sequence, 
            Referential< const Positional< Connective, Elemental > >
                position, 
            Referential< const Elemental >
                value 
        );

        /**
         * @brief 
         *     Function abstract used to remove elements from either pole.
         * @details  
         *     Abstraction Template
         *     --------------------
         *     This function type alias is used to declare function references 
         *     which remove one or more elements including either the first or 
         *     last elements in the list.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Elemental
         *     Type of the elements.
         */
        template <
            typename Connective,
            typename Natural,
            typename Elemental
        >
        using Recessive = bool(
            Referential< Junctive< Connective, Natural, Elemental > >
                sequence, 
            Referential< const Natural >
                count 
        );

        /**
         * @brief 
         *     Function abstract used to remove elements relative to a position.
         * @details  
         *     Abstraction Template
         *     --------------------
         *     This function type alias is used to declare function references 
         *     which remove one or more elements including the provided 
         *     position.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Elemental
         *     Type of the elements.
         */
        template <
            typename Connective,
            typename Natural,
            typename Elemental
        >
        using Concessive = bool(
            Referential< Junctive< Connective, Natural, Elemental > >
                sequence, 
            Referential< const Positional< Connective, Elemental > >
                position, 
            Referential< const Natural >
                count 
        );

        // It is the responsibility of the calling function to terminate or
        // attach each directional end of the resulting sequence of nodes
        // (before head and after tail where applicable).
        template <
            typename Connective,
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const Adjunctive< Connective, Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Sequence(
            Referential< Junctive< Connective, Natural, Elemental > >
                sequence,
            Referential< Locational< Nodal< Connective, Elemental > > >
                head,
            Referential< Locational< Nodal< Connective, Elemental > > >
                tail,
            Referential< Natural >
                length,
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
            auto
                Finalize = [&](
                    Referential< const Locational< Nodal< Connective, Elemental > > >
                        start,
                    Referential< const Locational< Nodal< Connective, Elemental > > >
                        finish,
                    Referential< const Natural >
                        counted
                ) -> bool {
                    head = start;
                    tail = finish;
                    length = counted;
                    return length > 0;
                };
            Appositional
                current;
            Locational< Nodal< Connective, Elemental > >
                first, last, next;
            Natural
                count;
            current = from;
            first = Adjunct.proclaim( sequence, direction.scale.go( space, current ).to );
            if (Safety && !first)
                return Finalize( 0, 0, 0 );
            last = first;
            count = 1;
            while (direction.scale.order.equality.is_not_equal( current, to )) {
                if (Safety && !direction.traverses( space, current, 1 )) {
                    ConnectNext( last, sequence.unused );
                    sequence.unused = first;
                    return Finalize( 0, 0, 0 );
                }
                direction.scale.traverse( space, current, 1 );
                next = Adjunct.proclaim( sequence, direction.scale.go( space, current ).to );
                if (Safety && !next) {
                    ConnectNext( last, sequence.unused );
                    sequence.unused = first;
                    return Finalize( 0, 0, 0 );
                }
                ConnectNext( last, next );
                last = next;
                count++;
            }
            return Finalize( first, last, count );
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Accede(
            Referential< SinglyJunctive< Natural, Elemental > >
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
            Locational< SinglyNodal< Elemental > >
                result;
            result = Adjunct.proclaim( sequence, value );
            if (Safety && !result)
                return false;
            SetNext( result, sequence.first );
            if (!sequence.first)
                sequence.last = result;
            sequence.first = result;
            sequence.count++;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Accede(
            Referential< DoublyJunctive< Natural, Elemental > >
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
            Locational< DoublyNodal< Elemental > >
                result;
            result = Adjunct.proclaim( sequence, value );
            if (Safety && !result)
                return false;
            UnsetPrevious( result );
            SetNext( result, sequence.first );
            if (sequence.first)
                SetPrevious( sequence.first, result );
            else
                sequence.last = result;
            sequence.first = result;
            sequence.count++;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Accede(
            Referential< SinglyJunctive< Natural, Elemental > >
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
            static auto&
                SequenceList = Sequence< SinglyLinked< Elemental >, Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, Safety >;
            Locational< SinglyNodal< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            SetNext( last, sequence.first );
            if (!sequence.first)
                sequence.last = last;
            sequence.first = first;
            sequence.count += length;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Accede(
            Referential< DoublyJunctive< Natural, Elemental > >
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
            static auto&
                SequenceList = Sequence< DoublyLinked< Elemental >, Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, Safety >;
            Locational< DoublyNodal< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            UnsetPrevious( first );
            SetNext( last, sequence.first );
            if (sequence.first)
                SetPrevious( sequence.first, last );
            else
                sequence.last = last;
            sequence.first = first;
            sequence.count += length;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Precede(
            Referential< SinglyJunctive< Natural, Elemental > >
                sequence,
            Referential< const SinglyPositional< Elemental > >
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
            Locational< SinglyNodal< Elemental > >
                result, previous;
            if (Safety && !rank.at)
                throw rank;
            result = Adjunct.proclaim( sequence, value );
            if (Safety && !result)
                return false;
            if (sequence.first == rank.at) {
                SetNext( result, sequence.first );
                sequence.first = result;
                sequence.count++;
                return true;
            }
            previous = sequence.first;
            while (GetNext( previous ) != rank.at) {
                if (Safety && !previous) {
                    SetNext( result, sequence.unused );
                    sequence.unused = result;
                    return false;
                }
                previous = GetNext( previous );
            }
            SetNext( previous, result );
            SetNext( result, rank.at );
            sequence.count++;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Precede(
            Referential< DoublyJunctive< Natural, Elemental > >
                sequence,
            Referential< const DoublyPositional< Elemental > >
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
            Locational< DoublyNodal< Elemental > >
                result, current;
            if (Safety && !rank.at)
                throw rank;
            result = Adjunct.proclaim( sequence, value );
            if (Safety) {
                if (!result)
                    return false;
                current = sequence.first; 
                while (current != rank.at) {
                    if (!current)
                        throw rank;
                    current = GetNext( current );
                }
            }
            if (GetPrevious( rank.at ))
                SetNext( GetPrevious( rank.at ), result );
            else
                sequence.first = result;
            SetPrevious( result, GetPrevious( rank.at ) );
            SetNext( result, rank.at );
            SetPrevious( rank.at, result );
            sequence.count++;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Precede(
            Referential< SinglyJunctive< Natural, Elemental > >
                sequence,
            Referential< const SinglyPositional< Elemental > >
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
            static auto&
                SequenceList = Sequence< SinglyLinked< Elemental >, Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, Safety >;
            Locational< SinglyNodal< Elemental > >
                first, last, previous;
            Natural
                length;
            if (Safety && (!rank.at || !sequence.first))
                throw rank;
            if (sequence.first == rank.at) {
                if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                    return false;
                SetNext( last, sequence.first );
                sequence.first = first;
                sequence.count += length;
                return true;
            }
            previous = sequence.first;
            while (GetNext( previous ) != rank.at) {
                if (Safety && !previous)
                    throw rank;
                previous = GetNext( previous );
            }
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            SetNext( previous, first );
            SetNext( last, rank.at );
            sequence.count += length;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Precede(
            Referential< DoublyJunctive< Natural, Elemental > >
                sequence,
            Referential< const DoublyPositional< Elemental > >
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
            static auto&
                SequenceList = Sequence< DoublyLinked< Elemental >, Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, Safety >;
            Locational< DoublyNodal< Elemental > >
                first, last;
            Natural
                length;
            if (Safety && (!rank.at || !sequence.first))
                throw rank;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            SetPrevious( first, GetPrevious( rank.at ) );
            if (GetPrevious( first ))
                SetNext( GetPrevious( first ), first );
            else
                sequence.first = first;
            SetNext( last, rank.at );
            SetPrevious( rank.at, last );
            sequence.count += length;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Cede(
            Referential< SinglyJunctive< Natural, Elemental > >
                sequence,
            Referential< const SinglyPositional< Elemental > >
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
            Locational< SinglyNodal< Elemental > >
                result;
            if (Safety && !rank.at)
                throw rank;
            result = Adjunct.proclaim( sequence, value );
            if (Safety && !result)
                return false;
            SetNext( result, GetNext( rank.at ) );
            SetNext( rank.at, result );
            if (!GetNext( result ))
                sequence.last = result;
            sequence.count++;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Cede(
            Referential< DoublyJunctive< Natural, Elemental > >
                sequence,
            Referential< const DoublyPositional< Elemental > >
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
            Locational< DoublyNodal< Elemental > >
                result;
            if (Safety && !rank.at)
                throw rank;
            result = Adjunct.proclaim( sequence, value );
            if (Safety && !result)
                return false;
            SetNext( result, GetNext( rank.at ) );
            SetPrevious( result, rank.at );
            SetNext( rank.at, result );
            if (GetNext( result ))
                SetPrevious( GetNext( result ), result );
            else
                sequence.last = result;
            sequence.count++;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Cede(
            Referential< SinglyJunctive< Natural, Elemental > >
                sequence,
            Referential< const SinglyPositional< Elemental > >
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
            static auto&
                SequenceList = Sequence< SinglyLinked< Elemental >, Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, Safety >;
            Locational< SinglyNodal< Elemental > >
                first, last;
            Natural
                length;
            if (Safety && !rank.at)
                throw rank;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            SetNext( last, GetNext( rank.at ) );
            if (!GetNext( last ))
                sequence.last = last;
            SetNext( rank.at, first );
            sequence.count += length;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Cede(
            Referential< DoublyJunctive< Natural, Elemental > >
                sequence,
            Referential< const DoublyPositional< Elemental > >
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
            static auto&
                SequenceList = Sequence< DoublyLinked< Elemental >, Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, Safety >;
            Locational< DoublyNodal< Elemental > >
                first, last;
            Natural
                length;
            if (Safety && !rank.at)
                throw rank;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            SetPrevious( first, rank.at );
            SetNext( last, GetNext( rank.at ) );
            if (GetNext( last ))
                SetPrevious( GetNext( last ), last );
            else
                sequence.last = last;
            SetNext( rank.at, first );
            sequence.count += length;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Proceed(
            Referential< SinglyJunctive< Natural, Elemental > >
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
            Locational< SinglyNodal< Elemental > >
                result;
            result = Adjunct.proclaim( sequence, value );
            if (Safety && !result)
                return false;
            UnsetNext( result );
            if (sequence.last)
                SetNext( sequence.last, result );
            else
                sequence.first = result;
            sequence.last = result;
            sequence.count++;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Proceed(
            Referential< DoublyJunctive< Natural, Elemental > >
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
            Locational< DoublyNodal< Elemental > >
                result;
            result = Adjunct.proclaim( sequence, value );
            if (Safety && !result)
                return false;
            SetPrevious( result, sequence.last );
            UnsetNext( result );
            if (sequence.last)
                SetNext( sequence.last, result );
            else
                sequence.first = result;
            sequence.last = result;
            sequence.count++;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Proceed(
            Referential< SinglyJunctive< Natural, Elemental > >
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
            static auto&
                SequenceList = Sequence< SinglyLinked< Elemental >, Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, Safety >;
            Locational< SinglyNodal< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            UnsetNext( last );
            if (sequence.last)
                SetNext( sequence.last, first );
            else
                sequence.first = first;
            sequence.last = last;
            sequence.count += length;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct,
            const bool
                Safety
        >
        static inline bool
        Proceed(
            Referential< DoublyJunctive< Natural, Elemental > >
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
            static auto&
                SequenceList = Sequence< DoublyLinked< Elemental >, Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, Safety >;
            Locational< DoublyNodal< Elemental > >
                first, last;
            Natural
                length;
            if (!SequenceList( sequence, first, last, length, direction, space, from, to ))
                return false;
            UnsetNext( last );
            SetPrevious( first, sequence.last );
            if (sequence.last)
                SetNext( sequence.last, first );
            else
                sequence.first = first;
            sequence.last = last;
            sequence.count += length;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            const bool
                Safety
        >
        static inline bool
        Succeed(
            Referential< SinglyJunctive< Natural, Elemental > >
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
            Locational< SinglyNodal< Elemental > >
                first, last;
            Natural
                index;
            if (Safety && (!count || !sequence.first))
                return false;
            first = last = sequence.first;
            for (index = 1; index < count; index++) {
                if (Safety && !GetNext( last ))
                    return false;
                last = GetNext( last );
            }
            sequence.first = GetNext( last );
            if (!sequence.first)
                sequence.last = 0;
            SetNext( last, sequence.unused );
            sequence.unused = first;
            sequence.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            const bool
                Safety
        >
        static inline bool
        Succeed(
            Referential< DoublyJunctive< Natural, Elemental > >
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
            Locational< DoublyNodal< Elemental > >
                first, last;
            Natural
                index;
            if (Safety && (!count || !sequence.first))
                return false;
            first = last = sequence.first;
            for (index = 1; index < count; index++) {
                if (Safety && !GetNext( last ))
                    return false;
                last = GetNext( last );
            }
            sequence.first = GetNext( last );
            if (sequence.first)
                UnsetPrevious( sequence.first );
            else
                sequence.last = 0;
            SetNext( last, sequence.unused );
            if (sequence.unused)
                SetPrevious( sequence.unused, last );
            sequence.unused = first;
            sequence.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            const bool
                Safety
        >
        static inline bool
        Supersede(
            Referential< SinglyJunctive< Natural, Elemental > >
                sequence,
            Referential< const SinglyPositional< Elemental > >
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
            Locational< SinglyNodal< Elemental > >
                first, last, previous;
            Natural
                index;
            if (Safety && !rank.at)
                return false;
            previous = sequence.first;
            last = previous;
            for (index = 1; index < count; index++) {
                if (Safety && (!last || last == rank.at))
                    throw count;
                last = GetNext( last );
            }
            if (last == rank.at) {
                sequence.first = GetNext( rank.at );
                if (!sequence.first)
                    sequence.last = sequence.first;
                SetNext( rank.at, sequence.unused );
                sequence.unused = previous;
                sequence.count -= count;
                return true;
            }
            while (GetNext( last ) != rank.at) {
                if (Safety && !last)
                    throw rank;
                previous = GetNext( previous );
                last = GetNext( last );
            }
            first = GetNext( previous );
            SetNext( previous, GetNext( rank.at ) );
            SetNext( rank.at, sequence.unused );
            sequence.unused = first;
            sequence.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            const bool
                Safety
        >
        static inline bool
        Supersede(
            Referential< DoublyJunctive< Natural, Elemental > >
                sequence,
            Referential< const DoublyPositional< Elemental > >
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
            Locational< DoublyNodal< Elemental > >
                first;
            Natural
                index;
            first = rank.at;
            for (index = 1; index < count; index++) {
                if (Safety && !first)
                    throw count;
                first = GetPrevious( first );
            }
            if (first == sequence.first) {
                sequence.first = GetNext( rank.at );
            } else {
                SetNext( GetPrevious( first ), GetNext( rank.at ) );
                UnsetPrevious( first );
            }
            if (GetNext( rank.at ))
                SetPrevious( GetNext( rank.at ), GetPrevious( first ) );
            else
                sequence.last = GetPrevious( first );
            SetNext( rank.at, sequence.unused );
            if (sequence.unused)
                SetPrevious( sequence.unused, rank.at );
            sequence.unused = first;
            sequence.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            const bool
                Safety
        >
        static inline bool
        Concede(
            Referential< SinglyJunctive< Natural, Elemental > >
                sequence,
            Referential< const SinglyPositional< Elemental > >
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
            Locational< SinglyNodal< Elemental > >
                last, previous;
            Natural
                index;
            if (Safety && (!rank.at || !count || !sequence.first))
                return false;
            last = rank.at;
            for (index = 1; index < count; index++) {
                if (Safety && !GetNext( last ))
                    return false;
                last = GetNext( last );
            }
            if (rank.at == sequence.first) {
                sequence.first = GetNext( last );
                previous = 0;
            } else {
                previous = sequence.first;
                while (GetNext( previous ) != rank.at) {
                    if (Safety && !previous)
                        throw rank;
                    previous = GetNext( previous );
                }
                SetNext( previous, GetNext( last ) );
            }
            if (!GetNext( last ))
                sequence.last = previous;
            SetNext( last, sequence.unused );
            sequence.unused = rank.at;
            sequence.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            const bool
                Safety
        >
        static inline bool
        Concede(
            Referential< DoublyJunctive< Natural, Elemental > >
                sequence,
            Referential< const DoublyPositional< Elemental > >
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
            Locational< DoublyNodal< Elemental > >
                last;
            Natural
                index;
            if (Safety) {
                if (!rank.at || !count || !sequence.first)
                    return false;
                last = sequence.first;
                while (last != rank.at) {
                    if (!last)
                        throw rank;
                    last = GetNext( last );
                }
            }
            last = rank.at;
            for (index = 1; index < count; index++) {
                if (Safety && !GetNext( last ))
                    return false;
                last = GetNext( last );
            }
            if (GetPrevious( rank.at ))
                SetNext( GetPrevious( rank.at ), GetNext( last ) );
            else
                sequence.first = GetNext( last );
            if (GetNext( last ))
                SetPrevious( GetNext( last ), GetPrevious( rank.at ) );
            else
                sequence.last = GetPrevious( rank.at );
            SetNext( last, sequence.unused );
            if (sequence.unused)
                SetPrevious( sequence.unused, last );
            sequence.unused = rank.at;
            sequence.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            const bool
                Safety
        >
        static inline bool
        Recede(
            Referential< SinglyJunctive< Natural, Elemental > >
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
            Locational< SinglyNodal< Elemental > >
                previous;
            Natural
                index, offset;
            if (Safety && (!count || !sequence.last || count > sequence.count))
                return false;
            if (count == sequence.count) {
                SetNext( sequence.last, sequence.unused );
                sequence.unused = sequence.first;
                sequence.first = sequence.last = 0;
                sequence.count = 0;
                return true;
            }
            offset = sequence.count - count - 1;
            previous = sequence.first;
            for (index = 0; index < offset; index++) {
                if (Safety && !GetNext( previous ))
                    return false;
                previous = GetNext( previous );
            }
            SetNext( sequence.last, sequence.unused );
            sequence.unused = GetNext( previous );
            UnsetNext( previous );
            sequence.count -= count;
            return true;
        }

        template <
            typename Natural,
            typename Elemental,
            const bool
                Safety
        >
        static inline bool
        Recede(
            Referential< DoublyJunctive< Natural, Elemental > >
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
            Locational< DoublyNodal< Elemental > >
                first, last;
            Natural
                index;
            if (Safety && (!count || !sequence.last))
                return false;
            first = last = sequence.last;
            for (index = 1; index < count; index++) {
                if (Safety && !GetPrevious( first ))
                    return false;
                first = GetPrevious( first );
            }
            sequence.last = GetPrevious( first );
            if (sequence.last) {
                UnsetNext( sequence.last );
                UnsetPrevious( first );
            } else
                sequence.first = 0;
            SetNext( last, sequence.unused );
            if (sequence.unused)
                SetPrevious( sequence.unused, last );
            sequence.unused = first;
            sequence.count -= count;
            return true;
        }

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Conjoint< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Relative, Appositional, RelativeNatural, Elemental >
        SingleConjoiner = {
            Accede< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, false >,
            Precede< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, false >,
            Cede< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, false >,
            Proceed< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, false >
        };

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Conjoint< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Relative, Appositional, RelativeNatural, Elemental >
        DoubleConjoiner = {
            Accede< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, false >,
            Precede< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, false >,
            Cede< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, false >,
            Proceed< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, false >
        };

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Conjoint< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Relative, Appositional, RelativeNatural, Elemental >
        SafeSingleConjoiner = {
            Accede< Relative, Appositional, RelativeNatural, Elemental, Adjunct, true >,
            Precede< Relative, Appositional, RelativeNatural, Elemental, Adjunct, true >,
            Cede< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, true >,
            Proceed< Relative, Appositional, RelativeNatural, Elemental, Adjunct, true >
        };

        template <
            typename Relative,
            typename Appositional,
            typename RelativeNatural,
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Conjoint< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Relative, Appositional, RelativeNatural, Elemental >
        SafeDoubleConjoiner = {
            Accede< Relative, Appositional, RelativeNatural, Elemental, Adjunct, true >,
            Precede< Relative, Appositional, RelativeNatural, Elemental, Adjunct, true >,
            Cede< Relative, Appositional, RelativeNatural, Natural, Elemental, Adjunct, true >,
            Proceed< Relative, Appositional, RelativeNatural, Elemental, Adjunct, true >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sequent< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
        SingleSequencer = {
            Instantiate< SinglyLinked< Elemental >, Natural, Elemental, Adjunct >,
            Account< SinglyLinked< Elemental >, Natural, Elemental >,
            Accede< Natural, Elemental, Adjunct, false >,
            Precede< Natural, Elemental, Adjunct, false >,
            Cede< Natural, Elemental, Adjunct, false >,
            Proceed< Natural, Elemental, Adjunct, false >,
            Succeed< Natural, Elemental, false >,
            Supersede< Natural, Elemental, false >,
            Concede< Natural, Elemental, false >,
            Recede< Natural, Elemental, false >,
            RemoveAll< SinglyLinked< Elemental >, Natural, Elemental >,
            DeleteOneNode< Natural, Elemental, Adjunct >,
            SingleConjoiner< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sequent< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
        DoubleSequencer = {
            Instantiate< DoublyLinked< Elemental >, Natural, Elemental, Adjunct >,
            Account< DoublyLinked< Elemental >, Natural, Elemental >,
            Accede< Natural, Elemental, Adjunct, false >,
            Precede< Natural, Elemental, Adjunct, false >,
            Cede< Natural, Elemental, Adjunct, false >,
            Proceed< Natural, Elemental, Adjunct, false >,
            Succeed< Natural, Elemental, false >,
            Supersede< Natural, Elemental, false >,
            Concede< Natural, Elemental, false >,
            Recede< Natural, Elemental, false >,
            RemoveAll< DoublyLinked< Elemental >, Natural, Elemental >,
            DeleteOneNode< Natural, Elemental, Adjunct >,
            DoubleConjoiner< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const SinglyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sequent< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Elemental >
        SafeSingleSequencer = {
            Instantiate< SinglyLinked< Elemental >, Natural, Elemental, Adjunct >,
            Account< SinglyLinked< Elemental >, Natural, Elemental >,
            Accede< Natural, Elemental, Adjunct, true >,
            Precede< Natural, Elemental, Adjunct, true >,
            Cede< Natural, Elemental, Adjunct, true >,
            Proceed< Natural, Elemental, Adjunct, true >,
            Succeed< Natural, Elemental, true >,
            Supersede< Natural, Elemental, true >,
            Concede< Natural, Elemental, true >,
            Recede< Natural, Elemental, true >,
            RemoveAll< SinglyLinked< Elemental >, Natural, Elemental >,
            DeleteOneNode< Natural, Elemental, Adjunct >,
            SafeSingleConjoiner< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural, Natural, Elemental, Adjunct >
        };

        template <
            typename Natural,
            typename Elemental,
            Referential< const DoublyAdjunctive< Natural, Elemental > >
                Adjunct
        >
        constexpr Sequent< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Elemental >
        SafeDoubleSequencer = {
            Instantiate< DoublyLinked< Elemental >, Natural, Elemental, Adjunct >,
            Account< DoublyLinked< Elemental >, Natural, Elemental >,
            Accede< Natural, Elemental, Adjunct, true >,
            Precede< Natural, Elemental, Adjunct, true >,
            Cede< Natural, Elemental, Adjunct, true >,
            Proceed< Natural, Elemental, Adjunct, true >,
            Succeed< Natural, Elemental, true >,
            Supersede< Natural, Elemental, true >,
            Concede< Natural, Elemental, true >,
            Recede< Natural, Elemental, true >,
            RemoveAll< DoublyLinked< Elemental >, Natural, Elemental >,
            DeleteOneNode< Natural, Elemental, Adjunct >,
            SafeDoubleConjoiner< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural, Natural, Elemental, Adjunct >
        };

    }

}

#endif
