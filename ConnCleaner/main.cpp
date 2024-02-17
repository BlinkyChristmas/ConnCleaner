
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <filesystem>

#include "ConnectionStatus.hpp"
using namespace std::string_literals ;

// ========================================================================
int main(int argc, const char * argv[]) {

    auto exitcode = EXIT_SUCCESS ;
    try {
        if (argc != 2) {
            throw std::runtime_error("connect log path required as input arguments") ;
        }
        auto logfile = std::filesystem::path(argv[1]) ;
        if (!std::filesystem::exists(logfile)) {
            std::clog << "Connection log does not exist, nothing to be done: "s << logfile.string() << std::endl;
            return exitcode ;
        }
        auto status = ConnectionStatus(logfile) ;
        if (!status.save(logfile)) {
            throw std::runtime_error("Unable to saee to: "s + logfile.string()) ;
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        exitcode = EXIT_FAILURE ;
    }
    catch (...) {
        std::cerr << "Unknown error!" << std::endl;
        exitcode = EXIT_FAILURE ;
    }
    return exitcode;
}
