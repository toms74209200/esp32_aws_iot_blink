/**
 * @file wifi_client_impl.cpp
 * @brief WiFi client implementation
 */

#include "wifi_client_impl.h"

bool wifi::WifiClientImpl::Init(std::string ssid, std::string password) const noexcept
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());

  Serial.print("WiFi connecting");
  for (int i = 0; i < 600; i++)
  {
    Serial.print(".");
    if (WiFi.isConnected())
    {
      Serial.println("");
      return true;
    }
    delay(100);
  }
  Serial.println("");
  return false;
}