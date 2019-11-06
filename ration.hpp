// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_MODULE
#define RATION_MODULE
#include "location.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

/**
 * @brief   
 *     Memory space rationing.
 * @details 
 *     Array based memory rationing conformity and initialization facility.
 */
namespace ration {

using ::location::Locational;

/**
 * @brief
 *     Memory resource conformity.
 * @details 
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
    Natural Maximum,
    typename Elemental>
struct Resourceful {

    Natural
        allotment; /**< Number of allotted elements. */

    Elemental
        source[Maximum]; /**< Array of memory elements to be rationed. */
};

/**
 * @brief
 *     Constant array resource sequential position type.
 * @details
 *     This type alias is used to represent a position in constant
 *     array sequential trajections.
 * @tparam Elemental
 *     Type of the elements.
 */
template <typename Elemental>
using ReadPositional = Locational<const Elemental>;

/**
 * @brief
 *     Modifiable array resource sequential position type.
 * @details
 *     This type alias is used to represent a position in modifiable
 *     array sequential trajections.
 * @tparam Elemental
 *     Type of the elements.
 */
template <typename Elemental>
using WritePositional = Locational<Elemental>;

/**
 * @brief
 *     Memory move function type.
 * @details 
 *     Type alias which represents functions which move memory within the
 *     resource array.
 * @tparam Natural
 *     Type of natural integer used to specify the __element__ (not byte) count.
 * @tparam Elemental
 *     Type of the rationed memory elements.
 */
template <
    typename Natural,
    typename Elemental>
using MemoryMoving = bool(
    Locational<Elemental>
        from,
    Locational<Elemental>
        to,
    Natural
        count);

/**
 * @brief
 *     Initialized resource.
 * @details 
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
    typename Elemental>
constexpr Resourceful<Natural, Maximum, Elemental>
    InitializedResource = { 0 };

/**
 * @brief
 *     Moves array elements by assignment.
 * @details
 *     Moves count array elements using the assignment operator, from one
 *     position to another within an array.  The direction of the move
 *     determines the order of the assignments.
 * @tparam Natural
 *     Type of natural integer.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] from
 *     Position to move the elements from.
 * @param[in] to
 *     Position to move the elements to.
 * @param[in] count
 *     Number of elements to move.
 * @return 
 *     This implementation always returns true.
 */
template <
    typename Natural,
    typename Elemental>
static inline bool
MoveElements(
    WritePositional<Elemental>
        from,
    WritePositional<Elemental>
        to,
    Natural
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    if (from < to)
        for (Natural index = count; index > 0; index--) {
            const Natural offset = index - 1;
            to[offset] = from[offset];
        }
    else
        for (Natural index = 0; index < count; index++)
            to[index] = from[index];
    return true;
}

}

#endif
