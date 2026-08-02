cmake_minimum_required(VERSION 3.20)

project(VoidStarBackend)


set(CMAKE_CXX_STANDARD 20)


find_package(mongocxx REQUIRED)


add_executable(
    VoidStarBackend

    src/main.cpp

    src/config/Config.cpp

    src/database/MongoConnection.cpp

    src/models/Character.cpp

    src/repositories/CharacterRepository.cpp

    src/services/CharacterService.cpp

    src/api/CharacterController.cpp
)


target_link_libraries(
    VoidStarBackend
    mongo::mongocxx_shared
)