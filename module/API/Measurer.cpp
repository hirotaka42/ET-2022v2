/**
 * @file Measurer.cpp
 * @author hirotaka42
 * @brief 計測に用いる関数をまとめたラッパークラス
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Measurer.h"

/**
 * @brief Construct a new Measurer:: Measurer object
 * PORT_2 カラーセンサ/colorSensor
 * PORT_B 正面 右ホイール/rightWheel
 * PORT_C 正面 左ホイール/leftWheel
 * PORT_A カラーセンサのアームモータ/armMotor
 * PORT_1 正面 右タッチセンサ/touchSensor
 */
Measurer::Measurer():
  colorSensor(PORT_2),
  rightWheel(PORT_B),
  leftWheel(PORT_C),
  armMotor(PORT_A),
  touchSensor(PORT_1)
{
}

/**
 * @brief 明るさを取得
 * 
 * @return int 
 */
int Measurer::getBrightness()
{
  return colorSensor.getBrightness();
}

/**
 * @brief RGB値を返す
 * 
 * @return rgb_raw_t 
 */
rgb_raw_t Measurer::getRawColor()
{
  rgb_raw_t rgb;
  colorSensor.getRawColor(rgb);
  return rgb;
}

/**
 * @brief 左モータ角位置取得
 * 
 * @return int 
 */
int Measurer::getLeftCount()
{
  return leftWheel.getCount();
}

/**
 * @brief 右モータ角位置取得
 * 
 * @return int 
 */
int Measurer::getRightCount()
{
  return rightWheel.getCount();
}

/**
 * @brief アームモータ角位置取得
 * 
 * @return int 
 */
int Measurer::getArmMotorCount()
{
  return armMotor.getCount();
}

/**
 * @brief タッチセンサの状態取得
 * 
 * @return true 
 * @return false 
 */
bool Measurer::isPressed()
{
  return touchSensor.isPressed();
}

/**
 * @brief EV3 正面 左の本体ボタンの状態取得
 * 
 * @return true 
 * @return false 
 */
bool Measurer::ev3_LeftButtonIsPressed()
{
  return ev3_button_is_pressed(LEFT_BUTTON);
}