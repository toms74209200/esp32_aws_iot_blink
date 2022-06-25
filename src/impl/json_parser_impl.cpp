/**
 * @file json_parser_imppl.cpp
 * @brief JSON parser implementation
 */

#include "json_parser_impl.h"

std::string json::JsonParserImpl::Get(std::string target,
                                      std::string key) const noexcept {
  StaticJsonDocument<5000> json_document;
  deserializeJson(json_document, target);
  if (!json_document.containsKey(key)) {
    return "";
  }
  return json_document[key];
}

int32_t json::JsonParserImpl::GetInt(std::string target,
                                     std::string key) const noexcept {
  StaticJsonDocument<5000> json_document;
  deserializeJson(json_document, target);
  if (!json_document.containsKey(key)) {
    return 0;
  }
  return json_document[key];
}