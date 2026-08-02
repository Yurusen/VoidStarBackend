#pragma once

#include "../services/CharacterService.h"

class CharacterController
{

public:
    CharacterController(
        CharacterService &service);

    void CreateCharacter(
        const Cultivator &character);

private:
    CharacterService &service;
};