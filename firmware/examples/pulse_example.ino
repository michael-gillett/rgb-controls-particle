#include "rgb-controls/rgb-controls.h"

RGBControls::Led led(D0, D1, D2);
RGBControls::Color color(255, 0, 0);

void loop() {
    led.pulse(color, 0, 100 , 5000);
}