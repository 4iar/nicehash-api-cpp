#include <string>

#include "../../include/nicehash-api.hpp"


/**
 * \brief Get all orders for a given algorithm id.
 *
 * Get all orders for a given algorithm (data refreshed every 30 seconds).
 * It (GET) requests https://api.nicehash.com/api?method=orders.get&location=...&algo=...
 * where the algo is an algorithm id and location is a location id (see https://www.nicehash.com/?p=api).
 *
 */
std::string NiceHashApi::getOrdersByAlgorithm (int algorithm_id, int location_id) {

    this->throwExceptionIfAlgorithmInvalid(algorithm_id);
    this->throwExceptionIfLocationInvalid(location_id);

    // Construct the query params (&location= and algo=)
    std::string endpoint = "https://api.nicehash.com/api?method=orders.get";
    std::string url = endpoint + "&location=" + std::to_string(location_id) + "&algo=" + std::to_string(algorithm_id);

    std::string response = this->client->get(url);

    return response;
}

/**
 * \brief Get all orders for a given algorithm by name.
 *
 * Get all orders for a given algorithm (data refreshed every 30 seconds).
 * It (GET) requests https://api.nicehash.com/api?method=orders.get&location=...&algo=...
 * where the algo is an algorithm id and location is a location id (see https://www.nicehash.com/?p=api).
 *
 */
std::string NiceHashApi::getOrdersByAlgorithm (std::string algorithm_name, int location_id) {
    return this->getOrdersByAlgorithm(this->algorithmNameToId(algorithm_name), location_id);
}
