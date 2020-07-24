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
                   vcpkg::Commands::Owns::OwnsCommand,
                   vcpkg::Commands::Cache::CacheCommand,
                   vcpkg::Commands::PortsDiff::PortsDiffCommand,
                   vcpkg::Commands::PortHistory::PortHistoryCommand,
                   vcpkg::Commands::Autocomplete::AutocompleteCommand,
                   vcpkg::Commands::X_VSInstances::X_VSInstancesCommand,
                   vcpkg::Commands::Hash::HashCommand,
                   vcpkg::Commands::Fetch::FetchCommand,
                   vcpkg::Commands::SetInstalled::SetInstalledCommand)
{
    TestType c;
}
