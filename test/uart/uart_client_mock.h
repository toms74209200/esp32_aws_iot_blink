#pragma once

#include <gmock/gmock.h>

#include "uart_client.h"

namespace uart {
class UartClientMock : public UartClient {
 public:
  MOCK_CONST_METHOD0(RecvData, std::vector<std::string>());
  MOCK_CONST_METHOD1(SendData, bool(const std::string data));
};
}  // namespace uart