#include <string>

#include "../../include/nicehash-api.hpp"


/**
 * \brief Get current global stats.
 *
 * Gets the current global stats by (GET) requesting https://api.nicehash.com/api?method=stats.global.current
 *
 */
std::string NiceHashApi::getCurrentGlobalStats () {
    std::string response = this->client->get("https://api.nicehash.com/api?method=stats.global.current");

    return response;
}