// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ALLOCATION_STDLIB_MODULE
#define ALLOCATION_STDLIB_MODULE
#include "../allocation.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdlib>
#else
#include <stdlib.h>
#endif

namespace allocation {

    /**
     * @brief
     *     Memory allocation implementations using one of either the C or C++
     *    standard library functions.
     * @details 
     *     Association
     *     -----------
     *     C or C++ standard library based functions and objectives of the
     *     default and array memory allocation classifiers.
     */
    namespace stdlib {

        /**
         * @brief
         *     Allocates memory space for an array of instances of the specified
         *     type using a standard library malloc function.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, no constructor is invoked.
         * @tparam Subjective
         *     Type of the data object to be allocated.
         * @param[out] locality 
         *     Reference to a pointer which will receive the address of the 
         *     allocated array of data objects.
         * @param[in] count 
         *     The number of objects to be allocated.
         * @return 
         *     The same address as stored in the pointer which was bound to 
         *     locality.
         */
        template <
            typename Subjective
        >
        static inline const Locational< Subjective >
        AllocateArrayUsingMalloc(
            Referential< Locational< Subjective > >
                locality,
            Referential< const size_t >
                count
        ) {
            return locality = static_cast< Locational< Subjective > >(malloc( sizeof(Subjective) * count ));
        }

        /**
         * @brief
         *     Allocates memory space for an instance of the specified type 
         *     using a standard library malloc function.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, no constructor is invoked.
         * @tparam Subjective 
         *     Type of the data object to be allocated.
         * @param[out] locality
         *     Reference to a pointer which will receive the address of the 
         *     allocated data object.
         * @return
         *     The same address as stored in the pointer which was bound to 
         *     locality.
         */
        template <
            typename Subjective
        >
        static inline const Locational< Subjective >
        AllocateElementUsingMalloc(
            Referential< Locational< Subjective > >
                locality
        ) {
            return AllocateArrayUsingMalloc( locality, 1 );
        }

        /**
         * @brief
         *     Allocates memory space for an array of instances of the specified
         *     type using a standard library calloc function.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, the allocated memory space is initialized to
         *     zeros and no constructor is invoked.
         * @tparam Subjective
         *     Type of the data object to be allocated.
         * @param[out] locality
         *     Reference to a pointer which will receive the address of the
         *     allocated array of data objects.
         * @param[in] count 
         *     The number of objects to be allocated.
         * @return
         *     The same address as stored in the pointer which was bound to
         *     locality.
         */
        template <
            typename Subjective
        >
        static inline const Locational< Subjective >
        AllocateArrayUsingCalloc(
            Referential< Locational< Subjective > >
                locality,
            Referential< const size_t >
                count
        ) {
            return locality = static_cast< Locational< Subjective > >(calloc( count, sizeof(Subjective) ));
        }

        /**
         * @brief
         *     Allocates memory space for an instance of the specified type 
         *     using a standard library calloc function.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, the allocated memory space is initialized to
         *     zeros and no constructor is invoked.
         * @tparam Subjective
         *     Type of the data object to be allocated.
         * @param[out] locality
         *     Reference to a pointer which will receive the address of the 
         *     allocated data object.
         * @return
         *     The same address as stored in the pointer which was bound to 
         *     locality.
         */
        template <
            typename Subjective
        >
        static inline const Locational< Subjective >
        AllocateElementUsingCalloc(
            Referential< Locational< Subjective > >
                locality
        ) {
            return AllocateArrayUsingCalloc( locality, 1 );
        }

        /**
         * @brief
         *     Frees the memory space of an instance of the specified type using
         *     a standard library free function.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, memory is freed using a standard library free
         *     function, no destructor is invoked and the pointer will not be 
         *     set to null.
         * @tparam Subjective
         *     Type of the data object to be freed.
         * @param[in] locality
         *     Reference to a pointer containing the address which will be 
         *     freed.
         * @return
         *     Does not return any value.
         */
        template <
            typename Subjective
        >
        static inline void
        DeleteUsingFree(
            Referential< Locational< Subjective > >
                locality
        ) {
            free( locality );
        }

        /**
         * @brief
         *     Frees the memory space of an instance of the specified type using
         *     a standard library free function.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, memory is freed using a standard library free
         *     function, no destructor is invoked and the pointer is set to 
         *     null.
         * @tparam Subjective
         *     Type of the data object to be freed.
         * @param[in,out] locality
         *     Reference to a pointer containing the address which will be 
         *     freed.
         * @return
         *     Does not return any value.
         */
        template <
            typename Subjective
        >
        static inline void
        DeleteUsingFreeAndSetToNull(
            Referential< Locational< Subjective > >
                locality
        ) {
            DeleteUsingFree( locality );
            SetToNull( locality );
        }

        /**
         * @brief
         *     Default malloc/free memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective which uses the malloc and free functions.  Disclaim 
         *     frees the memory space and then sets the pointer to null.
         * @tparam Subjective
         *     Type of the data objects.
         */
        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        DefaultMalloc = {
            AllocateElementUsingMalloc< Subjective >, 
            DeleteUsingFreeAndSetToNull< Subjective >
        };

        /**
         * @brief
         *     Default malloc memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective which uses malloc and free.  Disclaim frees the memory
         *     space but does not set the pointer to null.
         * @tparam Subjective 
         *     Type of the data objects.
         */
        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        FastDefaultMalloc = {
            AllocateElementUsingMalloc< Subjective >, 
            DeleteUsingFree< Subjective >
        };

        /**
         * @brief
         *     Array malloc memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective which uses malloc and free.  Disclaim frees the memory
         *     space and then sets the pointer to null.
         * @tparam Subjective
         *     Type of the data objects.
         */
        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        ArrayMalloc = {
            AllocateArrayUsingMalloc< Subjective >, 
            DeleteUsingFreeAndSetToNull< Subjective >
        };

        /**
         * @brief
         *     Array malloc memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective which uses malloc and free.  Disclaim frees the memory
         *     space but does not set the pointer to null.
         * @tparam Subjective 
         *     Type of the data objects.
         */
        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        FastArrayMalloc = {
            AllocateArrayUsingMalloc< Subjective >, 
            DeleteUsingFree< Subjective >
        };

        /**
         * @brief
         *     Default calloc memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective which uses calloc and free.  Disclaim frees the memory
         *     space and then sets the pointer to null.
         * @tparam Subjective
         *     Type of the data objects.
         */
        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        DefaultCalloc = {
            AllocateElementUsingCalloc< Subjective >, 
            DeleteUsingFreeAndSetToNull< Subjective >
        };

        /**
         * @brief
         *     Default calloc memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective which uses calloc and free.  Disclaim frees the memory
         *     space but does not set the pointer to null.
         * @tparam Subjective
         *     Type of the data objects.
         */
        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        FastDefaultCalloc = {
            AllocateElementUsingCalloc< Subjective >, 
            DeleteUsingFree< Subjective >
        };

        /**
         * @brief
         *     Array calloc memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective which uses calloc and free.  Disclaim frees the memory
         *     space and then sets the pointer to null.
         * @tparam Subjective 
         *     Type of the data objects.
         */
        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        ArrayCalloc = {
            AllocateArrayUsingCalloc< Subjective >, 
            DeleteUsingFreeAndSetToNull< Subjective >
        };

        /**
         * @brief
         *     Array calloc memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective which uses calloc and free.  Disclaim frees the memory
         *     space but does not set the pointer to null.
         * @tparam Subjective
         *     Type of the data objects.
         */
        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        FastArrayCalloc = {
            AllocateArrayUsingCalloc< Subjective >, 
            DeleteUsingFree< Subjective >
        };

    }

}

#endif
