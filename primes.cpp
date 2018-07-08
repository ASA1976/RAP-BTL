// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "localization.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::trajection;

template <
    typename Spatial,
    typename Positional,
    typename Natural
>
static inline bool
SequencePrimes(
    Referential< Spatial >
        primes,
    Referential< const Scalar< Spatial, Positional, Natural > >
        increment,
    Referential< const Natural >
        count
) {
    Natural
        added,
        value;
    Positional
        read_position,
        write_position;
    if (count < 1)
        return false;
    value = 2;
    increment.begin( primes, write_position );
    increment.go( primes, write_position ).to = value++;
    for (added = 1; added < count; value++) {
        increment.begin( primes, read_position );
        while (true) {
            if (value % increment.go( primes, read_position ).to == 0)
                break;
            if (read_position == write_position) {
                increment.traverse( primes, write_position );
                increment.go( primes, write_position ).to = value;
                added++;
                break;
            }
            increment.traverse( primes, read_position );
        }
    }
    return true;
}

template <
    typename Natural
>
static inline bool
DisplayPrimes(
    Referential< const Natural >
        count
) {
    using namespace ::localization;
    static auto&
        Increment = WriteIncrementScale< Natural, Natural >;
    WriteLocal< Natural >
        primes = new Natural[count];
    Natural
        position;
    if (count < 1)
        return false;
    SequencePrimes( primes, Increment, count );
    Increment.begin( primes, position );
    while (true) {
        printf( "%u\n", Increment.go( primes, position ).to );
        if (position == count - 1)
            break;
        Increment.traverse( primes, position );
    }
    return true;
}

static inline void PrintTitle(
    const Locational< const char >
        filename
) {
    puts( "Prime Number Sequencer" );
    puts( "" );
    printf( "%s COUNT\n\n", filename );
}

int
main(
    int
        argc,
    Locational< Locational< char > >
        argv
) {
    long
        test;
    unsigned
        count;
    if (argc != 2) {
        PrintTitle( argv[0] );
        printf( "Where COUNT is a natural integer number of primes to generate\n" );
        return 0;
    }
    if (
        sscanf( argv[1], "%ld", Locate( test ).at ) < 1
        || test < 0
        || sscanf( argv[1], "%u", Locate( count ).at ) < 1
    ) {
        PrintTitle( argv[0] );
        fprintf( stderr, "Error parsing COUNT '%s' as a natural integer\n", argv[1] );
        return -1;
    }
    return DisplayPrimes( count ) ? 0 : -1;
}
