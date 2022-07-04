/**
 * @file InitViewSenser.h
 * @author hirotaka42
 * @brief 開始前にセンサー値を目視する為にLCDへ表示するクラス
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INITVIEWSENSER_H
#define INITVIEWSENSER_H

#include "Measurer.h"
#include "Controller.h"

class InitViewSenser {
 public:
  static void start();
};

#endif