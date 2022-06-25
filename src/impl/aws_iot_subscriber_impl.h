/**
 * @file aws_iot_subscriber_impl.h
 * @brief AWS IoT Subscribe
 */

#pragma once

#include <Arduino.h>

namespace aws_iot {
class AwsIotSubscriberImpl {
 public:
  static void Notify(const String topic, const String payload);
};

}  // namespace aws_iot
