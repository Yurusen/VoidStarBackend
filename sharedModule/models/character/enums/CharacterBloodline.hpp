#pragma once

#include <cstdint>

namespace Character::BloodlineType
{

    enum class Bloodline : uint8_t
    {
        // ============================================================
        // Mortal / Common Bloodlines
        // ============================================================

        MortalBlood = 0,
        NobleBlood,
        AncientHumanBlood,

        // ============================================================
        // Spirit Beast Bloodlines
        // ============================================================

        SpiritBeastBloodline,
        AncientBeastBloodline,

        WolfBloodline,
        TigerBloodline,
        BearBloodline,
        SerpentBloodline,

        // ============================================================
        // Divine Beast Bloodlines
        // ============================================================

        DivineBeastBloodline,

        DragonBloodline,
        TrueDragonBloodline,
        AzureDragonBloodline,
        GoldenDragonBloodline,
        ChaosDragonBloodline,

        PhoenixBloodline,
        TruePhoenixBloodline,
        ImmortalPhoenixBloodline,
        NineColoredPhoenixBloodline,

        QilinBloodline,
        WhiteTigerBloodline,
        BlackTortoiseBloodline,
        VermillionBirdBloodline,

        // ============================================================
        // Celestial / Divine Bloodlines
        // ============================================================

        DivineBloodline,
        CelestialBloodline,
        HeavenlyRaceBloodline,

        AncientGodBloodline,
        PrimordialGodBloodline,
        TitanBloodline,

        // ============================================================
        // Demonic Bloodlines
        // ============================================================

        DemonBloodline,
        AncientDemonBloodline,
        PrimordialDemonBloodline,

        HeavenlyDemonBloodline,
        AbyssDemonBloodline,
        ChaosDemonBloodline,

        DemonGodBloodline,
        DevilAncestorBloodline,

        // ============================================================
        // Immortal Bloodlines
        // ============================================================

        ImmortalBloodline,
        AncientImmortalBloodline,
        TrueImmortalBloodline,

        GoldenImmortalBloodline,
        ImmortalEmperorBloodline,

        // ============================================================
        // Dao Origin Bloodlines
        // ============================================================

        DaoBloodline,
        HeavenlyDaoBloodline,
        GreatDaoBloodline,

        PrimordialBloodline,
        ChaosOriginBloodline,
        OriginAncestorBloodline,

        // ============================================================
        // Forbidden / Transcendent Bloodlines
        // ============================================================

        VoidAncestorBloodline,
        TimeAncestorBloodline,
        SpaceAncestorBloodline,

        SamsaraBloodline,

        TranscendentBloodline,
        SupremeOriginBloodline,

        Count
    };

}