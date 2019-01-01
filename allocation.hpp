// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ALLOCATION_MODULE
#define ALLOCATION_MODULE
#include "location.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

/**
 * @brief         
 *     Memory allocation and operator based implementations.
 * @details       
 *     Association
 *     -----------
 *     An opaque memory allocation classifier template is provided in order to
 *     unify the naming convention of function references used to allocate and 
 *     free memory spaces for the various allocation schemes.  The default, 
 *     array and copy allocation schemes are provided for default and array 
 *     default initialization as well as copy initialization of allocated memory
 *     spaces.  Finally functions and objectives are provided which make use of 
 *     the new and delete operators invoking the default constructors and copy 
 *     constructors.
 */
namespace allocation {

    using ::location::Referential;
    using ::location::Locational;

    /**
     * @brief         
     *     Opaque memory allocation classifier.
     * @details       
     *     Classification Template
     *     -----------------------
     *     This type is used to unify the naming convention of the function 
     *     references used to allocate and free memory for specific memory 
     *     allocation schemes.
     * @tparam Claimable
     *     Function type used to specify the claim abstract.
     * @tparam Disclaimable 
     *     Function type used to specify the disclaim abstract.
     */
    template <
        typename Claimable,
        typename Disclaimable
    >
    struct Allocative {

#ifndef RAPBTL_NO_STD_CPLUSPLUS
        static_assert(
            ::std::is_function< Claimable >::value,
            "Claimable:  Function type required"
        );
        static_assert(
            ::std::is_function< Disclaimable >::value,
            "Disclaimable:  Function type required"
        );
#endif

        Referential< Claimable >
            claim;  /**< Function reference used to allocate memory. */

        Referential< Disclaimable >
            disclaim; /**< Function reference used to free memory. */

    };

    /**
     * @brief         
     *     Claim default abstract.
     * @details       
     *     Abstraction Template
     *     --------------------
     *     Function type alias used when the claim function does not require any
     *     additional arguments.
     * @tparam Subjective
     *     Type of the data object.
     */
    template <
        typename Subjective
    >
    using DefaultClaimable = const Locational< Subjective >(
        Referential< Locational< Subjective > >
            locality
    );

    /**
     * @brief
     *     Disclaim default abstract.
     * @details       
     *     Abstraction Template
     *     --------------------
     *     Function type alias used when the disclaim function does not require
     *     any additional arguments.
     * @tparam Subjective
     *     Type of the data object.
     */
    template <
        typename Subjective
    >
    using DefaultDisclaimable = void(
        Referential< Locational< Subjective > >
            locality
    );

    /**
     * @brief
     *     Claim array abstract.
     * @details
     *     Abstraction Template
     *     --------------------
     *     Function type alias used when the claim function requires an 
     *     additional count argument.
     * @tparam Subjective 
     *     Type of the array element.
     */
    template <
        typename Natural,
        typename Subjective
    >
    using ArrayClaimable = const Locational< Subjective >(
        Referential< Locational< Subjective > >
            locality,
        Referential< const Natural >
            count
    );

    /**
     * @brief
     *     Claim copy abstract.
     * @details
     *     Abstraction Template
     *     --------------------
     *     Function type alias used when the claim function requires an 
     *     additional value argument.
     * @tparam Subjective 
     *     Type of the data object.
     */
    template <
        typename Subjective
    >
    using CopyClaimable = const Locational< Subjective >(
        Referential< Locational< Subjective > >
            locality,
        Referential< const Subjective >
            value 
    );

    /**
     * @brief
     *     Default memory allocation classifier.
     * @details
     *     Classification Template
     *     -----------------------
     *     This type alias defines the default memory allocation classifier.
     * @tparam Subjective 
     *     Type of the data object.
     */
    template <
        typename Subjective
    >
    using DefaultAllocative = Allocative< DefaultClaimable< Subjective >, DefaultDisclaimable< Subjective > >;

    /**
     * @brief
     *     Array memory allocation classifier.
     * @details       
     *     Classification Template
     *     -----------------------
     *     This type alias defines the array memory allocation classifier.
     * @tparam Subjective 
     *     Type of the array element.
     */
    template <
        typename Natural,
        typename Subjective
    >
    using ArrayAllocative = Allocative< ArrayClaimable< Natural, Subjective >, DefaultDisclaimable< Subjective > >;

    /**
     * @brief
     *     Copy memory allocation classifier.
     * @details
     *     Classification Template
     *     -----------------------
     *     This type alias defines the copy memory allocation classifier.
     * @tparam Subjective
     *     Type of the data object.
     */
    template <
        typename Subjective
    >
    using CopyAllocative = Allocative< CopyClaimable< Subjective >, DefaultDisclaimable< Subjective > >;

    /**
     * @brief
     *     Allocates memory space for an instance of the specified 
     *     type using the new operator.
     * @details
     *     Function Template
     *     -----------------
     *     With this function, the default constructor will be invoked.
     * @tparam Subjective   
     *     Type of the data object.
     * @param[out] locality     
     *     Reference to a pointer which will receive the address of the data 
     *     object.
     * @return        
     *     The same address as stored in the pointer which was bound to 
     *     locality.
     */
    template <
        typename Subjective
    >
    static inline const Locational< Subjective >
    AllocateNewElement(
        Referential< Locational< Subjective > >
            locality
    ) {
        return locality = new Subjective;
    }

    /**
     * @brief
     *     Allocates memory space for an array of instances of the specified 
     *     type using the new operator.
     * @details
     *     Function Template
     *     -----------------
     *     With this function, the default constructor(s) will be invoked.
     * @tparam Subjective
     *     Type of the array element.
     * @param[out] locality
     *     Reference to a pointer which will receive the address of the array of
     *     data objects.
     * @param[in] count
     *     The number of objects in the array.
     * @return        
     *     The same address as stored in the pointer which was bound to 
     *     locality.
     */
    template <
        typename Natural,
        typename Subjective
    >
    static inline const Locational< Subjective >
    AllocateNewArray(
        Referential< Locational< Subjective > >
            locality,
        Referential< const Natural >
            count
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return locality = new Subjective[count];
    }

    /**
     * @brief
     *     Allocates memory space for an instance of the specified type using 
     *     the new operator.
     * @details
     *     Function Template
     *     -----------------
     *     With this function, the copy constructor will be invoked.
     * @tparam Subjective 
     *     Type of the data object.
     * @param[out] locality
     *     Reference to a pointer which will receive the address of the data 
     *     object.
     * @param[in] subject
     *     The value to be passed to the copy constructor.
     * @return        
     *     The same address as stored in the pointer which was bound to 
     *     locality.
     */
    template <
        typename Subjective
    >
    static inline const Locational< Subjective >
    AllocateNewCopy(
        Referential< Locational< Subjective > >
            locality,
        Referential< const Subjective >
            subject
    ) {
        return locality = new Subjective( subject );
    }

    /**
     * @brief
     *     Sets the pointer to null (does not free the memory space).
     * @details
     *     Function Template
     *     -----------------
     *     This function can be useful in pseudo-allocation.
     * @tparam Subjective 
     *     Type of the data object.
     * @param[out] locality
     *     Reference to a pointer which will be set to null.
     * @return
     *     Does not return any value.
     */
    template <
        typename Subjective
    >
    static inline void
    SetToNull(
        Referential< Locational< Subjective > >
            locality
    ) {
        locality = 0;
    }

    /**
     * @brief
     *     Frees the memory space of an instance of the specified type using the
     *     delete operator.
     * @details
     *     Function Template
     *     -----------------
     *     With this function, the destructor will be invoked but the pointer 
     *     will not be set to null.
     * @tparam Subjective 
     *     Type of the data object.
     * @param[in] locality
     *     Reference to a pointer containing the address which will be deleted.
     * @return
     *     Does not return any value.
     */
    template <
        typename Subjective
    >
    static inline void
    DeleteElement(
        Referential< Locational< Subjective > >
            locality
    ) {
        delete locality;
    }

    /**
     * @brief
     *     Frees the memory space of an instance of the specified type using 
     *     the delete operator and sets the pointer to null.
     * @details
     *     Function Template
     *     -----------------
     *     With this function, the destructor will be invoked and the pointer 
     *     will be set to null.
     * @tparam Subjective 
     *     Type of the data object.
     * @param[in,out] locality
     *     Reference to a pointer containing the address which will be deleted.
     * @return
     *     Does not return any value.
     */
    template <
        typename Subjective
    >
    static inline void
    DeleteElementAndSetToNull(
        Referential< Locational< Subjective > >
            locality
    ) {
        DeleteElement( locality );
        SetToNull( locality );
    }

    /**
     * @brief
     *     Frees the memory space of an array of the specified type using the 
     *     delete array operator.
     * @details
     *     Function Template
     *     ----------------
     *     With this function, the destructor(s) will be invoked but the pointer
     *     will not be set to null.
     * @tparam Subjective 
     *     Type of the array element.
     * @param[in] locality 
     *     Reference to a pointer containing the array address which will be
     *     deleted.
     * @return
     *     Does not return any value.
     */
    template <
        typename Subjective
    >
    static inline void
    DeleteArray(
        Referential< Locational< Subjective > >
            locality
    ) {
        delete []locality;
    }

    /**
     * @brief
     *     Frees the memory space of an array of the specified type using the
     *     delete array operator and sets the pointer to null.
     * @details
     *     Function Template
     *     -----------------
     *     With this function, the destructor(s) will be invoked and the 
     *     pointer will be set to null.
     * @tparam Subjective 
     *     Type of the array element.
     * @param[in,out] locality
     *     Reference to a pointer containing the array address which will be 
     *     deleted.
     * @return
     *     Does not return any value.
     */
    template <
        typename Subjective
    >
    static inline void
    DeleteArrayAndSetToNull(
        Referential< Locational< Subjective > >
            locality
    ) {
        DeleteArray( locality );
        SetToNull( locality );
    }

    /**
     * @brief
     *     Default new/delete memory allocation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which uses the default new and delete operators.
     *     Disclaim frees the memory space and then sets the pointer to null.
     * @tparam Subjective 
     *     Type of the data objects.
     */
    template <
        typename Subjective
    >
    constexpr DefaultAllocative< Subjective >
        DefaultNew = {
            AllocateNewElement< Subjective >, 
            DeleteElementAndSetToNull< Subjective >
        };

    /**
     * @brief
     *     Default new/delete memory allocation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which uses the default new and delete operators.  
     *     Disclaim frees the memory space but does not set the pointer to null.
     * @tparam Subjective 
     *     Type of the data objects.
     */
    template <
        typename Subjective
    >
    constexpr DefaultAllocative< Subjective >
        FastDefaultNew = {
            AllocateNewElement< Subjective >, 
            DeleteElement< Subjective >
        };

    /**
     * @brief
     *     Array new/delete memory allocation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which uses the array new and array delete operators.  
     *     Disclaim frees the memory space and then sets the pointer to null.
     * @tparam Subjective 
     *     Type of the array elements.
     */
    template <
        typename Natural,
        typename Subjective
    >
    constexpr ArrayAllocative< Natural, Subjective >
        ArrayNew = {
            AllocateNewArray< Natural, Subjective >, 
            DeleteArrayAndSetToNull< Subjective >
        };

    /**
     * @brief
     *     Array new/delete memory allocation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which uses the array new and array delete operators.
     *     Disclaim frees the memory space but does not set the pointer to null.
     * @tparam Subjective 
     *     Type of the array elements.
     */
    template <
        typename Natural,
        typename Subjective
    >
    constexpr ArrayAllocative< Natural, Subjective >
        FastArrayNew = {
            AllocateNewArray< Natural, Subjective >, 
            DeleteArray< Subjective >
        };

    /**
     * @brief
     *     Copy new/delete memory allocation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which uses the copy new and delete operators.  
     *     Disclaim frees the memory space and then sets the pointer to null.
     * @tparam Subjective
     *     Type of the data objects.
     */
    template <
        typename Subjective
    >
    constexpr CopyAllocative< Subjective >
        CopyNew = {
            AllocateNewCopy< Subjective >, 
            DeleteElementAndSetToNull< Subjective >
        };

    /**
     * @brief
     *     Copy new/delete memory allocation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which uses the copy new and delete operators.  
     *     Disclaim frees the memory space but does not set the pointer to null.
     * @tparam Subjective
     *     Type of the data objects.
     */
    template <
        typename Subjective
    >
    constexpr CopyAllocative< Subjective >
        FastCopyNew = {
            AllocateNewCopy< Subjective >, 
            DeleteElement< Subjective >
        };

}

#endif
