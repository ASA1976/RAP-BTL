// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_CONTRIBUTION_MODULE
#define JUNCTION_CONTRIBUTION_MODULE
#include "../allocation/contribution.hpp"
#include "../junction.hpp"

namespace junction {

    namespace contribution {

        using ::ration::contribution::Contributory;
        using ::allocation::contribution::FastPoolAllocator;
        using ::allocation::contribution::SurePoolAllocator;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental,
            Referential< Contributory< Natural, Maximum, SinglyNodal< Elemental > > >
                Pool
        >
        constexpr SinglyAdjunctive< Natural, Elemental >
            FastPoolSingleAdjunct = {
                AllocateDefault< SinglyLinked< Elemental >, DefaultDisclaimable< SinglyNodal< Elemental > >, Natural, Elemental, FastPoolAllocator< Natural, Maximum, SinglyNodal< Elemental >, Pool > >,
                DeallocateDefault< SinglyLinked< Elemental >, DefaultClaimable< SinglyNodal< Elemental > >, Natural, Elemental, FastPoolAllocator< Natural, Maximum, SinglyNodal< Elemental >, Pool > >,
                ProclaimDefault< SinglyLinked< Elemental >, DefaultDisclaimable< SinglyNodal< Elemental > >, Natural, Elemental, FastPoolAllocator< Natural, Maximum, SinglyNodal< Elemental >, Pool > >
            };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental,
            Referential< Contributory< Natural, Maximum, DoublyNodal< Elemental > > >
                Pool
        >
        constexpr DoublyAdjunctive< Natural, Elemental >
            FastPoolDoubleAdjunct = {
                AllocateDefault< DoublyLinked< Elemental >, DefaultDisclaimable< DoublyNodal< Elemental > >, Natural, Elemental, FastPoolAllocator< Natural, Maximum, DoublyNodal< Elemental >, Pool > >,
                DeallocateDefault< DoublyLinked< Elemental >, DefaultClaimable< DoublyNodal< Elemental > >, Natural, Elemental, FastPoolAllocator< Natural, Maximum, DoublyNodal< Elemental >, Pool > >,
                ProclaimDefault< DoublyLinked< Elemental >, DefaultDisclaimable< DoublyNodal< Elemental > >, Natural, Elemental, FastPoolAllocator< Natural, Maximum, DoublyNodal< Elemental >, Pool > >
            };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental,
            Referential< Contributory< Natural, Maximum, SinglyNodal< Elemental > > >
                Pool
        >
        constexpr SinglyAdjunctive< Natural, Elemental >
            SurePoolSingleAdjunct = {
                AllocateDefault< SinglyLinked< Elemental >, DefaultDisclaimable< SinglyNodal< Elemental > >, Natural, Elemental, SurePoolAllocator< Natural, Maximum, SinglyNodal< Elemental >, Pool > >,
                DeallocateDefault< SinglyLinked< Elemental >, DefaultClaimable< SinglyNodal< Elemental > >, Natural, Elemental, SurePoolAllocator< Natural, Maximum, SinglyNodal< Elemental >, Pool > >,
                ProclaimDefault< SinglyLinked< Elemental >, DefaultDisclaimable< SinglyNodal< Elemental > >, Natural, Elemental, SurePoolAllocator< Natural, Maximum, SinglyNodal< Elemental >, Pool > >
            };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental,
            Referential< Contributory< Natural, Maximum, DoublyNodal< Elemental > > >
                Pool
        >
        constexpr DoublyAdjunctive< Natural, Elemental >
            SurePoolDoubleAdjunct = {
                AllocateDefault< DoublyLinked< Elemental >, DefaultDisclaimable< DoublyNodal< Elemental > >, Natural, Elemental, SurePoolAllocator< Natural, Maximum, DoublyNodal< Elemental >, Pool > >,
                DeallocateDefault< DoublyLinked< Elemental >, DefaultClaimable< DoublyNodal< Elemental > >, Natural, Elemental, SurePoolAllocator< Natural, Maximum, DoublyNodal< Elemental >, Pool > >,
                ProclaimDefault< DoublyLinked< Elemental >, DefaultDisclaimable< DoublyNodal< Elemental > >, Natural, Elemental, SurePoolAllocator< Natural, Maximum, DoublyNodal< Elemental >, Pool > >
            };

    }

}

#endif
