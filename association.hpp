// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ASSOCIATION_MODULE
#define ASSOCIATION_MODULE
#include "location.hpp"

/**
 * @brief   
 *     Associative map management.
 * @details 
 *     Association
 *     -----------
 *     An associative mapping classifier is provided which is used to manage 
 *     associative maps.  A key-value pairing conformity is also provided for 
 *     convenience, which is not necessary in order to implement an associative
 *     mapping objective.
 */
namespace association {

using ::location::Referential;

/**
     * @brief
     *     Associative mapping classifier.
     * @details
     *     Classification Template
     *     -----------------------
     *     This type is used to manage associative maps.
     * @tparam Consolidative
     *     Type of the space which contains the mappings.
     * @tparam Natural
     *     Type of natural integer for counts.
     * @tparam Correlative
     *     Type of the relators (keys).
     * @tparam Evaluative
     *     Type of the values.
     */
template <
    typename Consolidative,
    typename Natural,
    typename Correlative,
    typename Evaluative>
struct Associative {

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<const Natural>
            count)>
        prepare; /**< Function reference which is used to prepare space for
                      *   mappings which is optional.  The implementation should
                      *   return false if the operation is not supported.
                      *   Returning false is not considered an error but an 
                      *   indicator that the space could not be pre-allocated.
                      */

    Referential<Natural(
        Referential<const Consolidative>
            operand)>
        grade; /**< Function reference which returns the number of paired 
                    *   mappings currently in the space. 
                    */

    Referential<bool(
        Referential<const Consolidative>
            operand,
        Referential<const Correlative>
            relator)>
        correspond; /**< Function reference which returns true if a relator
                         *   (key) corresponds to a value. 
                         */

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<const Correlative>
            relator,
        Referential<const Evaluative>
            value)>
        associate; /**< Function reference which adds a mapping to the 
                        *   space.  Mappings should only contain unique relators
                        *   (keys), therefore false should be returned if the 
                        *   relator already exists in the space without 
                        *   affecting the space.
                        */

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<const Correlative>
            relator,
        Referential<const Correlative>
            value)>
        reassociate; /**< Function reference which replaces a relator (key)
                          *   while preserving the value previously associated
                          *   with the relator.  If the old relator did not
                          *   exist or the new relator already exists, the
                          *   implementing function should return false
                          *   without affecting the space.
                          */

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<const Correlative>
            relator)>
        disassociate; /**< Function reference which removes a mapping from 
                           *   a space.  If the relator (key) did not exist
                           *   the implementing function should return false
                           *   without affecting the space.
                           */

    Referential<bool(
        Referential<Consolidative>
            operand)>
        disband; /**< Function reference which removes all mappings from a
                      *   a space.  Should return true if the space was modified
                      *   or false if it was not.
                      */

    Referential<bool(
        Referential<Consolidative>
            operand)>
        dissolve; /**< Function reference used to deallocate memory space.
                       *   Implementations may deallocate all unused memory at 
                       *   once or deallocate a unit of memory space per call.
                       *   Either way true should be returned __only__ if there
                       *   exists more memory space available to be deallocated
                       *   __after__ the current call.
                       */
};

/**
     * @brief 
     *     Facilitates pairing a relator (key) and value.
     * @details  
     *     Conformation Template
     *     ---------------------
     *     This type can be used to pair a relator (key) and value.  It is 
     *     provided for convenience and does not have to be used by 
     *     implementations of the associative mapping classifier.
     * @tparam Correlative
     *     Type of the relator (key).
     * @tparam Evaluative
     *     Type of the value.
     */
template <
    typename Correlative,
    typename Evaluative>
struct Complementary {

    Correlative
        relator; /**< Instance of the relator (key). */

    Evaluative
        value; /**< Instance of the value. */
};

}

#endif
