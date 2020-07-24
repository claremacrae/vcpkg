#include "pch.h"

#include <vcpkg/base/system.print.h>

#include <vcpkg/build.h>
#include <vcpkg/commands.h>
#include <vcpkg/export.h>
#include <vcpkg/help.h>
#include <vcpkg/install.h>
#include <vcpkg/remove.h>
#include <vcpkg/update.h>

namespace vcpkg::Commands
{
    Span<const PackageNameAndFunction<CommandTypeA>> get_available_commands_type_a()
    {
        static std::vector<PackageNameAndFunction<CommandTypeA>> t = {
            {"install", &Install::perform_and_exit},
            {"x-set-installed", &SetInstalled::perform_and_exit},
            {"ci", &CI::perform_and_exit},
            {"remove", &Remove::perform_and_exit},
            {"upgrade", &Upgrade::perform_and_exit},
            {"build", &Build::Command::perform_and_exit},
            {"env", &Env::perform_and_exit},
            {"build-external", &BuildExternal::perform_and_exit},
            {"export", &Export::perform_and_exit},
            {"depend-info", &DependInfo::perform_and_exit},
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
