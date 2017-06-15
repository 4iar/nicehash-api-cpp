#include <string>

#include "../../include/nicehash-api.hpp"


/**
 * \brief Get API version. Query this to detect any changes of API.
 *
 * Gets the API version by (GET) requesting https://api.nicehash.com/api
 *
 */
std::string NiceHashApi::getApiVersion () {
    std::string response = this->client->get("https://api.nicehash.com/api");

    return response;
}