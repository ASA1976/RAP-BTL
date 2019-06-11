// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_CONTRIBUTION_MODULE
#define RATION_CONTRIBUTION_MODULE
#include "../ration.hpp"
#include "../attribution.hpp"
#include "../trajection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

    /**
     * @brief
     *     Pool rationing.
     * @details 
     *     Association
     *     -----------
     *     Array based pool rationing conformity, initialization facility, 
     *     tractile management and direct trajection implementations.
     */
    namespace contribution {

        using ::location::Referential;
        using ::location::Conferential;
        using ::trajection::Vectorial;
        using ::attribution::Tributary;
        using ::comparison::Comparison;

        /**
         * @brief
         *     Pool resource conformity.
         * @details 
         *     Conformation Template
         *     ---------------------
         *     Type definition which contains a cycles count, memory resource 
         *     definition and array of recycled indexes.
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
        struct Contributory {

            Natural
                cycles; /**< Number of recycled indexes. */

            Resourceful< Natural, Maximum, Elemental >
                resource; /**< Memory resource. */

            Natural
                recycle[Maximum]; /**< Array of recycled indexes. */

        };

        /**
         * @brief 
         *     Initialized pool.
         * @details 
         *     Information Template
         *     --------------------
         *     Initialized pool value which can be used to initialize an 
         *     instance of the same pool type.
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
        constexpr Contributory< Natural, Maximum, Elemental >
            InitializedPool = {
                0,
                InitializedResource< Natural, Maximum, Elemental >
            };

        /**
         * @brief
         *     Check if index is an allotted pool position.
         * @details
         *     Function Template
         *     -----------------
         *     Checks if index is a currently allotted pool element.
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
         *     True if index is allotted.
         */
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (index >= pool.resource.allotment)
                return false;
            for (Natural count = 0; count < pool.cycles; count++)
                if (index == pool.recycle[count])
                    return false;
            return true;
        }

        /**
         * @brief 
         *     Confers the element at index.
         * @details
         *     Function Template
         *     -----------------
         *     Returns a modifiable reference to the element at the specified 
         *     index.
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
        GoWrite(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< const Natural >
                index
        ) {
            using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Confer( pool.resource.source[index] );
        }

        /**
         * @brief
         *     Deters the element at index.
         * @details
         *     Function Template
         *     -----------------
         *     Returns a constant reference to the element at the specified 
         *     positional index.
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
        GoRead(
            Referential< const Contributory< Natural, Maximum, Elemental > >
                pool,
            Referential< const Natural >
                index
        ) {
            using ::location::Deter;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Deter( pool.resource.source[index] );
        }

        /**
         * @brief 
         *     Initializes the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Initializes the pool allotment and cycles count to zero.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in,out] pool 
         *     Reference to the pool.
         * @return 
         *     A reference to the pool.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< Contributory< Natural, Maximum, Elemental > >
        Initialize(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return pool = InitializedPool< Natural, Maximum, Elemental >;
        }

        /**
         * @brief 
         *     Empties the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Retributes all distributed elements in the pool.  Returns true only
         *     if there were allotted elements in the pool before the call.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in,out] pool 
         *     Reference to the pool.
         * @return 
         *     True if the pool was altered by this operation.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Contribute(
            Referential< Contributory< Natural, Maximum, Elemental > >
                pool
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (pool.cycles >= pool.resource.allotment)
                return false;
            Initialize( pool );
            return true;
        }

        /**
         * @brief 
         *     Returns the maximum size of the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Returns the maximum size of the pool.  This function may or may
         *     not incur run-time overhead depending on the invocation context.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] pool 
         *     Reference to the pool.
         * @return 
         *     The maximum number of pool elements.
         */
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Maximum;
        }

        /**
         * @brief 
         *     Returns the number of distributed elements in the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Returns the number of distributed elements in the pool which
         *     defaults to zero if the pool was properly initialized.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] pool 
         *     Reference to the pool.
         * @return 
         *     The number of allotted elements.
         */
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return pool.resource.allotment - pool.cycles;
        }

        /**
         * @brief 
         *     Distributes an available element from the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Distributes an element from the pool.  This version does
         *     not verify if more elements have been requested than are 
         *     available in the pool.  Use this version only if stringent 
         *     performance is required.
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
         *     Always returns true.
         */
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (pool.cycles)
                index = pool.recycle[--pool.cycles];
            else
                index = pool.resource.allotment++;
            return true;
        }

        /**
         * @brief 
         *     Retributes an element to the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Retributes an element to the pool.  This version does not verify
         *     if index is currently allotted or even a valid index.  Use this 
         *     version only if stringent performance is required.
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
         *     Always returns true.
         */
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
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            pool.recycle[pool.cycles++] = index;
            return true;
        }

        /**
         * @brief 
         *     Tributary pool management implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides fast tributary pool management.  
         *     Use this version if performance is stringent, however care should
         *     be taken to understand how each function works in order to 
         *     prevent overflowing the pool, which could cause bugs.
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
            Contributor = {
                Survey< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                Distribute< Natural, Maximum, Elemental >,
                Retribute< Natural, Maximum, Elemental >,
                Contribute< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Vectorial read trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides fast vectorial trajection into the
         *     pool.  Use this version if performance is stringent and requests
         *     for invalid index positions will not occur, as this version does
         *     not perform any run-time checks.
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
            ReadVector = {
                Comparison< Natural >,
                Contains< Natural, Maximum, Elemental >,
                GoRead< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Vectorial write trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides fast vectorial trajection into the
         *     pool.  Use this version if performance is stringent and requests
         *     for invalid index positions will not occur, as this version does
         *     not perform any run-time checks.
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
            WriteVector = {
                Comparison< Natural >,
                Contains< Natural, Maximum, Elemental >,
                GoWrite< Natural, Maximum, Elemental >
            };

    }

}

#endif
