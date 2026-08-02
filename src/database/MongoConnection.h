#pragma once

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/database.hpp>

class MongoConnection
{
public:
    MongoConnection();

    mongocxx::database GetDatabase();

private:
    mongocxx::instance mongoInstance;

    mongocxx::client client;
};