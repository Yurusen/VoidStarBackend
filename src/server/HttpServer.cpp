#include "HttpServer.h"

#include <crow.h>
#include <iostream>
#include <string>
#include <vector>

namespace
{
    // ============================================================
    // Helpers
    // ============================================================

    std::vector<std::string> ReadStringArray(
        const crow::json::rvalue &json)
    {
        std::vector<std::string> result;

        if (!json)
        {
            return result;
        }

        for (const auto &item : json)
        {
            result.push_back(item.s());
        }

        return result;
    }

    // ============================================================
    // JSON -> Cultivator
    // ============================================================

    Cultivator CharacterFromJson(
        const crow::json::rvalue &body)
    {
        // IMPORTANT:
        // {} value-initialises the Cultivator and prevents
        // uninitialised primitive values from being used.
        Cultivator character{};

        // ========================================================
        // Character ID
        // ========================================================

        if (body["CharacterID"])
        {
            character.CharacterID =
                body["CharacterID"].s();
        }

        // ========================================================
        // IDENTITY
        // ========================================================

        if (body["Identity"])
        {
            const auto &identity = body["Identity"];

            if (identity["PrimaryTitle"])
            {
                character.Identity.PrimaryTitle =
                    identity["PrimaryTitle"].s();
            }

            if (identity["Name"])
            {
                character.Identity.Name =
                    identity["Name"].s();
            }

            if (identity["CountryOfOrigin"])
            {
                character.Identity.CountryOfOrigin =
                    identity["CountryOfOrigin"].s();
            }

            if (identity["Titles"])
            {
                character.Identity.Titles =
                    ReadStringArray(identity["Titles"]);
            }

            if (identity["Achievements"])
            {
                character.Identity.Achievements =
                    ReadStringArray(identity["Achievements"]);
            }

            if (identity["Age"])
            {
                character.Identity.Age =
                    static_cast<int>(identity["Age"].i());
            }

            if (identity["LifeSpan"])
            {
                character.Identity.LifeSpan =
                    static_cast<long>(identity["LifeSpan"].i());
            }

            if (identity["Gender"])
            {
                character.Identity.Gender =
                    static_cast<
                        Character::Appearance::Gender>(identity["Gender"].i());
            }

            if (identity["Race"])
            {
                character.Identity.Race =
                    static_cast<
                        Character::Appearance::Race>(identity["Race"].i());
            }

            if (identity["HairColor"])
            {
                character.Identity.HairColor =
                    static_cast<
                        Character::Appearance::HairColor>(identity["HairColor"].i());
            }

            if (identity["EyeColor"])
            {
                character.Identity.EyeColor =
                    static_cast<
                        Character::Appearance::EyeColor>(identity["EyeColor"].i());
            }

            if (identity["BodyType"])
            {
                character.Identity.BodyType =
                    static_cast<
                        Character::Appearance::BodyType>(identity["BodyType"].i());
            }

            if (identity["NobilityStatus"])
            {
                character.Identity.NobilityStatus =
                    static_cast<
                        Character::Traits::NobilityStatus>(identity["NobilityStatus"].i());
            }

            if (identity["Alignment"])
            {
                character.Identity.Alignment =
                    static_cast<
                        Character::Traits::Alignment>(identity["Alignment"].i());
            }

            if (identity["Quirks"])
            {
                character.Identity.Quirks =
                    static_cast<
                        Character::Traits::Quirks>(identity["Quirks"].i());
            }

            if (identity["JianghuReputation"])
            {
                character.Identity.JianghuReputation =
                    static_cast<
                        Character::Traits::GeneralMoralityReputation>(identity["JianghuReputation"].i());
            }

            if (identity["SectReputation"])
            {
                character.Identity.SectReputation =
                    static_cast<
                        Character::Traits::GeneralMoralityReputation>(identity["SectReputation"].i());
            }

            if (identity["DemonicReputation"])
            {
                character.Identity.DemonicReputation =
                    static_cast<
                        Character::Traits::GeneralMoralityReputation>(identity["DemonicReputation"].i());
            }

            if (identity["UnorthodoxReputation"])
            {
                character.Identity.UnorthodoxReputation =
                    static_cast<
                        Character::Traits::GeneralMoralityReputation>(identity["UnorthodoxReputation"].i());
            }
        }

        // ========================================================
        // PERSONALITY
        // ========================================================

        if (body["Personality"])
        {
            const auto &personality = body["Personality"];

            if (personality["Aggression"])
                character.Personality.Aggression =
                    static_cast<int>(personality["Aggression"].i());

            if (personality["Honor"])
                character.Personality.Honor =
                    static_cast<int>(personality["Honor"].i());

            if (personality["Mercy"])
                character.Personality.Mercy =
                    static_cast<int>(personality["Mercy"].i());

            if (personality["Greed"])
                character.Personality.Greed =
                    static_cast<int>(personality["Greed"].i());

            if (personality["Ambition"])
                character.Personality.Ambition =
                    static_cast<int>(personality["Ambition"].i());

            if (personality["Loyalty"])
                character.Personality.Loyalty =
                    static_cast<int>(personality["Loyalty"].i());

            if (personality["Courage"])
                character.Personality.Courage =
                    static_cast<int>(personality["Courage"].i());

            if (personality["Ruthlessness"])
                character.Personality.Ruthlessness =
                    static_cast<int>(personality["Ruthlessness"].i());

            if (personality["Patience"])
                character.Personality.Patience =
                    static_cast<int>(personality["Patience"].i());

            if (personality["Fear"])
                character.Personality.Fear =
                    static_cast<int>(personality["Fear"].i());

            if (personality["Stress"])
                character.Personality.Stress =
                    static_cast<int>(personality["Stress"].i());

            if (personality["Fatigue"])
                character.Personality.Fatigue =
                    static_cast<int>(personality["Fatigue"].i());

            if (personality["Confidence"])
                character.Personality.Confidence =
                    static_cast<int>(personality["Confidence"].i());

            if (personality["Bloodlust"])
                character.Personality.Bloodlust =
                    static_cast<int>(personality["Bloodlust"].i());

            if (personality["Suspicion"])
                character.Personality.Suspicion =
                    static_cast<int>(personality["Suspicion"].i());

            if (personality["Anger"])
                character.Personality.Anger =
                    static_cast<int>(personality["Anger"].i());

            if (personality["Happiness"])
                character.Personality.Happiness =
                    static_cast<int>(personality["Happiness"].i());

            if (personality["Sadness"])
                character.Personality.Sadness =
                    static_cast<int>(personality["Sadness"].i());

            if (personality["Curiosity"])
                character.Personality.Curiosity =
                    static_cast<int>(personality["Curiosity"].i());
        }

        // ========================================================
        // STATS
        // ========================================================

        if (body["Stats"])
        {
            const auto &stats = body["Stats"];

            if (stats["Level"])
                character.Stats.Level =
                    static_cast<long>(stats["Level"].i());

            if (stats["Health"])
                character.Stats.Health =
                    static_cast<int>(stats["Health"].i());

            if (stats["Stamina"])
                character.Stats.Stamina =
                    static_cast<int>(stats["Stamina"].i());

            if (stats["Defense"])
                character.Stats.Defense =
                    static_cast<int>(stats["Defense"].i());

            if (stats["Accuracy"])
                character.Stats.Accuracy =
                    static_cast<int>(stats["Accuracy"].i());

            if (stats["Evasion"])
                character.Stats.Evasion =
                    static_cast<int>(stats["Evasion"].i());

            if (stats["CriticalChance"])
                character.Stats.CriticalChance =
                    static_cast<int>(stats["CriticalChance"].i());

            if (stats["CriticalDamage"])
                character.Stats.CriticalDamage =
                    static_cast<int>(stats["CriticalDamage"].i());

            if (stats["SpiritualResistance"])
                character.Stats.SpiritualResistance =
                    static_cast<int>(stats["SpiritualResistance"].i());

            if (stats["PhysicalStrength"])
                character.Stats.PhysicalStrength =
                    static_cast<int>(stats["PhysicalStrength"].i());

            if (stats["Speed"])
                character.Stats.Speed =
                    static_cast<int>(stats["Speed"].i());

            if (stats["QiCapacity"])
                character.Stats.QiCapacity =
                    static_cast<int>(stats["QiCapacity"].i());

            if (stats["SpiritualSense"])
                character.Stats.SpiritualSense =
                    static_cast<int>(stats["SpiritualSense"].i());

            if (stats["SoulStrength"])
                character.Stats.SoulStrength =
                    static_cast<int>(stats["SoulStrength"].i());

            if (stats["Comprehension"])
                character.Stats.Comprehension =
                    static_cast<int>(stats["Comprehension"].i());

            if (stats["DaoComprehension"])
                character.Stats.DaoComprehension =
                    static_cast<int>(stats["DaoComprehension"].i());

            if (stats["MentalFortitude"])
                character.Stats.MentalFortitude =
                    static_cast<int>(stats["MentalFortitude"].i());

            if (stats["Charisma"])
                character.Stats.Charisma =
                    static_cast<int>(stats["Charisma"].i());

            if (stats["Luck"])
                character.Stats.Luck =
                    static_cast<int>(stats["Luck"].i());

            if (stats["KarmaicBalance"])
                character.Stats.KarmaicBalance =
                    static_cast<int>(stats["KarmaicBalance"].i());

            if (stats["HeavenlyTribulationChance"])
                character.Stats.HeavenlyTribulationChance =
                    static_cast<int>(
                        stats["HeavenlyTribulationChance"].i());

            if (stats["HeavenlyFavor"])
                character.Stats.HeavenlyFavor =
                    static_cast<int>(stats["HeavenlyFavor"].i());

            if (stats["KillCount"])
                character.Stats.KillCount =
                    static_cast<long>(stats["KillCount"].i());

            if (stats["StatusEffects"])
            {
                character.Stats.StatusEffects =
                    static_cast<
                        Character::StatusEffect::Status>(stats["StatusEffects"].i());
            }
        }

        // ========================================================
        // INVENTORY
        // ========================================================

        if (body["Inventory"])
        {
            const auto &inventory = body["Inventory"];

            if (inventory["HasWeapon"])
                character.Inventory.bHasWeapon =
                    inventory["HasWeapon"].b();

            if (inventory["WeaponType"])
                character.Inventory.WeaponType =
                    static_cast<
                        Character::Inventory::WeaponType>(inventory["WeaponType"].i());

            if (inventory["WeaponGrade"])
                character.Inventory.WeaponGrade =
                    static_cast<
                        Character::Inventory::ItemGrade>(inventory["WeaponGrade"].i());

            if (inventory["WeaponDurability"])
                character.Inventory.WeaponDurability =
                    static_cast<int>(
                        inventory["WeaponDurability"].i());

            if (inventory["WeaponDamage"])
                character.Inventory.WeaponDamage =
                    static_cast<int>(
                        inventory["WeaponDamage"].i());

            if (inventory["WeaponOwnerBound"])
                character.Inventory.OwnerBound =
                    inventory["WeaponOwnerBound"].b();

            if (inventory["HasSecondaryWeapon"])
                character.Inventory.bHasSecondaryWeapon =
                    inventory["HasSecondaryWeapon"].b();

            if (inventory["SecondaryWeaponType"])
                character.Inventory.SeondaryWeaponType =
                    static_cast<
                        Character::Inventory::WeaponType>(inventory["SecondaryWeaponType"].i());

            if (inventory["SecondaryWeaponGrade"])
                character.Inventory.SecondaryWeaponGrade =
                    static_cast<
                        Character::Inventory::ItemGrade>(inventory["SecondaryWeaponGrade"].i());

            if (inventory["SecondaryWeaponDurability"])
                character.Inventory.SecondaryWeaponDurability =
                    static_cast<int>(
                        inventory["SecondaryWeaponDurability"].i());

            if (inventory["SecondaryWeaponDamage"])
                character.Inventory.SecondaryWeaponDamage =
                    static_cast<int>(
                        inventory["SecondaryWeaponDamage"].i());

            if (inventory["SecondaryWeaponOwnerBound"])
                character.Inventory.SecondaryWeaponOwnerBound =
                    inventory["SecondaryWeaponOwnerBound"].b();

            if (inventory["HasArmour"])
                character.Inventory.bHasArmour =
                    inventory["HasArmour"].b();

            if (inventory["ArmourType"])
                character.Inventory.ArmourType =
                    static_cast<
                        Character::Inventory::ArmourType>(inventory["ArmourType"].i());

            if (inventory["ArmourGrade"])
                character.Inventory.ArmourGrade =
                    static_cast<
                        Character::Inventory::ItemGrade>(inventory["ArmourGrade"].i());

            if (inventory["ArmourDurability"])
                character.Inventory.ArmourDurability =
                    static_cast<int>(
                        inventory["ArmourDurability"].i());

            if (inventory["ArmourDefense"])
                character.Inventory.ArmourDefense =
                    static_cast<int>(
                        inventory["ArmourDefense"].i());

            if (inventory["ArmourSpiritualResistance"])
                character.Inventory.ArmourSpiritualResistance =
                    static_cast<int>(
                        inventory["ArmourSpiritualResistance"].i());

            if (inventory["ArmourOwnerBound"])
                character.Inventory.ArmourOwnerBound =
                    inventory["ArmourOwnerBound"].b();

            if (inventory["HasAccessory"])
                character.Inventory.bHasAccessory =
                    inventory["HasAccessory"].b();

            if (inventory["AccessoryType"])
                character.Inventory.AccessoryType =
                    static_cast<
                        Character::Inventory::AccessoryType>(inventory["AccessoryType"].i());

            if (inventory["AccessoryGrade"])
                character.Inventory.AccessoryGrade =
                    static_cast<
                        Character::Inventory::ItemGrade>(inventory["AccessoryGrade"].i());

            if (inventory["HasStorageRing"])
                character.Inventory.bHasStorageRing =
                    inventory["HasStorageRing"].b();

            if (inventory["StorageRingType"])
                character.Inventory.StorageRingType =
                    static_cast<
                        Character::Inventory::StorageRingType>(inventory["StorageRingType"].i());

            if (inventory["StorageRingCapacity"])
                character.Inventory.StorageRingCapacity =
                    static_cast<int>(
                        inventory["StorageRingCapacity"].i());

            if (inventory["HasTreasure"])
                character.Inventory.bHasTreasure =
                    inventory["HasTreasure"].b();

            if (inventory["TreasureType"])
                character.Inventory.TreasureType =
                    static_cast<
                        Character::Inventory::TreasureType>(inventory["TreasureType"].i());

            if (inventory["TreasureGrade"])
                character.Inventory.TreasureGrade =
                    static_cast<
                        Character::Inventory::ItemGrade>(inventory["TreasureGrade"].i());

            if (inventory["SpiritStoneCount"])
                character.Inventory.spiritStoneCount =
                    static_cast<int>(
                        inventory["SpiritStoneCount"].i());

            if (inventory["SpiritStoneType"])
                character.Inventory.SpiritStoneType =
                    static_cast<
                        Character::Inventory::SpiritStoneType>(inventory["SpiritStoneType"].i());
        }

        // ========================================================
        // CULTIVATION
        // ========================================================

        if (body["Cultivation"])
        {
            const auto &cultivation = body["Cultivation"];

            if (cultivation["MartialPath"])
                character.Cultivation.MartialPath =
                    static_cast<
                        Character::SkillClass::MartialPath>(cultivation["MartialPath"].i());

            if (cultivation["SwordsmanStyle"])
                character.Cultivation.SwordsmanStyle =
                    static_cast<
                        Character::SkillClass::Swordsman::Style>(cultivation["SwordsmanStyle"].i());

            if (cultivation["AssassinStyle"])
                character.Cultivation.AssassinStyle =
                    static_cast<
                        Character::SkillClass::Assassin::Style>(cultivation["AssassinStyle"].i());

            if (cultivation["MonkStyle"])
                character.Cultivation.MonkStyle =
                    static_cast<
                        Character::SkillClass::Monk::Style>(cultivation["MonkStyle"].i());

            if (cultivation["SpearmanStyle"])
                character.Cultivation.SpearmanStyle =
                    static_cast<
                        Character::SkillClass::Spearman::Style>(cultivation["SpearmanStyle"].i());

            if (cultivation["ArcherStyle"])
                character.Cultivation.ArcherStyle =
                    static_cast<
                        Character::SkillClass::Archer::Style>(cultivation["ArcherStyle"].i());

            if (cultivation["AlchemistRank"])
                character.Cultivation.AlchemistRank =
                    static_cast<
                        Character::SkillClass::Alchemist::Rank>(cultivation["AlchemistRank"].i());

            if (cultivation["BeastTamerRank"])
                character.Cultivation.BeastTamerRank =
                    static_cast<
                        Character::SkillClass::BeastTamer::Rank>(cultivation["BeastTamerRank"].i());

            if (cultivation["FormationMasterRank"])
                character.Cultivation.FormationMasterRank =
                    static_cast<
                        Character::SkillClass::FormationMaster::Rank>(cultivation["FormationMasterRank"].i());

            if (cultivation["ArtifactRefinerRank"])
                character.Cultivation.ArtifactRefinerRank =
                    static_cast<
                        Character::SkillClass::ArtifactRefiner::Rank>(cultivation["ArtifactRefinerRank"].i());

            if (cultivation["WeaponProficiency"])
                character.Cultivation.WeaponProficiency =
                    static_cast<int>(
                        cultivation["WeaponProficiency"].i());

            if (cultivation["IsOrthodoxCultivator"])
                character.Cultivation.bIsOrthodoxCultivator =
                    cultivation["IsOrthodoxCultivator"].b();

            if (cultivation["OrthodoxRealm"])
                character.Cultivation.OrthodoxRealm =
                    static_cast<
                        Character::Cultivation::OrthodoxCultivationRealm>(cultivation["OrthodoxRealm"].i());

            if (cultivation["IsDemonicCultivator"])
                character.Cultivation.bIsDemonicCultivator =
                    cultivation["IsDemonicCultivator"].b();

            if (cultivation["DemonicRealm"])
                character.Cultivation.DemonicRealm =
                    static_cast<
                        Character::Cultivation::DemonicCultivationRealm>(cultivation["DemonicRealm"].i());

            if (cultivation["BreakthroughProgress"])
                character.Cultivation.BreakthroughProgress =
                    static_cast<int>(
                        cultivation["BreakthroughProgress"].i());

            if (cultivation["CultivationExperience"])
                character.Cultivation.CultivationExperience =
                    static_cast<int>(
                        cultivation["CultivationExperience"].i());

            if (cultivation["FoundationStability"])
                character.Cultivation.FoundationStability =
                    static_cast<int>(
                        cultivation["FoundationStability"].i());

            if (cultivation["CultivationSpeed"])
                character.Cultivation.CultivationSpeed =
                    static_cast<int>(
                        cultivation["CultivationSpeed"].i());

            if (cultivation["HasFamiliar"])
                character.Cultivation.bHasFamiliar =
                    cultivation["HasFamiliar"].b();

            if (cultivation["SpiritRoot"])
                character.Cultivation.SpiritRoot =
                    static_cast<
                        Character::Roots::SpiritRoot>(cultivation["SpiritRoot"].i());

            if (cultivation["BloodlineType"])
                character.Cultivation.BloodlineType =
                    static_cast<
                        Character::BloodlineType::Bloodline>(cultivation["BloodlineType"].i());

            if (cultivation["BloodlinePurity"])
                character.Cultivation.BloodlinePurity =
                    static_cast<int>(
                        cultivation["BloodlinePurity"].i());

            if (cultivation["BloodlineAwakening"])
                character.Cultivation.BloodlineAwakening =
                    static_cast<int>(
                        cultivation["BloodlineAwakening"].i());

            if (cultivation["PhysiqueType"])
                character.Cultivation.PhysiqueType =
                    static_cast<
                        Character::Physique::BodyType>(cultivation["PhysiqueType"].i());

            if (cultivation["SwordDao"])
                character.Cultivation.SwordDao =
                    static_cast<int>(
                        cultivation["SwordDao"].i());

            if (cultivation["BladeDao"])
                character.Cultivation.BladeDao =
                    static_cast<int>(
                        cultivation["BladeDao"].i());

            if (cultivation["FireDao"])
                character.Cultivation.FireDao =
                    static_cast<int>(
                        cultivation["FireDao"].i());

            if (cultivation["WaterDao"])
                character.Cultivation.WaterDao =
                    static_cast<int>(
                        cultivation["WaterDao"].i());

            if (cultivation["LightningDao"])
                character.Cultivation.LightningDao =
                    static_cast<int>(
                        cultivation["LightningDao"].i());

            if (cultivation["SpaceDao"])
                character.Cultivation.SpaceDao =
                    static_cast<int>(
                        cultivation["SpaceDao"].i());

            if (cultivation["TimeDao"])
                character.Cultivation.TimeDao =
                    static_cast<int>(
                        cultivation["TimeDao"].i());

            if (cultivation["LifeDao"])
                character.Cultivation.LifeDao =
                    static_cast<int>(
                        cultivation["LifeDao"].i());

            if (cultivation["DeathDao"])
                character.Cultivation.DeathDao =
                    static_cast<int>(
                        cultivation["DeathDao"].i());

            if (cultivation["ChaosDao"])
                character.Cultivation.ChaosDao =
                    static_cast<int>(
                        cultivation["ChaosDao"].i());
        }

        // ========================================================
        // TECHNIQUES
        // ========================================================

        if (body["Techniques"])
        {
            const auto &techniques = body["Techniques"];

            if (techniques["HasCultivationTechnique"])
                character.Techniques.bHasCultivationTechnique =
                    techniques["HasCultivationTechnique"].b();

            if (techniques["MainCultivationTechnique"])
                character.Techniques.MainCultivationTechnique =
                    techniques["MainCultivationTechnique"].s();

            if (techniques["MainCultivationTechniqueLevel"])
                character.Techniques.MainCultivationTechniqueLevel =
                    static_cast<int>(
                        techniques["MainCultivationTechniqueLevel"].i());

            if (techniques["HasSecondaryCultivationTechnique"])
                character.Techniques.bHasSecondaryCultivationTechnique =
                    techniques["HasSecondaryCultivationTechnique"].b();

            if (techniques["SecondaryCultivationTechnique"])
                character.Techniques.SecondaryCultivationTechnique =
                    techniques["SecondaryCultivationTechnique"].s();

            if (techniques["SecondaryCultivationTechniqueLevel"])
                character.Techniques.SecondaryCultivationTechniqueLevel =
                    static_cast<int>(
                        techniques["SecondaryCultivationTechniqueLevel"].i());

            if (techniques["BodyRefinementTechnique"])
                character.Techniques.BodyRefinementTechnique =
                    techniques["BodyRefinementTechnique"].s();

            if (techniques["BodyRefinementTechniqueLevel"])
                character.Techniques.BodyRefinementTechniqueLevel =
                    static_cast<int>(
                        techniques["BodyRefinementTechniqueLevel"].i());

            if (techniques["SoulCultivationTechnique"])
                character.Techniques.SoulCultivationTechnique =
                    techniques["SoulCultivationTechnique"].s();

            if (techniques["SoulCultivationTechniqueLevel"])
                character.Techniques.SoulCultivationTechniqueLevel =
                    static_cast<int>(
                        techniques["SoulCultivationTechniqueLevel"].i());

            if (techniques["MovementTechnique"])
                character.Techniques.MovementTechnique =
                    techniques["MovementTechnique"].s();

            if (techniques["MovementTechniqueLevel"])
                character.Techniques.MovementTechniqueLevel =
                    static_cast<int>(
                        techniques["MovementTechniqueLevel"].i());

            if (techniques["SecretTechnique"])
                character.Techniques.SecretTechnique =
                    techniques["SecretTechnique"].s();

            if (techniques["SecretTechniqueLevel"])
                character.Techniques.SecretTechniqueLevel =
                    static_cast<int>(
                        techniques["SecretTechniqueLevel"].i());

            if (techniques["ForbiddenTechnique"])
                character.Techniques.ForbiddenTechnique =
                    techniques["ForbiddenTechnique"].s();

            if (techniques["ForbiddenTechniqueLevel"])
                character.Techniques.ForbiddenTechniqueLevel =
                    static_cast<int>(
                        techniques["ForbiddenTechniqueLevel"].i());
        }

        // ========================================================
        // BODY CONDITION
        // ========================================================

        if (body["BodyCondition"])
        {
            const auto &bodyCondition =
                body["BodyCondition"];

            if (bodyCondition["MeridianQuality"])
                character.BodyCondition.MeridianQuality =
                    static_cast<int>(
                        bodyCondition["MeridianQuality"].i());

            if (bodyCondition["MeridianDamage"])
                character.BodyCondition.MeridianDamage =
                    static_cast<int>(
                        bodyCondition["MeridianDamage"].i());

            if (bodyCondition["HasBrokenMeridians"])
                character.BodyCondition.bHasBrokenMeridians =
                    bodyCondition["HasBrokenMeridians"].b();

            if (bodyCondition["BodyRefinementStage"])
                character.BodyCondition.BodyRefinementStage =
                    static_cast<int>(
                        bodyCondition["BodyRefinementStage"].i());
        }

        // ========================================================
        // RELATIONS
        // ========================================================

        if (body["Relations"])
        {
            const auto &relations = body["Relations"];

            if (relations["IsSectMember"])
                character.Relations.bIsSectMember =
                    relations["IsSectMember"].b();

            if (relations["SectRank"])
                character.Relations.SectRank =
                    static_cast<
                        Character::SectRankTypes::SectRank>(relations["SectRank"].i());

            if (relations["OriginPath"])
                character.Relations.OriginPath =
                    static_cast<
                        Character::Origin::Path>(relations["OriginPath"].i());

            if (relations["MasterName"])
                character.Relations.MasterName =
                    relations["MasterName"].s();

            if (relations["DiscipleNames"])
                character.Relations.DiscipleNames =
                    ReadStringArray(relations["DiscipleNames"]);

            if (relations["FamilyMembers"])
                character.Relations.FamilyMembers =
                    ReadStringArray(relations["FamilyMembers"]);

            if (relations["Friends"])
                character.Relations.Friends =
                    ReadStringArray(relations["Friends"]);

            if (relations["Rivals"])
                character.Relations.Rivals =
                    ReadStringArray(relations["Rivals"]);

            if (relations["Enemies"])
                character.Relations.Enemies =
                    ReadStringArray(relations["Enemies"]);

            if (relations["Lovers"])
                character.Relations.Lovers =
                    ReadStringArray(relations["Lovers"]);
        }

        return character;
    }
}

// ================================================================
// HttpServer
// ================================================================

HttpServer::HttpServer(
    CharacterService &service)
    : characterService(service)
{
}

void HttpServer::Start()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/test")
    ([]()
     { return "VoidStar Backend Online"; });

    CROW_ROUTE(app, "/create-character")
        .methods(crow::HTTPMethod::Post)([this](const crow::request &req)
                                         {
        try
        {
            // ====================================================
            // Parse request body
            // ====================================================

            auto body = crow::json::load(req.body);

            if (!body)
            {
                return crow::response(
                    400,
                    "Invalid JSON");
            }

            // ====================================================
            // Convert JSON -> Cultivator
            // ====================================================

            Cultivator character =
                CharacterFromJson(body);

            // ====================================================
            // Save character
            // ====================================================

            characterService.CreateCharacter(
                character);

            return crow::response(
                201,
                "Character created");
        }
        catch (const std::exception &e)
        {
            std::cerr
                << "CREATE CHARACTER ERROR: "
                << e.what()
                << std::endl;

            return crow::response(
                500,
                e.what());
        } });

    std::cout
        << "HTTP Server running on port 8080"
        << std::endl;

    app.port(8080)
        .multithreaded()
        .run();
}