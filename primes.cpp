// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "junction/consecution.hpp"
#include <cstdio>

using namespace ::consecution;

template <
    typename Spatial,
    typename Positional,
    typename Accumulative,
    typename Natural
>
static inline bool
SequencePrimes(
    Referential< Spatial >
        sequence,
    Referential< const Sequent< Spatial, Positional, Accumulative, Natural > >
        sequencer,
    Referential< const Directional< const Spatial, Positional, const Natural > >
        increment,
    Referential< const Natural >
        to
) {
    static const Natural
        Two = 2;
    auto
        scale = increment.scale;
    Natural
        value;
    Positional
        position;
    if (to < Two)
        return false;
    sequencer.proceed( sequence, Two );
    for (value = Two + 1; value <= to; value++) {
        scale.begin( sequence, position );
        while (true) {
            if (value % scale.go( sequence, position ).to == 0)
                break;
            if (!increment.traversable( sequence, position )) {
                sequencer.proceed( sequence, value );
                break;
            }
            scale.traverse( sequence, position );
        }
    }
    return true;
}

template <
    typename Natural
>
static bool
DisplayPrimes(
    Referential< const Natural >
        to
) {
    using namespace ::junction;
    using namespace ::junction::consecution;
    static auto
        Sequencer = JunctionSequencer< size_t, Natural, CopyNewAdjunct< size_t, Natural > >;
    static auto
        Increment = ReadIncrementDirection< size_t, Natural >;
    static auto
        Scale = Increment.scale;
    Junctive< size_t, Natural >
        primes;
    Positional< Natural >
        position;
    Initialize( primes );
    SequencePrimes( primes, Sequencer, Increment, to );
    if (Increment.begins( primes )) {
        for (Scale.begin( primes, position ); true; Scale.traverse( primes, position )) {
            printf( "%u\n", GoRead( primes, position ).to );
            if (!Increment.traversable( primes, position ))
                break;
        }
        Sequencer.secede( primes );
        while (Sequencer.condense( primes ));
    }
    return true;
}

int
main(
    int
        argc,
    Locational< Locational< char > >
        argv
) {
    static auto
        PrintTitle = [&]{
            puts( "Prime Number Sequencer" );
            puts( "" );
            printf( "%s TO\n\n", argv[0] );
        };
    long
        test;
    unsigned
        to;
    if (argc != 2) {
        PrintTitle();
        printf( "Where TO is a natural integer upper bound\n" );
        return 0;
    }
    if (
        sscanf( argv[1], "%ld", Locate( test ).at ) < 1
        || test < 0
        || sscanf( argv[1], "%u", Locate( to ).at ) < 1
    ) {
        PrintTitle();
        fprintf( stderr, "Error parsing TO upper bound ('%s') as a natural integer\n", argv[1] );
        return -1;
    }
    DisplayPrimes( to );
    return 0;
}
