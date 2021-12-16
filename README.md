# TE-Connectivity HTU21D(F) driver usage example
TE-Connectivity HTU21D(F) driver usage example

## Requirements
### Hardware requirements
The following boards are required:
- Zest Sensor T-RH
- Zest Core MTXDot

### Software requirements
TE-Connectivity HTU21D(F) driver usage example makes use of the following libraries (automatically
imported by `mbed deploy` or `mbed import`):
- te-connectivity-htu21d
- zest-core-mtxdot

## Usage
To clone **and** deploy the project in one command, use `mbed import` and skip to the
target enabling instructions:
```shell
mbed import https://gitlab.com/koncepto/CATIE/3sqair/software/te-connectivity-htu21d-example.git te-connectivity-htu21d-example
```

Alternatively:

- Clone to "te-connectivity-htu21d-example" and enter it:
  ```shell
  git clone https://gitlab.com/koncepto/CATIE/3sqair/software/te-connectivity-htu21d-example.git te-connectivity-htu21d-example
  cd te-connectivity-htu21d-example
  ```

- Deploy software requirements with:
  ```shell
  mbed deploy
  ```

Enable the custom target:
```shell
cp zest-core-mtxdot/custom_targets.json .
```

Compile the project:
```shell
mbed compile
```

Program the target device with a Segger J-Link debug probe and
[`sixtron_flash`](https://gitlab.com/catie_6tron/6tron-flash) tool:
```shell
sixtron_flash stm32l151cc BUILD/ZEST_CORE_MTXDOT/GCC_ARM/te-connectivity-htu21d-example.elf
```

Debug on the target device with the probe and Segger
[Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger)
software.
