#include <string>
#include <sstream>
#include <iterator>

#include "configurationParser.h"

void ConfigurationParser::configure(std::string cfg, mors* mors) {
    try {
        std::stringstream ss(cfg);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> configurationVector(begin, end);
        mors->configure(configurationVector);
    } catch (std::exception* ex) {
        throw ex;
    }
}