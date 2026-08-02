#pragma once

namespace Character::Roots
{

    enum class SpiritRoot
    {
        // ============================================================
        // Mortal Roots
        // ============================================================

        FalseSpiritRoot, // Almost no cultivation potential
        MortalRoot,      // Normal person talent

        OneElementRoot,   // Single element affinity
        DualElementRoot,  // Two element affinity
        ThreeElementRoot, // Balanced but average
        FourElementRoot,  // Rare mortal talent
        FiveElementRoot,  // Perfect elemental balance

        // ============================================================
        // Mutated Roots
        // ============================================================

        MutatedSpiritRoot,   // Unique abnormal mutation
        VariantSpiritRoot,   // Altered elemental affinity
        CorruptedSpiritRoot, // Damaged or unstable root

        // ============================================================
        // Heavenly / Divine Roots
        // ============================================================

        HeavenlySpiritRoot, // Favored by the heavens
        DivineSpiritRoot,   // Divine-level talent
        SupremeDivineRoot,  // Extremely rare

        // ============================================================
        // Demonic Roots
        // ============================================================

        DemonicSpiritRoot, // Demon cultivation compatible
        AncientDemonRoot,  // Ancient demonic lineage
        ChaosDemonRoot,    // Forbidden demonic power

        // ============================================================
        // Immortal Roots
        // ============================================================

        ImmortalSpiritRoot,  // Immortal cultivation talent
        TrueImmortalRoot,    // Rare immortal potential
        EternalImmortalRoot, // Legendary immortal talent

        // ============================================================
        // Forbidden / Special Roots
        // ============================================================

        YinYangSpiritRoot, // Balance of opposing forces
        ChaosSpiritRoot,   // Primordial chaotic energy
        VoidSpiritRoot,    // Space-related cultivation
        SamsaraSpiritRoot, // Reincarnation power

        ForbiddenSpiritRoot, // Dangerous unknown origin

        // ============================================================
        // Ultimate Roots
        // ============================================================

        PrimordialSpiritRoot, // Origin-level talent
        OriginDaoRoot         // Beyond normal cultivation systems
    };

}