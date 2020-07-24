#include <catch2/catch.hpp>

#include <vcpkg/base/files.h>

#include <vcpkg/commands.h>

#include <string>

TEST_CASE ("get_available_commands", "[commands_get_available_commands]")
{
    using namespace vcpkg;

    // Copied from inner() in toolsrc/src/vcpkg.cpp
    static const auto find_command = [](auto&& commands, vcpkg::StringView command) {
        auto it = Util::find_if(
            commands, [&](auto&& commandc) { return Strings::case_insensitive_ascii_equals(commandc.name, command); });
        using std::end;
        if (it != end(commands))
        {
            return &*it;
        }
        else
        {
            return static_cast<decltype(&*it)>(nullptr);
        }
    };

    {
        const auto& commands = Commands::get_available_commands_type_b();
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
        const auto& commands = Commands::get_available_commands_type_c();
        CHECK(find_command(commands, "version") != nullptr);
        CHECK(find_command(commands, "contact") != nullptr);
        CHECK(find_command(commands, "wibble") == nullptr);
    }
}
