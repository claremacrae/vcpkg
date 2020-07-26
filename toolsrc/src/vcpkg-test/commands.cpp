#include <catch2/catch.hpp>

#include <vcpkg/commands.version.h>

using namespace vcpkg;

TEST_CASE ("check all commands are constructable", "[commands]")
{
    using namespace Commands;
    VersionCommand v;
}
