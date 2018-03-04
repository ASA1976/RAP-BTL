// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "junction/consecution.hpp"
#include <cstdio>

using namespace ::consecution;

template <
    typename Natural
>
static inline bool
IsPrime(
    Referential< const Natural >
        value
) {
    static const Natural
        Zero = 0,
        Two = 2;
    Natural
        divisor;
    if (value < Two)
        return false;
    for (divisor = Two; divisor < value; divisor++)
        if (value % divisor == Zero)
            return false;
    return true;
}

template <
    typename Spatial,
    typename Positional,
    typename Accumulative,
    typename Natural
>
static inline void
SequencePrimes(
    Referential< Spatial >
        sequence,
    Referential< const Sequent< Spatial, Positional, Accumulative, Natural > >
        sequencer,
    Referential< const Natural >
        first,
    Referential< const Natural >
        last
) {
    Natural
        value;
    for (value = first; value <= last; value++)
        if (IsPrime( value ))
            sequencer.proceed( sequence, value );
}

static void
Demonstration( void ) {
    using namespace ::junction;
    using namespace ::junction::consecution;
    static auto
        Sequencer = JunctionSequencer< size_t, unsigned, CopyNewAdjunct< size_t, unsigned > >;
    static auto
        Begin = BeginReadIncrement< size_t, unsigned >;
    static auto
        Traverse = TraverseReadIncrement< size_t, unsigned >;
    static auto
        Traversable = IncrementTraversable< size_t, unsigned >;
    Junctive< size_t, unsigned >
        primes;
    Positional< unsigned >
        position;
    unsigned
        first,
        last;
    Initialize( primes );
    puts( "Prime Number Sequencer" );
    printf( "First natural integer: " );
    scanf( "%u", Locate( first ).at );
    printf( "Last natural integer: " );
    scanf( "%u", Locate( last ).at );
    printf( "Calculating primes..." );
    fflush( stdout );
    SequencePrimes( primes, Sequencer, first, last );
    puts( "done" );
    for (Begin( primes, position ); true; Traverse( primes, position )) {
        printf( "%u\n", GoRead( primes, position ).to );
        if (!Traversable( primes, position ))
            break;
    }
    Sequencer.secede( primes );
    printf( "Freeing memory..." );
    fflush( stdout );
    while (Sequencer.condense( primes ));
    puts( "done" );
}

int
main() {
    Demonstration();
    return 0;
}
