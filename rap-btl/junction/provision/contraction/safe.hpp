// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_JUNCTION_PROVISION_CONTRACTION_MODULE
#define SAFE_JUNCTION_PROVISION_CONTRACTION_MODULE
#include <junction/consecution/safe.hpp>
#include <junction/provision/contraction.hpp>

namespace junction {

namespace provision {

    namespace contraction {

        using consecution::SucceedSafely;

        template <
            typename Natural,
            typename Elemental>
        constexpr Tractile<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural>
            SafeSingleContractor = {
                Survey<SinglyLinked<Elemental>, Natural, Elemental>,
                Account<SinglyLinked<Elemental>, Natural, Elemental>,
                Protract<Natural, Elemental, true>,
                SucceedSafely<Natural, Elemental>,
                RemoveAll<SinglyLinked<Elemental>, Natural, Elemental>
            };

        template <
            typename Natural,
            typename Elemental>
        constexpr Tractile<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural>
            SafeDoubleContractor = {
                Survey<DoublyLinked<Elemental>, Natural, Elemental>,
                Account<DoublyLinked<Elemental>, Natural, Elemental>,
                Protract<Natural, Elemental, true>,
                SucceedSafely<Natural, Elemental>,
                RemoveAll<DoublyLinked<Elemental>, Natural, Elemental>
            };

    }

}

}

#endif
