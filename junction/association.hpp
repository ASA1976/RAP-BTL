// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_ASSOCIATION_MODULE
#define JUNCTION_ASSOCIATION_MODULE
#include "../junction.hpp"
#include "../association.hpp"

namespace junction {

    /**
     * @brief         
     *     Linked map management and trajection implementation.
     * @details       
     *     Association
     *     -----------
     *     Linked map management and trajection implementation.
     */
    namespace association {

        using ::association::Associative;
        using ::association::Complementary;

        /**
         * @brief 
         *     Linked map node conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a linked map node.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Connective,
            typename Correlative,
            typename Evaluative
        >
        using AssociativelyNodal = Nodal< Connective, Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map node conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a singly linked map node.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Correlative,
            typename Evaluative
        >
        using AssociativelySingleNodal = SinglyNodal< Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map node conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a doubly linked map node.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Correlative,
            typename Evaluative
        >
        using AssociativelyDoubleNodal = DoublyNodal< Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map position conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a linked map position.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Connective,
            typename Correlative,
            typename Evaluative
        >
        using AssociativelyPositional = Positional< Connective, Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map position conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a singly linked map 
         *     position.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Correlative,
            typename Evaluative
        >
        using AssociativelySinglePositional = SinglyPositional< Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map position conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a doubly linked map 
         *     position.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Correlative,
            typename Evaluative
        >
        using AssociativelyDoublePositional = DoublyPositional< Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a linked map.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        using AssociativelyJunctive = Junctive< Connective, Natural, Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a singly linked map.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        using AssociativelySingleJunctive = SinglyJunctive< Natural, Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a doubly linked map.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        using AssociativelyDoubleJunctive = DoublyJunctive< Natural, Complementary< Correlative, Evaluative > >;

        /**
         * @brief
         *     Linked map node management classifier.
         * @details
         *     Classification Template
         *     -----------------------
         *     This type is used to manage linked map nodes, including enforcement
         *     of recycling policy.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        using AssociativelyAdjunctive = Adjunctive< Connective, Natural, Complementary< Correlative, Evaluative > >;

        /**
         * @brief
         *     Linked map node management classifier.
         * @details
         *     Classification Template
         *     -----------------------
         *     This type is used to manage singly linked map nodes, including 
         *     enforcement of recycling policy.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        using AssociativelySingleAdjunctive = SinglyAdjunctive< Natural, Complementary< Correlative, Evaluative > >;

        /**
         * @brief
         *     Linked map node management classifier.
         * @details
         *     Classification Template
         *     -----------------------
         *     This type is used to manage doubly linked map nodes, including 
         *     enforcement of recycling policy.
         * @tparam Connective
         *     Type of the node linkage.
         * @tparam Natural
         *     Type of unsigned integer.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        using AssociativelyDoubleAdjunctive = DoublyAdjunctive< Natural, Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a singly connective map node
         *     link.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Correlative,
            typename Evaluative
        >
        using SingleComplementary = SinglyLinked< Complementary< Correlative, Evaluative > >;

        /**
         * @brief 
         *     Linked map conformity.
         * @details  
         *     Conformation Template
         *     ---------------------
         *     This type alias is used to represent a doubly connective map node
         *     link.
         * @tparam Correlative
         *     Type of the relator keys.
         * @tparam Evaluative
         *     Type of the value elements.
         */
        template <
            typename Correlative,
            typename Evaluative
        >
        using DoubleComplementary = DoublyLinked< Complementary< Correlative, Evaluative > >;

        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        static inline Conferential< const Correlative >
        GoReadRelator(
            Referential< const AssociativelyJunctive< Connective, Natural, Correlative, Evaluative > >
                map,
            Referential< const AssociativelyPositional< Connective, Correlative, Evaluative > >
                position
        ) {
            using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Confer( GoRead( map, position ).to.relator );
        }

        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        static inline Conferential< const Correlative >
        GoReadRelatorSafely(
            Referential< const AssociativelyJunctive< Connective, Natural, Correlative, Evaluative > >
                map,
            Referential< const AssociativelyPositional< Connective, Correlative, Evaluative > >
                position
        ) {
            using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!ContainsCheckSafely( map, position ))
                throw position;
            return GoReadRelator( map, position );
        }

        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        static inline Conferential< const Evaluative >
        GoReadElement(
            Referential< const AssociativelyJunctive< Connective, Natural, Correlative, Evaluative > >
                map,
            Referential< const AssociativelyPositional< Connective, Correlative, Evaluative > >
                position
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Confer( GoRead( map, position ).to.value );
        }

        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        static inline Conferential< const Evaluative >
        GoReadElementSafely(
            Referential< const AssociativelyJunctive< Connective, Natural, Correlative, Evaluative > >
                map,
            Referential< const AssociativelyPositional< Connective, Correlative, Evaluative > >
                position
        ) {
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!ContainsCheckSafely( map, position ))
                throw position;
            return GoReadElement( map, position );
        }

        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        static inline Conferential< Evaluative >
        GoWriteElement(
            Referential< AssociativelyJunctive< Connective, Natural, Correlative, Evaluative > >
                map,
            Referential< const AssociativelyPositional< Connective, Correlative, Evaluative > >
                position
        ) {
            using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            return Confer( GoWrite( map, position ).to.value );
        }

        template <
            typename Connective,
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        static inline Conferential< Evaluative >
        GoWriteElementSafely(
            Referential< AssociativelyJunctive< Connective, Natural, Correlative, Evaluative > >
                map,
            Referential< const AssociativelyPositional< Connective, Correlative, Evaluative > >
                position
        ) {
            using ::location::Confer;
#ifndef RAPBTL_NO_STD_CPLUSPLUS
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
#endif
            if (!ContainsCheckSafely( map, position ))
                throw position;
            return GoWriteElement( map, position );
        }

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Correlative >
        ReadRelatorIncrementSingleScale = {
            SingleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScale< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScale< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoReadRelator< SingleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        ReadRelatorIncrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoReadRelator< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Correlative >
        SafeReadRelatorIncrementSingleScale = {
            SingleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScaleSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScaleSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoReadRelatorSafely< SingleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        SafeReadRelatorIncrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoReadRelatorSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        ReadRelatorDecrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            TraverseReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            GoReadRelator< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        SafeReadRelatorDecrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            TraverseReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            GoReadRelatorSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Evaluative >
        ReadElementIncrementSingleScale = {
            SingleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScale< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScale< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoReadElement< SingleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        ReadElementIncrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoReadElement< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeReadElementIncrementSingleScale = {
            SingleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScaleSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScaleSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoReadElementSafely< SingleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeReadElementIncrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoReadElementSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        ReadElementDecrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            TraverseReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            GoReadElement< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeReadElementDecrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            TraverseReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            GoReadElementSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Evaluative >
        WriteElementIncrementSingleScale = {
            SingleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScale< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScale< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoWriteElement< SingleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        WriteElementIncrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoWriteElement< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeWriteElementIncrementSingleScale = {
            SingleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScaleSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScaleSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoWriteElementSafely< SingleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeWriteElementIncrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            TraverseReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            GoWriteElementSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        WriteElementDecrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            TraverseReadScale< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            GoWriteElement< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Scalar< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeWriteElementDecrementDoubleScale = {
            DoubleComparison< Complementary< Correlative, Evaluative > >,
            BeginReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            TraverseReadScaleSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            GoWriteElementSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Lineal< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        ReadRelatorDoubleLiner = {
            ReadRelatorIncrementDoubleScale< Natural, Correlative, Evaluative >,
            ReadRelatorDecrementDoubleScale< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Lineal< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        SafeReadRelatorDoubleLiner = {
            SafeReadRelatorIncrementDoubleScale< Natural, Correlative, Evaluative >,
            SafeReadRelatorDecrementDoubleScale< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Lineal< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        ReadElementDoubleLiner = {
            ReadElementIncrementDoubleScale< Natural, Correlative, Evaluative >,
            ReadElementDecrementDoubleScale< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Lineal< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeReadElementDoubleLiner = {
            SafeReadElementIncrementDoubleScale< Natural, Correlative, Evaluative >,
            SafeReadElementDecrementDoubleScale< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Lineal< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, Evaluative >
        WriteElementDoubleLiner = {
            WriteElementIncrementDoubleScale< Natural, Correlative, Evaluative >,
            WriteElementDecrementDoubleScale< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Lineal< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, Evaluative >
        SafeWriteElementDoubleLiner = {
            SafeWriteElementIncrementDoubleScale< Natural, Correlative, Evaluative >,
            SafeWriteElementDecrementDoubleScale< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Correlative >
        ReadRelatorIncrementSingleDirection = {
            ReadRelatorIncrementSingleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraverses< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            Contains< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        ReadRelatorIncrementDoubleDirection = {
            ReadRelatorIncrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraverses< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            Contains< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Correlative >
        SafeReadRelatorIncrementSingleDirection = {
            SafeReadRelatorIncrementSingleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraversesCheckSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            ContainsCheckSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        SafeReadRelatorIncrementDoubleDirection = {
            SafeReadRelatorIncrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraversesCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            ContainsCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        ReadRelatorDecrementDoubleDirection = {
            ReadRelatorDecrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            DirectionTraverses< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            Contains< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        SafeReadRelatorDecrementDoubleDirection = {
            SafeReadRelatorDecrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            DirectionTraversesCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            ContainsCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Evaluative >
        ReadElementIncrementSingleDirection = {
            ReadElementIncrementSingleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >,  GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraverses< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            Contains< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        ReadElementIncrementDoubleDirection = {
            ReadElementIncrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraverses< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            Contains< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeReadElementIncrementSingleDirection = {
            SafeReadElementIncrementSingleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraversesCheckSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            ContainsCheckSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeReadElementIncrementDoubleDirection = {
            SafeReadElementIncrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraversesCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            ContainsCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        ReadElementDecrementDoubleDirection = {
            ReadElementDecrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            DirectionTraverses< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            Contains< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeReadElementDecrementDoubleDirection = {
            SafeReadElementDecrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            DirectionTraversesCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            ContainsCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, Evaluative >
        WriteElementIncrementSingleDirection = {
            WriteElementIncrementSingleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >,  GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraverses< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            Contains< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, Evaluative >
        WriteElementIncrementDoubleDirection = {
            WriteElementIncrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraverses< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            Contains< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< AssociativelySingleJunctive< Natural, Correlative, Evaluative >, AssociativelySinglePositional< Correlative, Evaluative >, Natural, Evaluative >
        SafeWriteElementIncrementSingleDirection = {
            SafeWriteElementIncrementSingleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraversesCheckSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            ContainsCheckSafely< SingleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, Evaluative >
        SafeWriteElementIncrementDoubleDirection = {
            SafeWriteElementIncrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetFirst< Natural, Complementary< Correlative, Evaluative > >, GetNext< Complementary< Correlative, Evaluative > > >,
            DirectionTraversesCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetNext< Complementary< Correlative, Evaluative > > >,
            ContainsCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, Evaluative >
        WriteElementDecrementDoubleDirection = {
            WriteElementDecrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            DirectionTraverses< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            Contains< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Directional< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, Evaluative >
        SafeWriteElementDecrementDoubleDirection = {
            SafeWriteElementDecrementDoubleScale< Natural, Correlative, Evaluative >,
            DirectionBegins< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetLast< Natural, Complementary< Correlative, Evaluative > >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            DirectionTraversesCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative >, GetPrevious< Complementary< Correlative, Evaluative > > >,
            ContainsCheckSafely< DoubleComplementary< Correlative, Evaluative >, Natural, Complementary< Correlative, Evaluative > >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Axial< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        ReadRelatorDoubleAxis = {
            ReadRelatorIncrementDoubleDirection< Natural, Correlative, Evaluative >,
            ReadRelatorDecrementDoubleDirection< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Axial< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Correlative >
        SafeReadRelatorDoubleAxis = {
            SafeReadRelatorIncrementDoubleDirection< Natural, Correlative, Evaluative >,
            SafeReadRelatorDecrementDoubleDirection< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Axial< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        ReadElementDoubleAxis = {
            ReadElementIncrementDoubleDirection< Natural, Correlative, Evaluative >,
            ReadElementDecrementDoubleDirection< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Axial< const AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, const Evaluative >
        SafeReadElementDoubleAxis = {
            SafeReadElementIncrementDoubleDirection< Natural, Correlative, Evaluative >,
            SafeReadElementDecrementDoubleDirection< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Axial< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, Evaluative >
        WriteElementDoubleAxis = {
            WriteElementIncrementDoubleDirection< Natural, Correlative, Evaluative >,
            WriteElementDecrementDoubleDirection< Natural, Correlative, Evaluative >
        };

        template <
            typename Natural,
            typename Correlative,
            typename Evaluative
        >
        constexpr Axial< AssociativelyDoubleJunctive< Natural, Correlative, Evaluative >, AssociativelyDoublePositional< Correlative, Evaluative >, Natural, Evaluative >
        SafeWriteElementDoubleAxis = {
            SafeWriteElementIncrementDoubleDirection< Natural, Correlative, Evaluative >,
            SafeWriteElementDecrementDoubleDirection< Natural, Correlative, Evaluative >
        };

    }

}

#endif
