# SwitchControllerESP32

ESP32-S3-DevkitCを使ってNintendo Switchのゲームを自動化するマイコン用のライブラリです。

# このライブラリについて

このライブラリはinterimadd氏の[NintendoSwitchControll](https://github.com/interimadd/NintendoSwitchControll)を参考に作成しています

# 導入方法

必要なもの

    ESP32-S3-DevkitC-1 1台(https://akizukidenshi.com/catalog/g/gM-17073/)
    USB ケーブル 2本（ESP32-S3-DevkitC-1 と Switch や PC を接続するのに必要）

動作環境

    Arduino IDE（1.8.19 推奨）
    Arduino core for ESP32 (2.0.6)

参考URL:https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html#installing-using-arduino-ide

# 使い方

## ライブラリのインストール

Arduinoのライブラリのあるフォルダ、C:/Users/ユーザ名/Documents/Arduino/librariesなどにこのリポジトリをダウンロードし展開する

## 書き込み

1. ESP32 S3 DevkitC-1のUSB端子のUARTシルク側をPCに接続、USBシルク側をSwitchへ接続
2. Arduino IDEを立ち上げる
3. ツール→ボード→ESP32 Arduino→ESP32S3 Dev Moduleを選択
4. シリアルポートも接続してるポートに変更
5. サンプルスケッチ(ファイル→スケッチ例→SwitchControllerESP32→AutoButton)を開く
6. スケッチ→マイコンボードへ書き込む

Aボタン連打するサンプルなので、ポケモンセンターのNPCの前などで試してください

# 注意

主要な関数に関しては元のライブラリと同じように使用することができますが、使用前に初期化関数を実行する必要がありますので注意してください。

    --setup関数--
    switchcontrolleresp32_init();  ← 必須
    USB.begin();                   ← 必須
    switchcontrolleresp32_reset(); ← 念のため

# Lisence

このプロジェクトのライセンスはMITライセンスです。詳細はLICENSEをご覧ください。
