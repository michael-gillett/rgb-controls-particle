#include "application.h"
#include "rgb-controls.h"


namespace RGBControls {
  Color::Color(int r, int g, int b) {
    _red = r;
    _green = g;
    _blue = b;
  }

  Color Color::withBrightness(int brightness) {
    int r = red   * brightness / 100;
    int g = green * brightness / 100;
    int b = blue  * brightness / 100;
    return Color(r, g, b);
  }

  Color Color::lerp(Color to, float t) {
    int dR = (to.red - red) * t;
    int dG = (to.green - green) * t;
    int dB = (to.blue - blue) * t;
    return Color(red + dR, green + dG, blue + dB);
  }

  Led::Led(int rPin, int gPin, int bPin) {
    _rPin = rPin;
    _gPin = gPin;
    _bPin = bPin;
    _step = 1;
    _dir = 1;
    pinMode(_rPin, OUTPUT);
    pinMode(_gPin, OUTPUT);
    pinMode(_bPin, OUTPUT);
  }

  void Led::setColor(Color c) {
    analogWrite(_rPin, c.red);
    analogWrite(_gPin, c.green);
    analogWrite(_bPin, c.blue);
  }

  void Led::pulse(Color c, int min, int max, int cycleTime) {
    Color nextColor = c.withBrightness(min + _step);
    setColor(nextColor);
    delay(cycleTime / (2 * delta));
    step(min, max);
  }

  void Led::fadeBetween(Color c1, Color c2) {
    Color nextColor = c1.lerp(c2, _step / 100.0);
    setColor(nextColor);
    delay(50);
    step(0, 100);
  }

  void Led::step(int min, int max) {
   if (_step >= max || _step <= min) {
      _dir *= -1;
    }
    _step += _dir;
  }
}
