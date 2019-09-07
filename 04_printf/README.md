# 04_printf

UART経由で変数値等を文字列で表示するためのprintf関数のサンプル  

* GPIO14(8pin) -> TXD
* GPIO15(10pin) -> RXD
* GND(14pin) -> GND

## μSDカードに書き込むファイル

* bootcode.bin  
下記からダウンロードする  
https://github.com/raspberrypi/firmware/blob/master/boot/bootcode.bin
* start.elf  
下記からダウンロードする  
https://github.com/raspberrypi/firmware/blob/master/boot/start.elf
* config.txt  
このリポジトリに登録されているものをそのまま使う
* kernel.img  
makeして生成されたものを使う

