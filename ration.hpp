// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_MODULE
#define RATION_MODULE
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

/**
 * @brief   
 *     Memory space rationing.
 * @details 
 *     Association
 *     -----------
 *     Array based memory rationing conformity and initialization facility.
 */
namespace ration {

    using ::location::Locational;

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

    template <
        typename Elemental
    >
    using ReadPositional = Locational< const Elemental >;

    template <
        typename Elemental
    >
    using WritePositional = Locational< Elemental >;

    /**
     * @brief
     *     Memory move function type.
     * @details 
     *     Type alias which represents functions which move memory within an 
     *     array.
     * @tparam Natural
     *     Type of natural integer used to specify counts.
     * @tparam Elemental
     *     Type of the rationed memory elements.
     */
    template <
        typename Natural,
        typename Elemental
    >
    using MemoryMoving = bool(
        Locational< Elemental >,
        Locational< Elemental >,
        Natural
    );

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

    template <
        typename Natural,
        typename Elemental
    >
    static inline bool
    MoveElements(
        WritePositional< Elemental >
            from,
        WritePositional< Elemental >
            to,
        Natural
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        Natural 
            index;
        if (from < to)
            for (index = count; index > 0; index--) {
                const Natural offset = index - 1;
                to[offset] = from[offset];
            }
        else
            for (index = 0; index < count; index++)
                to[index] = from[index];
        return true;
    }

}

#endif
