#include <map>
#include <algorithm>
#include <cctype>
#include <iostream>

#include "../../include/nicehash-api.hpp"

std::string strToUpper(std::string strToConvert);

/**
 * \brief Convert an algorithm name to its id
 *
 * See https://www.nicehash.com/?p=api for name->id mappings
 *
 */
int NiceHashApi::algorithmNameToId(std::string algorithm_name) {
    std::map<std::string, int> mappings = {
            {"SCRYPT", 0},
            {"SHA256", 1},
            {"SCRYPTNF", 2},
            {"X11", 3},
            {"X13", 4},
            {"KECCAK", 5},
            {"X15", 6},
            {"NIST5", 7},
            {"NEOSCRYPT", 8},
            {"LYRA2RE", 9},
            {"WHIRLPOOLX", 10},
            {"QUBIT", 11},
            {"QUARK", 12},
            {"AXIOM", 13},
            {"LYRA2REV2", 14},
            {"SCRYPTJANENF16", 15},
            {"BLAKE256R8", 16},
            {"BLAKE256R14", 17},
            {"BLAKE256R8VNL", 18},
            {"HODL", 19},
            {"DAGGERHASHIMOTO", 20},
            {"DECRED", 21},
            {"CRYPTONIGHT", 22},
            {"LBRY", 23},
            {"EQUIHASH", 24},
            {"PASCAL", 25},
            {"X11GOST", 26},
            {"SIA", 27},
            {"BLAKE2S", 28}
    };

    return mappings[strToUpper(algorithm_name)];
}

std::string strToUpper(std::string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}

