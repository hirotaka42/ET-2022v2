/**
 * @file InitViewSenser.cpp
 * @author hirotaka42
 * @brief 開始前にセンサー値を目視する為にLCDへ表示するクラス
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "InitViewSenser.h"


void InitViewSenser::start()
{
/* インスタンス作成 */
  Controller controller;
  Measurer measurer;

  /* 明るさの値(0~100)をLCD表示用にchar MAX100文字分の配列を確保 */
  char brightnessResult[100]; // 0~100
  controller.initLcd("Getting Brightness...");
  controller.setLcdView("Press Touch Sensor to exit.",1);

  /* タッチセンサが押されるまで明るさを表示 */
  while (!measurer.isPressed()) {
    sprintf(brightnessResult, "%d",measurer.getBrightness());
    /* ブリリアンスデータのLCD表示 */ 
    controller.setLcdView(brightnessResult,2);
    controller.wait(250);
    /* 0.25秒 wait */
    /* 早すぎると処理が追いつかない為 */
  }
  /* LCD表示領域の初期化 */
  for(int n=0;n<7;n++) controller.setLcdView("",n);
  

  
  controller.initLcd("Go to Ready?");
  controller.wait(500);
  /* 0.5秒 wait */
  /* 初期化完了通知 LED */
  controller.setLedColorOrange();
  controller.wait(250);
  /* 0.25秒 wait */
}