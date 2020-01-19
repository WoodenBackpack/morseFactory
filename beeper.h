#include <windows.h>

class beeper {
public:
  void beep(const DWORD& freq, const DWORD& time) const;
  void sleep(const DWORD& time) const;
};