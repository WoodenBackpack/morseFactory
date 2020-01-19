#include <windows.h>
#include <sstream>
#include <iterator>
#include <stdlib.h>

#include "soundMorse.h"

SoundMorse::SoundMorse() : mFreq(1000), mPauseTime(300), mDotTime(100), mDashTime(200),
                 mCharPauseTime(100) {
    mBeeper = new beeper();
}

SoundMorse::~SoundMorse() {
    delete mBeeper;
}

void SoundMorse::setFrequency(const DWORD &freq) {
    mFreq = freq;
}
void SoundMorse::setPause(const DWORD &pauseTime) {
    mPauseTime = pauseTime;
}
void SoundMorse::setDotTime(const DWORD &dotTime) {
    mDotTime = dotTime;
}
void SoundMorse::setDashTime(const DWORD &dashTime) {
    mDashTime = dashTime;
}
void SoundMorse::setCharPause(const DWORD &charPauseTime) {
    mCharPauseTime = charPauseTime;
}

SoundMorse& SoundMorse::operator<<(SoundMorse& (*pause)(SoundMorse &)) {
	mBeeper->sleep(mCharPauseTime);
	return *this;
}

// Manipulator is not a memeber of morse
SoundMorse& pause(SoundMorse& m) {
	return m;
}
  
template <class T>
SoundMorse& SoundMorse::operator<<(const T& paramStr) {
    std::ostringstream ss;
    ss << paramStr;
    beepIt(ss.str());
    return *this;
}

void SoundMorse::morseIt(const std::string& data) {
    beepIt(data);
}

void SoundMorse::beepChar(const char& c) {
    std::string converted = convertToMorse(c);
    for (unsigned int j = 0; j < converted.length(); ++j) {
        char character = converted.at(j);
        if (character == dot) {
            mBeeper->beep(mFreq, mDotTime);
        } else if (character == dash) {
            mBeeper->beep(mFreq, mDashTime);
        }
    }
}

void SoundMorse::beepSpace(const char& c) {
    mBeeper->sleep(mPauseTime);
    mBeeper->sleep(mCharPauseTime);
}

void SoundMorse::beepIt(const std::string& word) {
    for (int i = 0; i < word.length(); ++i) {
        char c = word.at(i);
        if (c == space) {
            beepSpace(c);
            continue;
        }
        beepChar(c);
        mBeeper->sleep(mCharPauseTime);
    }
}

void SoundMorse::configure(std::vector<std::string> parameters) {
    if (parameters.size() < 5) {
        throw WrongConfigurationException();
    }
    setConfigurationData(parameters);
    mFreq = atoi(parameters[0].c_str());
    mPauseTime = atoi(parameters[1].c_str());
    mDotTime = atoi(parameters[2].c_str());
    mDashTime = atoi(parameters[3].c_str());
    mCharPauseTime = atoi(parameters[4].c_str());
}