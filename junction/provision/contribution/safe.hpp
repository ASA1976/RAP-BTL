// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_PROVISION_CONTRIBUTION_MODULE
#define SAFE_JUNCTION_PROVISION_CONTRIBUTION_MODULE
#include "../contribution.hpp"
#include "../../consecution/safe.hpp"

namespace junction {

    namespace provision {

        namespace contribution {

            using consecution::ConcedeSafely;

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
