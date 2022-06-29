

# ET-2022
[ETロボコン2022](https://www.etrobo.jp/)プライマリークラス実機のプログラムです。  

## 開発環境
- [ETロボコン公式シミュレータ](https://github.com/ETrobocon/etrobo)
- [Raspi用 SPIKE制御開発環境「RasPike（ラスパイク）」](https://github.com/ETrobocon/RasPike)
- C++
- Git/GitHub

環境構築の詳細は、[公式wiki](https://github.com/ETrobocon/etrobo/wiki)を見てください。

## ビルド方法(シュミレータ)
etrobo ディレクトリで以下のコマンドを実行するとデフォルトLコースでビルドされます
 ```
 # シュミレータ向け
 make app=ET-2022 sim up
 
 # 実機向け(ケーブルを繋いで実行)
 make app=ET-2022 up
 ```

明示的にL/Rコース向けにビルドするには?
```
# シュミレータ向け R
make right app=ET-2022 sim up
# シュミレータ向け L
make left app=ET-2022 sim up

# 実機向け(ケーブルを繋いで実行)  R
make right app=ET-2022 up
# 実機向け(ケーブルを繋いで実行)  L
make left app=ET-2022 up

```

## 使用ポート一覧(実機)
実機の使用ポートは2022年度版,組み立て手順書を元に接続しています。  
>HackEV/HackSPi組み立て手順書(Build_Inst_M2.0.pdf)  
>Release:2022-05-14 13:50

なお、注意書きとして以下の、記載があるので念の為こちらにも引用します。
>※この配線方法は一例です。ケーブルの本数・長さ・使用するポートなどは任意に選択可能です。
>※タッチセンサーは左右どちらでも結構です。


|ポート |接続モータ |ケーブル長 |ポート |接続センサ| ケーブル長|
|:-:|--|:-:|:-:|--|:-:|
|PORT_A|アームモータ|35cm|PORT_1|タッチセンサ|35cm|
|PORT_B|右モータ|25cm|PORT_2|カラーセンサ|25cm|
|PORT_C|左モータ|25cm|PORT_3|超音波センサ|25cm|
|PORT_D|しっぽモータ|50cm|PORT_4|ジャイロセンサ|35cm|

### API 使用ポート
```vim:Measurer.cpp
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
```

```vim:Controller.cpp
/**
 * @file Controller.cpp
 * @brief モーター制御に用いる関数をまとめたラッパークラス
 * @author hirotaka42
 */
#include "Controller.h"

/**
 * @brief Construct a new Controller:: Controller object
 * PORT_B 正面 右ホイール/rightWheel
 * PORT_C 正面 左ホイール/leftWheel
 * PORT_A カラーセンサのアームモータ/armMotor
 */
Controller::Controller():
  rightWheel(PORT_B),
  leftWheel(PORT_C),
  armMotor(PORT_A) 
{
}
```

### Motion 使用ポート
```vim:Tracer.cpp
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
 * PORT_2 カラーセンサ/colorSensor
 */
Tracer::Tracer(bool _isLeftEdge):
  isLeftEdge(_isLeftEdge),
  colorSensor(PORT_2)
{
}
```
