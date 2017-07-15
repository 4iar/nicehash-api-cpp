#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <stdexcept>

#include "../mocks/client.mock.hpp"
#include "nicehash-api.hpp"


using ::testing::AtLeast;
using ::testing::Return;


class GetOrdersById : public ::testing::Test {
public:
    std::shared_ptr<MockClient> client;
    NiceHashApi niceHashApi;

    void SetUp() {
        this->client = std::shared_ptr<MockClient>(new MockClient);
        niceHashApi = NiceHashApi(this->client);
    }
};

TEST_F(GetOrdersById, GetsOrdersByTheAlgorithmIdAndLocationId) {
    // Location id 0
    std::string url = "https://api.nicehash.com/api?method=orders.get&location=0&algo=3";
    std::string response_expected = "{\"result\":{\"orders\":[{\"type\":0,\"id\":5877,\"price\":\"0.0505\",\"algo\":1,\"alive\":true,\"limit_speed\":\"1.0\",\"workers\":0,\"accepted_speed\":0.0}]},\"method\":\"orders.get\"}";
    int algorithm_id = 3;
    int location_id = 0;

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));
    std::string response_actual = niceHashApi.getOrdersByAlgorithm(algorithm_id, location_id);
    EXPECT_EQ(response_actual, response_expected);

    // Location id 1
    url = "https://api.nicehash.com/api?method=orders.get&location=1&algo=3";
    location_id = 1;

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));
    response_actual = niceHashApi.getOrdersByAlgorithm(algorithm_id, location_id);
    EXPECT_EQ(response_actual, response_expected);
}

TEST_F(GetOrdersById, GetsOrdersByTheAlgorithmNameAndLocationId) {
    // Location id 0
    std::string url = "https://api.nicehash.com/api?method=orders.get&location=0&algo=3";
    std::string response_expected = "{\"result\":{\"orders\":[{\"type\":0,\"id\":5877,\"price\":\"0.0505\",\"algo\":1,\"alive\":true,\"limit_speed\":\"1.0\",\"workers\":0,\"accepted_speed\":0.0}]},\"method\":\"orders.get\"}";
    std::string algorithm_name = "x11";
    int location_id = 0;

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));
    std::string response_actual = niceHashApi.getOrdersByAlgorithm(algorithm_name, location_id);
    EXPECT_EQ(response_actual, response_expected);

    // Location id 1
    url = "https://api.nicehash.com/api?method=orders.get&location=1&algo=3";
    location_id = 1;

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));
    response_actual = niceHashApi.getOrdersByAlgorithm(algorithm_name, location_id);
    EXPECT_EQ(response_actual, response_expected);
}

TEST_F(GetOrdersById, ThrowsExceptionIfAlgorithmIdIsNotValid) {
    int location_id = 0;
    int invalid_algorithm_id = 1337;
    int valid_algorithm_id = 20;

    ASSERT_NO_THROW(niceHashApi.getOrdersByAlgorithm(valid_algorithm_id, location_id));

    ASSERT_THROW(niceHashApi.getOrdersByAlgorithm(invalid_algorithm_id, location_id), std::invalid_argument);
}

