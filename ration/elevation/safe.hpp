// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_RATION_ELEVATION_MODULE
#define SAFE_RATION_ELEVATION_MODULE
#include "../elevation.hpp"

namespace ration {

namespace elevation {

    /**
     * @brief
     *     Confers the element at index.
     * @details
     *     Returns a modifiable reference to the element at the specified 
     *     index.  Throws an exception if the index is not currently 
     *     allotted.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum
     *     The maximum number of elements.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] stack
     *     Reference to the stack.
     * @param[in] index
     *     Reference to the index.
     * @return 
     *     The reference conferment.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Conferential<Elemental>
    GoWriteSafely(
        Referential<Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<const Natural>
            index)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!Contains(stack, index))
            throw index;
        return GoWrite(stack, index);
    }

    /**
     * @brief 
     *     Deters the element at index.
     * @details
     *     Returns a constant reference to the element at the specified 
     *     positional index.  Throws an exception if the index is not 
     *     currently allotted.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] stack
     *     Reference to the stack.
     * @param[in] index
     *     Reference to the index.
     * @return 
     *     The reference determent.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Conferential<const Elemental>
    GoReadSafely(
        Referential<const Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<const Natural>
            index)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!Contains(stack, index))
            throw index;
        return GoRead(stack, index);
    }

    /**
     * @brief 
     *     Begins read increment trajection.
     * @details
     *     Assigns to index the count offset from the beginning of the 
     *     stack, which begins at the first protracted element.  Throws
     *     an exception if there are no allotted elements.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum
     *     The maximum number of elements.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] stack
     *     Reference to the stack.
     * @param[out] index
     *     Reference to the index.
     * @param[in] count 
     *     Reference to the offset count.
     * @return
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Referential<const Natural>
    BeginReadIncrementSafely(
        Referential<const Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<Natural>
            index,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!Begins(stack, count))
            throw stack.allotment;
        return BeginReadIncrement(stack, index, count);
    }

    /**
     * @brief
     *     Begins write increment trajection.
     * @details
     *     Assigns to index the count offset from the beginning of the 
     *     stack, which begins at the first protracted element. Throws 
     *     an exception if there are no allotted elements.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] stack
     *     Reference to the stack.
     * @param[out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Referential<const Natural>
    BeginWriteIncrementSafely(
        Referential<Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<Natural>
            index,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!Begins(stack, count))
            throw stack.allotment;
        return BeginWriteIncrement(stack, index, count);
    }

    /**
     * @brief 
     *     Traverses read increment.
     * @details
     *     Increases index by count offset.  Throws an exception if the 
     *     count offset would move index beyond the end of the stack.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] stack 
     *     Reference to the stack.
     * @param[in,out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Referential<const Natural>
    TraverseReadIncrementSafely(
        Referential<const Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<Natural>
            index,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!IncrementTraverses(stack, index, count))
            throw index;
        return TraverseReadIncrement(stack, index, count);
    }

    /**
     * @brief 
     *     Traverses write increment.
     * @details
     *     Increases index by count offset.  Throws an exception if the 
     *     count offset would move index beyond the end of the stack.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] stack 
     *     Reference to the stack.
     * @param[in,out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Referential<const Natural>
    TraverseWriteIncrementSafely(
        Referential<Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<Natural>
            index,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!IncrementTraverses(stack, index, count))
            throw index;
        return TraverseWriteIncrement(stack, index, count);
    }

    /**
     * @brief 
     *     Begins read decrement trajection.
     * @details
     *     Assigns to index the count offset from the end of the stack, 
     *     which ends at the last protracted element. Throws an exception 
     *     if there are no allotted elements.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum
     *     The maximum number of elements.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] stack
     *     Reference to the stack.
     * @param[out] index
     *     Reference to the index.
     * @param[in] count 
     *     Reference to the offset count.
     * @return
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Referential<const Natural>
    BeginReadDecrementSafely(
        Referential<const Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<Natural>
            index,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!Begins(stack, count))
            throw stack.allotment;
        return BeginReadDecrement(stack, index, count);
    }

    /**
     * @brief 
     *     Begins write decrement trajection.
     * @details
     *     Assigns to index the count offset from the end of the stack, 
     *     which ends at the last protracted element. Throws an exception 
     *     if there are no allotted elements.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] stack
     *     Reference to the stack.
     * @param[out] index
     *     Reference to the index.
     * @param[in] count 
     *     Reference to the offset count.
     * @return
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Referential<const Natural>
    BeginWriteDecrementSafely(
        Referential<Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<Natural>
            index,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!Begins(stack, count))
            throw stack.allotment;
        return BeginWriteDecrement(stack, index, count);
    }

    /**
     * @brief 
     *     Traverses read decrement.
     * @details
     *     Decreases index by count offset.  Throws an exception if the 
     *     count offset would move index beyond the beginning of the stack.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] stack 
     *     Reference to the stack.
     * @param[in,out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Referential<const Natural>
    TraverseReadDecrementSafely(
        Referential<const Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<Natural>
            index,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!DecrementTraverses(stack, index, count))
            throw index;
        return TraverseReadDecrement(stack, index, count);
    }

    /**
     * @brief 
     *     Traverses read decrement.
     * @details
     *     Decreases index by count offset.  Throws an exception if the 
     *     count offset would move index beyond the beginning of the stack.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] stack 
     *     Reference to the stack.
     * @param[in,out] index
     *     Reference to the index.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the index as a constant.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    static inline Referential<const Natural>
    TraverseWriteDecrementSafely(
        Referential<Elevatory<Natural, Maximum, Elemental>>
            stack,
        Referential<Natural>
            index,
        Referential<const Natural>
            count)
    {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral<Natural>::value && is_unsigned<Natural>::value,
            "Natural:  Unsigned integer type required");
#endif
        if (!DecrementTraverses(stack, index, count))
            throw index;
        return TraverseWriteDecrement(stack, index, count);
    }

    /**
     * @brief 
     *     Vectorial read trajection implementation.
     * @details
     *     Objective table which provides safe vectorial trajection into the
     *     stack.  Use this version if performance is not stringent and 
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
        Natural Maximum,
        typename Elemental>
    constexpr Vectorial<const Elevatory<Natural, Maximum, Elemental>, Natural, const Elemental>
        SafeReadVector = {
            Comparison<Natural>,
            Contains<Natural, Maximum, Elemental>,
            GoReadSafely<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Vectorial write trajection implementation.
     * @details
     *     Objective table which provides safe vectorial trajection into the
     *     stack.  Use this version if performance is not stringent and 
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
        Natural Maximum,
        typename Elemental>
    constexpr Vectorial<Elevatory<Natural, Maximum, Elemental>, Natural, Elemental>
        SafeWriteVector = {
            Comparison<Natural>,
            Contains<Natural, Maximum, Elemental>,
            GoWriteSafely<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Scalar<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
        SafeReadIncrementScale = {
            Comparison<Natural>,
            BeginReadIncrementSafely<Natural, Maximum, Elemental>,
            TraverseReadIncrementSafely<Natural, Maximum, Elemental>,
            GoReadSafely<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Scalar<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
        SafeWriteIncrementScale = {
            Comparison<Natural>,
            BeginWriteIncrementSafely<Natural, Maximum, Elemental>,
            TraverseWriteIncrementSafely<Natural, Maximum, Elemental>,
            GoWriteSafely<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Scalar<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
        SafeReadDecrementScale = {
            Comparison<Natural>,
            BeginReadDecrementSafely<Natural, Maximum, Elemental>,
            TraverseReadDecrementSafely<Natural, Maximum, Elemental>,
            GoReadSafely<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Scalar<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
        SafeWriteDecrementScale = {
            Comparison<Natural>,
            BeginWriteDecrementSafely<Natural, Maximum, Elemental>,
            TraverseWriteDecrementSafely<Natural, Maximum, Elemental>,
            GoWriteSafely<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Lineal<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
        SafeReadLiner = {
            SafeReadIncrementScale<Natural, Maximum, Elemental>,
            SafeReadDecrementScale<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
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
    constexpr Lineal<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
        SafeWriteLiner = {
            SafeWriteIncrementScale<Natural, Maximum, Elemental>,
            SafeWriteDecrementScale<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Directional<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
        SafeReadIncrementDirection = {
            SafeReadIncrementScale<Natural, Maximum, Elemental>,
            Begins<Natural, Maximum, Elemental>,
            IncrementTraverses<Natural, Maximum, Elemental>,
            Contains<Natural, Maximum, Elemental>,
            Account<Natural, Maximum, Elemental>,
            CountIncrement<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
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
    constexpr Directional<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
        SafeWriteIncrementDirection = {
            SafeWriteIncrementScale<Natural, Maximum, Elemental>,
            Begins<Natural, Maximum, Elemental>,
            IncrementTraverses<Natural, Maximum, Elemental>,
            Contains<Natural, Maximum, Elemental>,
            Account<Natural, Maximum, Elemental>,
            CountIncrement<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Directional<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
        SafeReadDecrementDirection = {
            SafeReadDecrementScale<Natural, Maximum, Elemental>,
            Begins<Natural, Maximum, Elemental>,
            DecrementTraverses<Natural, Maximum, Elemental>,
            Contains<Natural, Maximum, Elemental>,
            Account<Natural, Maximum, Elemental>,
            CountDecrement<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Directional<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
        SafeWriteDecrementDirection = {
            SafeWriteDecrementScale<Natural, Maximum, Elemental>,
            Begins<Natural, Maximum, Elemental>,
            DecrementTraverses<Natural, Maximum, Elemental>,
            Contains<Natural, Maximum, Elemental>,
            Account<Natural, Maximum, Elemental>,
            CountDecrement<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Axial<const Elevatory<Natural, Maximum, Elemental>, Natural, Natural, const Elemental>
        SafeReadAxis = {
            SafeReadIncrementDirection<Natural, Maximum, Elemental>,
            SafeReadDecrementDirection<Natural, Maximum, Elemental>
        };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objective table which provides safe sequential trajection into 
     *     the stack.  Use this version if performance is not stringent and
     *     the index might be moved out of bounds.
     * @tparam Natural
     *     Type of natural integer for sizes.
     * @tparam Maximum 
     *     The maximum number of elements.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural Maximum,
        typename Elemental>
    constexpr Axial<Elevatory<Natural, Maximum, Elemental>, Natural, Natural, Elemental>
        SafeWriteAxis = {
            SafeWriteIncrementDirection<Natural, Maximum, Elemental>,
            SafeWriteDecrementDirection<Natural, Maximum, Elemental>
        };

}

}

#endif
