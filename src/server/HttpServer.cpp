#include "HttpServer.h"

#include <crow.h>
#include <iostream>

HttpServer::HttpServer(
    CharacterService &service)

    : characterService(service)

{
}

void HttpServer::Start()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/test")
    ([]()
     { return "VoidStar Backend Online"; });

    CROW_ROUTE(app, "/create-character")
        .methods(crow::HTTPMethod::Post)([this](const crow::request &req)
                                         {
        try
        {
            auto body = crow::json::load(req.body);

            if (!body)
            {
                return crow::response(
                    400,
                    "Invalid JSON");
            }


            Cultivator character;

            character.CharacterID =
                body["CharacterID"].s();


            character.Identity.Name =
                body["Name"].s();


            characterService.CreateCharacter(
                character);


            return crow::response(
                201,
                "Character created");
        }
        catch (const std::exception &e)
        {
            return crow::response(
                500,
                e.what());
        } });

    std::cout
        << "HTTP Server running on port 8080"
        << std::endl;

    app.port(8080)
        .multithreaded()
        .run();
}