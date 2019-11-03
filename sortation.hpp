// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SORTATION_MODULE
#define SORTATION_MODULE
#include "comparison.hpp"
#include "trajection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

/**
 * @brief   
 *     Sequential and bisectional search implementations.
 * @details 
 *     Sequential and bisectional search algorithms which use specified
 *     trajection objectives corresponding to the spatial types being searched.
 *     Several versions of the algorithms are provided, being optimized for 
 *     either singular or iterative searches through spaces.
 */
namespace sortation {

using ::comparison::BinaryComparative;
using ::location::Referential;
using ::trajection::Lineal;
using ::trajection::Scalar;

/**
 * @brief   
 *     Function type which simplifies declaration syntax.
 * @details 
 *     Function type alias used to declare equality comparison and sortation
 *     order function references.
 * @tparam Evaluative
 *     Type of both values being compared.
 */
template <typename Evaluative>
using Assortive = BinaryComparative<Evaluative, Evaluative>;

/**
 * @brief
 *     Searches sequentially for some value in a scalar space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The extent argument can be used to further limit the scope
 *     of the search or can reflect the actual number of elements in the 
 *     space after the position.  With this overload, the scalar trajection 
 *     objective is specified as a function argument.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @param[in] space
 *     Reference to the space being searched.
 * @param[in] scale 
 *     Reference to a scalar trajection objective.
 * @param[in] value 
 *     Reference to the value being sought.
 * @param[in,out] position 
 *     Reference to a positional instance.  The position must be set to the
 *     initial position that the search should start from.   If the function
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last 
 *     position considered.
 * @param[in] extent
 *     Number of elements in the space __after__  the initial position to be
 *     considered in the search.
 * @param[in] equate 
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @return
 *     True if the value sought was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative>
static inline bool
SearchSection(
    Referential<const Spatial>
        space,
    Referential<const Scalar<const Spatial, Positional, Natural, const Evaluative>>
        scale,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Natural
        extent,
    Referential<Assortive<Evaluative>>
        equate)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    while (true) {
        if (equate(scale.go(space, position).to, value))
            return true;
        else if (!extent--)
            return false;
        scale.traverse(space, position, 1);
    }
}

/**
 * @brief
 *     Searches sequentially for some value in a scalar space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The extent argument can be used to further limit the 
 *     scope of the search or can reflect the actual number of elements in 
 *     the space after the position.  With this overload, the scalar 
 *     trajection objective is specified as a template argument.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @tparam Equate
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @tparam Scale
 *     Reference to a scalar trajection objective.
 * @param[in] space
 *     Reference to the space being searched.
 * @param[in] value
 *     Reference to the value being sought.
 * @param[in,out] position
 *     Reference to a positional instance.  The position must be set to the
 *     initial position that the search should start from.   If the function
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last
 *     position considered.
 * @param[in] extent 
 *     Number of elements in the space __after__ the initial position to be 
 *     considered in the search.
 * @return 
 *     True or false if the value was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative,
    Referential<Assortive<Evaluative>> Equate,
    Referential<const Scalar<const Spatial, Positional, Natural, const Evaluative>> Scale>
static inline bool
SearchSection(
    Referential<const Spatial>
        space,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Natural
        extent)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return SearchSection(space, Scale, value, position, extent, Equate);
}

/**
 * @brief
 *     Searches sequentially for some value in a scalar space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The extent argument can be used to further limit the 
 *     scope of the search or can reflect the actual number of elements in 
 *     the space after the position.  As the position is moved through the 
 *     space, the extent argument is decreased in the calling context.  With
 *     this overload, the scalar trajection objective is specified as a 
 *     function argument.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @param[in] space
 *     Reference to the space being searched.
 * @param[in] scale
 *     Reference to a scalar trajection objective.
 * @param[in] value 
 *     Reference to the value being sought.
 * @param[in,out] position 
 *     Reference to a positional instance.  The position must be set to the
 *     initial position that the search should start from.  If the function 
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last 
 *     position considered.
 * @param[in,out] extent
 *     Number of elements in the space __after__ the initial position to be 
 *     considered in the search.  The extent will also be modified in the 
 *     calling context.
 * @param[in] equate
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @return
 *     True or false if the value was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative>
static inline bool
SearchSectionIteratively(
    Referential<const Spatial>
        space,
    Referential<const Scalar<const Spatial, Positional, Natural, const Evaluative>>
        scale,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Referential<Natural>
        extent,
    Referential<Assortive<Evaluative>>
        equate)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    while (true) {
        if (equate(scale.go(space, position).to, value))
            return true;
        else if (!extent--)
            return false;
        scale.traverse(space, position, 1);
    }
}

/**
 * @brief
 *     Searches sequentially for some value in a scalar space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The extent argument can be used to further limit the scope
 *     of the search or can reflect the actual number of elements in the 
 *     space after the position.  As the position is moved through the 
 *     space, the extent argument is decreased in the calling context.  With
 *     this overload, the scalar trajection objective is specified as a 
 *     template argument.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @tparam Equate
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @tparam Scale
 *     Reference to a scalar trajection objective.
 * @param[in] space
 *     Reference to the space being searched.
 * @param[in] value 
 *     Reference to the value being sought.
 * @param[in,out] position
 *     Reference to a positional instance.  The position must be set to the
 *     initial position that the search should start from.  If the function 
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last 
 *     position considered.
 * @param[in,out] extent
 *     Number of elements in the space __after__ the initial position to be 
 *     considered in the search.  The extent will also be modified in  the 
 *     calling context.
 * @return 
 *     True or false if the value was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative,
    Referential<Assortive<Evaluative>> Equate,
    Referential<const Scalar<const Spatial, Positional, Natural, const Evaluative>> Scale>
static inline bool
SearchSectionIteratively(
    Referential<const Spatial>
        space,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Referential<Natural>
        extent)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return SearchSectionIteratively(space, Scale, value, position, extent, Equate);
}

/**
 * @brief
 *     Searches bisectionally for some value in a linear space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The before and after argument can be used to limit the 
 *     scope of the search or can reflect the actual number of elements in
 *     the space before and after the position.  With this overload, the 
 *     liner, equate and order objectives are specified as function 
 *     arguments.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @param[in] space
 *     Reference to the space being searched.
 * @param[in] liner
 *     Reference to a lineal trajection objective.
 * @param[in] value
 *     Reference to the value being sought.
 * @param[in,out] position
 *     Reference to a positional instance.  The position must be set to the
 *     initial position that the search should start from.  If the function 
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last 
 *     position considered.
 * @param[in] before
 *     Number of elements in the space __before__ the initial position to be
 *     considered in the search.
 * @param[in] after
 *     Number of elements in the space __after__ the initial position to be 
 *     considered in the search.
 * @param[in] equate 
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @param[in] order
 *     Reference to an assortive function which returns true if the first 
 *     argument belongs first in the sortation order.
 * @return
 *     True or false if the value was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative>
static inline bool
SearchBisection(
    Referential<const Spatial>
        space,
    Referential<const Lineal<const Spatial, Positional, Natural, const Evaluative>>
        liner,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Natural
        before,
    Natural
        after,
    Referential<Assortive<Evaluative>>
        equate,
    Referential<Assortive<Evaluative>>
        order)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using ElementReferential = Referential<const Evaluative>;
    Natural moves, remainder, difference;
    while (true) {
        ElementReferential element = liner.increment.go(space, position).to;
        if (equate(element, value))
            return true;
        if (order(element, value)) {
            if (!after)
                return false;
            remainder = after % 2;
            moves = after / 2 + remainder;
            difference = after - moves;
            before = difference - (remainder ? 0 : 1);
            after = difference;
            liner.increment.traverse(space, position, moves);
        } else {
            if (!before)
                return false;
            remainder = before % 2;
            moves = before / 2 + remainder;
            difference = before - moves;
            after = difference - (remainder ? 0 : 1);
            before = difference;
            liner.decrement.traverse(space, position, moves);
        }
    }
}

/**
 * @brief
 *     Searches bisectionally for some value in a linear space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The before and after argument can be used to limit the 
 *     scope of the search or can reflect the actual number of elements in 
 *     the space before and after the position.  With this overload, the 
 *     Liner, Equate and Order objectives are specified as template 
 *     arguments.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @tparam Equate 
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @tparam Order
 *     Reference to an assortive function which returns true if the first 
 *     argument belongs first in the sortation order.
 * @tparam Liner
 *     Reference to a lineal trajection objective.
 * @param[in] space
 *     Reference to the space being searched.
 * @param[in] value
 *     Reference to the value being sought.
 * @param[in,out] position
 *     Reference to a positional instance.  The position must be set to the
 *     initial position that the search should start from.  If the function 
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last 
 *     position considered.
 * @param[in] before
 *     Number of elements in the space __before__  the initial position to
 *     be considered in the search.
 * @param[in] after
 *     Number of elements in the space __after__  the initial position to be 
 *     considered in the search.
 * @return
 *     True or false if the value was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative,
    Referential<Assortive<Evaluative>> Equate,
    Referential<Assortive<Evaluative>> Order,
    Referential<const Lineal<const Spatial, Positional, Natural, const Evaluative>> Liner>
static inline bool
SearchBisection(
    Referential<const Spatial>
        space,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Natural
        before,
    Natural
        after)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return SearchBisection(space, Liner, value, position, before, after, Equate, Order);
}

/**
 * @brief
 *     Searches bisectionally for some value in a linear space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The before and after argument can be used to limit the
 *     scope of the search or they can reflect the actual number of elements
 *     in the space before and after the position.  As the position is moved 
 *     through the space, the before and after arguments are also modified
 *     in the calling context.  With this overload, the lineal trajection 
 *     objective is specified as a function argument.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional 
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @param[in] space 
 *     Reference to the space being searched.
 * @param[in] liner
 *     Reference to a lineal trajection objective.
 * @param[in] value
 *     Reference to the value being sought.
 * @param[in,out] position
 *     Reference to a positional instance.  The position must be set to the 
 *     initial position that the search should start from.  If the function 
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last 
 *     position considered.
 * @param[in,out] before
 *     Number of elements in the space __before__ the initial position to be
 *     considered in the search.  The before count will also be modified in 
 *     the calling context.
 * @param[in,out] after
 *     Number of elements in the space __after__ the initial position to be 
 *     considered in the search.  The after count will also be modified in 
 *     the calling context.
 * @param[in] equate
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @param[in] order
 *     Reference to an assortive function which returns true if the first 
 *     argument belongs first in the sortation order.
 * @return
 *     True or false if the value was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative>
static inline bool
SearchBisectionIteratively(
    Referential<const Spatial>
        space,
    Referential<const Lineal<const Spatial, Positional, Natural, const Evaluative>>
        liner,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Referential<Natural>
        before,
    Referential<Natural>
        after,
    Referential<Assortive<Evaluative>>
        equate,
    Referential<Assortive<Evaluative>>
        order)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    using ElementReferential = Referential<const Evaluative>;
    Natural moves, remainder, difference, min, max;
    min = before;
    max = after;
    while (true) {
        ElementReferential element = liner.increment.go(space, position).to;
        if (equate(element, value))
            return true;
        if (order(element, value)) {
            if (!max)
                return false;
            remainder = max % 2;
            moves = max / 2 + remainder;
            before += moves;
            after -= moves;
            difference = max - moves;
            min = difference - (remainder ? 0 : 1);
            max = difference;
            liner.increment.traverse(space, position, moves);
        } else {
            if (!min)
                return false;
            remainder = min % 2;
            moves = min / 2 + remainder;
            before -= moves;
            after += moves;
            difference = min - moves;
            max = difference - (remainder ? 0 : 1);
            min = difference;
            liner.decrement.traverse(space, position, moves);
        }
    }
}

/**
 * @brief
 *     Searches bisectionally for some value in a linear space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The before and after argument can be used to further limit
 *     the scope of the search or can reflect the actual number of elements 
 *     in the space before and after the position.  As the position is moved 
 *     through the space, the before and after arguments are also modified
 *     in the calling context.  With this overload, the lineal trajection 
 *     objective is specified as a function argument.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @tparam Equate
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @tparam Order
 *     Reference to an assortive function which returns true if the first 
 *     argument belongs first in the sortation order.
 * @tparam Liner
 *     Reference to a lineal trajection objective.
 * @param[in] space
 *     Reference to the space being searched.
 * @param[in] value
 *     Reference to the value being sought.
 * @param[in,out] position
 *     Reference to a positional instance.  The position must be set to the 
 *     initial position that the search should start from.  If the function 
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last 
 *     position considered.
 * @param[in,out] before
 *     Number of elements in the space __before__ the initial position to be
 *     considered in the search.  The before count will also be modified in 
 *     the calling context.
 * @param[in,out] after
 *     Number of elements in the space __after__ the initial position to be 
 *     considered in the search.  The after count will also be modified in 
 *     the calling context.
 * @return
 *     True or false if the value was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative,
    Referential<Assortive<Evaluative>> Equate,
    Referential<Assortive<Evaluative>> Order,
    Referential<const Lineal<const Spatial, Positional, Natural, const Evaluative>> Liner>
static inline bool
SearchBisectionIteratively(
    Referential<const Spatial>
        space,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Referential<Natural>
        before,
    Referential<Natural>
        after)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return SearchBisectionIteratively(space, Liner, value, position, before, after, Equate, Order);
}

/**
 * @brief
 *     Searches bisectionally for some value in a scalar space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The extent argument can be used to further limit the scope
 *     of the search or can reflect the actual number of elements in the 
 *     space after the position.  With this overload, the scalar trajection 
 *     objective is specified as a function argument and extra memory space
 *     is used to perform the bisectional search in a sequential fashion.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @param[in] space
 *     Reference to the space being searched.
 * @param[in] scale 
 *     Reference to a scalar trajection objective.
 * @param[in] value 
 *     Reference to the value being sought.
 * @param[in,out] position 
 *     Reference to a positional instance.  The position must be set to the
 *     initial position that the search should start from.   If the function
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last 
 *     position considered.
 * @param[in] extent
 *     Number of elements in the space __after__  the initial position to be
 *     considered in the search.
 * @param[in] equate 
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @param[in] order
 *     Reference to an assortive function which returns true if the first 
 *     argument belongs first in the sortation order.
 * @return
 *     True if the value sought was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative>
static inline bool
SearchScalarBisection(
    Referential<const Spatial>
        space,
    Referential<const Scalar<const Spatial, Positional, Natural, const Evaluative>>
        scale,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Natural
        extent,
    Referential<Assortive<Evaluative>>
        equate,
    Referential<Assortive<Evaluative>>
        order)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    Positional first;
    Natural moves;
    first = position;
    while (true) {
        if (!extent)
            return equate(scale.go(space, position).to, value);
        moves = extent / 2 + extent % 2;
        scale.traverse(space, position, moves);
        if (equate(scale.go(space, position).to, value))
            return true;
        if (order(scale.go(space, position).to, value)) {
            extent -= moves;
            if (!extent)
                return false;
            extent--;
            scale.traverse(space, position, 1);
            first = position;
        } else {
            extent = moves - 1;
            position = first;
        }
    }
}

/**
 * @brief
 *     Searches bisectionally for some value in a scalar space.
 * @details
 *     This function begins searching a space at the specified position 
 *     argument.  The extent argument can be used to further limit the scope
 *     of the search or can reflect the actual number of elements in the 
 *     space after the position.  With this overload, the scalar trajection 
 *     objective is specified as a template argument and extra memory space
 *     is used to perform the bisectional search in a sequential fashion.
 * @tparam Spatial
 *     Type of the space to be searched.
 * @tparam Positional
 *     Type of the positions in the space.
 * @tparam Natural
 *     Type of natural integer counts.
 * @tparam Evaluative
 *     Type of the elements in the space.
 * @tparam Equate 
 *     Reference to an assortive function which returns true if both 
 *     arguments are to be considered equal.
 * @tparam Order
 *     Reference to an assortive function which returns true if the first 
 *     argument belongs first in the sortation order.
 * @tparam Scale
 *     Reference to a scalar trajection objective.
 * @param[in] space
 *     Reference to the space being searched.
 * @param[in] value
 *     Reference to the value being sought.
 * @param[in,out] position
 *     Reference to a positional instance.  The position must be set to the
 *     initial position that the search should start from.  If the function 
 *     returns true the position will be set to where the value was located.
 *     If the function returns false the position will be set to the last 
 *     position considered.
 * @param[in] before
 *     Number of elements in the space __before__  the initial position to
 *     be considered in the search.
 * @param[in] after
 *     Number of elements in the space __after__  the initial position to be 
 *     considered in the search.
 * @return
 *     True or false if the value was found.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Evaluative,
    Referential<Assortive<Evaluative>> Equate,
    Referential<Assortive<Evaluative>> Order,
    Referential<const Scalar<const Spatial, Positional, Natural, const Evaluative>> Scale>
static inline bool
SearchScalarBisection(
    Referential<const Spatial>
        space,
    Referential<const Evaluative>
        value,
    Referential<Positional>
        position,
    Natural
        extent)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<Natural>::value && is_unsigned<Natural>::value,
        "Natural:  Unsigned integer type required");
#endif
    return SearchScalarBisection(space, Scale, value, position, extent, Equate, Order);
}

}

#endif
