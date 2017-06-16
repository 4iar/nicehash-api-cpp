#include <string>

#include "../../include/nicehash-api.hpp"


/**
 * \brief Get average (24h) global stats.
 *
 * Gets the average (24h) global stats by (GET) requesting https://api.nicehash.com/api?method=stats.global.24h
 *
 */
std::string NiceHashApi::getAverageGlobalStats (){
    std::string response = this->client->get("https://api.nicehash.com/api?method=stats.global.24h");

    return response;
}