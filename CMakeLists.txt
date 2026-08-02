cmake_minimum_required(VERSION 3.20)

project(VoidStarBackend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(mongocxx REQUIRED)
find_package(Crow CONFIG REQUIRED)

add_executable(
    VoidStarBackend

    src/main.cpp

    src/config/Config.cpp

    src/server/HttpServer.cpp

    src/database/MongoConnection.cpp

    src/repositories/CharacterRepository.cpp

    src/services/CharacterService.cpp

    src/api/CharacterController.cpp

)

target_link_libraries(
    VoidStarBackend
    PRIVATE
        mongo::mongocxx_shared
        Crow::Crow
)