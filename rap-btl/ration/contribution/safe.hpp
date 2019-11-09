// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_RATION_CONTRIBUTION_MODULE
#define SAFE_RATION_CONTRIBUTION_MODULE
#include <ration/contribution.hpp>

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
        typename Elemental>
    static inline Conferential<Elemental>
    GoWriteSafely(
        Referential<Contributory<Natural, Maximum, Elemental>>
            pool,
        Referential<const Natural>
            index)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!Contains(pool, index))
            throw index;
        return GoWrite(pool, index);
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
        typename Elemental>
    static inline Conferential<const Elemental>
    GoReadSafely(
        Referential<const Contributory<Natural, Maximum, Elemental>>
            pool,
        Referential<const Natural>
            index)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!Contains(pool, index))
            throw index;
        return GoRead(pool, index);
    }

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
        typename Elemental>
    constexpr Vectorial<const Contributory<Natural, Maximum, Elemental>, Natural, const Elemental>
        SafeReadVector = {
            Comparison<Natural>,
            Contains<Natural, Maximum, Elemental>,
            GoReadSafely<Natural, Maximum, Elemental>
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
        typename Elemental>
    constexpr Vectorial<Contributory<Natural, Maximum, Elemental>, Natural, Elemental>
        SafeWriteVector = {
            Comparison<Natural>,
            Contains<Natural, Maximum, Elemental>,
            GoWriteSafely<Natural, Maximum, Elemental>
        };

}

}

#endif
