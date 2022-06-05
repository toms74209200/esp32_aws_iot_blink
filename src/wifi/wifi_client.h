/**
 * @file wifi_client.h
 * @brief WiFi client
 */

#pragma once

#include <string>

namespace wifi
{
  class WifiClient
  {
  public:
    virtual bool Init(std::string ssid, std::string password) const = 0;
  };
}