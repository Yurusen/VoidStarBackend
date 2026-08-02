#include "database/MongoConnection.h"
#include "repositories/CharacterRepository.h"
#include "services/CharacterService.h"
#include "api/CharacterController.h"
#include "server/HttpServer.h"

int main()
{

    MongoConnection database;

    CharacterRepository repository(
        database);

    CharacterService service(
        repository);

    CharacterController controller(
        service);

    HttpServer server(
        service);

    server.Start();

    return 0;
}