
Led led(D0, D1, D2);
Color red(255, 0, 0);

void loop() {
  led.pulse(red, 50, 50, 5000);
}