// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include "allocation/alignment.hpp"
#include "ration/elevation.hpp"
#include "ration/contraction.hpp"
#include "ration/contribution.hpp"
#include "junction/provision/elevation.hpp"
#include "junction/provision/contraction.hpp"
#include "junction/provision/contribution.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::traction;
using namespace ::attribution;

template <
    typename Spatial,
    typename Positional
>
static inline void
DemonstrateElevation(
    Referential< Spatial >
        stack,
    Referential< const Tractile< Spatial, Positional, unsigned > >
        elevator
) {
    Positional
        position;
    printf( "Stack limit: %u\n", elevator.survey( stack ) );
    elevator.protract( stack, position, 2 );
    printf( "Stack size: %u\n", elevator.account( stack ) );
    elevator.retract( stack, elevator.account( stack ) );
    printf( "Stack size: %u\n", elevator.account( stack ) );
}

template <
    typename Spatial,
    typename Positional
>
static inline void
DemonstrateContraction(
    Referential< Spatial >
        queue,
    Referential< const Tractile< Spatial, Positional, unsigned > >
        contractor
) {
    Positional
        position;
    printf( "Queue limit: %u\n", contractor.survey( queue ) );
    contractor.protract( queue, position, 2 );
    printf( "Queue size: %u\n", contractor.account( queue ) );
    contractor.retract( queue, contractor.account( queue ) );
    printf( "Queue size: %u\n", contractor.account( queue ) );
}

template <
    typename Spatial,
    typename Positional
>
static inline void
DemonstrateContribution(
    Referential< Spatial >
        pool,
    Referential< const Tributary< Spatial, Positional, unsigned > >
        contributor
) {
    Positional
        position;
    printf( "Pool limit: %u\n", contributor.survey( pool ) );
    contributor.distribute( pool, position );
    printf( "Pool size: %u\n", contributor.account( pool ) );
    contributor.retribute( pool, position );
    printf( "Pool size: %u\n", contributor.account( pool ) );
}

static inline void
DemonstrateRation() {
    using namespace ::ration::elevation;
    using namespace ::ration::contraction;
    using namespace ::ration::contribution;
    static const unsigned
        Maximum = 16;
    static auto&
        StackElevator = Elevator< unsigned, Maximum, int >;
    static auto&
        QueueContractor = Contractor< unsigned, Maximum, int >;
    static auto&
        PoolContributor = Contributor< unsigned, Maximum, int >;
    Elevatory< unsigned, Maximum, int >
        stack;
    Contractional< unsigned, Maximum, int >
        queue;
    Contributory< unsigned, Maximum, int >
        pool;
    Initialize( stack );
    Initialize( queue );
    Initialize( pool );
    DemonstrateElevation( stack, StackElevator );
    DemonstrateContraction( queue, QueueContractor );
    DemonstrateContribution( pool, PoolContributor );
}

static inline void
DemonstrateJunction() {
    using namespace ::junction;
    using namespace ::junction::provision::elevation;
    using namespace ::junction::provision::contraction;
    using namespace ::junction::provision::contribution;
    using namespace ::allocation::alignment;
    using IntegerNodal = DoublyNodal< int >;
    static const unsigned
        Maximum = 16;
    static auto&
        StackElevator = DoubleElevator< unsigned, Maximum, int, FastDefaultAligned< IntegerNodal > >;
    static auto&
        QueueContractor = DoubleContractor< unsigned, Maximum, int, FastDefaultAligned< IntegerNodal > >;
    static auto&
        PoolContributor = DoubleContributor< unsigned, Maximum, int, FastDefaultAligned< IntegerNodal > >;
    DoublyJunctive< unsigned, int >
        list;
    Initialize( list );
    DemonstrateElevation( list, StackElevator );
    DemonstrateContraction( list, QueueContractor );
    DemonstrateContribution( list, PoolContributor );
}

int
main() {
    DemonstrateRation();
    puts( "" );
    DemonstrateJunction();
}
