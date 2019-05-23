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
 *     Invocation of any object with or without linkage.
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
            location; /**< Data pointer to the invocable object location. */

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
            return interface( location, arguments... );
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
     *     Invokes the procedural object.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes either a function, lambda or functor.
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
            location = static_cast< Specific >(locality);
        return Refer( Refer( location ).to ).to( arguments... );
    }

    /**
     * @brief 
     *     Invokes the procedural object safely.
     * @details
     *     Function Template
     *     -----------------
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
            location = static_cast< Specific >(locality);
        if (!location)
            throw location;
        if (!Refer( location ).to)
            throw Refer( location ).to;
        return Invoke( location, arguments ... );
    }

    /**
     * @brief 
     *     Invokes an object oriented non-static method.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes an object oriented non-static method.
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
            instance = static_cast< Specific >(locality);
        return (instance->object->*instance->method)( arguments... );
    }

    /**
     * @brief 
     *     Invokes an object oriented non-static method safely.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes an object oriented non-static method. Throws an exception if
     *     location itself is null or either of its members, method or object 
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
            instance = static_cast< Specific >(locality);
        if (!instance)
            throw instance;
        if (!instance->method)
            throw instance->method;
        if (!instance->object)
            throw instance->object;
        return Invoke( instance, arguments ... );
    }

   /**
     * @brief 
     *     Prepares a lambda expression which can later invoke the invocation.
     * @details
     *     Function Template
     *     -----------------
     *     Prepares a lambda expression which can later be used to invoke any
     *     invocation.  The invocative instance is captured by copy when 
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
                return invocation.interface( invocation.location, arguments... );
            };
        return lambda;
    }

   /**
     * @brief 
     *     Prepares a lambda expression which can safely invoke the invocation.
     * @details
     *     Function Template
     *     -----------------
     *     Prepares a lambda expression which can later be used to invoke any
     *     invocation.  The invocative instance is captured by copy when 
     *     PrepareInvocation is called.  Throws an exception immediately if 
     *     either of the interface or location members of the invocative 
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
        if (!invocation.location)
            throw invocation.location;
        return PrepareInvocation( invocation );
    }

    /**
     * @brief 
     *     Assigns a non-static method instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns a method and object to a methodic instance, which can be 
     *     assigned to an invocative instance.
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
     *     Methodic instance returned by value.
     */
    template <
        class ClassTypical,
        typename MethodLocational,
        typename Resultant,
        typename ...Parametric
    >
    static inline Methodic< ClassTypical, MethodLocational, Resultant, Parametric... >
    AssignClassMethod(
        MethodLocational
            method, 
        Referential< ClassTypical >
            object
    ) {
        const Methodic< ClassTypical, MethodLocational, Resultant, Parametric... >
            location = {method, Locate( object ).at};
        return location;
    }

    /**
     * @brief 
     *     Assigns a non-static method safely.
     * @details
     *     Function Template
     *     -----------------
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
     *     Methodic instance returned by value.
     */
    template <
        class ClassTypical,
        typename MethodLocational,
        typename Resultant,
        typename ...Parametric
    >
    static inline Methodic< ClassTypical, MethodLocational, Resultant, Parametric... >
    AssignClassMethodSafely(
        MethodLocational
            method, 
        Referential< ClassTypical >
            object 
    ) {
        if (!method)
            throw method;
        const Methodic< ClassTypical, MethodLocational, Resultant, Parametric... >
            location = {method, Locate( object ).at};
        return location;
    }

    /**
     * @brief 
     *     Assigns a procedural invocative instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     procedure specified by location.  The location argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.
     * @tparam Procedural
     *     Procedural (function, lambda or functor) type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] location
     *     Reference to a pointer with suitable duration.
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
            location
    ) {
        static_assert(
            sizeof Locate( location ).at == sizeof(Locational< const void >),
            "location: Pointer to pointer should be a data type"
        );
        static auto&
            Invoke = InvokeProcedure< Procedural, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( location ).at};
        return invocation;
    }

    /**
     * @brief 
     *     Assigns a safe procedural invocative instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     procedure specified by location.  The location argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.  If the location provided is null, this version will throw 
     *     the location argument.  The resulting interface function will throw
     *     an exception if its provided pointers are null.
     * @tparam Procedural
     *     Procedural (function, lambda or functor) type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] location
     *     Reference to a pointer with suitable duration.
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
            location
    ) {
        static_assert(
            sizeof Locate( location ).at == sizeof(Locational< const void >),
            "location: Pointer to pointer should be a data type"
        );
        static auto&
            Invoke = InvokeProcedureSafely< Procedural, Resultant, Parametric... >;
        if (!location)
            throw location;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( location ).at};
        return invocation;
    }

    /**
     * @brief 
     *     Assigns a methodic invocative instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke a 
     *     specific method against an object both specified by the instance 
     *     argument.  The instance argument specifier must have sufficient 
     *     duration such that it exists when the invocation occurs.
     * @tparam ClassTypical
     *     Qualified object oriented class type.
     * @tparam MethodLocational
     *     Pointer to qualified member function type.
     * @tparam Resultant
     *     Return type of the invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the parameter types of the invocation.
     * @param[in] instance
     *     Reference to a methodic instance with suitable duration.
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
            instance
    ) {
        static auto&
            Invoke = InvokeMethod< ClassTypical, MethodLocational, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( instance ).at};
        return invocation;
    }

    /**
     * @brief 
     *     Assigns a safe methodic invocative instance.
     * @details
     *     Function Template
     *     -----------------
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
     * @param[in] instance
     *     Reference to a methodic instance with suitable duration.
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
            instance
    ) {
        static auto&
            Invoke = InvokeMethodSafely< ClassTypical, MethodLocational, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( instance ).at};
        return invocation;
    }

}

#endif
