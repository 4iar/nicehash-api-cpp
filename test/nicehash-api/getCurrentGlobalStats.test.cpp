#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../setup.hpp"


using ::testing::Return;


class GetCurrentGlobalStats : public TestSetUp {
};

TEST_F(GetCurrentGlobalStats, GetsTheCurrentGlobalStats) {
    std::string url = "https://api.nicehash.com/api?method=stats.global.current";
    std::string response_expected = "{\"result\":{\"stats\":[{\"profitability_above_ltc\":\"8.27\",\"price\":\"0.1683\",\"profitability_ltc\":\"0.1554\",\"algo\":0,\"speed\":\"27.0678\"},{\"price\":\"0.0117\",\"profitability_btc\":\"0.0114\",\"profitability_above_btc\":\"2.39\",\"algo\":1,\"speed\":\"1597723.0669\"},{\"profitability_above_ltc\":\"89.98\",\"price\":\"0.5906\",\"profitability_ltc\":\"0.1554\",\"algo\":2,\"speed\":\"0.0038\"},{\"profitability_above_ltc\":\"610.26\",\"price\":\"0.2007\",\"profitability_ltc\":\"0.1554\",\"algo\":3,\"speed\":\"24.9009\"},{\"profitability_above_ltc\":\"119.72\",\"price\":\"0.0854\",\"profitability_ltc\":\"0.1554\",\"algo\":4,\"speed\":\"0.5826\"},{\"profitability_above_ltc\":\"190.79\",\"price\":\"0.0009\",\"profitability_ltc\":\"0.1554\",\"algo\":5,\"speed\":\"2.6436\"},{\"profitability_above_ltc\":\"123.75\",\"price\":\"0.0994\",\"profitability_ltc\":\"0.1554\",\"algo\":6,\"speed\":\"0.0275\"},{\"profitability_above_ltc\":\"-100.00\",\"price\":\"0.0000\",\"profitability_ltc\":\"0.1554\",\"algo\":7,\"speed\":\"0.0000\"},{\"profitability_above_ltc\":\"405.27\",\"price\":\"2.6180\",\"profitability_ltc\":\"0.1554\",\"algo\":8,\"speed\":\"0.1194\"},{\"profitability_above_ltc\":\"293.06\",\"price\":\"0.4888\",\"profitability_ltc\":\"0.1554\",\"algo\":9,\"speed\":\"0.0346\"}]},\"method\":\"stats.global.current\"}";

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));

    std::string response_actual = niceHashApi.getCurrentGlobalStats();

    EXPECT_EQ(response_actual, response_expected);
}
