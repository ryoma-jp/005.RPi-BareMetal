# 02_led_c

Raspberry Pi 3 Model B+をベアメタルで起動してLEDを点灯する  
01_ledはアセンブラでLEDを点灯  
02_led_cではC言語のmain関数を呼び出してLEDを点灯する  

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

