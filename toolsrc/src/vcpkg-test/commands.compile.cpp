#include <catch2/catch.hpp>

#include <vcpkg/commands.h>

// Temporary test to speed up refactoring.
// Delete after use.
TEST_CASE ("check command structs are constructible", "[commands-compile]")
{
    using namespace vcpkg;

    Commands::BuildExternal::BuildExternalCommand c;
}
