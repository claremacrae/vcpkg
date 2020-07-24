#pragma once

#include <vcpkg/commands.interfaces.h>

namespace vcpkg::Commands
{
    namespace Cache
    {
        struct CacheCommand : PathsCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths) const override;
        };

        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }
}
