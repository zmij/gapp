gapp
====

CPP Interface for Google Analytics Measurement Protocol

Installation
============

Clone the repository or download sources tarball, then cd to the root gapp directory.

```bash
mkdir -p build/release
cd build/release
cmake ../..
make 
sudo make install
```

gapp library uses [Asio (boost::asio)](https://think-async.com/) library for sending requests. Default is boost asio,
but standalone Asio can be used.

Configuration options:

Option | Meaning
------ | -------
STANDALONE_ASIO (ON/OFF) | use standalone asio instead of boost::asio (which is default) 
BUILD_TESTS (ON/OFF) | build tests for the gapp library
TEST_TRACK_ID (string value) | track id used for testing. You can use it to check if the library is working. 

Usage
=====

```cpp

#include <gapp/gapp.hpp>

::gapp::tracker tracker{ "UA-XXXXXX-X" };

::gapp::event evt{ /* event properties */ };
tracker.track(evt);

```
