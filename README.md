# LED Matrix

This is an Arduino project aimed at driving a pair of **Sure Electronics DE-DP14211 P7.62 32X16 RG Bicolor LED Dot Matrix** boards. These boards use an **Holtec HT1632C** controller.

Based on the [HT1632C library](https://github.com/wildstray/ht1632c). Tested with an Arduino Uno R3.

## Installation

Begin by installing [Ino](http://inotool.org/). On a Mac with brew installed, you can simply run `brew install ino`.

Next, build this project and upload it to your Arduino:
```
ino build
ino upload
```

You can monitor the serial port using `ino serial` (use Ctrl+A Ctrl+X to exit) or something like:
```
stty -f /dev/tty.usbmodem1411 9600 -parity cs8 -cstopb
tail -f /dev/tty.usbmodem1411
```

(Change your serial interface accordingly. `ino serial` will guess it for you.)

After running the previous `stty` command, you can send commands to the board manually using one of the following:
```
cat commands.txt > /dev/tty.usbmodem1411
echo "test" > /dev/tty.usbmodem1411
```

## Wiring

Connect Input of Matrix 1 to the Arduino following the following schematics.
Connect Output of Matrix 1 to Input of Matrix 2, including +5V and GND.

```
+----------/==\----------+
| 1  3  5  7  9 11 13 15 |
| 2  4  6  8 10 12 14 16 |
+------------------------+

1      CS      Connect to pin 5 of the Arduino
2      CLK     Connect to pin 4 of the Arduino
5      WR      Connect to pin 6 of the Arduino
7      DATA    Connect to pin 7 of the Arduino
13     GND     Connect to pin GND of the Arduino
14     +5V     Connect to pin 5V of the Arduino
```
