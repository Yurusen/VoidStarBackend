#include <string>
#include <vector>
#include "../enums/CharacterAppearance.hpp"
#include "../enums/CharacterTraits.hpp"

class CharacterIdentityBuild
{

public:
    // ============================================================
    // Titles
    // ============================================================

    std::string PrimaryTitle;
    std::string Name;
    std::string CountryOfOrigin;

    std::vector<std::string> Titles;

    std::vector<std::string> Achievements;

    // ============================================================
    // Character Appearance
    // ============================================================

    int Age;
    long LifeSpan;

    Character::Appearance::Gender Gender;
    Character::Appearance::Race Race;
    Character::Appearance::HairColor HairColor;
    Character::Appearance::EyeColor EyeColor;
    Character::Appearance::BodyType BodyType;

    // ============================================================
    // Character Persona
    // ============================================================

    Character::Traits::NobilityStatus NobilityStatus;
    Character::Traits::Alignment Alignment;
    Character::Traits::Quirks Quirks;

    // ============================================================
    // Faction Reputation
    // ============================================================
    Character::Traits::GeneralMoralityReputation JianghuReputation;
    Character::Traits::GeneralMoralityReputation SectReputation;
    Character::Traits::GeneralMoralityReputation DemonicReputation;
    Character::Traits::GeneralMoralityReputation UnorthodoxReputation;
};