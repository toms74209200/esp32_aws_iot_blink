/**
 * @file input_setting.h
 * @brief input settings from UART
 */

#pragma once

#include <string>

#include "../aws_iot/aws_iot_settings.h"
#include "../json/json_parser.h"
#include "../wifi/wifi_client.h"
#include "uart_client.h"

namespace uart {
struct Constants {
  static const std::string kSsidKey;
  static const std::string kPasswordKey;
  static const std::string kEndPointKey;
  static const std::string kCertCaKey;
  static const std::string kCertCrtKey;
  static const std::string kCertPrivateKey;
  static const std::string kPortKey;
  static const std::string kThingNameKey;
};
class InputSetting {
 public:
  InputSetting(const json::JsonParser &json_parser,
               const uart::UartClient &uart_client,
               const wifi::WifiClient &wifi_client)
      : json_parser_(json_parser),
        uart_client_(uart_client),
        wifi_client_(wifi_client){};
  void RecvWifiSetting() const noexcept;
  aws_iot::AwsIotSettings RecvAwsSetting() const noexcept;

 private:
  const json::JsonParser &json_parser_;
  const uart::UartClient &uart_client_;
  const wifi::WifiClient &wifi_client_;
};
}  // namespace uart
