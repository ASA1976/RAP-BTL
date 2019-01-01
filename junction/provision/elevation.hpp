// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_PROVISION_ELEVATION_MODULE
#define JUNCTION_PROVISION_ELEVATION_MODULE
#include "../consecution.hpp"
#include "../provision.hpp"
#include "../../traction.hpp"

namespace junction {

    namespace provision {

        /**
         * @brief         
         *     Linked list stack resource management implementation.
         * @details       
         *     Association
         *     -----------
         *     Linked list stack resource management implementation.
         */
        namespace elevation {

            using ::traction::Tractile;
            using consecution::Succeed;
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
                SingleElevator = {
                    Survey< SinglyLinked< Elemental >, Natural, Maximum, Elemental >,
                    Account< SinglyLinked< Elemental >, Natural, Elemental >,
                    Protract< Natural, Maximum, Elemental, Allocator, false >,
                    Succeed< Natural, Elemental >,
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
                DoubleElevator = {
                    Survey< DoublyLinked< Elemental >, Natural, Maximum, Elemental >,
                    Account< DoublyLinked< Elemental >, Natural, Elemental >,
                    Protract< Natural, Maximum, Elemental, Allocator, false >,
                    Succeed< Natural, Elemental >,
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
            constexpr Tractile< SinglyJunctive< Natural, Elemental >, SinglyPositional< Elemental >, Natural >
                SafeSingleElevator = {
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
                SafeDoubleElevator = {
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
