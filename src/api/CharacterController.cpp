#include "CharacterController.h"
#include "../../sharedModule/models/character/Character.hpp"

CharacterController::CharacterController(
    CharacterService &service)

    : service(service)

{
}

void CharacterController::CreateCharacter(
    const Cultivator &character)

{

    service.CreateCharacter(
        character);
}