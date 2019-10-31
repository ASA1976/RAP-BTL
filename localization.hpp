// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef LOCALIZATION_MODULE
#define LOCALIZATION_MODULE
#include "comparison.hpp"
#include "trajection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

/**
 * @brief         
 *     Pointer space trajection implementation.
 * @details       
 *     Association
 *     -----------
 *     Implements sequential scalar trajection from a pointer.  This form of
 *     trajection is indeterminate since a pointer does not relate a count
 *     number of local elements.
 */
namespace localization {

using ::comparison::Comparison;
using ::location::Conferential;
using ::location::Locational;
using ::location::Referential;
using ::trajection::Lineal;
using ::trajection::Scalar;

/**
     * @brief
     *     Pointer to modifiable elements.
     * @details
     *     Conformation Template
     *     ---------------------
     *     This type alias is used to represent a pointer type to modifiable
     *     elements.
     * @tparam Elemental
     *     Type of the elements.
     */
template <
    typename Elemental>
using WriteLocal = const Locational<Elemental>;

/**
     * @brief
     *     Pointer to constant elements.
     * @details
     *     Conformation Template
     *     ---------------------
     *     This type alias is used to represent a pointer type to constant
     *     elements.
     * @tparam Elemental
     *     Type of the elements.
     */
template <
    typename Elemental>
using ReadLocal = const Locational<const Elemental>;

/**
     * @brief 
     *     Confers the element at index.
     * @details
     *     Function Template
     *     -----------------
     *     Returns a reference to the element at the specified index.  This 
     *     version does not check if the pointer is null.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @return
     *     The reference conferment.
     */
template <
    typename Integral,
    typename Elemental>
static inline Conferential<Elemental>
IndexicalGo(
    Referential<const Locational<Elemental>>
        locality,
    Referential<const Integral>
        index)
{
    using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Integral>::value,
        "Integral:  Integer type required");
#endif
    return Confer(locality[index]);
}

/**
     * @brief
     *     Begins increment trajection.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns to index the count positive offset from zero.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
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
    typename Integral,
    typename Natural,
    typename Elemental>
static inline Referential<const Integral>
BeginIncrement(
    Referential<const Locational<Elemental>>
        locality,
    Referential<Integral>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Integral>::value,
        "Integral:  Integer type required");
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index = static_cast<Integral>(count);
}

/**
     * @brief
     *     Begins decrement trajection.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns to index the count negative offset from zero.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
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
    typename Integral,
    typename Natural,
    typename Elemental>
static inline Referential<const Integral>
BeginDecrement(
    Referential<const Locational<Elemental>>
        locality,
    Referential<Integral>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Integral>::value,
        "Integral:  Integer type required");
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index = -static_cast<Integral>(count);
}

/**
     * @brief 
     *     Traverses increment.
     * @details
     *     Function Template
     *     -----------------
     *     Increases index by count offset.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @param[in,out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
template <
    typename Integral,
    typename Natural,
    typename Elemental>
static inline Referential<const Integral>
TraverseIncrement(
    Referential<const Locational<Elemental>>
        locality,
    Referential<Integral>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Integral>::value,
        "Integral:  Integer type required");
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index += static_cast<Integral>(count);
}

/**
     * @brief 
     *     Traverses decrement.
     * @details
     *     Function Template
     *     -----------------
     *     Decreases index by count offset.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @param[in,out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
template <
    typename Integral,
    typename Natural,
    typename Elemental>
static inline Referential<const Integral>
TraverseDecrement(
    Referential<const Locational<Elemental>>
        locality,
    Referential<Integral>
        index,
    Referential<const Natural>
        count)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Integral>::value,
        "Integral:  Integer type required");
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return index -= static_cast<Integral>(count);
}

/**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection from a
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Elemental 
     *     Type of the elements.
     */
template <
    typename Integral,
    typename Natural,
    typename Elemental>
constexpr Scalar<const Locational<const Elemental>, Integral, Natural, const Elemental>
    ReadIncrementScale = {
        Comparison<Integral>,
        BeginIncrement<Integral, Natural, const Elemental>,
        TraverseIncrement<Integral, Natural, const Elemental>,
        IndexicalGo<Integral, const Elemental>
    };

/**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection from a 
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Elemental 
     *     Type of the elements.
     */
template <
    typename Integral,
    typename Natural,
    typename Elemental>
constexpr Scalar<const Locational<Elemental>, Integral, Natural, Elemental>
    WriteIncrementScale = {
        Comparison<Integral>,
        BeginIncrement<Integral, Natural, Elemental>,
        TraverseIncrement<Integral, Natural, Elemental>,
        IndexicalGo<Integral, Elemental>
    };

/**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a 
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Elemental 
     *     Type of the elements.
     */
template <
    typename Integral,
    typename Natural,
    typename Elemental>
constexpr Scalar<const Locational<const Elemental>, Integral, Natural, const Elemental>
    ReadDecrementScale = {
        Comparison<Integral>,
        BeginDecrement<Integral, Natural, const Elemental>,
        TraverseDecrement<Integral, Natural, const Elemental>,
        IndexicalGo<Integral, const Elemental>
    };

/**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a 
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Elemental 
     *     Type of the elements.
     */
template <
    typename Integral,
    typename Natural,
    typename Elemental>
constexpr Scalar<const Locational<Elemental>, Integral, Natural, Elemental>
    WriteDecrementScale = {
        Comparison<Integral>,
        BeginDecrement<Integral, Natural, Elemental>,
        TraverseDecrement<Integral, Natural, Elemental>,
        IndexicalGo<Integral, Elemental>
    };

/**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.
     *     Use this version if performance is stringent and the pointer is 
     *     prevented from being null.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Elemental 
     *     Type of the elements.
     */
template <
    typename Integral,
    typename Natural,
    typename Elemental>
constexpr Lineal<const Locational<const Elemental>, Integral, Natural, const Elemental>
    ReadLiner = {
        ReadIncrementScale<Integral, Natural, Elemental>,
        ReadDecrementScale<Integral, Natural, Elemental>
    };

/**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.  
     *     Use this version if performance is stringent and the pointer is 
     *     prevented from being null.
     * @tparam Integral
     *     Type of integer for index.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Elemental 
     *     Type of the elements.
     */
template <
    typename Integral,
    typename Natural,
    typename Elemental>
constexpr Lineal<const Locational<Elemental>, Integral, Natural, Elemental>
    WriteLiner = {
        WriteIncrementScale<Integral, Natural, Elemental>,
        WriteDecrementScale<Integral, Natural, Elemental>
    };

}

#endif
