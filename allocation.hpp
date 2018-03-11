// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ALLOCATION_MODULE
#define ALLOCATION_MODULE
#include "location.hpp"

namespace allocation {

    using namespace ::location;

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
    using DefaultClaimable = void(
        Referential< Locational< Subjective > >
    );

    template <
        typename Subjective
    >
    using DefaultDisclaimable = DefaultClaimable< Subjective >;

    template <
        typename Natural,
        typename Subjective
    >
    using ArrayClaimable = void(
        Referential< Locational< Subjective > >,
        Referential< const Natural >
    );

    template <
        typename Subjective
    >
    using CopyClaimable = void(
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
    static inline void
    New(
        Referential< Locational< Subjective > >
            locality
    ) {
        locality = new Subjective;
    }

    template <
        typename Natural,
        typename Subjective
    >
    static inline void
    NewArray(
        Referential< Locational< Subjective > >
            locality,
        Referential< const Natural >
            count
    ) {
        locality = new Subjective[count];
    }

    template <
        typename Subjective
    >
    static inline void
    NewCopy(
        Referential< Locational< Subjective > >
            locality,
        Referential< const Subjective >
            subject
    ) {
        locality = new Subjective( subject );
    }

    template <
        typename Subjective
    >
    static inline void
    SetNull(
        Referential< Locational< Subjective > >
            locality
    ) {
        locality = 0;
    }

    template <
        typename Subjective
    >
    static inline void
    Delete(
        Referential< Locational< Subjective > >
            locality
    ) {
        delete locality;
    }

    template <
        typename Subjective
    >
    static inline void
    DeleteAndNull(
        Referential< Locational< Subjective > >
            locality
    ) {
        Delete( locality );
        SetNull( locality );
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
    DeleteArrayAndNull(
        Referential< Locational< Subjective > >
            locality
    ) {
        DeleteArray( locality );
        SetNull( locality );
    }

    template <
        typename Subjective
    >
    constexpr DefaultAllocative< Subjective >
    DefaultNew = {New, DeleteAndNull};

    template <
        typename Subjective
    >
    constexpr DefaultAllocative< Subjective >
    FastDefaultNew = {New, Delete};

    template <
        typename Natural,
        typename Subjective
    >
    constexpr ArrayAllocative< Natural, Subjective >
    ArrayNew = {NewArray, DeleteArrayAndNull};

    template <
        typename Natural,
        typename Subjective
    >
    constexpr ArrayAllocative< Natural, Subjective >
    FastArrayNew = {NewArray, DeleteArray};

    template <
        typename Subjective
    >
    constexpr CopyAllocative< Subjective >
    CopyNew = {NewCopy, DeleteAndNull};

    template <
        typename Subjective
    >
    constexpr CopyAllocative< Subjective >
    FastCopyNew = {NewCopy, Delete};

}

#endif
