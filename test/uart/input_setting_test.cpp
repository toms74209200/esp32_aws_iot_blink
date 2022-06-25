#include <gtest/gtest.h>

#include "input_setting.h"
#include "json_parser_mock.h"
#include "uart_client_mock.h"
#include "wifi_client_mock.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::ReturnRef;

TEST(InputSettingRecvWifiSettingTest, Normal) {
  json::JsonParserMock json_parser_mock;
  EXPECT_CALL(json_parser_mock, Get(_, "ssid"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("foo"));
  EXPECT_CALL(json_parser_mock, Get(_, "password"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("bar"));

  uart::UartClientMock uart_client_mock;
  std::vector<std::string> return_data = {
      "{\"ssid\":\"foo\",\"password\":\"bar\"}"};
  EXPECT_CALL(uart_client_mock, RecvData())
      .Times(AtLeast(1))
      .WillRepeatedly(Return(return_data));

  wifi::WifiClientMock wifi_client_mock;
  EXPECT_CALL(wifi_client_mock, Init("foo", "bar"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return(true));

  uart::InputSetting input_setting =
      uart::InputSetting(json_parser_mock, uart_client_mock, wifi_client_mock);
  input_setting.RecvWifiSetting();
}

TEST(InputSettingRecvAwsSettingTest, Normal) {
  json::JsonParserMock json_parser_mock;
  EXPECT_CALL(json_parser_mock, Get(_, "endpoint"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("endpoint"));
  EXPECT_CALL(json_parser_mock, Get(_, "cert_ca"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("cert_ca"));
  EXPECT_CALL(json_parser_mock, Get(_, "cert_crt"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("cert_crt"));
  EXPECT_CALL(json_parser_mock, Get(_, "cert_private"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("cert_private"));
  EXPECT_CALL(json_parser_mock, GetInt(_, "port"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return(8883));
  EXPECT_CALL(json_parser_mock, Get(_, "thing_name"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("thing_name"));

  uart::UartClientMock uart_client_mock;
  std::vector<std::string> return_data = {
      "{\"endpoint\":\"endpoint\",\"cert_ca\":\"cert_ca\",\"cert_crt\":\"cert_"
      "crt\",\"cert_private\":"
      "\"cert_private\",\"port\":8883,\"thing_name\":\"thing_name\"}"};
  EXPECT_CALL(uart_client_mock, RecvData())
      .Times(AtLeast(1))
      .WillRepeatedly(Return(return_data));

  wifi::WifiClientMock wifi_client_mock;

  uart::InputSetting input_setting =
      uart::InputSetting(json_parser_mock, uart_client_mock, wifi_client_mock);
  aws_iot::AwsIotSettings actual_result = input_setting.RecvAwsSetting();

  ASSERT_EQ(actual_result.end_point, "endpoint");
  ASSERT_EQ(actual_result.cert_ca, "cert_ca");
  ASSERT_EQ(actual_result.cert_crt, "cert_crt");
  ASSERT_EQ(actual_result.cert_private, "cert_private");
  ASSERT_EQ(actual_result.port, 8883);
  ASSERT_EQ(actual_result.thing_name, "thing_name");
}