// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef INVOCATION_MODULE
#define INVOCATION_MODULE
#include "abstraction.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

/**
 * @brief   
 *     Invocation facilitation.
 * @details 
 *     Association
 *     -----------
 *     Invocation of any code object with or without linkage.
 */
namespace invocation {

    using ::location::Locational;
    using ::location::Referential;
    using ::location::Locate;
    using ::location::Refer;
    using ::abstraction::Abstract;

    /**
     * @brief         
     *     Invocation classifier.
     * @details       
     *     Classification Template
     *     -----------------------
     *     This type is used to represent the invocation of any stored procedure
     *     whose invocation abstract matches the provided specifiers.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     */
    template <
        typename Resultant,
        typename ...Parametric
    >
    struct Invocative {

        Locational< Abstract< Resultant, const Locational< const void >, Parametric... > >
            interface; /**< Code pointer to the interface function. */

        Locational< const void >
            objective; /**< Data pointer to the objective. */

        /**
         * @brief 
         *     Allows instances of the Invocative type to be directly invoked.
         * @details
         *     Operator Overload
         *     -----------------
         *     Invokes any kind of stored procedure, specific to the invocation
         *     abstract specified by the template arguments.
         */
        Resultant
        operator()( 
            Parametric... 
                arguments /**< Argument pack which is expanded for the invocation. */
        ) const {
            return interface( objective, arguments... );
        }

    };

    /**
     * @brief         
     *     Object oriented non-static method classifier.
     * @details       
     *     Classification Template
     *     -----------------------
     *     This type is used to represent a non-static method invocation.  
     *     Qualifiers should be applied to the ClassTypical and MethodLocational
     *     argument specifiers as appropriate in order to cast the object
     *     and pointer to member function as required in order to invoke the
     *     desired member function (qualifier overloads, etc.).
     * @tparam ClassTypical
     *     Qualified object oriented class type.
     * @tparam MethodLocational
     *     Pointer to qualified member function type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     */
    template <
        class ClassTypical,
        typename MethodLocational,
        typename Resultant,
        typename ...Parametric
    >
    struct Methodic {

#ifndef RAPBTL_NO_STD_CPLUSPLUS
        static_assert(
            ::std::is_member_function_pointer< MethodLocational >::value,
            "MethodLocational:  Pointer to member function type required"
        );
#endif

        MethodLocational
            method; /**< Pointer to qualified member function. */

        Locational< ClassTypical >
            object; /**< Pointer to qualified data object. */

    };

    /**
     * @brief 
     *     Invokes the procedural objective.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes either a function, lambda or functor objective.
     * @tparam Procedural
     *     Procedural (function, lambda or functor) type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] locality 
     *     Opaque pointer to the procedural objective.
     * @param[in] arguments
     *     Argument pack which is expanded for the invocation.
     * @return
     *     Result of the invocation.
     */
    template <
        typename Procedural,
        typename Resultant,
        typename ...Parametric
    >
    Resultant
    InvokeProcedure(
        const Locational< const void >
            locality,
        Parametric...
            arguments
    ) {
        using Specific = const Locational< const Locational< Procedural > >;
        static_assert(
            sizeof(Specific) == sizeof(const Locational< const void >),
            "Specific: Pointer to pointer should be a data type"
        );
        Specific
            objective = static_cast< Specific >(locality);
        return Refer( Refer( objective ).to ).to( arguments... );
    }

    /**
     * @brief 
     *     Invokes the procedural objective safely.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes either a function, lambda or functor objective.  Throws an
     *     exception if objective is null or its dereferenced pointer space is 
     *     in turn null.
     * @tparam Procedural
     *     Procedural (function, lambda or functor) type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] locality 
     *     Opaque pointer to the procedural objective.
     * @param[in] arguments
     *     Argument pack which is expanded for the invocation.
     * @return
     *     Result of the invocation.
     */
    template <
        typename Procedural,
        typename Resultant,
        typename ...Parametric
    >
    Resultant
    InvokeProcedureSafely(
        const Locational< const void >
            locality,
        Parametric...
            arguments
    ) {
        using Specific = const Locational< const Locational< Procedural > >;
        static_assert(
            sizeof(Specific) == sizeof(const Locational< const void >),
            "Specific: Pointer to pointer should be a data type"
        );
        static auto&
            Invoke = InvokeProcedure< Procedural, Resultant, Parametric... >;
        Specific
            objective = static_cast< Specific >(locality);
        if (!objective)
            throw objective;
        if (!Refer( objective ).to)
            throw Refer( objective ).to;
        return Invoke( objective, arguments ... );
    }

    /**
     * @brief 
     *     Invokes an object oriented non-static method objective.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes an object oriented non-static method objective.
     * @tparam ClassTypical
     *     Qualified object oriented class type.
     * @tparam MethodLocational
     *     Pointer to qualified member function type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] locality 
     *     Opaque pointer to the methodic objective.
     * @param[in] arguments
     *     Argument pack which is expanded for the invocation.
     * @return
     *     Result of the invocation.
     */
    template <
        class ClassTypical,
        typename MethodLocational,
        typename Resultant,
        typename ...Parametric
    >
    Resultant
    InvokeMethod(
        const Locational< const void >
            locality,
        Parametric...
            arguments
    ) {
        using Specific = const Locational< const Methodic< ClassTypical, MethodLocational, Resultant, Parametric... > >;
        Specific
            objective = static_cast< Specific >(locality);
        return (objective->object->*objective->method)( arguments... );
    }

    /**
     * @brief 
     *     Invokes an object oriented non-static method objective safely.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes an object oriented non-static method objective. Throws an 
     *     exception if objective itself is null or either of its members, 
     *     method or object are null.
     * @tparam ClassTypical
     *     Qualified object oriented class type.
     * @tparam MethodLocational
     *     Pointer to qualified member function type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] locality 
     *     Opaque pointer to the methodic objective.
     * @param[in] arguments
     *     Argument pack which is expanded for the invocation.
     * @return
     *     Result of the invocation.
     */
    template <
        class ClassTypical,
        typename MethodLocational,
        typename Resultant,
        typename ...Parametric
    >
    Resultant
    InvokeMethodSafely(
        const Locational< const void >
            locality,
        Parametric...
            arguments
    ) {
        using Specific = const Locational< const Methodic< ClassTypical, MethodLocational, Resultant, Parametric... > >;
        static auto&
            Invoke = InvokeMethod< ClassTypical, MethodLocational, Resultant, Parametric... >;
        Specific
            objective = static_cast< Specific >(locality);
        if (!objective)
            throw objective;
        if (!objective->method)
            throw objective->method;
        if (!objective->object)
            throw objective->object;
        return Invoke( objective, arguments ... );
    }

   /**
     * @brief 
     *     Prepares a lambda expression which can invoke the stored procedure.
     * @details
     *     Function Template
     *     -----------------
     *     Prepares a lambda expression which can be used to invoke any stored
     *     procedure.  The invocative instance is captured by copy when 
     *     PrepareInvocation is called.
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
        typename ...Parametric
    >
    static inline auto
    PrepareInvocation(
        Referential< const Invocative< Resultant, Parametric... > >
            invocation
    ) {
        auto 
            lambda = [invocation]( 
                Parametric... 
                    arguments 
            ) -> Resultant {
                return invocation.interface( invocation.objective, arguments... );
            };
        return lambda;
    }

   /**
     * @brief 
     *     Prepares a lambda expression which invokes a procedural call safely.
     * @details
     *     Function Template
     *     -----------------
     *     Prepares a lambda expression which can be used to invoke any stored
     *     procedure.  The invocative instance is captured by copy when 
     *     PrepareInvocation is called.  Throws an exception immediately if 
     *     either of the interface or objective members of the invocative 
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
        typename ...Parametric
    >
    static inline auto
    PrepareInvocationSafely(
        Referential< const Invocative< Resultant, Parametric... > >
            invocation
    ) {
        if (!invocation.interface)
            throw invocation.interface;
        if (!invocation.objective)
            throw invocation.objective;
        return PrepareInvocation( invocation );
    }

    /**
     * @brief 
     *     Assigns a non-static method objective.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an objective containing the pointers required to invoke an 
     *     object oriented non-static method.
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
     *     Methodic objective instance returned by value.
     */
    template <
        class ClassTypical,
        typename MethodLocational,
        typename Resultant,
        typename ...Parametric
    >
    static inline Methodic< ClassTypical, MethodLocational, Resultant, Parametric... >
    AssignMethodObjective(
        MethodLocational
            method, 
        Referential< ClassTypical >
            object
    ) {
        const Methodic< ClassTypical, MethodLocational, Resultant, Parametric... >
            objective = {method, Locate( object ).at};
        return objective;
    }

    /**
     * @brief 
     *     Assigns a non-static method objective safely.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an objective containing the pointers required to invoke an 
     *     object oriented non-static method.  Throws an exception if method is
     *     null.
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
     *     Methodic objective instance returned by value.
     */
    template <
        class ClassTypical,
        typename MethodLocational,
        typename Resultant,
        typename ...Parametric
    >
    static inline Methodic< ClassTypical, MethodLocational, Resultant, Parametric... >
    AssignMethodObjectiveSafely(
        MethodLocational
            method, 
        Referential< ClassTypical >
            object 
    ) {
        if (!method)
            throw method;
        const Methodic< ClassTypical, MethodLocational, Resultant, Parametric... >
            objective = {method, Locate( object ).at};
        return objective;
    }

    /**
     * @brief 
     *     Assigns a procedural invocative instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     procedure specified by objective.  The objective argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.
     * @tparam Procedural
     *     Procedural (function, lambda or functor) type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] objective
     *     Reference to a function pointer with suitable duration.
     * @return
     *     Invocative instance returned by value.
     */
    template <
        typename Procedural,
        typename Resultant,
        typename ...Parametric
    >
    static inline Invocative< Resultant, Parametric... >
    AssignInvokeProcedure(
        Referential< const Locational< Procedural > >
            objective
    ) {
        static_assert(
            sizeof Locate( objective ).at == sizeof(Locational< const void >),
            "objective: Pointer to pointer should be a data type"
        );
        static auto&
            Invoke = InvokeProcedure< Procedural, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( objective ).at};
        return invocation;
    }

    /**
     * @brief 
     *     Assigns a safe procedural invocative instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     procedure specified by objective.  The objective argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.  If the location provided is null, this version will throw 
     *     the objective argument.  The resulting interface function will throw
     *     an exception if its provided pointers are null.
     * @tparam Procedural
     *     Procedural (function, lambda or functor) type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] objective
     *     Reference to a function pointer with suitable duration.
     * @return
     *     Invocative instance returned by value.
     */
    template <
        typename Procedural,
        typename Resultant,
        typename ...Parametric
    >
    static inline Invocative< Resultant, Parametric... >
    AssignInvokeProcedureSafely(
        Referential< const Locational< Procedural > >
            objective
    ) {
        static_assert(
            sizeof Locate( objective ).at == sizeof(Locational< const void >),
            "objective: Pointer to pointer should be a data type"
        );
        static auto&
            Invoke = InvokeProcedureSafely< Procedural, Resultant, Parametric... >;
        if (!objective)
            throw objective;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( objective ).at};
        return invocation;
    }

    /**
     * @brief 
     *     Assigns a methodic invocative instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     method specified by objective.  The objective argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.
     * @tparam ClassTypical
     *     Qualified object oriented class type.
     * @tparam MethodLocational
     *     Pointer to qualified member function type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] objective
     *     Reference to method objective with suitable duration.
     * @return
     *     Invocative instance returned by value.
     */
    template <
        class ClassTypical,
        typename MethodLocational,
        typename Resultant,
        typename ...Parametric
    >
    static inline Invocative< Resultant, Parametric... >
    AssignInvokeMethod(
        Referential< const Methodic< ClassTypical, MethodLocational, Resultant, Parametric... > >
            objective
    ) {
        static auto&
            Invoke = InvokeMethod< ClassTypical, MethodLocational, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( objective ).at};
        return invocation;
    }

    /**
     * @brief 
     *     Assigns a safe methodic invocative instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     method specified by objective.  The objective argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.  The resulting interface function will throw an exception if 
     *     its provided pointers are null.
     * @tparam ClassTypical
     *     Qualified object oriented class type.
     * @tparam MethodLocational
     *     Pointer to qualified member function type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] objective
     *     Reference to method objective with suitable duration.
     * @return
     *     Invocative instance returned by value.
     */
    template <
        class ClassTypical,
        typename MethodLocational,
        typename Resultant,
        typename ...Parametric
    >
    static inline Invocative< Resultant, Parametric... >
    AssignInvokeMethodSafely(
        Referential< const Methodic< ClassTypical, MethodLocational, Resultant, Parametric... > >
            objective
    ) {
        static auto&
            Invoke = InvokeMethodSafely< ClassTypical, MethodLocational, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( objective ).at};
        return invocation;
    }

}

#endif
