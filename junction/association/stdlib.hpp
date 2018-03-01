// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef JUNCTION_ASSOCIATION_STDLIB_MODULE
#define JUNCTION_ASSOCIATION_STDLIB_MODULE
#include "../association.hpp"
#include "../stdlib.hpp"

namespace junction {

    namespace association {

        namespace stdlib {

            using namespace ::junction::stdlib;

            template <
                typename Natural,
                typename Correlative,
                typename Elemental
            >
            constexpr auto
            DefaultMallocAssociativeAdjunct = DefaultMallocAdjunct< Natural, Associational< Correlative, Elemental > >;

            template <
                typename Natural,
                typename Correlative,
                typename Elemental
            >
            constexpr auto
            DefaultCallocAssociativeAdjunct = DefaultCallocAdjunct< Natural, Associational< Correlative, Elemental > >;

        }

    }

}

#endif
