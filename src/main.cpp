#include "database/MongoConnection.h"

#include "repositories/CharacterRepository.h"

#include "services/CharacterService.h"

#include "api/CharacterController.h"

int main()
{

    MongoConnection database;

    CharacterRepository repository(
        database);

    CharacterService service(
        repository);

    CharacterController controller(
        service);

    controller.CreateCharacter(
        1001,
        "Knight");

    return 0;
}