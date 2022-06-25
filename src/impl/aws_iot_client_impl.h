/**
 * @file aws_iot_client_impl.h
 * @brief AWS IoT client implementation
 */

#pragma once

#include <MQTTClient.h>
#include <WiFiClientSecure.h>
#include <string>

#include "../aws_iot/aws_iot_client.h"
#include "../aws_iot/aws_iot_settings.h"
#include "../aws_iot/aws_iot_topic.h"
#include "aws_iot_subscriber_impl.h"

namespace aws_iot {
class AwsIotClientImpl : public AwsIotClient {
 public:
  AwsIotClientImpl()
      : mqtt_client_(MQTTClient(256)),
        wifi_client_secure_(WiFiClientSecure()){};
  bool Init(const AwsIotSettings aws_iot_settings) noexcept override;
  void Subscribe(const std::string& topic_name) noexcept override;
  void Publish(const std::string& topic_name,
               const std::string& payload) noexcept override;

 private:
  MQTTClient mqtt_client_;
  WiFiClientSecure wifi_client_secure_;
};
}  // namespace aws_iot