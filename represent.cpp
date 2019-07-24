// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include "representation.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::location;

template <
    size_t
        Length
>
static inline void
DisplayHexByteList(
    Referential< const unsigned char[Length] >
        bytes
) {
    size_t
        count;
    for (count = 0; count < Length; count++) {
        printf( "%02X", bytes[count] );
        if (count < Length - 1)
            printf( ", " );
    }
}

template <
    typename Subjective
>
static inline void
DisplayHexMemory(
    Referential< const Subjective >
        subject
) {
    using namespace ::representation;
    DisplayHexByteList( AddressNatively( subject ) );
}

int
main() {
    puts( "" );
    puts( "Literal 7 Hex Byte List: " );
    DisplayHexMemory( 7 );
    puts( "" );
    puts( "" );
    puts( "Literal true Hex Byte List: " );
    DisplayHexMemory( true );
    puts( "" );
    puts( "" );
    puts( "Literal 3.14159 Hex Byte List: " );
    DisplayHexMemory( 3.14159 );
    puts( "" );
    puts( "" );
}
