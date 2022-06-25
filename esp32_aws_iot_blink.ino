#define ARDUINO_STL

// #include "src/standard/standard.h"
#include "src/impl/aws_iot_client_impl.h"
#include "src/impl/json_parser_impl.h"
#include "src/impl/uart_client_impl.h"
#include "src/impl/wifi_client_impl.h"
#include "src/uart/input_setting.h"

constexpr int32_t kUartBaudrate = 9600;

aws_iot::AwsIotClientImpl aws_iot_client;

const uart::UartClientImpl uart_client(kUartBaudrate);
const json::JsonParserImpl json_parser;
const wifi::WifiClientImpl wifi_client;
const uart::InputSetting input_setting(json_parser, uart_client, wifi_client);

std::string thing_name;

void setup() {
  while (!uart_client.HasReceived()) {
    delay(100);
  }
  input_setting.RecvWifiSetting();
  while (!uart_client.HasReceived()) {
    delay(100);
  }
  aws_iot::AwsIotSettings aws_iot_settings = input_setting.RecvAwsSetting();
  thing_name = aws_iot_settings.thing_name;
  aws_iot_client.Init(aws_iot_settings);
  aws_iot_client.Subscribe("$aws/things/" + thing_name +
                           "/shadow/get/accepted");
}

void loop() {
  aws_iot_client.Publish("$aws/things/" + thing_name + "/shadow/get/accepted",
                         "test");
  delay(10000);
}