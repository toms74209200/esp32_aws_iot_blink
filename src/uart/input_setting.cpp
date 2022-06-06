/**
 * @file input_setting.cpp
 * @brief input settings from UART
 */

#include "input_setting.h"

const std::string uart::Constants::kSsidKey = "ssid";
const std::string uart::Constants::kPasswordKey = "password";

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