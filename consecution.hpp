// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef CONSECUTION_MODULE
#define CONSECUTION_MODULE
#include "trajection.hpp"

namespace consecution {

    using namespace ::trajection;

    template <
        typename Consolidative,
        typename Positional,
        typename Relative,
        typename Appositional,
        typename Elemental
    >
    struct Conjoint {

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Directional< const Relative, Appositional, const Elemental > >,
            Referential< const Relative >,
            Referential< const Appositional >,
            Referential< const Appositional >
        ) >
            accede;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Positional >,
            Referential< const Directional< const Relative, Appositional, const Elemental > >,
            Referential< const Relative >,
            Referential< const Appositional >,
            Referential< const Appositional >
        ) >
            precede;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Directional< const Relative, Appositional, const Elemental > >,
            Referential< const Relative >,
            Referential< const Appositional >,
            Referential< const Appositional >
        ) >
            proceed;

    };

    template <
        typename Consolidative,
        typename Positional,
        typename Natural,
        typename Elemental
    >
    struct Sequent {

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Natural >
        ) >
            antecede;

        Referential< Natural(
            Referential< const Consolidative >
        ) >
            account;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Elemental >
        ) >
            accede;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Positional >,
            Referential< const Elemental >
        ) >
            precede;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Elemental >
        ) >
            proceed;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Natural >
        ) >
            succeed;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Positional >,
            Referential< const Natural >
        ) >
            concede;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Natural >
        ) >
            recede;

        Referential< bool(
            Referential< Consolidative >
        ) >
            secede;

        Referential< bool(
            Referential< Consolidative >
        ) >
            condense;

        Referential< const Conjoint< Consolidative, Positional, Consolidative, Positional, Elemental > >
            conjoiner;

    };

}

#endif
