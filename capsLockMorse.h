#include "mors.h"
#include <windows.h>

class CapsLockMorse : public mors {
public:
  CapsLockMorse();
  virtual ~CapsLockMorse(){}
  void morseIt(const std::string& data);
  void configure(std::vector<std::string> parameters);
  CapsLockMorse(const CapsLockMorse& other);
  CapsLockMorse& operator=(const CapsLockMorse& other);

  DWORD getCharPauseTime() const;
  DWORD getPauseTime() const;
  DWORD getDotTime() const;
  DWORD getDashTime() const;

  void setCharPauseTime(const DWORD& time);
  void setPauseTime(const DWORD& time);
  void setDotTime(const DWORD& time);
  void setDashTime(const DWORD& time);

protected:
  void flickCapsLock(const std::string& cfg);
  DWORD mCharPauseTime;
  DWORD mPauseTime;
  DWORD mDotTime;
  DWORD mDashTime;
};