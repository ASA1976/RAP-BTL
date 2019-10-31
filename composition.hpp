// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef COMPOSITION_MODULE
#define COMPOSITION_MODULE
#include "location.hpp"

/**
 * @brief
 *     Composition management.
 * @details 
 *     Association
 *     -----------
 *     Composition management classifier which is used to manage various types
 *     of compositions.
 */
namespace composition {

using ::location::Referential;

/**
     * @brief
     *     Composition management classifier.
     * @details 
     *     Classification Template
     *     -----------------------
     *     This type is used to manage compositions in a general manner.  
     *     Semantic behavior of the composition is context driven, meaning
     *     duplicate elements may or may not be allowed by the composition in 
     *     the context of their use.
     * @tparam Consolidative 
     *     Type of the composition.
     * @tparam Natural
     *     Type of natural integer used by the composition.
     * @tparam Elemental
     *     Type of the elementary objects.
     */
template <
    typename Consolidative,
    typename Natural,
    typename Elemental>
struct Compositional {

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<const Natural>
            count)>
        precompose; /**< Function reference which can be used to prepare the
                         *   composition for the specified number of elements.  
                         *   If the composition does not support this operation
                         *   or it was unable to prepare for the requested 
                         *   count, false should be returned but not considered
                         *   an error condition.
                         */

    Referential<bool(
        Referential<const Consolidative>
            operand,
        Referential<const Elemental>
            value)>
        accredit; /**< Function reference which indicates if the specified
                       *   element currently exists in the composition.
                       */

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<const Elemental>
            value)>
        compose; /**< Function reference used to incorporate an element
                      *   in the composition.  The semantics of duplicate
                      *   elements are determined by the implementation which
                      *   can return false if it refuses duplicate elements.
                      */

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<const Elemental>
            original,
        Referential<const Elemental>
            replacement)>
        recompose; /**< Function reference used to replace a compostional
                        *   element with another.  A return value of false
                        *   should never alter the composition's __elements__.
                        *   The semantics of duplicate elements are determined
                        *   by the implementation.
                        */

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<const Elemental>
            value)>
        discompose; /**< Function reference used to remove an element from
                         *   the composition.  A return value of false should
                         *   never alter the composition's __elements__.  The
                         *   semantics of duplicate elements are determined by
                         *   the implementation.
                         */

    Referential<bool(
        Referential<Consolidative>
            operand)>
        decompose; /**< Function reference used to remove all elements from
                        *   the composition.  A return value of false means
                        *   that no elements were removed from the composition.
                        */

    Referential<bool(
        Referential<Consolidative>
            operand)>
        dispose; /**< Function reference used to indicate that the
                      *   implementation should tidy up any temporary space
                      *   being used.  If the implementation cleans the
                      *   temporary space all at once, it should return false
                      *   when completed.  A return value of true should only
                      *   be returned if after doing some cleaning up, more 
                      *   temporary space could be cleared by a subsequent 
                      *   call to this function.
                      */
};

}

#endif
