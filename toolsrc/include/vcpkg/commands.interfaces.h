#pragma once

#include <vcpkg/vcpkgcmdarguments.h>
#include <vcpkg/vcpkgpaths.h>

namespace vcpkg::Commands
{
    enum class DryRun : bool
    {
        No,
        Yes,
    };

    struct Command
    {
        virtual ~Command() = default;
    };

    struct BasicCommand : Command
    {
    };
}
