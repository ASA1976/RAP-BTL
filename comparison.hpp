// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef COMPARISON_MODULE
#define COMPARISON_MODULE
#include "location.hpp"

/**
 * @brief   
 *     Comparison and operator based implementations.
 * @details 
 *     Equality, relational and combined comparison classifiers are provided 
 *     which permit different contexts of comparison to exist pertaining to the
 *     same type (many-to-one relationship).  These classifiers can also be 
 *     useful in generic programming instead of relying on operator overloads
 *     to perform comparisons.  Functions and objectives are provided as simple
 *     wrappers for operator based comparison implementations for types which 
 *     support C++ language based comparison operators.
 */
namespace comparison {

using ::location::Referential;

/**
 * @brief
 *     Function type used by all comparison classifiers.
 * @details 
 *     Function type alias used to compare two values and return a boolean 
 *     result.
 * @tparam Basic
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 */
template <
    typename Basic,
    typename Relative = Basic>
using BinaryComparative = bool(
    Referential<const Basic>
        base,
    Referential<const Relative>
        relative);

/**
 * @brief 
 *     Equality comparison classifier.
 * @details 
 *     This type is used for in/equality comparisons only.
 * @tparam Basic
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 */
template <
    typename Basic,
    typename Relative = Basic>
struct Equative {

    Referential<BinaryComparative<Basic, Relative>>
        is_equal, /**< Function reference used to compare for equality. */
        is_not_equal; /**< Function reference used to compare for 
                       *   inequality. 
                       */
};

/**
 * @brief   
 *     Relational comparison classifier.
 * @details 
 *     This type is used for relational comparisons only.
 * @tparam Basic
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 */
template <
    typename Basic,
    typename Relative = Basic>
struct Relational {

    Referential<BinaryComparative<Basic, Relative>>
        is_lesser, /**< Function reference used to determine if the first 
                    *   argument is less than the second. 
                    */
        is_greater, /**< Function reference used to determine if the first 
                     *   argument is greater than the second. 
                     */
        is_not_greater, /**< Function reference used to determine if the 
                         *   first argument is not greater than the second. 
                         */
        is_not_lesser; /**< Function reference used to determine if the 
                        *   first argument is not less than the second. 
                        */
};

/**
 * @brief
 *     Combined comparison classifier.
 * @details 
 *     This type combines both equality and relational comparisons.
 * @tparam Basic
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 */
template <
    typename Basic,
    typename Relative = Basic>
struct Comparative {

    Referential<const Equative<Basic, Relative>>
        equality; /**< Reference to equality comparison objective table. */

    Referential<const Relational<Basic, Relative>>
        relation; /**< Reference to relational comparison objective table. */
};

/**
 * @brief
 *     Compares two values for equality using the equal to operator.
 * @details
 *     This function wraps the C++ equal to operator in order to implement
 *     the is_equal member of the equative classifier.
 * @tparam Basic
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 * @param[in] base
 *     Reference to the base object.
 * @param[in] relative
 *     Reference to the relative object.
 * @return
 *     True if both objects are to be considered equal.
 */
template <
    typename Basic,
    typename Relative = Basic>
static inline bool
IsEqual(
    Referential<const Basic>
        base,
    Referential<const Relative>
        relative)
{
    return base == relative;
}

/**
 * @brief
 *     Compares two values for inequality using the not equal to operator.
 * @details
 *     This function wraps the not equal to operator in order to implement 
 *     the is_not_equal member of the equative classifier.
 * @tparam Basic 
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 * @param[in] base
 *     Reference to the base object.
 * @param[in] relative
 *     Reference to the relative object.
 * @return
 *     True if both objects are to be considered not equal.
 */
template <
    typename Basic,
    typename Relative = Basic>
static inline bool
IsNotEqual(
    Referential<const Basic>
        base,
    Referential<const Relative>
        relative)
{
    return base != relative;
}

/**
 * @brief
 *     Compares two values using the less than operator.
 * @details
 *     This function wraps the less than operator in order to implement the 
 *     is_lesser member of the relational classifier.
 * @tparam Basic
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 * @param[in] base
 *     Reference to the base object.
 * @param[in] relative
 *     Reference to the relative object.
 * @return
 *     True if base is less than relative.
 */
template <
    typename Basic,
    typename Relative = Basic>
static inline bool
IsLesser(
    Referential<const Basic>
        base,
    Referential<const Relative>
        relative)
{
    return base < relative;
}

/**
 * @brief
 *     Compares two values using the greater than operator.
 * @details
 *     This function wraps the greater than operator in order to implement
 *     the is_greater member of the relational classifier.
 * @tparam Basic 
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 * @param[in] base
 *     Reference to the base object.
 * @param[in] relative
 *     Reference to the relative object.
 * @return
 *     True if base is greater than relative.
 */
template <
    typename Basic,
    typename Relative = Basic>
static inline bool
IsGreater(
    Referential<const Basic>
        base,
    Referential<const Relative>
        relative)
{
    return base > relative;
}

/**
 * @brief
 *     Compares two values using the less than or equal to operator.
 * @details
 *     This function wraps the less than or equal to operator in order to
 *     implement the is_not_greater member of the relational classifier.
 * @tparam Basic
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 * @param[in] base
 *     Reference to the base object.
 * @param[in] relative
 *     Reference to the relative object.
 * @return
 *     True if base is not greater than relative.
 */
template <
    typename Basic,
    typename Relative = Basic>
static inline bool
IsNotGreater(
    Referential<const Basic>
        base,
    Referential<const Relative>
        relative)
{
    return base <= relative;
}

/**
 * @brief
 *     Compares two values greater than or equal to operator.
 * @details
 *     This function wraps the greater than or equal to operator in order to
 *     implement the is_not_lesser member of the relational classifier.
 * @tparam Basic
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 * @param[in] base
 *     Reference to the base object.
 * @param[in] relative
 *     Reference to the relative object.
 * @return
 *     True if base is not less than relative.
 */
template <
    typename Basic,
    typename Relative = Basic>
static inline bool
IsNotLesser(
    Referential<const Basic>
        base,
    Referential<const Relative>
        relative)
{
    return base >= relative;
}

/**
 * @brief
 *     Equality comparison objective.
 * @details
 *     Objective which uses equality comparison operators in order to 
 *     implement the equative classifier.
 * @tparam Basic 
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 */
template <
    typename Basic,
    typename Relative = Basic>
constexpr Equative<Basic, Relative>
    Equality = {
        IsEqual<Basic, Relative>,
        IsNotEqual<Basic, Relative>
    };

/**
 * @brief 
 *     Relational comparison objective.
 * @details
 *     Objective which uses relational comparison operators in order to 
 *     implement the relational classifier.
 * @tparam Basic
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 */
template <
    typename Basic,
    typename Relative = Basic>
constexpr Relational<Basic, Relative>
    Relation = {
        IsLesser<Basic, Relative>,
        IsGreater<Basic, Relative>,
        IsNotGreater<Basic, Relative>,
        IsNotLesser<Basic, Relative>
    };

/**
 * @brief
 *     Combined comparison objective.
 * @details
 *     Objective which uses comparison operators in order to implement the 
 *     comparative classifier.
 * @tparam Basic 
 *     Type of the base object.
 * @tparam Relative
 *     Type of the relative object.
 */
template <
    typename Basic,
    typename Relative = Basic>
constexpr Comparative<Basic, Relative>
    Comparison = {
        Equality<Basic, Relative>,
        Relation<Basic, Relative>
    };

}

#endif
