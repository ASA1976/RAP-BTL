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
            locality; /**< Data pointer to the invocable object */

        /**
         * @brief 
         *     Allows instances of the Invocative type to be directly invoked.
         * @details
         *     Operator Overload
         *     -----------------
         *     Invokes any kind of stored procedure, specific to the invocation
         *     abstract specified by the template arguments.
         */
        constexpr Resultant
        operator()( 
            Parametric... 
                arguments /**< Argument pack which is expanded for the invocation. */
        ) const {
            return interface( locality, arguments... );
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
        Specific
            procedure = static_cast< Specific >(locality);
        return Refer( Refer( procedure ).to ).to( arguments... );
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
                return invocation.interface( invocation.locality, arguments... );
            };
        return lambda;
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
            instance = {method, Locate( object ).at};
        return instance;
    }

    /**
     * @brief 
     *     Assigns a procedural invocative instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     procedure specified by locality.  The locality argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.
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
        typename ...Parametric
    >
    static inline Invocative< Resultant, Parametric... >
    AssignInvokeProcedure(
        Referential< const Locational< Procedural > >
            locality
    ) {
        static auto&
            Invoke = InvokeProcedure< Procedural, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( locality ).at};
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
     *     Assigns an invocative instance for functions (only) which can deduce
     *     the template arguments.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     function specified by locality.  The locality argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.
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
        typename ...Parametric
    >
    static inline Invocative< Resultant, Parametric... >
    AssignInvokeFunction(
        Referential< const Locational< Abstract< Resultant, Parametric... > > >
            locality
    ) {
        static auto&
            Invoke = InvokeProcedure< Abstract< Resultant, Parametric... >, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( locality ).at};
        return invocation;
    }

}

#endif
