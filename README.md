# Color

A simple C++ type representing the color.

## Usage

```cpp
// Adjust the include path, depending on where you put the library files.
#include "./libs/Color/Color.cpp"

Color *testColor = new Color(0x050403);

Serial.println((uint32_t)testColor);

// Lighten color up a bit:
testColor->lighten(64);

Serial.println((uint32_t)testColor);
```

## Motivation

As I was playing around with some micro controllers and RGB LEDs, I wanted to use an easy, abstracted data type for color manipulation.

## License

This project is licensed under the terms of the MIT license.