#pragma once

#include <cstdint>

namespace Character::Origin
{
    enum class Path : uint8_t
    {
        // ============================================================
        // Orthodox Sects (正道宗门)
        // ============================================================

        GreatSect = 0, // One of the dominant ancient sects
        MajorSect,     // Powerful established sect
        SmallSect,     // Minor local sect
        HiddenSect,    // Ancient sect hidden from the world
        AncientSect,   // Sect with inheritance from ancient eras

        // ============================================================
        // Unorthodox / Neutral Paths (旁门)
        // ============================================================

        UnorthodoxSect,   // Uses unusual cultivation methods
        WanderingSect,    // Sect without fixed territory
        ClanCultivator,   // Cultivates through family bloodline
        NobleClan,        // Ancient cultivation family
        MerchantAlliance, // Wealth-based cultivation organization

        // ============================================================
        // Demonic Paths (魔道)
        // ============================================================

        DemonicSect,     // Traditional demon cultivation sect
        BloodDemonSect,  // Blood refinement techniques
        SoulDemonSect,   // Soul cultivation techniques
        ForbiddenSect,   // Uses banned cultivation arts
        AbyssCultivator, // Cultivators tied to dark realms

        // ============================================================
        // Independent Cultivators (散修)
        // ============================================================

        RogueCultivator,     // No sect affiliation
        WanderingCultivator, // Travels seeking opportunities
        HermitCultivator,    // Lives secluded from society
        AncientInheritance,  // Obtained a lost inheritance
        TreasureHunter,      // Searches ruins and secret realms

        // ============================================================
        // Special Origins
        // ============================================================

        RoyalFamily,   // Mortal or immortal dynasty
        HeavenlyCourt, // Servant of celestial authority
        ImmortalClan,  // High-level immortal lineage
        BeastClan,     // Non-human cultivation lineage
        SpiritRace,    // Natural spirits
        DemonRace,     // Born demon lineage

        Count
    };
}