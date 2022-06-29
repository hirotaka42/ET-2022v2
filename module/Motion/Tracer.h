/**
 * @file Tracer.h
 * @author hirotaka42
 * @brief  ライントレースをするための制御クラス
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
  /**
   * コンストラクタ
   * 
   */
  Tracer(bool _isLeftEdge);

  /**
   * @brief 
   * 
   */
  void run();

  /**
   * @brief 
   * 
   */
  void init();

  /**
   * @brief 
   * 
   */
  void stop();


private:
  bool isLeftEdge;
  Controller controller;
  ColorSensor colorSensor;

  const int8_t mThreshold = 20;

  #ifndef MAKE_RASPIKE
    // RASPIKE用の設定
    const int8_t pwm = (Motor::PWM_MAX) / 6;
  #else
    //それ以外のPWM設定
    const int8_t pwm = 60;
  #endif
};
