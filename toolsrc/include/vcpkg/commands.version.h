#pragma once

#include <vcpkg/commands.interfaces.h>

namespace vcpkg::Commands
{
    namespace Version
    {
        const char* base_version();
        const std::string& version();
        void warn_if_vcpkg_version_mismatch(const VcpkgPaths& paths);
        void perform_and_exit(const VcpkgCmdArguments& args, Files::Filesystem& fs);
    }
}
