#pragma once

#include <gmock/gmock.h>

#include "aws_iot_client.h"

namespace aws_iot {
class AwsIotClientMock : public AwsIotClient {
 public:
  MOCK_METHOD1(Init, bool(const AwsIotSettings aws_iot_settings));
  MOCK_METHOD1(Subscribe, void(const std::string& topic_name));
  MOCK_METHOD2(Publish,
               void(const std::string& topic_name, const std::string& payload));
};
}  // namespace aws_iot