// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_CONTRIBUTION_PROVISION_MODULE
#define JUNCTION_CONTRIBUTION_PROVISION_MODULE
#include "../consecution.hpp"
#include "../provision.hpp"
#include "../../attribution.hpp"

namespace junction {

    namespace provision {

        namespace contribution {

            using ::attribution::Tributary;

            template <
                typename Natural,
                typename Elemental,
                Referential< const DefaultAllocative< Junctional< Elemental > > >
                    Allocator
            >
            static inline bool
            Distribute(
                Referential< Junctive< Natural, Elemental > >
                    list,
                Referential< Positional< Elemental > >
                    position
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                position.at = Reclaim( list );
                if (!position.at) {
                    Allocator.claim( position.at );
                    if (!position.at)
                        return false;
                    list.total++;
                    position.at->next = 0;
                }
                position.at->previous = list.last;
                if (list.last)
                    list.last->next = position.at;
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
                Referential< const DefaultAllocative< Junctional< Elemental > > >
                    Allocator
            >
            static inline bool
            DistributeSafely(
                Referential< Junctive< Natural, Elemental > >
                    list,
                Referential< Positional< Elemental > >
                    position
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                if (list.count >= Maximum)
                    return false;
                return Distribute( list, position );
            }

            template <
                typename Natural,
                typename Elemental
            >
            static inline bool
            Retribute(
                Referential< Junctive< Natural, Elemental > >
                    list,
                Referential< const Positional< Elemental > >
                    position
            ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
#endif
                static const Natural
                    Count = 1;
                return consecution::Concede( list, position, Count );
            }

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< Junctional< Elemental > > >
                    Allocator
            >
            constexpr Tributary< Junctive< Natural, Elemental >, Positional< Elemental >, Natural >
            Contributor = {
                Survey< Natural, Maximum, Elemental >,
                Account< Natural, Elemental >,
                Distribute< Natural, Elemental, Allocator >,
                Retribute< Natural, Elemental >,
                RemoveAllNodes< Natural, Elemental >
            };

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< Junctional< Elemental > > >
                    Allocator
            >
            constexpr Tributary< Junctive< Natural, Elemental >, Positional< Elemental >, Natural >
            SafeContributor = {
                Survey< Natural, Maximum, Elemental >,
                Account< Natural, Elemental >,
                DistributeSafely< Natural, Maximum, Elemental, Allocator >,
                Retribute< Natural, Elemental >,
                RemoveAllNodes< Natural, Elemental >
            };

        }

    }

}

#endif
