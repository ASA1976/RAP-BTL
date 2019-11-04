// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_PROVISION_CONTRIBUTION_MODULE
#define SAFE_JUNCTION_PROVISION_CONTRIBUTION_MODULE
#include "../../consecution/safe.hpp"
#include "../contribution.hpp"

namespace junction {

namespace provision {

namespace contribution {

using consecution::ConcedeSafely;

template <
    typename Natural,
    typename Elemental>
constexpr Tributary<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural>
    SafeSingleContributor = {
        Survey<SinglyLinked<Elemental>, Natural, Elemental>,
        Account<SinglyLinked<Elemental>, Natural, Elemental>,
        Distribute<Natural, Elemental, true>,
        Retribute<SinglyLinked<Elemental>, Natural, Elemental, ConcedeSafely<Natural, Elemental>>,
        RemoveAll<SinglyLinked<Elemental>, Natural, Elemental>
    };

template <
    typename Natural,
    typename Elemental>
constexpr Tributary<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural>
    SafeDoubleContributor = {
        Survey<DoublyLinked<Elemental>, Natural, Elemental>,
        Account<DoublyLinked<Elemental>, Natural, Elemental>,
        Distribute<Natural, Elemental, true>,
        Retribute<DoublyLinked<Elemental>, Natural, Elemental, ConcedeSafely<Natural, Elemental>>,
        RemoveAll<DoublyLinked<Elemental>, Natural, Elemental>
    };

}

}

}

#endif
