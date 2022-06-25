/**
 * @file aws_iot_topic.h
 * @brief AWS IoT topic
 */

#pragma once

namespace aws_iot {
struct AwsIotTopic {
  AwsIotTopic(std::string topic, std::string payload)
      : topic(topic), payload(payload){};
  const std::string topic;
  const std::string payload;
};
}  // namespace aws_iot