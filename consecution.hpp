// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef CONSECUTION_MODULE
#define CONSECUTION_MODULE
#include "trajection.hpp"

/**
 * @brief
 *     Sequence management.
 * @details
 *     Association
 *     -----------
 *     Sequence management abstracts and classifiers.
 */
namespace consecution {

    using ::location::Referential;
    using ::trajection::Directional;

    /**
     * @brief
     *     Function type which simplifies declaration syntax.
     * @details 
     *     Abstraction Template
     *     --------------------
     *     Function type alias used to declare accede and proceed batch element
     *     function references.
     * @tparam Consolidative
     *     Type of the sequence.
     * @tparam Positional
     *     Type of positions in the sequence.
     * @tparam Relative
     *     Type of the relative space.
     * @tparam Appositional
     *     Type of positions used by the relative space.
     * @tparam RelativeNatural
     *     Type of natural integer used by the relative space.
     * @tparam Elemental 
     *     Type of the elementary objects.
     */
    template <
        typename Consolidative,
        typename Positional,
        typename Relative,
        typename Appositional,
        typename RelativeNatural,
        typename Elemental
    >
    using ConjointlyConsequent = bool(
        Referential< Consolidative >
            operand,
        Referential< const Directional< const Relative, Appositional, RelativeNatural, const Elemental > >
            relativity,
        Referential< const Relative >
            relative, 
        Referential< const Appositional >
            first, 
        Referential< const Appositional >
            last 
    );

    /**
     * @brief
     *     Function type which simplifies declaration syntax.
     * @details
     *     Abstraction Template
     *     --------------------
     *     Function type alias used to declare precede and cede batch element 
     *     function references.
     * @tparam Consolidative
     *     Type of the sequence.
     * @tparam Positional
     *     Type of positions in the sequence.
     * @tparam Relative
     *     Type of the relative space.
     * @tparam Appositional
     *     Type of positions used by the relative space.
     * @tparam RelativeNatural
     *     Type of natural integer used by the relative space.
     * @tparam Elemental 
     *     Type of the elementary objects.
     */
    template <
        typename Consolidative,
        typename Positional,
        typename Relative,
        typename Appositional,
        typename RelativeNatural,
        typename Elemental
    >
    using ConjointlyPrecedent = bool(
        Referential< Consolidative >
            operand, 
        Referential< const Positional >
            rank, 
        Referential< const Directional< const Relative, Appositional, RelativeNatural, const Elemental > >
            relativity, 
        Referential< const Relative >
            relative, 
        Referential< const Appositional >
            first, 
        Referential< const Appositional >
            last 
    );

    /**
     * @brief
     *     Sequence batch insertion classifier.
     * @details
     *     Classification Template
     *     -----------------------
     *     This type is used to insert a batch of elements into a sequence at 
     *     once from another sequential space.
     * @tparam Consolidative
     *     Type of the operand sequence.
     * @tparam Positional
     *     Type of positions used by the operand sequence.
     * @tparam Relative
     *     Type of the relative space.
     * @tparam Appositional
     *     Type of positions used by the relative space.
     * @tparam RelativeNatural 
     *     Type of natural integer used by the relative space.
     * @tparam Elemental
     *     Type of the elementary objects.
     */
    template <
        typename Consolidative,
        typename Positional,
        typename Relative,
        typename Appositional,
        typename RelativeNatural,
        typename Elemental
    >
    struct Conjoint {

        Referential< ConjointlyConsequent< Consolidative, Positional, Relative, Appositional, RelativeNatural, Elemental > >
            accede; /**< Function reference used to insert the specified range 
                     *   of elements in the relative space at the beginning of 
                     *   the operand sequence.
                     */

        Referential< ConjointlyPrecedent< Consolidative, Positional, Relative, Appositional, RelativeNatural, Elemental > >
            precede; /**< Function reference used to insert the specified range 
                      *   of elements in the relative space __before__ the 
                      *   specified position in the operand sequence.
                      */

        Referential< ConjointlyPrecedent< Consolidative, Positional, Relative, Appositional, RelativeNatural, Elemental > >
            cede; /**< Function reference used to insert the specified range 
                   *   of elements in the relative space __after__ the specified
                   *   position in the operand sequence.
                   */

        Referential< ConjointlyConsequent< Consolidative, Positional, Relative, Appositional, RelativeNatural, Elemental > >
            proceed; /**< Function reference used to insert the specified range 
                      *   of elements in the relative space at the end of the 
                      *   operand sequence.
                      */

    };

    /**
     * @brief
     *     Sequence management classifier.
     * @details
     *     Classification Template
     *     -----------------------
     *     This type is used to manage a sequence of elements.  It provides 
     *     elementary operations for an instance of a sequence as well as batch
     *     insertion into the sequence from an instance of the same 
     *     consolidative type.
     * @tparam Consolidative
     *     Type of the sequence.
     * @tparam Positional 
     *     Type of positions used by the sequence.
     * @tparam Natural
     *     Type of natural integer used by the sequence.
     * @tparam Elemental
     *     Type of the elements in the sequence.
     */
    template <
        typename Consolidative,
        typename Positional,
        typename Natural,
        typename Elemental
    >
    struct Sequent {

        Referential< bool(
            Referential< Consolidative >
                operand, 
            Referential< const Natural >
                count 
        ) >
            antecede; /**< Function reference which can be used to prepare the
                       *   sequence for the specified number of elements.  If 
                       *   the sequence does not support this operation or it 
                       *   was unable to prepare for the requested count, false
                       *   should be returned but not considered an error 
                       *   condition.
                       */

        Referential< Natural(
            Referential< const Consolidative >
                operand 
        ) >
            account; /**< Function reference which returns the current number
                      *   of elements in the sequence.
                      */

        Referential< bool(
            Referential< Consolidative >
                operand, 
            Referential< const Elemental >
                value 
        ) >
            accede; /**< Function reference which inserts the specified 
                     *   element at the beginning of the sequence.
                     */

        Referential< bool(
            Referential< Consolidative >
                operand, 
            Referential< const Positional >
                rank, 
            Referential< const Elemental >
                value 
        ) >
            precede; /**< Function reference which inserts the specified 
                      *   element before the specified position in the sequence.
                      */

        Referential< bool(
            Referential< Consolidative >
                operand, 
            Referential< const Positional >
                rank, 
            Referential< const Elemental >
                value 
        ) >
            cede; /**< Function reference which inserts the specified 
                   *   element after the specified position in the sequence.
                   */

        Referential< bool(
            Referential< Consolidative >
                operand, 
            Referential< const Elemental >
                value 
        ) >
            proceed; /**< Function reference which inserts the specified 
                      *   element at the end of the sequence.
                      */

        Referential< bool(
            Referential< Consolidative >
                operand, 
            Referential< const Natural >
                count 
        ) >
            succeed; /**< Function reference which removes the specified
                      *   number of elements from the beginning of the
                      *   sequence.
                      */

        Referential< bool(
            Referential< Consolidative >
                operand, 
            Referential< const Positional >
                rank, 
            Referential< const Natural >
                count 
        ) >
            supersede; /**< Function reference which removes the specified
                        *   number of elements from the sequence including
                        *   the specified position and positions __before__ it.
                        */

        Referential< bool(
            Referential< Consolidative >
                operand, 
            Referential< const Positional >
                rank, 
            Referential< const Natural >
                count 
        ) >
            concede; /**< Function reference which removes the specified 
                      *   number of elements from the sequence including
                      *   the specified position and positions __after__ it.
                      */

        Referential< bool(
            Referential< Consolidative >
                operand, 
            Referential< const Natural >
                count 
        ) >
            recede; /**< Function reference which removes the specified
                     *   number of elements from the end of the sequence.
                     */

        Referential< bool(
            Referential< Consolidative >
                operand 
        ) >
            secede; /**< Function reference which removes all of the elements
                     *   from a sequence.
                     */

        Referential< bool(
            Referential< Consolidative >
                operand 
        ) >
            condense; /**< Function reference used to indicate that the
                       *   implementation should tidy up any temporary space
                       *   being used.  If the implementation cleans the
                       *   temporary space all at once, it should return false
                       *   when completed.  A return value of true __should 
                       *   only be returned if after doing some cleaning up, 
                       *   more temporary space could be cleared by a 
                       *   subsequent call to this function__.
                       */


        Referential< const Conjoint< Consolidative, Positional, Consolidative, Positional, Natural, Elemental > >
            conjoiner; /**< Objective reference used to insert a batch of
                        *   elements at once from a space of the same 
                        *   consolidative type as this sequence.
                        */

    };

}

#endif
