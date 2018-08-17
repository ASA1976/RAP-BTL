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
                Alignment = alignof( Subjective ),
            size_t
                Size = sizeof( Subjective )
        >
        static inline void
        AlignedAlloc(
            Referential< Locational< Subjective > >
                locality
        ) {
#ifndef _MSC_VER
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
#endif
            locality = (Locational< Subjective >) aligned_alloc( Alignment, Size );
#else
            locality = (Locational< Subjective >) _aligned_malloc( Size, Alignment );
#endif
        }

        template <
            typename Subjective,
            size_t
                Alignment = alignof( Subjective ),
            size_t
                Size = sizeof( Subjective )
        >
        static inline void
        AlignedAlloc(
            Referential< Locational< Subjective > >
                locality,
            Referential< const size_t >
                count
        ) {
#ifndef _MSC_VER
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
#endif
            locality = (Locational< Subjective >) aligned_alloc( Alignment, count * Size );
#else
            locality = (Locational< Subjective >) _aligned_malloc( count * Size, Alignment );
#endif
        }

        template <
            typename Subjective
        >
        static inline void
        AlignedFree(
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
        AlignedFreeAndNull(
            Referential< Locational< Subjective > >
                locality
        ) {
            AlignedFree( locality );
            SetNull( locality );
        }

        template <
            typename Subjective,
            size_t
                Alignment = alignof( Subjective ),
            size_t
                Size = sizeof( Subjective )
        >
        constexpr DefaultAllocative< Subjective >
        DefaultAligned = {
            AlignedAlloc< Subjective, Alignment, Size >, 
            AlignedFreeAndNull< Subjective >
        };

        template <
            typename Subjective,
            size_t
                Alignment = alignof( Subjective ),
            size_t
                Size = sizeof( Subjective )
        >
        constexpr DefaultAllocative< Subjective >
        FastDefaultAligned = {
            AlignedAlloc< Subjective, Alignment, Size >, 
            AlignedFree< Subjective >
        };

        template <
            typename Subjective,
            size_t
                Alignment = alignof( Subjective ),
            size_t
                Size = sizeof( Subjective )
        >
        constexpr ArrayAllocative< Subjective, size_t >
        ArrayAligned = {
            AlignedAlloc< Subjective, Alignment, Size >, 
            AlignedFreeAndNull< Subjective >
        };

        template <
            typename Subjective,
            size_t
                Alignment = alignof( Subjective ),
            size_t
                Size = sizeof( Subjective )
        >
        constexpr ArrayAllocative< Subjective, size_t >
        FastArrayAligned = {
            AlignedAlloc< Subjective, Alignment, Size >, 
            AlignedFree< Subjective >
        };

    }

}

#endif
