// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_RATION_CONTRIBUTION_MODULE
#define SAFE_RATION_CONTRIBUTION_MODULE
#include "../contribution.hpp"

namespace ration {

    namespace contribution {

        /**
         * @brief
         *     Confers the element at index.
         * @details
         *     Function Template
         *     -----------------
         *     Returns a modifiable reference to the element at the specified 
         *     index.  Throws an exception if the index is not currently 
         *     allotted.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum
         *     The maximum number of elements.
         * @tparam Elemental
         *     Type of the elements.
         * @param[in] pool
         *     Reference to the pool.
         * @param[in] index
         *     Reference to the index.
         * @return 
         *     The reference conferment.
         */
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!Contains( pool, index ))
                throw index;
            return GoWrite( pool, index );
        }

        /**
         * @brief 
         *     Deters the element at index.
         * @details
         *     Function Template
         *     -----------------
         *     Returns a constant reference to the element at the specified 
         *     positional index.  Throws an exception if the index is not 
         *     currently allotted.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] pool
         *     Reference to the pool.
         * @param[in] index
         *     Reference to the index.
         * @return 
         *     The reference determent.
         */
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!Contains( pool, index ))
                throw index;
            return GoRead( pool, index );
        }

        /**
         * @brief 
         *     Distributes an element from the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Distributes an element from the pool.  This version will
         *     return false if more elements have been requested than are 
         *     available in the pool.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in,out] pool 
         *     Reference to the pool.
         * @param[out] index 
         *     Reference to the index.
         * @return 
         *     Returns true if the number of requested elements were protracted.
         */
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (Account( pool ) >= Maximum)
                return false;
            return Distribute( pool, index );
        }

        /**
         * @brief 
         *     Retributes an element to the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Retributes an element to the pool.  This version returns false 
         *     if index is not currently allotted or is an invalid index.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in,out] pool 
         *     Reference to the pool.
         * @param[in] index 
         *     Reference to the index.
         * @return 
         *     Returns true if the index was retracted.
         */
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!Contains( pool, index ))
                return false;
            if (pool.cycles >= Maximum)
                return false;
            return Retribute( pool, index );
        }

        /**
         * @brief 
         *     Tributary pool management implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe tributary pool management.  
         *     Use this version if overflowing the pool is not prevented, where
         *     this version will perform the run-time checks for you.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         */
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
                Contribute< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Vectorial read trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe vectorial trajection into the
         *     pool.  Use this version if performance is not stringent and 
         *     requests for invalid index positions might occur, as this version
         *     does perform run-time checks.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         */
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

        /**
         * @brief 
         *     Vectorial write trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe vectorial trajection into the
         *     pool.  Use this version if performance is not stringent and 
         *     requests for invalid index positions might occur, as this version
         *     does perform run-time checks.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         */
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
