// � 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ORDINATION_MODULE
#define ORDINATION_MODULE
#include "trajection.hpp"
#include "comparison.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

/**
 * @brief         
 *     Array space trajection implementation.
 * @details       
 *     Association
 *     -----------
 *     Implements vectorial and sequential trajection through an array of 
 *     elements.
 */
namespace ordination {

    using ::location::Locational;
    using ::location::Referential;
    using ::location::Conferential;
    using ::trajection::Vectorial;
    using ::trajection::Scalar;
    using ::trajection::Lineal;
    using ::trajection::Directional;
    using ::trajection::Axial;
    using ::comparison::Comparison;

    /**
     * @brief
     *     Modifiable array type.
     * @details
     *     Conformation Template
     *     ---------------------
     *     This type alias is used to represent an array of modifiable
     *     elements.
     * @tparam Elemental
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    using WriteOrdinal = Elemental[Length];

    /**
     * @brief
     *     Constant array type.
     * @details
     *     Conformation Template
     *     ---------------------
     *     This type alias is used to represent an array of constant
     *     elements.
     * @tparam Elemental
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    using ReadOrdinal = const Elemental[Length];

    /**
     * @brief
     *     Modifiable array sequential position type.
     * @details
     *     Conformation Template
     *     ---------------------
     *     This type alias is used to represent a position in modifiable
     *     array sequential trajections.
     * @tparam Elemental
     *     Type of the elements.
     */
    template <
        typename Elemental
    >
    using WritePositional = Locational< Elemental >;

    /**
     * @brief
     *     Constant array sequential position type.
     * @details
     *     Conformation Template
     *     ---------------------
     *     This type alias is used to represent a position in constant
     *     array sequential trajections.
     * @tparam Elemental
     *     Type of the elements.
     */
    template <
        typename Elemental
    >
    using ReadPositional = Locational< const Elemental >;

    /**
     * @brief
     *     Check if index is within the array.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if index is within the array.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
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
        Referential< const Elemental[Length] >
            array,
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
     *     Check if index is within the array.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if index is within the array.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
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
        Referential< const Elemental[Length] >
            array,
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
        if (index < 0)
            throw index;
        return ContainsIndex( array, index );
    }

    /**
     * @brief 
     *     Confers the element at index.
     * @details
     *     Function Template
     *     -----------------
     *     Returns a reference to the element at the specified index.  This 
     *     version does not check if index is within the array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
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
    NaturalGo(
        Referential< Elemental[Length] >
            array,
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
        return Confer( array[index] );
    }

    /**
     * @brief 
     *     Confers the element at index.
     * @details
     *     Function Template
     *     -----------------
     *     Returns a reference to the element at the specified index.  This 
     *     version will throw an exception if index is not within the array
     *     bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
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
    NaturalGoSafely(
        Referential< Elemental[Length] >
            array,
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
        if (!SafelyContainsIndex( array, index ))
            throw index;
        return NaturalGo( array, index );
    }

    /**
     * @brief
     *     Check if position is within the array.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if position is within the array.  This version does not check
     *     if position is null.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
     * @return
     *     True if position is within the array bounds.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    ContainsPosition(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return position >= array && position <= array + Length - 1;
    }

    /**
     * @brief
     *     Check if position is within the array.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if position is within the array.  This version throws an 
     *     exception if position is null.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
     * @return
     *     True if position is within the array bounds.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    ContainsPositionChecksForNull(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Contains = ContainsPosition< Natural, Length, Elemental >;
        if (!position)
            throw position;
        return Contains( array, position );
    }

    /**
     * @brief 
     *     Confers the element at position.
     * @details
     *     Function Template
     *     -----------------
     *     Returns a reference to the element at the specified position.  This
     *     version does not check if position is within the array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
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
    PositionalGo(
        Referential< Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
        using ::location::Refer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return Refer( position );
    }

    /**
     * @brief 
     *     Confers the element at position.
     * @details
     *     Function Template
     *     -----------------
     *     Returns a reference to the element at the specified position.  This 
     *     version will throw an exception if position is null or is not within 
     *     the array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
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
    PositionalGoSafely(
        Referential< Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        static auto&
            Contains = ContainsPositionChecksForNull< Natural, Length, Elemental >;
        static auto&
            Go = PositionalGo< Natural, Length, Elemental >;
        if (!Contains( array, position ))
            throw position;
        return Go( array, position );
    }

    /**
     * @brief
     *     Checks if sequential trajection can begin.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can begin at the specified offset
     *     count.  This version offers less integrity than SafelyBegins when
     *     the Natural type specifier is allowed to be a signed integer.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if count is less than length.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    Begins(
        Referential< const Elemental[Length] >
            array,
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
     *     count.  This version offers more integrity when the Natural type
     *     specifier is allowed to be a signed integer.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if count is less than length.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    SafelyBegins(
        Referential< const Elemental[Length] >
            array,
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
        if (count < 0)
            throw count;
        return Begins( array, count );
    }

    /**
     * @brief
     *     Begins increment trajection.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns to position the element address at count positive offset from
     *     the base element of the array.  This version does not check if count
     *     would move position beyond the array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[out] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the position as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginIncrement(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position,
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
        return position = array + count;
    }

    /**
     * @brief
     *     Begins increment trajection.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns to position the element address at count positive offset from
     *     the base element of the array.  This version throws an exception if
     *     count would move position beyond the array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[out] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the position as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginIncrementSafely(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position,
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
        if (!SafelyBegins( array, count ))
            throw count;
        return BeginIncrement( array, position, count );
    }

    /**
     * @brief
     *     Begins decrement trajection.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns to position the element address at count negative offset from
     *     the last element of the array.  This version does not check if count
     *     would move position beyond the array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[out] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the position as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginDecrement(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position,
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
        return position = array + Length - 1 - count;
    }

    /**
     * @brief
     *     Begins decrement trajection.
     * @details
     *     Function Template
     *     -----------------
     *     Assigns to position the element address at count negative offset from
     *     the last element of the array.  This version throws an exception if
     *     count would move position beyond the array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[out] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the position as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    BeginDecrementSafely(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position,
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
        if (!SafelyBegins( array, count ))
            throw count;
        return BeginDecrement( array, position, count );
    }

    /**
     * @brief
     *     Checks if sequential trajection can continue.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can traverse from position to the
     *     specified count offset.  This version does not check if the pointer
     *     is null.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the offset can be reached from position.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraverses(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position,
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
        return count < Length && position < array + Length - count;
    }

    /**
     * @brief
     *     Checks if sequential trajection can continue.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can traverse from position to the
     *     specified count offset.  This version throws an exception if the 
     *     pointer is null or count is less than zero.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the offset can be reached from position.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    IncrementTraversesSafely(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position,
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
        if (!position)
            throw position;
        if (count < 0)
            throw count;
        return IncrementTraverses( array, position, count );
    }

    /**
     * @brief
     *     Checks if sequential trajection can continue.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can traverse from position to the
     *     specified count offset.  This version does not check if the pointer
     *     is null.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the offset can be reached from position.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraverses(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position,
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
        return count < Length && position > array + Length - 1 - count;
    }

    /**
     * @brief
     *     Checks if sequential trajection can continue.
     * @details
     *     Function Template
     *     -----------------
     *     Checks if sequential trajection can traverse from position to the
     *     specified count offset.  This version throws an exception if the 
     *     pointer is null.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     True if the offset can be reached from position.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline bool
    DecrementTraversesSafely(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position,
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
        if (!position)
            throw position;
        if (count < 0)
            throw count;
        return DecrementTraverses( array, position, count );
    }

    /**
     * @brief 
     *     Traverses increment.
     * @details
     *     Function Template
     *     -----------------
     *     Increases position by count offset.  This version does not check if
     *     position is null or would be moved out of the array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[in,out] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the position as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseIncrement(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position,
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
        return position += count;
    }

    /**
     * @brief 
     *     Traverses increment.
     * @details
     *     Function Template
     *     -----------------
     *     Increases position by count offset.  This version throws an exception
     *     if position is null or would be moved out of array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[in,out] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the position as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseIncrementSafely(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position,
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
        if (!IncrementTraversesSafely( array, position, count ))
            throw count;
        return TraverseIncrement( array, position, count );
    }

    /**
     * @brief 
     *     Traverses decrement.
     * @details
     *     Function Template
     *     -----------------
     *     Decreases position by count offset.  This version does not check if
     *     position is null or would be moved out of the array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[in,out] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the position as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseDecrement(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position,
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
        return position -= count;
    }

    /**
     * @brief 
     *     Traverses decrement.
     * @details
     *     Function Template
     *     -----------------
     *     Decreases position by count offset.  This version throws an exception
     *     if position is null or would be moved out of array bounds.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[in,out] position
     *     Reference to the position.
     * @param[in] count
     *     Reference to the offset count.
     * @return 
     *     A reference to the position as a constant.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Referential< const Locational< Elemental > >
    TraverseDecrementSafely(
        Referential< Elemental[Length] >
            array,
        Referential< Locational< Elemental > >
            position,
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
        if (!DecrementTraversesSafely( array, position, count ))
            throw count;
        return TraverseDecrement( array, position, count );
    }

    /**
     * @brief 
     *     Returns the number of elements in the array.
     * @details
     *     Function Template
     *     -----------------
     *     Returns the number of elements in the array.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @return 
     *     The number of elements in the array.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    Account(
        Referential< Elemental[Length] >
            array
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
     *     Returns the number of elements in the array __after__ position.
     * @details
     *     Function Template
     *     -----------------
     *     Returns the number of elements in the array __after__ the specified
     *     position (does not include the element at position).
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
     * @return 
     *     The number of elements __after__ position.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    CountIncrement(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return static_cast< Natural >(array + Length - position);
    }

    /**
     * @brief 
     *     Returns the number of elements in the array __before__ position.
     * @details
     *     Function Template
     *     -----------------
     *     Returns the number of elements in the array __before__ the specified
     *     position (does not include the element at position).
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     * @param[in] array 
     *     Reference to the array.
     * @param[in] position
     *     Reference to the position.
     * @return 
     *     The number of elements __before__ position.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    static inline Natural
    CountDecrement(
        Referential< const Elemental[Length] >
            array,
        Referential< const Locational< Elemental > >
            position
    ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
        using namespace ::std;
        static_assert(
            is_integral< Natural >::value && is_unsigned< Natural >::value,
            "Natural:  Unsigned integer type required"
        );
#endif
        return static_cast< Natural >(position - array);
    }

    /**
     * @brief 
     *     Vectorial read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides vectorial trajection into the array.
     *     Use this version if performance is stringent and requests for invalid 
     *     index positions will not occur, as this version does not perform any 
     *     run-time checks.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Elemental[Length], Natural, const Elemental >
    ReadVector = {
        ContainsIndex< Natural, Length, const Elemental >,
        NaturalGo< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Vectorial read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides vectorial trajection into the array.
     *     Use this version if performance is not stringent and requests for 
     *     invalid index positions might occur, as this version does perform 
     *     run-time checks.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< const Elemental[Length], Natural, const Elemental >
    SafeReadVector = {
        ContainsIndex< Natural, Length, const Elemental >,
        NaturalGoSafely< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Vectorial write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides vectorial trajection into the array.
     *     Use this version if performance is stringent and requests for invalid 
     *     index positions will not occur, as this version does not perform any 
     *     run-time checks.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< Elemental[Length], Natural, Elemental >
    WriteVector = {
        ContainsIndex< Natural, Length, Elemental >,
        NaturalGo< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Vectorial write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides vectorial trajection into the array.
     *     Use this version if performance is not stringent and requests for 
     *     invalid index positions might occur, as this version does perform 
     *     run-time checks.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Vectorial< Elemental[Length], Natural, Elemental >
    SafeWriteVector = {
        ContainsIndex< Natural, Length, Elemental >,
        NaturalGoSafely< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if performance is stringent and run-time
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    ReadIncrementScale = {
        Comparison< Locational< const Elemental > >,
        BeginIncrement< Natural, Length, const Elemental >,
        TraverseIncrement< Natural, Length, const Elemental >,
        PositionalGo< Natural, Length, const Elemental >,
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if run-time checks are necessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    SafeReadIncrementScale = {
        Comparison< Locational< const Elemental > >,
        BeginIncrementSafely< Natural, Length, const Elemental >,
        TraverseIncrementSafely< Natural, Length, const Elemental >,
        PositionalGoSafely< Natural, Length, const Elemental >,
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if performance is stringent and run-time
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    WriteIncrementScale = {
        Comparison< Locational< Elemental > >,
        BeginIncrement< Natural, Length, Elemental >,
        TraverseIncrement< Natural, Length, Elemental >,
        PositionalGo< Natural, Length, Elemental >,
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if run-time checks are necessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteIncrementScale = {
        Comparison< Locational< Elemental > >,
        BeginIncrementSafely< Natural, Length, Elemental >,
        TraverseIncrementSafely< Natural, Length, Elemental >,
        PositionalGoSafely< Natural, Length, Elemental >,
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection through
     *     an array.  Use this version if performance is stringent and run-time
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    ReadDecrementScale = {
        Comparison< Locational< const Elemental > >,
        BeginDecrement< Natural, Length, const Elemental >,
        TraverseDecrement< Natural, Length, const Elemental >,
        PositionalGo< Natural, Length, const Elemental >,
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if run-time checks are necessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    SafeReadDecrementScale = {
        Comparison< Locational< const Elemental > >,
        BeginDecrementSafely< Natural, Length, const Elemental >,
        TraverseDecrementSafely< Natural, Length, const Elemental >,
        PositionalGoSafely< Natural, Length, const Elemental >,
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection through
     *     an array.  Use this version if performance is stringent and run-time
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    WriteDecrementScale = {
        Comparison< Locational< Elemental > >,
        BeginDecrement< Natural, Length, Elemental >,
        TraverseDecrement< Natural, Length, Elemental >,
        PositionalGo< Natural, Length, Elemental >,
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if run-time checks are necessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Scalar< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteDecrementScale = {
        Comparison< Locational< Elemental > >,
        BeginDecrementSafely< Natural, Length, Elemental >,
        TraverseDecrementSafely< Natural, Length, Elemental >,
        PositionalGoSafely< Natural, Length, Elemental >,
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection through an 
     *     array.  Use this version if performance is stringent and run-time 
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    ReadLiner = {
        ReadIncrementScale< Natural, Length, Elemental >,
        ReadDecrementScale< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection through an 
     *     array.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
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
     *     Objective table which provides sequential trajection through an 
     *     array.  Use this version if performance is stringent and run-time 
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    WriteLiner = {
        WriteIncrementScale< Natural, Length, Elemental >,
        WriteDecrementScale< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection through an 
     *     array.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Lineal< Elemental[Length], Locational< Elemental >, Natural, Elemental >
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
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if performance is stringent and run-time
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    ReadIncrementDirection = {
        ReadIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        IncrementTraverses< Natural, Length, const Elemental >,
        ContainsPosition< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountIncrement< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if run-time checks are necessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    SafeReadIncrementDirection = {
        SafeReadIncrementScale< Natural, Length, Elemental >,
        SafelyBegins< Natural, Length, const Elemental >,
        IncrementTraversesSafely< Natural, Length, const Elemental >,
        ContainsPositionChecksForNull< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountIncrement< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if performance is stringent and run-time
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    WriteIncrementDirection = {
        WriteIncrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        IncrementTraverses< Natural, Length, Elemental >,
        ContainsPosition< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountIncrement< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential positive trajection through
     *     an array.  Use this version if run-time checks are necessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteIncrementDirection = {
        SafeWriteIncrementScale< Natural, Length, Elemental >,
        SafelyBegins< Natural, Length, Elemental >,
        IncrementTraversesSafely< Natural, Length, Elemental >,
        ContainsPositionChecksForNull< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountIncrement< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection through
     *     an array.  Use this version if performance is stringent and run-time
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    ReadDecrementDirection = {
        ReadDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, const Elemental >,
        DecrementTraverses< Natural, Length, const Elemental >,
        ContainsPosition< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountDecrement< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection through
     *     an array.  Use this version if run-time checks are necessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
    SafeReadDecrementDirection = {
        SafeReadDecrementScale< Natural, Length, Elemental >,
        SafelyBegins< Natural, Length, const Elemental >,
        DecrementTraversesSafely< Natural, Length, const Elemental >,
        ContainsPositionChecksForNull< Natural, Length, const Elemental >,
        Account< Natural, Length, const Elemental >,
        CountDecrement< Natural, Length, const Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection through
     *     an array.  Use this version if performance is stringent and run-time
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    WriteDecrementDirection = {
        WriteDecrementScale< Natural, Length, Elemental >,
        Begins< Natural, Length, Elemental >,
        DecrementTraverses< Natural, Length, Elemental >,
        ContainsPosition< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountDecrement< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential write trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential negative trajection through
     *     an array.  Use this version if run-time checks are necessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Directional< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteDecrementDirection = {
        SafeWriteDecrementScale< Natural, Length, Elemental >,
        SafelyBegins< Natural, Length, Elemental >,
        DecrementTraversesSafely< Natural, Length, Elemental >,
        ContainsPositionChecksForNull< Natural, Length, Elemental >,
        Account< Natural, Length, Elemental >,
        CountDecrement< Natural, Length, Elemental >
    };

    /**
     * @brief 
     *     Sequential read trajection implementation.
     * @details
     *     Objectification Template
     *     ------------------------
     *     Objective table which provides sequential trajection through an 
     *     array.  Use this version if performance is stringent and run-time 
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
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
     *     Objective table which provides sequential trajection through an 
     *     array.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< const Elemental[Length], Locational< const Elemental >, Natural, const Elemental >
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
     *     Objective table which provides sequential trajection through an 
     *     array.  Use this version if performance is stringent and run-time 
     *     checks are unnecessary.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< Elemental[Length], Locational< Elemental >, Natural, Elemental >
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
     *     Objective table which provides sequential trajection through an 
     *     array.  Use this version if performance is not stringent and the 
     *     pointer is not prevented from being null.
     * @tparam Natural
     *     Type of natural integer.
     * @tparam Length
     *     The length of the array.
     * @tparam Elemental 
     *     Type of the elements.
     */
    template <
        typename Natural,
        Natural
            Length,
        typename Elemental
    >
    constexpr Axial< Elemental[Length], Locational< Elemental >, Natural, Elemental >
    SafeWriteAxis = {
        SafeWriteIncrementDirection< Natural, Length, Elemental >,
        SafeWriteDecrementDirection< Natural, Length, Elemental >
    };

}

#endif
