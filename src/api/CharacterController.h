#pragma once

#include "../services/CharacterService.h"

class CharacterController
{

public:
    CharacterController(
        CharacterService &service);

    void CreateCharacter(
        int playerId,
        const std::string &name);

private:
    CharacterService &service;
};