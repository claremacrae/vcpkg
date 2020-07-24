#include <catch2/catch.hpp>

#include <vcpkg/commands.h>

// Temporary test to speed up refactoring.
// Delete after use.
TEMPLATE_TEST_CASE("check command structs are constructible",
                   "[commands-compile]",
                   vcpkg::Commands::BuildExternal::BuildExternalCommand,
                   vcpkg::Commands::CI::CICommand,
                   vcpkg::Commands::CIClean::CICleanCommand,
                   vcpkg::Commands::Env::EnvCommand,
                   vcpkg::Commands::Create::CreateCommand,
                   vcpkg::Commands::Upgrade::UpgradeCommand,
                   vcpkg::Commands::Edit::EditCommand,
                   vcpkg::Commands::DependInfo::DependInfoCommand,
                   vcpkg::Commands::Search::SearchCommand,
                   vcpkg::Commands::List::ListCommand,
                   vcpkg::Commands::SetInstalled::SetInstalledCommand)
{
    TestType c;
}
