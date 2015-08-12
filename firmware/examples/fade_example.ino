#include "rgb-controls/rgb-controls.h"

using namespace RGBControls;

Led led(D0, D1, D2);
Color red(255, 0, 0);
Color blue(255, 0, 0);

void loop() {
  led.fadeBetween(red, blue);
}
