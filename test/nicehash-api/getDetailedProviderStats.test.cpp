#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../setup.hpp"


using ::testing::Return;


class GetDetailedProviderStats : public TestSetUp {
};

TEST_F(GetDetailedProviderStats, GetsTheDetailedProviderStats) {
    std::string url = "https://api.nicehash.com/api?method=stats.provider.ex&addr=17a212wdrvEXWuipCV5gcfxdALfMdhMoqh";
    std::string response_expected = "{\n"
            "    \"method\":\"stats.provider.ex\",\n"
            "    \"result\":{\n"
            "        \"addr\":\"17a212wdrvEXWuipCV5gcfxdALfMdhMoqh\",\n"
            "        \"current\":[{\n"
            "            \"algo\":3, // algorithm number (3 = X11)\n"
            "            \"name\":\"X11\", // algorithm name\n"
            "            \"suffix\":\"MH\", // speed suffix (kH, MH, GH, TH,...)\n"
            "            \"profitability\":\"0.00045845\", // current profitability in BTC/suffix/Day\n"
            "            \"data\":[{ // speed object can contain following fields: \n"
            "                      // a (accepted), rt (rejected target), rs (rejected stale), \n"
            "                      // rd (rejected duplicate) and ro (rejected other)\n"
            "                      // if fields are not present, speed is 0\n"
            "                \"a\":\"23.09\", // accepted speed (in MH/s for X11)\n"
            "                \"rs\":\"0.54\", // rejected speed - stale\n"
            "                },\n"
            "                \"0.0001234\" // balance (unpaid)\n"
            "            ]},\n"
            "            ... // other algorithms here \n"
            "        ],\n"
            "        \"past\":[{\n"
            "            \"algo\":3,\n"
            "            \"data\":[\n"
            "                [4863234, // timestamp; multiply with 300 to get UNIX timestamp\n"
            "                {\"a\":\"28.6\"}, // speed object\n"
            "                \"0\" // balance (unpaid)\n"
            "                ],[4863235,{\"a\":\"27.4\"},\"0.00000345\"],\n"
            "                ... // next entries with inc. timestamps\n"
            "            ]},\n"
            "            ... // other algorithms here\n"
            "        ],\n"
            "        \"payments\":[{\n"
            "            \"amount\":\"0.00431400\",\n"
            "            \"fee\":\"0.00023000\",\n"
            "            \"TXID\":\"txidhere\",\n"
            "            \"time\":1453538732, // UNIX timestamp\n"
            "            \"type\":0 // payment type (0 for standard NiceHash payment)\n"
            "        },\n"
            "        ... // other payments here\n"
            "        ]\n"
            "    }\n"
            "}\n"
            "";
    std::string address = "17a212wdrvEXWuipCV5gcfxdALfMdhMoqh";

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));

    std::string response_actual = niceHashApi.getDetailedProviderStats(address);

    EXPECT_EQ(response_actual, response_expected);
}
