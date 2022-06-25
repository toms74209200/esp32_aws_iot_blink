/**
 * @file uart_client.h
 * @brief UART
 */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace uart {
class UartClient {
 public:
  virtual std::vector<std::string> RecvData() const = 0;
  virtual bool SendData(const std::string data) const = 0;
  virtual bool HasReceived() const = 0;
};
}  // namespace uart