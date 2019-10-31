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
#define QUEUE_MAX 8
#define SIZES_TYPE unsigned int
#define SAMPLES_TYPE int
#define RAPBTL_NO_STD_CPLUSPLUS
#include "ration/contraction.hpp"

using namespace ration::contraction;
using queue_t = Contractional<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;

queue_t queue;

static void printQueue()
{
    static auto& Reader = ReadIncrementDirection<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    SIZES_TYPE position;
    if (!Reader.begins(queue, 0))
        return;
    Reader.scale.begin(queue, position, 0);
    Serial.print(F("Queue: "));
    while (true) {
        Serial.print(Reader.scale.go(queue, position).to);
        if (!Reader.traverses(queue, position, 1))
            break;
        Reader.scale.traverse(queue, position, 1);
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
    static auto& Manager = SureContractor<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    static auto& Writer = WriteIncrementDirection<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    SIZES_TYPE position;
    if (Manager.account(queue) == Manager.survey(queue))
        Manager.retract(queue, 1);
    Manager.protract(queue, position, 1);
    Writer.scale.go(queue, position).to = analogRead(ANALOG_PIN);
    printQueue();
}
