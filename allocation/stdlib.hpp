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

    namespace stdlib {

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

        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        DefaultMalloc = {
            AllocateElementUsingMalloc< Subjective >, 
            DeleteUsingFreeAndSetToNull< Subjective >
        };

        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        FastDefaultMalloc = {
            AllocateElementUsingMalloc< Subjective >, 
            DeleteUsingFree< Subjective >
        };

        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        ArrayMalloc = {
            AllocateArrayUsingMalloc< Subjective >, 
            DeleteUsingFreeAndSetToNull< Subjective >
        };

        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        FastArrayMalloc = {
            AllocateArrayUsingMalloc< Subjective >, 
            DeleteUsingFree< Subjective >
        };

        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        DefaultCalloc = {
            AllocateElementUsingCalloc< Subjective >, 
            DeleteUsingFreeAndSetToNull< Subjective >
        };

        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        FastDefaultCalloc = {
            AllocateElementUsingCalloc< Subjective >, 
            DeleteUsingFree< Subjective >
        };

        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        ArrayCalloc = {
            AllocateArrayUsingCalloc< Subjective >, 
            DeleteUsingFreeAndSetToNull< Subjective >
        };

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
