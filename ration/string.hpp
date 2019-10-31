// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef RATION_STRING_MODULE
#define RATION_STRING_MODULE
#include "../location.hpp"
#include "../ration.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstring>
#else
extern "C" {
#include <string.h>
}
#endif

namespace ration {

/**
     * @brief
     *     Array sequence memory move implementation using one of either the C 
     *     or C++ standard memmove library function.
     * @details
     *     Association
     *     -----------
     *     C or C++ standard library based function which implements the Moving
     *     function type.
     */
namespace string {

    using ::location::Locational;

    template <
        typename Natural,
        typename Elemental>
    static inline bool
    MoveBytes(
        Locational<Elemental>
            from,
        Locational<Elemental>
            to,
        Natural
            count)
    {
        return memmove(to, from, count * sizeof(Elemental));
    }

}

}

#endif
