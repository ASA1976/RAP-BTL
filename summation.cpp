// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "iteration.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
#include <stdio.h>
#endif

using namespace ::iteration;

static inline void
SumIndices(
    Referential< int >
        operand,
    Referential< const int >
        index,
    Referential< const int >
        lower,
    Referential< const int >
        upper
) {
    operand += index;
}

template <
    typename Spatial,
    typename Positional,
    typename Natural,
    typename Elemental
>
static inline bool
DisplayList(
    Referential< Spatial >
        list,
    Referential< const Directional< Spatial, Positional, Natural, Elemental > >
        direction,
    const Locational< const char >
        format
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
        printf( format, direction.scale.go( list, position ).to );
        if (!direction.traverses( list, position, 1 ))
            break;
    }
    return true;
}

int main() {
    static auto&
        Increment = IncrementIteratingDirection< int, unsigned int, int, SumIndices >;
    static const int
        Lower = 0,
        Upper = 9;
    int
        sum;
    Iterative< int, int >
        sigma = {Lower, Upper, sum};
    sum = 0;
    printf( "Sigma( %d <= i => %d := |%u| ) i\n", Lower, Upper, Increment.survey( sigma ) );
    DisplayList( sigma, Increment, "Sum = %d\n" );
}
