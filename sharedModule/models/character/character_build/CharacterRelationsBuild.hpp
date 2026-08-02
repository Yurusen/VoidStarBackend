#include <string>
#include <vector>
#include "../enums/CharacterOrigin.hpp"
#include "../enums/CharacterSectRank.hpp"

class CharacterRelationsBuild
{

public:
    // ============================================================
    // Character Origin
    // ============================================================

    bool bIsSectMember;
    Character::SectRankTypes::SectRank SectRank;
    Character::Origin::Path OriginPath;

    // ============================================================
    // Character Relationships
    // ============================================================

    std::string MasterName;

    std::vector<std::string> DiscipleNames;

    std::vector<std::string> FamilyMembers;

    std::vector<std::string> Friends;

    std::vector<std::string> Rivals;

    std::vector<std::string> Enemies;

    std::vector<std::string> Lovers;
};