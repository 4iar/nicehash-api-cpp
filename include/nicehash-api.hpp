#pragma once

#include <string>

#include "client.hpp"


class NiceHashApi {
private:
    Client* client;
public:
    // Global
    std::string getCurrentGlobalStats ();
    std::string getAverageGlobalStats ();

    // Provider
    std::string getProviderStats ();
    std::string getDetailedProviderStats ();
    std::string getProviderWorkers ();

    // Orders
    std::string getAlgorithmOrders ();
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
