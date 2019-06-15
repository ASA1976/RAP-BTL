// © 2019 Aaron Sami Abassi
// Licensed under the Academic Free License version 3.0
#ifndef TEST_CONDITIONS
#define TEST_CONDITIONS
#include <cstdio>

struct {

    void
    operator()() {
        puts( "Test1" );
    }

}
    Test1;

auto 
    Test2 = []() -> void {
        puts( "Test2" );
    };

void
Test3() {
    puts( "Test3" );
}

#endif
