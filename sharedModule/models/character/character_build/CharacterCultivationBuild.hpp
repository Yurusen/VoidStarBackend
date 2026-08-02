#include "../enums/CharacterCultivation.hpp"
#include "../enums/CharacterRoots.hpp"
#include "../enums/CharacterBloodline.hpp"
#include "../enums/CharacterPhysique.hpp"
#include "../enums/CharacterSkills.hpp"
// #include "BeastBuild.hpp"
#include <string>
#include <vector>

class CharacterCultivationBuild
{

public:
    // ============================================================
    // Character Skills
    // ============================================================

    Character::SkillClass::MartialPath MartialPath;

    Character::SkillClass::Swordsman::Style SwordsmanStyle;
    Character::SkillClass::Assassin::Style AssassinStyle;
    Character::SkillClass::Monk::Style MonkStyle;
    Character::SkillClass::Spearman::Style SpearmanStyle;
    Character::SkillClass::Archer::Style ArcherStyle;
    Character::SkillClass::Alchemist::Rank AlchemistRank;
    Character::SkillClass::BeastTamer::Rank BeastTamerRank;
    Character::SkillClass::FormationMaster::Rank FormationMasterRank;
    Character::SkillClass::ArtifactRefiner::Rank ArtifactRefinerRank;

    int WeaponProficiency;

    // ============================================================
    // Character Cultivation
    // ============================================================

    bool bIsOrthodoxCultivator;
    Character::Cultivation::OrthodoxCultivationRealm OrthodoxRealm;

    bool bIsDemonicCultivator;
    Character::Cultivation::DemonicCultivationRealm DemonicRealm;

    int BreakthroughProgress;

    int CultivationExperience;

    int FoundationStability;

    int CultivationSpeed;

    bool bHasFamiliar;
    // BeastBuild BeastFamiliar;

    Character::Roots::SpiritRoot SpiritRoot;

    Character::BloodlineType::Bloodline BloodlineType;
    int BloodlinePurity;
    int BloodlineAwakening;

    Character::Physique::BodyType PhysiqueType;

    int SwordDao;
    int BladeDao;
    int FireDao;
    int WaterDao;
    int LightningDao;
    int SpaceDao;
    int TimeDao;
    int LifeDao;
    int DeathDao;
    int ChaosDao;
};