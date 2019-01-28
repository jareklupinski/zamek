#ifndef _ZAMEK_UTILS_H
#define _ZAMEK_UTILS_H

#include "zamek-globals.h"

class ZamekUtils {
  public:
    void refreshBatteryLevel();
    uint8_t waitForPress();
    void handleSerial();
    void typePassword();
    unsigned long calculateCrc();
    void clearAccount();
    void randomEntry();
    void throwErrorScreen();
};

#endif /* _ZAMEK_UTILS_H */
