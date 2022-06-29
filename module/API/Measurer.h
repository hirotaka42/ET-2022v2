/**
 * @file Measurer.h
 * @author hirotaka42
 * @brief 計測に用いる関数をまとめたラッパークラス
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MEASURER_H
#define MEASURER_H

#include "ev3api.h"
#include "ColorSensor.h"
#include "Motor.h"
#include "TouchSensor.h"

class Measurer {
 public:
  /**
   * コンストラクタ
   */
  Measurer();

  /**
   * 明るさを取得
   * @return 反射光の強さ(0-100)
   */
  int getBrightness();

  /**
   * RGB値を取得
   * @return RGB値
   */
  rgb_raw_t getRawColor();

  /**
   * 左モータ角位置取得
   * @return 左モータ角位置[deg]
   */
  int getLeftCount();

  /**
   * 右モータ角位置取得
   * @return 右モータ角位置[deg]
   */
  int getRightCount();

  /**
   * アームモータ角位置取得
   * @return アームモータ角位置[deg]
   */
  int getArmMotorCount();

  /**
   * タッチセンサ状態取得
   * @return true:押されている状態, false:押されていない状態
   */
  bool isPressed();

  /**
   * EV3 正面 左の本体ボタンの状態取得
   * 
   * @return true :押されている状態
   * @return false:押されていない状態
   */
  bool ev3_LeftButtonIsPressed();

  /**
   * @brief Construct a new Measurer:: Measurer object
   * PORT_2 カラーセンサ
   * PORT_B 正面 右ホイール
   * PORT_C 正面 左ホイール
   * PORT_A カラーセンサ アームモータ
   * PORT_1 正面 右タッチセンサ
   */
  
  private:
    ev3api::ColorSensor colorSensor;
    ev3api::Motor leftWheel;
    ev3api::Motor rightWheel;
    ev3api::Motor armMotor;
    ev3api::TouchSensor touchSensor;
};

#endif