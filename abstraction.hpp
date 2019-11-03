// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ABSTRACTION_MODULE
#define ABSTRACTION_MODULE
#include "location.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

/**
 * @brief   
 *     Abstraction facilitation.
 * @details 
 *     Abstraction of function and invocation of code objects with linkage.
 */
namespace abstraction {

using ::location::Referential;

/**
 * @brief 
 *     Function abstract.
 * @details 
 *     Function type alias corresponding to the invocation abstract.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 */
template <
    typename Resultant,
    typename... Parametric>
using Abstract = Resultant(Parametric...);

/**
 * @brief 
 *     Invokes a lambda or functor with linkage.
 * @details
 *     Invokes either a lambda or functor with linkage (from the file or 
 *     name space scope).  Invoking a function or static member 
 *     function can be done directly without this template, though this 
 *     template can also be used to invoke them.
 * @tparam Procedural
 *     Procedural (function, lambda or functor) type.
 * @tparam Location
 *     Reference to a function, lambda or functor object.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 * @param[in] arguments
 *     Argument pack which is expanded for the invocation.
 * @return
 *     Result of the invocation.
 */
template <
    typename Procedural,
    Referential<Procedural> Location,
    typename Resultant,
    typename... Parametric>
Resultant AbstractProcedure(Parametric... arguments)
{
    return Location(arguments...);
}

/**
 * @brief 
 *     Invokes a non-static method against an object with linkage.
 * @details
 *     Invokes an object oriented non-static method where the object 
 *     instance must have linkage.
 * @tparam ClassTypical
 *     Qualified object oriented class type.
 * @tparam MethodLocational
 *     Pointer to qualified member function type.
 * @tparam Object
 *     Reference to the object the method will be invoked against.
 * @tparam Method
 *     Pointer to the method which will be invoked.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 * @param[in] arguments
 *     Argument pack which is expanded for the invocation.
 * @return
 *     Result of the invocation.
 */
template <
    typename ClassTypical,
    typename MethodLocational,
    Referential<ClassTypical> Object,
    MethodLocational Method,
    typename Resultant,
    typename... Parametric>
Resultant AbstractMethod(Parametric... arguments)
{
#ifndef RAPBTL_NO_STD_CPLUSPLUS
    static_assert(
        ::std::is_member_function_pointer<MethodLocational>::value,
        "MethodLocational:  Pointer to member function type required");
#endif
    static_assert(Method != 0, "Method:  Pointer is null");
    return (Object.*Method)(arguments...);
}

}

#endif
