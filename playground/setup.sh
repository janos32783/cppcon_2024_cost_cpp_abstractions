#!/bin/bash

# install dependencies
sudo apt-get install git make cmake libusb-1.0-0-dev
sudo apt-get install gcc build-essential

# download ST-link utilities
cd ~
mkdir stm32
cd stm32
git clone https://github.com/stlink-org/stlink
cd stlink
cmake .
make
sudo make install
# copy the binaries
cd bin
sudo cp st-* /usr/local/bin
cd ../lib
sudo cp *.so* /lib32
# udev rule
cd ../config
sudo cp udev/rules.d/49-stlinkv* /etc/udev/rules.d/
# reload udev rules
sudo udevadm control --reload-rules
sudo udevadm trigger
# basrhc
echo "add the following line to the end of your bashrc file and source it"
echo 'export LD_LIBRARY_PATH=/usr/lib32:/usr/local/lib:$LD_LIBRARY_PATH'
