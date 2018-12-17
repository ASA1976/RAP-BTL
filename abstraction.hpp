// © 2018 Aaron Sami Abassi
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
    using Abstract = Resultant( Parametric... arguments );

    /**
     * @brief         
     *     Procedural invocation interface classifier.
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

        const Locational< Abstract< Resultant, const Locational< const void >, Parametric... > >
            interface;

        const Locational< const void >
            objective;

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
    static Resultant
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
     *     Creates an invocation instance.
     * @details
     *     Function Template
     *     -----------------
     *     Creates an invocative instance which can later be used to invoke the 
     *     procedure specified by objective.
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
    CreateInvocation(
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
     *     Creates an invocation instance safely.
     * @details
     *     Function Template
     *     -----------------
     *     Creates an invocative instance which can later be used to invoke the 
     *     procedure specified by objective.  If the location provided is null, 
     *     this version will throw the objective argument.
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
    CreateInvocationSafely(
        Referential< const Locational< Procedural > >
            objective
    ) {
        static auto&
            Create = CreateInvocation< Procedural, Resultant, Parametric... >;
        if (!objective)
            throw objective;
        return Create( objective );
    }

}

#endif
