#pragma once

#include <cstdint>

namespace Character::SectRankTypes
{

    enum class SectRank : uint8_t
    {
        // Recruitment
        Candidate = 0,

        // Disciples
        OuterDisciple,
        InnerDisciple,
        CoreDisciple,
        DirectDisciple,
        TrueDisciple,
        ShadowDisciple,

        // Staff
        JuniorInstructor,
        Instructor,
        Deacon,

        // Elders
        HallElder,
        PeakMaster,
        GrandElder,
        SupremeElder,

        // Leadership
        ViceSectMaster,
        SectMaster,
        Patriarch,
        Ancestor,

        // Exiled
        Exiled,
        Traitor,
        Outcast,

        Count
    };

}