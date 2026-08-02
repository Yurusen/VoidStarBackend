#include "Character.h"

Character::Character()
{

    CharacterID = "";

    Stats.Level = 1;

    Stats.Health = 100;

    Personality.Honor = 50;

    Personality.Courage = 50;
}

std::string Character::GetID() const
{

    return CharacterID;
}

void Character::SetID(
    const std::string &id)
{

    CharacterID = id;
}