# esp32-c3-attacks

This repository serves as a comprehensive resource for reproducing the demonstration featured in the article "Hardware security for IoT identity assurance".

With this demonstration, we aim to illustrate how different technologies can be put together to create a secure IoT device built on top of an ESP32-C3. This repository has detailed instructions to set up a demonstration, attack scripts, and firmware implementations that incorporate countermeasures against the demonstrated hardware attacks.

## Table of Content
* [Vulnerable firmware](vulnerable-firmware)
* Attacks
    * [Voltage Glitch](attacks/voltage-glitch)
    * [Timing Attack](attacks/timing-attack)
    * [PCB level Attack](attacks/pcb-level-attack)

## Compile firmware and flash to hardware

```
$ make build flash monitor
```

## Required equipment
* Ai-Thinker ESP-C3-13 
* Rework station
* Soldering station
* Stereo microscope
* Multimeter
* Tweezer
* Scapel
* 0.01 copper cable
* 2 x Variable voltage power supply
* TS12A4514P and TS12A4515P
* Breadboard
* Dupont cables
* ChipWhisperer-Nano
* Saleae Logic 8 logic analyzer
* FT232H
* XGecu TL866II Plus

## Software requirements
* docker
* make
* jupyter
* Ghidra
