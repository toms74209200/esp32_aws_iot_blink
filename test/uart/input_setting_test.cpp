#include <gtest/gtest.h>

#include "aws_iot_client_mock.h"
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

  aws_iot::AwsIotClientMock aws_iot_client_mock;

  uart::InputSetting input_setting =
      uart::InputSetting(aws_iot_client_mock, json_parser_mock,
                         uart_client_mock, wifi_client_mock);
  input_setting.RecvWifiSetting();
}

TEST(InputSettingRecvAwsSettingTest, Normal) {
  json::JsonParserMock json_parser_mock;
  EXPECT_CALL(json_parser_mock, Get(_, "endpoint"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("endpoint"));
  EXPECT_CALL(json_parser_mock, Get(_, "cert"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("cert"));
  EXPECT_CALL(json_parser_mock, Get(_, "key"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("key"));
  EXPECT_CALL(json_parser_mock, Get(_, "secret"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("secret"));
  EXPECT_CALL(json_parser_mock, Get(_, "device"))
      .Times(AtLeast(1))
      .WillRepeatedly(Return("device"));

  uart::UartClientMock uart_client_mock;
  std::vector<std::string> return_data = {
      "{\"endpoint\":\"endpoint\",\"cert\":\"cert\",\"key\":\"key\",\"secret\":"
      "\"secret\",\"device\":\"device\"}"};
  EXPECT_CALL(uart_client_mock, RecvData())
      .Times(AtLeast(1))
      .WillRepeatedly(Return(return_data));

  aws_iot::AwsIotClientMock aws_iot_client_mock;
  EXPECT_CALL(aws_iot_client_mock, Init())
      .Times(AtLeast(1))
      .WillRepeatedly(Return(true));
  EXPECT_CALL(aws_iot_client_mock, SetEndPoint("endpoint"))
      .Times(AtLeast(1))
      .WillRepeatedly(ReturnRef(aws_iot_client_mock));
  EXPECT_CALL(aws_iot_client_mock, SetCert("cert"))
      .Times(AtLeast(1))
      .WillRepeatedly(ReturnRef(aws_iot_client_mock));
  EXPECT_CALL(aws_iot_client_mock, SetAwsKey("key"))
      .Times(AtLeast(1))
      .WillRepeatedly(ReturnRef(aws_iot_client_mock));
  EXPECT_CALL(aws_iot_client_mock, SetSecret("secret"))
      .Times(AtLeast(1))
      .WillRepeatedly(ReturnRef(aws_iot_client_mock));
  EXPECT_CALL(aws_iot_client_mock, SetDevice("device"))
      .Times(AtLeast(1))
      .WillRepeatedly(ReturnRef(aws_iot_client_mock));

  wifi::WifiClientMock wifi_client_mock;

  uart::InputSetting input_setting =
      uart::InputSetting(aws_iot_client_mock, json_parser_mock,
                         uart_client_mock, wifi_client_mock);
  input_setting.RecvAwsSetting();
}