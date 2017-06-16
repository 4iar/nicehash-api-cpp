#include <string>
#include <set>
#include <stdexcept>

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

    // Manually declare these algorithm ids (rather than using a loop) because
    // certain algorithms might be invalidated in the future.
    const std::set<int> valid_algorithm_ids = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                                         13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                                         23, 24, 25, 26, 27};
    const bool algorithm_id_is_valid = valid_algorithm_ids.count(algorithm_id);
    if (!algorithm_id_is_valid)
        throw std::invalid_argument("Algorithm ID is invalid");

    // Construct the query params (&addr= and algo=)
    std::string endpoint = "https://api.nicehash.com/api?method=stats.provider.workers&addr=";
    std::string url = endpoint + address + "&algo=" + std::to_string(algorithm_id);

    std::string response = this->client->get(url);

    return response;
}