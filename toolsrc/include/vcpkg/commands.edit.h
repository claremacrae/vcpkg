#pragma once

#include <vcpkg/commands.interfaces.h>

namespace vcpkg::Commands
{
    namespace Edit
    {
        struct EditCommand : PathsCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths) const override;
        };
        extern const CommandStructure COMMAND_STRUCTURE;
        void perform_and_exit(const VcpkgCmdArguments& args, const VcpkgPaths& paths);
    }
}
