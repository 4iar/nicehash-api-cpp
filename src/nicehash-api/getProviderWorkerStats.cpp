#include <string>

#include "../../include/nicehash-api.hpp"


/**
 * \brief Get detailed stats for a provider's workers
 *
 * Get current stats for provider for all algorithms (data refreshed every 30 seconds).
 * It (GET) requests https://api.nicehash.com/api?method=stats.provider&addr=...
 * where the addr param is a wallet address.
 * The past 56 payments are also returned in the response.
 *
 */
std::string NiceHashApi::getProviderWorkerStats (std::string address, int algorithm_id){

    this->throwExceptionIfAlgorithmInvalid(algorithm_id);

    // Construct the query params (&addr= and algo=)
    std::string endpoint = "https://api.nicehash.com/api?method=stats.provider.workers&addr=";
    std::string url = endpoint + address + "&algo=" + std::to_string(algorithm_id);

    std::string response = this->client->get(url);

    return response;
}