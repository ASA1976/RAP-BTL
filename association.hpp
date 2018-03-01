// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ASSOCIATION_MODULE
#define ASSOCIATION_MODULE
#include "location.hpp"

namespace association {

    using namespace ::location;

    template <
        typename Consolidative,
        typename Natural,
        typename Correlative,
        typename Evaluative
    >
    struct Associative {

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Natural >
        ) >
            prepare;

        Referential< Natural(
            Referential< const Consolidative >
        ) >
            grade;

        Referential< bool(
            Referential< const Consolidative >,
            Referential< const Correlative >
        ) >
            correspond;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Correlative >,
            Referential< const Evaluative >
        ) >
            associate;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Correlative >,
            Referential< const Correlative >
        ) >
            reassociate;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Correlative >
        ) >
            disassociate;

        Referential< bool(
            Referential< Consolidative >
        ) >
            disband;

        Referential< bool(
            Referential< Consolidative >
        ) >
            dissolve;

    };

    template <
        typename Correlative,
        typename Evaluative
    >
    struct Associational {

        Correlative
            relator;

        Evaluative
            value;

    };

}

#endif
