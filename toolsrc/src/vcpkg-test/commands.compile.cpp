#include <catch2/catch.hpp>

#include <vcpkg/commands.autocomplete.h>
#include <vcpkg/commands.buildexternal.h>
#include <vcpkg/commands.cache.h>
#include <vcpkg/commands.ci.h>
#include <vcpkg/commands.ciclean.h>
#include <vcpkg/commands.contact.h>
#include <vcpkg/commands.create.h>
#include <vcpkg/commands.dependinfo.h>
#include <vcpkg/commands.edit.h>
#include <vcpkg/commands.env.h>
#include <vcpkg/commands.fetch.h>
#include <vcpkg/commands.format-manifest.h>
#include <vcpkg/commands.hash.h>
#include <vcpkg/commands.integrate.h>
#include <vcpkg/commands.list.h>
#include <vcpkg/commands.owns.h>
#include <vcpkg/commands.porthistory.h>
#include <vcpkg/commands.portsdiff.h>
#include <vcpkg/commands.search.h>
#include <vcpkg/commands.upgrade.h>
#include <vcpkg/commands.version.h>
#include <vcpkg/commands.xvsinstances.h>
#include <vcpkg/help.h>
#include <vcpkg/update.h>

// Temporary test to speed up refactoring.
// Delete after use.
TEMPLATE_TEST_CASE("check command structs are constructable",
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
                   vcpkg::Commands::Integrate::IntegrateCommand,
                   vcpkg::Commands::PortsDiff::PortsDiffCommand,
                   vcpkg::Commands::PortHistory::PortHistoryCommand,
                   vcpkg::Commands::Autocomplete::AutocompleteCommand,
                   vcpkg::Commands::Version::VersionCommand,
                   vcpkg::Commands::Contact::ContactCommand,
                   vcpkg::Commands::X_VSInstances::X_VSInstancesCommand,
                   vcpkg::Commands::Hash::HashCommand,
                   vcpkg::Commands::Fetch::FetchCommand,
                   vcpkg::Commands::FormatManifest::FormatManifestCommand,
                   vcpkg::Update::UpdateCommand,
                   vcpkg::Help::HelpCommand)
{
    TestType c;
}
