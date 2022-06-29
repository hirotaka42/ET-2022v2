/**
 * @file Tracer.cpp
 * @author hirotaka42
 * @brief  ライントレースをするための制御クラス
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Tracer.h"

/**
 * @brief Construct a new Tracer:: Tracer object
 * 
 */
Tracer::Tracer(bool _isLeftEdge):
  isLeftEdge(_isLeftEdge),
  colorSensor(PORT_2){
  }

/**
 * @brief 
 * 
 */
void Tracer::init() {
  controller.initLcd("Tracer");
}

/**
 * @brief 
 * 
 */
void Tracer::stop() {
  controller.setLcdView("Stopped.", 1);
  controller.stopMotor();
}

/**
 * @brief ON/OFF制御でライントレースをする関数
 * 
 */
void Tracer::run() {

  if(colorSensor.getBrightness() >= mThreshold) {
    controller.setLeftMotorPwm(0);
    controller.setRightMotorPwm(pwm);
    
  } else {
    controller.setLeftMotorPwm(pwm);
    controller.setRightMotorPwm(0);
  }
}