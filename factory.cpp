#include "factory.h"
#include "soundMorse.h"
#include "diskMorse.h"
#include "stdCoutMorse.h"
#include "capsLockMorse.h"
#include "configurationParser.h"

factory::factory() : currentType(MorseType::beep) {
    setOutput(currentType);
}

factory::~factory() {
    if (m != nullptr) {
         delete m;
    }
}

void factory::setConfiguration(const std::string& conf) {
    currentConfiguration = conf;
}

std::string factory::getCurrentconfiguration() const {
    return currentConfiguration;
}

void factory::setExternalInfo(const std::string& exInfo) {
    try {
        if (m == nullptr) {
            setOutput(currentType);        
        }
        ConfigurationParser::configure(exInfo, m);
    } catch (std::exception* ex) {
        throw ex;
    }
}

void factory::convert(const std::string& msg) {
    m->morseIt(msg);
}

void factory::convert(const double& msg) {
    std::stringstream ss;
    ss << msg;
    m->morseIt(ss.str());
}

void factory::convert(const int& msg) {
    std::stringstream ss;
    ss << msg;
    m->morseIt(ss.str());
}

void factory::setOutput(const MorseType& type) {
    if (currentType == type && m != nullptr) {
        return;
    }
    currentType = type;
    switch(currentType) {
        case MorseType::beep:
          m = new SoundMorse();
          break;
        case MorseType::disk:
          m = new DiskMorse();
          break;
        case MorseType::console:
          m = new StdCoutMorse();
          break;
        case MorseType::capsLock:
          m = new CapsLockMorse();
          break;
    }
    try {
        ConfigurationParser::configure(getCurrentconfiguration(), m);
    } catch (std::exception* ex) {
        throw ex;
    }
}

mors* factory::getMorse() const {
    return m;
}

factory::MorseType factory::getType() const {
    return currentType;
}

factory::factory(const factory& other) {
    setOutput(other.getType());
}

factory& factory::operator=(const factory& other) {
    setOutput(other.getType());
    return *this;
}