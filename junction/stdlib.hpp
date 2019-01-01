// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_STDLIB_MODULE
#define JUNCTION_STDLIB_MODULE
#include "../junction.hpp"
#include "../allocation/stdlib.hpp"

namespace junction {

    /**
     * @brief         
     *     Linked list standard library based memory allocation implementation.
     * @details       
     *     Association
     *     -----------
     *     Linked list standard library based memory allocation implementation.
     */
    namespace stdlib {

        using ::allocation::stdlib::FastDefaultMalloc;
        using ::allocation::stdlib::FastDefaultCalloc;

        template <
            typename Natural,
            typename Elemental
        >
        constexpr SinglyAdjunctive< Natural, Elemental >
            DefaultMallocSingleAdjunct = {
                AllocateDefault< SinglyLinked< Elemental >, DefaultDisclaimable< SinglyNodal< Elemental > >, Natural, Elemental, FastDefaultMalloc< SinglyNodal< Elemental > > >,
                DeallocateDefault< SinglyLinked< Elemental >, DefaultClaimable< SinglyNodal< Elemental > >, Natural, Elemental, FastDefaultMalloc< SinglyNodal< Elemental > > >,
                ProclaimDefault< SinglyLinked< Elemental >, DefaultDisclaimable< SinglyNodal< Elemental > >, Natural, Elemental, FastDefaultMalloc< SinglyNodal< Elemental > > >
            };

        template <
            typename Natural,
            typename Elemental
        >
        constexpr DoublyAdjunctive< Natural, Elemental >
            DefaultMallocDoubleAdjunct = {
                AllocateDefault< DoublyLinked< Elemental >, DefaultDisclaimable< DoublyNodal< Elemental > >, Natural, Elemental, FastDefaultMalloc< DoublyNodal< Elemental > > >,
                DeallocateDefault< DoublyLinked< Elemental >, DefaultClaimable< DoublyNodal< Elemental > >, Natural, Elemental, FastDefaultMalloc< DoublyNodal< Elemental > > >,
                ProclaimDefault< DoublyLinked< Elemental >, DefaultDisclaimable< DoublyNodal< Elemental > >, Natural, Elemental, FastDefaultMalloc< DoublyNodal< Elemental > > >
            };

        template <
            typename Natural,
            typename Elemental
        >
        constexpr SinglyAdjunctive< Natural, Elemental >
            DefaultCallocSingleAdjunct = {
                AllocateDefault< SinglyLinked< Elemental >, DefaultDisclaimable< SinglyNodal< Elemental > >, Natural, Elemental, FastDefaultCalloc< SinglyNodal< Elemental > > >,
                DeallocateDefault< SinglyLinked< Elemental >, DefaultClaimable< SinglyNodal< Elemental > >, Natural, Elemental, FastDefaultCalloc< SinglyNodal< Elemental > > >,
                ProclaimDefault< SinglyLinked< Elemental >, DefaultDisclaimable< SinglyNodal< Elemental > >, Natural, Elemental, FastDefaultCalloc< SinglyNodal< Elemental > > >
            };

        template <
            typename Natural,
            typename Elemental
        >
        constexpr DoublyAdjunctive< Natural, Elemental >
            DefaultCallocDoubleAdjunct = {
                AllocateDefault< DoublyLinked< Elemental >, DefaultDisclaimable< DoublyNodal< Elemental > >, Natural, Elemental, FastDefaultCalloc< DoublyNodal< Elemental > > >,
                DeallocateDefault< DoublyLinked< Elemental >, DefaultClaimable< DoublyNodal< Elemental > >, Natural, Elemental, FastDefaultCalloc< DoublyNodal< Elemental > > >,
                ProclaimDefault< DoublyLinked< Elemental >, DefaultDisclaimable< DoublyNodal< Elemental > >, Natural, Elemental, FastDefaultCalloc< DoublyNodal< Elemental > > >
            };

    }

}

#endif
