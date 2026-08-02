#pragma once

#include <cstdint>

namespace Character::Physique
{

    enum class BodyType : uint8_t
    {
        // ============================================================
        // Mortal / Common Physiques
        // ============================================================

        MortalBody = 0,
        RobustBody,
        IronBody,
        SteelBody,
        JadeBody,
        SpiritBody,

        // ============================================================
        // Rare Mortal / Foundation Physiques
        // ============================================================

        NineYinBody,
        PureYangBody,
        YinYangHarmonyBody,

        FiveElementBody,
        LightningVeinBody,
        WindSpiritBody,
        FireSpiritBody,
        WaterSpiritBody,
        EarthSpiritBody,

        // ============================================================
        // Ancient Bloodline Physiques
        // ============================================================

        DragonConstitution,
        TrueDragonBody,
        AzureDragonBody,

        PhoenixConstitution,
        ImmortalPhoenixBody,
        VermillionBirdBody,

        QilinBody,
        WhiteTigerBody,
        BlackTortoiseBody,

        // ============================================================
        // Martial / Combat Physiques
        // ============================================================

        SwordBone,
        SaberBone,
        SpearBone,

        BattleGodBody,
        WarGodPhysique,
        AsuraBody,

        VajraBody,
        DiamondIndestructibleBody,

        // ============================================================
        // Divine Physiques
        // ============================================================

        HeavenlyPhysique,
        DivineBody,
        SaintBody,

        CelestialBody,
        ImmortalBody,
        EternalBody,

        NineHeavensDivineBody,
        PrimordialDivineBody,

        // ============================================================
        // Dao Origin Physiques
        // ============================================================

        DaoSpiritBody,
        DaoSourceBody,
        DaoOriginBody,

        ChaosDaoBody,
        PrimordialChaosBody,

        HeavenlyDaoPhysique,
        GreatDaoBody,
        TranscendentDaoBody,

        // ============================================================
        // Demonic Physiques
        // ============================================================

        DemonicBody,
        BloodDemonBody,
        AbyssDemonBody,

        HeavenlyDemonBody,
        AncientDemonBody,
        PrimordialDemonBody,

        ChaosDemonPhysique,
        DemonGodBody,

        // ============================================================
        // Forbidden / Beyond Realm
        // ============================================================

        SamsaraBody,
        VoidBody,
        TimeSpaceBody,

        OriginChaosBody,
        SupremeOriginBody,

        TranscendentPhysique,

        Count
    };

}