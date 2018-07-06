// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_PROVISION_MODULE
#define JUNCTION_PROVISION_MODULE
#include "../junction.hpp"

namespace junction {

    namespace provision {

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
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
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
                position
        ) {
            using namespace ::std;
            static_assert(
                is_integral< Natural >::value && is_unsigned< Natural >::value,
                "Natural:  Unsigned integer type required"
            );
            position.at = Reclaim( list );
            if (!position.at) {
                Allocator.claim( position.at );
                if (!position.at)
                    return false;
                position.at->next = 0;
            }
            position.at->previous = list.last;
            if (list.last)
                list.last->next = position.at;
            else
                list.first = position.at;
            list.last = position.at;
            list.total++;
            list.count++;
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
                position
        ) {
            static auto&
                ProtractList = Protract< Natural, Elemental, Allocator >;
            if (list.count >= Maximum)
                return false;
            return ProtractList( list, position );
        }

    };

};

#endif
