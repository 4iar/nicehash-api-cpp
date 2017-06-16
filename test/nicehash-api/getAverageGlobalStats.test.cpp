#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../mocks/client.mock.hpp"
#include "nicehash-api.hpp"


using ::testing::AtLeast;
using ::testing::Return;


class GetAverageGlobalStats : public ::testing::Test {
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

TEST_F(GetAverageGlobalStats, GetsTheAverageGlobalStats) {
    std::string url = "https://api.nicehash.com/api?method=stats.global.24h";
    std::string response_expected = "{\"result\":{\"stats\":[{\"price\":\"0.1962\",\"algo\":0,\"speed\":\"23.8031\"},{\"price\":\"0.0118\",\"algo\":1,\"speed\":\"1576060.6047\"},{\"price\":\"0.3759\",\"algo\":2,\"speed\":\"0.0041\"},{\"price\":\"0.1998\",\"algo\":3,\"speed\":\"25.0689\"},{\"price\":\"0.2213\",\"algo\":4,\"speed\":\"1.5202\"},{\"price\":\"0.0008\",\"algo\":5,\"speed\":\"2.4735\"},{\"price\":\"0.1559\",\"algo\":6,\"speed\":\"0.0324\"},{\"price\":\"0.0000\",\"algo\":7,\"speed\":\"0.0000\"},{\"price\":\"2.9811\",\"algo\":8,\"speed\":\"0.1268\"},{\"price\":\"0.4853\",\"algo\":9,\"speed\":\"0.0304\"}]},\"method\":\"stats.global.24h\"}";

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));

    std::string response_actual = niceHashApi.getAverageGlobalStats();

    EXPECT_EQ(response_actual, response_expected);
}
