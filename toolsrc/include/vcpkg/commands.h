#pragma once

#include <vcpkg/build.h>
#include <vcpkg/commands.interfaces.h>
#include <vcpkg/dependencies.h>
#include <vcpkg/statusparagraphs.h>
#include <vcpkg/vcpkgcmdarguments.h>
#include <vcpkg/vcpkgpaths.h>

#include <array>
#include <map>
#include <vector>

namespace vcpkg::Commands
{
    template<class T>
    struct PackageNameAndFunction
    {
        std::string name;
        T function;
    };

    Span<const PackageNameAndFunction<std::shared_ptr<TripletCommand>>> get_available_commands_type_a();
    Span<const PackageNameAndFunction<std::shared_ptr<PathsCommand>>> get_available_commands_type_b();
    Span<const PackageNameAndFunction<std::shared_ptr<BasicCommand>>> get_available_commands_type_c();

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
