# Ceedling Microchip Example

Sample project on how to use Ceedling for a multi-target project targeting 
different Microchip controllers.

This is quite an advanced project in terms of tooling setup. It aims to
illustrate the setup needed to run tests on host, simulator and hardware along
with support for targeting different devices with differenet toolchain.

This project uses the [mdb](https://github.com/deltalejo/ceedling-mdb-plugin)
Ceedling plugin to ease the task of running tests on both simulator and hardware.

_Make sure you have a working installation of Ceedling, MPLAB X and the XC
compilers._

## Contents

<!-- TOC -->

- [Contents](#contents)
- [Get Started](#get-started)
	- [Get Sources](#get-sources)
	- [Setup Environment](#setup-environment)
- [Project organization](#project-organization)
	- [Platforms](#platforms)
	- [Toolchains](#toolchains)
	- [Targets](#targets)
- [Running tests](#running-tests)
	- [Host](#host)
	- [Simulator](#simulator)
	- [Hardware](#hardware)

<!-- /TOC -->

## Get Started

### Get Sources

Clone this repo somewhere on your PC. e.g:

```shell
cd somewhere/in/your/pc
git clone https://github.com/deltalejo/ceedling-microchip-example.git
cd ceedling-microchip-example
```

### Setup Environment

Inside project's root, create a `env.yml` file and set its contents accordingly.
e.g.:

```yaml
---
:environment:
  # MPLAB X path (for packs on MPLABX installation dir)
  - :mplabx_path: /opt/microchip/mplabx/v6.20
  # Device Packs path (for packs on user installation dir)
  - :dfp_path: ~/.mchp_packs
  # Compilers paths
  - :xc8_path: /opt/microchip/xc8/v2.46
  - :xc16_path: /opt/microchip/xc16/v2.10
  - :xc32_path: /opt/microchip/xc32/v4.40
  - :xcdsc_path: /opt/microchip/xc-dsc/v3.10
  - :path:
      - "#{ENV['XC8_PATH']}/bin"
      - "#{ENV['XC16_PATH']}/bin"
      - "#{ENV['XC32_PATH']}/bin"
      - "#{ENV['XCDSC_PATH']}/bin"
      - "#{ENV['PATH']}"
...
```

## Project organization

The project is set up to support multiple target devices each requiring
potentially a different toolchain and allows for running tests on host,
simulator and hardware.

### Platforms

Each platform has a corresponding configuration file inside `platforms` dir
containing only settings specific to the platform, for example, build root dir.

The following are the supported platforms:

- Host: [**`host.yml`**](platforms/host.yml)
- Simulator: [**`simulator.yml`**](platforms/simulator.yml)
- Target: [**`target.yml`**](platforms/target.yml)

### Toolchains

### Targets

## Running tests

### Host

`ceedling -m PIC18F26K22 -m host -m gcc test:all`

### Simulator

`ceedling -m PIC18F26K22 -m simulator -m xc8 test:all`

### Hardware

`ceedling -m PIC18F26K22 -m target -m xc8 mdb:serialport[/dev/ttyUSB0] test:all`
