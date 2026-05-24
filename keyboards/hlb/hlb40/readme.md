# HLB H40-H / H40-EC

* Keyboard Maintainer: [H3lli0n](https://github.com/H3lli0n/)
* Hardware Supported: HLB40-H (RP2040) / HLB40-EC (SMT32F411);
* Hardware Availability: HLB40 - a 40% atari inspired keyboard

HLB H40-H / H40-EC : HHKB 6U 40% keyboard with a hotswap MX pcb and an EC (Dynacap and Naevies) compatible one.
PCB comes in hotswap format `hlb40_h` and EC version `hlb40_ec`. After checking what PCB you own and setting up your build environment, you can compile the default keymap by using one of the options below.

Make example for this keyboard (after setting up your build environment):  

    make hlb/hlb40/<version>:default

Flashing example for this keyboard:

    make hlb/hlb40/<version>:default:flash
    
Where `<version>` can be `hlb40_h` or `hlb40_ec`.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the thumb key on the left and plug in the keyboard. For the right side, hold the thumb key on the right and plug the keyboard.
* **Physical reset button**: 
  * Press and hold the BOOT0 button.
  * Press and release the NRST button.
  * Release the BOOT0 button.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
