// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ALLOCATION_CONTRIBUTION_MODULE
#define ALLOCATION_CONTRIBUTION_MODULE
#include "../allocation.hpp"
#include "../ration/contribution.hpp"

namespace allocation {

/**
 * @brief
 *     Memory pseudo-allocation implementations which use a pre-allocated 
 *     memory pool.
 * @details 
 *     Functions and objectives which make use of memory pools to manage 
 *     pre-allocated memory spaces.
 */
namespace contribution {

    using ::ration::contribution::Contributory;

    /**
     * @brief
     *     Distributes an element from the data pool.
     * @details
     *     This version does not check the pool's limit when distributing 
     *     elements from the pool.  Use AssignAssuredly instead if the 
     *     calling context could request more elements than are available 
     *     in the pool.
     * @tparam Natural 
     *     Type of the natural integer counts.
     * @tparam Maximum
     *     The number of elements available in the pool.
     * @tparam Subjective
     *     Type of the data elements.
     * @param[out] locality
     *     Reference to a pointer which will receive the address of the 
     *     assigned pool element.
     * @return
     *     The same address as stored in the pointer which was bound to
     *     locality.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Subjective,
        Referential<Contributory<Natural, Maximum, Subjective>> Pool>
    static inline const Locational<Subjective>
    Assign(
        Referential<Locational<Subjective>>
            locality)
    {
        using namespace ::location;
        using namespace ::ration::contribution;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        Natural index;
        Distribute(Pool, index);
        return locality = Locate(GoWrite(Pool, index).to).at;
    }

    /**
     * @brief
     *     Distributes an element from the data pool.
     * @details
     *     This version checks the pool's limit on each assignment request 
     *     when distributing elements from the pool.  Use Assign instead if
     *     performance is stringent and the calling context protects against
     *     requesting more elements than are available in the pool.
     * @tparam Natural
     *     Type of the natural integer counts.
     * @tparam Maximum 
     *     The number of elements available in the pool.
     * @tparam Subjective 
     *     Type of the data elements.
     * @param[out] locality 
     *     Reference to a pointer which will receive the address of the 
     *     assigned pool element.
     * @return 
     *     The same address as stored in the pointer which was bound to 
     *     locality.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Subjective,
        Referential<Contributory<Natural, Maximum, Subjective>> Pool>
    static inline const Locational<Subjective>
    AssignAssuredly(
        Referential<Locational<Subjective>>
            locality)
    {
        using namespace ::location;
        using namespace ::ration::contribution;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        Natural index;
        if (DistributeAssuredly(Pool, index))
            locality = Locate(GoWrite(Pool, index).to).at;
        else
            locality = 0;
        return locality;
    }

    /**
     * @brief
     *     Revokes an element and returns it into the data pool.
     * @details
     *     This version does not set the pointer to null after revoking the
     *     element back into the pool.  Use RevokeAssuredly instead if the 
     *     calling context might attempt to use the pointer after the 
     *     revocation.
     * @tparam Natural
     *     Type of the natural integer counts.
     * @tparam Maximum
     *     The number of elements available in the pool.
     * @tparam Subjective 
     *     Type of the data elements.
     * @param[in] locality
     *     Reference to a pointer whose address will be returned into the 
     *     pool.
     * @return 
     *     Does not return any value.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Subjective,
        Referential<Contributory<Natural, Maximum, Subjective>> Pool>
    static inline void
    Revoke(
        Referential<Locational<Subjective>>
            locality)
    {
        using namespace ::ration::contribution;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        Natural index;
        index = static_cast<Natural>(locality - Pool.resource.source);
        Retribute(Pool, index);
    }

    /**
     * @brief
     *     Revokes an element and returns it into the data pool.
     * @details
     *     This version sets the pointer to null after revoking the element
     *     back into the pool.  Use Revoke instead if performance is 
     *     stringent and the calling context protects against reusing the 
     *     pool element after revocation.
     * @tparam Natural
     *     Type of the natural integer counts.
     * @tparam Maximum
     *     The number of elements available in the pool.
     * @tparam Subjective
     *     Type of the data elements.
     * @param[in,out] locality
     *     Reference to a pointer whose address will be returned into the 
     *     pool.
     * @return
     *     Does not return any value.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Subjective,
        Referential<Contributory<Natural, Maximum, Subjective>> Pool>
    static inline void
    RevokeAssuredly(
        Referential<Locational<Subjective>>
            locality)
    {
        using namespace ::ration::contribution;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        Natural index;
        index = static_cast<Natural>(locality - Pool.resource.source);
        if (RetributeAssuredly(Pool, index))
            locality = 0;
    }

    /**
     * @brief
     *     Fast pool pseudo-allocator.
     * @details
     *     Function reference table which uses a data pool to implement a 
     *     pseudo-allocation scheme.  With this version, the allocate 
     *     function does not check the pool limits.
     * @tparam Natural
     *     Type of the natural integer counts.
     * @tparam Maximum
     *     The number of elements available in the pool.
     * @tparam Subjective
     *     Type of the data elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Subjective,
        Referential<Contributory<Natural, Maximum, Subjective>> Pool>
    constexpr DefaultAllocative<Subjective>
        FastPoolAllocator = {
            Assign<Natural, Maximum, Subjective, Pool>,
            Revoke<Natural, Maximum, Subjective, Pool>
        };

    /**
     * @brief
     *     Safe pool pseudo-allocator.
     * @details
     *     Function reference table which uses a data pool to implement a
     *     pseudo-allocation scheme.  With this version, the deallocate 
     *     function does not set the pointer address to null.
     * @tparam Natural
     *     Type of the natural integer counts.
     * @tparam Maximum
     *     The number of elements available in the pool.
     * @tparam Subjective
     *     Type of the data elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Subjective,
        Referential<Contributory<Natural, Maximum, Subjective>> Pool>
    constexpr DefaultAllocative<Subjective>
        SurePoolAllocator = {
            AssignAssuredly<Natural, Maximum, Subjective, Pool>,
            RevokeAssuredly<Natural, Maximum, Subjective, Pool>
        };

}

}

#endif
