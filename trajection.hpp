// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef TRAJECTION_MODULE
#define TRAJECTION_MODULE
#include "comparison.hpp"

/**
 * @brief   
 *     Spatial trajection.
 * @details 
 *     Spatial trajection abstracts and classifiers which provide a consistent 
 *     interface for vectorial and sequential trajections through arbitrary 
 *     spaces.
 */
namespace trajection {

using ::comparison::Comparative;
using ::location::Conferential;
using ::location::Referential;

/**
 * @brief   
 *     Function type which simplifies declaration syntax.
 * @details 
 *     Function type alias used to declare function references which denote
 *     if trajection is possible from a implied beginning to a specified 
 *     offset.
 * @tparam Spatial
 *      Type of the space.
 * @tparam Natural
 *     Type of natural integer to denote magnitude.
 */
template <
    typename Spatial,
    typename Natural>
using Enterable = bool(
    Referential<const Spatial>
        space,
    Referential<const Natural>
        offset);

/**
 * @brief
 *     Function type which simplifies declaration syntax.
 * @details 
 *     Function type alias used to declare function references which denote 
 *     if trajection is possible to a specified position in the space.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional
 *     Type of positions used by the space.
 */
template <
    typename Spatial,
    typename Positional>
using Attainable = bool(
    Referential<const Spatial>
        space,
    Referential<const Positional>
        position);

/**
 * @brief   
 *     Function type which simplifies declaration syntax.
 * @details 
 *     Function type alias used to declare function references which denote 
 *     if sequential trajection is possible from a specified position given
 *     a specified offset magnitude.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional 
 *     Type of positions used by the space.
 * @tparam Natural
 *     Type of natural integer to denote magnitude.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural>
using Traversable = bool(
    Referential<const Spatial>
        space,
    Referential<const Positional>
        position,
    Referential<const Natural>
        offset);

/**
 * @brief
 *     Function type which simplifies declaration syntax.
 * @details 
 *     Function type alias used to declare function references which perform
 *     sequential trajection from a specified position given a specified 
 *     offset magnitude.  Implementing functions will modify the position 
 *     argument specified by reference and return a constant reference to 
 *     the same positional instance after being modified.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional
 *     Type of positions used by the space.
 * @tparam Natural
 *     Type of natural integer to denote magnitude.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural>
using Trajectile = Referential<const Positional>(
    Referential<Spatial>
        space,
    Referential<Positional>
        position,
    Referential<const Natural>
        offset);

/**
 * @brief
 *     Function type which simplifies declaration syntax.
 * @details 
 *     Function type alias used to declare function references which confer
 *     the subspace in the space at the specified position.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional
 *     Type of positions used by the space.
 * @tparam Endemical
 *     Type of subspaces within the space.
 */
template <
    typename Spatial,
    typename Positional,
    typename Endemical>
using Expositive = Conferential<Endemical>(
    Referential<Spatial>
        space,
    Referential<const Positional>
        position);

/**
 * @brief
 *     Function type which simplifies declaration syntax.
 * @details 
 *     Function type alias used to declare function references which return
 *     the range of valid positions used by the space.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Natural
 *     Type of natural integer to denote magnitude.
 */
template <
    typename Spatial,
    typename Natural>
using Aggregate = Natural(
    Referential<const Spatial>
        space);

/**
 * @brief
 *     Function type which simplifies declaration syntax.
 * @details 
 *     Function type alias used to declare function references which return
 *     the range of valid sequential positions in the space relative to the 
 *     specified position but not included it.  If there are no more valid 
 *     positions the implementing function should return zero.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional 
 *     Type of positions used by the space.
 * @tparam Natural
 *     Type of natural integer to denote magnitude.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural>
using Cumulative = Natural(
    Referential<const Spatial>
        space,
    Referential<const Positional>
        position);

/**
 * @brief
 *     Vectorial trajection classifier.
 * @details 
 *     This type is used perform direct trajections to subspaces at 
 *     specified positions in a space.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional 
 *     Type of positions used by the space.
 * @tparam Endemical
 *     Type of subspaces within the space.
 */
template <
    typename Spatial,
    typename Positional,
    typename Endemical>
struct Vectorial {

    Referential<const Comparative<Positional>>
        order; /**< Objective reference used to determine the order of
                *   positions.
                */

    Referential<Attainable<Spatial, Positional>>
        contains; /**< Function reference used to verify if a position is 
                   *   contained within the space. 
                   */

    Referential<Expositive<Spatial, Positional, Endemical>>
        go; /**< Function reference used to expose a subspace at a 
             *   specified position. 
             */
};

/**
 * @brief
 *     Scalar trajection classifier.
 * @details 
 *     This type is used perform indeterminate sequential trajections to 
 *     subspaces at provided positions in the space from some implied 
 *     beginning.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional 
 *     Type of positions used by the space.
 * @tparam Natural
 *     Type of natural integer to denote magnitude.
 * @tparam Endemical
 *     Type of subspaces within the space.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Endemical>
struct Scalar {

    Referential<const Comparative<Positional>>
        order; /**< Objective reference used to determine the order of
                *   positions.
                */

    Referential<Trajectile<Spatial, Positional, Natural>>
        begin, /**< Function reference used to begin sequential 
                *   trajection through the space at the specified offset
                *   magnitude, where an offset of zero should set the 
                *   position to the first valid position.
                */
        traverse; /**< Function reference used to traverse sequentially 
                   *   through the space from the specified position by
                   *   the specified offset magnitude, where zero should 
                   *   not modify the position.
                   */

    Referential<Expositive<Spatial, Positional, Endemical>>
        go; /**< Function reference used to expose a subspace in the 
             *   space at the specified position.
             */
};

/**
 * @brief   
 *     Lineal trajection classifier.
 * @details 
 *     This type is used perform indeterminate sequential trajections to 
 *     subspaces at provided positions in the space from some implied 
 *     increment and decrement beginning.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional 
 *     Type of positions used by the space.
 * @tparam Natural
 *     Type of natural integer to denote magnitude.
 * @tparam Endemical
 *     Type of subspaces within the space.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Endemical>
struct Lineal {

    Referential<const Scalar<Spatial, Positional, Natural, Endemical>>
        increment, /**< Objective reference used for scalar increment
                    *   trajection.
                    */
        decrement; /**< Objective reference used for scalar decrement 
                    *   trajection.
                    */
};

/**
 * @brief
 *     Directional trajection classifier.
 * @details 
 *     This type is used perform determinate sequential trajections to 
 *     subspaces at provided positions in the space from some implied 
 *     beginning.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional 
 *     Type of positions used by the space.
 * @tparam Natural
 *     Type of natural integer to denote magnitude.
 * @tparam Endemical
 *     Type of subspaces within the space.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Endemical>
struct Directional {

    Referential<const Scalar<Spatial, Positional, Natural, Endemical>>
        scale; /**< Objective reference used for scalar trajection
                *   in this direction.
                */

    Referential<Enterable<Spatial, Natural>>
        begins; /**< Function reference used to determine if trajection
                 *   in this direction can begin at the specified 
                 *   offset magnitude relative to the implied beginning
                 *   of the space, where zero means the first position.
                 */

    Referential<Traversable<Spatial, Positional, Natural>>
        traverses; /**< Function reference used to determine if the space
                    *   can be traversed from the specified position to a 
                    *   position at a specified offset magnitude, where 
                    *   an offset of zero should always return false.
                    */

    Referential<Attainable<Spatial, Positional>>
        meets; /**< Function reference used to determine if the 
                *   specified position exists along this direction
                *   of travel through the space.
                */

    Referential<Aggregate<Spatial, Natural>>
        survey; /**< Function reference used to report the total number 
                 *   of valid positions along this direction of travel
                 *   through the space.
                 */

    Referential<Cumulative<Spatial, Positional, Natural>>
        count; /**< Function reference used to report the relative 
                *   number of remaining valid positions __after__ the
                *   specified position along this direction of travel
                *   through the space, where zero should be returned
                *   if the specified position is the last one.
                */
};

/**
 * @brief   
 *     Axial trajection classifier.
 * @details 
 *     This type is used perform determinate sequential trajections to 
 *     subspaces at provided positions in the space from some implied 
 *     increment and decrement beginning.
 * @tparam Spatial
 *     Type of the space.
 * @tparam Positional 
 *     Type of positions used by the space.
 * @tparam Natural
 *     Type of natural integer to denote magnitude.
 * @tparam Endemical 
 *     Type of subspaces within the space.
 */
template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Endemical>
struct Axial {

    Referential<const Directional<Spatial, Positional, Natural, Endemical>>
        increment, /**< Objective reference used for directional increment
                    *   trajection.
                    */
        decrement; /**< Objective reference used for directional decrement
                    *   trajection.
                    */
};

}

#endif
