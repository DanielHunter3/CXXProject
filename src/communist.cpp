// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <array>
#include <map>

#include "header/details.hpp"
#include "header/communist.hpp"

bool isValidFunction(const Function& aCommand) noexcept {
    std::array<Function, 16> allCommands = {
        Cat, Pwd, Rename,
        Copy, Cut, Echo, 
        Perm, Reperm, Ls, 
        Cd, Mkdir, Rmdir, 
        Cls, Rm, Touch,
        Exit
    };
    if (in(allCommands, aCommand)) {
        return true;
    }
    return false;
}

Result<Function> stringToFunction(const std::string& strfunc) noexcept {
    std::map<std::string, Function> map {
        {"cat", Cat}, {"pwd", Pwd}, {"rename", Rename}, 
        {"cp", Copy}, {"cut", Cut}, {"echo", Echo},
        {"perm", Perm}, {"reperm", Reperm}, {"ls", Ls}, 
        {"cd", Cd}, {"mkdir", Mkdir}, {"rmdir", Rmdir}, 
        {"cls", Cls}, {"rm", Rm}, {"touch", Touch},
        {"exit", Exit}
    };
    if (map.find(strfunc) == map.end()) {
        return ResultError {NotFoundError, "Command is not found"};
    }
    return map[strfunc];
}