#pragma once

#include <vcpkg/commands.interfaces.h>

namespace vcpkg::Commands
{
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
}
