# Nicehash API wrapper (C++)

[![Build Status](https://travis-ci.org/4iar/nicehash-api-cpp.svg?branch=master)](https://travis-ci.org/4iar/nicehash-api-cpp)

## Installation

## Usage

## API

### Public

`niceHashApi.getApiVersion()`

#### Global

`niceHashApi.getAverageGlobalStats()`

`niceHashApi.getCurrentGlobalStats()`

#### Provider

`niceHashApi.getProviderStats (std::string address)`

`niceHashApi.getDetailedProviderStats (std::string address)`

`niceHashApi.getProviderWorkerStats (std::string address)`

#### Orders

`niceHashApi.getOrdersByAlgorithm (int algorithm_id, int location_id)`
