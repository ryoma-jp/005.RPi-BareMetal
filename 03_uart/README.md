# 03_uart

Raspberry Pi 3 Model B+をベアメタルで起動して"Hello World!"をUARTで送信する  

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

