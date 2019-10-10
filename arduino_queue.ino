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
#define SIZES_TYPE uint8_t
#define SAMPLES_TYPE int
// Use PROGMEM:
#define MEMORY(LITERAL) F(LITERAL)
// Use SRAM:
// #define MEMORY(LITERAL) LITERAL
// REQUIRED for use in Arduino sketches:
#define RAPBTL_NO_STD_CPLUSPLUS
#include "ration/contraction.hpp"

using namespace ration::contraction;
using queue_t = Contractional<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;

queue_t queue; // This defaults to all zero, a valid initial state for this type

void printQueue() {
    static auto& Reader = ReadIncrementDirection<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    SIZES_TYPE position; // Initialized by 'begin' below, otherwise unused
    if (!Reader.begins(queue, 0))
        return; // Queue was empty
    Reader.scale.begin(queue, position, 0);
    Serial.print(MEMORY("Queue: "));
    while (true) {
        Serial.print(Reader.scale.go(queue, position).to);
        if (!Reader.traverses(queue, position, 1))
            break; // End of the queue
        Reader.scale.traverse(queue, position, 1);
        Serial.print(MEMORY(", "));
    }
    Serial.println(MEMORY(""));
}

void setup() {
    Serial.begin(SERIAL_RATE); 
}

void loop() {
    // SureContractor performs size checks on each operation, which is slower
    // static auto& Manager = SureContractor<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    static auto& Manager = FastContractor<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    static auto& Writer = WriteIncrementDirection<SIZES_TYPE, QUEUE_MAX, SAMPLES_TYPE>;
    SIZES_TYPE position; // Initialized by 'protract' below, otherwise unused
    if (Manager.account(queue) == Manager.survey(queue)) // Is the queue full?
        Manager.retract(queue, 1); // Dequeue first sample space
    Manager.protract(queue, position, 1); // Enqueue new sample space
    Writer.scale.go(queue, position).to = analogRead(ANALOG_PIN);
    // Use Writer to move position forward after protracting more than 1
    printQueue(); 
}
