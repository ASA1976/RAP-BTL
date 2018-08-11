// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "junction/contribution.hpp"
#include "junction/collection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::junction;
using namespace ::junction::contribution;

const unsigned short
CacheLimit = 0x2000;

const unsigned short
NodePoolSize = CacheLimit / sizeof( Junctional< int > ) - 1;

Contributory< unsigned short, NodePoolSize, Junctional< int > >
NodePool;

constexpr Adjunctive< unsigned short, int >
NodePoolAdjunct = FastPoolAdjunct< unsigned short, NodePoolSize, int, NodePool >;

template <
    typename Spatial,
    typename Positional,
    typename Natural
>
static inline bool
OutputIntegers(
    Referential< const Spatial >
        list,
    Referential< const Directional< const Spatial, Positional, Natural, const int > >
        direction,
    Locational< FILE >
        handle
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
        fprintf( handle, "%d\n", direction.scale.go( list, position ).to );
        if (!direction.traversable( list, position, 1 ))
            break;
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
    using namespace ::junction::collection;
    using ::comparison::IsEqual;
    using ::comparison::IsLesser;
    enum Erroneous {
        NumberOfArguments = -1,
        InputFile = -2,
        OutputFile = -3,
        IntegerCount = -4
    };
    static auto&
        Collector = JunctionCollector< unsigned short, int, NodePoolAdjunct, IsEqual< int >, IsLesser< int > >;
    static auto&
        Increment = ReadIncrementDirection< unsigned short, int >;
    Locational< FILE >
        input,
        output;
    Junctive< unsigned short, int >
        set;
    unsigned short
        count;
    int
        value;
    input = stdin;
    output = stdout;
    switch (argc) {
    case 3:
        output = fopen( argv[2], "w" );
        if (!output) {
            fprintf( stderr, "Could not write to file '%s'\n", argv[2] );
            return Erroneous::OutputFile;
        }
    case 2:
        input = fopen( argv[1], "r" );
        if (!input) {
            fprintf( stderr, "Could not read from file '%s'\n", argv[1] );
            return Erroneous::InputFile;
        }
        break;
    default:
        fprintf( stderr, "%s input_file_path ?output_file_path?\n", argv[0] );
        return Erroneous::NumberOfArguments;
    }
    Initialize( set );
    count = 0;
    while (!feof( input )) {
        if (fscanf( input, "%d", Locate( value ).at ) == 1) {
            if (count == NodePoolSize) {
                fprintf( stderr, "Maximum number of integers is %u\n", NodePoolSize );
                fclose( input );
                return Erroneous::IntegerCount;
            }
            Collector.selector.composer.compose( set, value );
            count++;
        }
    }
    if (input != stdin)
        fclose( input );
    OutputIntegers( set, Increment, output );
    if (output != stdout)
        fclose( output );
}
