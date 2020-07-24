#pragma once

#include <vcpkg/commands.interfaces.h>

namespace vcpkg::Commands
{
    namespace Contact
    {
        struct ContactCommand : BasicCommand
        {
            void perform_and_exit(const VcpkgCmdArguments& args, Files::Filesystem& fs) const override;
        };
        extern const CommandStructure COMMAND_STRUCTURE;
        const std::string& email();
    }
}
