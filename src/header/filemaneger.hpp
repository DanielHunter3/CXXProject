#pragma once

#include <vector>
#include <string>

std::vector<std::string> getFilesInDirectory(const std::string& directoryPath) noexcept;

std::vector<std::string> getDirectoriesInDirectory(const std::string& directoryPath) noexcept;

std::vector<std::string> getFilesAndDirectories(const std::string& directoryPath) noexcept;

std::string getCurrentWorkingDirectory() noexcept;