// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_PROVISION_CONTRACTION_MODULE
#define JUNCTION_PROVISION_CONTRACTION_MODULE
#include "../../traction.hpp"
#include "../consecution.hpp"
#include "../provision.hpp"

namespace junction {

namespace provision {

    /**
     * @brief         
     *     Linked list queue resource management implementation.
     * @details       
     *     Linked list queue resource management implementation.
     */
    namespace contraction {

        using consecution::Succeed;
        using ::traction::Tractile;

        template <
            typename Natural,
            typename Elemental>
        constexpr Tractile<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural>
            SingleContractor = {
                Survey<SinglyLinked<Elemental>, Natural, Elemental>,
                Account<SinglyLinked<Elemental>, Natural, Elemental>,
                Protract<Natural, Elemental, false>,
                Succeed<Natural, Elemental>,
                RemoveAll<SinglyLinked<Elemental>, Natural, Elemental>
            };

        template <
            typename Natural,
            typename Elemental>
        constexpr Tractile<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural>
            DoubleContractor = {
                Survey<DoublyLinked<Elemental>, Natural, Elemental>,
                Account<DoublyLinked<Elemental>, Natural, Elemental>,
                Protract<Natural, Elemental, false>,
                Succeed<Natural, Elemental>,
                RemoveAll<DoublyLinked<Elemental>, Natural, Elemental>
            };

    }

}

}

#endif
