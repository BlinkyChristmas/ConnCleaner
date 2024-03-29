//Copyright © 2024 Charles Kerr. All rights reserved.

#ifndef ConnectionStatus_hpp
#define ConnectionStatus_hpp

#include <cstdint>
#include <filesystem>
#include <istream>
#include <string>
#include <unordered_map>
#include <deque>
#include <vector>
#include "LogContainer.hpp"

//======================================================================
class ConnectionStatus {
    
    std::unordered_map<std::string, LogContainer> connectionStatus ;
    
public:
    ConnectionStatus()  = default ;
    ConnectionStatus(const std::filesystem::path &filepath);
    
    auto load(const std::filesystem::path &filepath) -> bool ;
    
    auto size() const -> size_t ;
    auto empty() const -> bool ;
    
    auto keys() const -> std::vector<std::string> ;
    
    auto operator[](const std::string &key) const -> const LogContainer& ;
    auto operator[](const std::string &key)  -> LogContainer& ;
    auto save(const std::filesystem::path &path) -> bool ;
};

#endif /* ConnectionStatus_hpp */
