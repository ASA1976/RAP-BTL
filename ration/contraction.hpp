// � 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_CONTRACTION_MODULE
#define RATION_CONTRACTION_MODULE
#include "../ration.hpp"
#include "../traction.hpp"
#include "../trajection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <type_traits>
#endif

namespace ration {

    /**
     * @brief
     *     Queue rationing.
     * @details
     *     Association
     *     -----------
     *     Array based queue rationing conformity, initialization facility, 
     *     tractile management and sequential trajection implementations.
     */
    namespace contraction {

        using ::location::Referential;
        using ::location::Conferential;
        using ::trajection::Vectorial;
        using ::trajection::Scalar;
        using ::trajection::Lineal;
        using ::trajection::Directional;
        using ::trajection::Axial;
        using ::traction::Tractile;
        using ::comparison::Comparison;

        /**
         * @brief
         *     Queue resource conformity.
         * @details
         *     Conformation Template
         *     ---------------------
         *     Type definition which contains an offset to the first queue 
         *     element and a memory resource definition.
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
        struct Contractional {

            Natural
                first; /**< Offset to the first element in the queue. */

            Resourceful< Natural, Maximum, Elemental >
                resource; /**< Memory resource. */

        };

        /**
         * @brief 
         *     Initialized queue.
         * @details 
         *     Information Template
         *     --------------------
         *     Initialized queue value which can be used to initialize an 
         *     instance of the same queue type.
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
        constexpr Contractional< Natural, Maximum, Elemental >
            InitializedQueue = {
                0,
                InitializedResource< Natural, Maximum, Elemental >
            };

        /**
         * @brief
         *     Check if index is an allotted queue position.
         * @details
         *     Function Template
         *     -----------------
         *     Checks if index is a currently allotted queue element.
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
            const Natural
                terminal = queue.first + queue.resource.allotment;
            if (index < queue.first) {
                if (terminal <= Maximum)
                    return false;
                if (index >= terminal - Maximum)
                    return false;
            } else {
                if (index >= terminal)
                    return false;
            }
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
        GoWrite(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue,
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
            return Confer( queue.resource.source[index] );
        }

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
        GoRead(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            return Deter( queue.resource.source[index] );
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
         *     Checks if sequential trajection can begin.
         * @details
         *     Function Template
         *     -----------------
         *     Checks if sequential trajection can begin at the specified offset
         *     count.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue
         *     Reference to the queue.
         * @param[in] count
         *     Reference to the offset count.
         * @return 
         *     True if the offset can be reached from the either the increment
         *     or decrement beginnings.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Begins(
            Referential< const Contractional< Natural, Maximum, Elemental > >
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
            return count < queue.resource.allotment;
        }

        /**
         * @brief
         *     Begins read increment trajection.
         * @details
         *     Function Template
         *     -----------------
         *     Assigns to index the count offset from the beginning of the 
         *     queue, which begins at the first protracted element.
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
        BeginReadIncrement(
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
            index = queue.first + count;
            if (index >= Maximum)
                index -= Maximum;
            return index;
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
         *     queue, which begins at the first protracted element.
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
        BeginWriteIncrement(
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
            index = queue.first + count;
            if (index >= Maximum)
                index -= Maximum;
            return index;
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
         *     Checks if sequential trajection can continue.
         * @details
         *     Function Template
         *     -----------------
         *     Checks if sequential trajection can traverse from index to the
         *     specified count offset.
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
         * @param[in] count
         *     Reference to the offset count.
         * @return 
         *     True if the offset can be reached from index.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        IncrementTraverses(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            Natural
                extent;
            extent = queue.first + queue.resource.allotment;
            if (index < queue.first) {
                if (extent <= Maximum)
                    return false;
                return index + count < extent - Maximum;
            } else {
                return index + count < extent;
            }
        }

        /**
         * @brief 
         *     Traverses read increment.
         * @details
         *     Function Template
         *     -----------------
         *     Increases index by count offset.
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
        TraverseReadIncrement(
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
            Natural
                offset;
            offset = index + count;
            return index = offset < Maximum ? offset : offset - Maximum;
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
         *     Increases index by count offset.
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
        TraverseWriteIncrement(
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
            Natural
                offset;
            offset = index + count;
            return index = offset < Maximum ? offset : offset - Maximum;
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
         *     which ends at the last protracted element.
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
        BeginReadDecrement(
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
            Natural
                extent;
            extent = queue.first + queue.resource.allotment;
            if (extent > Maximum)
                return index = extent - Maximum - 1 - count;
            return extent - 1 - count;
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
         *     which ends at the last protracted element.
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
        BeginWriteDecrement(
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
            Natural
                extent;
            extent = queue.first + queue.resource.allotment;
            if (extent > Maximum)
                return index = extent - Maximum - 1 - count;
            return extent - 1 - count;
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
         *     Checks if sequential trajection can continue.
         * @details
         *     Function Template
         *     -----------------
         *     Checks if sequential trajection can traverse from index to the
         *     specified count offset.
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
         * @param[in] count
         *     Reference to the offset count.
         * @return 
         *     True if the offset can be reached from index.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        DecrementTraverses(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue,
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
            if (count > index)
                return Maximum + index - count >= queue.first;
            return index - count >= queue.first;
        }

        /**
         * @brief 
         *     Traverses read decrement.
         * @details
         *     Function Template
         *     -----------------
         *     Decreases index by count offset.
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
        TraverseReadDecrement(
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
            return index = count > index ? Maximum + index - count : index - count;
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
         *     Traverses write decrement.
         * @details
         *     Function Template
         *     -----------------
         *     Decreases index by count offset.
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
        TraverseWriteDecrement(
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
            return index = count > index ? Maximum + index - count : index - count;
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
         *     Initializes the queue.
         * @details
         *     Function Template
         *     -----------------
         *     Initializes the queue allotment and first index to zero.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
         * @return 
         *     A reference to the queue.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Referential< Contractional< Natural, Maximum, Elemental > >
        Initialize(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return queue = InitializedQueue< Natural, Maximum, Elemental >;
        }

        /**
         * @brief 
         *     Empties the queue.
         * @details
         *     Function Template
         *     -----------------
         *     Retracts all protracted elements in the queue.  Returns true only
         *     if there were allotted elements in the queue before the call.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
         * @return 
         *     True if the queue was altered by this operation.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Contract(
            Referential< Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!queue.resource.allotment)
                return false;
            Initialize( queue );
            return true;
        }

        /**
         * @brief 
         *     Returns the maximum size of the queue.
         * @details
         *     Function Template
         *     -----------------
         *     Returns the maximum size of the queue.  This function may or may
         *     not incur run-time overhead depending on the invocation context.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
         * @return 
         *     The maximum number of queue elements.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        Survey(
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue
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
         *     Returns the number of protracted elements in the queue.
         * @details
         *     Function Template
         *     -----------------
         *     Returns the number of protracted elements in the queue which
         *     defaults to zero if the queue was properly initialized.
         * @tparam Natural
         *     Type of natural integer for sizes.
         * @tparam Maximum 
         *     The maximum number of elements.
         * @tparam Elemental 
         *     Type of the elements.
         * @param[in] queue 
         *     Reference to the queue.
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
            Referential< const Contractional< Natural, Maximum, Elemental > >
                queue
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return queue.resource.allotment;
        }

        /**
         * @brief 
         *     Returns the number of protracted elements __after__ index.
         * @details
         *     Function Template
         *     -----------------
         *     Returns the number of protracted elements in the queue __after__
         *     the specified index (does not include the element at index).
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
         *     The number of elements __after__ index.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        CountIncrement(
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
            return queue.resource.allotment - 1 - index;
        }

        /**
         * @brief 
         *     Returns the number of protracted elements __before__ index.
         * @details
         *     Function Template
         *     -----------------
         *     Returns the number of protracted elements in the queue 
         *     __before__ the specified index (does not include the element at
         *     index).
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
         *     The number of elements __before__ index.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        CountDecrement(
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
            return index;
        }

        /**
         * @brief 
         *     Protracts elements to the end of the queue.
         * @details
         *     Function Template
         *     -----------------
         *     Protracts elements to the end of the queue.  This version does
         *     not verify if count is zero or if more elements have been 
         *     requested than are available in the queue.  Use this version only
         *     if stringent performance is required.
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
         *     Always returns true.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Protract(
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
            index = queue.first + queue.resource.allotment;
            if (index >= Maximum)
                index -= Maximum;
            queue.resource.allotment += count;
            return true;
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
         *     does not verify if count is zero or if count is larger than the 
         *     number of protracted elements.  Use this version only if 
         *     stringent performance is required.
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
         *     Always returns true.
         */
        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline bool
        Retract(
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
            queue.resource.allotment -= count;
            queue.first += count;
            if (queue.first >= Maximum)
                queue.first -= Maximum;
            return true;
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
         *     Objective table which provides fast tractile queue management.  
         *     Use this version if performance is stringent, however care should
         *     be taken to understand how each function works in order to 
         *     prevent overflowing the queue or attempting to protract zero
         *     elements, which could cause bugs.
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
            Contractor = {
                Survey< Natural, Maximum, Elemental >,
                Account< Natural, Maximum, Elemental >,
                Protract< Natural, Maximum, Elemental >,
                Retract< Natural, Maximum, Elemental >,
                Contract< Natural, Maximum, Elemental >
            };

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
         *     Objective table which provides fast vectorial trajection into the
         *     queue.  Use this version if performance is stringent and requests
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
        constexpr Vectorial< const Contractional< Natural, Maximum, Elemental >, Natural, const Elemental >
            ReadVector = {
                Comparison< Natural >,
                Contains< Natural, Maximum, Elemental >,
                GoRead< Natural, Maximum, Elemental >
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
         *     Objective table which provides fast vectorial trajection into the
         *     queue.  Use this version if performance is stringent and requests
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
        constexpr Vectorial< Contractional< Natural, Maximum, Elemental >, Natural, Elemental >
            WriteVector = {
                Comparison< Natural >,
                Contains< Natural, Maximum, Elemental >,
                GoWrite< Natural, Maximum, Elemental >
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            ReadIncrementScale = {
                Comparison< Natural >,
                BeginReadIncrement< Natural, Maximum, Elemental >,
                TraverseReadIncrement< Natural, Maximum, Elemental >,
                GoRead< Natural, Maximum, Elemental >
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            WriteIncrementScale = {
                Comparison< Natural >,
                BeginWriteIncrement< Natural, Maximum, Elemental >,
                TraverseWriteIncrement< Natural, Maximum, Elemental >,
                GoWrite< Natural, Maximum, Elemental >
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            ReadDecrementScale = {
                Comparison< Natural >,
                BeginReadDecrement< Natural, Maximum, Elemental >,
                TraverseReadDecrement< Natural, Maximum, Elemental >,
                GoRead< Natural, Maximum, Elemental >
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            WriteDecrementScale = {
                Comparison< Natural >,
                BeginWriteDecrement< Natural, Maximum, Elemental >,
                TraverseWriteDecrement< Natural, Maximum, Elemental >,
                GoWrite< Natural, Maximum, Elemental >
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            ReadLiner = {
                ReadIncrementScale< Natural, Maximum, Elemental >,
                ReadDecrementScale< Natural, Maximum, Elemental >
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            WriteLiner = {
                WriteIncrementScale< Natural, Maximum, Elemental >,
                WriteDecrementScale< Natural, Maximum, Elemental >
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            ReadIncrementDirection = {
                ReadIncrementScale< Natural, Maximum, Elemental >,
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            WriteIncrementDirection = {
                WriteIncrementScale< Natural, Maximum, Elemental >,
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            ReadDecrementDirection = {
                ReadDecrementScale< Natural, Maximum, Elemental >,
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            WriteDecrementDirection = {
                WriteDecrementScale< Natural, Maximum, Elemental >,
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            ReadAxis = {
                ReadIncrementDirection< Natural, Maximum, Elemental >,
                ReadDecrementDirection< Natural, Maximum, Elemental >
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
         *     Objective table which provides fast sequential trajection into 
         *     the queue.  Use this version if performance is stringent and 
         *     the index is prevented from being moved out of bounds.
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
            WriteAxis = {
                WriteIncrementDirection< Natural, Maximum, Elemental >,
                WriteDecrementDirection< Natural, Maximum, Elemental >
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
