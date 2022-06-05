/**
 * @file uart_client_impl.h
 * @brief UART client implementation
 */

#pragma once

#include <Arduino.h>

#include "../uart/uart_client.h"

namespace uart
{
  class UartClientImpl : public UartClient
  {
  public:
    UartClientImpl(const int32_t baudrate)
    {
      Serial.begin(baudrate);
    };
    std::vector<std::string> RecvData() const noexcept override;
    bool SendData(const std::string data) const noexcept override;
  };
}