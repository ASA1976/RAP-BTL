// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef TRACTION_MODULE
#define TRACTION_MODULE
#include "location.hpp"

namespace traction {

    using namespace ::location;

    template <
        typename Consolidative,
        typename Positional,
        typename Natural
    >
    struct Tractile {

        Referential< Natural(
            Referential< const Consolidative >
        ) >
            survey;

        Referential< Natural(
            Referential< const Consolidative >
        ) >
            account;

        Referential< bool(
            Referential< Consolidative >,
            Referential< Positional >
        ) >
            protract;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Natural >
        ) >
            retract;

        Referential< bool(
            Referential< Consolidative >
        ) >
            contract;

    };

}

#endif

