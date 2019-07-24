// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include "ordination.hpp"
#include "sortation.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::location;

template <
    const size_t
        Length
>
static inline bool
FindInSortedArray(
    Referential< const char[Length] >
        array,
    Referential< const char >
        value,
    Referential< Locational< const char > >
        position
) {
    using namespace ::ordination;
    using namespace ::sortation;
    using namespace ::comparison;
    static auto&
        Liner = ReadLiner< size_t, Length, char >;
    static auto&
        Find = SearchBisection< char[Length], Locational< const char >, size_t, char, IsEqual, IsLesser >;
    position = array;
    return Find( array, Liner, value, position, 0, Length - 1 );
}

int
main() {
    static const char
        array[] = {'A','C','E','G','I','K','M'},
        key = 'G';
    static Locational< const char >
        locality;
    if (!FindInSortedArray( array, key, locality ))
        return -1;
    printf( "'%c'\n", Refer( locality ).to );
}
