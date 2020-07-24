#pragma once

#include <vcpkg/build.h>
#include <vcpkg/dependencies.h>
#include <vcpkg/statusparagraphs.h>
#include <vcpkg/vcpkgcmdarguments.h>
#include <vcpkg/vcpkgpaths.h>

#include <array>
#include <map>
#include <vector>

namespace vcpkg::Commands
{
    using CommandTypeA = void (*)(const VcpkgCmdArguments& args, const VcpkgPaths& paths, Triplet default_triplet);
    using CommandTypeB = void (*)(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    using CommandTypeC = void (*)(const VcpkgCmdArguments& args, Files::Filesystem& fs);

    struct Command
    {
        virtual ~Command() = default;
    };

    struct BasicCommand : Command
    {
    };

    struct PathsCommand : Command
    {
        virtual void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths) const = 0;
    };

    struct TripletCommand : Command
    {
        virtual void perform_and_exit(const VcpkgCmdArguments& args,
                                      const VcpkgPaths& paths,
                                      Triplet default_triplet) const = 0;
    };

    enum class DryRun : bool
    {
        No,
        Yes,
    };

    namespace BuildExternal
    {
        struct BuildExternalCommand : TripletCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args,
                                  const VcpkgPaths& paths,
                                  Triplet default_triplet) const override;
        };
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths, Triplet default_triplet);
    }

    namespace CI
    {
        struct CICommand : TripletCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args,
                                  const VcpkgPaths& paths,
                                  Triplet default_triplet) const override;
        };
        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths, Triplet default_triplet);
    }

    namespace CIClean
    {
        struct CICleanCommand : PathsCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths) const override;
        };
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace Env
    {
        struct EnvCommand : TripletCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args,
                                  const VcpkgPaths& paths,
                                  Triplet default_triplet) const override;
        };
        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths, Triplet default_triplet);
    }

    namespace Create
    {
        struct CreateCommand : PathsCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths) const override;
        };
        extern const CommandStructure COMMAND_STRUCTURE;
        int perform(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace Upgrade
    {
        struct UpgradeCommand : TripletCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args,
                                  const VcpkgPaths& paths,
                                  Triplet default_triplet) const override;
        };

        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths, Triplet default_triplet);
    }

    namespace Edit
    {
        struct EditCommand : PathsCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths) const override;
        };
        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace DependInfo
    {
        struct DependInfoCommand : TripletCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args,
                                  const VcpkgPaths& paths,
                                  Triplet default_triplet) const override;
        };

        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths, Triplet default_triplet);
    }

    namespace Search
    {
        struct SearchCommand : PathsCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths) const override;
        };
        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace List
    {
        struct ListCommand : PathsCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths) const override;
        };
        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace Owns
    {
        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace Cache
    {
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace Integrate
    {
        extern const CommandStructure COMMAND_STRUCTURE;

        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
        void append_helpstring(HelpTableFormatter& table);
        std::string get_helpstring();
    }

    namespace PortsDiff
    {
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace PortHistory
    {
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace Autocomplete
    {
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace Version
    {
        const char* base_version();
        const std::string& version();
        void warn_if_vcpkg_version_mismatch(const VcpkgPaths& paths);
        void perform_and_exit(const VcpkgCmdArguments& args, Files::Filesystem& fs);
    }

    namespace Contact
    {
        extern const CommandStructure COMMAND_STRUCTURE;
        const std::string& email();
        void perform_and_exit(const VcpkgCmdArguments& args, Files::Filesystem& fs);
    }

    namespace X_VSInstances
    {
        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace Hash
    {
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace Fetch
    {
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace FormatManifest
    {
        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }

    namespace SetInstalled
    {
        struct SetInstalledCommand : TripletCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args,
                                  const VcpkgPaths& paths,
                                  Triplet default_triplet) const override;
        };

        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit_ex(const VcpkgCmdArguments& args,
                                 const VcpkgPaths& paths,
                                 const PortFileProvider::PathsPortFileProvider& provider,
                                 IBinaryProvider& binary_provider,
                                 const CMakeVars::CMakeVarProvider& cmake_vars,
                                 const std::vector<FullPackageSpec>& specs,
                                 const Build::BuildPackageOptions& install_plan_options,
                                 DryRun dry_run,
                                 const Optional<fs::path>& pkgsconfig_path);
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths, Triplet default_triplet);
    }

    template<class T>
    struct PackageNameAndFunction
    {
        std::string name;
        T function;
    };

    Span<const PackageNameAndFunction<CommandTypeA>> get_available_commands_type_a();
    Span<const PackageNameAndFunction<CommandTypeB>> get_available_commands_type_b();
    Span<const PackageNameAndFunction<CommandTypeC>> get_available_commands_type_c();

    template<typename T>
    T find(const std::string& command_name, const std::vector<PackageNameAndFunction<T>> available_commands)
    {
        for (const PackageNameAndFunction<T>& cmd : available_commands)
        {
            if (cmd.name == command_name)
            {
                return cmd.function;
            }
        }

        // not found
        return nullptr;
    }
}
