#include "MongoConnection.h"
#include "../config/Config.h"

MongoConnection::MongoConnection()
    : client(
          mongocxx::uri{
              Config::MongoURI()})
{
}

mongocxx::database MongoConnection::GetDatabase()
{
    return client[Config::DatabaseName()];
}