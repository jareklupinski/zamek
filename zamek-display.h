#ifndef _ZAMEK_DISPLAY_H_
#define _ZAMEK_DISPLAY_H_

#include "zamek-globals.h"

#define BLACK 0
#define WHITE 1
#define INVERSE 2
#define SSD1306_128_32
#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 32
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22
#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_CHARGEPUMP 0x8D
#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

typedef volatile uint8_t PortReg;
typedef uint8_t PortMask;

class ZamekDisplay : public Print {
  public:
    ZamekDisplay(int8_t SID, int8_t SCLK, int8_t DC, int8_t RST, int8_t CS);
    void renderPinScreen();
    void renderMainScreen();
    void renderEditScreen();
    void drawScreen();
    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
    void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
    void setCursor(int16_t x, int16_t y);
    void setTextColor(uint16_t c);
    void setTextColor(uint16_t c, uint16_t bg);
    void setTextSize(uint8_t s);
    void begin(uint8_t switchvcc = SSD1306_SWITCHCAPVCC);
    void ssd1306_command(uint8_t c);
    void clearDisplay(void);
    void display();
    void dim(boolean dim);
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void wipeScreen();
    void drawBatteryIndicator();
    void drawFastVLine(int16_t x, int16_t __y, int16_t __h, uint16_t color);
    virtual size_t write(uint8_t);
  protected:
    int16_t  _width, _height, cursor_x, cursor_y;
    uint16_t textcolor, textbgcolor;
    uint8_t textsize, rotation;
    boolean wrap;
  private:
    int8_t _vccstate, sid, sclk, dc, rst, cs;
    PortReg *mosiport, *clkport, *csport, *dcport;
    PortMask mosipinmask, clkpinmask, cspinmask, dcpinmask;
    void fastSPIwrite(uint8_t c);
};

#endif /* _ZAMEK_DISPLAY_H_ */
