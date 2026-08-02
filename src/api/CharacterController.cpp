#include "CharacterController.h"

CharacterController::CharacterController(
    CharacterService &service)

    : service(service)

{
}

void CharacterController::CreateCharacter(
    int playerId,
    const std::string &name)

{

    service.CreateCharacter(
        playerId,
        name);
}