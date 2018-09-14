// © 2018 Aaron Sami Abassi
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
#include <stdlib.h>
#endif
#else
// Requires _aligned_malloc From MSC CRT
#include <malloc.h>
#endif

namespace allocation {

    namespace alignment {

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
