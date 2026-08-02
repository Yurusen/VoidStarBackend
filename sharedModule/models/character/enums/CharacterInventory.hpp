#pragma once

namespace Character::Inventory
{

    // ============================================================
    // Weapons
    // ============================================================

    enum class WeaponType
    {
        Sword,
        Sabre,
        Spear,
        Staff,
        Bow,
        Dagger,
        Fan,
        Whip,
        Axe,
        Hammer,
        FistWeapon,

        FlyingSword,
        DivineWeapon,
        DemonicWeapon
    };

    // ============================================================
    // Armour
    // ============================================================

    enum class ArmourType
    {
        Cloth,
        Leather,
        IronArmour,
        SpiritArmour,
        BattleRobes,

        SectUniform,
        DivineArmour,
        ImmortalArmour,
        DemonicArmour,

        RuinicArmour
    };

    // ============================================================
    // Accessories
    // ============================================================

    enum class AccessoryType
    {
        Ring,
        Necklace,
        Bracelet,
        Earring,
        Hairpin,
        Pendant,
        Talisman,

        SpiritBead,
        DaoArtifact
    };

    // ============================================================
    // Storage Rings
    // ============================================================

    enum class StorageRingType
    {
        BasicStorageRing,
        SpiritStorageRing,
        SpatialRing,

        HeavenGradeRing,
        ImmortalStorageRing,

        VoidRing

    };

    // ============================================================
    // Treasures
    // ============================================================

    enum class TreasureType
    {
        SpiritTreasure,
        EarthTreasure,
        HeavenTreasure,

        DivineTreasure,
        ImmortalTreasure,

        AncientArtifact,
        PrimordialArtifact,

        ForbiddenTreasure
    };

    // ============================================================
    // Spirit Stones
    // ============================================================

    enum class SpiritStoneType
    {
        LowGrade,
        MediumGrade,
        HighGrade,
        TopGrade,

        HeavenGrade,
        ImmortalGrade,

        DivineSpiritStone,
        PrimordialSpiritStone
    };

    enum class ItemGrade
    {
        Common,
        Mortal,
        Spirit,
        Earth,
        Heaven,
        Divine,
        Immortal,
        Primordial,
        Mythic,
    };
}