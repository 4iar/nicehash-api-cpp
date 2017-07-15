#pragma once

#include <string>
#include <memory>

#include "client.hpp"


class NiceHashApi {
private:
    std::shared_ptr<Client> client;
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
    std::string getProviderWorkerStats (std::string address, std::string algorithm_name);

    // Orders
    std::string getOrdersByAlgorithm (int algorithm_id, int location_id);
    std::string getOrdersByAlgorithm (std::string algorithm_name, int location_id);
    std::string getMultiAlgorithmInfo ();
    std::string getSimpleMultiAlgorithmInfo ();

    // Helpers
    int algorithmNameToId (std::string algorithm_name);
    std::string algorithmIdToName (int algorithm_id);
    std::string getApiVersion ();

    // Constructors
    NiceHashApi ()
        : NiceHashApi(std::shared_ptr<Client>(new Client)) {};
    NiceHashApi (std::shared_ptr<Client> new_client) {
        this->client = new_client;
    };
};
