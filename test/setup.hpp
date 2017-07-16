#include <memory>

#include "mocks/client.mock.hpp"
#include "nicehash-api.hpp"


class TestSetUp : public ::testing::Test {
public:
    std::shared_ptr<MockClient> client;
    NiceHashApi niceHashApi;

    void SetUp() {
        this->client = std::shared_ptr<MockClient>(new MockClient);
        niceHashApi = NiceHashApi(this->client);
    }
};
