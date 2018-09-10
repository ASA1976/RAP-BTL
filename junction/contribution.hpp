// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_CONTRIBUTION_MODULE
#define JUNCTION_CONTRIBUTION_MODULE
#include "../allocation/contribution.hpp"
#include "../junction.hpp"

namespace junction {

    namespace contribution {

        using ::ration::contribution::Contributory;
        using ::allocation::contribution::FastPoolAllocator;
        using ::allocation::contribution::SafePoolAllocator;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental,
            Referential< Contributory< Natural, Maximum, Junctional< Elemental > > >
                Pool
        >
        constexpr Adjunctive< Natural, Elemental >
        FastPoolAdjunct = {
            AllocateDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, FastPoolAllocator< Natural, Maximum, Junctional< Elemental >, Pool > >,
            DeallocateDefault< DefaultClaimable< Junctional< Elemental > >, Natural, Elemental, FastPoolAllocator< Natural, Maximum, Junctional< Elemental >, Pool > >,
            ProclaimDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, FastPoolAllocator< Natural, Maximum, Junctional< Elemental >, Pool > >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental,
            Referential< Contributory< Natural, Maximum, Junctional< Elemental > > >
                Pool
        >
        constexpr Adjunctive< Natural, Elemental >
        SafePoolAdjunct = {
            AllocateDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, SafePoolAllocator< Natural, Maximum, Junctional< Elemental >, Pool > >,
            DeallocateDefault< DefaultClaimable< Junctional< Elemental > >, Natural, Elemental, SafePoolAllocator< Natural, Maximum, Junctional< Elemental >, Pool > >,
            ProclaimDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, SafePoolAllocator< Natural, Maximum, Junctional< Elemental >, Pool > >
        };

    }

}

#endif
