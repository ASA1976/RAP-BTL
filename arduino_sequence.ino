// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
//
// Arduino specific code was based on The Arduino Reference analogRead() example
// https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
// The Arduino Reference text is licensed under a Creative Commons 
// Attribution-Share Alike 3.0 License.
//
#define ANALOG_PIN A3
#define SERIAL_RATE 9600
#define SEQUENCE_MAX 8
#define SIZES_TYPE unsigned int
#define SAMPLES_TYPE int
#define RAPBTL_NO_STD_CPLUSPLUS
#include "ration/consecution.hpp"
#include "sortation.hpp"

using namespace ration::consecution;
using sequence_t = Compact<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE>;
using read_position_t = ReadPositional<SAMPLES_TYPE>;
using write_position_t = WritePositional<SAMPLES_TYPE>;

sequence_t sequence;

static void printSequence() {
    static auto& Reader = ReadIncrementDirection<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE>;
    read_position_t position;
    if (!Reader.begins(sequence, 0))
        return; 
    Reader.scale.begin(sequence, position, 0);
    while (true) {
        Serial.print(Reader.scale.go(sequence, position).to);
        if (!Reader.traverses(sequence, position, 1))
            break;
        Reader.scale.traverse(sequence, position, 1);
        Serial.print(F(", "));
    }
    Serial.println(F(""));
}

void setup() {
    Serial.begin(SERIAL_RATE); 
}

void loop() {
    using namespace sortation;
    using namespace comparison;
    static auto& ArraySequencer = SureSequencer<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE, MoveElements<SIZES_TYPE, SAMPLES_TYPE>>;
    static auto& Search = SearchBisection<sequence_t, read_position_t, SIZES_TYPE, SAMPLES_TYPE>;
    static auto& Liner = ReadLiner<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE>;
    read_position_t read_position;
    write_position_t write_position;
    int sample;
    sample = analogRead(ANALOG_PIN);
    if (ArraySequencer.account(sequence) == 0) {
        ArraySequencer.accede(sequence, sample);
        return;
    }
    if (ArraySequencer.account(sequence) == SEQUENCE_MAX)
        ArraySequencer.recede(sequence, 1);
    Liner.increment.begin(sequence, read_position, 0);
    Search(sequence, Liner, sample, read_position, 0, ArraySequencer.account(sequence) - 1, IsEqual, IsGreater);
    write_position = const_cast<write_position_t>(read_position);
    if (sample > Liner.increment.go(sequence, read_position).to)
        ArraySequencer.precede(sequence, write_position, sample);
    else
        ArraySequencer.cede(sequence, write_position, sample);
    printSequence();
}
