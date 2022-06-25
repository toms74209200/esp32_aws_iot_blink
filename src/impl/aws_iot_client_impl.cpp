/**
 * @file aws_iot_client_impl.cpp
 * @brief AWS IoT client implementation
 */

#include "aws_iot_client_impl.h"

bool aws_iot::AwsIotClientImpl::Init(
    const aws_iot::AwsIotSettings aws_iot_settings) noexcept {
  Serial.println("init");
  wifi_client_secure_.setCACert(aws_iot_settings.cert_ca.c_str());
  wifi_client_secure_.setCertificate(aws_iot_settings.cert_crt.c_str());
  wifi_client_secure_.setPrivateKey(aws_iot_settings.cert_private.c_str());
  mqtt_client_.begin(aws_iot_settings.end_point.c_str(), aws_iot_settings.port,
                     wifi_client_secure_);
  mqtt_client_.onMessage(aws_iot::AwsIotSubscriberImpl::Notify);
  Serial.print("AWS IoT connecting");
  while (!mqtt_client_.connect(aws_iot_settings.thing_name.c_str())) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nconnected");
  return mqtt_client_.connected();
}

void aws_iot::AwsIotClientImpl::Subscribe(
    const std::string& topic_name) noexcept {
  Serial.println("subscribe");
  mqtt_client_.subscribe(topic_name.c_str());
}

void aws_iot::AwsIotClientImpl::Publish(const std::string& topic_name,
                                        const std::string& payload) noexcept {
  Serial.println("publish");
  mqtt_client_.publish(topic_name.c_str(), payload.c_str());
}
