# RAP-BTL
#### Relational Association Programming - Basic Template Library

© 2019 Aaron Sami Abassi

Licensed under the Academic Free License version 3.0

## Arduino Examples

The Arduino examples in this directory can be compiled using the Arduino gcc-avr
compiler (tested with AVR 1.8.1) if the template library header files are
properly incorporated into the build process.

## Sloeber IDE

The Arduino examples compile successfully using the Sloeber Eclipse IDE plugin.
However the default C++ parser is not yet fully capable of interpreting this
newer dialect of C++14 and may show errors which are not in fact errors at all.
In order to successfully compile these examples, after opening or creating an 
Arduino project, in the 'File' menu of the 'Arduino View', select 'Import...' 
then open the Arduino section, then select 'Import a folder containing source 
code in the current project' then find and select the rap-btl directory 
containing the top-level headers.

## Arduino IDE

Because of the design of the Arduino IDE, I have not found a way to successfully
incorporate the use of any **template library** in the integrated environment.  
Though there was one template library listed in the add-on libraries (ETL),
it did not successfully install when tested, circa October 2019 and therefore
was unable to shed light on how to install a template library within this IDE.

