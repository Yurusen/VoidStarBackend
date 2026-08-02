#pragma once

#include "../enums/CharacterAppearance.hpp"
#include "../enums/CharacterTraits.hpp"
#include "../enums/CharacterStatusEffect.hpp"

#include <string>
#include <vector>

class CharacterStatsBuild
{

public:
    // ============================================================
    // Character Stats
    // ============================================================

    long Level;
    int Health;
    int Stamina;
    int Defense;
    int Accuracy;
    int Evasion;
    int CriticalChance;
    int CriticalDamage;
    int SpiritualResistance;
    int PhysicalStrength;
    int Speed;

    int QiCapacity;
    int SpiritualSense;
    int SoulStrength;
    int Comprehension;
    int DaoComprehension;
    int MentalFortitude;
    int Charisma;
    int Luck;
    int KarmaicBalance;
    int HeavenlyTribulationChance;
    int HeavenlyFavor;

    long KillCount;
    Character::StatusEffect::Status StatusEffects;
};