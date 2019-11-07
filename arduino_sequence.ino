// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
//
// Arduino specific code was based on The Arduino Reference analogRead() example
// https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
// The Arduino Reference text is licensed under a Creative Commons
// Attribution-Share Alike 3.0 License.
//

/*
   Stores the top 10 highest analog sample readings, ignoring duplicate values.
   Prints the sequence to the serial monitor after every sample reading.
*/
#define ANALOG_PIN A3
#define SERIAL_RATE 9600
#define SEQUENCE_MAX 10
#define SIZES_TYPE unsigned int
#define SAMPLES_TYPE int
#define BASE_OFFSET 0
#define ONE_SAMPLE 1
#define RAPBTL_NO_STD_CPLUSPLUS
#include "ration/collection.hpp"

using namespace ration;
using resource_t = Resourceful<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE>;
using position_t = ReadPositional<SAMPLES_TYPE>;

resource_t resource;

static void printSequence()
{
    using namespace ration::consecution;
    static auto& Increment = ReadIncrementDirection<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE>;
    position_t position;
    if (!Increment.begins(resource, BASE_OFFSET))
        return;
    Increment.scale.begin(resource, position, BASE_OFFSET);
    while (true) {
        Serial.print(Increment.scale.go(resource, position).to);
        if (!Increment.traverses(resource, position, ONE_SAMPLE))
            break;
        Increment.scale.traverse(resource, position, ONE_SAMPLE);
        Serial.print(F(", "));
    }
    Serial.println(F(""));
}

void setup()
{
    Serial.begin(SERIAL_RATE);
}

void loop()
{
    using namespace comparison;
    using namespace ration::consecution;
    using namespace ration::collection;
    static auto& Sequencer = SureSequencer<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE, MoveElements<SIZES_TYPE, SAMPLES_TYPE>>;
    static auto& Composer = SureOrderedComposer<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE, IsEqual<SAMPLES_TYPE>, IsGreater<SAMPLES_TYPE>, MoveElements<SIZES_TYPE, SAMPLES_TYPE>>;
    static auto& Decrement = ReadDecrementDirection<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE>;
    position_t position;
    int sample;
    sample = analogRead(ANALOG_PIN);
    if (Decrement.begins(resource, BASE_OFFSET)) {
        Decrement.scale.begin(resource, position, BASE_OFFSET);
        if (sample > Decrement.scale.go(resource, position).to) {
            if (!Composer.accredit(resource, sample)) {
                if (Sequencer.account(resource) == SEQUENCE_MAX)
                    Sequencer.recede(resource, ONE_SAMPLE);
                Composer.compose(resource, sample);
            }
        }
    } else {
        Sequencer.accede(resource, sample);
    }
    printSequence();
}
