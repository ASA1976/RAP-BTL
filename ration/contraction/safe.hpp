// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef SAFE_RATION_CONTRACTION_MODULE
#define SAFE_RATION_CONTRACTION_MODULE
#include "../contraction.hpp"

namespace ration {

    namespace contraction {

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
         * @param[in] queue
         *     Reference to the queue.
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
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!Contains( queue, index ))
                throw index;
            return GoWrite( queue, index );
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
         * @param[in] queue
         *     Reference to the queue.
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
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!Contains( queue, index ))
                throw index;
            return GoRead( queue, index );
        }

         /**
         * @brief 
         *     Begins read increment trajection.
         * @details
         *     Function Template
         *     -----------------
         *     Assigns to index the count offset from the beginning of the 
         *     queue, which begins at the first protracted element.  Throws
         *     an exception if there are no allotted elements.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue
         *     Reference to the queue.
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
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadIncrementSafely(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!Begins( queue, count ))
                throw queue.allotment;
            return BeginReadIncrement( queue, index, count );
        }

        /**
         * @brief
         *     Begins write increment trajection.
         * @details
         *     Function Template
         *     -----------------
         *     Assigns to index the count offset from the beginning of the 
         *     queue, which begins at the first protracted element. Throws 
         *     an exception if there are no allotted elements.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue
         *     Reference to the queue.
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
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteIncrementSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!Begins( queue, count ))
                throw queue.allotment;
            return BeginWriteIncrement( queue, index, count );
        }

        /**
         * @brief 
         *     Traverses read increment.
         * @details
         *     Function Template
         *     -----------------
         *     Increases index by count offset.  Throws an exception if the 
         *     count offset would move index beyond the end of the queue.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
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
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseReadIncrementSafely(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!IncrementTraverses( queue, index, count ))
                throw count;
            return TraverseReadIncrement( queue, index, count );
        }

        /**
         * @brief 
         *     Traverses write increment.
         * @details
         *     Function Template
         *     -----------------
         *     Increases index by count offset.  Throws an exception if the 
         *     count offset would move index beyond the end of the queue.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
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
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseWriteIncrementSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!IncrementTraverses( queue, index, count ))
                throw index;
            return TraverseWriteIncrement( queue, index, count );
        }

        /**
         * @brief 
         *     Begins read decrement trajection.
         * @details
         *     Function Template
         *     -----------------
         *     Assigns to index the count offset from the end of the queue, 
         *     which ends at the last protracted element. Throws an exception 
         *     if there are no allotted elements.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum
         *     The maximum number of elements.
         * @tparam Elemental
         *     Type of the elements.
         * @param[in] queue
         *     Reference to the queue.
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
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginReadDecrementSafely(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!Begins( queue, count ))
                throw queue.allotment;
            return BeginReadDecrement( queue, index, count );
        }

        /**
         * @brief 
         *     Begins write decrement trajection.
         * @details
         *     Function Template
         *     -----------------
         *     Assigns to index the count offset from the end of the queue, 
         *     which ends at the last protracted element. Throws an exception 
         *     if there are no allotted elements.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue
         *     Reference to the queue.
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
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        BeginWriteDecrementSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!Begins( queue, count ))
                throw queue.allotment;
            return BeginWriteDecrement( queue, index, count );
        }

        /**
         * @brief 
         *     Traverses read decrement.
         * @details
         *     Function Template
         *     -----------------
         *     Decreases index by count offset.  Throws an exception if the 
         *     count offset would move index beyond the beginning of the queue.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
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
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseReadDecrementSafely(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!DecrementTraverses( queue, index, count ))
                throw index;
            return TraverseReadDecrement( queue, index, count );
        }

        /**
         * @brief 
         *     Traverses read decrement.
         * @details
         *     Function Template
         *     -----------------
         *     Decreases index by count offset.  Throws an exception if the 
         *     count offset would move index beyond the beginning of the queue.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
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
                Maximum,
            typename Elemental
        >
        static inline Referential< const Natural >
        TraverseWriteDecrementSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (!DecrementTraverses( queue, index, count ))
                throw index;
            return TraverseWriteDecrement( queue, index, count );
        }

        /**
         * @brief 
         *     Protracts elements to the end of the queue.
         * @details
         *     Function Template
         *     -----------------
         *     Protracts elements to the end of the queue.  This version will
         *     return false if count is zero or more elements have been 
         *     requested than are available in the queue.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
         * @param[out] index 
         *     Reference to the index.
         * @param[in] count 
         *     Reference to the count.
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
        ProtractSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (queue.resource.allotment + count > Maximum)
                return false;
            return Protract( queue, index, count );
        }

        /**
         * @brief 
         *     Retracts elements from the beginning of the queue.
         * @details
         *     Function Template
         *     -----------------
         *     Retracts elements from the beginning of the queue.  This version 
         *     returns false if count is zero or if count is larger than the
         *     number of protracted elements.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
         * @param[in] count 
         *     Reference to the count.
         * @return 
         *     Returns true if the number of requested elements were retracted.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        RetractSafely(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (count > queue.resource.allotment)
                return false;
            return Retract( queue, count );
        }

        /**
         * @brief 
         *     Tractile queue management implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe tractile queue management.  
         *     Use this version if overflowing the queue or protraction
         *     requests of zero elements are not prevented, where this version
         *     will perform the run-time checks for you.
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
        constexpr Tractile< Contractional< Natural, Maximum, Elemental >, Natural, Natural >
            SafeContractor = {
                Survey< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                ProtractSafely< Natural, Maximum, Elemental >,
                RetractSafely< Natural, Maximum, Elemental >,
                Contract< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Vectorial read trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe vectorial trajection into the
         *     queue.  Use this version if performance is not stringent and 
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
        constexpr Vectorial< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
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
         *     queue.  Use this version if performance is not stringent and 
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
        constexpr Vectorial< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
            SafeWriteVector = {
                Comparison< Natural >,
                Contains< Natural, Maximum, Elemental >,
                GoWriteSafely< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential read trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
            SafeReadIncrementScale = {
                Comparison< Natural >,
                BeginReadIncrementSafely< Natural, Maximum, Elemental >,
                TraverseReadIncrementSafely< Natural, Maximum, Elemental >,
                GoReadSafely< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential write trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
            SafeWriteIncrementScale = {
                Comparison< Natural >,
                BeginWriteIncrementSafely< Natural, Maximum, Elemental >,
                TraverseWriteIncrementSafely< Natural, Maximum, Elemental >,
                GoWriteSafely< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential read trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Scalar< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
            SafeReadDecrementScale = {
                Comparison< Natural >,
                BeginReadDecrementSafely< Natural, Maximum, Elemental >,
                TraverseReadDecrementSafely< Natural, Maximum, Elemental >,
                GoReadSafely< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential write trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Scalar< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
            SafeWriteDecrementScale = {
                Comparison< Natural >,
                BeginWriteDecrementSafely< Natural, Maximum, Elemental >,
                TraverseWriteDecrementSafely< Natural, Maximum, Elemental >,
                GoWriteSafely< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential read trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Lineal< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
            SafeReadLiner = {
                SafeReadIncrementScale< Natural, Maximum, Elemental >,
                SafeReadDecrementScale< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential write trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Lineal< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
            SafeWriteLiner = {
                SafeWriteIncrementScale< Natural, Maximum, Elemental >,
                SafeWriteDecrementScale< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential read trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
            SafeReadIncrementDirection = {
                SafeReadIncrementScale< Natural, Maximum, Elemental >,
                Begins< Natural, Maximum, Elemental >,
                IncrementTraverses< Natural, Maximum, Elemental >,
                Contains< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                CountIncrement< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential write trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
            SafeWriteIncrementDirection = {
                SafeWriteIncrementScale< Natural, Maximum, Elemental >,
                Begins< Natural, Maximum, Elemental >,
                IncrementTraverses< Natural, Maximum, Elemental >,
                Contains< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                CountIncrement< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential read trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Directional< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
            SafeReadDecrementDirection = {
                SafeReadDecrementScale< Natural, Maximum, Elemental >,
                Begins< Natural, Maximum, Elemental >,
                DecrementTraverses< Natural, Maximum, Elemental >,
                Contains< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                CountDecrement< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential write trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Directional< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
            SafeWriteDecrementDirection = {
                SafeWriteDecrementScale< Natural, Maximum, Elemental >,
                Begins< Natural, Maximum, Elemental >,
                DecrementTraverses< Natural, Maximum, Elemental >,
                Contains< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                CountDecrement< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential read trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Axial< const Contractional< Natural, Maximum, Elemental >, Natural, Natural, const Elemental >
            SafeReadAxis = {
                SafeReadIncrementDirection< Natural, Maximum, Elemental >,
                SafeReadDecrementDirection< Natural, Maximum, Elemental >
            };

        /**
         * @brief 
         *     Sequential write trajection implementation.
         * @details
         *     Objectification Template
         *     ------------------------
         *     Objective table which provides safe sequential trajection into 
         *     the queue.  Use this version if performance is not stringent and
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
            typename Elemental
        >
        constexpr Axial< Contractional< Natural, Maximum, Elemental >, Natural, Natural, Elemental >
            SafeWriteAxis = {
                SafeWriteIncrementDirection< Natural, Maximum, Elemental >,
                SafeWriteDecrementDirection< Natural, Maximum, Elemental >
            };

    }

}

#endif