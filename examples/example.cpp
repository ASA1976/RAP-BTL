// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include <junction/association/collection.hpp>
#include <junction/association/selection.hpp>
#include <junction/collection.hpp>
#include <junction/selection.hpp>
#include <junction/stdlib.hpp>
#include <ration/association/collection.hpp>
#include <ration/association/selection.hpp>
#include <ration/collection.hpp>
#include <ration/selection.hpp>
#include <ration/string.hpp>
#include <segmentation.hpp>
#include <automation.hpp>
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
using MessageLocal = const Locational<const char>;
using MapComplementary = Complementary<char, int>;
using ListAdjunctive = DoublyAdjunctive<size_t, char>;
using MapAdjunctive = DoublyAdjunctive<size_t, MapComplementary>;
constexpr ListAdjunctive ListAdjunct = DefaultMallocDoubleAdjunct<size_t, char>;
constexpr MapAdjunctive MapAdjunct = DefaultMallocDoubleAdjunct<size_t, MapComplementary>;

#if defined(_MSC_VER) && _MSC_VER < 1921
template bool ::comparison::IsLesser(Referential<const char>, Referential<const char>);
template bool ::comparison::IsEqual(Referential<const char>, Referential<const char>);
template bool ::ration::string::MoveBytes(Locational<char>, Locational<char>, size_t);
template bool ::ration::string::MoveBytes(Locational<MapComplementary>, Locational<MapComplementary>, size_t);
#endif

template <
    typename Spatial,
    typename Natural>
static bool
ComposeSets(
    Referential<Spatial>
        base,
    Referential<Spatial>
        relative,
    Referential<const Compositional<Spatial, Natural, char>>
        composer)
{
    composer.decompose(base);
    composer.decompose(relative);
    composer.precompose(base, 3);
    composer.precompose(relative, 3);
    return composer.compose(base, 'Y')
        && composer.compose(base, 'A')
        && composer.compose(base, 'M')
        && composer.compose(relative, 'M')
        && composer.compose(relative, 'B')
        && composer.compose(relative, 'Z');
}

template <
    typename Spatial,
    typename Natural>
static bool
AssociateMap(
    Referential<Spatial>
        map,
    Referential<const Associative<Spatial, Natural, char, int>>
        associator)
{
    associator.disband(map);
    associator.prepare(map, 3);
    return associator.associate(map, 'y', 1)
        && associator.associate(map, 'z', -1)
        && associator.associate(map, 'x', 0);
}

template <
    typename Spatial,
    typename Positional,
    typename Natural>
static bool
ProceedSequence(
    Referential<Spatial>
        list,
    Referential<const Sequent<Spatial, Positional, Natural, char>>
        sequencer,
    Referential<const Conjoint<Spatial, Positional, MessageLocal, Natural, Natural, char>>
        conjoiner)
{
    using namespace ::segmentation;
    static const Natural Length = 7;
    static auto& Direction = ReadIncrementDirection<Natural, Length, char>;
    static const char Message[Length] = { 'M', 'E', 'S', 'S', 'A', 'G', 'E' };
    static const Natural First = 0, Last = Length - 1;
    sequencer.secede(list);
    sequencer.antecede(list, Length);
    return conjoiner.proceed(list, Direction, Message, First, Last);
}

template <
    typename Spatial,
    typename Positional,
    typename Natural>
static bool
DisplayCharacters(
    Referential<const Spatial>
        list,
    Referential<const Directional<const Spatial, Positional, Natural, const char>>
        direction)
{
    Positional position;
    if (!direction.begins(list, 0))
        return false;
    direction.scale.begin(list, position, 0);
    while (true) {
        printf("'%c'", direction.scale.go(list, position).to);
        if (!direction.traverses(list, position, 1))
            break;
        direction.scale.traverse(list, position, 1);
        printf(",");
    }
    return true;
}

template <
    typename Spatial,
    typename Positional,
    typename Natural>
static bool
DisplayMappings(
    Referential<const Spatial>
        map,
    Referential<const Directional<const Spatial, Positional, Natural, const MapComplementary>>
        direction)
{
    Positional position;
    if (!direction.begins(map, 0))
        return false;
    direction.scale.begin(map, position, 0);
    while (true) {
        auto& mapping = direction.scale.go(map, position).to;
        printf("%c=%d", mapping.relator, mapping.value);
        if (!direction.traverses(map, position, 1))
            break;
        printf(" ");
        direction.scale.traverse(map, position, 1);
    }
    return true;
}

static bool
DemonstrateRation()
{
    using namespace ::ration;
    using namespace ::ration::consecution;
    using namespace ::ration::selection;
    using namespace ::ration::collection;
    using namespace ::ration::association;
    using namespace ::ration::association::selection;
    using namespace ::ration::association::collection;
    using namespace ::ration::string;
    using namespace ::comparison;
    constexpr size_t Length = 16;
    using ListResourceful = Resourceful<size_t, Length, char>;
    using MapResourceful = AssociativelyResourceful<size_t, Length, char, int>;
    static auto& ListSequencer = SureSequencer<size_t, Length, char, MoveBytes>;
    static auto& ListConjoiner = SureConjoiner<MessageLocal, size_t, size_t, size_t, Length, char, MoveBytes>;
    static auto& ListSelector = SureSelector<size_t, Length, char, IsEqual, MoveBytes>;
    static auto& ListCollector = SureCollector<size_t, Length, char, IsEqual, IsLesser, MoveBytes>;
    static auto& ListAxis = ReadAxis<size_t, Length, char>;
    static auto& MapCorrelator = SureCorrelator<size_t, Length, char, int, IsEqual, MoveBytes>;
    static auto& MapAssociator = SureAssociator<size_t, Length, char, int, IsEqual, IsLesser, MoveBytes>;
    static auto& MapDirection = ReadIncrementDirection<size_t, Length, MapComplementary>;
    ListResourceful list, base, relative;
    MapResourceful map;
    Initialize(list);
    Initialize(base);
    Initialize(relative);
    Initialize(map);
    puts("Ration (Array List And Map)");
    if (!ProceedSequence(list, ListSequencer, ListConjoiner))
        return false;
    printf("Sequence = (");
    DisplayCharacters(list, ListAxis.increment);
    puts(")");
    if (!ComposeSets(base, relative, ListSelector.composer))
        return false;
    printf("Unordered Sets: Base = {");
    DisplayCharacters(base, ListAxis.increment);
    printf("}, Relative = {");
    DisplayCharacters(relative, ListAxis.increment);
    puts("}");
    if (!ListSelector.section.unite(list, ListAxis.increment, base, ListAxis.increment, relative))
        return false;
    printf("Unordered Union Of Base And Relative = {");
    DisplayCharacters(list, ListAxis.increment);
    puts("}");
    if (!ComposeSets(base, relative, ListCollector.selector.composer))
        return false;
    printf("Ordered Sets: Base = {");
    DisplayCharacters(base, ListAxis.increment);
    printf("}, Relative = {");
    DisplayCharacters(relative, ListAxis.increment);
    puts("}");
    if (!ListCollector.bisection.unite(list, ListAxis, base, ListAxis, relative))
        return false;
    printf("Ordered Union Of Base And Relative = {");
    DisplayCharacters(list, ListAxis.increment);
    puts("}");
    if (!AssociateMap(map, MapCorrelator))
        return false;
    printf("Unordered Map: [");
    DisplayMappings(map, MapDirection);
    puts("]");
    if (!AssociateMap(map, MapAssociator))
        return false;
    printf("Ordered Map: [");
    DisplayMappings(map, MapDirection);
    puts("]");
    return true;
}

static bool
DemonstrateJunction()
{
    using namespace ::junction::consecution;
    using namespace ::junction::selection;
    using namespace ::junction::collection;
    using namespace ::junction::association;
    using namespace ::junction::association::selection;
    using namespace ::junction::association::collection;
    using namespace ::comparison;
    using namespace ::automation;
    using ListJunctive = DoublyJunctive<size_t, char>;
    using MapJunctive = AssociativelyDoubleJunctive<size_t, char, int>;
    static auto& ListSequencer = DoubleSequencer<size_t, char, ListAdjunct>;
    static auto& ListConjoiner = DoubleConjoiner<MessageLocal, size_t, size_t, size_t, char, ListAdjunct>;
    static auto& ListSelector = DoubleSelector<size_t, char, IsEqual, ListAdjunct>;
    static auto& ListCollector = DoubleCollector<size_t, char, IsEqual, IsLesser, ListAdjunct>;
    static auto& ListAxis = ReadDoubleAxis<size_t, char>;
    static auto& MapCorrelator = DoubleCorrelator<size_t, char, int, IsEqual, MapAdjunct>;
    static auto& MapAssociator = DoubleAssociator<size_t, char, int, IsEqual, IsLesser, MapAdjunct>;
    static auto& MapDirection = ReadIncrementDoubleDirection<size_t, MapComplementary>;
    ListJunctive list, base, relative;
    MapJunctive map;
    auto cleaner = Automate([&]{
        ListSequencer.secede(list);
        ListSequencer.secede(base);
        ListSequencer.secede(relative);
        MapCorrelator.disband(map);
        printf("Freeing 1/4.");
        while (ListSequencer.condense(list))
            printf(".");
        printf(" 2/4.");
        while (ListSequencer.condense(base))
            printf(".");
        printf(" 3/4.");
        while (ListSequencer.condense(relative))
            printf(".");
        printf(" 4/4.");
        while (MapCorrelator.dissolve(map))
            printf(".");
        puts("");
    });
    Initialize(list);
    Initialize(base);
    Initialize(relative);
    Initialize(map);
    puts("Junction (Linked List And Map)");
    if (!ProceedSequence(list, ListSequencer, ListConjoiner))
        return false;
    printf("Sequence = (");
    DisplayCharacters(list, ListAxis.increment);
    puts(")");
    if (!ComposeSets(base, relative, ListSelector.composer))
        return false;
    printf("Unordered Sets: Base = {");
    DisplayCharacters(base, ListAxis.increment);
    printf("}, Relative = {");
    DisplayCharacters(relative, ListAxis.increment);
    puts("}");
    if (!ListSelector.section.unite(list, ListAxis.increment, base, ListAxis.increment, relative))
        return false;
    printf("Unordered Union Of Base And Relative = {");
    DisplayCharacters(list, ListAxis.increment);
    puts("}");
    if (!ComposeSets(base, relative, ListCollector.selector.composer))
        return false;
    printf("Ordered Sets: Base = {");
    DisplayCharacters(base, ListAxis.increment);
    printf("}, Relative = {");
    DisplayCharacters(relative, ListAxis.increment);
    puts("}");
    if (!ListCollector.bisection.unite(list, ListAxis, base, ListAxis, relative))
        return false;
    printf("Ordered Union Of Base And Relative = {");
    DisplayCharacters(list, ListAxis.increment);
    puts("}");
    if (!AssociateMap(map, MapCorrelator))
        return false;
    printf("Unordered Map: [");
    DisplayMappings(map, MapDirection);
    puts("]");
    if (!AssociateMap(map, MapAssociator))
        return false;
    printf("Ordered Map: [");
    DisplayMappings(map, MapDirection);
    puts("]");
    return true;
}

int main()
{
    enum Erroneous {
        RationDemonstration = -1,
        JunctionDemonstration = -2
    };
    if (!DemonstrateRation()) {
        fprintf(stderr, "ERROR during ration demonstration\n");
        return Erroneous::RationDemonstration;
    }
    puts("");
    if (!DemonstrateJunction()) {
        fprintf(stderr, "ERROR during junction demonstration\n");
        return Erroneous::JunctionDemonstration;
    }
}
