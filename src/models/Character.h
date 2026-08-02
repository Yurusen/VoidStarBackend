#pragma once

#include <string>
#include <vector>

struct Character
{

public:
    Character();

    std::string GetID() const;

    void SetID(
        const std::string &id);

    std::string CharacterID;

    struct IdentityData
    {
        std::string Name;

        std::string PrimaryTitle;

        std::string CountryOfOrigin;

        std::vector<std::string> Titles;

        std::vector<std::string> Achievements;

        long long Age = 0;

        long long LifeSpan = 0;

        std::string Gender;

        std::string Race;

        std::string HairColor;

        std::string EyeColor;

        std::string BodyType;

        std::string NobilityStatus;

        std::string Alignment;

        std::string Quirks;

        std::string JianghuReputation;

        std::string SectReputation;

        std::string DemonicReputation;

        std::string UnorthodoxReputation;

    } Identity;

    struct PersonalityData
    {

        int Aggression = 0;

        int Honor = 50;

        int Mercy = 0;

        int Greed = 0;

        int Ambition = 0;

        int Loyalty = 0;

        int Courage = 50;

        int Ruthlessness = 0;

        int Patience = 0;

        int Fear = 0;

        int Stress = 0;

        int Fatigue = 0;

        int Confidence = 0;

        int Bloodlust = 0;

        int Suspicion = 0;

        int Anger = 0;

        int Happiness = 0;

        int Sadness = 0;

        int Curiosity = 0;

    } Personality;

    struct StatsData
    {

        int Level = 1;

        int Health = 100;

        int Stamina = 100;

        int Defense = 0;

        int Accuracy = 0;

        int Evasion = 0;

        int CriticalChance = 0;

        int CriticalDamage = 0;

        int SpiritualResistance = 0;

        int PhysicalStrength = 0;

        int Speed = 0;

        int QiCapacity = 0;

        int SpiritualSense = 0;

        int SoulStrength = 0;

        int Comprehension = 0;

        int DaoComprehension = 0;

        int MentalFortitude = 0;

        int Charisma = 0;

        int Luck = 0;

        int KarmaicBalance = 0;

        long long KillCount = 0;

        std::string StatusEffects;

    } Stats;

    struct InventoryData
    {

        bool bHasWeapon = false;

        std::string WeaponType;

        int WeaponDurability = 0;

        int WeaponDamage = 0;

    } Inventory;

    struct CultivationData
    {

        std::string MartialPath;

        int WeaponProficiency = 0;

        int BreakthroughProgress = 0;

        int CultivationExperience = 0;

        std::string SpiritRoot;

    } Cultivation;

    struct RelationsData
    {

        bool bIsSectMember = false;

        std::string SectRank;

        std::string MasterName;

        std::vector<std::string> DiscipleNames;

        std::vector<std::string> Friends;

        std::vector<std::string> FamilyMembers;

        std::vector<std::string> Rivals;

        std::vector<std::string> Enemies;

        std::vector<std::string> Lovers;

    } Relations;
};