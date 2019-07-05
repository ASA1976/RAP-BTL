# Relational Association Programming - Basic Template Library

Note: This is a **draft** version.

## std::function & ::invocation Performance Analysis

Using the Assembly output from the LLVM clang++ version 7.0.1 compiler and 
output from The GNU Project Debugger version 8.1.1 on a 32-bit i686 Linux 
system, we compare the results of the std::function + std::bind (GNU C++ Library
libstdc++.so.6.0.25) implementation and ::invocation implementation to deduce 
suitability for real-time, embedded/microcontroller, high performance and 
monolithic software systems programming.

### Preamble

The std::function + std::bind and ::invocation templates allow any invocable C++
object to be called from a given point in code matching a set of parameter and 
return types.  For the purposes of general systems programming, it is imperative
that such an invocation system be capable of invoking the objects in a 
reasonable number of instructions and call stack frame layers, as well as 
ideally avoiding the need for a heap memory for micro-controller environments 
and other embedded systems where heap memory implementations may be impractical.

### Test Source Code & Header

For the test we shall pass to a statically linked function StaticTest and to an 
externally linked function ExternTest, a constant reference to each 
implementation's invocation object.  There shall be 4 test cases, one functor
(call operator overload), one lambda, one function and one method (member 
function) shall each be represented using the implementation's invocation object 
solution.  For each of the test cases, the StaticTest function is called once 
respective of the provided order.  Then for each of the test cases, the 
ExternTest function is called once also respective of the provided order.  The 
emitted code shall be divided into 3 parts, the test_extern compilation unit, 
the test_stdfunction compilation unit and the test_invocative compilation unit.

#### Test Conditions Header

The 4 test cases are included by each of the implementation's compilation units
as the included header
['test.conditions'](http://github.com/ASA1976/RAP-BTL/blob/master/test.conditions)
file.  The test cases are not intended to be included by the test_extern's 
compilation unit.

#### External Linkage Test Source

The
['test_extern.cpp'](http://github.com/ASA1976/RAP-BTL/blob/master/test_extern.cpp)
source code contains 2 overloads of the TestExtern function which each accept
a single parameteric constant reference argument to an implementation's 
invocation object and simply invoke it.

#### std::function Source

The 
['test_stdfunction.cpp'](http://github.com/ASA1976/RAP-BTL/blob/master/test_stdfunction.cpp)
source code defines it's version of the TestStatic function, declares it's 
version of TestExtern for external linkage to the test_extern compilation unit
and defines a main function which calls the 8 tests per the order state above.

#### ::invocation Source

The
['test_invocative.cpp'](http://github.com/ASA1976/RAP-BTL/blob/master/test_invocative.cpp) 
source code defines it's version of the TestStatic function, declares it's
version of TestExtern for external linkage to the test_extern compilation unit
and defines a main function which calls the 8 tests per the order stated above.

### Assembly Output Observations

We shall examine the size of the resulting compiler object image and the 
instruction pointer paths through the object images in the emitted Assembly 
source code in order to draw observations about the number call stack frame 
layers used in the emitted code.

#### test_extern Assembly Code

The
['test_extern_clang++.s'](http://github.com/ASA1976/RAP-BTL/blob/master/test_extern_clang%2B%2B.s)
file contains a total of 14 Assembly mnemonic statements and 0 bytes of defined
image data space, where both the std::function and Invocative versions of the 
TestExtern function overload ontain 7 Assembly mnemonic statements each.  The 
TestExtern function overload for the std::function implementation uses an 
indirect jump instruction to invoke the handler.  The TestExtern function 
overload for the ::invocation implementation uses a call instruction to invoke 
the interface function. 

#### std::function Assembly Code

The
['test_stdfunction_clang++.s'](http://github.com/ASA1976/RAP-BTL/blob/master/test_stdfunction_clang%2B%2B.s)
file contains a total of 243 Assembly mnemonic statements and 219 bytes of 
defined image data space throughout the entire Assembly source code.  The calls 
to puts have been expanded inline in main for all 4 TestStatic tests.  As 
observed in the test_extern Assembly code, the TestExtern function overload for 
std::function uses an indirect jump to all 4 handler functions.  The handler
functions for Test1 and Test2 call puts and upon return they in turn return 
directly to main, creating 0 stack frame layers for the actual call in these 
cases, however there is a call instruction to the function base manager 
occurring beforehand in all 4 cases.  In the case of Test3, the handler jumps to
the Test3 function which in turn returns directly to main, which again creates 0
stack frame layers for the actual call.  In the case of Test4, the handler calls 
the member function which returns to the handler which in turn returns to main, 
creating 1 stack frame layer for the actual call.

#### ::invocation Assembly Code

The
['test_invocative_clang++.s'](http://github.com/ASA1976/RAP-BTL/blob/master/test_invocative_clang%2B%2B.s)
file contains a total of 75 Assembly mnemonic statements and 24 bytes of defined 
image data space throughout the entire Assembly source code.  The calls to puts 
have been expanded inline in main for all 4 TestStatic tests.  As observed in 
the test_extern Assembly code, the TestExtern function overload for ::invocation 
uses a call instruction to the interface functions.  The interface functions for 
Test1 and Test2 call puts directly and then return directly to main, creating 1 
stack frame layer for the actual call in these cases.  In the case of Test3, the
interface function jumps to the Test3 function which in turn returns directly to
main, which creates 1 stack frame layer for the actual call.  In the case of 
Test4, the interface function calls the member function which returns to the 
interface function which in turn returns to main, creating 2 stack frame layers 
for the actual call.

### Debugger Output Observations

We shall examine the number of overall instructions executed within the object
images, the number of call return addresses pushed and popped on the stack from
within the object images, any instructions executed beyond the object images and
any heap memory management requests.  It should be noted that the debugger 
command issued was 'stepi' except when puts, the new operator and the delete 
operator executed where the debuger command issues was 'finish' once, then 
'stepi' resumed.

#### std::function Debugger Output

The
['test_stdfunction_clang++.txt'](http://github.com/ASA1976/RAP-BTL/blob/master/test_stdfunction_clang%2B%2B.txt)
file indicates that there were a total of 201 instructions executed within the
object images, 22 call return addresses pushed and popped on the stack from
within the object image code, the new and delete operators were required and 2 
heap allocations and deallocations each were requested.  

#### ::invocation Debugger Output

The
['test_invocative_clang++.txt'](http://github.com/ASA1976/RAP-BTL/blob/master/test_invocative_clang%2B%2B.txt)
file indicates that there were a total of 101 instructions executed within the
object images, 17 call return addresses pushed and popped on the stack from 
within the object image code, that no other code was required and no heap memory 
use was requested.

### Conclusions

Based on the list of observations it is clear that the ::invocation 
implemetation does not require any heap implementation or run-time libraries.  
It is also clear that the ::invocation implementation produces much more concise
instruction code on the tested platform.  The difference in instructions 
executed at run-time within the object images is very nearly half, the 
difference in object image code is less than a third and the difference in 
object image data is is just above one tenth for each implementation's 
compilation unit all favouring ::invocation over std::function + std::bind
for systems programming concerns.

### Footnote

Because ::invocation is portable to all C++ compiler supported architecture and 
platform environments without modification and due to it's design, it is 
unlikely that any *current* std::function implementation will be capable of 
parallel performance.  However std::function should continue to be used by
general application software development, as the improper use of ::invocation
can lead to serious problems if deployed in the field.

