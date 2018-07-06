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

            using namespace ::attribution;

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
                using namespace ::std;
                static_assert(
                    is_integral< Natural >::value && is_unsigned< Natural >::value,
                    "Natural:  Unsigned integer type required"
                );
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
                consecution::Account< Natural, Elemental >,
                Protract< Natural, Elemental, Allocator >,
                Retribute< Natural, Elemental >,
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
            constexpr Tributary< Junctive< Natural, Elemental >, Positional< Elemental >, Natural >
            SafeContributor = {
                Survey< Natural, Maximum, Elemental >,
                consecution::Account< Natural, Elemental >,
                ProtractSafely< Natural, Maximum, Elemental, Allocator >,
                Retribute< Natural, Elemental >,
                Empty< Natural, Elemental >
            };

        }

    }

}

#endif
