#include <stdexcept>
#include <set>

#include "../../include/nicehash-api.hpp"


/**
 * \brief Throw an exception if the location id is invalid
 *
 * Throw a std::invalid_argument exception if the location id is invalid.
 * Valid location ids can be found here https://www.nicehash.com/?p=api
 * Currently there are only two locations (0, 1) but this may change in the
 * future, so this function is here for flexibility later (but currently a bit overkill).
 *
 */
void NiceHashApi::throwExceptionIfLocationInvalid (int location_id) {
    const std::set<int> valid_location_ids = { 0, 1 };

    const bool location_id_is_valid = valid_location_ids.count(location_id);

    if (!location_id_is_valid)
        throw std::invalid_argument("Location ID is invalid");
}

