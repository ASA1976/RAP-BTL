// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
// #define RAPBTL_NO_STD_CPLUSPLUS 1
#include "segmentation.hpp"
#include "sortation.hpp"
#ifndef RAPBTL_NO_STD_CPLUSPLUS
#include <cstdio>
#include <cstring>
#else
#include <stdio.h>
#include <string.h>
#endif

using namespace ::location;
using namespace ::trajection;

#if defined( _MSC_VER ) && _MSC_VER < 1921
template bool ::comparison::IsLesser(Referential< const int >, Referential< const int >);
template bool ::comparison::IsEqual(Referential< const int >, Referential< const int >);
#endif

template <
	typename Spatial,
	typename Positional,
	typename Natural
>
static inline bool
OutputIntegers(
	Referential< const Spatial >
		list,
	Referential< const Scalar< const Spatial, Positional, Natural, const int > >
		scale,
	Referential< const Natural >
		count,
	Locational< FILE >
		handle
) {
	Positional
		position;
	Natural
		index;
	scale.begin(list, position, 0);
	for (index = 0; index < count; index++) {
		fprintf( handle, "%d\n", scale.go(list, position).to );
		scale.traverse( list, position, 1 );
	}
	return true;
}

int
main(
	int
		argc,
	Locational< Locational< char > >
		argv
) {
	using namespace ::comparison;
	using namespace ::segmentation;
	using namespace ::sortation;
	using IntegerSegmental = ReadLocal< int >;
	enum Erroneous {
		NumberOfArguments = -1,
		InputFile = -2,
		OutputFile = -3,
		IntegerCount = -4
	};
	static const unsigned
		CacheLimit = 0x2000,
		CacheReserve = 0x80;
	static const unsigned
		MaximumIntegers = (CacheLimit - CacheReserve) / sizeof(int);
	static auto&
		Increment = ReadIncrementScale< unsigned, unsigned, int >;
	static auto&
		SearchIntegers = SearchBisectionIteratively< IntegerSegmental, unsigned, unsigned, int, IsEqual, IsLesser, ReadLiner< unsigned, MaximumIntegers, int > >;
	Locational< FILE >
		input,
		output;
	int
		value, integers[MaximumIntegers];
	unsigned
		count, position, before, after;
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
	while (!feof(input)) {
		if (fscanf(input, "%d", Locate(value).at) == 1) {
			integers[0] = value;
			count = 1;
			position = before = after = 0;
			break;
		}
	}
	while (!feof(input)) {
		if (fscanf( input, "%d", Locate( value ).at ) == 1) {
			if (count == MaximumIntegers) {
				fprintf(stderr, "Maximum number of integers is %u\n", MaximumIntegers );
				if (output != stdout)
					fclose(output);
				fclose(input);
				return Erroneous::IntegerCount;
			}
			if (!SearchIntegers( integers, value, position, before, after )) {
				if (IsLesser( integers[position], value )) {
					if (after > 0) {
						memmove( integers + position + 2, integers + position + 1, after * sizeof( int ) );
					}
					integers[position + 1] = value;
				} else {
					memmove( integers + position + 1, integers + position, (after + 1) * sizeof(int) );
					integers[position] = value;
				}
				after++;
				count++;
			} else {
				fprintf(stderr, "Duplicate integer %d ignored\n", value);
			}
		}
	}
	OutputIntegers( static_cast< Locational< const int > >(integers), Increment, count, output );
	if (output != stdout)
		fclose(output);
	fclose(input);
}
