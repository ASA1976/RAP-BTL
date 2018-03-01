// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_STDLIB_MODULE
#define JUNCTION_STDLIB_MODULE
#include "../junction.hpp"
#include "../allocation/stdlib.hpp"

namespace junction {

    namespace stdlib {

        using namespace ::allocation::stdlib;

        template <
            typename Natural,
            typename Elemental
        >
        constexpr Adjunctive< Natural, Elemental >
        DefaultMallocAdjunct = {
            AllocateDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, FastDefaultMalloc< Junctional< Elemental > > >,
            DeallocateDefault< DefaultClaimable< Junctional< Elemental > >, Natural, Elemental, FastDefaultMalloc< Junctional< Elemental > > >,
            ProclaimDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, FastDefaultMalloc< Junctional< Elemental > > >
        };

        template <
            typename Natural,
            typename Elemental
        >
        constexpr Adjunctive< Natural, Elemental >
        DefaultCallocAdjunct = {
            AllocateDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, FastDefaultCalloc< Junctional< Elemental > > >,
            DeallocateDefault< DefaultClaimable< Junctional< Elemental > >, Natural, Elemental, FastDefaultCalloc< Junctional< Elemental > > >,
            ProclaimDefault< DefaultDisclaimable< Junctional< Elemental > >, Natural, Elemental, FastDefaultCalloc< Junctional< Elemental > > >
        };

    }

}

#endif
