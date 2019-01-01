// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SELECTION_MODULE
#define SELECTION_MODULE
#include "composition.hpp"
#include "sortation.hpp"

/**
 * @brief   
 *     Unsorted set management.
 * @details 
 *     Association
 *     -----------
 *     Unsorted set management abstracts, classifiers and unsorted set equality 
 *     comparison function.
 */
namespace selection {

    using ::location::Referential;
    using ::trajection::Directional;
    using ::composition::Compositional;
    using ::sortation::Assortive;

    /**
     * @brief  
     *     Function type which simplifies declaration syntax.
     * @details 
     *     Abstraction Template
     *     --------------------
     *     Function type alias used to declare unsorted set duplication function
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
        typename Elemental
    >
    using Duplicative = bool(
        Referential< Consolidative >
            operand,
        Referential< const Directional< const Basic, BasicPositional, BasicNatural, const Elemental > >
            basis,
        Referential< const Basic >
            base_set
    );

    /**
     * @brief 
     *     Function type which simplifies declaration syntax.
     * @details 
     *     Abstraction Template
     *     --------------------
     *     Function type alias used to declare set equivalency determination 
     *     function references.
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
        typename Basic,
        typename BasicPositional,
        typename BasicNatural,
        typename Relative,
        typename RelativePositional,
        typename RelativeNatural,
        typename Elemental
    >
    using Equipollent = bool(
        Referential< const Directional< const Basic, BasicPositional, BasicNatural, const Elemental > >
            basis,
        Referential< const Basic >
            base_set,
        Referential< const Directional< const Relative, RelativePositional, RelativeNatural, const Elemental > >
            relativity,
        Referential< const Relative >
            relative_set
    );

    /**
     * @brief 
     *     Set on set operations classifier.
     * @details 
     *     Classification Template
     *     -----------------------
     *     This type is used for unsorted set operations.
     *
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
        typename Elemental
    >
    struct Sectional {

        Referential< bool(
            Referential< Consolidative >
                operand,
            Referential< const Directional< const Basic, BasicPositional, BasicNatural, const Elemental > >
                basis,
            Referential< const Basic >
                base_set,
            Referential< const Directional< const Relative, RelativePositional, RelativeNatural, const Elemental > >
                relativity,
            Referential< const Relative >
                relative_set
        ) >
            complement, /**< Function reference used to compose the relative 
                         *   complement of two unsorted sets. 
                         */
            differentiate, /**< Function reference used to compose the 
                            *   difference of two unsorted sets. 
                            */
            intersect, /**< Function reference used to compose the 
                        *   intersection of two unsorted sets. 
                        */
            unite; /**< Function reference used to compose the union
                    *   of two unsorted sets. 
                    */

    };

    /**
     * @brief 
     *     Unsorted set management classifier.
     * @details 
     *     Classification Template
     *     -----------------------
     *     This type is used for unsorted set management including elementary 
     *     and whole set operation objectives, unsorted set duplication, 
     *     unsorted set comparison and set counting.
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
        typename Elemental
    >
    struct Selective {

        Referential< const Compositional< Consolidative, Natural, Elemental > >
            composer; /**< Objective reference used to perform elementary 
                       *   set operations.  This composer must not allow two
                       *   elements which are equivalent to exist in the set.
                       */

        Referential< const Sectional< Consolidative, Consolidative, Positional, Natural, Consolidative, Positional, Natural, Elemental > >
            section; /**< Objective reference used to perform set operations 
                      *   between unsorted sets.
                      */

        Referential< Duplicative< Consolidative, Consolidative, Positional, Natural, Elemental > >
            duplicate; /**< Function reference used to duplicate an unsorted 
                        *   set.
                        */

        Referential< Equipollent< Consolidative, Positional, Natural, Consolidative, Positional, Natural, Elemental > >
            equate; /**< Function reference used to evaluate the equivalency
                     *   of two unsorted sets.
                     */

        Referential< Natural(
            Referential< const Consolidative >
                operand
        ) >
            count; /**< Function reference used to count the number of 
                    *   elements in a set.
                    */

    };

    /**
     * @brief
     *     Compares two unsorted sets for set equivalence.
     * @details
     *     Function Template
     *     -----------------
     *     Compares the elements of any two unsorted sets for equivalence.  If 
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
        Referential< Assortive< Elemental > >
            Equate
    >
    static inline bool
    EquateSelections(
        Referential< const Directional< const Basic, BasicPositional, BasicNatural, const Elemental > >
            basis,
        Referential< const Basic >
            base_set,
        Referential< const Directional< const Relative, RelativePositional, RelativeNatural, const Elemental > >
            relativity,
        Referential< const Relative >
            relative_set
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< BasicNatural >::value && is_unsigned< BasicNatural >::value,
            "BasicNatural:  Unsigned integer type required"
        );
        static_assert(
            is_integral< RelativeNatural >::value && is_unsigned< RelativeNatural >::value,
            "RelativeNatural:  Unsigned integer type required"
        );
#endif
        BasicPositional
            base_position;
        RelativePositional
            relative_position;
        if (basis.begins( base_set, 0 )) {
            if (!relativity.begins( relative_set, 0 ))
                return false;
            basis.scale.begin( base_set, base_position, 0 );
            while (true) {
                auto&
                    base_value = basis.scale.go( base_set, base_position ).to;
                relativity.scale.begin( relative_set, relative_position, 0 );
                while (true) {
                    auto&
                        relative_value = relativity.scale.go( relative_set, relative_position ).to;
                    if (Equate( base_value, relative_value ))
                        break;
                    if (!relativity.traverses( relative_set, relative_position, 1 ))
                        return false;
                    relativity.scale.traverse( relative_set, relative_position, 1 );
                }
                if (!basis.traverses( base_set, base_position, 1 ))
                    break;
                basis.scale.traverse( base_set, base_position, 1 );
            }
        } else if (relativity.begins( relative_set, 0 ))
            return false;
        return true;
    }

}

#endif
