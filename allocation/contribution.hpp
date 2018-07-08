// � 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ALLOCATION_CONTRIBUTION_MODULE
#define ALLOCATION_CONTRIBUTION_MODULE
#include "../allocation.hpp"
#include "../ration/contribution.hpp"

namespace allocation {

    namespace contribution {

        using namespace ::ration::contribution;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Subjective,
            Referential< Contributory< Natural, Maximum, Subjective > >
                Pool
        >
        static inline void
        Assign(
            Referential< Locational< Subjective > >
                locality
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Natural
                index;
            Distribute( Pool, index );
            locality = Locate( GoWrite( Pool, index ).to ).at;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Subjective,
            Referential< Contributory< Natural, Maximum, Subjective > >
                Pool
        >
        static inline void
        AssignSafely(
            Referential< Locational< Subjective > >
                locality
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Natural
                index;
            if (DistributeSafely( Pool, index ))
                locality = Locate( GoWrite( Pool, index ).to ).at;
            else
                locality = 0;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Subjective,
            Referential< Contributory< Natural, Maximum, Subjective > >
                Pool
        >
        static inline void
        Revoke(
            Referential< Locational< Subjective > >
                locality
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Natural
                index;
            index = (Natural) (locality - Pool.resource.source);
            Retribute( Pool, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Subjective,
            Referential< Contributory< Natural, Maximum, Subjective > >
                Pool
        >
        static inline void
        RevokeSafely(
            Referential< Locational< Subjective > >
                locality
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            Natural
                index;
            index = (Natural) (locality - Pool.resource.source);
            if (RetributeSafely( Pool, index ))
                locality = 0;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Subjective,
            Referential< Contributory< Natural, Maximum, Subjective > >
                Pool
        >
        constexpr DefaultAllocative< Subjective >
        FastPoolAllocator = {
            Assign< Natural, Maximum, Subjective, Pool >,
            Revoke< Natural, Maximum, Subjective, Pool >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Subjective,
            Referential< Contributory< Natural, Maximum, Subjective > >
                Pool
        >
        constexpr DefaultAllocative< Subjective >
        SafePoolAllocator = {
            AssignSafely< Natural, Maximum, Subjective, Pool >,
            RevokeSafely< Natural, Maximum, Subjective, Pool >
        };

    }

}

#endif