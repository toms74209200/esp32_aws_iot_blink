/**
 * @file input_setting.cpp
 * @brief input settings from UART
 */

#include "input_setting.h"

const std::string uart::Constants::kSsidKey = "ssid";
const std::string uart::Constants::kPasswordKey = "password";
const std::string uart::Constants::kEndPointKey = "endpoint";
const std::string uart::Constants::kCertKey = "cert";
const std::string uart::Constants::kAwsKeyKey = "key";
const std::string uart::Constants::kSecretKey = "secret";
const std::string uart::Constants::kDeviceKey = "device";

void uart::InputSetting::RecvWifiSetting() const noexcept {
  std::vector<std::string> recv_data = uart_client_.RecvData();
  if (recv_data.empty()) {
    return;
  }
  std::string return_string = recv_data.at(0);

  std::string ssid = json_parser_.Get(return_string, Constants::kSsidKey);
  std::string password =
      json_parser_.Get(return_string, Constants::kPasswordKey);

  wifi_client_.Init(ssid, password);
}

void uart::InputSetting::RecvAwsSetting() const noexcept {
  std::vector<std::string> recv_data = uart_client_.RecvData();
  if (recv_data.empty()) {
    return;
  }
  std::string return_string = recv_data.at(0);

  std::string end_point =
      json_parser_.Get(return_string, Constants::kEndPointKey);
  std::string cert = json_parser_.Get(return_string, Constants::kCertKey);
  std::string aws_key = json_parser_.Get(return_string, Constants::kAwsKeyKey);
  std::string secret = json_parser_.Get(return_string, Constants::kSecretKey);
  std::string device = json_parser_.Get(return_string, Constants::kDeviceKey);

  aws_iot_client_.SetEndPoint(end_point)
      .SetCert(cert)
      .SetAwsKey(aws_key)
      .SetSecret(secret)
      .SetDevice(device)
      .Init();
}