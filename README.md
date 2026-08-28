# Nixie Clock

The goal of this project is to build your own Nixie Clock and get a result like this: 


<img width="50%" height="50%" alt="NixieClockPNG" src="https://github.com/user-attachments/assets/d1e34a4e-a483-455f-ad5f-f81e5258e634" />

## Resources
### Controlling the Tubes

The project is based on the idea of controlling the Nixie tubes with old russian driver parts utilizing an arduino nano based on this [article](https://www.instructables.com/Controlling-Nixie-Tube-With-Arduino-Using-K155ID1-/) 

<img width="70%" height="70%" alt="Tubes" src="https://content.instructables.com/FN2/1ZCH/KVGOE71X/FN21ZCHKVGOE71X.png" />


### Real Time Clock (RTC)

In order to keep the time during a power outage or when moving the clock a RTC added to the project. For this purpose the DS3231 was used due to its low cost, easy I2C comunnication and available Arduino libraries.

<img width="20%" height="20%" alt="RTC" src="https://encrypted-tbn0.gstatic.com/shopping?q=tbn:ANd9GcSDtU3tkG2VmIApGWzz9WwgbIkqxKVBMOfeg96Nj73GCxVfh-xf7HzulpxQOxY_ohqEbN519tbpTo6MZ-1UbXGI60lt3EvOn342TQSrz5Q19jvr5SmMBKUBUG2Vq28j6VTwDyKGFQ&usqp=CAc" />

## Designing the PCB

For the PCB Design a Schematic and Layout were designed in Fusion 360 and available for download and use. Before ordering your own PCBs, the DC Jack placement should be adapted as in the current design it sits inverted on the TOP Side. For my build, I fixed it by manipulating the installed DC Jack before soldering it onto the PCB.  

Rendering of PCB V1:

<img width="40%" height="40%" alt="Schematic V1 3D BOTTOM" src="https://github.com/user-attachments/assets/ed71f3c9-ec3f-40fd-b28c-fcd79df5c866" />
<img width="40%" height="40%" alt="Schematic V1 3D TOP" src="https://github.com/user-attachments/assets/46bbb8fd-a7d0-4900-9558-70f116a16dd6" />

## BOM

| Reference Designators | Quantity | Description | Package | Value |
|---|---|---|---|---|
| ARDUINO_NANO | 1 | Arduino Nano V3.0 | ARDUINO_NANO |  |
| C1, C2, C3, C4, C5 | 5 | CAPACITOR, European symbol | C0603 | 100n |
| C6, C7 | 2 | CAPACITOR, European symbol | C0603 | 10u |
| D1 | 1 | DCDC Converter | NIXIE_DCDC | DCDC_NIXIE |
| DC_JACK | 1 | 2.1mm x 5.5mm THM DC jack with internal switch. Digikey part #PJ-102A, 4UCON part #05537 | PJ-102A | 2.1MMJACKTHM |
| DCDC_IN, DCDC_OUT | 2 | PIN HEADER | 1X02 |  |
| L1 | 1 | Linear Regulator 5V | TO220 | L7805_5V |
| NX1, NX2, NX3, NX4 | 4 | IN-14: medium numeric frontview nixie tube | IN-14 | IN-14 |
| R1, R2, R3, R4 | 4 | RESISTOR, European symbol | R1206 | 10k |
| RTC | 1 | RTC Module with Battery and EEPROM based on DS3231 and AT24C32 chips | RTC-DS3231-AT24C32 | RTC-DS3231-AT24C32 |
| U1, U2, U3, U4 | 4 | Nixie Drivers | DIL16 | K155ID1 |

## Software

The Software is split into 2 parts: "SetTime" and "Control".

First the "SetTime" code has to be flashed to the Arduino in order to set the RTC to the current time. Afterwards the "Coltrol" code shall be flashed to actually display the time on the Nixie Tubes. I recommend using the Arduino IDE for programming.

## Case

A ready to print 3D case for the designed PCB is available to download. 

<img width="50%" height="50%" alt="Gehäuse V2" src="https://github.com/user-attachments/assets/7d09da18-d838-4d78-9b70-2e443c91c7ed" />

## Lizenzierung

Dieses Projekt ist dual lizenziert:
- Die **Software und Firmware** steht unter der [Apache 2.0 Lizenz](LICENSE-SOFTWARE).
- Die **Hardware-Designs** (Schaltpläne, CAD-Daten, PCB-Layouts) stehen unter der [CERN-OHL-P v2 Lizenz](LICENSE-HARDWARE).

Beide Lizenzen schließen jegliche Haftung oder Gewährleistung aus. Die Nutzung erfolgt auf eigene Gefahr.





