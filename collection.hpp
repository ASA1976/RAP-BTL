// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef COLLECTION_MODULE
#define COLLECTION_MODULE
#include "selection.hpp"

/**
 * @brief
 *     Sorted set management.
 * @details
 *     Sorted set management abstracts, classifiers and sorted set equality
 *     comparison function.
 */
namespace collection {

using ::composition::Compositional;
using ::location::Referential;
using ::selection::Equipollent;
using ::selection::Sectional;
using ::selection::Selective;
using ::sortation::Assortive;
using ::trajection::Axial;
using ::trajection::Directional;

/**
 * @brief
 *     Function type which simplifies declaration syntax.
 * @details 
 *     Function type alias used to declare sorted set duplication function 
 *     references.
 * @tparam Consolidative
 *     Type of the operand set.
 * @tparam Basic
 *     Type of the base set.
 * @tparam BasicPositional
 *     Type of positions used by the base set.
 * @tparam BasicNatural
 *     Type of natural integer used by the base set.
 * @tparam Elemental
 *     Type of the elementary set objects.
 */
template <
    typename Consolidative,
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Elemental>
using Collative = bool(
    Referential<Consolidative>
        operand,
    Referential<const Axial<const Basic, BasicPositional, BasicNatural, const Elemental>>
        basis,
    Referential<const Basic>
        base_set);

/**
 * @brief
 *     Function type which simplifies declaration syntax.
 * @details
 *     Function type alias used to declare sorted set operation function 
 *     references.
 * @tparam Consolidative
 *     Type of the operand set.
 * @tparam Basic
 *     Type of the base set.
 * @tparam BasicPositional
 *     Type of positions used by the base set.
 * @tparam BasicNatural
 *     Type of natural integer used by the base set.
 * @tparam Relative
 *     Type of the relative set.
 * @tparam RelativePositional 
 *     Type of positions used by the relative set.
 * @tparam RelativeNatural
 *     Type of natural integer used by the relative set.
 * @tparam Elemental
 *    Type of the elementary set objects.
 */
template <
    typename Consolidative,
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Relative,
    typename RelativePositional,
    typename RelativeNatural,
    typename Elemental>
using BisectionallyOperative = bool(
    Referential<Consolidative>
        opeand,
    Referential<const Axial<const Basic, BasicPositional, BasicNatural, const Elemental>>
        basis,
    Referential<const Basic>
        base_set,
    Referential<const Axial<const Relative, RelativePositional, RelativeNatural, const Elemental>>
        relativity,
    Referential<const Relative>
        relative_set);

/**
 * @brief
 *     Set on set operations classifier.
 * @details
 *     This type is used for sorted set operations when both sets make use
 *     of the same sortation order.
 * @tparam Consolidative
 *     Type of the operand set.
 * @tparam Basic
 *     Type of the base set.
 * @tparam BasicPositional
 *     Type of positions used by the base set.
 * @tparam BasicNatural
 *     Type of natural integer used by the base set.
 * @tparam Relative 
 *     Type of the relative set.
 * @tparam RelativePositional 
 *     Type of positions used by the relative set.
 * @tparam RelativeNatural 
 *     Type of natural integer used by the relative set.
 * @tparam Elemental 
 *     Type of the elementary set objects.
 */
template <
    typename Consolidative,
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Relative,
    typename RelativePositional,
    typename RelativeNatural,
    typename Elemental>
struct Bisectional {

    Referential<BisectionallyOperative<Consolidative, Basic, BasicPositional, BasicNatural, Relative, RelativePositional, RelativeNatural, Elemental>>
        complement, /**< Function reference used to compose the relative 
                     *   complement of two sorted sets. 
                     */
        differentiate, /**< Function reference used to compose the
                        *   difference of two sorted sets. 
                        */
        intersect, /**< Function reference used to compose the
                    *   intersection of two sorted sets. 
                    */
        unite; /**< Function reference used to compose the union of two
                *   sorted sets. 
                */
};

/**
 * @brief
 *     Sorted set management classifier.
 * @details 
 *     This type is used for sorted set management including elementary and
 *     whole set operation objectives, sorted set duplication and sorted set
 *     comparison.
 * @tparam Consolidative 
 *     Type of the operand set.
 * @tparam Positional
 *     Type of positions used by the operand set.
 * @tparam Natural 
 *     Type of natural integer used by the operand set.
 * @tparam Elemental
 *     Type of the elementary set objects.
 */
template <
    typename Consolidative,
    typename Positional,
    typename Natural,
    typename Elemental>
struct Collective {

    Referential<const Selective<Consolidative, Positional, Natural, Elemental>>
        selector; /**< Objective reference used to perform elementary 
                   *   sorted set operations and operations between sets 
                   *   which are not in the same sortation order.
                   */

    Referential<const Bisectional<Consolidative, Consolidative, Positional, Natural, Consolidative, Positional, Natural, Elemental>>
        bisection; /**< Objective reference used to perform set operations 
                    *   between sets in the same sortation order. 
                    */

    Referential<Collative<Consolidative, Consolidative, Positional, Natural, Elemental>>
        collate; /**< Function reference used to duplicate a sorted set. */

    Referential<Equipollent<Consolidative, Positional, Natural, Consolidative, Positional, Natural, Elemental>>
        correlate; /**< Function reference used to evaluate the equivalency
                    *   of two sorted sets. 
                    */
};

/**
 * @brief
 *     Compares two sorted sets of the same sortation order for set 
 *     equivalence.
 * @details
 *     Compares the elements of any two sorted sets for equivalence.  If 
 *     both sets are empty or both sets contain the same number of 
 *     equivalent elements, the two sets are considered equal.
 * @tparam Basic 
 *     Type of the base set.
 * @tparam BasicPositional
 *     Type of positions used by the base set.
 * @tparam BasicNatural
 *     Type of natural integer used by the base set.
 * @tparam Relative
 *     Type of the relative set.
 * @tparam RelativePositional 
 *     Type of positions used by the relative set.
 * @tparam RelativeNatural
 *     Type of natural integer used by the relative set.
 * @tparam Elemental
 *     Type of the elementary set objects.
 * @tparam Equate
 *     Function reference used to compare set elements for equivalence.
 * @param[in] basis
 *     Reference to the base set directional trajection objective.
 * @param[in] base_set 
 *     Reference to the base set.
 * @param[in] relativity
 *     Reference to the relative set directional trajection objective.
 * @param[in] relative_set
 *     Reference to the relative set.
 * @return
 *     True if both sets contain the same equivalent elements.
 */
template <
    typename Basic,
    typename BasicPositional,
    typename BasicNatural,
    typename Relative,
    typename RelativePositional,
    typename RelativeNatural,
    typename Elemental,
    Referential<Assortive<Elemental>> Equate>
static inline bool
EquateCollections(
    Referential<const Directional<const Basic, BasicPositional, BasicNatural, const Elemental>>
        basis,
    Referential<const Basic>
        base_set,
    Referential<const Directional<const Relative, RelativePositional, RelativeNatural, const Elemental>>
        relativity,
    Referential<const Relative>
        relative_set)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    using namespace ::std;
    static_assert(
        is_integral<BasicNatural>::value && is_unsigned<BasicNatural>::value,
        "BasicNatural:  Unsigned integer type required");
    static_assert(
        is_integral<RelativeNatural>::value && is_unsigned<RelativeNatural>::value,
        "RelativeNatural:  Unsigned integer type required");
#endif
    BasicPositional base_position;
    RelativePositional relative_position;
    if (basis.begins(base_set, 0)) {
        if (!relativity.begins(relative_set, 0))
            return false;
        basis.scale.begin(base_set, base_position, 0);
        relativity.scale.begin(relative_set, relative_position, 0);
        while (true) {
            if (!Equate(basis.scale.go(base_set, base_position).to, relativity.scale.go(relative_set, relative_position).to))
                return false;
            if (!basis.traverses(base_set, base_position, 1)) {
                if (relativity.traverses(relative_set, relative_position, 1))
                    return false;
                break;
            }
            basis.scale.traverse(base_set, base_position, 1);
            relativity.scale.traverse(relative_set, relative_position, 1);
        }
    } else if (relativity.begins(relative_set, 0))
        return false;
    return true;
}

}

#endif
