// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SEGMENTATION_MODULE
#define SEGMENTATION_MODULE
#include "localization.hpp"

/**
 * @brief         
 *     Segment space trajection implementation.
 * @details       
 *     Implements vectorial and sequential trajection between a pointer base and
 *     positive relative offsets of a compile-time known length.
 */
namespace segmentation {

using ::comparison::Comparison;
using ::localization::IndexicalGo;
using ::localization::ReadIncrementScale;
using ::localization::ReadLocal;
using ::localization::TraverseDecrement;
using ::localization::WriteIncrementScale;
using ::localization::WriteLocal;
using ::location::Conferential;
using ::location::Locational;
using ::location::Referential;
using ::trajection::Axial;
using ::trajection::Directional;
using ::trajection::Lineal;
using ::trajection::Scalar;
using ::trajection::Vectorial;

/**
 * @brief
 *     Check if index is within the segment.
 * @details
 *     Checks if index is within the segment.  This version does not check
 *     if locality is null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental
 *     Type of the elements.
 * @param[in] locality
 *     Reference to the pointer.
 * @param[in] index
 *     Reference to the index.
 * @return
 *     True if index is less than length.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
static inline bool
ContainsIndex(
    Referential<const Locational<Elemental>>
        locality,
    Referential<const Natural>
        index)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index < Length;
}

/**
 * @brief
 *     Checks if sequential trajection can begin.
 * @details
 *     Checks if sequential trajection can begin at the specified offset
 *     count.
 * @tparam Natural
 *     Type of natural integer for count.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] locality
 *     Reference to the pointer.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     True if the segment's length is greater than zero and count is less
 *     than length.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
static inline bool
Begins(
    Referential<const Locational<Elemental>>
        locality,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return count < Length;
}

/**
 * @brief
 *     Begins increment trajection.
 * @details
 *     Assigns to index the count negative offset from the length of the 
 *     segment minus one.  This version does not check if the segment length
 *     is zero, if the pointer is null or if count is greater than or equal
 *     to the segment length.
 * @tparam Natural
 *     Type of natural integer for index and count.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] locality 
 *     Reference to the pointer.
 * @param[out] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     A reference to the index as a constant.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
static inline Referential<const Natural>
BeginDecrement(
    Referential<const Locational<Elemental>>
        locality,
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
    return index = Length - 1 - count;
}

/**
 * @brief
 *     Checks if sequential trajection can continue.
 * @details
 *     Checks if sequential trajection can traverse from index to the
 *     specified count offset.  This version does not check if the pointer
 *     is null.
 * @tparam Natural
 *     Type of natural integer for index and count.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] locality
 *     Reference to the pointer.
 * @param[in] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     True if the offset can be reached from index.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
static inline bool
IncrementTraverses(
    Referential<const Locational<Elemental>>
        locality,
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
    return index + count < Length;
}

/**
 * @brief
 *     Checks if sequential trajection can continue.
 * @details
 *     Checks if sequential trajection can traverse from index to the
 *     specified count offset.  This version does not check if the pointer
 *     is null.
 * @tparam Natural
 *     Type of natural integer for index and count.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] locality
 *     Reference to the pointer.
 * @param[in] index
 *     Reference to the index.
 * @param[in] count
 *     Reference to the offset count.
 * @return 
 *     True if the offset can be reached from index.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
static inline bool
DecrementTraverses(
    Referential<const Locational<Elemental>>
        locality,
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
 *     Returns the number of elements in the segment.
 * @details
 *     Returns the number of elements in the segment.
 * @tparam Natural
 *     Type of natural integer for index and result.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] locality 
 *     Reference to the pointer.
 * @return 
 *     The number of elements in the segment.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
static inline Natural
Account(
    Referential<const Locational<Elemental>>
        locality)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return Length;
}

/**
 * @brief 
 *     Returns the number of elements in the segment __after__ index.
 * @details
 *     Returns the number of elements in the segment __after__
 *     the specified index (does not include the element at index).
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] locality 
 *     Reference to the pointer.
 * @param[in] index
 *     Reference to the index.
 * @return 
 *     The number of elements __after__ index.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
static inline Natural
CountIncrement(
    Referential<const Locational<Elemental>>
        locality,
    Referential<const Natural>
        index)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return Length - 1 - index;
}

/**
 * @brief 
 *     Returns the number of elements in the segment __before__ index.
 * @details
 *     Returns the number of elements in the segment __before__
 *     the specified index (does not include the element at index).
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 * @param[in] locality 
 *     Reference to the pointer.
 * @param[in] index
 *     Reference to the index.
 * @return 
 *     The number of elements __before__ index.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
static inline Natural
CountDecrement(
    Referential<const Locational<Elemental>>
        locality,
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
 *     Vectorial read trajection implementation.
 * @details
 *     Objective table which provides vectorial trajection into the segment.
 *     Use this version if performance is stringent and requests for invalid 
 *     index positions will not occur, as this version does not perform any 
 *     run-time checks.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Vectorial<const Locational<const Elemental>, Natural, const Elemental>
    ReadVector = {
        Comparison<Natural>,
        ContainsIndex<Natural, Length, const Elemental>,
        IndexicalGo<Natural, const Elemental>
    };

/**
 * @brief 
 *     Vectorial write trajection implementation.
 * @details
 *     Objective table which provides vectorial trajection into the segment.
 *     Use this version if performance is stringent and requests for invalid 
 *     index positions will not occur, as this version does not perform any 
 *     run-time checks.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Vectorial<const Locational<Elemental>, Natural, Elemental>
    WriteVector = {
        Comparison<Natural>,
        ContainsIndex<Natural, Length, Elemental>,
        IndexicalGo<Natural, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides sequential negative trajection from a 
 *     pointer.  Use this version if performance is stringent and the 
 *     pointer is prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Scalar<const Locational<const Elemental>, Natural, Natural, const Elemental>
    ReadDecrementScale = {
        Comparison<Natural>,
        BeginDecrement<Natural, Length, const Elemental>,
        TraverseDecrement<Natural, Natural, const Elemental>,
        IndexicalGo<Natural, const Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides sequential negative trajection from a 
 *     pointer.  Use this version if performance is stringent and the 
 *     pointer is prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Scalar<const Locational<Elemental>, Natural, Natural, Elemental>
    WriteDecrementScale = {
        Comparison<Natural>,
        BeginDecrement<Natural, Length, Elemental>,
        TraverseDecrement<Natural, Natural, Elemental>,
        IndexicalGo<Natural, Elemental>,
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides sequential trajection from a pointer.
 *     Use this version if performance is stringent and the pointer is 
 *     prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural
        Length,
    typename Elemental>
constexpr Lineal<const Locational<const Elemental>, Natural, Natural, const Elemental>
    ReadLiner = {
        ReadIncrementScale<Natural, Natural, Elemental>,
        ReadDecrementScale<Natural, Length, Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides sequential trajection from a pointer.
 *     Use this version if performance is stringent and the pointer is 
 *     prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Lineal<const Locational<Elemental>, Natural, Natural, Elemental>
    WriteLiner = {
        WriteIncrementScale<Natural, Natural, Elemental>,
        WriteDecrementScale<Natural, Length, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides sequential positive trajection from a
 *     pointer.  Use this version if performance is stringent and the 
 *     pointer is prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Directional<const Locational<const Elemental>, Natural, Natural, const Elemental>
    ReadIncrementDirection = {
        ReadIncrementScale<Natural, Natural, Elemental>,
        Begins<Natural, Length, const Elemental>,
        IncrementTraverses<Natural, Length, const Elemental>,
        ContainsIndex<Natural, Length, const Elemental>,
        Account<Natural, Length, const Elemental>,
        CountIncrement<Natural, Length, const Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides sequential positive trajection from a
 *     pointer.  Use this version if performance is stringent and the 
 *     pointer is prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Directional<const Locational<Elemental>, Natural, Natural, Elemental>
    WriteIncrementDirection = {
        WriteIncrementScale<Natural, Elemental>,
        Begins<Natural, Length, Elemental>,
        IncrementTraverses<Natural, Length, Elemental>,
        ContainsIndex<Natural, Length, Elemental>,
        Account<Natural, Length, Elemental>,
        CountIncrement<Natural, Length, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides sequential negative trajection from a
 *     pointer.  Use this version if performance is stringent and the 
 *     pointer is prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Directional<const Locational<const Elemental>, Natural, Natural, const Elemental>
    ReadDecrementDirection = {
        ReadDecrementScale<Natural, Length, Elemental>,
        Begins<Natural, Length, const Elemental>,
        DecrementTraverses<Natural, Length, const Elemental>,
        ContainsIndex<Natural, Length, const Elemental>,
        Account<Natural, Length, const Elemental>,
        CountDecrement<Natural, Length, const Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides sequential negative trajection from a
 *     pointer.  Use this version if performance is stringent and the 
 *     pointer is prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural
        Length,
    typename Elemental>
constexpr Directional<const Locational<Elemental>, Natural, Natural, Elemental>
    WriteDecrementDirection = {
        WriteDecrementScale<Natural, Length, Elemental>,
        Begins<Natural, Length, Elemental>,
        DecrementTraverses<Natural, Length, Elemental>,
        ContainsIndex<Natural, Length, Elemental>,
        Account<Natural, Length, Elemental>,
        CountDecrement<Natural, Length, Elemental>
    };

/**
 * @brief 
 *     Sequential read trajection implementation.
 * @details
 *     Objective table which provides sequential trajection from a pointer.
 *     Use this version if performance is stringent and the pointer is 
 *     prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Axial<const Locational<const Elemental>, Natural, Natural, const Elemental>
    ReadAxis = {
        ReadIncrementDirection<Natural, Length, Elemental>,
        ReadDecrementDirection<Natural, Length, Elemental>
    };

/**
 * @brief 
 *     Sequential write trajection implementation.
 * @details
 *     Objective table which provides sequential trajection from a pointer.
 *     Use this version if performance is stringent and the pointer is 
 *     prevented from being null.
 * @tparam Natural
 *     Type of natural integer for index.
 * @tparam Length
 *     The length of the segment.
 * @tparam Elemental 
 *     Type of the elements.
 */
template <
    typename Natural,
    Natural Length,
    typename Elemental>
constexpr Axial<const Locational<Elemental>, Natural, Natural, Elemental>
    WriteAxis = {
        WriteIncrementDirection<Natural, Length, Elemental>,
        WriteDecrementDirection<Natural, Length, Elemental>
    };

}

#endif
