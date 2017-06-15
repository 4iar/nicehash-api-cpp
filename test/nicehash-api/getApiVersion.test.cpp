#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../mocks/client.mock.hpp"
#include "nicehash-api.hpp"


using ::testing::AtLeast;


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
    EXPECT_CALL(*client, get(url))
            .Times(1);

    niceHashApi.getApiVersion();
}
