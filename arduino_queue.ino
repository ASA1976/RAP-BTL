// � 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
//
// Arduino specific code was based on The Arduino Reference analogRead() example
// https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
// The Arduino Reference text is licensed under a Creative Commons 
// Attribution-Share Alike 3.0 License.
//
#define ANALOG_PIN A3
#define SERIAL_RATE 9600
#define SIZES_TYPE uint8_t
#define QUEUE_MAX 8
#define RAPBTL_NO_STD_CPLUSPLUS
#include "ration/contraction.hpp"

using namespace ration::contraction;
using queue_t = Contractional<SIZES_TYPE, QUEUE_MAX, int>;

queue_t queue; // This defaults to all zero, a valid initial state for this type

void printQueue() {
    static auto& Reader = ReadIncrementDirection<SIZES_TYPE, QUEUE_MAX, int>;
    SIZES_TYPE position; // Initialized by 'begin' below, otherwise unused
    if (!Reader.begins(queue, 0))
        return; // Queue was empty
    Reader.scale.begin(queue, position, 0);
    Serial.println(""); // For some clarity
    while (true) {
        Serial.println(Reader.scale.go(queue, position).to);
        if (!Reader.traverses(queue, position, 1))
            return; // End of the queue
        Reader.scale.traverse(queue, position, 1);
    }
}

void setup() {
    Serial.begin(SERIAL_RATE); 
}

void loop() {
    static auto& Manager = Contractor<SIZES_TYPE, QUEUE_MAX, int>;
    static auto& Writer = WriteIncrementDirection<SIZES_TYPE, QUEUE_MAX, int>;
    SIZES_TYPE position; // Initialized by 'protract' below, otherwise unused
    if (Manager.account(queue) == Manager.survey(queue)) // Is the queue full?
        Manager.retract(queue, 1); // Dequeue first sample space
    Manager.protract(queue, position, 1); // Enqueue new sample space
    Writer.scale.go(queue, position).to = analogRead(ANALOG_PIN);
    printQueue(); 
}
