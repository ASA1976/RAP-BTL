// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef CONTRIBUTION_MODULE
#define CONTRIBUTION_MODULE
#include "../ration.hpp"
#include "../attribution.hpp"
#include "../trajection.hpp"

namespace ration {

    namespace contribution {

        using namespace ::attribution;
        using namespace ::trajection;
        using namespace ::comparison;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        struct Contributory {

            Natural
                cycles;

            Resourceful< Natural, Maximum, Elemental >
                resource;

            Natural
                recycle[Maximum];

        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Contributory< Natural, Maximum, Elemental >
        InitializedPool = {
            0,
            InitializedResource< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Contains(
            Referential< const Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (index >= pool.resource.allotment)
                return false;
            for (Natural count = 0; count < pool.cycles; count++)
                if (index == pool.recycle[count])
                    return false;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< Elemental >
        GoWrite(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return Confer( pool.resource.source[index] );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< Elemental >
        GoWriteSafely(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!Contains( pool, index ))
                throw index;
            return GoWrite( pool, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< const Elemental >
        GoRead(
            Referential< const Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return Defer( pool.resource.source[index] );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Conferential< const Elemental >
        GoReadSafely(
            Referential< const Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!Contains( pool, index ))
                throw index;
            return GoRead( pool, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline void
        Initialize(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            pool = InitializedPool< Natural, Maximum, Elemental >;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Empty(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!pool.resource.allotment)
                return false;
            Initialize( pool );
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        Survey(
            Referential< const Contributory< Natural, Maximum, Elemental > >
                pool
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return Maximum;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        Account(
            Referential< const Contributory< Natural, Maximum, Elemental > >
                pool
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            return pool.resource.allotment - pool.cycles;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Distribute(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (pool.cycles)
                index = pool.recycle[--pool.cycles];
            else
                index = pool.resource.allotment++;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        DistributeSafely(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (Account( pool ) >= Maximum)
                return false;
            return Distribute( pool, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Retribute(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            pool.recycle[pool.cycles++] = index;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        RetributeSafely(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< const Natural >
                index
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            if (!Contains( pool, index ))
                return false;
            if (pool.cycles >= Maximum)
                return false;
            return Retribute( pool, index );
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Tributary< Contributory< Natural, Maximum, Elemental >, Natural, Natural >
        Contributor = {
            Survey< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            Distribute< Natural, Maximum, Elemental >,
            Retribute< Natural, Maximum, Elemental >,
            Empty< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Tributary< Contributory< Natural, Maximum, Elemental >, Natural, Natural >
        SafeContributor = {
            Survey< Natural, Maximum, Elemental >,
            Account< Natural, Maximum, Elemental >,
            DistributeSafely< Natural, Maximum, Elemental >,
            RetributeSafely< Natural, Maximum, Elemental >,
            Empty< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Vectorial< const Contributory< Natural, Maximum, Elemental >, Natural, const Elemental >
        ReadVector = {
            Comparison< Natural >,
            Contains< Natural, Maximum, Elemental >,
            GoRead< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Vectorial< const Contributory< Natural, Maximum, Elemental >, Natural, const Elemental >
        SafeReadVector = {
            Comparison< Natural >,
            Contains< Natural, Maximum, Elemental >,
            GoReadSafely< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Vectorial< Contributory< Natural, Maximum, Elemental >, Natural, Elemental >
        WriteVector = {
            Comparison< Natural >,
            Contains< Natural, Maximum, Elemental >,
            GoWrite< Natural, Maximum, Elemental >
        };

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        constexpr Vectorial< Contributory< Natural, Maximum, Elemental >, Natural, Elemental >
        SafeWriteVector = {
            Comparison< Natural >,
            Contains< Natural, Maximum, Elemental >,
            GoWriteSafely< Natural, Maximum, Elemental >
        };

    }

}

#endif
