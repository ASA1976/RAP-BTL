// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include "segmentation.hpp"
#include "ordination.hpp"
#include "junction/stdlib.hpp"
#include "junction/selection.hpp"
#include "junction/collection.hpp"
#include "junction/association/selection.hpp"
#include "junction/association/collection.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::location;
using namespace ::trajection;
using namespace ::composition;
using namespace ::association;
using namespace ::consecution;
using namespace ::junction;
using namespace ::junction::stdlib;

using MessageLocal = const Locational< const char >;
using MapComplementary = Complementary< char, int >;

constexpr DoublyAdjunctive< size_t, char >
    ListAdjunct = DefaultMallocDoubleAdjunct< size_t, char >;

constexpr DoublyAdjunctive< size_t, MapComplementary >
    MapAdjunct = DefaultMallocDoubleAdjunct< size_t, MapComplementary >;

template <
    typename Spatial,
    typename Natural
>
static bool
ComposeSets(
    Referential< Spatial >
        base,
    Referential< Spatial >
        relative,
    Referential< const Compositional< Spatial, Natural, char > >
        composer
) {
    composer.decompose( base );
    composer.decompose( relative );
    composer.precompose( base, 3 );
    composer.precompose( relative, 3 );
    return composer.compose( base, 'Y' )
        && composer.compose( base, 'A' )
        && composer.compose( base, 'M' )
        && composer.compose( relative, 'M' )
        && composer.compose( relative, 'B' )
        && composer.compose( relative, 'Z' );
}

template <
    typename Spatial,
    typename Natural
>
static bool
AssociateMap(
    Referential< Spatial >
        map,
    Referential< const Associative< Spatial, Natural, char, int > >
        associator
) {
    associator.disband( map );
    associator.prepare( map, 3 );
    return associator.associate( map, 'y', 1 )
        && associator.associate( map, 'z', -1 )
        && associator.associate( map, 'x', 0 );
}

template <
    typename Spatial,
    typename Positional,
    typename Natural
>
static bool
ProceedSequence(
    Referential< Spatial >
        list,
    Referential< const Sequent< Spatial, Positional, Natural, char > >
        sequencer,
    Referential< const Conjoint< Spatial, Positional, MessageLocal, Natural, Natural, char > >
        conjoiner
) {
    using namespace ::segmentation;
    static const Natural
        Length = 7;
    static auto&
        Direction = ReadIncrementDirection< Natural, Length, char >;
    static const char
        Message[Length] = {'M', 'E', 'S', 'S', 'A', 'G', 'E'};
    static const Natural
        First = 0,
        Last = Length - 1;
    sequencer.secede( list );
    sequencer.antecede( list, Length );
    return conjoiner.proceed( list, Direction, Message, First, Last );
}

template <
    typename Spatial,
    typename Positional,
    typename Natural
>
static bool
DisplayCharacters(
    Referential< const Spatial >
        list,
    Referential< const Scalar< const Spatial, Positional, Natural, const char > >
        scale,
    Referential< const size_t >
        count
) {
    Positional
        position;
    size_t
        current;
    scale.begin( list, position, 0 );
    for (current = 0; current < count; current++) {
        printf( "'%c'", scale.go( list, position ).to );
        if (current < count - 1) {
            scale.traverse( list, position, 1 );
            printf( "," );
        }
    }
    return true;
}

template <
    typename Spatial,
    typename Positional,
    typename Natural
>
static bool
DisplayCharacters(
    Referential< const Spatial >
        list,
    Referential< const Directional< const Spatial, Positional, Natural, const char > >
        direction
) {
    return DisplayCharacters( list, direction.scale, direction.survey( list ) );
}

template <
    typename Spatial,
    typename Positional,
    typename Natural
>
static bool
DisplayMappings(
    Referential< const Spatial >
        map,
    Referential< const Directional< const Spatial, Positional, Natural, const MapComplementary > >
        direction
) {
    Positional
        position;
    if (!direction.begins( map, 0 ))
        return false;
    direction.scale.begin( map, position, 0 );
    while (true) {
        auto&
            mapping = direction.scale.go( map, position ).to;
        printf( "%c=%d", mapping.relator, mapping.value );
        if (!direction.traverses( map, position, 1 ))
            break;
        printf( " " );
        direction.scale.traverse( map, position, 1 );
    }
    return true;
}

static bool
DemonstrateLocalization() {
    using namespace ::localization;
    using namespace ::sortation;
    using namespace ::comparison;
    using Local = ReadLocal< char >;
    static const size_t
        Length = 5;
    static auto&
        Liner = ReadLiner< int, size_t, char >;
    static auto&
        Increment = ReadIncrementScale< int, size_t, char >;
    static const size_t
        Before = 2,
        After = 2;
    static Local
        locality = "ABCDE";
    int
        index;
    puts( "Localization (Pointer Only)" );
    printf( "locality := " );
    DisplayCharacters( locality, Increment, Length );
    index = 2;
    if (SearchBisection( locality, Liner, locality[0], index, Before, After, IsEqual, IsLesser )) {
        printf( " (found '%c')\n", Increment.go( locality, index ).to );
        return true;
    }
    printf( " (not found)\n" );
    return true;
}

static bool
DemonstrateSegmentation() {
    using namespace ::segmentation;
    using namespace ::sortation;
    using namespace ::comparison;
    using Segmental = ReadLocal< char >;
    static const size_t
        Length = 5;
    static auto&
        Liner = ReadLiner< size_t, Length, char >;
    static auto&
        Increment = ReadIncrementDirection< size_t, Length, char >;
    static const size_t
        Before = 2,
        After = 2;
    static Segmental
        segment = "ABCDE";
    size_t
        index;
    puts( "Segmentation (Pointer And Predetermined Length)" );
    printf( "segment := " );
    DisplayCharacters( segment, Increment );
    index = 2;
    if (SearchBisection( segment, Liner, segment[1], index, Before, After, IsEqual, IsLesser )) {
        printf( " (found '%c')\n", Increment.scale.go( segment, index ).to );
        return true;
    }
    printf( " (not found)\n" );
    return false;
}

static bool
DemonstrateOrdination() {
    using namespace ::location;
    using namespace ::ordination;
    using namespace ::sortation;
    using namespace ::comparison;
    static const size_t
        Length = 5;
    using Ordinal = ReadOrdinal< size_t, Length, char >;
    using Positional = ReadPositional< char >;
    static auto&
        Liner = ReadLiner< size_t, Length, char >;
    static auto&
        Increment = ReadIncrementDirection< size_t, Length, char >;
    static const size_t
        Before = 2,
        After = 2;
    static Ordinal
        array = {'A','B','C','D','E'};
    Positional
        position;
    puts( "Ordination (Array)" );
    printf( "array := " );
    DisplayCharacters( array, Increment );
    position = Locate( array[2] ).at;
    if (SearchBisection( array, Liner, array[3], position, Before, After, IsEqual, IsLesser )) {
        printf( " (found '%c')\n", Increment.scale.go( array, position ).to );
        return true;
    }
    printf( " (not found)\n" );
    return false;
}

static bool
DemonstrateJunction() {
    using namespace ::junction::consecution;
    using namespace ::junction::selection;
    using namespace ::junction::collection;
    using namespace ::junction::association;
    using namespace ::junction::association::selection;
    using namespace ::junction::association::collection;
    using namespace ::comparison;
    static auto&
        ListSequencer = DoubleSequencer< size_t, char, ListAdjunct >;
    static auto&
        ListConjoiner = DoubleConjoiner< const Locational< const char >, size_t, size_t, size_t, char, ListAdjunct >;
    static auto&
        ListSelector = DoubleSelector< size_t, char, IsEqual, ListAdjunct >;
    static auto&
        ListCollector = DoubleCollector< size_t, char, IsEqual, IsLesser, ListAdjunct >;
    static auto&
        ListAxis = ReadDoubleAxis< size_t, char >;
    static auto&
        MapCorrelator = DoubleCorrelator< size_t, char, int, IsEqual, MapAdjunct >;
    static auto&
        MapAssociator = DoubleAssociator< size_t, char, int, IsEqual, IsLesser, MapAdjunct >;
    static auto&
        MapDirection = ReadIncrementDoubleDirection< size_t, MapComplementary >;
    DoublyJunctive< size_t, char >
        list,
        base,
        relative;
    AssociativelyDoubleJunctive< size_t, char, int >
        map;
    Initialize( list );
    Initialize( base );
    Initialize( relative );
    Initialize( map );
    puts( "Junction (Linked List And Map)" );
    if (!ProceedSequence( list, ListSequencer, ListConjoiner ))
        return false;
    printf( "Sequence = (" );
    DisplayCharacters( list, ListAxis.increment );
    puts( ")" );
    if (!ComposeSets( base, relative, ListSelector.composer ))
        return false;
    printf( "Unordered Sets: Base = {" );
    DisplayCharacters( base, ListAxis.increment );
    printf( "}, Relative = {" );
    DisplayCharacters( relative, ListAxis.increment );
    puts( "}" );
    if (!ListSelector.section.unite( list, ListAxis.increment, base, ListAxis.increment, relative ))
        return false;
    printf( "Unordered Union Of Base And Relative = {" );
    DisplayCharacters( list, ListAxis.increment );
    puts( "}" );
    if (!ComposeSets( base, relative, ListCollector.selector.composer ))
        return false;
    printf( "Ordered Sets: Base = {" );
    DisplayCharacters( base, ListAxis.increment );
    printf( "}, Relative = {" );
    DisplayCharacters( relative, ListAxis.increment );
    puts( "}" );
    if (!ListCollector.bisection.unite( list, ListAxis, base, ListAxis, relative ))
        return false;
    printf( "Ordered Union Of Base And Relative = {" );
    DisplayCharacters( list, ListAxis.increment );
    puts( "}" );
    if (!AssociateMap( map, MapCorrelator ))
        return false;
    printf( "Unordered Map: [" );
    DisplayMappings( map, MapDirection );
    puts( "]" );
    if (!AssociateMap( map, MapAssociator ))
        return false;
    printf( "Ordered Map: [" );
    DisplayMappings( map, MapDirection );
    puts( "]" );
    ListSequencer.secede( list );
    ListSequencer.secede( base );
    ListSequencer.secede( relative );
    MapCorrelator.disband( map );
    printf( "Freeing 1/4." );
    while (ListSequencer.condense( list ))
        printf( "." );
    printf( " 2/4." );
    while (ListSequencer.condense( base ))
        printf( "." );
    printf( " 3/4." );
    while (ListSequencer.condense( relative ))
        printf( "." );
    printf( " 4/4." );
    while (MapCorrelator.dissolve( map ))
        printf( "." );
    puts( "" );
    return true;
}

int
main() {
    enum Erroneous {
        Localization = -1,
        Segmentation = -2,
        Ordination = -3,
        Junction = -4
    };
    if (!DemonstrateLocalization()) {
        fprintf( stderr, "ERROR during localization demonstration\n" );
        return Erroneous::Localization;
    }
    puts( "" );
    if (!DemonstrateSegmentation()) {
        fprintf( stderr, "ERROR during segmentation demonstration\n" );
        return Erroneous::Segmentation;
    }
    puts( "" );
    if (!DemonstrateOrdination()) {
        fprintf( stderr, "ERROR during ordination demonstration\n" );
        return Erroneous::Ordination;
    }
    puts( "" );
    if (!DemonstrateJunction()) {
        fprintf( stderr, "ERROR during junction demonstration\n" );
        return Erroneous::Junction;
    }
}
