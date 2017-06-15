#pragma once

#include <string>


class Client {
public:
    // Define these as virtual methods for easy compatibility with gmock
    virtual ~ Client () {};
    virtual std::string get (std::string const url);
};
