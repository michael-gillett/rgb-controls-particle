#ifndef rgb_controls_h
#define rgb_controls_h

#include "application.h"


namespace RGBControls {
    class Color {
      public:
        Color(int r, int g, int b);
        Color withBrightness(int brightness);
        Color lerp(Color to, float t);
        int red;
        int green;
        int blue;

    };

    class Led {
      public:
        Led(int rPin, int gPin, int bPin);
        void setColor(Color c);
        void pulse(Color c, int min, int max, int cycleTime);
        void fadeBetween(Color c1, Color c2);
        void step(int min, int max);
      private:
        int _rPin;
        int _gPin;
        int _bPin;

        int _step;
        int _dir;
    };
}

#endif
