#include <sstream>

#include "beeper.h"
#include "mors.h"

class SoundMorse : public mors {
public:
  SoundMorse();
  virtual ~SoundMorse();
  void setFrequency(const DWORD& freq);
  void setPause(const DWORD& pauseTime);
  void setDotTime(const DWORD& dotTime);
  void setDashTime(const DWORD& dashTime);
  void setCharPause(const DWORD& charPauseTime);
  SoundMorse& operator<<(SoundMorse& (*pause)(SoundMorse &));
  template <class T>
  SoundMorse& operator<<(const T& paramStr);

  void morseIt(const std::string& data);
  void configure(std::vector<std::string> parameters);
protected:
  void beepIt(const std::string& word);
  void beepChar(const char& c);
  void beepSpace(const char& c);

  DWORD mFreq;
  DWORD mCharPauseTime;
  DWORD mPauseTime;
  DWORD mDotTime;
  DWORD mDashTime;
  beeper* mBeeper;
};

SoundMorse& pause(SoundMorse &m);
