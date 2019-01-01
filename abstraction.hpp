// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ABSTRACTION_MODULE
#define ABSTRACTION_MODULE
#include "location.hpp"

/**
 * @brief   
 *     Procedural invocation facilitation.
 * @details 
 *     Association
 *     -----------
 *     Procedural invocation facilitation.
 */
namespace abstraction {

    using ::location::Locational;
    using ::location::Referential;
    using ::location::Locate;
    using ::location::Refer;

    /**
     * @brief 
     *     Function type which represents a procedural abstract.
     * @details 
     *     Abstraction Template
     *     --------------------
     *     Function type alias used to represent a procedural abstract.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        typename Resultant,
        typename ...Parametric
    >
    using Abstract = Resultant( Parametric... );

    /**
     * @brief         
     *     Procedural invocation classifier.
     * @details       
     *     Classification Template
     *     -----------------------
     *     This type is used to represent any instance of the specified 
     *     procedural invocation.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        typename Resultant,
        typename ...Parametric
    >
    struct Invocative {

        Locational< Abstract< Resultant, const Locational< const void >, Parametric... > >
            interface;

        Locational< const void >
            objective;

        Resultant
        operator()( 
            Parametric... 
                arguments 
        ) const {
            return interface( objective, arguments... );
        }

    };

    /**
     * @brief         
     *     Object oriented instance method classifier.
     * @details       
     *     Classification Template
     *     -----------------------
     *     This type is used to represent a method invocation relative to an 
     *     object pursuant to the specified procedural invocation.
     * @tparam ClassTypical
     *     Object oriented class type.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        class ClassTypical,
        typename Resultant,
        typename ...Parametric
    >
    struct Methodic {

        Abstract< Resultant, Parametric... > ClassTypical::* 
            method;

        Locational< ClassTypical >
            object;

    };

    /**
     * @brief 
     *     Invokes the procedural instance.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes the procedural instance, specific to the procedural type.
     * @tparam Procedural
     *     Procedural (function, lambda or functor) type.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        typename Procedural,
        typename Resultant,
        typename ...Parametric
    >
    static inline Resultant
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
     *     Invokes the procedural instance safely.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes the procedural instance, specific to the procedural type.
     * @tparam Procedural
     *     Procedural (function, lambda or functor) type.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        typename Procedural,
        typename Resultant,
        typename ...Parametric
    >
    static inline Resultant
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
     *     Invokes an object oriented instance method.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes an object oriented instance method, specific to the procedural type.
     * @tparam ClassTypical
     *     Object oriented class type.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        class ClassTypical,
        typename Resultant,
        typename ...Parametric
    >
    static inline Resultant
    InvokeMethod(
        const Locational< const void >
            locality,
        Parametric...
            arguments
    ) {
        using Specific = const Locational< const Methodic< ClassTypical, Resultant, Parametric... > >;
        Specific
            objective = static_cast< Specific >(locality);
        return (objective->object->*objective->method)( arguments... );
    }

    /**
     * @brief 
     *     Invokes an object oriented instance method safely.
     * @details
     *     Function Template
     *     -----------------
     *     Invokes an object oriented instance method, specific to the procedural type.
     *     Throws an exception if objective or either of its members method or object are
     *     null.
     * @tparam ClassTypical
     *     Object oriented class type.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        class ClassTypical,
        typename Resultant,
        typename ...Parametric
    >
    static inline Resultant
    InvokeMethodSafely(
        const Locational< const void >
            locality,
        Parametric...
            arguments
    ) {
        using Specific = const Locational< const Methodic< ClassTypical, Resultant, Parametric... > >;
        static auto&
            Invoke = InvokeMethod< ClassTypical, Resultant, Parametric... >;
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
     *     Prepares a lambda expression which invokes a procedural call.
     * @details
     *     Function Template
     *     -----------------
     *     Prepares a lambda expression which can be used to invoke a specified 
     *     procedural call.  The invocation instance is captured by copy when 
     *     being prepared to be called as a lambda expression.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
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
     *     Prepares a lambda expression which can be used to invoke a specified 
     *     procedural call.  The invocation instance is captured by copy when 
     *     being prepared to be called as a lambda expression.  If either of the
     *     interface or objective of the invocation are null, an exception is 
     *     thrown.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
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
     *     Assigns an instance method objective.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an objective containing the pointers required to invoke an 
     *     object oriented instance method.
     * @tparam ClassTypical
     *     Object oriented class type.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        class ClassTypical,
        typename Resultant,
        typename ...Parametric
    >
    static inline Methodic< ClassTypical, Resultant, Parametric... >
    AssignMethodObjective(
        Abstract< Resultant, Parametric... > ClassTypical::* const 
            method,
        Referential< ClassTypical >
            object
    ) {
        const Methodic< ClassTypical, Resultant, Parametric... >
            objective = {method, Locate( object ).at};
        return objective;
    }

    /**
     * @brief 
     *     Assigns an instance method objective safely.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an objective containing the pointers required to invoke an 
     *     object oriented instance method.  Throws an exception if method is
     *     null.
     * @tparam ClassTypical
     *     Object oriented class type.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        class ClassTypical,
        typename Resultant,
        typename ...Parametric
    >
    static inline Methodic< ClassTypical, Resultant, Parametric... >
    AssignMethodObjectiveSafely(
        Abstract< Resultant, Parametric... > ClassTypical::* const 
            method,
        Referential< ClassTypical >
            object
    ) {
        if (!method)
            throw method;
        const Methodic< ClassTypical, Resultant, Parametric... >
            objective = {method, Locate( object ).at};
        return objective;
    }

    /**
     * @brief 
     *     Assigns a procedural invocation instance.
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
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
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
     *     Assigns a safe procedural invocation instance.
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
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
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
     *     Assigns a methodic invocation instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     method specified by objective.  The objective argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.
     * @tparam ClassTypical
     *     Object oriented class type.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        class ClassTypical,
        typename Resultant,
        typename ...Parametric
    >
    static inline Invocative< Resultant, Parametric... >
    AssignInvokeMethod(
        Referential< const Methodic< ClassTypical, Resultant, Parametric... > >
            objective
    ) {
        static auto&
            Invoke = InvokeMethod< ClassTypical, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( objective ).at};
        return invocation;
    }

    /**
     * @brief 
     *     Assigns a safe methodic invocation instance.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns an invocative instance which can later be used to invoke the 
     *     method specified by objective.  The objective argument specifier
     *     must have sufficient duration such that it exists when the invocation
     *     occurs.  The resulting interface function will throw an exception if 
     *     its provided pointers are null.
     * @tparam ClassTypical
     *     Object oriented class type.
     * @tparam Resultant
     *     Return type of the procedural invocation.
     * @tparam ...Parametric
     *     Parameter pack which represents the procedural parameters.
     */
    template <
        class ClassTypical,
        typename Resultant,
        typename ...Parametric
    >
    static inline Invocative< Resultant, Parametric... >
    AssignInvokeMethodSafely(
        Referential< const Methodic< ClassTypical, Resultant, Parametric... > >
            objective
    ) {
        static auto&
            Invoke = InvokeMethodSafely< ClassTypical, Resultant, Parametric... >;
        const Invocative< Resultant, Parametric... >
            invocation = {Locate( Invoke ).at, Locate( objective ).at};
        return invocation;
    }

}

#endif
