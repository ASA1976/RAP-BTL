// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SEGMENTATION_MODULE
#define SEGMENTATION_MODULE
#include "localization.hpp"

/**
 * @brief         
 *     Segment space trajection implementation.
 * @details       
 *     Association
 *     -----------
 *     Implements vectorial and sequential trajection between a pointer base and
 *     positive relative offsets of a compile-time known length.
 */
namespace segmentation {

    using ::location::Locational;
    using ::location::Referential;
    using ::location::Conferential;
    using ::trajection::Vectorial;
    using ::trajection::Scalar;
    using ::trajection::Lineal;
    using ::trajection::Directional;
    using ::trajection::Axial;
    using ::localization::IndexicalGo;
    using ::localization::TraverseDecrement;
    using ::localization::ReadIncrementScale;
    using ::localization::WriteIncrementScale;
    using ::localization::ReadLocal;
    using ::localization::WriteLocal;
    using ::comparison::Comparison;

    /**
     * @brief
     *     Check if index is within the segment.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if index is within the segment.  This version does not check
     *     if locality is null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @return
     *     True if index is less than length.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    ContainsIndex(
        Referential< const Locational< Elemental > >
            locality,
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
        return index < Length;
    }

    /**
     * @brief
     *     Check if index is within the segment.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if index is within the segment.  This version throws an 
     *     exception if locality is null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @return
     *     True if index is less than length.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    SafelyContainsIndex(
        Referential< const Locational< Elemental > >
            locality,
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
        static auto&
            Contains = ContainsIndex< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        if (index < 0)
            throw index;
        return Contains( locality, index );
    }

    /**
     * @brief 
     *     Confers the element at index.
     * @details
     *     Function Template
     *     -----------------
     *     Returns a reference to the element at the specified index.  This
     *     version throws an exception if the pointer is null or the index
     *     is out of bounds.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @return
     *     The reference conferment.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Conferential< Elemental >
    IndexicalGoSafely(
        Referential< const Locational< Elemental > >
            locality,
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
        static auto&
            Contains = SafelyContainsIndex< Natural, Length, Elemental >;
        if (!Contains( locality, index ))
            throw index;
        return IndexicalGo( locality, index );
    }

    /**
     * @brief
     *     Checks if sequential trajection can begin.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can begin at the specified offset
     *     count.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the segment's length is greater than zero and count is less
     *     than length.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    Begins(
        Referential< const Locational< Elemental > >
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
        return count < Length;
    }

    /**
     * @brief
     *     Checks if sequential trajection can begin.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can begin at the specified offset
     *     count.  This version throws an exception if the pointer is null.
     * @tparam Natural
     *     Type of natural integer for count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the segment's length is greater than zero and count is less
     *     than length.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    SafelyBegins(
        Referential< const Locational< Elemental > >
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
        static auto&
            SegmentBegins = Begins< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        if (count < 0)
            throw count;
        return SegmentBegins( locality, count );
    }

    /**
     * @brief
     *     Begins increment trajection.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns to index the count positive offset from zero.  This version
     *     throws an exception if the segment length is zero, the pointer is 
     *     null or count is greater than or equal to the segment length.
     * @tparam Natural
     *     Type of natural integer for index and count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @param[out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    BeginIncrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
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
        if (Length < 1)
            throw Length;
        if (!locality)
            throw locality;
        if (count >= Length)
            throw count;
        return Begin( locality, index, count );
    }

    /**
     * @brief
     *     Begins increment trajection.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns to index the count negative offset from the length of the 
     *     segment minus one.  This version does not check if the segment length
     *     is zero, if the pointer is null or if count is greater than or equal
     *     to the segment length.
     * @tparam Natural
     *     Type of natural integer for index and count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @param[out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    BeginDecrement(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
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
        return index = Length - 1 - count;
    }

    /**
     * @brief
     *     Begins decrement trajection.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns to index the count negative offset from the length of the 
     *     segment minus one.  This version throws an exception if the segment 
     *     length is zero, the pointer is null or count is greater than or equal
     *     to the segment length.
     * @tparam Natural
     *     Type of natural integer for index and count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @param[out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    BeginDecrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
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
        static auto&
            Descend = BeginDecrement< Natural, Length, Elemental >;
        if (Length < 1)
            throw Length;
        if (!locality)
            throw locality;
        if (count >= Length)
            throw count;
        return Descend( locality, index, count );
    }

    /**
     * @brief
     *     Checks if sequential trajection can continue.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can traverse from index to the
     *     specified count offset.  This version does not check if the pointer
     *     is null.
     * @tparam Natural
     *     Type of natural integer for index and count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the offset can be reached from index.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraverses(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index,
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
        return index + count < Length;
    }

    /**
     * @brief
     *     Checks if sequential trajection can continue.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can traverse from index to the
     *     specified count offset.  This version throws an exception if the 
     *     pointer is null.
     * @tparam Natural
     *     Type of natural integer for index and count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the offset can be reached from index.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraversesSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index,
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
        static auto&
            Traverses = IncrementTraverses< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        if (count < 0)
            throw count;
        return Traverses( locality, index, count );
    }

    /**
     * @brief
     *     Checks if sequential trajection can continue.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can traverse from index to the
     *     specified count offset.  This version does not check if the pointer
     *     is null.
     * @tparam Natural
     *     Type of natural integer for index and count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the offset can be reached from index.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraverses(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index,
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
        return count <= index;
    }

    /**
     * @brief
     *     Checks if sequential trajection can continue.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can traverse from index to the
     *     specified count offset.  This version throws an exception if the 
     *     pointer is null.
     * @tparam Natural
     *     Type of natural integer for index and count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the offset can be reached from index.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraversesSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< const Natural >
            index,
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
        static auto&
            Traverses = DecrementTraverses< Natural, Length, Elemental >;
        if (!locality)
            throw locality;
        if (count < 0)
            throw count;
        return Traverses( locality, index, count );
    }

    /**
     * @brief 
     *     Traverses increment.
     * @details
     *     Function Template
     *     -----------------
     *     Increases index by count offset.  This version throws an exception if
     *     index would become greater than or equal to the segment length.
     * @tparam Natural
     *     Type of natural integer for index and count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @param[in,out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    TraverseIncrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
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
        static auto&
            Traverses = IncrementTraversesSafely< Natural, Length, Elemental >;
        if (!Traverses( locality, index, count ))
            throw count;
        return TraverseIncrement( locality, index, count );
    }

    /**
     * @brief 
     *     Traverses decrement.
     * @details
     *     Function Template
     *     -----------------
     *     Decreases index by count offset.  This version throws an exception if
     *     index would become less than zero.
     * @tparam Natural
     *     Type of natural integer for index and count.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @param[in,out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Natural >
    TraverseDecrementSafely(
        Referential< const Locational< Elemental > >
            locality,
        Referential< Natural >
            index,
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
        static auto&
            Traverses = DecrementTraversesSafely< Natural, Length, Elemental >;
        if (!Traverses( locality, index, count ))
            throw count;
        return TraverseDecrement( locality, index, count );
    }

    /**
     * @brief 
     *     Returns the number of elements in the segment.
     * @details
     *     Function Template
     *     -----------------
     *     Returns the number of elements in the segment.
     * @tparam Natural
     *     Type of natural integer for index and result.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @return 
     *     The number of elements in the segment.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    Account(
        Referential< const Locational< Elemental > >
            locality
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return Length;
    }

    /**
     * @brief 
     *     Returns the number of elements in the segment __after__ index.
     * @details
     *     Function Template
     *     -----------------
     *     Returns the number of elements in the segment __after__
     *     the specified index (does not include the element at index).
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @return 
     *     The number of elements __after__ index.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    CountIncrement(
        Referential< const Locational< Elemental > >
            locality,
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
        return Length - 1 - index;
    }

    /**
     * @brief 
     *     Returns the number of elements in the segment __before__ index.
     * @details
     *     Function Template
     *     -----------------
     *     Returns the number of elements in the segment __before__
     *     the specified index (does not include the element at index).
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] locality 
     *     Reference to the pointer.
     * @param[in] index
     *     Reference to the index.
     * @return 
     *     The number of elements __before__ index.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    CountDecrement(
        Referential< const Locational< Elemental > >
            locality,
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
        return index;
    }

    /**
     * @brief 
     *     Vectorial read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides vectorial trajection into the segment.
     *     Use this version if performance is stringent and requests for invalid 
     *     index positions will not occur, as this version does not perform any 
     *     run-time checks.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< const Elemental >, Natural, const Elemental >
    ReadVector = {
        Comparison< Natural >,
        ContainsIndex< Natural, Length, const Elemental >,
        IndexicalGo< Natural, const Elemental >
    };

    /**
     * @brief 
     *     Vectorial read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides vectorial trajection into the segment.
     *     Use this version if performance is not stringent and requests for 
     *     invalid index positions might occur, as this version does perform 
     *     run-time checks.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< const Elemental >, Natural, const Elemental >
    SafeReadVector = {
        Comparison< Natural >,
        SafelyContainsIndex< Natural, Length, const Elemental >,
        IndexicalGoSafely< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Vectorial write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides vectorial trajection into the segment.
     *     Use this version if performance is stringent and requests for invalid 
     *     index positions will not occur, as this version does not perform any 
     *     run-time checks.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< Elemental >, Natural, Elemental >
    WriteVector = {
        Comparison< Natural >,
        ContainsIndex< Natural, Length, Elemental >,
        IndexicalGo< Natural, Elemental >
    };

    /**
     * @brief 
     *     Vectorial read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides vectorial trajection into the segment.
     *     Use this version if performance is not stringent and requests for 
     *     invalid index positions might occur, as this version does perform 
     *     run-time checks.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Locational< Elemental >, Natural, Elemental >
    SafeWriteVector = {
        Comparison< Natural >,
        SafelyContainsIndex< Natural, Length, Elemental >,
        IndexicalGoSafely< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection from a 
     *     pointer.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadIncrementScale = {
        Comparison< Natural >,
        BeginIncrementSafely< Natural, Length, const Elemental >,
        TraverseIncrementSafely< Natural, Length, const Elemental >,
        IndexicalGoSafely< Natural, Length, const Elemental >,
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection from a 
     *     pointer.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteIncrementScale = {
        Comparison< Natural >,
        BeginIncrementSafely< Natural, Length, Elemental >,
        TraverseIncrementSafely< Natural, Length, Elemental >,
        IndexicalGoSafely< Natural, Length, Elemental >,
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a 
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadDecrementScale = {
        Comparison< Natural >,
        BeginDecrement< Natural, Length, const Elemental >,
        TraverseDecrement< Natural, Natural, const Elemental >,
        IndexicalGo< Natural, const Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a 
     *     pointer.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadDecrementScale = {
        Comparison< Natural >,
        BeginDecrementSafely< Natural, Length, const Elemental >,
        TraverseDecrementSafely< Natural, Length, const Elemental >,
        IndexicalGoSafely< Natural, Length, const Elemental >,
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a 
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteDecrementScale = {
        Comparison< Natural >,
        BeginDecrement< Natural, Length, Elemental >,
        TraverseDecrement< Natural, Natural,  Elemental >,
        IndexicalGo< Natural, Elemental >,
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a 
     *     pointer.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteDecrementScale = {
        Comparison< Natural >,
        BeginDecrementSafely< Natural, Length, Elemental >,
        TraverseDecrementSafely< Natural, Length, Elemental >,
        IndexicalGoSafely< Natural, Length, Elemental >,
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.
     *     Use this version if performance is stringent and the pointer is 
     *     prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadLiner = {
        ReadIncrementScale< Natural, Natural, Elemental >,
        ReadDecrementScale< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.
     *     Use this version if performance is stringent and the pointer is 
     *     prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteLiner = {
        WriteIncrementScale< Natural, Natural, Elemental >,
        WriteDecrementScale< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.
     *     Use this version if performance is not stringent and the pointer is 
     *     not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadLiner = {
        SafeReadIncrementScale< Natural, Length, Elemental >,
        SafeReadDecrementScale< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.
     *     Use this version if performance is not stringent and the pointer is 
     *     not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteLiner = {
        SafeWriteIncrementScale< Natural, Length, Elemental >,
        SafeWriteDecrementScale< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection from a
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadIncrementDirection = {
        ReadIncrementScale< Natural, Natural, Elemental >,
        Begins< Natural, Length, const Elemental >,
        IncrementTraverses< Natural, Length, const Elemental >,
        ContainsIndex< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountIncrement< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection from a 
     *     pointer.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadIncrementDirection = {
        SafeReadIncrementScale< Natural, Length, Elemental >,
        SafelyBegins< Natural, Length, const Elemental >,
        IncrementTraversesSafely< Natural, Length, const Elemental >,
        SafelyContainsIndex< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountIncrement< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection from a
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteIncrementDirection = {
        WriteIncrementScale< Natural, Elemental >,
        Begins< Natural, Length, Elemental >,
        IncrementTraverses< Natural, Length, Elemental >,
        ContainsIndex< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountIncrement< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection from a 
     *     pointer.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteIncrementDirection = {
        SafeWriteIncrementScale< Natural, Length, Elemental >,
        SafelyBegins< Natural, Length, Elemental >,
        IncrementTraversesSafely< Natural, Length, Elemental >,
        SafelyContainsIndex< Natural, Length, const Elemental >,
        Account< Natural, Length, Elemental >,
        CountIncrement< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadDecrementDirection = {
        ReadDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        DecrementTraverses< Natural, Length, const Elemental >,
        ContainsIndex< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountDecrement< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a 
     *     pointer.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadDecrementDirection = {
        SafeReadDecrementScale< Natural, Length, Elemental >,
        SafelyBegins< Natural, Length, const Elemental >,
        DecrementTraversesSafely< Natural, Length, const Elemental >,
        SafelyContainsIndex< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountDecrement< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a
     *     pointer.  Use this version if performance is stringent and the 
     *     pointer is prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteDecrementDirection = {
        WriteDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        DecrementTraverses< Natural, Length, Elemental >,
        ContainsIndex< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountDecrement< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection from a 
     *     pointer.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteDecrementDirection = {
        SafeWriteDecrementScale< Natural, Length, Elemental >,
        SafelyBegins< Natural, Length, Elemental >,
        DecrementTraversesSafely< Natural, Length, Elemental >,
        SafelyContainsIndex< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountDecrement< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.
     *     Use this version if performance is stringent and the pointer is 
     *     prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< const Elemental >, Natural, Natural, const Elemental >
    ReadAxis = {
        ReadIncrementDirection< Natural, Length, Elemental >,
        ReadDecrementDirection< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.
     *     Use this version if performance is not stringent and the pointer is 
     *     not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< const Elemental >, Natural, Natural, const Elemental >
    SafeReadAxis = {
        SafeReadIncrementDirection< Natural, Length, Elemental >,
        SafeReadDecrementDirection< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.
     *     Use this version if performance is stringent and the pointer is 
     *     prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< Elemental >, Natural, Natural, Elemental >
    WriteAxis = {
        WriteIncrementDirection< Natural, Length, Elemental >,
        WriteDecrementDirection< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection from a pointer.
     *     Use this version if performance is not stringent and the pointer is 
     *     not prevented from being null.
     * @tparam Natural
     *     Type of natural integer for index.
     * @tparam Length
     *     The length of the segment.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Locational< Elemental >, Natural, Natural, Elemental >
    SafeWriteAxis = {
        SafeWriteIncrementDirection< Natural, Length, Elemental >,
        SafeWriteDecrementDirection< Natural, Length, Elemental >
    };

}

#endif
