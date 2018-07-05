#ifndef _ZAMEK_IO_H
#define _ZAMEK_IO_H

#include "zamek-globals.h"

class ZamekIo {
  public:
    void centerButtonInterrupt();
    void leftButtonPressed();
    void rightButtonPressed();
    void upButtonPressed();
    void downButtonPressed();
    void centerButtonPressed();
    int handleButtonChecker();
};

#endif /* _ZAMEK_IO_H */
