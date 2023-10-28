## Rick Roll 

A rick roll for TI-84 Plus CE and TI-83 Premium CE calculators.

![Rick roll demo](https://i.ibb.co/Z8wtvbW/rickroll-demo.png)

### Prerequisites

In order to run this program, you have to send the [C libraries](https://github.com/CE-Programming/libraries/releases) to your calculator. Either by using [TI-Connect CE](https://education.ti.com/en/software/details/en/CA9C74CAD02440A69FDC7189D7E1B6C2/swticonnectcesoftware) or TiLP (for GNU/Linux, therefore I can't provide a single download link).

### Installation

#### Download

You have two choices:
- Compile the binary files yourself using the [CE toolchain](https://ce-programming.github.io/toolchain/static/getting-started.html). Don't forget to run `make gfx` to make the frame data, before running `make` to compile the source code.
- Download the binary files already compiled from the [releases](https://github.com/Sheep-s4n/TI84-Rick-Roll/releases).

After this, you just have to send `RICKROLL.8xp`, `RICKROLL.8xp.0.8xv`, `RICKROLL.8xp.1.8.xv` and `RICKROLL.8xp.2.8.xv` to your calculator.

#### Usage

> OS version < v5.5

Run the program named `RICKROLL` that you can access by pressing the `[prgm]` button.
> OS version >= v5.5

If you have OS 5.5 or a newer version, you'll have to install [arTIfiCE](https://yvantt.github.io/arTIfiCE/) jailbreak to run the binary eZ80 ASM files. Also, you can install a shell such as [Cesium](https://github.com/mateoconlechuga/cesium/releases) in order to quickly launch the rick roll.

### Notes

- I had to reduce the frames sizes to 120 x 120 instead of keeping their full size as the calculator has only 154 kB of RAM.
- To exit the program, press any key.