#ifndef _ZAMEK_SECURITY_H
#define _ZAMEK_SECURITY_H

#include "zamek-globals.h"

class ZamekSecurity {
  public:
    void lock();
    void unlock();
  private:
    void sanitize( byte *s );
};

#endif /* ZAMEK_SECURITY_H */
