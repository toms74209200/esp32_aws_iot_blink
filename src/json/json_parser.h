/**
 * @file json_parser.h
 * @brief JSON parser
 */

#pragma once

#include <string>

namespace json {
class JsonParser {
 public:
  virtual std::string Get(std::string target, std::string key) const = 0;
  virtual int32_t GetInt(std::string target, std::string key) const = 0;
};
}  // namespace json