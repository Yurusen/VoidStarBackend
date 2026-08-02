#include "Config.h"

std::string Config::MongoURI()
{
    return "mongodb://localhost:27017";
}

std::string Config::DatabaseName()
{
    return "VoidStarDatabase";
}