#include <string>
#include <vector>
#include "../enums/CharacterInventory.hpp"

class CharacterInventoryBuild
{

public:
    // ============================================================
    // Character Inventory
    // ============================================================

    bool bHasWeapon;
    Character::Inventory::WeaponType WeaponType;
    Character::Inventory::ItemGrade WeaponGrade;
    int WeaponDurability;
    int WeaponDamage;
    bool OwnerBound;

    bool bHasSecondaryWeapon;
    Character::Inventory::WeaponType SeondaryWeaponType;
    Character::Inventory::ItemGrade SecondaryWeaponGrade;
    int SecondaryWeaponDurability;
    int SecondaryWeaponDamage;
    bool SecondaryWeaponOwnerBound;

    bool bHasArmour;
    Character::Inventory::ArmourType ArmourType;
    Character::Inventory::ItemGrade ArmourGrade;
    int ArmourDurability;
    int ArmourDefense;
    int ArmourSpiritualResistance;
    bool ArmourOwnerBound;

    bool bHasAccessory;
    Character::Inventory::AccessoryType AccessoryType;
    Character::Inventory::ItemGrade AccessoryGrade;

    bool bHasStorageRing;
    Character::Inventory::StorageRingType StorageRingType;
    int StorageRingCapacity;

    bool bHasTreasure;
    Character::Inventory::TreasureType TreasureType;
    Character::Inventory::ItemGrade TreasureGrade;

    int spiritStoneCount;
    Character::Inventory::SpiritStoneType SpiritStoneType;
};