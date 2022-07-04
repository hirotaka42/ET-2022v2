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
  /* インスタンス作成 */
  Controller controller;
  Measurer measurer;

  /* センサー値を目視する為にLCDへ表示するクラスの呼び出し */
  InitViewSenser::start();

  if (_SIM)   controller.setLcdView("Hit SPACE bar to start",1);
  else        controller.setLcdView("Tap to Start",1);

  /* タッチセンサが押されるまで待機 */
  while (!measurer.isPressed()) {
      controller.wait(250);
      /* 0.25秒 wait */
      /* 早すぎると処理が追いつかない為 */
  }
  /* LCD表示領域の初期化 */
  for(int n=0;n<7;n++) controller.setLcdView("",n);

  /* タッチセンサが押されたら処理を開始 */
  /* ON/OFF制御でライントレースをするクラスの呼び出し */
  TraceArea::runTraceArea();

  /* シミュレータの場合,競技の終了を通知する */
  if(_SIM == 1) controller.notifyCompletedToSimulator();

}
