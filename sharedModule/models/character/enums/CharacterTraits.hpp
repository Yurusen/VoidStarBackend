#pragma once

namespace Character::Traits
{

    enum class NobilityStatus
    {
        Commoner,
        Noble,
        Royalty,
        FallenNoble,
        SecretLineage
    };

    enum class Alignment
    {
        Righteous,
        Neutral,
        Wanderer,
        Demonic,
        Buddhist,
        Daoist,
        Confucian,
        Mercenary,
        Imperial,
        Revolutionary,
        Heretical,
        Primordial
    };

    enum class GeneralMoralityReputation
    {
        Saintly,
        Honorable,
        Good,
        Neutral,
        SelfInterested,
        Ruthless,
        Cruel,
        Evil,
        Infamous,
        Demonic,
        Redeemed,
        Corrupted
    };

    enum class Quirks
    {
        Lazy,
        Lucky,
        Genius,
        SwordAddict,
        BattleManiac,
        NaturalAlchemist,
        ColdHeart,
        DemonSlayer,
    };

}