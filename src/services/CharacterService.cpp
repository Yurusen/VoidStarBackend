#include "CharacterService.h"

CharacterService::CharacterService(
    CharacterRepository &repository)

    : characterRepository(repository)

{
}

void CharacterService::CreateCharacter(
    int playerId,
    const std::string &name)

{

    Character character;

    character.SetID(
        std::to_string(playerId));

    character.Identity.Name =
        name;

    characterRepository.CreateCharacter(
        character);
}