#include <nicehash-api.hpp>
#include <iostream>

int main () {
    NiceHashApi niceHashApi;

    std::cout << "Api version: " << niceHashApi.getApiVersion() << std::endl;

    std::cout << "Possible algorithms: \n" <<
            "0 = Scrypt\n"
            "1 = SHA256\n"
            "2 = ScryptNf\n"
            "3 = X11\n"
            "4 = X13\n"
            "5 = Keccak\n"
            "6 = X15\n"
            "7 = Nist5\n"
            "8 = NeoScrypt\n"
            "9 = Lyra2RE\n"
            "10 = WhirlpoolX\n"
            "11 = Qubit\n"
            "12 = Quark\n"
            "13 = Axiom\n"
            "14 = Lyra2REv2\n"
            "15 = ScryptJaneNf16\n"
            "16 = Blake256r8\n"
            "17 = Blake256r14\n"
            "18 = Blake256r8vnl\n"
            "19 = Hodl\n"
            "20 = DaggerHashimoto\n"
            "21 = Decred\n"
            "22 = CryptoNight\n"
            "23 = Lbry\n"
            "24 = Equihash\n"
            "25 = Pascal\n"
            "26 = X11Gost\n"
            "27 = Sia\n"
            "28 = Blake2s\n\n\n\n"
              << std::endl;

    // Provide algorithm by id
    std::cout << "X11 orders: " << niceHashApi.getOrdersByAlgorithm(3, 0) << "\n\n\n\n" << std::endl;

    // or by name
    std::string algorithm_name = "equihash";
    std::cout << "Equihash orders: " << niceHashApi.getOrdersByAlgorithm(algorithm_name, 0) << std::endl;
}
