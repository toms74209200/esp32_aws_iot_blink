#include <gtest/gtest.h>

#include "input_setting.h"
#include "json_parser_mock.h"
#include "uart_client_mock.h"
#include "wifi_client_mock.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

TEST(InputSettingRecvWifiSettingTest, Normal)
{
    json::JsonParserMock json_parser_mock;
    EXPECT_CALL(json_parser_mock, Get(_, "ssid"))
        .Times(AtLeast(1))
        .WillRepeatedly(Return("foo"));
    EXPECT_CALL(json_parser_mock, Get(_, "password"))
        .Times(AtLeast(1))
        .WillRepeatedly(Return("bar"));

    uart::UartClientMock uart_client_mock;
    std::vector<std::string> return_data = {"{\"ssid\":\"foo\",\"password\":\"bar\"}"};
    EXPECT_CALL(uart_client_mock, RecvData())
        .Times(AtLeast(1))
        .WillRepeatedly(Return(return_data));

    wifi::WifiClientMock wifi_client_mock;
    EXPECT_CALL(wifi_client_mock, Init("foo", "bar"))
        .Times(AtLeast(1))
        .WillRepeatedly(Return(true));

    uart::InputSetting input_setting = uart::InputSetting(json_parser_mock, uart_client_mock, wifi_client_mock);
    input_setting.RecvWifiSetting();
}