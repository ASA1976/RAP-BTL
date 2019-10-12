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
#define SIZES_TYPE uint8_t
#define SAMPLES_TYPE int
#define RAPBTL_NO_STD_CPLUSPLUS
#include "junction/consecution.hpp"

using namespace junction;

using list_t = SinglyJunctive<SIZES_TYPE, SAMPLES_TYPE>;
using positional_t = SinglyPositional<SAMPLES_TYPE>;

list_t list;

static void printSequence() {
    static auto& Reader = ReadIncrementSingleDirection<SIZES_TYPE, SAMPLES_TYPE>;
    positional_t position;
    if (!Reader.begins(list, 0))
        return; 
    Reader.scale.begin(list, position, 0);
    while (true) {
        Serial.print(Reader.scale.go(list, position).to);
        if (!Reader.traverses(list, position, 1))
            break;
        Reader.scale.traverse(list, position, 1);
        Serial.print(F(", "));
    }
    Serial.println(F(""));
}

void setup() {
    using nodal_t = SinglyNodal<SAMPLES_TYPE>;
    static nodal_t nodes[SEQUENCE_MAX];
    IntegrateNodes(list, nodes);
    Serial.begin(SERIAL_RATE); 
}

void loop() {
    using namespace junction::consecution;
    using namespace sortation;
    using namespace comparison;
    static auto& Sequencer = SingleSequencer<SIZES_TYPE, SAMPLES_TYPE, DefaultStaticSingleAdjunct<SIZES_TYPE, SAMPLES_TYPE>>;
    static auto& Search = SearchScalarBisection<list_t, positional_t, SIZES_TYPE, SAMPLES_TYPE>;
    static auto& Scale = ReadIncrementSingleScale<SIZES_TYPE, SAMPLES_TYPE>;
    positional_t position;
    int sample;
    sample = analogRead(ANALOG_PIN);
    if (list.count == 0) {
        Sequencer.proceed(list, sample);
        return;
    }
    if (list.count == list.total)
        Sequencer.recede(list, 1);
    Scale.begin(list, position, 0);
    Search(list, Scale, sample, position, list.count - 1, IsEqual, IsGreater);
    if (Scale.go(list, position).to >= sample)
        Sequencer.cede(list, position, sample);
    else
        Sequencer.precede(list, position, sample);
    printSequence();
}
