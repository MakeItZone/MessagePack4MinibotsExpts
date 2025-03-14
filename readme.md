# Experiments with `MessagePack` for 'lil 'bots

We want a reasonably performant, somewhat simple (human readabl'ish), protocol for sending data
between programs, which may be running on different CPUs, different languages, and different
physical connections.

First use cases:

* desktop C/C++ to microPython (unix docker container) via files
* Pi Pico C/C++ SDK (BluePad BT gamepad library) to desktop terminal, *python, via serial
* Pi Pico C/C++ SDK to upython on an ESP32, via serial
* Pi Pico C/C++ (or ESP32 upython) to where-ever via WiFi
  * *It'd be really nice if we can use the Pico's WiFi at the sametime as the BT interface.*

## Components

### `MsgBuff`
The C++ test app.
Instantiates a `uni_gamepad`, serializes it as a `messagepack`, and outputs it to `stdout` as well as writing it out to `message.bin`.

Use something like `xxd` to view `message.bin` as a hex dump.
