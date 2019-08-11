#! /bin/bash

sudo apt install -y clang
sudo apt install -y gnupg2
sudo apt install -y make
sudo apt install -y zlib1g-dev
sudo apt install -y libgmp3-dev
sudo apt install -y pkg-config
sudo apt install -y libglib2.0-dev
sudo apt install -y libpixman-1-dev

# --- qemu ---
qemu_version="3.1.1"
wget https://download.qemu.org/qemu-${qemu_version}.tar.xz
tar xvJf qemu-${qemu_version}.tar.xz
cd qemu-${qemu_version}
./configure
make
sudo make install
cd ..

