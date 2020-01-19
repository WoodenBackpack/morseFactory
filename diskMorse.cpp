#include "diskMorse.h"

#include <fstream>
#include <exception>
#include <sstream>
#include <iterator>
#include <vector>

DiskMorse::DiskMorse() : currentFileName("") {

}

void DiskMorse::morseIt(const std::string& data) {
    if (currentFileName.empty()) {
        //raise std::exception();
    }
    std::ofstream ofs(currentFileName);
    for (int i = 0; i < data.length(); ++i) {
        const std::string& c = convertToMorse(data[i]);
        ofs << c << "\n";
    }
}

void DiskMorse::configure(std::vector<std::string> parameters) {
    if (parameters.size() < 1) {
        throw WrongConfigurationException();
    }
    setConfigurationData(parameters);
    currentFileName = parameters[0];
}

DiskMorse::DiskMorse(const DiskMorse& other) {
    configure(other.getConfigurationData());
}

DiskMorse& DiskMorse::operator=(const DiskMorse& other) {
    configure(other.getConfigurationData());
    return *this;
}

std::string DiskMorse::getFile() const {
    return currentFileName;
}

void DiskMorse::setFile(const std::string& fileName) {
    currentFileName = fileName;
}