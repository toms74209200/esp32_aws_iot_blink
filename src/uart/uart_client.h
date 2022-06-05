/**
 * @file uart_client.h
 * @brief UART
 */

#pragma once

#include <cstdint>
#include <vector>
#include <string>

namespace uart
{
  class UartClient
  {
  public:
    virtual std::vector<std::string> RecvData() const = 0;
    virtual bool SendData(const std::string data) const = 0;
  };
} // namespace uart