#include "CharacterRepository.h"

#include <cstdint>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <bsoncxx/json.hpp>

using bsoncxx::builder::stream::array;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;

CharacterRepository::CharacterRepository(
    MongoConnection &database)
    : mongo(database)
{
}

std::string CharacterRepository::GetCharacterById(
    const std::string &id)
{
       auto collection =
           mongo.GetDatabase()["characters"];

       auto result = collection.find_one(
           document{}
           << "CharacterID"
           << id
           << finalize);

       if (!result)
       {
              return "{}";
       }

       return bsoncxx::to_json(
           result->view());
}

void CharacterRepository::CreateCharacter(
    const Cultivator &character)
{
       auto collection =
           mongo.GetDatabase()["characters"];

       // ============================================================
       // IDENTITY ARRAYS
       // ============================================================

       auto titles = array{};

       for (const auto &title :
            character.Identity.Titles)
       {
              titles << title;
       }

       auto achievements = array{};

       for (const auto &achievement :
            character.Identity.Achievements)
       {
              achievements << achievement;
       }

       // ============================================================
       // RELATION ARRAYS
       // ============================================================

       auto discipleNames = array{};

       for (const auto &name :
            character.Relations.DiscipleNames)
       {
              discipleNames << name;
       }

       auto friends = array{};

       for (const auto &name :
            character.Relations.Friends)
       {
              friends << name;
       }

       auto familyMembers = array{};

       for (const auto &name :
            character.Relations.FamilyMembers)
       {
              familyMembers << name;
       }

       auto rivals = array{};

       for (const auto &name :
            character.Relations.Rivals)
       {
              rivals << name;
       }

       auto enemies = array{};

       for (const auto &name :
            character.Relations.Enemies)
       {
              enemies << name;
       }

       auto lovers = array{};

       for (const auto &name :
            character.Relations.Lovers)
       {
              lovers << name;
       }

       // ============================================================
       // IDENTITY
       // ============================================================

       auto identity =
           document{}

           << "Name"
           << character.Identity.Name

           << "PrimaryTitle"
           << character.Identity.PrimaryTitle

           << "CountryOfOrigin"
           << character.Identity.CountryOfOrigin

           << "Age"
           << static_cast<std::int64_t>(
                  character.Identity.Age)

           << "LifeSpan"
           << static_cast<std::int64_t>(
                  character.Identity.LifeSpan)

           << "Titles"
           << titles.view()

           << "Achievements"
           << achievements.view()

           // Appearance
           << "Gender"
           << static_cast<std::int64_t>(
                  character.Identity.Gender)

           << "Race"
           << static_cast<std::int64_t>(
                  character.Identity.Race)

           << "HairColor"
           << static_cast<std::int64_t>(
                  character.Identity.HairColor)

           << "EyeColor"
           << static_cast<std::int64_t>(
                  character.Identity.EyeColor)

           << "BodyType"
           << static_cast<std::int64_t>(
                  character.Identity.BodyType)

           // Traits
           << "NobilityStatus"
           << static_cast<std::int64_t>(
                  character.Identity.NobilityStatus)

           << "Alignment"
           << static_cast<std::int64_t>(
                  character.Identity.Alignment)

           << "Quirks"
           << static_cast<std::int64_t>(
                  character.Identity.Quirks)

           << "JianghuReputation"
           << static_cast<std::int64_t>(
                  character.Identity.JianghuReputation)

           << "SectReputation"
           << static_cast<std::int64_t>(
                  character.Identity.SectReputation)

           << "DemonicReputation"
           << static_cast<std::int64_t>(
                  character.Identity.DemonicReputation)

           << "UnorthodoxReputation"
           << static_cast<std::int64_t>(
                  character.Identity.UnorthodoxReputation)

           << finalize;

       // ============================================================
       // PERSONALITY
       // ============================================================

       auto personality =
           document{}

           << "Aggression"
           << static_cast<std::int64_t>(
                  character.Personality.Aggression)

           << "Honor"
           << static_cast<std::int64_t>(
                  character.Personality.Honor)

           << "Mercy"
           << static_cast<std::int64_t>(
                  character.Personality.Mercy)

           << "Greed"
           << static_cast<std::int64_t>(
                  character.Personality.Greed)

           << "Ambition"
           << static_cast<std::int64_t>(
                  character.Personality.Ambition)

           << "Loyalty"
           << static_cast<std::int64_t>(
                  character.Personality.Loyalty)

           << "Courage"
           << static_cast<std::int64_t>(
                  character.Personality.Courage)

           << "Ruthlessness"
           << static_cast<std::int64_t>(
                  character.Personality.Ruthlessness)

           << "Patience"
           << static_cast<std::int64_t>(
                  character.Personality.Patience)

           << "Fear"
           << static_cast<std::int64_t>(
                  character.Personality.Fear)

           << "Stress"
           << static_cast<std::int64_t>(
                  character.Personality.Stress)

           << "Fatigue"
           << static_cast<std::int64_t>(
                  character.Personality.Fatigue)

           << "Confidence"
           << static_cast<std::int64_t>(
                  character.Personality.Confidence)

           << "Bloodlust"
           << static_cast<std::int64_t>(
                  character.Personality.Bloodlust)

           << "Suspicion"
           << static_cast<std::int64_t>(
                  character.Personality.Suspicion)

           << "Anger"
           << static_cast<std::int64_t>(
                  character.Personality.Anger)

           << "Happiness"
           << static_cast<std::int64_t>(
                  character.Personality.Happiness)

           << "Sadness"
           << static_cast<std::int64_t>(
                  character.Personality.Sadness)

           << "Curiosity"
           << static_cast<std::int64_t>(
                  character.Personality.Curiosity)

           << finalize;

       // ============================================================
       // STATS
       // ============================================================

       auto stats =
           document{}

           << "Level"
           << static_cast<std::int64_t>(
                  character.Stats.Level)

           << "Health"
           << static_cast<std::int64_t>(
                  character.Stats.Health)

           << "Stamina"
           << static_cast<std::int64_t>(
                  character.Stats.Stamina)

           << "Defense"
           << static_cast<std::int64_t>(
                  character.Stats.Defense)

           << "Accuracy"
           << static_cast<std::int64_t>(
                  character.Stats.Accuracy)

           << "Evasion"
           << static_cast<std::int64_t>(
                  character.Stats.Evasion)

           << "CriticalChance"
           << static_cast<std::int64_t>(
                  character.Stats.CriticalChance)

           << "CriticalDamage"
           << static_cast<std::int64_t>(
                  character.Stats.CriticalDamage)

           << "SpiritualResistance"
           << static_cast<std::int64_t>(
                  character.Stats.SpiritualResistance)

           << "PhysicalStrength"
           << static_cast<std::int64_t>(
                  character.Stats.PhysicalStrength)

           << "Speed"
           << static_cast<std::int64_t>(
                  character.Stats.Speed)

           << "QiCapacity"
           << static_cast<std::int64_t>(
                  character.Stats.QiCapacity)

           << "SpiritualSense"
           << static_cast<std::int64_t>(
                  character.Stats.SpiritualSense)

           << "SoulStrength"
           << static_cast<std::int64_t>(
                  character.Stats.SoulStrength)

           << "Comprehension"
           << static_cast<std::int64_t>(
                  character.Stats.Comprehension)

           << "DaoComprehension"
           << static_cast<std::int64_t>(
                  character.Stats.DaoComprehension)

           << "MentalFortitude"
           << static_cast<std::int64_t>(
                  character.Stats.MentalFortitude)

           << "Charisma"
           << static_cast<std::int64_t>(
                  character.Stats.Charisma)

           << "Luck"
           << static_cast<std::int64_t>(
                  character.Stats.Luck)

           << "KarmaicBalance"
           << static_cast<std::int64_t>(
                  character.Stats.KarmaicBalance)

           << "HeavenlyTribulationChance"
           << static_cast<std::int64_t>(
                  character.Stats.HeavenlyTribulationChance)

           << "HeavenlyFavor"
           << static_cast<std::int64_t>(
                  character.Stats.HeavenlyFavor)

           << "KillCount"
           << static_cast<std::int64_t>(
                  character.Stats.KillCount)

           << "StatusEffects"
           << static_cast<std::int64_t>(
                  character.Stats.StatusEffects)

           << finalize;

       // ============================================================
       // INVENTORY
       // ============================================================

       auto inventory =
           document{}

           // Primary weapon
           << "HasWeapon"
           << character.Inventory.bHasWeapon

           << "WeaponType"
           << static_cast<std::int64_t>(
                  character.Inventory.WeaponType)

           << "WeaponGrade"
           << static_cast<std::int64_t>(
                  character.Inventory.WeaponGrade)

           << "WeaponDurability"
           << static_cast<std::int64_t>(
                  character.Inventory.WeaponDurability)

           << "WeaponDamage"
           << static_cast<std::int64_t>(
                  character.Inventory.WeaponDamage)

           << "WeaponOwnerBound"
           << character.Inventory.OwnerBound

           // Secondary weapon
           << "HasSecondaryWeapon"
           << character.Inventory.bHasSecondaryWeapon

           << "SecondaryWeaponType"
           << static_cast<std::int64_t>(
                  character.Inventory.SeondaryWeaponType)

           << "SecondaryWeaponGrade"
           << static_cast<std::int64_t>(
                  character.Inventory.SecondaryWeaponGrade)

           << "SecondaryWeaponDurability"
           << static_cast<std::int64_t>(
                  character.Inventory.SecondaryWeaponDurability)

           << "SecondaryWeaponDamage"
           << static_cast<std::int64_t>(
                  character.Inventory.SecondaryWeaponDamage)

           << "SecondaryWeaponOwnerBound"
           << character.Inventory.SecondaryWeaponOwnerBound

           // Armour
           << "HasArmour"
           << character.Inventory.bHasArmour

           << "ArmourType"
           << static_cast<std::int64_t>(
                  character.Inventory.ArmourType)

           << "ArmourGrade"
           << static_cast<std::int64_t>(
                  character.Inventory.ArmourGrade)

           << "ArmourDurability"
           << static_cast<std::int64_t>(
                  character.Inventory.ArmourDurability)

           << "ArmourDefense"
           << static_cast<std::int64_t>(
                  character.Inventory.ArmourDefense)

           << "ArmourSpiritualResistance"
           << static_cast<std::int64_t>(
                  character.Inventory.ArmourSpiritualResistance)

           << "ArmourOwnerBound"
           << character.Inventory.ArmourOwnerBound

           // Accessory
           << "HasAccessory"
           << character.Inventory.bHasAccessory

           << "AccessoryType"
           << static_cast<std::int64_t>(
                  character.Inventory.AccessoryType)

           << "AccessoryGrade"
           << static_cast<std::int64_t>(
                  character.Inventory.AccessoryGrade)

           // Storage ring
           << "StorageRingType"
           << static_cast<std::int64_t>(
                  character.Inventory.StorageRingType)

           << "StorageRingCapacity"
           << static_cast<std::int64_t>(
                  character.Inventory.StorageRingCapacity)

           << "StorageRingType"
           << static_cast<std::int64_t>(
                  character.Inventory.StorageRingType)

           // Treasure
           << "HasTreasure"
           << character.Inventory.bHasTreasure

           << "TreasureType"
           << static_cast<std::int64_t>(
                  character.Inventory.TreasureType)

           << "TreasureGrade"
           << static_cast<std::int64_t>(
                  character.Inventory.TreasureGrade)

           // Spirit stones
           << "SpiritStoneCount"
           << static_cast<std::int64_t>(
                  character.Inventory.spiritStoneCount)

           << "SpiritStoneType"
           << static_cast<std::int64_t>(
                  character.Inventory.SpiritStoneType)

           << finalize;

       // ============================================================
       // CULTIVATION
       // ============================================================

       auto cultivation =
           document{}

           << "MartialPath"
           << static_cast<std::int64_t>(
                  character.Cultivation.MartialPath)

           << "SwordsmanStyle"
           << static_cast<std::int64_t>(
                  character.Cultivation.SwordsmanStyle)

           << "WeaponProficiency"
           << static_cast<std::int64_t>(
                  character.Cultivation.WeaponProficiency)

           << "IsOrthodoxCultivator"
           << character.Cultivation.bIsOrthodoxCultivator

           << "IsDemonicCultivator"
           << character.Cultivation.bIsDemonicCultivator

           << "BreakthroughProgress"
           << static_cast<std::int64_t>(
                  character.Cultivation.BreakthroughProgress)

           << "CultivationExperience"
           << static_cast<std::int64_t>(
                  character.Cultivation.CultivationExperience)

           << "FoundationStability"
           << static_cast<std::int64_t>(
                  character.Cultivation.FoundationStability)

           << "CultivationSpeed"
           << static_cast<std::int64_t>(
                  character.Cultivation.CultivationSpeed)

           << "HasFamiliar"
           << character.Cultivation.bHasFamiliar

           << "SpiritRoot"
           << static_cast<std::int64_t>(
                  character.Cultivation.SpiritRoot)

           << "BloodlineType"
           << static_cast<std::int64_t>(
                  character.Cultivation.BloodlineType)

           << "BloodlinePurity"
           << static_cast<std::int64_t>(
                  character.Cultivation.BloodlinePurity)

           << "BloodlineAwakening"
           << static_cast<std::int64_t>(
                  character.Cultivation.BloodlineAwakening)

           << "PhysiqueType"
           << static_cast<std::int64_t>(
                  character.Cultivation.PhysiqueType)

           << "SwordDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.SwordDao)

           << "BladeDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.BladeDao)

           << "FireDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.FireDao)

           << "WaterDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.WaterDao)

           << "LightningDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.LightningDao)

           << "SpaceDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.SpaceDao)

           << "TimeDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.TimeDao)

           << "LifeDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.LifeDao)

           << "DeathDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.DeathDao)

           << "ChaosDao"
           << static_cast<std::int64_t>(
                  character.Cultivation.ChaosDao)

           << finalize;

       // ============================================================
       // TECHNIQUES
       // ============================================================

       auto techniques =
           document{}

           << "HasCultivationTechnique"
           << character.Techniques.bHasCultivationTechnique

           << "MainCultivationTechnique"
           << character.Techniques.MainCultivationTechnique

           << "MainCultivationTechniqueLevel"
           << static_cast<std::int64_t>(
                  character.Techniques.MainCultivationTechniqueLevel)

           << "HasSecondaryCultivationTechnique"
           << character.Techniques.bHasSecondaryCultivationTechnique

           << "SecondaryCultivationTechnique"
           << character.Techniques.SecondaryCultivationTechnique

           << "SecondaryCultivationTechniqueLevel"
           << static_cast<std::int64_t>(
                  character.Techniques.SecondaryCultivationTechniqueLevel)

           << "BodyRefinementTechnique"
           << character.Techniques.BodyRefinementTechnique

           << "BodyRefinementTechniqueLevel"
           << static_cast<std::int64_t>(
                  character.Techniques.BodyRefinementTechniqueLevel)

           << "SoulCultivationTechnique"
           << character.Techniques.SoulCultivationTechnique

           << "SoulCultivationTechniqueLevel"
           << static_cast<std::int64_t>(
                  character.Techniques.SoulCultivationTechniqueLevel)

           << "MovementTechnique"
           << character.Techniques.MovementTechnique

           << "MovementTechniqueLevel"
           << static_cast<std::int64_t>(
                  character.Techniques.MovementTechniqueLevel)

           << "SecretTechnique"
           << character.Techniques.SecretTechnique

           << "SecretTechniqueLevel"
           << static_cast<std::int64_t>(
                  character.Techniques.SecretTechniqueLevel)

           << "ForbiddenTechnique"
           << character.Techniques.ForbiddenTechnique

           << "ForbiddenTechniqueLevel"
           << static_cast<std::int64_t>(
                  character.Techniques.ForbiddenTechniqueLevel)

           << finalize;

       // ============================================================
       // BODY CONDITION
       // ============================================================

       auto bodyCondition =
           document{}

           << "MeridianQuality"
           << static_cast<std::int64_t>(
                  character.BodyCondition.MeridianQuality)

           << "MeridianDamage"
           << static_cast<std::int64_t>(
                  character.BodyCondition.MeridianDamage)

           << "HasBrokenMeridians"
           << character.BodyCondition.bHasBrokenMeridians

           << "BodyRefinementStage"
           << static_cast<std::int64_t>(
                  character.BodyCondition.BodyRefinementStage)

           << finalize;

       // ============================================================
       // RELATIONS
       // ============================================================

       auto relations =
           document{}

           << "IsSectMember"
           << character.Relations.bIsSectMember

           << "SectRank"
           << static_cast<std::int64_t>(
                  character.Relations.SectRank)

           << "OriginPath"
           << static_cast<std::int64_t>(
                  character.Relations.OriginPath)

           << "MasterName"
           << character.Relations.MasterName

           << "DiscipleNames"
           << discipleNames.view()

           << "Friends"
           << friends.view()

           << "FamilyMembers"
           << familyMembers.view()

           << "Rivals"
           << rivals.view()

           << "Enemies"
           << enemies.view()

           << "Lovers"
           << lovers.view()

           << finalize;

       // ============================================================
       // COMPLETE CHARACTER DOCUMENT
       // ============================================================

       auto doc =
           document{}

           << "CharacterID"
           << character.CharacterID

           << "Identity"
           << identity.view()

           << "Personality"
           << personality.view()

           << "Stats"
           << stats.view()

           << "Inventory"
           << inventory.view()

           << "Cultivation"
           << cultivation.view()

           << "Techniques"
           << techniques.view()

           << "BodyCondition"
           << bodyCondition.view()

           << "Relations"
           << relations.view()

           << finalize;

       // ============================================================
       // INSERT
       // ============================================================

       collection.insert_one(
           doc.view());
}