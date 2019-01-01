// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_IDENTIFICATION_MODULE
#define RATION_IDENTIFICATION_MODULE
#include "../attribution.hpp"
#include "../ration.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

    /**
     * @brief
     *     Identifier rationing.
     * @details
     *     Association
     *     -----------
     *     Fast identification system which uses simple integer enumeration and
     *     recycling of revoked identifiers.
     */
    namespace identification {

        using ::location::Referential;
        using ::attribution::Tributary;

        /**
         * @brief 
         *     Identifier pool conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type is used to represent an identifier pool.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        struct Identical {

            Natural
                next; /**< Next never assigned identifier. */
            
            Resourceful< Natural, Maximum, Natural >
                recycle; /**< Recycle of unused identifiers. */

        };

        /**
         * @brief 
         *     Initialized identifier pool.
         * @details 
         *     Information Template
         *     --------------------
         *     Initialized identifier pool value which can be used to 
         *     initialize an instance of the same identifier pool type.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        constexpr Identical< Natural, Maximum >
            InitializedIdentifierPool = {
                0,
                InitializedResource< Natural, Maximum, Natural >
            };

        /**
         * @brief
         *     Check if identifier is valid.
         * @details
         *     Function Template
         *     -----------------
         *     Checks if an identifier is a currently valid.  Revoked 
         *     identifiers and identifiers which have never been assigned are 
         *     both considered invalid.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         * @param[in] pool
         *     Reference to the pool.
         * @param[in] identifier
         *     Reference to the identifier.
         * @return
         *     True if identifier is valid.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        static inline bool
        IsValid(
            Referential< const Identical< Natural, Maximum > >
                pool,
            Referential< const Natural >
                identifier
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (identifier >= pool.next)
                return false;
            for (Natural count = 0; count < pool.recycle.allotment; count++)
                if (identifier == pool.recycle.source[count])
                    return false;
            return true;
        }

        /**
         * @brief 
         *     Initializes the identifier pool.
         * @details
         *     Function Template
         *     -----------------
         *     Initializes the identifier pool.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         * @param[in,out] pool 
         *     Reference to the pool.
         * @return 
         *     A reference to the pool.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        static inline Referential< Identical< Natural, Maximum > >
        Initialize(
            Referential< Identical< Natural, Maximum > >
                pool
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return pool = InitializedIdentifierPool< Natural, Maximum >;
        }

        /**
         * @brief 
         *     Invalidates all identifiers in the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Retributes all identifiers issued by the pool.  Returns true only
         *     if there were allotted identifiers in the pool before the call.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         * @param[in,out] pool 
         *     Reference to the pool.
         * @return 
         *     True if the pool was altered by this operation.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        static inline bool
        Contribute(
            Referential< Identical< Natural, Maximum > >
                pool
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (pool.recycle.allotment >= pool.next)
                return false;
            Initialize( pool );
            return true;
        }

        /**
         * @brief 
         *     Returns the maximum number of concurrent identifiers.
         * @details
         *     Function Template
         *     -----------------
         *     Returns the maximum number of concurrent idenfitiers in the pool.
         *     This function may or may not incur run-time overhead depending on
         *     the invocation context.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         * @param[in] pool 
         *     Reference to the pool.
         * @return 
         *     The maximum number of concurrent identifiers.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        static inline Natural
        Survey(
            Referential< const Identical< Natural, Maximum > >
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
         *     Returns the number of active identifiers in the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Returns the number of active identifiers in the pool which
         *     defaults to zero if the identifier pool was properly 
         *     initialized.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         * @param[in] pool 
         *     Reference to the pool.
         * @return 
         *     The number of active identifiers in the pool.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        static inline Natural
        Account(
            Referential< const Identical< Natural, Maximum > >
                pool
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return pool.next - pool.recycle.allotment;
        }

        /**
         * @brief 
         *     Assigns an available identifier from the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Assigns an available identifier from the pool.  This version
         *     does not verify if more identifiers have been requested than are 
         *     available in the identifier pool.  Use this version only if 
         *     stringent performance is required.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         * @param[in,out] pool
         *     Reference to the pool.
         * @param[out] identifier 
         *     Reference to the identifier.
         * @return 
         *     Always returns true.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        static inline bool
        Distribute(
            Referential< Identical< Natural, Maximum > >
                pool,
            Referential< Natural >
                identifier
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (pool.recycle.allotment)
                identifier = pool.recycle.source[--pool.recycle.allotment];
            else
                identifier = pool.next++;
            return true;
        }

        /**
         * @brief 
         *     Assigns an available identifier from the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Assigns an available identifier from the pool.  This version will
         *     return false if more identifiers have been requested than are 
         *     available in the pool.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         * @param[in,out] pool
         *     Reference to the pool.
         * @param[out] identifier 
         *     Reference to the identifier.
         * @return 
         *     Always returns true.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        static inline bool
        DistributeSafely(
            Referential< Identical< Natural, Maximum > >
                pool,
            Referential< Natural >
                identifier
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
            return Distribute( pool, identifier );
        }

        /**
         * @brief 
         *     Retributes an identifier to the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Retributes an identifier to the pool.  This version does not verify
         *     if identifier is currently allotted.  Use this version only if 
         *     stringent performance is required.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum
         *     Maximum number of concurrently assigned identifiers.
         * @param[in,out] pool
         *     Reference to the pool.
         * @param[in] identifier 
         *     Reference to the identifier.
         * @return 
         *     Always returns true.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        static inline bool
        Retribute(
            Referential< Identical< Natural, Maximum > >
                pool,
            Referential< const Natural >
                identifier
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            pool.recycle.source[pool.recycle.allotment++] = identifier;
            return true;
        }

        /**
         * @brief 
         *     Retributes an identifier to the pool.
         * @details
         *     Function Template
         *     -----------------
         *     Retributes an identifier to the pool.  This version returns false 
         *     if identifier is not currently allotted.
         * @tparam Natural
         *     Type of natural integer.
         * @tparam Maximum 
         *     The maximum number of identifiers.
         * @param[in,out] pool 
         *     Reference to the pool.
         * @param[in] identifier 
         *     Reference to the identifier.
         * @return 
         *     Returns true if the identifier was retracted.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        static inline bool
        RetributeSafely(
            Referential< Identical< Natural, Maximum > >
                pool,
            Referential< const Natural >
                identifier
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!IsValid( pool, identifier ))
                return false;
            if (pool.recycle.allotment >= Maximum)
                return false;
            return Retribute( pool, identifier );
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
         *     Type of natural integer.
         * @tparam Maximum 
         *     The maximum number of identifiers.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        constexpr Tributary< Identical< Natural, Maximum >, Natural, Natural >
            IdentityContributor = {
                Survey< Natural, Maximum >,
                Account< Natural, Maximum >,
                Distribute< Natural, Maximum >,
                Retribute< Natural, Maximum >,
                Contribute< Natural, Maximum >
            };

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
         *     Type of natural integer.
         * @tparam Maximum 
         *     The maximum number of identifiers.
         */
        template <
            typename Natural,
            Natural
                Maximum
        >
        constexpr Tributary< Identical< Natural, Maximum >, Natural, Natural >
            SafeIdentityContributor = {
                Survey< Natural, Maximum >,
                Account< Natural, Maximum >,
                DistributeSafely< Natural, Maximum >,
                RetributeSafely< Natural, Maximum >,
                Contribute< Natural, Maximum >
            };

    }

}

#endif
