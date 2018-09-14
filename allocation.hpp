// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ALLOCATION_MODULE
#define ALLOCATION_MODULE
#include "location.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace allocation {

    using ::location::Referential;
    using ::location::Locational;

    template <
        typename Claimable,
        typename Disclaimable
    >
    struct Allocative {

        Referential< Claimable >
            claim;

        Referential< Disclaimable >
            disclaim;

    };

    template <
        typename Subjective
    >
    using DefaultClaimable = const Locational< Subjective >(
        Referential< Locational< Subjective > >
    );

    template <
        typename Subjective
    >
    using DefaultDisclaimable = void(
        Referential< Locational< Subjective > >
    );

    template <
        typename Natural,
        typename Subjective
    >
    using ArrayClaimable = const Locational< Subjective >(
        Referential< Locational< Subjective > >,
        Referential< const Natural >
    );

    template <
        typename Subjective
    >
    using CopyClaimable = const Locational< Subjective >(
        Referential< Locational< Subjective > >,
        Referential< const Subjective >
    );

    template <
        typename Subjective
    >
    using DefaultAllocative = Allocative< DefaultClaimable< Subjective >, DefaultDisclaimable< Subjective > >;

    template <
        typename Natural,
        typename Subjective
    >
    using ArrayAllocative = Allocative< ArrayClaimable< Natural, Subjective >, DefaultDisclaimable< Subjective > >;

    template <
        typename Subjective
    >
    using CopyAllocative = Allocative< CopyClaimable< Subjective >, DefaultDisclaimable< Subjective > >;

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

    template <
        typename Subjective
    >
    static inline void
    DeleteAndSetToNull(
        Referential< Locational< Subjective > >
            locality
    ) {
        DeleteElement( locality );
        SetToNull( locality );
    }

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

    template <
        typename Subjective
    >
    constexpr DefaultAllocative< Subjective >
    DefaultNew = {
        AllocateNewElement< Subjective >, 
        DeleteAndSetToNull< Subjective >
    };

    template <
        typename Subjective
    >
    constexpr DefaultAllocative< Subjective >
    FastDefaultNew = {
        AllocateNewElement< Subjective >, 
        DeleteElement< Subjective >
    };

    template <
        typename Natural,
        typename Subjective
    >
    constexpr ArrayAllocative< Natural, Subjective >
    ArrayNew = {
        AllocateNewArray< Natural, Subjective >, 
        DeleteArrayAndSetToNull< Natural, Subjective >
    };

    template <
        typename Natural,
        typename Subjective
    >
    constexpr ArrayAllocative< Natural, Subjective >
    FastArrayNew = {
        AllocateNewArray< Natural, Subjective >, 
        DeleteArray< Natural, Subjective >
    };

    template <
        typename Subjective
    >
    constexpr CopyAllocative< Subjective >
    CopyNew = {
        AllocateNewCopy< Subjective >, 
        DeleteAndSetToNull< Subjective >
    };

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
