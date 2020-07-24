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
        const auto& commands = Commands::get_available_commands_type_c();
        CHECK(find_command(commands, "version") != nullptr);
        CHECK(find_command(commands, "contact") != nullptr);
        CHECK(find_command(commands, "wibble") == nullptr);
    }
}
