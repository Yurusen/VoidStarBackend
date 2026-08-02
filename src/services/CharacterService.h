#pragma once

#include "../models/Character.h"

#include "../repositories/CharacterRepository.h"

class CharacterService
{

public:
    CharacterService(
        CharacterRepository &repository);

    void CreateCharacter(
        int playerId,
        const std::string &name);

    std::string GetCharacterById(
        const std::string &id)
    {
        return characterRepository.GetCharacterById(id);
    };

private:
    CharacterRepository &characterRepository;
};