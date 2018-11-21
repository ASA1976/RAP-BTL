// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef LOCATION_MODULE
#define LOCATION_MODULE

/**
 * @brief
 *     Object location, referencing and operator based implementations.
 * @details 
 *     Association
 *     -----------
 *     Memory location and referencing conformities and functions are provided
 *     for pointer, Lvalue reference and Rvalue references which make source 
 *     code read more like literary language.     
 *
 *     __Note carefully__ that use of the __functions__ in this namespace can 
 *     __severely hinder__ run-time performance if compiler optimization is not 
 *     available for any reason.
 */
namespace location {

    /**
     * @brief
     *     Memory pointer conformity.
     * @details
     *     Situation Template
     *     ------------------
     *     Type alias which represents a pointer type.  Increases the legibility
     *     of function pointer parameter declarations, where type and identifier
     *     both appear.
     * @tparam Subjective
     *     Type of the object.
     */
    template <
        typename Subjective
    >
    using Locational = Subjective*;

    /**
     * @brief
     *     Lvalue reference conformity.
     * @details 
     *     Situation Template
     *     ------------------
     *     Type alias which represents an Lvalue reference type.  Increases the
     *     legibility of array and function reference parameter declarations, 
     *     where type and identifier both appear.
     * @tparam Subjective 
     *     Type of the object.
     */
    template <
        typename Subjective
    >
    using Referential = Subjective&;

    /**
     * @brief
     *     Rvalue reference conformity.
     * @details
     *     Situation Template
     *     ------------------
     *     Type alias which represents an Rvalue reference type.  Increases the 
     *     legibility of array reference parameter declarations.
     * @tparam Subjective 
     *     Type of the object.
     */
    template <
        typename Subjective
    >
    using Deferential = Subjective&&;

    /**
     * @brief
     *     Memory pointer posit conformity.
     * @details 
     *     Conformation Template
     *     ---------------------
     *     Type definition which contains a single member pointer.  Useful when 
     *     possibly returning a function pointer from a function, syntactically 
     *     preventing directly chained function invocations.
     * @tparam Subjective
     *     Type of the object.
     */
    template <
        typename Subjective
    >
    struct Positive {

        Locational< Subjective >
            at; /**< Pointer to the subject. */

    };

    /**
     * @brief
     *     Lvalue reference conferment conformity.
     * @details 
     *     Conformation Template
     *     ---------------------
     *     Type definition which contains a single member Lvalue reference.  
     *     Useful when possibly returning a function reference from a function,
     *     syntactically preventing directly chained function invocations.
     * @tparam Subjective
     *     Type of the object.
     */
    template <
        typename Subjective
    >
    struct Conferential {

        Referential< Subjective >
            to; /**< Lvalue reference to the subject. */

    };

    /**
     * @brief
     *     Rvalue reference deferment conformity.
     * @details 
     *     Conformation Template
     *     ---------------------
     *     Type definition which contains a single member Rvalue reference.
     *     Syntactically used to enforce explicitly addressing the Rvalue 
     *     reference.
     * @tparam Subjective
     *     Type of the object.
     */
    template <
        typename Subjective
    >
    struct Deferent {

        Deferential< Subjective >
            to; /**< Rvalue reference to the subject. */

    };

    /**
     * @brief
     *     Locates the memory address of a subject as a posit.
     * @details
     *     Function Template
     *     -----------------
     *     Useful when writing functions templates which may return function
     *     pointers, syntactically preventing directly chained function 
     *     invocations.  Also makes order of operations syntactically clearer 
     *     when compared to it's equivalent operator syntax. 
     *
     *     __Note carefully__ that use of this function can __severely hinder__
     *     run-time performance if compiler optimization is not available for 
     *     any reason.
     * @tparam Subjective
     *     Type of the object.
     * @param[in] subject
     *     Reference to the subject.
     * @return
     *     The address of the subject as a posit.
     */
    template <
        typename Subjective
    >
    static inline Positive< Subjective >
    Locate(
        Referential< Subjective >
            subject
    ) {
        const Positive< Subjective >
            posit = {&subject};
        return posit;
    }

    /**
     * @brief
     *     Confers an Lvalue reference as a conferment.
     * @details
     *     Function Template
     *     -----------------
     *     Useful when writing function templates which may return function
     *     references, syntactically preventing directly chained function 
     *     invocations.
     *
     *     __Note carefully__ that use of this function can __severely hinder__ 
     *     run-time performance if compiler optimization is not available for 
     *     any reason.
     * @tparam Subjective
     *     Type of the object.
     * @param[in] subject
     *     Reference to the subject.
     * @return
     *     The reference to the subject as a conferment.
     */
    template <
        typename Subjective
    >
    static inline Conferential< Subjective >
    Confer(
        Referential< Subjective >
            subject
    ) {
        const Conferential< Subjective >
            conferment = {subject};
        return conferment;
    }

    /**
     * @brief
     *     Defers an Rvalue reference as a deferment. 
     * @details
     *     Function Template
     *     -----------------
     *     Returns the Rvalue reference as a deferment.
     *
     *     __Note carefully__ that use of this function can __severely hinder__
     *     run-time performance if compiler optimization is not available for 
     *     any reason.
     * @tparam Subjective
     *     Type of the object.
     * @param[in] subject
     *     Reference to the subject.
     * @return
     *     The reference to the subject as a deferment.
     */
    template <
        typename Subjective
    >
    static inline Deferent< Subjective >
    Defer(
        Referential< Subjective >
            subject
    ) {
        const Deferent< Subjective >
            deferment = {subject};
        return deferment;
    }

    /**
     * @brief
     *     Deters a reference to constant subject as a deterrent.
     * @details
     *     Function Template
     *     -----------------
     *     Useful when writing function templates which return references to 
     *     constant objects where containing the reference in a data structure 
     *     is desired.
     *
     *     __Note carefully__ that use of this function can __severely hinder__ 
     *     run-time performance if compiler optimization is not available for 
     *     any reason.
     * @tparam Subjective
     *     Type of the object.
     * @param[in] subject
     *     Reference to the subject.
     * @return
     *     The reference to the subject as a deterrent.
     */
    template <
        typename Subjective
    >
    static inline Conferential< const Subjective >
    Deter(
        Referential< Subjective >
            subject
    ) {
		static auto&
			View = Confer< const Subjective >;
        return View( subject );
    }

    /**
     * @brief
     *     Refers to subject provided by location as a conferment.
     * @details
     *     Function Template
     *     -----------------
     *     Makes order of operations syntactically clearer when compared to it's
     *     equivalent operator syntax.
     *
     *     __Note carefully__ that use of this function can __severely hinder__ 
     *     run-time performance if compiler optimization is not available for 
     *     any reason.
     * @tparam Subjective
     *     Type of the object.
     * @param[in] locality
     *     Memory address of the subject.
     * @return
     *     The reference to the subject as a conferment.
     */
    template <
        typename Subjective
    >
    static inline Conferential< Subjective >
    Refer(
        const Locational< Subjective >
            locality
    ) {
        return Confer( *locality );
    }

}

#endif
