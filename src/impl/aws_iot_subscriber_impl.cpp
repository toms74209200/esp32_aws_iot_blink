/**
 * @file aws_iot_subscriber_impl.cpp
 * @brief AWS IoT Subscribe listener
 */

#include "aws_iot_subscriber_impl.h"

void aws_iot::AwsIotSubscriberImpl::Notify(const String topic,
                                           const String payload) {
  Serial.printf("topic: %s\npayload: %s\n", topic, payload);
}