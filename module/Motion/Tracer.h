/**
 * @file Tracer.h
 * @author hirotaka42
 * @brief  ON/OFF制御でライントレースをするクラス
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "ColorSensor.h"
#include "Controller.h"

using namespace ev3api;

class Tracer {
public:
  Tracer();
  void run();
  void init();
  void stop();

private:
  Controller controller;
  ColorSensor colorSensor;
  const int8_t mThreshold = 20;
#ifndef MAKE_RASPIKE
  const int8_t pwm = (Motor::PWM_MAX) / 6;
#else
  const int8_t pwm = 60;
#endif
};
