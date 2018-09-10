// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_PROVISION_MODULE
#define JUNCTION_PROVISION_MODULE
#include "../junction.hpp"

namespace junction {

    namespace provision {

        using ::allocation::DefaultAllocative;

        template <
            typename Natural,
            Natural
                Maximum,
            typename Elemental
        >
        static inline Natural
        Survey(
            Referential< const Junctive< Natural, Elemental > >
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
            typename Elemental,
            Referential< const DefaultAllocative< Junctional< Elemental > > >
                Allocator
        >
        static inline bool
        Protract(
            Referential< Junctive< Natural, Elemental > >
                list,
            Referential< Positional< Elemental > >
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
            Locational< Junctional< Elemental > >
                node;
            Natural
                index;
            position.at = Reclaim( list );
            if (!position.at) {
                Allocator.claim( position.at );
                if (!position.at)
                    return false;
                list.total++;
            }
            node = position.at;
            for (index = 1; index < count; index++) {
                node->next = Reclaim( list );
                if (!node->next) {
                    Allocator.claim( node->next );
                    if (!node->next) {
                        node->next = list.unused;
                        if (list.unused)
                            list.unused->previous = node;
                        list.unused = position.at;
                        list.unused->previous = 0;
                        return false;
                    }
                    list.total++;
                }
                node->next->previous = node;
                node = node->next;
            }
            node->next = 0;
            position.at->previous = list.last;
            if (list.last)
                list.last->next = position.at;
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
            Referential< const DefaultAllocative< Junctional< Elemental > > >
                Allocator
        >
        static inline bool
        ProtractSafely(
            Referential< Junctive< Natural, Elemental > >
                list,
            Referential< Positional< Elemental > >
                position,
            Referential< const Natural >
                count
        ) {
            static auto&
                ProtractList = Protract< Natural, Elemental, Allocator >;
            if (list.count >= Maximum)
                return false;
            return ProtractList( list, position, count );
        }

    };

};

#endif
