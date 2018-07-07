// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#include "ration/elevation.hpp"
#include "ration/contraction.hpp"
#include "ration/contribution.hpp"
#include "junction/provision/elevation.hpp"
#include "junction/provision/contraction.hpp"
#include "junction/provision/contribution.hpp"
#include <cstdio>

using namespace ::traction;
using namespace ::attribution;

using Natural = unsigned int;

template <
    typename Spatial,
    typename Positional
>
static inline void
TestElevation(
    Referential< Spatial >
        stack,
    Referential< const Tractile< Spatial, Positional, Natural > >
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
TestContraction(
    Referential< Spatial >
        queue,
    Referential< const Tractile< Spatial, Positional, Natural > >
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
TestContribution(
    Referential< Spatial >
        pool,
    Referential< const Tributary< Spatial, Positional, Natural > >
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
TestRation( void ) {
    using namespace ::ration::elevation;
    using namespace ::ration::contraction;
    using namespace ::ration::contribution;
    static auto&
        StackElevator = Elevator< Natural, 16, char >;
    static auto&
        QueueContractor = Contractor< Natural, 16, char >;
    static auto&
        PoolContributor = Contributor< Natural, 16, char >;
    Elevatory< Natural, 16, char >
        stack;
    Contractional< Natural, 16, char >
        queue;
    Contributory< Natural, 16, char >
        pool;
    Initialize( stack );
    Initialize( queue );
    Initialize( pool );
    TestElevation( stack, StackElevator );
    TestContraction( queue, QueueContractor );
    TestContribution( pool, PoolContributor );
}

static inline void
TestJunction( void ) {
    using namespace ::junction;
    using namespace ::junction::provision::elevation;
    using namespace ::junction::provision::contraction;
    using namespace ::junction::provision::contribution;
    using namespace ::allocation;
    static auto&
        StackElevator = Elevator< Natural, 16, char, FastDefaultNew< Junctional< char > > >;
    static auto&
        QueueContractor = Contractor< Natural, 16, char, FastDefaultNew< Junctional< char > > >;
    static auto&
        PoolContributor = Contributor< Natural, 16, char, FastDefaultNew< Junctional< char > > >;
    Junctive< Natural, char >
        list;
    Initialize( list );
    TestElevation( list, StackElevator );
    TestContraction( list, QueueContractor );
    TestContribution( list, PoolContributor );
}

int
main() {
    TestRation();
    puts( "" );
    TestJunction();
}
