// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef ATTRIBUTION_MODULE
#define ATTRIBUTION_MODULE
#include "location.hpp"

namespace attribution {

    using ::location::Referential;

    template <
        typename Consolidative,
        typename Positional,
        typename Natural
    >
    struct Tributary {

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
            distribute;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Positional >
        ) >
            retribute;

        Referential< bool(
            Referential< Consolidative >
        ) >
            contribute;

    };

}

#endif


