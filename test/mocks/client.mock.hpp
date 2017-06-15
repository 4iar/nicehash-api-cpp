#pragma once

#include <string>

#include <client.hpp>


class MockClient : public Client {
public:
    MOCK_METHOD1(get, std::string(std::string const url));
};