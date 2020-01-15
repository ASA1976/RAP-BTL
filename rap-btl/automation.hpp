// © 2020 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef AUTOMATION_MODULE
#define AUTOMATION_MODULE
#include <location.hpp>

/**
 * @brief   
 *     Template used to trigger closure calls on another object's destructor.
 * @details 
 *     These templates are used to invoke a lambda when an object's 
 *     destructor is called.  This can be useful for automatically running
 *     a lambda expression just before any return statement in a function or
 *     at the end of any block scope within a function.  This can be used to
 *     automatically free memory at the end of a scope of reference, as an
 *     example.
 */
namespace automation {

using ::location::Referential;

/**
 * @brief 
 *     Immutable type which calls the lambda expression on destructor.
 * @details 
 *     Instances of this type will call the referenced lambda expression 
 *     when their own destructors have been called.
 * @tparam Expressive
 *     Type of the lambda expression without parameters to be called.
 */
template <typename Expressive>
struct Automatic final {

    Referential<const Expressive> closure; /**< Reference to a lambda expression. */
    Automatic(Referential<const Expressive> expression) : closure(expression) {}
    ~Automatic() { closure(); }
};

/**
 * @brief 
 *     Function which simplifies binding to a lambda.
 * @details 
 *     This function is useful for initializing an automatic object without
 *     requiring explicitly naming any types.  An example might be the statement
 *     "auto trigger = Automate([bindings]{ body });".
 * @tparam Expressive
 *     Type of the lambda expression without parameters to be called.
 */
template <typename Expressive>
static inline Automatic<Expressive>
Automate(
    Referential<const Expressive> 
        expression
) {
    using Specific = Automatic<Expressive>;
    return Specific(expression);
}

}
#endif
