/**
 * @file uart_client_impl.cpp
 * @brief UART client implementation
 */

#include "uart_client_impl.h"

std::vector<std::string> uart::UartClientImpl::RecvData() const noexcept {
  if (Serial.available() <= 0) {
    return {};
  }
  std::string data = Serial.readString().c_str();
  Serial.print("recieved: ");
  Serial.println(data.c_str());
  return {data};
};

bool uart::UartClientImpl::SendData(const std::string data) const noexcept {
  Serial.print(data.c_str());
  return true;
};