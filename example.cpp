// � 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "segmentation.hpp"
#include "ordination.hpp"
#include "junction/selection.hpp"
#include "junction/collection.hpp"
#include "junction/association/selection.hpp"
#include "junction/association/collection.hpp"
#include "junction/association/stdlib.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace ::composition;
using namespace ::association;
using namespace ::consecution;

template <
    typename Spatial,
    typename Natural
>
static inline bool
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
        && composer.compose( relative, 'Z' )
        ;
}

template <
    typename Spatial,
    typename Natural
>
static inline bool
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
        && associator.associate( map, 'x', 0 )
        ;
}

template <
    typename Spatial,
    typename Positional,
    typename Natural
>
static inline bool
ProceedSequence(
    Referential< Spatial >
        list,
    Referential< const Sequent< Spatial, Positional, Natural, char > >
        sequencer,
    Referential< const Conjoint< Spatial, Positional, Locational< const char >, Locational< const char >, char > >
        conjoiner
) {
    using namespace ::segmentation;
    static const Natural
        Length = 7;
    static auto
        Direction = ReadIncrementDirection< Natural, Length, char >;
    static const char
        Message[Length] = {'M', 'E', 'S', 'S', 'A', 'G', 'E'};
    sequencer.secede( list );
    sequencer.antecede( list, Length );
    return conjoiner.proceed( list, Direction, Message, Message, Message + Length - 1 );
}

template <
    typename Spatial,
    typename Positional
>
static inline bool
DisplayCharacters(
    Referential< const Spatial >
        list,
    Referential< const Scalar< const Spatial, Positional, const char > >
        scale,
    Referential< const size_t >
        count
) {
    Positional
        position;
    scale.begin( list, position );
    for (size_t current = 0; current < count; current++) {
        printf( "'%c'", scale.go( list, position ).to );
        if (current < count - 1) {
            scale.traverse( list, position );
            printf( "," );
        }
    }
    return true;
}

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
    size_t
        count;
    return Count( list, direction, position, count )
        && DisplayCharacters( list, direction.scale, count )
        ;
}

template <
    typename Spatial,
    typename Positional
>
static inline bool
DisplayMappings(
    Referential< const Spatial >
        map,
    Referential< const Directional< const Spatial, Positional, const Associational< char, int > > >
        direction
) {
    auto
        scale = direction.scale;
    Positional
        position;
    if (!direction.begins( map ))
        return false;
    for (scale.begin( map, position ); true; scale.traverse( map, position )) {
        auto
            mapping = scale.go( map, position ).to;
        printf( "%c=%d", mapping.relator, mapping.value );
        if (!direction.traversable( map, position ))
            break;
        printf( " " );
    }
    return true;
}

static bool
DemonstrateLocalization( void ) {
    using namespace ::localization;
    using Local = ReadLocal< char >;
    static auto
        Scale = ReadIncrementScale< char >;
    static Local
        locality = "ABCDE";
    puts( "Localization" );
    printf( "locality := " );
    DisplayCharacters( locality, Scale, 5 );
    printf( "\n" );
    return true;
}

static bool
DemonstrateSegmentation( void ) {
    using namespace ::segmentation;
    using namespace ::sortation;
    using Segmental = ReadLocal< char >;
    using Positional = ReadPositional< char >;
    static const size_t
        Length = 5;
    static auto
        Axis = ReadAxis< size_t, Length, char >;
    static auto
        FindCharacter = SearchBisectionally< Segmental, Positional, size_t, char, EquateRelationally, OrderRelationally >;
    static Segmental
        segment = "ABCDE";
    Positional
        position;
    puts( "Segmentation" );
    printf( "segment := " );
    DisplayCharacters( segment, Axis.increment );
    if (FindCharacter( segment, Axis, Length, segment[1], position )) {
        printf( " (found '%c')\n", Refer( position ).to );
        return true;
    }
    printf( " (not found)\n" );
    return false;
}

static bool
DemonstrateOrdination( void ) {
    using namespace ::ordination;
    using namespace ::sortation;
    static const size_t
        Length = 5;
    using Ordinal = ReadOrdinal< size_t, Length, char >;
    using Positional = ReadPositional< char >;
    static auto
        Axis = ReadAxis< size_t, Length, char >;
    static auto
        FindCharacter = SearchBisectionally< Ordinal, Positional, size_t, char, EquateRelationally, OrderRelationally >;
    static Ordinal
        array = {'A','B','C','D','E'};
    Positional
        position;
    puts( "Ordination" );
    printf( "array := " );
    DisplayCharacters( array, Axis.increment );
    if (FindCharacter( array, Axis, Length, array[3], position )) {
        printf( " (found '%c')\n", Refer( position ).to );
        return true;
    }
    printf( " (not found)\n" );
    return false;
}

static bool
DemonstrateJunction( void ) {
    using namespace ::junction;
    using namespace ::junction::consecution;
    using namespace ::junction::selection;
    using namespace ::junction::collection;
    using namespace ::junction::association;
    using namespace ::junction::association::selection;
    using namespace ::junction::association::collection;
    using namespace ::junction::association::stdlib;
    static auto
        ListSequencer = JunctionSequencer< size_t, char, DefaultCallocAdjunct< size_t, char > >;
    static auto
        ListConjoiner = JunctionConjoiner< Locational< const char >, Locational< const char >, size_t, char, DefaultCallocAdjunct< size_t, char > >;
    static auto
        ListSelector = JunctionSelector< size_t, char, DefaultCallocAdjunct< size_t, char >, EquateRelationally >;
    static auto
        ListCollector = JunctionCollector< size_t, char, DefaultCallocAdjunct< size_t, char >, EquateRelationally, OrderRelationally >;
    static auto
        ListAxis = ReadAxis< size_t, char >;
    static auto
        MapCorrelator = JunctionCorrelator< size_t, char, int, DefaultCallocAssociativeAdjunct< size_t, char, int >, EquateRelationally >;
    static auto
        MapAssociator = JunctionAssociator< size_t, char, int, DefaultCallocAssociativeAdjunct< size_t, char, int >, EquateRelationally, OrderRelationally >;
    static auto
        MapDirection = ReadIncrementDirection< size_t, Associational< char, int > >;
    Junctive< size_t, char >
        list,
        base,
        relative;
    AssociativelyJunctive< size_t, char, int >
        map;
    auto FreeMemory = [&]( bool status ) -> bool {
        ListSequencer.secede( list );
        ListSequencer.secede( base );
        ListSequencer.secede( relative );
        MapCorrelator.disband( map );
        printf( "Freeing Linked List 1/4." );
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
        printf( "\n" );
        return status;
    };
    puts( "Junction" );
    Initialize( list );
    Initialize( base );
    Initialize( relative );
    Initialize( map );
    if (!ProceedSequence( list, ListSequencer, ListConjoiner ))
        return FreeMemory( false );
    printf( "Sequence = (" );
    DisplayCharacters( list, ListAxis.increment );
    puts( ")" );
    if (!ComposeSets( base, relative, ListSelector.composer ))
        return FreeMemory( false );
    printf( "Unordered Sets: Base = {" );
    DisplayCharacters( base, ListAxis.increment );
    printf( "}, Relative = {" );
    DisplayCharacters( relative, ListAxis.increment );
    puts( "}" );
    if (!ListSelector.section.unite( list, ListAxis.increment, base, ListAxis.increment, relative ))
        return FreeMemory( false );
    printf( "Unordered Union Of Base And Relative = {" );
    DisplayCharacters( list, ListAxis.increment );
    puts( "}" );
    if (!ComposeSets( base, relative, ListCollector.selector.composer ))
        return FreeMemory( false );
    printf( "Ordered Sets: Base = {" );
    DisplayCharacters( base, ListAxis.increment );
    printf( "}, Relative = {" );
    DisplayCharacters( relative, ListAxis.increment );
    puts( "}" );
    if (!ListCollector.bisection.unite( list, ListAxis, base, ListAxis, relative ))
        return FreeMemory( false );
    printf( "Ordered Union Of Base And Relative = {" );
    DisplayCharacters( list, ListAxis.increment );
    puts( "}" );
    if (!AssociateMap( map, MapCorrelator ))
        return FreeMemory( false );
    printf( "Unordered Map: [" );
    DisplayMappings( map, MapDirection );
    puts( "]" );
    if (!AssociateMap( map, MapAssociator ))
        return FreeMemory( false );
    printf( "Ordered Map: [" );
    DisplayMappings( map, MapDirection );
    puts( "]" );
    return FreeMemory( true );
}

static bool
QueueDemonstrations( void ) {
    if (!DemonstrateLocalization()) {
        fprintf( stderr, "ERROR during localization demonstration\n" );
        return false;
    }
    printf( "\n" );
    if (!DemonstrateSegmentation()) {
        fprintf( stderr, "ERROR during segmentation demonstration\n" );
        return false;
    }
    printf( "\n" );
    if (!DemonstrateOrdination()) {
        fprintf( stderr, "ERROR during ordination demonstration\n" );
        return false;
    }
    printf( "\n" );
    if (!DemonstrateJunction()) {
        fprintf( stderr, "ERROR during junction demonstration\n" );
        return false;
    }
    return true;
}

int
main() {
    return QueueDemonstrations()
        ? 0
        : -1
        ;
}
