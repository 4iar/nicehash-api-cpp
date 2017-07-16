#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../setup.hpp"

using ::testing::AtLeast;
using ::testing::Return;


class GetProviderStats : public TestSetUp {
};

TEST_F(GetProviderStats, GetsTheProviderStats) {
    std::string url = "https://api.nicehash.com/api?method=stats.provider&addr=1P5PNW6Wd53QiZLdCs9EXNHmuPTX3rD6hW";
    std::string response_expected = "{\"result\":{\"stats\":[{\"balance\":\"0.00010688\",\"rejected_speed\":\"0.0000\",\"algo\":0,\"accepted_speed\":\"0.0820\"},{\"balance\":\"0.00000000\",\"rejected_speed\":\"0.0000\",\"algo\":2,\"accepted_speed\":\"0.0000\"},{\"balance\":\"0.00000000\",\"rejected_speed\":\"0.0000\",\"algo\":3,\"accepted_speed\":\"0.0000\"},{\"balance\":\"0.00000000\",\"rejected_speed\":\"0.0000\",\"algo\":4,\"accepted_speed\":\"0.0000\"},{\"balance\":\"0.00000000\",\"rejected_speed\":\"0.0000\",\"algo\":6,\"accepted_speed\":\"0.0000\"},{\"balance\":\"0.00000000\",\"rejected_speed\":\"0.0000\",\"algo\":7,\"accepted_speed\":\"0.0000\"}],\"payments\":[{\"amount\":\"0.01604289\",\"fee\":\"0.00032741\",\"TXID\":\"e47ce45771b4bb80b52cb787c95eca0bb0779cb5cb7a9af437d1b13e450db7a5\",\"time\":\"2015-01-22 17:03:27\"}],\"addr\":\"16dZdWFr6bhy5bxwsyUyunuWED8zWfQiYA\"},\"method\":\"stats.provider\"}";
    std::string address = "1P5PNW6Wd53QiZLdCs9EXNHmuPTX3rD6hW";

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));

    std::string response_actual = niceHashApi.getProviderStats(address);

    EXPECT_EQ(response_actual, response_expected);
}
