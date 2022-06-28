#include "Tracer.h"

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2) {
  }

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();
  rightWheel.stop();
}

void Tracer::run() {
  msg_f("running...", 1);
  if(colorSensor.getBrightness() >= mThreshold) {
    leftWheel.setPWM(0);
    rightWheel.setPWM(pwm);
  } else {
    leftWheel.setPWM(pwm);
    rightWheel.setPWM(0);
  }
}
