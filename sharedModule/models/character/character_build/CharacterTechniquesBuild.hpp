#include <string>
#include <vector>
#include "../enums/CharacterAppearance.hpp"
#include "../enums/CharacterTraits.hpp"
#include "../enums/CharacterStatusEffect.hpp"

class CharacterTechniquesBuild
{

public:
    // ============================================================
    // Character Techniques
    // ============================================================

    bool bHasCultivationTechnique;

    std::string MainCultivationTechnique;
    int MainCultivationTechniqueLevel;

    bool bHasSecondaryCultivationTechnique;

    std::string SecondaryCultivationTechnique;
    int SecondaryCultivationTechniqueLevel;

    std::string BodyRefinementTechnique;
    int BodyRefinementTechniqueLevel;

    std::string SoulCultivationTechnique;
    int SoulCultivationTechniqueLevel;

    std::string MovementTechnique;
    int MovementTechniqueLevel;

    std::string SecretTechnique;
    int SecretTechniqueLevel;

    std::string ForbiddenTechnique;
    int ForbiddenTechniqueLevel;
};