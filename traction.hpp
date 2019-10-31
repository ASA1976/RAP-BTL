// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef TRACTION_MODULE
#define TRACTION_MODULE
#include "location.hpp"

/**
 * @brief   
 *     Positional stack or queue management.
 * @details 
 *     Association
 *     -----------
 *     A stack or queue management classifier is provided which is used to 
 *     manage a queue or stack of positional elements.
 */
namespace traction {

using ::location::Referential;

/**
     * @brief   
     *     Stack or queue management classifier.
     * @details 
     *     Classification Template
     *     -----------------------
     *     This type is used to manage a stack or queue of positional elements.
     * @tparam Consolidative
     *     Type of the consolidative space.
     * @tparam Positional
     *     Type of positions used by the space.
     * @tparam Natural
     *     Type of natural integer used by the space.
     */
template <
    typename Consolidative,
    typename Positional,
    typename Natural>
struct Tractile {

    Referential<Natural(
        Referential<const Consolidative>
            operand)>
        survey; /**< Function reference used to report the maximum number
                     *   of elements available in the space.
                     */

    Referential<Natural(
        Referential<const Consolidative>
            operand)>
        account; /**< Function reference used to report the number of 
                      *   currently allotted elements from the space.
                      */

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<Positional>
            position,
        Referential<const Natural>
            count)>
        protract; /**< Function reference used to request the allotment of
                       *   a specified number of elements from the space, where 
                       *   if the function returns true the position argument 
                       *   will represent the first allotted element in the
                       *   batch.
                       */

    Referential<bool(
        Referential<Consolidative>
            operand,
        Referential<const Natural>
            count)>
        retract; /**< Function reference used to return the specified 
                      *   number of elements to the space.
                      */

    Referential<bool(
        Referential<Consolidative>
            operand)>
        contract; /**< Function reference used to retract all allotted
                       *   elements to the space.
                       */
};

}

#endif
