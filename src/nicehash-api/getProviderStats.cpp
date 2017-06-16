#include <string>

#include "../../include/nicehash-api.hpp"


/**
 * \brief Get current stats for provider for all algorithms.
 *
 * Get current stats for provider for all algorithms (data refreshed every 30 seconds).
 * It (GET) requests https://api.nicehash.com/api?method=stats.provider&addr=...
 * where the addr param is a wallet address.
 * The past 56 payments are also returned in the response.
 *
 */
std::string NiceHashApi::getProviderStats (std::string address){

    // Construct the query params (&addr=)
    std::string endpoint = "https://api.nicehash.com/api?method=stats.provider&addr=";
    std::string url = endpoint + address;

    std::string response = this->client->get(url);

    return response;
}