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
#include <ration/consecution.hpp>
#include <sortation.hpp>

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
    using namespace sortation;
    using namespace ration::consecution;
    static auto& Sequencer = SureSequencer<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE, MoveElements<SIZES_TYPE, SAMPLES_TYPE>>;
    static auto& Liner = ReadLiner<SIZES_TYPE, SEQUENCE_MAX, SAMPLES_TYPE>;
    static auto& Equate = IsEqual<SAMPLES_TYPE>;
    static auto& Order = IsGreater<SAMPLES_TYPE>;
    static const SIZES_TYPE ZeroSize = 0;
    position_t position;
    SAMPLES_TYPE sample;
    sample = analogRead(ANALOG_PIN);
    if (resource.allotment > ZeroSize) {
        Liner.decrement.begin(resource, position, BASE_OFFSET);
        if (sample > Liner.decrement.go(resource, position).to) {
            if (!SearchBisection(resource, Liner, sample, position, resource.allotment - 1, ZeroSize, Equate, Order)) {
                if (resource.allotment == SEQUENCE_MAX)
                    Sequencer.recede(resource, ONE_SAMPLE);
                if (resource.allotment > ZeroSize) {
                    Liner.increment.begin(resource, position, BASE_OFFSET);
                    SearchBisection(resource, Liner, sample, position, ZeroSize, resource.allotment - 1, Equate, Order);
                    if (sample > Liner.increment.go(resource, position).to) {
                        Sequencer.precede(resource, position, sample);
                    } else {
                        Sequencer.cede(resource, position, sample);
                    }
                } else {
                    Sequencer.accede(resource, sample);
                }
            }
        }
    } else {
        Sequencer.accede(resource, sample);
    }
    printSequence();
}
