// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_PROVISION_CONTRACTION_MODULE
#define SAFE_JUNCTION_PROVISION_CONTRACTION_MODULE
#include "../contraction.hpp"
#include "../../consecution/safe.hpp"

namespace junction {

    namespace provision {

        namespace contraction {

            using consecution::SucceedSafely;

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< SinglyNodal< Elemental > > >
                    Allocator
            >
            constexpr Tractile< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural >
                SafeSingleContractor = {
                    Survey< SinglyLinked< Elemental >, Natural, Maximum, Elemental >,
                    Account< SinglyLinked< Elemental >, Natural, Elemental >,
                    Protract< Natural, Maximum, Elemental, Allocator, true >,
                    SucceedSafely< Natural, Elemental >,
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
            constexpr Tractile< DoublyJunctive< Natural, Elemental >, DoublyPositional< Elemental >, Natural >
                SafeDoubleContractor = {
                    Survey< DoublyLinked< Elemental >, Natural, Maximum, Elemental >,
                    Account< DoublyLinked< Elemental >, Natural, Elemental >,
                    Protract< Natural, Maximum, Elemental, Allocator, true >,
                    SucceedSafely< Natural, Elemental >,
                    RemoveAll< DoublyLinked< Elemental >, Natural, Elemental >
                };

        }

    }

}

#endif
