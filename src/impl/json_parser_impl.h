/**
 * @file json_parser_impl.h
 * @brief JSON parser implementation
 */

#pragma once

#include <ArduinoJson.h>

#include "../json/json_parser.h"

namespace json {
class JsonParserImpl : public JsonParser {
  std::string Get(std::string target, std::string key) const noexcept override;
};
}  // namespace json