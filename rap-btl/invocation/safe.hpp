// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_INVOCATION_MODULE
#define SAFE_INVOCATION_MODULE
#include <invocation.hpp>

namespace invocation {

/**
 * @brief 
 *     Invokes the procedural object safely.
 * @details
 *     Invokes either a function, lambda or functor.  Throws an exception if
 *     locality is null or its dereferenced pointer space is in turn null.
 * @tparam Procedural
 *     Procedural (function, lambda or functor) type.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 * @param[in] locality 
 *     Data pointer to the procedural object.
 * @param[in] arguments
 *     Argument pack which is expanded for the invocation.
 * @return
 *     Result of the invocation.
 */
template <
    typename Procedural,
    typename Resultant,
    typename... Parametric>
Resultant
InvokeProcedureSafely(
    const Locational<const void>
        locality,
    Parametric... arguments)
{
    using namespace ::location;
    using Classificatory = Locational<const Locational<Procedural>>;
    static auto& Invoke = InvokeProcedure<Procedural, Resultant, Parametric...>;
    const Classificatory objective = static_cast<Classificatory>(locality);
    if (!objective)
        throw objective;
    if (!Refer(objective).to)
        throw Refer(objective).to;
    return Invoke(objective, arguments...);
}

/**
 * @brief 
 *     Invokes an object oriented non-static method safely.
 * @details
 *     Invokes an object oriented non-static method. Throws an exception if
 *     locality itself is null or either of its members, method or object 
 *     are null.
 * @tparam ClassTypical
 *     Qualified object oriented class type.
 * @tparam MethodLocational
 *     Pointer to qualified member function type.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 * @param[in] locality 
 *     Data pointer to the methodic instance.
 * @param[in] arguments
 *     Argument pack which is expanded for the invocation.
 * @return
 *     Result of the invocation.
 */
template <
    class ClassTypical,
    typename MethodLocational,
    typename Resultant,
    typename... Parametric>
Resultant
InvokeMethodSafely(
    const Locational<const void>
        locality,
    Parametric... arguments)
{
    using Specific = Methodic<ClassTypical, MethodLocational, Resultant, Parametric...>;
    using Classificatory = Locational<const Specific>;
    static auto& Invoke = InvokeMethod<ClassTypical, MethodLocational, Resultant, Parametric...>;
    const Classificatory objective = static_cast<Classificatory>(locality);
    if (!objective)
        throw objective;
    if (!objective->method)
        throw objective->method;
    if (!objective->object)
        throw objective->object;
    return Invoke(objective, arguments...);
}

/**
 * @brief 
 *     Prepares a lambda expression which can safely invoke the invocation.
 * @details
 *     Prepares a lambda expression which can later be used to invoke any
 *     invocation.  The invocative instance is captured by copy when 
 *     PrepareInvocation is called.  Throws an exception immediately if 
 *     either of the interface or locality members of the invocative 
 *     instance are null.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 * @param[in] invocation 
 *     Reference to a constant invocative instance.
 * @return
 *     Lambda expression returned by value.
 */
template <
    typename Resultant,
    typename... Parametric>
static inline auto
PrepareInvocationSafely(
    Referential<const Invocative<Resultant, Parametric...>>
        invocation)
{
    if (!invocation.interface)
        throw invocation.interface;
    if (!invocation.locality)
        throw invocation.locality;
    return PrepareInvocation(invocation);
}

/**
 * @brief 
 *     Assigns a non-static method safely.
 * @details
 *     Assigns a method and object to a methodic instance, which can be 
 *     assigned to an invocative instance.  Throws an exception if method 
 *     is null.
 * @tparam ClassTypical
 *     Qualified object oriented class type.
 * @tparam MethodLocational
 *     Pointer to qualified member function type.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 * @param[in] method
 *     Pointer to qualified member function.
 * @param[in] object
 *     Reference to qualified data object.
 * @return
 *     Methodic message instance returned by value.
 */
template <
    class ClassTypical,
    typename MethodLocational,
    typename Resultant,
    typename... Parametric>
static inline Methodic<ClassTypical, MethodLocational, Resultant, Parametric...>
AssignClassMethodSafely(
    MethodLocational
        method,
    Referential<ClassTypical>
        object)
{
    using namespace ::location;
    using Specific = Methodic<ClassTypical, MethodLocational, Resultant, Parametric...>;
    if (!method)
        throw method;
    const Specific message = { method, Locate(object).at };
    return message;
}

/**
 * @brief 
 *     Assigns a safe procedural invocative instance.
 * @details
 *     Assigns an invocative instance which can later be used to invoke the 
 *     procedure specified by locality.  The locality argument specifier
 *     must have sufficient duration such that it exists when the invocation
 *     occurs.  If the locality provided is null, this version will throw 
 *     the locality argument.  The resulting interface function will throw
 *     an exception if its provided pointers are null.
 * @tparam Procedural
 *     Procedural (function, lambda or functor) type.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 * @param[in] locality
 *     Reference to a pointer with suitable duration.
 * @return
 *     Invocative instance returned by value.
 */
template <
    typename Procedural,
    typename Resultant,
    typename... Parametric>
static inline Invocative<Resultant, Parametric...>
AssignInvokeProcedureSafely(
    Referential<const Locational<Procedural>>
        locality)
{
    using namespace ::location;
    using Specific = Invocative<Resultant, Parametric...>;
    static auto& Invoke = InvokeProcedureSafely<Procedural, Resultant, Parametric...>;
    if (!locality)
        throw locality;
    const Specific invocation = { Locate(Invoke).at, Locate(locality).at };
    return invocation;
}

/**
 * @brief 
 *     Assigns a safe methodic invocative instance.
 * @details
 *     Assigns an invocative instance which can later be used to invoke a 
 *     specific method against an object both specified by the instance 
 *     argument.  The instance argument specifier must have sufficient 
 *     duration such that it exists when the invocation occurs.  The 
 *     resulting interface function will throw an exception if its provided 
 *     pointers are null.
 * @tparam ClassTypical
 *     Qualified object oriented class type.
 * @tparam MethodLocational
 *     Pointer to qualified member function type.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 * @param[in] message
 *     Reference to a methodic message instance with suitable duration.
 * @return
 *     Invocative instance returned by value.
 */
template <
    class ClassTypical,
    typename MethodLocational,
    typename Resultant,
    typename... Parametric>
static inline Invocative<Resultant, Parametric...>
AssignInvokeMethodSafely(
    Referential<const Methodic<ClassTypical, MethodLocational, Resultant, Parametric...>>
        message)
{
    using namespace ::location;
    using Specific = Invocative<Resultant, Parametric...>;
    static auto& Invoke = InvokeMethodSafely<ClassTypical, MethodLocational, Resultant, Parametric...>;
    const Specific invocation = { Locate(Invoke).at, Locate(message).at };
    return invocation;
}

/**
 * @brief 
 *     Assigns a safe procedural invocative instance.
 * @details
 *     Assigns an invocative instance which can later be used to invoke the 
 *     function specified by locality.  The locality argument specifier
 *     must have sufficient duration such that it exists when the invocation
 *     occurs.  If the locality provided is null, this version will throw 
 *     the locality argument.  The resulting interface function will throw
 *     an exception if its provided pointers are null.
 * @tparam Resultant
 *     Return type of the invocation.
 * @tparam ...Parametric
 *     Parameter pack which represents the parameter types of the invocation.
 * @param[in] locality
 *     Reference to a pointer with suitable duration.
 * @return
 *     Invocative instance returned by value.
 */
template <
    typename Resultant,
    typename... Parametric>
static inline Invocative<Resultant, Parametric...>
AssignInvokeFunctionSafely(
    Referential<const Locational<Abstract<Resultant, Parametric...>>>
        locality)
{
    using namespace ::location;
    using Specific = Invocative<Resultant, Parametric...> static auto& Invoke = InvokeProcedureSafely<Abstract<Resultant, Parametric...>, Resultant, Parametric...>;
    if (!locality)
        throw locality;
    const Specific invocation = { Locate(Invoke).at, Locate(locality).at };
    return invocation;
}

}

#endif
