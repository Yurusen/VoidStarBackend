#pragma once

#include <cstdint>

namespace Character::SkillClass
{
    // ============================================================
    // Martial Paths / Combat Classes
    // ============================================================

    enum class MartialPath : uint8_t
    {
        Swordsman = 0,
        Assassin,
        Monk,
        Spearman,
        Archer,

        Count
    };

    // --------------------------------------------------------
    // Sword Path (剑道)
    // --------------------------------------------------------

    struct Swordsman
    {
        enum class Style : uint8_t
        {
            SwordNovice = 0,
            SwordDisciple,

            DualSword,
            GreatSword,
            FlyingSword,

            SwordMaster,
            SwordSaint,
            SwordImmortal,

            HeavenlySword,
            DaoSword,
            VoidDaoSword,

            Count
        };
    };

    // --------------------------------------------------------
    // Assassin Path (刺客道)
    // --------------------------------------------------------

    struct Assassin
    {
        enum class Style : uint8_t
        {
            ShadowNovice = 0,
            HiddenBlade,

            PoisonBlade,
            DaggerMaster,

            ShadowAssassin,
            NightWalker,

            PhantomKiller,
            DeathLord,

            VoidAssassin,

            Count
        };
    };

    // --------------------------------------------------------
    // Monk Path (佛修 / 体修)
    // --------------------------------------------------------

    struct Monk
    {
        enum class Style : uint8_t
        {
            Initiate = 0,
            MartialMonk,

            BodyCultivator,
            IronBody,

            VajraBody,
            GoldenBody,

            Arhat,
            SaintMonk,

            BuddhaWarrior,

            Count
        };
    };

    // --------------------------------------------------------
    // Spear Path (枪道)
    // --------------------------------------------------------

    namespace Spearman
    {
        enum class Style : uint8_t
        {
            SpearApprentice = 0,

            BattlefieldSpear,
            DragonSpear,

            SpearMaster,
            SpearKing,
            SpearSaint,

            HeavenlySpear,
            TrueSpearDao,

            Count
        };
    };

    // --------------------------------------------------------
    // Archer Path (弓道)
    // --------------------------------------------------------

    struct Archer
    {
        enum class Style : uint8_t
        {
            Hunter = 0,

            SpiritArcher,
            WindArcher,
            MoonArcher,

            DivineArcher,
            StarArcher,

            HeavenlyBow,

            Count
        };
    };

    // --------------------------------------------------------
    // Alchemist Path (炼丹师)
    // --------------------------------------------------------

    struct Alchemist
    {
        enum class Rank : uint8_t
        {
            Apprentice = 0,

            PillRefiner,
            SpiritAlchemist,

            GrandAlchemist,
            EarthAlchemist,
            HeavenAlchemist,

            ImmortalAlchemist,

            Count
        };
    };

    // --------------------------------------------------------
    // Beast Tamer Path (御兽师)
    // --------------------------------------------------------

    struct BeastTamer
    {
        enum class Rank : uint8_t
        {
            Novice = 0,

            SpiritTamer,
            BeastHandler,

            BeastMaster,
            DivineTamer,

            AncientTamer,
            BeastLord,

            Count
        };
    };

    // --------------------------------------------------------
    // Formation Path (阵法师)
    // --------------------------------------------------------

    struct FormationMaster
    {
        enum class Rank : uint8_t
        {
            Apprentice = 0,

            FormationStudent,
            FormationMaster,

            GrandFormationMaster,

            HeavenFormationMaster,

            DaoFormationMaster,

            Count
        };
    };

    // --------------------------------------------------------
    // Artifact Refining Path (炼器师)
    // --------------------------------------------------------

    struct ArtifactRefiner
    {
        enum class Rank : uint8_t
        {
            Apprentice = 0,

            WeaponSmith,
            SpiritCrafter,

            ArtifactMaster,

            DivineCrafter,

            ImmortalRefiner,

            Count
        };
    };
}