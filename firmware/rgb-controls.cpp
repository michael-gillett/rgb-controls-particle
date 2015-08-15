#include "application.h"
#include "rgb-controls.h"


namespace RGBControls {
  Color::Color(int r, int g, int b) {
    red = r;
    green = g;
    blue = b;
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
    pinMode(_rPin, OUTPUT);
    pinMode(_gPin, OUTPUT);
    pinMode(_bPin, OUTPUT);
  }

  void Led::setColor(Color c) {
    analogWrite(_rPin, c.red);
    analogWrite(_gPin, c.green);
    analogWrite(_bPin, c.blue);
  }

  void Led::off() {
    Color black(0, 0, 0);
    setColor(black);
  }

  void Led::flash(Color c, int onTime, int offTime) {
    setColor(c);
    delay(onTime);
    off();
    delay(offTime);
  }

  void Led::flashN(Color* colors, int length) {
    for (int n = 0; n < length; n++) {
      flash(colors[n], 500, 0);
    }
  }

  void Led::pulse(Color c, int min, int max, int cycleTime) {
    Color nextColor = c.withBrightness(min + _step);
    setColor(nextColor);
    delay(cycleTime / (max - min));
    step(min, max);
  }

  int n = 0;
  bool up = false;
  void Led::fadeN(Color* colors, int length) {
    if (_step == 0 || _step == 100) {
      n++;
      if (n >= length) {
        n = 0;
        up = !up && (length % 2 != 0)
      }
    }
    Color a = colors[n];
    Color b = colors[(n + 1 == length) ? 0 : n + 1];
    if ((n % 2 == 0) ^ up)
      fadeBetween(a, b);
    else
      fadeBetween(b, a);
  }

  void Led::fadeBetween(Color c1, Color c2) {
    Color nextColor = c1.lerp(c2, _step / 100.0);
    setColor(nextColor);
    delay(25);
    step(0, 100);
  }


  bool isIncreasing = true;
  void Led::step(int min, int max) {
    _step = _step + (isIncreasing ? 1 : -1);
    if (_step >= max || _step <= min) isIncreasing = !isIncreasing;
  }
}
