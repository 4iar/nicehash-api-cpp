#include <string>

#include "client/client.hpp"


class MockClient : public Client {
public:
    MOCK_METHOD1(get, std::string(std::string const url));
};