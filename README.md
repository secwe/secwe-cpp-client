# Secwe AI C++ Client
Secwe AI C++ Client is a C++ client for Secwe AI API.
provides a simple interface for sending and receiving data from the Secwe AI Prediction API.

## Introduction
This code is designed to be easy to use and to implementing a malicious web-app detection service for your applications.
### A simple implementation of the Secwe AI Prediction API in C++.

## Usage
```cpp
#include "secwe_client.h"

int main() {
    secwe_client secweb
    (
            "__USERNAME__",
            "__API_KEY__"
    );

    auto result =
            secweb.Get("secwe.com.tr");
    
    /*
     or URI/URL like 
     https://secwe.com.tr, https://secwe.com.tr/robots.txt"
    */
    
    return 0;
}
```
