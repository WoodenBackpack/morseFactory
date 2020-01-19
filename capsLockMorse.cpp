#include "capsLockMorse.h"

#include <sstream>
#include <iterator>
#include <vector>

CapsLockMorse::CapsLockMorse() : mCharPauseTime(200), mPauseTime(100), 
    mDotTime(100), mDashTime(200) {
}

void CapsLockMorse::morseIt(const std::string& data) {
    for (int i = 0 ; i < data.length(); ++i) {
        std::string converted = convertToMorse(data[i]);
        flickCapsLock(converted);
    }
}

  void CapsLockMorse::configure(std::vector<std::string> parameters) {
    if (parameters.size() < 4) {
        throw WrongConfigurationException();
    }
    setConfigurationData(parameters);
    mPauseTime = atoi(parameters[0].c_str());
    mDotTime = atoi(parameters[1].c_str());
    mDashTime = atoi(parameters[2].c_str());
    mCharPauseTime = atoi(parameters[3].c_str());
}

void CapsLockMorse::flickCapsLock(const std::string& morseChar) {
	INPUT in[2];                                //przygotuj strukture na dwa zdarzenia in[0] wcisniecie klawisza
												//in[1] wycisniecie klawisza
	in[0].type = INPUT_KEYBOARD;                //wcisniecie klawisza na klawiaturze
	in[0].ki.wVk = VK_CAPITAL;                    //jaki klawisz - CAPSLOCK
	in[0].ki.wScan = 0;
	in[0].ki.time = 0;
	in[0].ki.dwFlags = 0;                        //jesli 0 to akcja wcisniecia klawisza
	in[0].ki.dwExtraInfo = 0;

	in[1] = in[0];                                //szykujemy strukture na wycisniecie klawisza. Jest taka sama poza
	in[1].ki.dwFlags = KEYEVENTF_KEYUP;            //tym ze teraz wykonujemy akacje wycisniecia klawisza

    for (int i = 0 ; i < morseChar.length(); ++i) {
        if (morseChar[i] == space) {
            ::Sleep(mPauseTime);
            continue;
        }  
        ::SendInput(2, in, sizeof(INPUT));        
        if (morseChar[i] == dot) {
            ::Sleep(mDotTime);
        } else if (morseChar[i] == dash) {
            ::Sleep(mDashTime);
        }
        ::SendInput(2, in, sizeof(INPUT));        
        ::Sleep(mCharPauseTime);
    }
}

CapsLockMorse::CapsLockMorse(const CapsLockMorse& other) {
    configure(other.getConfigurationData());
}

CapsLockMorse& CapsLockMorse::operator=(const CapsLockMorse& other) {
    configure(other.getConfigurationData());
    return *this;
}

void CapsLockMorse::setCharPauseTime(const DWORD& time) {
    mCharPauseTime = time;
}

void CapsLockMorse::setPauseTime(const DWORD& time) {
    mPauseTime = time;
}

void CapsLockMorse::setDotTime(const DWORD& time) {
    mDotTime = time;
}

void CapsLockMorse::setDashTime(const DWORD& time) {
    mDashTime = time;
}

DWORD CapsLockMorse::getCharPauseTime() const {
    return mCharPauseTime;
}
DWORD CapsLockMorse::getPauseTime() const {
    return mPauseTime;
}
DWORD CapsLockMorse::getDotTime() const {
    return mDotTime;
}
DWORD CapsLockMorse::getDashTime() const {
    return mDashTime;
}