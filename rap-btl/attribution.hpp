// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ATTRIBUTION_MODULE
#define ATTRIBUTION_MODULE
#include <location.hpp>

/**
 * @brief   
 *     Positional pool management.
 * @details
 *     A pool management classifier is provided which is used to manage a pool 
 *     of positional elements.
 */
namespace attribution {

using ::location::Referential;

/**
 * @brief
 *     Pool management classifier.
 * @details 
 *     This type is used to manage a pool of positional elements.
 * @tparam Consolidative 
 *     Type of the space which contains the pool.
 * @tparam Positional
 *     Type of the positions in the pool.
 * @tparam Natural
 *     Type of natural integer for counts.
 */
template <
    typename Consolidative,
    typename Positional,
    typename Natural>
struct Tributary {

    Referential<Natural(
        Referential<const Consolidative>
            pool)>
        survey; /**< Function reference which reports the maximum number of
                 *   elements available in the pool.
                 */

    Referential<Natural(
        Referential<const Consolidative>
            pool)>
        account; /**< Function reference which reports the number of
                  *   elements which are currently distributed from the 
                  *   pool.
                  */

    Referential<bool(
        Referential<Consolidative>
            pool,
        Referential<Positional>
            position)>
        distribute; /**< Function reference used to request an element from
                     *   the pool.  Returns true if an element was assigned 
                     *   and sets the position reference to the position in 
                     *   the space which was assigned for this request.
                     */

    Referential<bool(
        Referential<Consolidative>
            pool,
        Referential<const Positional>
            position)>
        retribute; /**< Function reference used to return a specific element
                    *   to the pool.  Returns true if the provided position
                    *   was succesfully retributed to the pool.
                    */

    Referential<bool(
        Referential<Consolidative>
            pool)>
        contribute; /**< Function reference used to return all elements to
                     *   the pool.  Returns true if the operation altered
                     *   the pool.
                     */
};

}

#endif
