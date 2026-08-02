#pragma once

#include <string>

class Config
{

public:
    static std::string MongoURI();

    static std::string DatabaseName();
};