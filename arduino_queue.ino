// � 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
//
// Arduino specific code was based on The Arduino Reference analogRead() example
// https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
// The Arduino Reference text is licensed under a Creative Commons
// Attribution-Share Alike 3.0 License.
//

/*
   Stores the last 8 analog sample readings in a very fast queue object.
   Prints the queue to the serial monitor after every sample reading.
*/
#define ANALOG_PIN A3
#define SERIAL_RATE 9600
#define QUEUE_MAX 8
#define SIZES_TYPE unsigned int
#define SAMPLES_TYPE int
#define RAPBTL_NO_STD_CPLUSPLUS
#include "ration/contraction.hpp"

using namespace ration::contraction;
using queue_t = Contractional<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;

constexpr SIZES_TYPE BaseOffset = 0, OneSample = 1;
queue_t queue;

static void printQueue()
{
    static auto& Increment = ReadIncrementDirection<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    SIZES_TYPE position;
    if (!Increment.begins(queue, BaseOffset))
        return;
    Increment.scale.begin(queue, position, BaseOffset);
    Serial.print(F("Queue: "));
    while (true) {
        Serial.print(Increment.scale.go(queue, position).to);
        if (!Increment.traverses(queue, position, OneSample))
            break;
        Increment.scale.traverse(queue, position, OneSample);
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
    static auto& Contractor = SureContractor<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    static auto& Increment = WriteIncrementDirection<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    SIZES_TYPE position;
    if (Contractor.account(queue) == Contractor.survey(queue))
        Contractor.retract(queue, OneSample);
    Contractor.protract(queue, position, OneSample);
    Increment.scale.go(queue, position).to = analogRead(ANALOG_PIN);
    printQueue();
}
