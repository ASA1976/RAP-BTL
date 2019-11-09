// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include <junction/consecution.hpp>
#include <junction/contribution.hpp>
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::junction;
using namespace ::junction::contribution;
using namespace ::consecution;
constexpr unsigned short NodePoolSize = 3;
using PoolNodal = Contributory<unsigned short, NodePoolSize, SinglyNodal<char>>;
using PoolAdjunctive = SinglyAdjunctive<unsigned short, char>;

PoolNodal NodePool;
// Use SurePoolSingleAdjunct if overflowing the pool is a possibility
constexpr PoolAdjunctive NodePoolAdjunct = FastPoolSingleAdjunct<unsigned short, NodePoolSize, char, NodePool>;

template <
    typename Spatial,
    typename Positional,
    typename Natural>
static inline bool
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
static inline void
DemonstrateSequence(
    Referential<Spatial>
        sequence,
    Referential<const Sequent<Spatial, Positional, Natural, char>>
        sequencer,
    Referential<const Directional<const Spatial, Positional, Natural, const char>>
        increment)
{
    sequencer.antecede(sequence, 3);
    sequencer.proceed(sequence, 'B');
    sequencer.accede(sequence, 'A');
    sequencer.proceed(sequence, 'C');
    DisplayCharacters(sequence, increment);
    puts(" (should read 'A','B','C')");
    sequencer.succeed(sequence, 1);
    sequencer.recede(sequence, 1);
    DisplayCharacters(sequence, increment);
    puts(" (should read 'B')");
    sequencer.secede(sequence);
    while (sequencer.condense(sequence))
        ;
}

int main()
{
    using namespace ::junction::consecution;
    using ListJunctive = SinglyJunctive<unsigned short, char>;
    static auto& Sequencer = SingleSequencer<unsigned short, char, NodePoolAdjunct>;
    static auto& Increment = ReadIncrementSingleDirection<unsigned short, char>;
    ListJunctive list;
    Initialize(list);
    DemonstrateSequence(list, Sequencer, Increment);
}
