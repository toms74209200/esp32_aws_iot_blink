#pragma once

#include <gmock/gmock.h>

#include "json_parser.h"

namespace json {
class JsonParserMock : public JsonParser {
 public:
  MOCK_CONST_METHOD2(Get, std::string(std::string, std::string));
  MOCK_CONST_METHOD2(GetInt, int32_t(std::string, std::string));
};
}  // namespace json