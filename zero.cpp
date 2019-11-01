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
using namespace ::comparison;

template <const size_t Length>
static inline bool
Find(
    Referential<const char[Length]>
        array,
    Referential<const char>
        value,
    Referential<Locational<const char>>
        position,
    Referential<BinaryComparative<char>>
        equate,
    Referential<BinaryComparative<char>>
        order)
{
    using namespace ::ordination;
    using namespace ::sortation;
    static auto& Liner = ReadLiner<size_t, Length, char>;
    static const size_t Before = 0, After = Length - 1;
    if (Length < 1)
        return false;
    position = array;
    return SearchBisection(array, Liner, value, position, Before, After, equate, order);
}

int main()
{
    static const char array[] = { 'A', 'C', 'E', 'G', 'I', 'K', 'M' }, key = 'G';
    static Locational<const char> locality;
    static unsigned offset;
    if (!Find(array, key, locality, IsEqual, IsLesser))
        return -1;
    offset = locality - array;
    printf("array[%u] = '%c'\n", offset, Refer(locality).to);
}
