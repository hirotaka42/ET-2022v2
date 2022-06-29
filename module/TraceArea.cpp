/**
 * @file TraceArea.cpp
 * @author hirotaka42
 * @brief ON/OFF制御でライントレースをするクラス
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "TraceArea.h"

void TraceArea::runTraceArea()
{
  /* true:左エッジ,false:右エッジ */
  bool isLeftEdge;
  /* Controller インスタンス作成 */
  Controller controller;
  
  /* L/R コース別 エッジの設定 */
  if(IS_LEFT_COURSE) isLeftEdge = !IS_LEFT_COURSE;
  else isLeftEdge = IS_LEFT_COURSE;

  /* Tracerにエッジを与えてインスタンス化する */
  Tracer tracer(isLeftEdge);

  tracer.init();
  controller.setLcdView("running...", 1);
  while (!ev3_button_is_pressed(LEFT_BUTTON)){
    tracer.run();
    controller.wait(1000*10*4);
    /* 0.04秒 wait */
    /* 早すぎると処理が追いつかない為 */
  }
  /* LEFT_BUTTON が押されたら停止 */
  tracer.stop();

}

