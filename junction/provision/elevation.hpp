// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_ELEVATION_PROVISION_MODULE
#define JUNCTION_ELEVATION_PROVISION_MODULE
#include "../consecution.hpp"
#include "../provision.hpp"
#include "../../traction.hpp"

namespace junction {

    namespace provision {

        namespace elevation {

            using namespace ::traction;
            using consecution::Succeed;

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< Junctional< Elemental > > >
                    Allocator
            >
            constexpr Tractile< Junctive< Natural, Elemental >, Positional< Elemental >, Natural >
            Elevator = {
                Survey< Natural, Maximum, Elemental >,
                Account< Natural, Elemental >,
                Protract< Natural, Elemental, Allocator >,
                Succeed< Natural, Elemental >,
                Empty< Natural, Elemental >
            };

            template <
                typename Natural,
                Natural
                    Maximum,
                typename Elemental,
                Referential< const DefaultAllocative< Junctional< Elemental > > >
                    Allocator
            >
            constexpr Tractile< Junctive< Natural, Elemental >, Positional< Elemental >, Natural >
            SafeElevator = {
                Survey< Natural, Maximum, Elemental >,
                Account< Natural, Elemental >,
                ProtractSafely< Natural, Maximum, Elemental, Allocator >,
                Succeed< Natural, Elemental >,
                Empty< Natural, Elemental >
            };

        }

    }

}

#endif
