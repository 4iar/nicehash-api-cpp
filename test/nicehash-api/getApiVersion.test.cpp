#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../mocks/client.mock.hpp"
#include "nicehash-api.hpp"


using ::testing::AtLeast;
using ::testing::Return;


class GetApiVersionTest : public ::testing::Test {
public:
    MockClient* client;
    NiceHashApi niceHashApi;

    void SetUp() {
        this->client = new MockClient;
        niceHashApi = NiceHashApi(this->client);
    }

    void TearDown() {
        delete(this->client);
    }
};

TEST_F(GetApiVersionTest, GetsTheApiVersion) {
    std::string url = "https://api.nicehash.com/api";
    std::string response_expected = "{\"result\":{\"api_version\":\"1.0.1\"},\"method\":null}";

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));

    std::string response_actual = niceHashApi.getApiVersion();

    EXPECT_EQ(response_actual, response_expected);
}

