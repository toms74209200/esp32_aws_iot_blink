FROM debian:bullseye AS clang-build

RUN apt-get update && apt-get install -y \
    git \
    make \
    cmake \
    curl \
    clang \
    clang-format \
    clang-tidy \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

FROM clang-build AS arduino-dev

# install arduino-cli
RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=/usr/local/bin sh -s 0.21.1

COPY arduino-cli.yaml /root/.arduino15/arduino-cli.yaml

RUN arduino-cli core update-index

# install esp32
RUN arduino-cli core install esp32:esp32

# install ArduinoSTL
RUN arduino-cli lib install ArduinoSTL --config-file /root/.arduino15/arduino-cli.yaml

# install AWS Pub/Sub libraries
RUN arduino-cli lib install MQTT --config-file /root/.arduino15/arduino-cli.yaml \
    && arduino-cli lib install ArduinoJson --config-file /root/.arduino15/arduino-cli.yaml

FROM arduino-dev AS google-test

# install GoogleTest
RUN git clone https://github.com/google/googletest.git -b release-1.11.0 \
    && cd googletest \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && make install