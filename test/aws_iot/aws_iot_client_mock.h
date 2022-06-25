#pragma once

#include <gmock/gmock.h>

#include "aws_iot_client.h"

namespace aws_iot {
class AwsIotClientMock : public AwsIotClient {
 public:
  MOCK_METHOD1(SetEndPoint, AwsIotClient&(std::string end_point));
  MOCK_METHOD1(SetCert, AwsIotClient&(std::string cert));
  MOCK_METHOD1(SetAwsKey, AwsIotClient&(std::string aws_key));
  MOCK_METHOD1(SetSecret, AwsIotClient&(std::string secret));
  MOCK_METHOD1(SetDevice, AwsIotClient&(std::string device));
  MOCK_CONST_METHOD0(Init, bool());
};
}  // namespace aws_iot