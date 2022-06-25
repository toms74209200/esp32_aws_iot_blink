/**
 * @file aws_iot_client.h
 * @brief AWS IoT client
 */

#pragma once

#include <string>

#include "aws_iot_settings.h"
#include "aws_iot_topic.h"

namespace aws_iot {
class AwsIotClient {
 public:
  virtual bool Init(const AwsIotSettings aws_iot_settings) = 0;
  virtual void Subscribe(const std::string& topic_name) = 0;
  virtual void Publish(const std::string& topic_name,
                       const std::string& payload) = 0;
};
}  // namespace aws_iot