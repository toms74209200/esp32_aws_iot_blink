/**
 * @file input_setting.h
 * @brief input settings from UART
 */

#pragma once

#include "../aws_iot/aws_iot_client.h"
#include "../json/json_parser.h"
#include "../wifi/wifi_client.h"
#include "uart_client.h"

namespace uart {
struct Constants {
  static const std::string kSsidKey;
  static const std::string kPasswordKey;
  static const std::string kEndPointKey;
  static const std::string kCertKey;
  static const std::string kAwsKeyKey;
  static const std::string kSecretKey;
  static const std::string kDeviceKey;
};
class InputSetting {
 public:
  InputSetting(aws_iot::AwsIotClient &aws_iot_client,
               const json::JsonParser &json_parser,
               const uart::UartClient &uart_client,
               const wifi::WifiClient &wifi_client)
      : aws_iot_client_(aws_iot_client),
        json_parser_(json_parser),
        uart_client_(uart_client),
        wifi_client_(wifi_client){};
  void RecvWifiSetting() const noexcept;
  void RecvAwsSetting() const noexcept;

 private:
  aws_iot::AwsIotClient &aws_iot_client_;
  const json::JsonParser &json_parser_;
  const uart::UartClient &uart_client_;
  const wifi::WifiClient &wifi_client_;
};
}  // namespace uart
