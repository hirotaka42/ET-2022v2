/**
 * @file TraceArea.h
 * @author hirotaka42
 * @brief ON/OFF制御でライントレースをするクラス
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LINETRACEAREAJr_H
#define LINETRACEAREAJr_H
#include "Tracer.h"

#include "Controller.h"

/**
 * Lコース/Rコース向けの設定を定義
 * デフォルトはLコース
 */
#if defined(MAKE_RIGHT)
static constexpr bool IS_LEFT_COURSE = false;  // Rコース
#else
static constexpr bool IS_LEFT_COURSE = true;  // Lコース
#endif


class TraceArea {
 public:
  /**
   *@fn static void runTraceArea();
   *@brief ライントレースエリアを走行する
   */
  static void runTraceArea();


  /**
   * コンストラクタ
   * インスタンス化を禁止するためにpriveteにし、処理については記述していない
   */
  TraceArea();
};

#endif
