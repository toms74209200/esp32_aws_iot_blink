#pragma once

#include <gmock/gmock.h>

#include "wifi_client.h"

namespace wifi
{
  class WifiClientMock : public WifiClient
  {
  public:
    MOCK_CONST_METHOD2(Init, bool(std::string ssid, std::string password));
  };
}