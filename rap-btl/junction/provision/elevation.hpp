// � 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_PROVISION_ELEVATION_MODULE
#define JUNCTION_PROVISION_ELEVATION_MODULE
#include <junction/consecution.hpp>
#include <junction/provision.hpp>
#include <traction.hpp>

namespace junction {

namespace provision {

    /**
     * @brief         
     *     Linked list stack resource management implementation.
     * @details       
     *     Linked list stack resource management implementation.
     */
    namespace elevation {

        using consecution::Recede;
        using ::traction::Tractile;

        template <
            typename Natural,
            typename Elemental>
        constexpr Tractile<SinglyJunctive<Natural, Elemental>, SinglyPositional<Elemental>, Natural>
            SingleElevator = {
                Survey<SinglyLinked<Elemental>, Natural, Elemental>,
                Account<SinglyLinked<Elemental>, Natural, Elemental>,
                Protract<Natural, Elemental, false>,
                Recede<Natural, Elemental>,
                RemoveAll<SinglyLinked<Elemental>, Natural, Elemental>
            };

        template <
            typename Natural,
            typename Elemental>
        constexpr Tractile<DoublyJunctive<Natural, Elemental>, DoublyPositional<Elemental>, Natural>
            DoubleElevator = {
                Survey<DoublyLinked<Elemental>, Natural, Elemental>,
                Account<DoublyLinked<Elemental>, Natural, Elemental>,
                Protract<Natural, Elemental, false>,
                Recede<Natural, Elemental>,
                RemoveAll<DoublyLinked<Elemental>, Natural, Elemental>
            };

    }

}

}

#endif
