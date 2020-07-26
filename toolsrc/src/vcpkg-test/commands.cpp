#include <catch2/catch.hpp>

#include <vcpkg/commands.contact.h>
#include <vcpkg/commands.h>
#include <vcpkg/commands.version.h>

using namespace vcpkg;

TEST_CASE ("check all commands are constructable", "[commands]")
{
    using namespace Commands;
    Contact::ContactCommand c;
    Version::VersionCommand v;
}

TEST_CASE ("check all command names are found", "[commands]")
{
    auto commands_raw = Commands::get_available_commands_type_c();
    std::vector<Commands::PackageNameAndFunction<Commands::CommandTypeC>> commands(commands_raw.begin(),
                                                                                   commands_raw.end());
    CHECK(Commands::find("version", commands) != nullptr);
    CHECK(Commands::find("contact", commands) != nullptr);
    CHECK(Commands::find("wibble", commands) == nullptr);
}
