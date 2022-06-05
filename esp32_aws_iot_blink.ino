#define ARDUINO_STL

// #include "src/standard/standard.h"
#include "src/impl/json_parser_impl.h"
#include "src/impl/uart_client_impl.h"
#include "src/impl/wifi_client_impl.h"
#include "src/uart/input_setting.h"

constexpr int32_t kUartBaudrate = 9600;

const uart::UartClientImpl uart_client(kUartBaudrate);
const json::JsonParserImpl json_parser;
const wifi::WifiClientImpl wifi_client;
const uart::InputSetting input_setting(json_parser, uart_client, wifi_client);

void setup() {}

void loop()
{
  input_setting.RecvWifiSetting();
}