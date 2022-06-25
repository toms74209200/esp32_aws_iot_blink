/**
 * @file input_setting.cpp
 * @brief input settings from UART
 */

#include "input_setting.h"

const std::string uart::Constants::kSsidKey = "ssid";
const std::string uart::Constants::kPasswordKey = "password";
const std::string uart::Constants::kEndPointKey = "endpoint";
const std::string uart::Constants::kCertCaKey = "cert_ca";
const std::string uart::Constants::kCertCrtKey = "cert_crt";
const std::string uart::Constants::kCertPrivateKey = "cert_private";
const std::string uart::Constants::kPortKey = "port";
const std::string uart::Constants::kThingNameKey = "thing_name";

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

aws_iot::AwsIotSettings uart::InputSetting::RecvAwsSetting() const noexcept {
  std::vector<std::string> recv_data = uart_client_.RecvData();

  if (recv_data.empty()) {
    return aws_iot::AwsIotSettings::Builder()
        .EndPoint("")
        .CertCa("")
        .CertCrt("")
        .CertPrivate("")
        .Port(0)
        .ThingName("")
        .Build();
  }
  std::string return_string = recv_data.at(0);

  std::string end_point =
      json_parser_.Get(return_string, Constants::kEndPointKey);
  std::string cert_ca = json_parser_.Get(return_string, Constants::kCertCaKey);
  std::string cert_crt =
      json_parser_.Get(return_string, Constants::kCertCrtKey);
  std::string cert_private =
      json_parser_.Get(return_string, Constants::kCertPrivateKey);
  uint32_t port = json_parser_.GetInt(return_string, Constants::kPortKey);
  std::string thing_name =
      json_parser_.Get(return_string, Constants::kThingNameKey);

  return aws_iot::AwsIotSettings::Builder()
      .EndPoint(end_point)
      .CertCa(cert_ca)
      .CertCrt(cert_crt)
      .CertPrivate(cert_private)
      .Port(port)
      .ThingName(thing_name)
      .Build();
}