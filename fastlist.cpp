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
    typename Positional
>
static inline bool
DisplayCharacters(
    Referential< const Spatial >
        list,
    Referential< const Directional< const Spatial, Positional, const char > >
        direction
) {
    Positional
        position;
    if (!direction.begins( list ))
        return false;
    for (
        direction.scale.begin( list, position );
        true;
        direction.scale.traverse( list, position )
    ) {
        printf( "'%c'", direction.scale.go( list, position ).to );
        if (!direction.traversable( list, position ))
            break;
        printf( "," );
    }
    return true;
}

template <
    typename Spatial,
    typename Positional
>
static inline void
DemonstrateSequence(
    Referential< Spatial >
        space,
    Referential< const Sequent< Spatial, Positional, Natural, char > >
        sequencer,
    Referential< const Directional< const Spatial, Positional, const char > >
        increment
) {
    sequencer.antecede( space, 3 );
    sequencer.proceed( space, 'B' );
    sequencer.accede( space, 'A' );
    sequencer.proceed( space, 'C' );
    DisplayCharacters( space, increment );
    puts( " (should read 'A','B','C')" );
    sequencer.succeed( space, 1 );
    sequencer.recede( space, 1 );
    DisplayCharacters( space, increment );
    puts( " (should read 'B')" );
    sequencer.secede( space );
    while (sequencer.condense( space ));
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
