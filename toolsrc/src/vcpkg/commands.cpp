#include "pch.h"

#include <vcpkg/base/system.print.h>

#include <vcpkg/build.h>
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
#include <vcpkg/commands.h>
#include <vcpkg/commands.hash.h>
#include <vcpkg/commands.integrate.h>
#include <vcpkg/commands.list.h>
#include <vcpkg/commands.owns.h>
#include <vcpkg/commands.porthistory.h>
#include <vcpkg/commands.portsdiff.h>
#include <vcpkg/commands.search.h>
#include <vcpkg/commands.setinstalled.h>
#include <vcpkg/commands.upgrade.h>
#include <vcpkg/commands.version.h>
#include <vcpkg/commands.xvsinstances.h>
#include <vcpkg/export.h>
#include <vcpkg/help.h>
#include <vcpkg/install.h>
#include <vcpkg/remove.h>
#include <vcpkg/update.h>

namespace vcpkg::Commands
{
    Span<const PackageNameAndFunction<std::shared_ptr<TripletCommand>>> get_available_commands_type_a()
    {
        static std::vector<PackageNameAndFunction<std::shared_ptr<TripletCommand>>> t = {
            {"install", std::make_shared<Install::InstallCommand>()},
            {"x-set-installed", std::make_shared<SetInstalled::SetInstalledCommand>()},
            {"ci", std::make_shared<CI::CICommand>()},
            {"remove", std::make_shared<Remove::RemoveCommand>()},
            {"upgrade", std::make_shared<Upgrade::UpgradeCommand>()},
            {"build", std::make_shared<Build::Command::BuildCommand>()},
            {"env", std::make_shared<Env::EnvCommand>()},
            {"build-external", std::make_shared<BuildExternal::BuildExternalCommand>()},
            {"export", std::make_shared<Export::ExportCommand>()},
            {"depend-info", std::make_shared<DependInfo::DependInfoCommand>()},
        };
        return t;
    }

    Span<const PackageNameAndFunction<std::shared_ptr<PathsCommand>>> get_available_commands_type_b()
    {
        static std::vector<PackageNameAndFunction<std::shared_ptr<PathsCommand>>> t = {
            {"/?", std::make_shared<Help::HelpCommand>()},
            {"help", std::make_shared<Help::HelpCommand>()},
            {"search", std::make_shared<Search::SearchCommand>()},
            {"list", std::make_shared<List::ListCommand>()},
            {"integrate", std::make_shared<Integrate::IntegrateCommand>()},
            {"owns", std::make_shared<Owns::OwnsCommand>()},
            {"update", std::make_shared<Update::UpdateCommand>()},
            {"edit", std::make_shared<Edit::EditCommand>()},
            {"create", std::make_shared<Create::CreateCommand>()},
            {"cache", std::make_shared<Cache::CacheCommand>()},
            {"portsdiff", std::make_shared<PortsDiff::PortsDiffCommand>()},
            {"autocomplete", std::make_shared<Autocomplete::AutocompleteCommand>()},
            {"hash", std::make_shared<Hash::HashCommand>()},
            {"fetch", std::make_shared<Fetch::FetchCommand>()},
            {"x-ci-clean", std::make_shared<CIClean::CICleanCommand>()},
            {"x-history", std::make_shared<PortHistory::PortHistoryCommand>()},
            {"x-vsinstances", std::make_shared<X_VSInstances::X_VSInstancesCommand>()},
            {"x-format-manifest", std::make_shared<FormatManifest::FormatManifestCommand>()},
        };
        return t;
    }

    Span<const PackageNameAndFunction<std::shared_ptr<BasicCommand>>> get_available_commands_type_c()
    {
        static std::vector<PackageNameAndFunction<std::shared_ptr<BasicCommand>>> t = {
            {"version", std::make_shared<Version::VersionCommand>()},
            {"contact", std::make_shared<Contact::ContactCommand>()},
        };
        return t;
    }
}
