// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_PROVISION_MODULE
#define JUNCTION_PROVISION_MODULE
#include "../junction.hpp"

namespace junction {

    /**
     * @brief         
     *     Linked list resource management common functionality.
     * @details       
     *     Association
     *     -----------
     *     Linked list resource management common functionality.
     */
    namespace provision {

        using ::allocation::DefaultAllocative;

        template <
            typename Connective,
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        Survey(
            Referential< const Junctive< Connective, Natural, Elemental > >
                list
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

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental,
            Referential< const DefaultAllocative< SinglyNodal< Elemental > > >
                Allocator,
            const bool
                Safety
        >
        static inline bool
        Protract(
            Referential< SinglyJunctive< Natural, Elemental > >
                list,
            Referential< SinglyPositional< Elemental > >
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
            Locational< SinglyNodal< Elemental > >
                node, result;
            Natural
                index;
            if (Safety && list.count >= Maximum)
                return false;
            position.at = Reclaim( list );
            if (!position.at) {
                Allocator.claim( position.at );
                if (!position.at)
                    return false;
                list.total++;
            }
            node = position.at;
            for (index = 1; index < count; index++) {
                SetNext( node, Reclaim( list ) );
                if (!GetNext( node )) {
                    Allocator.claim( result );
                    if (!result) {
                        SetNext( node, list.unused );
                        list.unused = position.at;
                        return false;
                    }
                    SetNext( node, result );
                    list.total++;
                }
                node = GetNext( node );
            }
            UnsetNext( node );
            if (list.last)
                SetNext( list.last, position.at );
            else
                list.first = position.at;
            list.last = position.at;
            list.count += count;
            return true;
        }

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental,
            Referential< const DefaultAllocative< DoublyNodal< Elemental > > >
                Allocator,
            const bool
                Safety
        >
        static inline bool
        Protract(
            Referential< DoublyJunctive< Natural, Elemental > >
                list,
            Referential< DoublyPositional< Elemental > >
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
            Locational< DoublyNodal< Elemental > >
                node, result;
            Natural
                index;
            if (Safety && list.count >= Maximum)
                return false;
            position.at = Reclaim( list );
            if (!position.at) {
                Allocator.claim( position.at );
                if (!position.at)
                    return false;
                list.total++;
            }
            node = position.at;
            for (index = 1; index < count; index++) {
                SetNext( node, Reclaim( list ) );
                if (!GetNext( node )) {
                    Allocator.claim( result );
                    if (!result) {
                        ConnectNext( node, list.unused );
                        list.unused = position.at;
                        UnsetPrevious( list.unused );
                        return false;
                    }
                    SetNext( node, result );
                    list.total++;
                }
                SetPrevious( GetNext( node ), node );
                node = GetNext( node );
            }
            UnsetNext( node );
            SetPrevious( position.at, list.last );
            if (list.last)
                SetNext( list.last, position.at );
            else
                list.first = position.at;
            list.last = position.at;
            list.count += count;
            return true;
        }

    }

}

#endif
