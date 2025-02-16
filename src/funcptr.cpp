// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <map>
#include <cstdlib>
#include <memory>
#include <string>

#include "header/communist.hpp"
#include "header/element.hpp"
#include "header/funcptr.hpp"

using namespace filemaneger;

Result<Result<StringFunction>> getElementFunction(const std::vector<std::string>& arguments) noexcept {
    std::map<Function, Result<StringFunction>> functions {
        {Rename, [arguments]() {
            if (arguments.size() < 2)
                return ResultError {RangeOutError};
            element::rename(arguments[1], arguments[2]);
            return "\0";
        }},
        {Copy, [arguments]() {
            element::copy(arguments[1], arguments[2]);
            return "\0";
        }},
        {Pwd, [arguments]() {
            return element::pwd(arguments[1]);
        }}
    };
    if (stringToFunction(arguments[0]).is_ok() && 
        functions.find(stringToFunction(arguments[0]).ok()) != functions.end()) {
            return functions[stringToFunction(arguments[0]).ok()];
    }
    return ResultError {RangeOutError, "Command not found"};
}

StringFunction getFunctionOfFile(const std::vector<std::string>& arguments) {
    auto functions = std::make_unique<std::map<Function, StringFunction>>();
    *functions = {
        {Cat, [arguments]() {
            return filemaneger::file::readFile(arguments.at(1));
        }},
        {Echo, [arguments]() {
            file::writeFile(arguments.at(1), arguments.at(2), std::ios::out);
            return "\0";
        }},
        {Touch, [arguments](){
            file::createFile(arguments.at(1));
            return "\0";
        }},
        {Rm, [arguments](){
            file::deleteFile(arguments.at(1));
            return "\0";
        }}
    };
    return functions->at(stringToFunction(arguments.at(0)));
}

VectorStringFunction getFunctionOfDirectoryVector(const std::vector<std::string>& arguments) 
{
    auto functions = std::make_unique<std::map<Function, VectorStringFunction>>(); 
    *functions = {
        {Ls, [arguments]() {
            return getFilesAndDirectories(".");
        }},
        {Cd, [arguments]() {
            directory::changeDirectory(arguments.at(1));
            return getFilesAndDirectories(arguments.at(1));
        }},
    };
    return functions->at(stringToFunction(arguments.at(0)));
}

VoidFunction getFunctionOfDirectoryVoid(const std::vector<std::string>& arguments) 
{
    auto functions = std::make_unique<std::map<Function, VoidFunction>>(); 
    *functions = {
        {Mkdir, [arguments]() { directory::createDirectory(arguments.at(1)); }},
        {Rmdir, [arguments]() { directory::deleteDirectory(arguments.at(1)); }},
        {Cls, []() {
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
        }}
    };
    return functions->at(stringToFunction(arguments.at(0)));
}

// Все функции, кроме getFunctionOfDirectoryVector
StringFunction getStringUniversalFunction(const std::vector<std::string>& arguments) 
{
    auto functions = std::make_unique<std::map<Function, StringFunction>>();
    *functions = {
        {Rename, [arguments]() {
            element::rename(arguments.at(1), arguments.at(2));
            return "\0";
        }},
        {Copy, [arguments]() {
            element::copy(arguments.at(1), arguments.at(2));
            return "\0";
        }},
        {Pwd, [arguments]() {
            return element::pwd(arguments.at(1));
        }},
        {Cat, [arguments]() {
            return filemaneger::file::readFile(arguments.at(1));
        }},
        {Echo, [arguments]() {
            file::writeFile(arguments.at(1), arguments.at(2), std::ios::out);
            return "\0";
        }},
        {Touch, [arguments](){
            file::createFile(arguments.at(1));
            return "\0";
        }},
        {Rm, [arguments](){
            file::deleteFile(arguments.at(1));
            return "\0";
        }},
        {Mkdir, [arguments]() { 
            directory::createDirectory(arguments.at(1)); 
            return "\0";
        }},
        {Rmdir, [arguments]() { 
            directory::deleteDirectory(arguments.at(1)); 
            return "\0";
        }},
        {Cls, []() {
            #ifdef _WIN32
                std::system("cls");
            #else
                std::system("clear");
            #endif
            return "\0";
        }}
    };
    return functions->at(stringToFunction(arguments.at(0)));
}