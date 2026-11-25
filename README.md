# Temperature Monitor

**AVR digital thermometer: LM35 sensor + ATmega32 + 16x2 LCD, written in layered embedded C.**

## Description

Temperature Monitor reads the ambient temperature from an LM35 analog sensor using the ATmega32's internal ADC and shows it live on a 16x2 character LCD (4-bit mode). It uses the LM35 **full-range** setup, so it can measure **negative temperatures** (-55°C to +150°C) by shifting the sensor signal up with an op-amp circuit. The code is organized in a layered architecture (MCAL / HAL / Service) with configuration headers, so drivers are reusable and hardware changes only need a config edit.

## Features

- Continuous temperature reading from an LM35 sensor
- Full-range measurement (-55°C to +150°C) including negative values
- ADC driver with selectable reference (AREF / AVCC / internal 2.56 V) and prescaler
- 16x2 LCD driver in 4-bit mode (high or low nibble selectable)
- Print helpers for characters, strings and signed integers
- Layered, configurable, register-level drivers (no external HAL libraries)

## Hardware

| Component | Details |
|-----------|---------|
| MCU | ATmega32, 8 MHz (`F_CPU = 8000000UL`) |
| Sensor | LM35 (full-range, 10 mV/°C) |
| Signal conditioning | Op-amp summing amplifier (R1 = R2 = R3 = R4 = 10 kΩ) + 1 V reference (B1) |
| ADC input | Op-amp output on PA0 (ADC0) |
| Display | 16x2 LCD (HD44780), 4-bit mode |
| LCD data | PA4 - PA7 (high nibble) |
| LCD RS / E | PA1 / PA2 |
| ADC reference | Internal 2.56 V |

## Signal Conditioning (Negative Temperatures)

The ATmega32 ADC cannot read negative voltages, but the LM35 outputs negative voltage below 0°C (e.g. -210 mV at -21°C). The op-amp circuit adds a **+1 V offset** to the sensor signal so the ADC always sees a positive voltage:

```
V_out = V_LM35 + 1 V
```

(V+ = (V_LM35 + 1 V) / 2, and the gain is 1 + R3/R4 = 2.)

The firmware then subtracts the same offset (`LM35_OFFSET_MV = 1000`) to recover the real temperature:

| Temperature | LM35 output | Op-amp output (PA0) | ADC input range check |
|-------------|-------------|---------------------|-----------------------|
| -55°C | -550 mV | 450 mV | OK |
| -21°C | -210 mV | 790 mV | OK |
| 0°C | 0 mV | 1000 mV | OK |
| 25°C | 250 mV | 1250 mV | OK |
| +150°C | 1500 mV | 2500 mV | OK (below 2.56 V Vref) |

```
temp(°C) = (ADC × 2560 / 1024 - 1000) / 10
```

> If you use a plain LM35 (0°C to 150°C only) without the op-amp, set `LM35_OFFSET_MV` to `0L`.

## Project Structure

```
Temperature_Monitor/
├── Temperature_Monitor.c      # main application
├── HAL/
│   ├── LCD/                   # lcd.c, lcd.h, lcd_Config.h
│   └── LM35/                  # LM35.c, LM35.h, LM35_Config.h
├── MCAL/
│   ├── ADC/                   # ADC.c, ADC.h, ADC_Config.h, ADC_Reg.h
│   └── DIO/                   # DIO.c, DIO.h, DIO_REG.h
└── serv/                      # STD_TYPE.h, STD_Macros.h
```

## Configuration

- **LCD pins / nibble:** `HAL/LCD/lcd_Config.h`
- **LM35 channel, Vref, scaling, offset:** `HAL/LM35/LM35_Config.h` (keep `LM35_OFFSET_MV` equal to the op-amp circuit's offset)
- **ADC reference and prescaler:** `MCAL/ADC/ADC_Config.h`
- **CPU frequency and types:** `serv/STD_TYPE.h`

## Build & Run

1. Open the project in **Microchip Studio (Atmel Studio)** and select the **ATmega32** device.
2. Make sure the clock is 8 MHz (fuse bits / `F_CPU`).
3. Build, then flash the `.hex` to the MCU (or simulate in Proteus).
4. The LCD shows the live temperature (see the demo below).

## Demo



## How It Works

1. `Init_vLCD4bit()` and `LM35_vInit()` initialize the LCD and ADC.
2. The op-amp shifts the LM35 voltage (10 mV per °C) up by 1 V, and the ADC reads it on PA0.
3. The reading is converted to millivolts, the 1000 mV offset is subtracted, and the result is divided by 10 to get °C (can be negative).
4. The value is written on the LCD in an endless loop.
