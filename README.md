<p align="center">
<img width="250" src="https://raw.githubusercontent.com/4iar/nicehash-api-cpp/assets/logo.jpg">
</p>

# Nicehash API wrapper (C++)

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://travis-ci.org/4iar/nicehash-api-cpp.svg?branch=master)](https://travis-ci.org/4iar/nicehash-api-cpp)

A C++ API wrapper for the [NiceHash](https://www.nicehash.com/) cloud cryptomining service.

## Requirements

- cURL libs (e.g. Fedora: libcurl-devel, Ubuntu/Debian: libcurl-dev)

- CMake >= 3.1

## Setup

See example CMakeLists.txt in the [examples/](https://github.com/4iar/nicehash-api-cpp/tree/master/examples) folder that uses
[ExternalProject](https://cmake.org/cmake/help/v3.2/module/ExternalProject.html) to integrate nicehash-api-cpp with an existing CMake project.

Alternatively, manually build the library as below, then link libnicehash-api-cpp.so.

```bash
git clone https://github.com/4iar/nicehash-api-cpp.git && cd nicehash-api-cpp
mkdir build && cd build
cmake ..
make
```


## Usage



```cpp
#include <nicehash-api.hpp>

...

    // Initialise client
    NiceHashApi niceHashApi;

    // Run a query
    // (see docs below for all API functions)
    std::string algorithm_name = "equihash";
    std::string stats = niceHashApi.getOrdersByAlgorithm(algorithm_name, 0)
```

## API

Official documentation @ [NiceHash.com](https://www.nicehash.com/?p=api)

### Public

`niceHashApi.getApiVersion()`

#### Global

##### stats.global.current

Get current profitability (price) and hashing speed for all algorithms. Refreshed every 30 seconds.

`niceHashApi.getAverageGlobalStats()`

##### stats.global.24h

Get average profitability (price) and hashing speed for all algorithms in past 24 hours.

`niceHashApi.getCurrentGlobalStats()`

#### Provider

##### stats.provider

Get current stats for provider for all algorithms. Refreshed every 30 seconds. It also returns past 56 payments.

`niceHashApi.getProviderStats (std::string address)`

##### stats.provider.ex

Get detailed stats for provider for all algorithms including history data and past 56 payments.

`niceHashApi.getDetailedProviderStats (std::string address)`

##### stats.provider.workers

Get detailed stats for provider's workers (rigs).

`niceHashApi.getProviderWorkerStats (std::string address, int algorithm_id)`

or

`niceHashApi.getProviderWorkerStats (std::string address, std::string algorithm_name)`

#### Orders

##### orders.get

Get all orders for certain algorithm. Refreshed every 30 seconds.

`niceHashApi.getOrdersByAlgorithm (int algorithm_id, int location_id)`

or

`niceHashApi.getOrdersByAlgorithm (std::string algorithm_name, int location_id)`

#### Algorithms

##### multialgo.info

Get information about Mult-Algorithm Mining.

##### simplemultialgo.info

Get information about Simple Multi-Algorithm Mining.

### Private

##### orders.get&my
##### orders.create
##### orders.refill
##### orders.remove
##### orders.set.price
##### orders.set.price.decrease
##### orders.set.limit
##### balance
