#include <nicehash-api.hpp>
#include <iostream>

int main () {
    NiceHashApi niceHashApi;

    std::cout << "Api version: " << niceHashApi.getApiVersion() << std::endl;

    std::cout << "Global averages : " << niceHashApi.getAverageGlobalStats() << std::endl;
}
