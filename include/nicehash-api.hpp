#pragma once

#include <string>

#include "client.hpp"


class NiceHashApi {
private:
    Client* client;
    void throwExceptionIfAlgorithmInvalid (int algorithm_id);
    void throwExceptionIfLocationInvalid (int location_id);
public:
    // Global
    std::string getCurrentGlobalStats ();
    std::string getAverageGlobalStats ();

    // Provider
    std::string getProviderStats (std::string address);
    std::string getDetailedProviderStats (std::string address);
    std::string getProviderWorkerStats (std::string address, int algorithm_id);

    // Orders
    std::string getOrdersByAlgorithm (int algorithm_id, int location_id);
    std::string getMultiAlgorithmInfo ();
    std::string getSimpleMultiAlgorithmInfo ();

    // Helpers
    int algorithmNameToId (std::string algorithm_name);
    std::string algorithmIdToName (int algorithm_id);
    std::string getApiVersion ();

    // Constructors
    NiceHashApi () {
        this->client = new Client;
    };
    NiceHashApi (Client* new_client) {
        this->client = new_client;
    };
};
