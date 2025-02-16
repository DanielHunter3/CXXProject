#pragma once

#include <string>

#include "resulthandler.hpp"

enum Function {
    Cat, Pwd, Rename,
    Copy, Cut, Echo, 
    Perm, Reperm, Ls, 
    Cd, Mkdir, Rmdir, 
    Cls, Rm, Touch,
    Exit
};

bool isValidFunction(const Function& aCommand) noexcept;

Result<Function> stringToFunction(const std::string&) noexcept;