#pragma once

#include "character_build/CharacterBodyConditionBuild.hpp"
#include "character_build/CharacterStatsBuild.hpp"
#include "character_build/CharacterPersonalityBuild.hpp"
#include "character_build/CharacterCultivationBuild.hpp"
#include "character_build/CharacterIdentityBuild.hpp"
#include "character_build/CharacterInventoryBuild.hpp"
#include "character_build/CharacterRelationsBuild.hpp"
#include "character_build/CharacterTechniquesBuild.hpp"

class Cultivator
{

public:
    std::string CharacterID;
    CharacterIdentityBuild Identity;
    CharacterPersonalityBuild Personality;
    CharacterStatsBuild Stats;
    CharacterRelationsBuild Relations;
    CharacterInventoryBuild Inventory;
    CharacterCultivationBuild Cultivation;
    CharacterTechniquesBuild Techniques;
    CharacterBodyConditionBuild BodyCondition;

    Cultivator() = default;

    void PrintCharacter();
};
