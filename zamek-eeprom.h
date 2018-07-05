#ifndef _ZAMEK_EEPROM_H
#define _ZAMEK_EEPROM_H

#include "zamek-globals.h"

class ZamekEeprom {
  public:
    void readEntry( byte *entry );
    void writeEntry( byte *entry );
  private:
    uint8_t present();
};

#endif /* _ZAMEK_EEPROM_H */
