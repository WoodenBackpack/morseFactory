#include "beeper.h"

void beeper::beep(const DWORD& freq, const DWORD& time) const {
  Beep(freq, time);
}

void beeper::sleep(const DWORD& time) const {
  Sleep(time);
}