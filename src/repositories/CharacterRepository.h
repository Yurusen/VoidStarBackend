#pragma once

#include "../../sharedModule/models/character/Character.hpp"

#include "../database/MongoConnection.h"

class CharacterRepository
{

public:
    CharacterRepository(
        MongoConnection &database);

    void CreateCharacter(
        const Cultivator &character);

    std::string GetCharacterById(
        const std::string &id);

private:
    MongoConnection &mongo;
};