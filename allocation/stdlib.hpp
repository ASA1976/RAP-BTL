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
        static inline void
        Malloc(
            Referential< Locational< Subjective > >
                locality,
            Referential< const size_t >
                count
        ) {
            locality = (Locational< Subjective >) malloc( sizeof( Subjective ) * count );
        }

        template <
            typename Subjective
        >
        static inline void
        Malloc(
            Referential< Locational< Subjective > >
                locality
        ) {
            Malloc( locality, 1 );
        }

        template <
            typename Subjective
        >
        static inline void
        Calloc(
            Referential< Locational< Subjective > >
                locality,
            Referential< const size_t >
                count
        ) {
            locality = (Locational< Subjective >) calloc( count, sizeof( Subjective ) );
        }

        template <
            typename Subjective
        >
        static inline void
        Calloc(
            Referential< Locational< Subjective > >
                locality
        ) {
            Calloc( locality, 1 );
        }

        template <
            typename Subjective
        >
        static inline void
        Free(
            Referential< Locational< Subjective > >
                locality
        ) {
            free( locality );
        }

        template <
            typename Subjective
        >
        static inline void
        FreeAndNull(
            Referential< Locational< Subjective > >
                locality
        ) {
            Free( locality );
            SetNull( locality );
        }

        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        DefaultMalloc = {Malloc, FreeAndNull};

        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        FastDefaultMalloc = {Malloc, Free};

        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        ArrayMalloc = {Malloc, FreeAndNull};

        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        FastArrayMalloc = {Malloc, Free};

        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        DefaultCalloc = {Calloc, FreeAndNull};

        template <
            typename Subjective
        >
        constexpr DefaultAllocative< Subjective >
        FastDefaultCalloc = {Calloc, Free};

        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        ArrayCalloc = {Calloc, FreeAndNull};

        template <
            typename Subjective
        >
        constexpr ArrayAllocative< Subjective, size_t >
        FastArrayCalloc = {Calloc, Free};

    }

}

#endif
