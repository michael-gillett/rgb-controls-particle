#include "application.h"


namespace RGBControls {
    class Color {
      public:
        Color(int r, int g, int b);
        Color withBrightness(int brightness);
        Color lerp(Color to, float t);
        int _red;
        int _green;
        int _blue;
    };

    class Led {
      public:
        Led(int rPin, int gPin, int bPin);
        void setColor(Color c);
        void pulse(Color c, int base, int delta, int cycleTime);
        void fadeBetween(Color c1, Color c2);
        void step(int delta);
      private:
        int _rPin;
        int _gPin;
        int _bPin;

        int _step;
        int _dir;
    };
}
