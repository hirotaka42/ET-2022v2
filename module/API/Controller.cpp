/**
 * @file Controller.cpp
 * @brief モーター制御に用いる関数をまとめたラッパークラス
 * @author hirotaka42
 */
#include "Controller.h"

/**
 * @brief Construct a new Controller:: Controller object
 * rightWheel(PORT_B), 
 * leftWheel (PORT_C), 
 * armMotor  (PORT_A)
 */
Controller::Controller():
  rightWheel(PORT_B),
  leftWheel(PORT_C),
  armMotor(PORT_A) 
  {

  }

/**
 * @brief PWMが基準値に収まるように下限上限(-100~100)の設定
 * 
 * @param value 
 * @return int 
 */
int Controller::limitPwmValue(const int value)
{
  if(value > MOTOR_PWM_MAX) {
    return MOTOR_PWM_MAX;
  } else if(value < MOTOR_PWM_MIN) {
    return MOTOR_PWM_MIN;
  }
  return value;
}

/**
 * @brief PWM値を右モータにセット
 * 
 * @param pwm 
 */
void Controller::setRightMotorPwm(const int pwm)
{
  rightWheel.setPWM(limitPwmValue(pwm));
}

/**
 * @brief PWM値を左モータにセット
 * 
 * @param pwm 
 */
void Controller::setLeftMotorPwm(const int pwm)
{
  leftWheel.setPWM(limitPwmValue(pwm));
}

/**
 * @brief タイヤのモータを停止する
 * 
 */
void Controller::stopMotor()
{
  leftWheel.stop();
  rightWheel.stop();
}

/**
 * @brief PWM値をアームのモータにセット
 * 
 * @param pwm 
 */
void Controller::setArmMotorPwm(const int pwm)
{
  armMotor.setPWM(limitPwmValue(pwm));
}

/**
 * @brief アームのモータを停止
 * 
 */
void Controller::stopArmMotor()
{
  armMotor.stop();
}

/**
 * @brief 本体中央の通知用LEDを指定の色(赤,緑,オレンジ)で光らせ,OFFで消す
 * 
 * LED_OFF オフにする
 * LED_RED 	     赤
 * LED_GREEN 	   緑
 * LED_ORANGE オレンジ色
 */
void Controller::setLedColorOrange()
{
  ev3_led_set_color(LED_ORANGE);
}

/**
 * @brief 本体中央の通知用LEDを指定の色(赤,緑,オレンジ)で光らせ,OFFで消す
 * 
 * LED_OFF オフにする
 * LED_RED 	     赤
 * LED_GREEN 	   緑
 * LED_ORANGE オレンジ色
 */
void Controller::offLedColor()
{
  ev3_led_set_color(LED_OFF);
}

/**
 * @brief スリープ時間(ミリ秒)
 * 
 * @param milliSec 
 */
void Controller::wait(int milliSec)
{
  clock.sleep(milliSec);
}

/**
 * @brief LCD表示の初期処理用
 * 
 * @param str 
 */
void Controller::initLcd(const char *str) {
  // フォントの設定と0行目の表示
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string(str, 0, 0);
}

/**
 * @brief 行単位で引数の文字列を表示
 * 
 * @param str 
 * @param line 
 */
void Controller::setLcdView(const char *str, int32_t line) {
  const int8_t line_height = 20;
  ev3_lcd_fill_rect(0, line * line_height, EV3_LCD_WIDTH, line_height, EV3_LCD_WHITE);
  ev3_lcd_draw_string(str, 0, line * line_height);
}

/**
 * @brief シミュレータへ競技の終了を通知する
 * 
 */
void Controller::notifyCompletedToSimulator()
{
  ETRoboc_notifyCompletedToSimulator();
}


