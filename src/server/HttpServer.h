#pragma once
#include "../services/CharacterService.h"

class HttpServer
{
private:
    CharacterService &characterService;

public:
    HttpServer(
        CharacterService &service);

    void Start();
};
