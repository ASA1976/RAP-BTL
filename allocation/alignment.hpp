// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ALLOCATION_ALIGNMENT_MODULE
#define ALLOCATION_ALIGNMENT_MODULE
#include "../allocation.hpp"
#ifndef _MSC_VER
#ifndef RAPBTL_NO_STD_CPLUSPLUS
// Requires aligned_alloc From C++17
#include <cstdlib>
#else
// Requires aligned_alloc From C11
extern "C" {
#include <stdlib.h>
}
#endif
#else
// Requires _aligned_malloc From MSC CRT
#include <malloc.h>
#endif

namespace allocation {

    /**
     * @brief   
     *     Aligned memory allocation implementations using one of either the 
     *     C++17, C11 or MSC CRT library functions.
     * @details
     *     Association
     *     -----------
     *     Aligned memory allocation functions and objectives are provided in 
     *     order to use the C++17 standard library, C11 standard library or MSC
     *     CRT library to implement aligned memory allocation.  If MSC is 
     *     detected it is used, otherwise C11 or C++17 are used depending on the
     *     presence of the RAPBTL_NO_STD_CPLUSPLUS macro.
     */
    namespace alignment {

        /**
         * @brief
         *     Allocates memory space for an instance of the specified type at a
         *     specified memory boundary.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, memory is allocated at a memory boundary and
         *     no constructor is invoked.
         * @tparam Subjective
         *     Type of the data object.
         * @tparam Alignment
         *     Byte boundary the allocated memory should be aligned to.
         * @tparam Size
         *     Size of the memory space to be allocated.
         * @param[out] locality
         *     Reference to a pointer which will receive the address of the 
         *     allocated data object.
         * @return
         *     The same address as stored in the pointer which was bound to 
         *     locality.
         */
        template <
            typename Subjective,
            size_t
                Alignment = alignof(Subjective),
            size_t
                Size = sizeof(Subjective)
        >
        static inline const Locational< Subjective >
        AllocateAlignedElement(
            Referential< Locational< Subjective > >
                locality
        ) {
#ifndef _MSC_VER
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
#endif
            return locality = static_cast< Locational< Subjective > >(aligned_alloc( Alignment, Size ));
#else
            return locality = static_cast< Locational< Subjective > >(_aligned_malloc( Size, Alignment ));
#endif
        }

        /**
         * @brief
         *     Allocates memory space for an array of instances of the specified
         *     type at a specified memory boundary.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, memory is allocated at a memory boundary and
         *     no constructor is invoked.
         * @tparam Subjective
         *     Type of the data object to be allocated.
         * @tparam Alignment
         *     Byte boundary the allocated memory should align to.
         * @tparam Size
         *     Size of the memory space to be allocated.
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
            typename Subjective,
            size_t
                Alignment = alignof(Subjective),
            size_t
                Size = sizeof(Subjective)
        >
        static inline const Locational< Subjective >
        AllocateAlignedArray(
            Referential< Locational< Subjective > >
                locality,
            Referential< const size_t >
                count
        ) {
#ifndef _MSC_VER
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
#endif
            return locality = static_cast< Locational< Subjective > >(aligned_alloc( Alignment, count * Size ));
#else
            return locality = static_cast< Locational< Subjective > >(_aligned_malloc( count * Size, Alignment ));
#endif
        }

        /**
         * @brief
         *     Frees the memory space for an aligned instance of the specified 
         *     type.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, the aligned memory space is freed, no 
         *     destructor is invoked and the pointer will not be set to null.
         * @tparam Subjective
         *     Type of the data object.
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
        DeleteAlignedSubject(
            Referential< Locational< Subjective > >
                locality
        ) {
#ifndef _MSC_VER
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            ::std::
#endif
            free( locality );
#else
            _aligned_free( locality );
#endif
        }

        /**
         * @brief
         *     Frees the memory space for an aligned instance of the specified
         *     type.
         * @details
         *     Function Template
         *     -----------------
         *     With this function, the aligned memory space is freed, no 
         *     destructor is invoked and the pointer is set to null.
         * @tparam Subjective
         *     Type of the data object.
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
        DeleteAlignedSubjectAndSetToNull(
            Referential< Locational< Subjective > >
                locality
        ) {
            DeleteAlignedSubject( locality );
            SetToNull( locality );
        }

        /**
         * @brief
         *     Default aligned memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which uses aligned allocate and free functions.
         *     Disclaim frees the aligned memory space and then sets the pointer
         *     to null.
         * @tparam Subjective
         *     Type of the data objects.
         * @tparam Alignment
         *     Byte boundary the allocated memory should align to.
         * @tparam Size
         *     Size of the memory space to be allocated.
         */
        template <
            typename Subjective,
            size_t
                Alignment = alignof(Subjective),
            size_t
                Size = sizeof(Subjective)
        >
        constexpr DefaultAllocative< Subjective >
            DefaultAligned = {
                AllocateAlignedElement< Subjective, Alignment, Size >, 
                DeleteAlignedSubjectAndSetToNull< Subjective >
            };

        /**
         * @brief
         *     Default aligned memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which uses aligned allocate and free functions.
         *     Disclaim frees the aligned memory space but does not set the 
         *     pointer to null.
         * @tparam Subjective
         *     Type of the data objects.
         * @tparam Alignment
         *     Byte boundary the allocated memory should align to.
         * @tparam Size
         *     Size of the memory space to be allocated.
         */
        template <
            typename Subjective,
            size_t
                Alignment = alignof(Subjective),
            size_t
                Size = sizeof(Subjective)
        >
        constexpr DefaultAllocative< Subjective >
            FastDefaultAligned = {
                AllocateAlignedElement< Subjective, Alignment, Size >, 
                DeleteAlignedSubject< Subjective >
            };

        /**
         * @brief
         *     Array aligned memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which allocates uninitialized aligned memory for
         *     an array.  Disclaim frees the aligned memory space and then sets
         *     the pointer to null.
         * @tparam Subjective
         *     Type of the data objects.
         * @tparam Alignment
         *     Byte boundary the allocated memory should align to.
         * @tparam Size 
         *     Size of the memory space to be allocated.
         */
        template <
            typename Subjective,
            size_t
                Alignment = alignof(Subjective),
            size_t
                Size = sizeof(Subjective)
        >
        constexpr ArrayAllocative< Subjective, size_t >
            ArrayAligned = {
                AllocateAlignedArray< Subjective, Alignment, Size >, 
                DeleteAlignedSubjectAndSetToNull< Subjective >
            };

        /**
         * @brief
         *     Array aligned memory allocation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which allocates uninitialized aligned memory for
         *     an array.  Disclaim frees the aligned memory space but does not 
         *     set the pointer to null.
         * @tparam Subjective
         *     Type of the data objects.
         * @tparam Alignment
         *     Byte boundary the allocated memory should align to.
         * @tparam Size
         *     Size of the memory space to be allocated.
         */
        template <
            typename Subjective,
            size_t
                Alignment = alignof(Subjective),
            size_t
                Size = sizeof(Subjective)
        >
        constexpr ArrayAllocative< Subjective, size_t >
            FastArrayAligned = {
                AllocateAlignedArray< Subjective, Alignment, Size >, 
                DeleteAlignedSubject< Subjective >
            };

    }

}

#endif
