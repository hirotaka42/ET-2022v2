/**
 * @file EtRobocon2022.cpp
 * @brief 全体を制御するクラス
 * @author hirotaka42
 */

#include "EtRobocon2022.h"

/**
 * @brief シミュレータか実機かの判定
 * 1:SIM, 0:実機
 */
 #if defined(MAKE_SIM)
     static const int _SIM = 1;
 #elif defined(MAKE_EV3)
     static const int _SIM = 0;
 #else
    static const int _SIM = 0;
 #endif

/**
 * @brief メイン処理
 * 
 */
void EtRobocon2022::start()
{
  Controller controller;
  /* Controller インスタンス作成 */
  controller.setLedColorOrange();
  /* 初期化完了通知 LED */
  controller.setLcdView("Go to the start, ready?",2);
  controller.wait(1000*1000*3);
  /* 3秒 wait */

  if (_SIM)   controller.setLcdView("Hit SPACE bar to start",2);
  else        controller.setLcdView("Tap Touch Sensor to start",2);


}
