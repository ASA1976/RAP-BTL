// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_PROVISION_CONTRIBUTION_MODULE
#define JUNCTION_PROVISION_CONTRIBUTION_MODULE
#include "../consecution.hpp"
#include "../provision.hpp"
#include "../../attribution.hpp"

namespace junction {

    namespace provision {

        /**
         * @brief         
         *     Linked list pool resource management implementation.
         * @details       
         *     Association
         *     -----------
         *     Linked list pool resource management implementation.
         */
        namespace contribution {

            using ::attribution::Tributary;
            using consecution::Concessive;
            using consecution::Concede;
            using consecution::ConcedeSafely;

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< SinglyNodal< Elemental > > >
                    Allocator,
                const bool
                    Safety
            >
            static inline bool
            Distribute(
                Referential< SinglyJunctive< Natural, Elemental > >
                    list,
                Referential< SinglyPositional< Elemental > >
                    position
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                if (Safety && list.count >= Maximum)
                    return false;
                position.at = Reclaim( list );
                if (!position.at) {
                    Allocator.claim( position.at );
                    if (!position.at)
                        return false;
                    list.total++;
                }
                UnsetNext( position.at );
                if (list.last)
                    SetNext( list.last, position.at );
                else
                    list.first = position.at;
                list.last = position.at;
                list.count++;
                return true;
            }

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< DoublyNodal< Elemental > > >
                    Allocator,
                const bool
                    Safety
            >
            static inline bool
            Distribute(
                Referential< DoublyJunctive< Natural, Elemental > >
                    list,
                Referential< DoublyPositional< Elemental > >
                    position
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                if (Safety && list.count >= Maximum)
                    return false;
                position.at = Reclaim( list );
                if (!position.at) {
                    Allocator.claim( position.at );
                    if (!position.at)
                        return false;
                    list.total++;
                }
                UnsetNext( position.at );
                SetPrevious( position.at, list.last );
                if (list.last)
                    SetNext( list.last, position.at );
                else
                    list.first = position.at;
                list.last = position.at;
                list.count++;
                return true;
            }

            template <
                typename Connective,
                typename Natural,
                typename Elemental,
                Referential< Concessive< Connective, Natural, Elemental > >
                    Concede
            >
            static inline bool
            Retribute(
                Referential< Junctive< Connective, Natural, Elemental > >
                    list,
                Referential< const Positional< Connective, Elemental > >
                    position
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                return Concede( list, position, 1 );
            }

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< SinglyNodal< Elemental > > >
                    Allocator
            >
            constexpr Tributary< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural >
                SingleContributor = {
                    Survey< SinglyLinked< Elemental >, Natural, Maximum, Elemental >,
                    Account< SinglyLinked< Elemental >, Natural, Elemental >,
                    Distribute< Natural, Maximum, Elemental, Allocator, false >,
                    Retribute< SinglyLinked< Elemental >, Natural, Elemental, Concede< Natural, Elemental > >,
                    RemoveAll< SinglyLinked< Elemental >, Natural, Elemental >
                };

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< DoublyNodal< Elemental > > >
                    Allocator
            >
            constexpr Tributary< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural >
                DoubleContributor = {
                    Survey< DoublyLinked< Elemental >, Natural, Maximum, Elemental >,
                    Account< DoublyLinked< Elemental >, Natural, Elemental >,
                    Distribute< Natural, Maximum, Elemental, Allocator, false >,
                    Retribute< DoublyLinked< Elemental >, Natural, Elemental, Concede< Natural, Elemental > >,
                    RemoveAll< DoublyLinked< Elemental >, Natural, Elemental >
                };

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< SinglyNodal< Elemental > > >
                    Allocator
            >
            constexpr Tributary< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural >
                SafeSingleContributor = {
                    Survey< SinglyLinked< Elemental >, Natural, Maximum, Elemental >,
                    Account< SinglyLinked< Elemental >, Natural, Elemental >,
                    Distribute< Natural, Maximum, Elemental, Allocator, true >,
                    Retribute< SinglyLinked< Elemental >, Natural, Elemental, ConcedeSafely< Natural, Elemental > >,
                    RemoveAll< SinglyLinked< Elemental >, Natural, Elemental >
                };

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< DoublyNodal< Elemental > > >
                    Allocator
            >
            constexpr Tributary< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural >
                SafeDoubleContributor = {
                    Survey< DoublyLinked< Elemental >, Natural, Maximum, Elemental >,
                    Account< DoublyLinked< Elemental >, Natural, Elemental >,
                    Distribute< Natural, Maximum, Elemental, Allocator, true >,
                    Retribute< DoublyLinked< Elemental >, Natural, Elemental, ConcedeSafely< Natural, Elemental > >,
                    RemoveAll< DoublyLinked< Elemental >, Natural, Elemental >
                };

        }

    }

}

#endif
