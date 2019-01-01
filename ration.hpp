// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_MODULE
#define RATION_MODULE
#include <type_traits>

/**
 * @brief   
 *     Memory space rationing.
 * @details 
 *     Association
 *     -----------
 *     Array based memory rationing conformity and initialization facility.
 */
namespace ration {

    /**
     * @brief
     *     Memory resource conformity.
     * @details 
     *     Conformation Template
     *     ---------------------
     *     Type definition which contains an allotment tracker and an array of 
     *     memory elements.  This type is used verbatim in the stack 
     *     implementation in the elevation inner namespace and incorporated
     *     into the queue and pool implementations in the contraction and
     *     contribution inner namespaces respectively.
     * @tparam Natural
     *     Type of natural integer used to track allotments.
     * @tparam Maximum
     *     The maximum number of elements and size of the array.
     * @tparam Elemental
     *     Type of the rationed memory elements.
     */
    template <
        typename Natural,
        Natural
            Maximum,
        typename Elemental
    >
    struct Resourceful {

        Natural
            allotment; /**< Number of allotted elements. */

        Elemental
            source[Maximum]; /**< Array of memory elements to be rationed. */

    };

    /**
     * @brief
     *     Initialized resource.
     * @details 
     *     Information Template
     *     --------------------
     *     Initialized resource value which can be used to initialize an 
     *     instance of the same resource type.
     * @tparam Natural
     *     Type of natural integer used to track allotments.
     * @tparam Maximum
     *     The maximum number of elements and size of the array.
     * @tparam Elemental
     *     Type of the rationed memory elements.
     */
    template <
        typename Natural,
        Natural
            Maximum,
        typename Elemental
    >
    constexpr Resourceful< Natural, Maximum, Elemental >
        InitializedResource = {0};

}

#endif
