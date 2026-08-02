#pragma once

#include "../models/Character.h"

#include "../database/MongoConnection.h"

class CharacterRepository
{

public:
    CharacterRepository(
        MongoConnection &database);

    void CreateCharacter(
        const Character &character);

    std::string GetCharacterById(
        const std::string &id);

private:
    MongoConnection &mongo;
};