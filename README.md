# esp32-c3-attacks

This repository serves as a comprehensive resource for  reproducing the demonstration featured in the article "Hardware security for IoT identity assurance".


 This repository has detailed instructions to set up a demonstration 

, attack scripts, and firmware implementations that incorporate countermeasures against the demonstrated attacks.

## Table of Content
* (Vulnerable firmware)[vulnerable-firmware]
* Attacks
    * (Voltage Glitch)[attacks/voltage-glitch]
    * (Timing Attck)[attacks/timing-attack]
    * (PCB level Attack)[attacks/pcb-level-attack]

## Compile firmware and flash to hardware

```
$ make build flash monitor
```

## Requirements
* docker
* make