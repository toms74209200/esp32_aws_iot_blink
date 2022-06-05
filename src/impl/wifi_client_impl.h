/**
 * @file wifi_client_impl.h
 * @brief WiFi client implementation
 */

#pragma once

#include <Arduino.h>
#include <WiFi.h>

#include "../wifi/wifi_client.h"

namespace wifi
{
  class WifiClientImpl : public WifiClient
  {
    bool Init(std::string ssid, std::string password) const noexcept override;
  };
}