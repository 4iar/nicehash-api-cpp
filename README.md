# Nicehash API wrapper (C++)

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://travis-ci.org/4iar/nicehash-api-cpp.svg?branch=master)](https://travis-ci.org/4iar/nicehash-api-cpp)

## Installation

## Usage

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

`niceHashApi.getProviderWorkerStats (std::string address)`

#### Orders

##### orders.get

Get all orders for certain algorithm. Refreshed every 30 seconds.

`niceHashApi.getOrdersByAlgorithm (int algorithm_id, int location_id)`

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
