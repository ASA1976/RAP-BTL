// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "junction/contribution.hpp"
#include "junction/consecution.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::junction;
using namespace ::junction::contribution;
using namespace ::consecution;

using Natural = unsigned short;
using Nodal = Junctional< char >;

const Natural
NodePoolSize = 3;

Contributory< Natural, NodePoolSize, Nodal >
NodePool;

// Use SafePoolAdjunct if overflowing the pool is a possibility
constexpr Adjunctive< Natural, char >
NodePoolAdjunct = FastPoolAdjunct< Natural, NodePoolSize, char, NodePool >;

template <
    typename Spatial,
    typename Positional,
    typename Natural
>
static inline bool
DisplayCharacters(
    Referential< const Spatial >
        list,
    Referential< const Directional< const Spatial, Positional, Natural, const char > >
        direction
) {
    Positional
        position;
    if (!direction.begins( list, 0 ))
        return false;
    for (
        direction.scale.begin( list, position, 0 );
        true;
        direction.scale.traverse( list, position, 1 )
    ) {
        printf( "'%c'", direction.scale.go( list, position ).to );
        if (!direction.traverses( list, position, 1 ))
            break;
        printf( "," );
    }
    return true;
}

template <
    typename Spatial,
    typename Positional,
    typename Natural
>
static inline void
DemonstrateSequence(
    Referential< Spatial >
        sequence,
    Referential< const Sequent< Spatial, Positional, Natural, char > >
        sequencer,
    Referential< const Directional< const Spatial, Positional, Natural, const char > >
        increment
) {
    sequencer.antecede( sequence, 3 );
    sequencer.proceed( sequence, 'B' );
    sequencer.accede( sequence, 'A' );
    sequencer.proceed( sequence, 'C' );
    DisplayCharacters( sequence, increment );
    puts( " (should read 'A','B','C')" );
    sequencer.succeed( sequence, 1 );
    sequencer.recede( sequence, 1 );
    DisplayCharacters( sequence, increment );
    puts( " (should read 'B')" );
    sequencer.secede( sequence );
    while (sequencer.condense( sequence ));
}

int
main() {
    using namespace ::junction::consecution;
    static auto&
        Sequencer = JunctionSequencer< Natural, char, NodePoolAdjunct >;
    static auto&
        Increment = ReadIncrementDirection< Natural, char >;
    Junctive< Natural, char >
        list;
    Initialize( list );
    DemonstrateSequence( list, Sequencer, Increment );
}
