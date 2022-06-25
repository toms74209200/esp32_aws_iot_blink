/**
 * @file aws_iot_client.h
 * @brief AWS IoT client
 */

#pragma once

#include <string>

namespace aws_iot {
class AwsIotClient {
 public:
  virtual AwsIotClient& SetEndPoint(const std::string end_point) = 0;
  virtual AwsIotClient& SetCert(const std::string cert) = 0;
  virtual AwsIotClient& SetAwsKey(const std::string aws_key) = 0;
  virtual AwsIotClient& SetSecret(const std::string secret) = 0;
  virtual AwsIotClient& SetDevice(const std::string device) = 0;
  virtual bool Init() const = 0;
};
}  // namespace aws_iot