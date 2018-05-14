// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "segmentation.hpp"
#include "ordination.hpp"
#include "junction/stdlib.hpp"
#include "junction/selection.hpp"
#include "junction/collection.hpp"
#include "junction/association/selection.hpp"
#include "junction/association/collection.hpp"
#include <cstdio>
#include <type_traits>

using namespace ::composition;
using namespace ::association;
using namespace ::consecution;

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
    using namespace ::std;
    static_assert(
        is_integral< Natural >::value && is_unsigned< Natural >::value,
        "Natural:  Unsigned integer type required"
    );
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
    using namespace ::std;
    static_assert(
        is_integral< Natural >::value && is_unsigned< Natural >::value,
        "Natural:  Unsigned integer type required"
    );
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
    Referential< const Conjoint< Spatial, Positional, const Locational< const char >, Locational< const char >, char > >
        conjoiner
) {
    using namespace ::segmentation;
    using namespace ::std;
    static_assert(
        is_integral< Natural >::value && is_unsigned< Natural >::value,
        "Natural:  Unsigned integer type required"
    );
    static const Natural
        Length = 7;
    static Referential< const Directional< ReadLocal< char >, ReadPositional< char >, const char > >
        Direction = ReadIncrementDirection< Natural, Length, char >;
    static const char
        Message[Length] = {'M', 'E', 'S', 'S', 'A', 'G', 'E'};
    static const ReadPositional< char >
        First = Message,
        Last = Message + Length - 1;
    sequencer.secede( list );
    sequencer.antecede( list, Length );
    return conjoiner.proceed( list, Direction, Message, First, Last );
}

template <
    typename Spatial,
    typename Positional
>
static bool
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
static bool
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
        && DisplayCharacters( list, direction.scale, count );
}

template <
    typename Spatial,
    typename Positional
>
static bool
DisplayMappings(
    Referential< const Spatial >
        map,
    Referential< const Directional< const Spatial, Positional, const Associational< char, int > > >
        direction
) {
    Referential< const Scalar< const Spatial, Positional, const Associational< char, int > > >
        scale = direction.scale;
    Positional
        position;
    if (!direction.begins( map ))
        return false;
    for (scale.begin( map, position ); true; scale.traverse( map, position )) {
        Referential< const Associational< char, int > >
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
    using Positional = ReadPositional< char >;
    static Referential< const Scalar< Local, Positional, const char > >
        Scale = ReadIncrementScale< char >;
    static Local
        locality = "ABCDE";
    puts( "Localization (Pointer Only)" );
    printf( "locality := " );
    DisplayCharacters( locality, Scale, 5 );
    puts( "" );
    return true;
}

static bool
DemonstrateSegmentation( void ) {
    using namespace ::segmentation;
    using namespace ::sortation;
    using Segmental = ReadLocal< char >;
    using Positional = ReadPositional< char >;
    using Bisectional = bool(
        Referential< const Segmental >,
        Referential< const Axial< const Segmental, Positional, const char > >,
        Referential< const size_t >,
        Referential< const char >,
        Referential< Positional >
    );
    static const size_t
        Length = 5;
    static Referential< const Axial< Segmental, Positional, const char > >
        Axis = ReadAxis< size_t, Length, char >;
    static Referential< Bisectional >
        FindCharacter = SearchBisectionally< Segmental, Positional, size_t, char, EquateRelationally, OrderRelationally >;
    static Segmental
        segment = "ABCDE";
    Positional
        position;
    puts( "Segmentation (Pointer And Predetermined Length)" );
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
    using Bisectional = bool(
        Referential< const Ordinal >,
        Referential< const Axial< const Ordinal, Positional, const char > >,
        Referential< const size_t >,
        Referential< const char >,
        Referential< Positional >
    );
    static Referential< const Axial< Ordinal, Positional, const char > >
        Axis = ReadAxis< size_t, Length, char >;
    static Referential< Bisectional >
        FindCharacter = SearchBisectionally< Ordinal, Positional, size_t, char, EquateRelationally, OrderRelationally >;
    static Ordinal
        array = {'A','B','C','D','E'};
    Positional
        position;
    puts( "Ordination (Array)" );
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
    using namespace ::junction::stdlib;
    using namespace ::junction::consecution;
    using namespace ::junction::selection;
    using namespace ::junction::collection;
    using namespace ::junction::association;
    using namespace ::junction::association::selection;
    using namespace ::junction::association::collection;
    static Referential< const Sequent< Junctive< size_t, char >, Positional< char >, size_t, char > >
        ListSequencer = JunctionSequencer< size_t, char, DefaultCallocAdjunct< size_t, char > >;
    static Referential< const Conjoint< Junctive< size_t, char >, Positional< char >, const Locational< const char >, Locational< const char >, char > >
        ListConjoiner = JunctionConjoiner< const Locational< const char >, Locational< const char >, size_t, char, DefaultCallocAdjunct< size_t, char > >;
    static Referential< const Selective< Junctive< size_t, char >, Positional< char >, size_t, char > >
        ListSelector = JunctionSelector< size_t, char, DefaultCallocAdjunct< size_t, char >, EquateRelationally >;
    static Referential< const Collective< Junctive< size_t, char >, Positional< char >, size_t, char > >
        ListCollector = JunctionCollector< size_t, char, DefaultCallocAdjunct< size_t, char >, EquateRelationally, OrderRelationally >;
    static Referential< const Axial< const Junctive< size_t, char >, Positional< char >, const char > >
        ListAxis = ReadAxis< size_t, char >;
    static Referential< const Associative< AssociativelyJunctive< size_t, char, int >, size_t, char, int > >
        MapCorrelator = JunctionCorrelator< size_t, char, int, DefaultCallocAdjunct< size_t, Associational< char, int > >, EquateRelationally >;
    static Referential< const Associative< AssociativelyJunctive< size_t, char, int >, size_t, char, int > >
        MapAssociator = JunctionAssociator< size_t, char, int, DefaultCallocAdjunct< size_t, Associational< char, int > >, EquateRelationally, OrderRelationally >;
    static Referential< const Directional< const AssociativelyJunctive< size_t, char, int >, AssociativelyPositional< char, int >, const Associational< char, int > > >
        MapDirection = ReadIncrementDirection< size_t, Associational< char, int > >;
    struct LocalJunctive {

        Junctive< size_t, char >
            list,
            base,
            relative;

        AssociativelyJunctive< size_t, char, int >
            map;

        LocalJunctive() {
            Initialize( list );
            Initialize( base );
            Initialize( relative );
            Initialize( map );
        }

        ~LocalJunctive() {
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
        }

    }
        junctions;
    puts( "Junction (Linked List And Map)" );
    if (!ProceedSequence( junctions.list, ListSequencer, ListConjoiner ))
        return false;
    printf( "Sequence = (" );
    DisplayCharacters( junctions.list, ListAxis.increment );
    puts( ")" );
    if (!ComposeSets( junctions.base, junctions.relative, ListSelector.composer ))
        return false;
    printf( "Unordered Sets: Base = {" );
    DisplayCharacters( junctions.base, ListAxis.increment );
    printf( "}, Relative = {" );
    DisplayCharacters( junctions.relative, ListAxis.increment );
    puts( "}" );
    if (!ListSelector.section.unite( junctions.list, ListAxis.increment, junctions.base, ListAxis.increment, junctions.relative ))
        return false;
    printf( "Unordered Union Of Base And Relative = {" );
    DisplayCharacters( junctions.list, ListAxis.increment );
    puts( "}" );
    if (!ComposeSets( junctions.base, junctions.relative, ListCollector.selector.composer ))
        return false;
    printf( "Ordered Sets: Base = {" );
    DisplayCharacters( junctions.base, ListAxis.increment );
    printf( "}, Relative = {" );
    DisplayCharacters( junctions.relative, ListAxis.increment );
    puts( "}" );
    if (!ListCollector.bisection.unite( junctions.list, ListAxis, junctions.base, ListAxis, junctions.relative ))
        return false;
    printf( "Ordered Union Of Base And Relative = {" );
    DisplayCharacters( junctions.list, ListAxis.increment );
    puts( "}" );
    if (!AssociateMap( junctions.map, MapCorrelator ))
        return false;
    printf( "Unordered Map: [" );
    DisplayMappings( junctions.map, MapDirection );
    puts( "]" );
    if (!AssociateMap( junctions.map, MapAssociator ))
        return false;
    printf( "Ordered Map: [" );
    DisplayMappings( junctions.map, MapDirection );
    puts( "]" );
    return true;
}

static bool
QueueDemonstrations( void ) {
    if (!DemonstrateLocalization()) {
        fprintf( stderr, "ERROR during localization demonstration\n" );
        return false;
    }
    puts( "" );
    if (!DemonstrateSegmentation()) {
        fprintf( stderr, "ERROR during segmentation demonstration\n" );
        return false;
    }
    puts( "" );
    if (!DemonstrateOrdination()) {
        fprintf( stderr, "ERROR during ordination demonstration\n" );
        return false;
    }
    puts( "" );
    if (!DemonstrateJunction()) {
        fprintf( stderr, "ERROR during junction demonstration\n" );
        return false;
    }
    return true;
}

int
main() {
    return QueueDemonstrations() ? 0 : -1;
}
