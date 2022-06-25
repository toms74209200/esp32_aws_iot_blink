/**
 * @file aws_iot_settings.h
 * @brief AWS IoT connection settings
 */

#pragma once

#include <string>

namespace aws_iot {
struct AwsIotSettings {
  struct Builder {
    Builder& EndPoint(const std::string& end_point) {
      this->end_point = end_point;
      return *this;
    }
    Builder& CertCa(const std::string& cert_ca) {
      this->cert_ca = cert_ca;
      return *this;
    };
    Builder& CertCrt(const std::string& cert_crt) {
      this->cert_crt = cert_crt;
      return *this;
    }
    Builder& CertPrivate(const std::string& cert_private) {
      this->cert_private = cert_private;
      return *this;
    }
    Builder& Port(const uint32_t port) {
      this->port = port;
      return *this;
    }
    Builder& ThingName(const std::string& thing_name) {
      this->thing_name = thing_name;
      return *this;
    }
    AwsIotSettings Build() {
      return AwsIotSettings(*this);
    }
    std::string end_point;
    std::string cert_ca;
    std::string cert_crt;
    std::string cert_private;
    uint32_t port;
    std::string thing_name;
  };
  const std::string end_point;
  const std::string cert_ca;
  const std::string cert_crt;
  const std::string cert_private;
  const uint32_t port;
  const std::string thing_name;

 private:
  explicit AwsIotSettings(Builder builder)
      : end_point(builder.end_point),
        cert_ca(builder.cert_ca),
        cert_crt(builder.cert_crt),
        cert_private(builder.cert_private),
        port(builder.port),
        thing_name(builder.thing_name){};
};
}  // namespace aws_iot