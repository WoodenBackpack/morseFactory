#include "stdCoutMorse.h"
#include <iostream>

void StdCoutMorse::morseIt(const std::string& data) {
      for (int i = 0; i < data.length(); ++i) {
        const std::string& c = convertToMorse(data[i]);
        std::cout << c << "\n";
    }
}

void StdCoutMorse::configure(std::vector<std::string> parameters) {
    setConfigurationData(parameters);
}


StdCoutMorse::StdCoutMorse(const StdCoutMorse& other) {

}

StdCoutMorse& StdCoutMorse::operator=(const StdCoutMorse& other) {
    return *this;
}