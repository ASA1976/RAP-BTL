// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef COMPOSITION_MODULE
#define COMPOSITION_MODULE
#include "location.hpp"

namespace composition {

    using ::location::Referential;

    template <
        typename Consolidative,
        typename Natural,
        typename Elemental
    >
    struct Compositional {

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Natural >
        ) >
            precompose;

        Referential< bool(
            Referential< const Consolidative >,
            Referential< const Elemental >
        ) >
            accredit;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Elemental >
        ) >
            compose;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Elemental >,
            Referential< const Elemental >
        ) >
            recompose;

        Referential< bool(
            Referential< Consolidative >,
            Referential< const Elemental >
        ) >
            discompose;

        Referential< bool(
            Referential< Consolidative >
        ) >
            decompose;

        Referential< bool(
            Referential< Consolidative >
        ) >
            dispose;

    };

}

#endif
