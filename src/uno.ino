#include <MIDI_Controller.h>

HairlessMIDI_Interface myHairlessMidi;

AnalogMultiplex multiplexer(A0, { 2, 3, 4, 5 } );

Analog potentiometers[] = {
  {multiplexer.pin(0), MIDI_CC::Channel_Volume, 1},
  {multiplexer.pin(1), MIDI_CC::Channel_Volume, 2},
  {multiplexer.pin(2), MIDI_CC::Channel_Volume, 3},
  {multiplexer.pin(3), MIDI_CC::Channel_Volume, 4},
  {multiplexer.pin(4), MIDI_CC::Channel_Volume, 5},
  {multiplexer.pin(5), MIDI_CC::Channel_Volume, 6},
  {multiplexer.pin(6), MIDI_CC::Channel_Volume, 7},
  {multiplexer.pin(7), MIDI_CC::Channel_Volume, 8},
  {multiplexer.pin(8), MIDI_CC::Channel_Volume, 9}
};

const uint8_t velocity = 0b1111111;  // Maximum velocity (0b1111111 = 0x7F = 127)
const uint8_t C4 = 60;  // Note number 60 is defined as middle C in the MIDI specification

Digital button1(11, C4, 1, velocity);
Digital button2(12, C4, 2, velocity);
Digital button3(13, C4, 3, velocity);

Digital button4(A3, C4, 5, velocity);
Digital button5(A4, C4, 6, velocity);
Digital button6(A5, C4, 7, velocity);

void setup() {}

void loop() {
  MIDI_Controller.refresh();
}
