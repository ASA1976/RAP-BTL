// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS
#include <ration/collection.hpp>
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#else
extern "C" {
#include <stdio.h>
}
#endif

using namespace ::location;
using namespace ::trajection;

template <
    typename Spatial,
    typename Positional,
    typename Natural>
static inline bool
OutputIntegers(
    Referential<const Spatial>
        list,
    Referential<const Directional<const Spatial, Positional, Natural, const int>>
        direction,
    Locational<FILE>
        handle)
{
    Positional position;
    if (!direction.begins(list, 0))
        return false;
    direction.scale.begin(list, position, 0);
    while (true) {
        fprintf(handle, "%d\n", direction.scale.go(list, position).to);
        if (!direction.traverses(list, position, 1))
            break;
        direction.scale.traverse(list, position, 1);
    }
    return true;
}

int main(
    int
        argc,
    Locational<Locational<char>>
        argv)
{
    using namespace ::ration;
    using namespace ::ration::collection;
    using namespace ::ration::consecution;
    using namespace ::comparison;
    enum Erroneous {
        NumberOfArguments = -1,
        InputFile = -2,
        OutputFile = -3,
        IntegerCount = -4
    };
    static constexpr unsigned CacheLimit = 0x2000, CacheReserve = 0x80;
    static constexpr unsigned MaximumNodes = (CacheLimit - CacheReserve) / sizeof(int);
    using IntegerResourceful = Resourceful<unsigned, MaximumNodes, int>;
    static auto& Composer = SureOrderedComposer<unsigned, MaximumNodes, int, IsEqual<int>, IsLesser<int>, MoveElements<unsigned, int>>;
    static auto& Increment = ReadIncrementDirection<unsigned, MaximumNodes, int>;
    Locational<FILE> input, output;
    IntegerResourceful set;
    int value;
    output = stdout;
    switch (argc) {
    case 3:
        output = fopen(argv[2], "w");
        if (!output) {
            fprintf(stderr, "Could not write to file '%s'\n", argv[2]);
            return Erroneous::OutputFile;
        }
    case 2:
        input = fopen(argv[1], "r");
        if (!input) {
            fprintf(stderr, "Could not read from file '%s'\n", argv[1]);
            return Erroneous::InputFile;
        }
        break;
    default:
        fprintf(stderr, "%s input_file_path ?output_file_path?\n", argv[0]);
        return Erroneous::NumberOfArguments;
    }
    Initialize(set);
    while (!feof(input)) {
        if (fscanf(input, "%d", Locate(value).at) == 1) {
            if (Account(set) == MaximumNodes) {
                fprintf(stderr, "Maximum number of integers is %u\n", MaximumNodes);
                if (output != stdout)
                    fclose(output);
                fclose(input);
                return Erroneous::IntegerCount;
            }
            if (!Composer.compose(set, value))
                fprintf(stderr, "Duplicate integer %d ignored\n", value);
        }
    }
    OutputIntegers(set, Increment, output);
    if (output != stdout)
        fclose(output);
    fclose(input);
}
