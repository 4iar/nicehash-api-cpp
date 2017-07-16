#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../setup.hpp"


using ::testing::AtLeast;
using ::testing::Return;


class GetProviderWorkerStats : public TestSetUp {
};

TEST_F(GetProviderWorkerStats, GetsTheProviderWorkerStatsByAlgorithmId) {
    std::string url = "https://api.nicehash.com/api?method=stats.provider.workers&addr=17a212wdrvEXWuipCV5gcfxdALfMdhMoqh&algo=3";
    std::string response_expected = "{\n"
            "    \"method\":\"stats.provider.workers\",\n"
            "    \"result\":{\n"
            "        \"addr\":\"17a212wdrvEXWuipCV5gcfxdALfMdhMoqh\",\n"
            "        \"algo\":3,\n"
            "        \"workers\":[[\n"
            "                \"rigname\", // name of the worker\n"
            "                {\"a\":\"11.02\",\"rs\":\"0.54\"}, // speed object\n"
            "                15, // time connected (minutes)\n"
            "                1, // 1 = xnsub enabled, 0 = xnsub disabled\n"
            "                \"0.1\", // difficulty\n"
            "                0, // connected to location (0 for EU, 1 for US, 2 for HK and 3 for JP)\n"
            "            ],\n"
            "            ... // other workers here\n"
            "        ]\n"
            "    }\n"
            "}";
    std::string address = "17a212wdrvEXWuipCV5gcfxdALfMdhMoqh";
    int algorithm_id = 3;

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));

    std::string response_actual = niceHashApi.getProviderWorkerStats(address, algorithm_id);

    EXPECT_EQ(response_actual, response_expected);
}

TEST_F(GetProviderWorkerStats, GetsTheProviderWorkerStatsByAlgorithmName) {
    std::string url = "https://api.nicehash.com/api?method=stats.provider.workers&addr=17a212wdrvEXWuipCV5gcfxdALfMdhMoqh&algo=3";
    std::string response_expected = "{\n"
            "    \"method\":\"stats.provider.workers\",\n"
            "    \"result\":{\n"
            "        \"addr\":\"17a212wdrvEXWuipCV5gcfxdALfMdhMoqh\",\n"
            "        \"algo\":3,\n"
            "        \"workers\":[[\n"
            "                \"rigname\", // name of the worker\n"
            "                {\"a\":\"11.02\",\"rs\":\"0.54\"}, // speed object\n"
            "                15, // time connected (minutes)\n"
            "                1, // 1 = xnsub enabled, 0 = xnsub disabled\n"
            "                \"0.1\", // difficulty\n"
            "                0, // connected to location (0 for EU, 1 for US, 2 for HK and 3 for JP)\n"
            "            ],\n"
            "            ... // other workers here\n"
            "        ]\n"
            "    }\n"
            "}";
    std::string address = "17a212wdrvEXWuipCV5gcfxdALfMdhMoqh";
    std::string algorithm_name = "x11";

    EXPECT_CALL(*client, get(url))
            .WillOnce(Return(response_expected));

    std::string response_actual = niceHashApi.getProviderWorkerStats(address, algorithm_name);

    EXPECT_EQ(response_actual, response_expected);
}

TEST_F(GetProviderWorkerStats, ThrowsExceptionIfAlgorithmIdIsNotValid) {
    std::string address = "17a212wdrvEXWuipCV5gcfxdALfMdhMoqh";
    int invalid_algorithm_id = 1337;
    int valid_algorithm_id = 20;

    ASSERT_NO_THROW(niceHashApi.getProviderWorkerStats(address, valid_algorithm_id));

    ASSERT_THROW(niceHashApi.getProviderWorkerStats(address, invalid_algorithm_id), std::invalid_argument);
}

