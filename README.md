

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
