#include "CharacterService.h"

CharacterService::CharacterService(
    CharacterRepository &repository)

    : characterRepository(repository)

{
}

void CharacterService::CreateCharacter(
    const Cultivator &character)
{
    characterRepository.CreateCharacter(
        character);
}