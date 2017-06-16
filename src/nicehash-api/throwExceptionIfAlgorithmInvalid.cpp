#include <stdexcept>
#include <set>

#include "../../include/nicehash-api.hpp"


/**
 * \brief Throw an exception if the algorithm id is invalid
 *
 * Throw a std::invalid_argument exception if the algorithm id is invalid.
 * Valid algorithm ids can be found here https://www.nicehash.com/?p=api
 *
 */
void NiceHashApi::throwExceptionIfAlgorithmInvalid (int algorithm_id) {
    // Manually declare these algorithm ids (rather than using a loop) because
    // certain algorithms might be invalidated in the future.
    const std::set<int> valid_algorithm_ids = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                                               13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                                               23, 24, 25, 26, 27};

    const bool algorithm_id_is_valid = valid_algorithm_ids.count(algorithm_id);

    if (!algorithm_id_is_valid)
        throw std::invalid_argument("Algorithm ID is invalid");
}