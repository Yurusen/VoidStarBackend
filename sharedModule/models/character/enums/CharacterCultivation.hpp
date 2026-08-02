#pragma once

#include <cstdint>

namespace Character::Cultivation
{

    enum class OrthodoxCultivationRealm : uint8_t
    {
        // No cultivation
        Mortal = 0,

        // Foundation
        BodyTempering,
        QiGathering,
        FoundationEstablishment,
        GoldenCore,
        NascentSoul,
        SpiritTransformation,
        VoidRefinement,
        Integration,
        Mahayana,

        // Ascension
        TribulationTranscendent,
        TrueAscendant,

        // Immortal Realms
        EarthImmortal,
        HeavenImmortal,
        TrueImmortal,
        GoldenImmortal,
        MysticImmortal,
        ImmortalKing,
        ImmortalEmperor,

        // Dao Realms
        DaoLord,
        DaoSovereign,
        DaoSaint,
        DaoAncestor,

        // Transcendence
        Nirvana,
        EternalImmortal,
        PrimordialBeing,
        Transcendent,

        Count
    };

    enum class DemonicCultivationRealm : uint8_t
    {
        // No cultivation
        Mortal = 0,

        // Demonic Foundation
        BodyRefinement,
        BloodCondensation,
        DemonSeedFormation,
        DemonCore,
        NascentDemonSoul,
        DemonSoulTransformation,

        // Higher Demonic Realms
        AbyssRefinement,
        DemonFusion,
        GreatDemon,

        // Demonic Ascension
        HeavenlyDemonTribulation,
        TrueDemonAscendant,

        // Demon Immortal Realms
        EarthDemon,
        HeavenDemon,
        TrueDemon,
        DemonKing,
        DemonEmperor,

        // Demon Dao Realms
        DemonLord,
        DemonSaint,
        DemonGod,
        DemonAncestor,

        // Forbidden Transcendence
        PrimordialDemon,
        ChaosDemon,
        EternalDemon,
        TranscendentDemon,

        Count
    };

}