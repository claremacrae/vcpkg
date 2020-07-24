#include <catch2/catch.hpp>

#include <vcpkg/base/files.h>

#include <vcpkg/commands.h>

#include <string>

TEST_CASE ("get_available_commands", "[commands_get_available_commands]")
{
    using namespace vcpkg;

    static const auto find_command = [](auto&& commands, const std::string& command) {
        return Commands::find(command, commands);
    };

    {
        const auto& span = Commands::get_available_commands_type_a();
        using ContainerType = std::vector<Commands::PackageNameAndFunction<Commands::CommandTypeA>>;
        const ContainerType commands(span.begin(), span.end());

        CHECK(find_command(commands, "install") != nullptr);
        CHECK(find_command(commands, "x-set-installed") != nullptr);
        CHECK(find_command(commands, "ci") != nullptr);
        CHECK(find_command(commands, "remove") != nullptr);
        CHECK(find_command(commands, "upgrade") != nullptr);
        CHECK(find_command(commands, "build") != nullptr);
        CHECK(find_command(commands, "env") != nullptr);
        CHECK(find_command(commands, "build-external") != nullptr);
        CHECK(find_command(commands, "export") != nullptr);
        CHECK(find_command(commands, "depend-info") != nullptr);
        CHECK(find_command(commands, "wibble") == nullptr);
    }

    {
        const auto& span = Commands::get_available_commands_type_b();
        using ContainerType = std::vector<Commands::PackageNameAndFunction<std::shared_ptr<Commands::PathsCommand>>>;
        const ContainerType commands(span.begin(), span.end());
        CHECK(find_command(commands, "/?") != nullptr);
        CHECK(find_command(commands, "help") != nullptr);
        CHECK(find_command(commands, "search") != nullptr);
        CHECK(find_command(commands, "list") != nullptr);
        CHECK(find_command(commands, "integrate") != nullptr);
        CHECK(find_command(commands, "owns") != nullptr);
        CHECK(find_command(commands, "update") != nullptr);
        CHECK(find_command(commands, "edit") != nullptr);
        CHECK(find_command(commands, "create") != nullptr);
        CHECK(find_command(commands, "cache") != nullptr);
        CHECK(find_command(commands, "portsdiff") != nullptr);
        CHECK(find_command(commands, "autocomplete") != nullptr);
        CHECK(find_command(commands, "hash") != nullptr);
        CHECK(find_command(commands, "fetch") != nullptr);
        CHECK(find_command(commands, "x-ci-clean") != nullptr);
        CHECK(find_command(commands, "x-history") != nullptr);
        CHECK(find_command(commands, "x-vsinstances") != nullptr);
        CHECK(find_command(commands, "x-format-manifest") != nullptr);
        CHECK(find_command(commands, "wibble") == nullptr);
    }

    {
        const auto& span = Commands::get_available_commands_type_c();
        using ContainerType = std::vector<Commands::PackageNameAndFunction<std::shared_ptr<Commands::BasicCommand>>>;
        const ContainerType commands(span.begin(), span.end());
        CHECK(find_command(commands, "version") != nullptr);
        CHECK(find_command(commands, "contact") != nullptr);
        CHECK(find_command(commands, "wibble") == nullptr);
    }
}
