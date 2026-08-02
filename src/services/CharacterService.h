#pragma once

#include "../../sharedModule/models/character/Character.hpp"

#include "../repositories/CharacterRepository.h"

class CharacterService
{

public:
    CharacterService(
        CharacterRepository &repository);

    void CreateCharacter(
        const Cultivator &character);

    std::string GetCharacterById(
        const std::string &id)
    {
        return characterRepository.GetCharacterById(id);
    };

private:
    CharacterRepository &characterRepository;
};