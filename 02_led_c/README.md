# 02_led_c

01_ledはアセンブラでLEDを点灯  
02_led_cではC言語のmain関数を呼び出してLEDを点灯する  

## Raspberry Pi 3 Model B+ (AArch64)をベアメタルで起動してLEDを点灯する

### μSDカードに書き込むファイル

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

		$ ln -s Makefile_aarch64 Makefile
		$ make

## Raspberry Pi Zero W (AArch32)をベアメタルで起動してLEDを点灯する

### μSDカードに書き込むファイル

* bootcode.bin  
下記からダウンロードする  
https://github.com/raspberrypi/firmware/blob/master/boot/bootcode.bin
* start.elf  
下記からダウンロードする  
https://github.com/raspberrypi/firmware/blob/master/boot/start.elf
* kernel.img  
makeして生成されたものを使う

		$ ln -s Makefile_aarch32 Makefile
		$ make


