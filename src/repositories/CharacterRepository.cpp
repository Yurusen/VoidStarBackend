#include "CharacterRepository.h"

#include <cstdint>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <bsoncxx/json.hpp>

using bsoncxx::builder::stream::array;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;

CharacterRepository::CharacterRepository(
    MongoConnection &database)
    : mongo(database)
{
}

std::string CharacterRepository::GetCharacterById(
    const std::string &id)
{
    auto collection = mongo.GetDatabase()["characters"];

    auto result = collection.find_one(
        bsoncxx::builder::stream::document{}
        << "CharacterID"
        << id
        << bsoncxx::builder::stream::finalize);

    if (!result)
    {
        return "{}";
    }

    return bsoncxx::to_json(
        result->view());
}

void CharacterRepository::CreateCharacter(
    const Cultivator &character)
{
    auto collection =
        mongo.GetDatabase()["characters"];

    auto titles = array{};

    for (const auto &title :
         character.Identity.Titles)
    {
        titles << title;
    }

    auto friends = array{};

    for (const auto &friendName :
         character.Relations.Friends)
    {
        friends << friendName;
    }

    auto identity =
        document{}

        << "Name"
        << character.Identity.Name

        << "PrimaryTitle"
        << character.Identity.PrimaryTitle

        << "CountryOfOrigin"
        << character.Identity.CountryOfOrigin

        << "Age"
        << static_cast<std::int64_t>(
               character.Identity.Age)

        << "Titles"
        << titles.view()

        << finalize;

    auto stats =
        document{}

        << "Level"
        << static_cast<std::int64_t>(
               character.Stats.Level)

        << "Health"
        << static_cast<std::int64_t>(
               character.Stats.Health)

        << "KillCount"
        << static_cast<std::int64_t>(
               character.Stats.KillCount)

        << finalize;

    auto personality =
        document{}

        << "Honor"
        << static_cast<std::int64_t>(
               character.Personality.Honor)

        << "Courage"
        << static_cast<std::int64_t>(
               character.Personality.Courage)

        << finalize;

    auto relations =
        document{}

        << "Friends"
        << friends.view()

        << finalize;

    auto doc =
        document{}

        << "CharacterID"
        << character.CharacterID

        << "Identity"
        << identity.view()

        << "Stats"
        << stats.view()

        << "Personality"
        << personality.view()

        << "Relations"
        << relations.view()

        << finalize;

    collection.insert_one(
        doc.view());
}