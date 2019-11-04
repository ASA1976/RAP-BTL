// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_ELEVATION_MODULE
#define RATION_ELEVATION_MODULE
#include "../ration.hpp"
#include "../traction.hpp"
#include "../trajection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

/**
 * @brief
 *     Stack rationing.
 * @details 
 *     Array based stack rationing conformity, initialization facility, 
 *     tractile management and sequential trajection implementations.
 */
namespace elevation {

using ::comparison::Comparison;
using ::location::Conferential;
using ::location::Referential;
using ::traction::Tractile;
using ::trajection::Axial;
using ::trajection::Directional;
using ::trajection::Lineal;
using ::trajection::Scalar;
using ::trajection::Vectorial;

/**
 * @brief
 *     Stack resource conformity.
 * @details
 *     Type alias which defines stack data as a memory resource.
 * @tparam Natural 
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
using Elevatory = Resourceful<Natural, Maximum, Elemental>;

/**
 * @brief
 *     Initialized stack.
 * @details 
 *     Initialized stack value which can be used to initialize an 
 *     instance of the same stack type.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Elevatory<Natural, Maximum, Elemental>
    InitializedStack = InitializedResource<Natural, Maximum, Elemental>;

/**
 * @brief
 *     Check if index is an allotted stack position.
 * @details
 *     Checks if index is a currently allotted stack element.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum
 *     The maximum number of elements.
 * @tparam Elemental
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in] index
 *     Reference to the index.
 * @return
 *     True if index is allotted.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline bool
Contains(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        index)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index < stack.allotment;
}

/**
 * @brief 
 *     Confers the element at index.
 * @details
 *     Returns a modifiable reference to the element at the specified 
 *     index.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in] index
 *     Reference to the index.
 * @return
 *     The reference conferment.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Conferential<Elemental>
GoWrite(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        index)
{
    using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return Confer(stack.source[index]);
}

/**
 * @brief
 *     Deters the element at index.
 * @details
 *     Returns a constant reference to the element at the specified 
 *     positional index.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum
 *     The maximum number of elements.
 * @tparam Elemental
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in] index
 *     Reference to the index.
 * @return
 *     The reference determent.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Conferential<const Elemental>
GoRead(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        index)
{
    using ::location::Deter;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return Deter(stack.source[index]);
}

/**
 * @brief
 *     Checks if sequential trajection can begin.
 * @details
 *     Checks if sequential trajection can begin at the specified offset
 *     count.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     True if the offset can be reached from the either the increment
 *     or decrement beginnings.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline bool
Begins(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return count < stack.allotment;
}

/**
 * @brief
 *     Begins read increment trajection.
 * @details
 *     Assigns to index the count offset from the beginning of the 
 *     stack, which begins at the first protracted element.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @param[out] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     A reference to the index as a constant.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Referential<const Natural>
BeginReadIncrement(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index = count;
}

/**
 * @brief
 *     Begins write increment trajection.
 * @details
 *     Assigns to index the count offset from the beginning of the 
 *     stack, which begins at the first protracted element.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[out] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return
 *     A reference to the index as a constant.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Referential<const Natural>
BeginWriteIncrement(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index = count;
}

/**
 * @brief
 *     Checks if sequential trajection can continue.
 * @details
 *     Checks if sequential trajection can traverse from index to the
 *     specified count offset.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     True if the offset can be reached from index.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline bool
IncrementTraverses(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index + count < stack.allotment;
}

/**
 * @brief 
 *     Traverses read increment.
 * @details
 *     Increases index by count offset.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in,out] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     A reference to the index as a constant.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Referential<const Natural>
TraverseReadIncrement(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index += count;
}

/**
 * @brief 
 *     Traverses write increment.
 * @details
 *     Increases index by count offset.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in,out] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     A reference to the index as a constant.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Referential<const Natural>
TraverseWriteIncrement(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index += count;
}

/**
 * @brief
 *     Begins read decrement trajection.
 * @details
 *     Assigns to index the count offset from the end of the stack, 
 *     which ends at the last protracted element.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @param[out] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     A reference to the index as a constant.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Referential<const Natural>
BeginReadDecrement(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index = stack.allotment - 1 - count;
}

/**
 * @brief
 *     Begins write decrement trajection.
 * @details
 *     Assigns to index the count offset from the end of the stack, 
 *     which ends at the last protracted element.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @param[out] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     A reference to the index as a constant.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Referential<const Natural>
BeginWriteDecrement(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index = stack.allotment - 1 - count;
}

/**
 * @brief
 *     Checks if sequential trajection can continue.
 * @details
 *     Checks if sequential trajection can traverse from index to the
 *     specified count offset.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     True if the offset can be reached from index.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline bool
DecrementTraverses(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return count <= index;
}

/**
 * @brief 
 *     Traverses read decrement.
 * @details
 *     Decreases index by count offset.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in,out] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     A reference to the index as a constant.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Referential<const Natural>
TraverseReadDecrement(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index -= count;
}

/**
 * @brief 
 *     Traverses write decrement.
 * @details
 *     Decreases index by count offset.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack
 *     Reference to the stack.
 * @param[in,out] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     A reference to the index as a constant.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Referential<const Natural>
TraverseWriteDecrement(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index -= count;
}

/**
 * @brief 
 *     Initializes the stack.
 * @details
 *     Initializes the stack allotment to zero.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @return 
 *     A reference to the stack.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Referential<Elevatory<Natural, Maximum, Elemental>>
Initialize(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    stack.allotment = 0;
    return stack;
}

/**
 * @brief 
 *     Empties the stack.
 * @details
 *     Retracts all protracted elements in the stack.  Returns true only
 *     if there were allotted elements in the stack before the call.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @return 
 *     True if the stack was altered by this operation.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline bool
Contract(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    if (!stack.allotment)
        return false;
    Initialize(stack);
    return true;
}

/**
 * @brief 
 *     Returns the maximum size of the stack.
 * @details
 *     Returns the maximum size of the stack.  This function may or may
 *     not incur run-time overhead depending on the invocation context.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @return 
 *     The maximum number of stack elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Natural
Survey(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return Maximum;
}

/**
 * @brief 
 *     Returns the number of protracted elements in the stack.
 * @details
 *     Returns the number of protracted elements in the stack which
 *     defaults to zero if the stack was properly initialized.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @return 
 *     The number of allotted elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Natural
Account(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return stack.allotment;
}

/**
 * @brief 
 *     Returns the number of protracted elements __after__ index.
 * @details
 *     Returns the number of protracted elements in the stack __after__
 *     the specified index (does not include the element at index).
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @param[in] index 
 *     Reference to the index.
 * @return 
 *     The number of elements __after__ index.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Natural
CountIncrement(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        index)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return stack.allotment - 1 - index;
}

/**
 * @brief 
 *     Returns the number of protracted elements __before__ index.
 * @details
 *     Returns the number of protracted elements in the stack 
 *     __before__ the specified index (does not include the element at
 *     index).
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @param[in] index 
 *     Reference to the index.
 * @return 
 *     The number of elements __before__ index.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline Natural
CountDecrement(
    Referential<const Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        index)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index;
}

/**
 * @brief 
 *     Protracts elements to the end of the stack.
 * @details
 *     Protracts elements to the end of the stack.  This version does
 *     not verify if count is zero or if more elements have been 
 *     requested than are available in the stack.  Use this version only
 *     if stringent performance is required.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @param[out] index 
 *     Reference to the index.
 * @param[in] count 
 *     Reference to the count.
 * @return 
 *     Always returns true.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline bool
Increase(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    index = stack.allotment;
    stack.allotment += count;
    return true;
}

/**
 * @brief 
 *     Protracts elements to the end of the stack.
 * @details
 *     Protracts elements to the end of the stack.  This version will
 *     return false is count is zero or more elements have been 
 *     requested than are available in the stack.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @param[out] index 
 *     Reference to the index.
 * @param[in] count 
 *     Reference to the count.
 * @return 
 *     Returns true if the number of requested elements were protracted.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline bool
IncreaseAssuredly(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<Natural>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    if (!count || stack.allotment + count > Maximum)
        return false;
    return Increase(stack, index, count);
}

/**
 * @brief 
 *     Retracts elements from the end of the stack.
 * @details
 *     Retracts elements from the end of the stack.  This version does
 *     not verify if count is zero or if count is larger than the number
 *     of protracted elements.  Use this version only if stringent 
 *     performance is required.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @param[in] count 
 *     Reference to the count.
 * @return 
 *     Always returns true.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline bool
Decrease(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    stack.allotment -= count;
    return true;
}

/**
 * @brief 
 *     Retracts elements from the end of the stack.
 * @details
 *     Retracts elements from the end of the stack.  This version 
 *     returns false if count is zero or if count is larger than the
 *     number of protracted elements.  Use this version only if 
 *     stringent performance is required.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] stack 
 *     Reference to the stack.
 * @param[in] count 
 *     Reference to the count.
 * @return 
 *     Returns true if the number of requested elements were retracted.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
static inline bool
DecreaseAssuredly(
    Referential<Elevatory<Natural, Maximum, Elemental>>
        stack,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    if (!count || count > stack.allotment)
        return false;
    return Decrease(stack, count);
}

/**
 * @brief 
 *     Tractile stack management implementation.
 * @details
 *     Objective table which provides fast tractile stack management.  
 *     Use this version if performance is stringent, however care should
 *     be taken to understand how each function works in order to 
 *     prevent overflowing the stack or attempting to protract zero
 *     elements, which could cause bugs.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Tractile<Elevatory<Natural, Maximum, Elemental>, Natural, Natural>
    FastElevator = {
        Survey<Natural, Maximum, Elemental>,
        Account<Natural, Maximum, Elemental>,
        Increase<Natural, Maximum, Elemental>,
        Decrease<Natural, Maximum, Elemental>,
        Contract<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Tractile stack management implementation.
 * @details
 *     Objective table which provides safe tractile stack management.  
 *     Use this version if overflowing the stack or protraction
 *     requests of zero elements are not prevented, where this version
 *     will perform the run-time checks for you.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Tractile<Elevatory<Natural, Maximum, Elemental>, Natural, Natural>
    SureElevator = {
        Survey<Natural, Maximum, Elemental>,
        Account<Natural, Maximum, Elemental>,
        IncreaseAssuredly<Natural, Maximum, Elemental>,
        DecreaseAssuredly<Natural, Maximum, Elemental>,
        Contract<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Vectorial read trajection implementation.
 * @details
 *     Objective table which provides fast vectorial trajection into the
 *     stack.  Use this version if performance is stringent and requests
 *     for invalid index positions will not occur, as this version does
 *     not perform any run-time checks.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Vectorial<const Elevatory<Natural, Maximum, Elemental>, Natural, const Elemental>
    ReadVector = {
        Comparison<Natural>,
        Contains<Natural, Maximum, Elemental>,
        GoRead<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Vectorial write trajection implementation.
 * @details
 *     Objective table which provides fast vectorial trajection into the
 *     stack.  Use this version if performance is stringent and requests
 *     for invalid index positions will not occur, as this version does
 *     not perform any run-time checks.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Vectorial<Elevatory<Natural, Maximum, Elemental>, Natural, Elemental>
    WriteVector = {
        Comparison<Natural>,
        Contains<Natural, Maximum, Elemental>,
        GoWrite<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural
        Maximum,
    typename Elemental>
constexpr Scalar<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
    ReadIncrementScale = {
        Comparison<Natural>,
        BeginReadIncrement<Natural, Maximum, Elemental>,
        TraverseReadIncrement<Natural, Maximum, Elemental>,
        GoRead<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Scalar<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
    WriteIncrementScale = {
        Comparison<Natural>,
        BeginWriteIncrement<Natural, Maximum, Elemental>,
        TraverseWriteIncrement<Natural, Maximum, Elemental>,
        GoWrite<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Scalar<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
    ReadDecrementScale = {
        Comparison<Natural>,
        BeginReadDecrement<Natural, Maximum, Elemental>,
        TraverseReadDecrement<Natural, Maximum, Elemental>,
        GoRead<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Scalar<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
    WriteDecrementScale = {
        Comparison<Natural>,
        BeginWriteDecrement<Natural, Maximum, Elemental>,
        TraverseWriteDecrement<Natural, Maximum, Elemental>,
        GoWrite<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Lineal<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
    ReadLiner = {
        ReadIncrementScale<Natural, Maximum, Elemental>,
        ReadDecrementScale<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Lineal<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
    WriteLiner = {
        WriteIncrementScale<Natural, Maximum, Elemental>,
        WriteDecrementScale<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Directional<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
    ReadIncrementDirection = {
        ReadIncrementScale<Natural, Maximum, Elemental>,
        Begins<Natural, Maximum, Elemental>,
        IncrementTraverses<Natural, Maximum, Elemental>,
        Contains<Natural, Maximum, Elemental>,
        Account<Natural, Maximum, Elemental>,
        CountIncrement<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Directional<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
    WriteIncrementDirection = {
        WriteIncrementScale<Natural, Maximum, Elemental>,
        Begins<Natural, Maximum, Elemental>,
        IncrementTraverses<Natural, Maximum, Elemental>,
        Contains<Natural, Maximum, Elemental>,
        Account<Natural, Maximum, Elemental>,
        CountIncrement<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Directional<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
    ReadDecrementDirection = {
        ReadDecrementScale<Natural, Maximum, Elemental>,
        Begins<Natural, Maximum, Elemental>,
        DecrementTraverses<Natural, Maximum, Elemental>,
        Contains<Natural, Maximum, Elemental>,
        Account<Natural, Maximum, Elemental>,
        CountDecrement<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Directional<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
    WriteDecrementDirection = {
        WriteDecrementScale<Natural, Maximum, Elemental>,
        Begins<Natural, Maximum, Elemental>,
        DecrementTraverses<Natural, Maximum, Elemental>,
        Contains<Natural, Maximum, Elemental>,
        Account<Natural, Maximum, Elemental>,
        CountDecrement<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Axial<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
    ReadAxis = {
        ReadIncrementDirection<Natural, Maximum, Elemental>,
        ReadDecrementDirection<Natural, Maximum, Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides fast sequential trajection into 
 *     the stack.  Use this version if performance is stringent and 
 *     the index is prevented from being moved out of bounds.
 * @tparam Natural
 *     Type of natural integer for sizes.
 * @tparam Maximum 
 *     The maximum number of elements.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Maximum,
    typename Elemental>
constexpr Axial<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
    WriteAxis = {
        WriteIncrementDirection<Natural, Maximum, Elemental>,
        WriteDecrementDirection<Natural, Maximum, Elemental>
    };

}

}

#endif
