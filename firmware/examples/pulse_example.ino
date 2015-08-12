#include "rgb-controls/rgb-controls.h"

using namespace RGBControls;

Led led(D0, D1, D2);
Color color(255, 0, 0);

void loop() {
  led.pulse(color, 0, 100 , 5000);
}
