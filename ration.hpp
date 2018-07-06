// © 2018 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_MODULE
#define RATION_MODULE

namespace ration {

    template <
        typename Natural,
        Natural
            Maximum,
        typename Elemental
    >
    struct Resourceful {

        Natural
            allotment;

        Elemental
            source[Maximum];

    };

    template <
        typename Natural,
        Natural
            Maximum,
        typename Elemental
    >
    constexpr Resourceful< Natural, Maximum, Elemental >
    InitializedResource = {0};

}

#endif
