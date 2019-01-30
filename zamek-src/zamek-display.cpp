#include "zamek-display.h"

GLOBAL_VARIABLES

static uint8_t buffer[ 512 ] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x20, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0xE0, 0xF0, 0x90, 0x80, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x10, 0x10, 0xF0, 0x80, 0x80, 0xF0, 0x10, 0x10, 0xF0, 0x80, 0x80, 0xF0, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0xC3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x18, 0x38, 0x3C, 0x1C, 0x1E, 0x0E, 0x07, 0x07, 0xC3, 0x3F, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xF8, 0xF8, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x80, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC0, 0x20, 0x10, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x60, 0x60, 0xE0, 0xF0, 0x70, 0x39, 0x3E, 0x1C, 0x18, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x80, 0x00, 0x00, 0x00, 0x10, 0x18, 0x1F, 0x1F, 0x18, 0x10, 0x00, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0x03, 0xFC, 0x03, 0x00, 0x00, 0x03, 0xFC, 0x00, 0x00, 0x00, 0xFE, 0x11, 0x10, 0x10, 0x10, 0x10, 0x0F, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x03, 0x0C, 0x30, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00 };

void ZamekDisplay::renderPinScreen() {          //put the PIN Screen in the buffer
  wipeScreen();
  setTextSize( 3 );
  for ( int i = 0; i < pinIndex; i++ ) {
    if ( 82 - ( 17 * i ) > -4 ) { //ugh
      setCursor( 82 - ( 17 * i ), 6 );
      print( pinArray[ pinIndex - ( i + 1 ) ] );
    }
  }
  drawBitmap( 104, 0, pinFrame, 24, 32, WHITE );
  setCursor( 109, 6 );
  setTextColor( BLACK, WHITE );
  print( numpadIndex );
}

void ZamekDisplay::renderMainScreen() {         //put the Main Screen in the buffer
  if ( programPosition == MAIN_INDEX ) {
    drawBitmap( 0, 0, arrows, 24, 8, WHITE );
    setTextColor( BLACK, WHITE );
  }
  else {
    drawBitmap( 0, 0, arrows, 24, 8, BLACK );
    setTextColor( WHITE );
  }
  setCursor( 6, 0 );
  print( siteIndex + 1 );
  setTextColor( WHITE );
  setCursor( 28, 0 );
  
    print( minLevel );
    write( '-' );
    print( batteryLevel );
    write( '-' );
    print( maxLevel );
  
  /*
    if ( USBSTA & ( 1 << VBUS )){
    setCursor( 32, 0 );
    setTextColor( WHITE );
    print( "Type" );
    }
  */
  drawBatteryIndicator();
  setCursor( 0, 8 );
  if ( programPosition == MAIN_SITE ) setTextColor( BLACK, WHITE );
  else setTextColor( WHITE );
  print("Site");
  setTextColor( WHITE );
  print(":");
  for ( int i = 0; i < 16; i++ ) print( currentSite[ i ] );
  setCursor( 0, 16 );
  if ( programPosition == MAIN_USER ) setTextColor( BLACK, WHITE );
  else setTextColor( WHITE );
  print("User");
  setTextColor( WHITE );
  print(":");
  for ( int i = 0; i < 16; i++ ) print( currentUser[ i ] );
  setCursor( 0, 24 );
  if ( programPosition == MAIN_PASS ) setTextColor( BLACK, WHITE );
  else setTextColor( WHITE );
  print("Pass");
  setTextColor( WHITE );
  print(":");
  for ( int i = 0; i < 16; i++ ) print( currentPass[ i ] );
}

void ZamekDisplay::renderEditScreen() {         //put the Edit Screen in the buffer
  switch ( typeIndex ) {
    case 0: print("Site:"); break;
    case 1: print("User:"); break;
    case 2: print("Pass:"); break;
  }
  for ( int i = 0; i < 16; i++ ) {
    if ( cursorIndex == i ) setTextColor( BLACK, WHITE );
    else setTextColor( WHITE );
    switch ( typeIndex ) {
      case 0: print( currentSite[ i ]); break;
      case 1: print( currentUser[ i ]); break;
      case 2: print( currentPass[ i ]); break;
    }
  }
  setTextColor( WHITE );
  print(" ");
  if ( programPosition == EDIT_LEFT_CURSOR ) setTextColor( BLACK, WHITE );
  else setTextColor( WHITE );
  print("<");
  if ( programPosition == EDIT_RIGHT_CURSOR ) setTextColor( BLACK, WHITE );
  else setTextColor( WHITE );
  print(">");
  setTextColor( WHITE );
  print(" ");
  print(" ");
  for ( int i = 0; i < 16; i++ ) {
    if (( programPosition == EDIT_KB1 ) && ( selectorIndex == i )) setTextColor( BLACK, WHITE );
    else setTextColor( WHITE );
    print( char( pgm_read_byte_near( keyboard1 + i + keyboardIndex )));
  }
  if ( programPosition == EDIT_RAND ) setTextColor( BLACK, WHITE );
  else setTextColor( WHITE );
  print("Rand");
  setTextColor( WHITE );
  print(" ");
  for ( int i = 0; i < 16; i++ ) {
    if (( programPosition == EDIT_KB2 ) && ( selectorIndex == i )) setTextColor( BLACK, WHITE );
    else setTextColor( WHITE );
    print( char( pgm_read_byte_near( keyboard2 + i + keyboardIndex )));
  }
  if ( programPosition == EDIT_BACK ) setTextColor( BLACK, WHITE );
  else setTextColor( WHITE );
  print("Save");
  setTextColor( WHITE );
  print(" ");
  for ( int i = 0; i < 16; i++ ) {
    if (( programPosition == EDIT_KB3 ) && ( selectorIndex == i )) setTextColor( BLACK, WHITE );
    else setTextColor( WHITE );
    print( char( pgm_read_byte_near( keyboard3 + i + keyboardIndex )));
  }
}

void ZamekDisplay::drawScreen() {               //draw current program state's associated screen
  wipeScreen();
  switch ( programPosition ) {
    case PIN_SCREEN:
      renderPinScreen();
      break;
    case MAIN_INDEX:
    case MAIN_SITE:
    case MAIN_USER:
    case MAIN_PASS:
      renderMainScreen();
      break;
    case EDIT_LEFT_CURSOR:
    case EDIT_RIGHT_CURSOR:
    case EDIT_RAND:
    case EDIT_BACK:
    case EDIT_KB1:
    case EDIT_KB2:
    case EDIT_KB3:
      renderEditScreen();
      break;
    default:
      zamekUtils.throwErrorScreen();
      break;
  }
  display();
}

ZamekDisplay::ZamekDisplay(int8_t SID, int8_t SCLK, int8_t DC, int8_t RST, int8_t CS) {
  _width    = SSD1306_LCDWIDTH;
  _height   = SSD1306_LCDHEIGHT;
  cursor_y  = cursor_x    = 0;
  textsize  = 1;
  textcolor = textbgcolor = 0xFFFF;
  wrap      = true;
  cs = CS;
  rst = RST;
  dc = DC;
  sclk = SCLK;
  sid = SID;
}

void ZamekDisplay::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  for (int16_t i = x; i < x + w; i++) {
    drawFastVLine(i, y, h, color);
  }
}
void ZamekDisplay::drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) {
  int16_t i, j, byteWidth = (w + 7) / 8;
  uint8_t byte;
  for (j = 0; j < h; j++) {
    for (i = 0; i < w; i++) {
      if (i & 7) byte <<= 1;
      else      byte   = pgm_read_byte(bitmap + j * byteWidth + i / 8);
      if (byte & 0x80) drawPixel(x + i, y + j, color);
    }
  }
}
size_t ZamekDisplay::write(uint8_t c) {
  if (c == '\n') {
    cursor_y += textsize * 8;
    cursor_x  = 0;
  } else if (c == '\r') {
    // skip em
  } else {
    if (wrap && ((cursor_x + textsize * 6) >= _width)) { // Heading off edge?
      cursor_x  = 0;            // Reset x to zero
      cursor_y += textsize * 8; // Advance y one line
    }
    drawChar(cursor_x, cursor_y, c, textcolor, textbgcolor, textsize);
    cursor_x += textsize * 6;
  }
  return 1;
}
void ZamekDisplay::drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) {

  if ((x >= _width)            || // Clip right
      (y >= _height)           || // Clip bottom
      ((x + 6 * size - 1) < 0) || // Clip left
      ((y + 8 * size - 1) < 0))   // Clip top
    return;

  //if(!_cp437 && (c >= 176)) c++; // Handle 'classic' charset behavior
  if (c >= 176) c++; // Handle 'classic' charset behavior

  for (int8_t i = 0; i < 6; i++ ) {
    uint8_t line;
    if (i < 5) line = pgm_read_byte(font + (c * 5) + i);
    else      line = 0x0;
    for (int8_t j = 0; j < 8; j++, line >>= 1) {
      if (line & 0x1) {
        if (size == 1) drawPixel(x + i, y + j, color);
        else          fillRect(x + (i * size), y + (j * size), size, size, color);
      } else if (bg != color) {
        if (size == 1) drawPixel(x + i, y + j, bg);
        else          fillRect(x + i * size, y + j * size, size, size, bg);
      }
    }
  }
}

void ZamekDisplay::setCursor(int16_t x, int16_t y) {
  cursor_x = x;
  cursor_y = y;
}

void ZamekDisplay::setTextSize(uint8_t s) {
  textsize = (s > 0) ? s : 1;
}

void ZamekDisplay::setTextColor(uint16_t c) {
  textcolor = textbgcolor = c;
}

void ZamekDisplay::setTextColor(uint16_t c, uint16_t b) {
  textcolor = c;
  textbgcolor = b;
}

void ZamekDisplay::begin(uint8_t vccstate) {
  _vccstate = vccstate;
  pinMode(dc, OUTPUT);
  pinMode(cs, OUTPUT);
  pinMode(sid, OUTPUT);
  pinMode(sclk, OUTPUT);
  pinMode(rst, OUTPUT);
  csport      = portOutputRegister(digitalPinToPort(cs));
  cspinmask   = digitalPinToBitMask(cs);
  dcport      = portOutputRegister(digitalPinToPort(dc));
  dcpinmask   = digitalPinToBitMask(dc);
  clkport     = portOutputRegister(digitalPinToPort(sclk));
  clkpinmask  = digitalPinToBitMask(sclk);
  mosiport    = portOutputRegister(digitalPinToPort(sid));
  mosipinmask = digitalPinToBitMask(sid);
  digitalWrite(rst, HIGH);
  delay(10);
  digitalWrite(rst, LOW);
  delay(10);
  digitalWrite(rst, HIGH);
  // Init sequence
  ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
  ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
  ssd1306_command(0x80);                                  // the suggested ratio 0x80
  ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
  ssd1306_command(SSD1306_LCDHEIGHT - 1);
  ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
  ssd1306_command(0x0);                                   // no offset
  ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
  ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
  ssd1306_command(0x14);
  ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
  ssd1306_command(0x00);                                  // 0x0 act like ks0108
  ssd1306_command(SSD1306_SEGREMAP | 0x1);
  ssd1306_command(SSD1306_COMSCANDEC);
  ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
  ssd1306_command(0x02);
  ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
  ssd1306_command(0x00);
  ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
  ssd1306_command(0xF1);
  ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
  ssd1306_command(0x40);
  ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
  ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
  ssd1306_command(SSD1306_DEACTIVATE_SCROLL);
  ssd1306_command(SSD1306_DISPLAYON);//--turn on oled panel
}

void ZamekDisplay::wipeScreen() {           //reset the OLED display
  clearDisplay();
  setCursor(0, 0);
  setTextSize(1);
  setTextColor(WHITE);
}

void ZamekDisplay::ssd1306_command(uint8_t c) {
  //*csport |= cspinmask;
  digitalWrite(cs, HIGH);
  //*dcport &= ~dcpinmask;
  digitalWrite( dc, LOW);
  //*csport &= ~cspinmask;
  digitalWrite( cs, LOW);
  fastSPIwrite(c);
  //*csport |= cspinmask;
  digitalWrite(cs, HIGH);
}

void ZamekDisplay::display(void) {
  ssd1306_command(SSD1306_COLUMNADDR);
  ssd1306_command(0);   // Column start address (0 = reset)
  ssd1306_command(SSD1306_LCDWIDTH - 1); // Column end address (127 = reset)
  ssd1306_command(SSD1306_PAGEADDR);
  ssd1306_command(0); // Page start address (0 = reset)
  ssd1306_command(3); // Page end address
  //*csport |= cspinmask;
  digitalWrite(cs, HIGH);
  //*dcport |= dcpinmask;
  digitalWrite( dc, HIGH);
  //*csport &= ~cspinmask;
  digitalWrite( cs, LOW);
  for (uint16_t i = 0; i < 512; i++) {
    fastSPIwrite(buffer[i]);
  }
  //*csport |= cspinmask;
  digitalWrite(cs, HIGH);
}

void ZamekDisplay::clearDisplay(void) {
  memset(buffer, 0, 512);
}

inline void ZamekDisplay::fastSPIwrite(uint8_t d) {
  for (uint8_t bit = 0x80; bit; bit >>= 1) {
    //*clkport &= ~clkpinmask;
    digitalWrite(sclk, LOW);
    if (d & bit) digitalWrite( sid, HIGH); // *mosiport |=  mosipinmask;
    else digitalWrite( sid, LOW);//       *mosiport &= ~mosipinmask;
    //*clkport |=  clkpinmask;
    digitalWrite(sclk, HIGH);
  }
}

void ZamekDisplay::drawPixel(int16_t x, int16_t y, uint16_t color) {
  if ((x < 0) || (x >= 128) || (y < 0) || (y >= 32))  return;
  switch (color) {
    case WHITE:    buffer[x + (y / 8)*SSD1306_LCDWIDTH] |=  (1 << (y & 7)); break;
    case BLACK:    buffer[x + (y / 8)*SSD1306_LCDWIDTH] &= ~(1 << (y & 7)); break;
    case INVERSE:  buffer[x + (y / 8)*SSD1306_LCDWIDTH] ^=  (1 << (y & 7)); break;
  }
}

void ZamekDisplay::drawBatteryIndicator() {     //draw battery state on screen
  uint8_t charging = !digitalRead( BAT_STAT_PIN );
  drawBitmap( 104, 0, battery, 24, 8, WHITE );
  uint16_t minValue = 600;
  uint16_t maxValue = 850;
  uint16_t threshold1 = ((( maxValue - minValue ) / 3 ) + minValue );
  uint16_t threshold2 = (((( maxValue - minValue ) * 2 ) / 3 ) + minValue );
  if ( batteryLevel < threshold1 ) {
    if ( charging && (( millis() / 1000 ) % 2 )) fillRect( 114, 0, 9, 8, BLACK );
    else fillRect( 109, 0, 14, 8, BLACK );
  }
  else if ( batteryLevel < threshold2 ) {
    if ( charging && (( millis() / 1000 ) % 2 )) fillRect( 119, 0, 4, 8, BLACK );
    else fillRect( 114, 0, 9, 8, BLACK );
  }
  else if ( batteryLevel < maxLevel ) {
    if ( charging && (( millis() / 1000 ) % 2 ));
    else fillRect( 119, 0, 4, 8, BLACK );
  }
  //TODO add handling for invalid battery levels
}

//trimmed down adafruit's gfx implementation
void ZamekDisplay::drawFastVLine(int16_t x, int16_t __y, int16_t __h, uint16_t color) {


  // this display doesn't need ints for coordinates, use local byte registers for faster juggling
  uint8_t y = __y;
  uint8_t h = __h;


  // set up the pointer for fast movement through the buffer
  uint8_t *pBuf = buffer;
  // adjust the buffer pointer for the current row
  pBuf += ((y / 8) * SSD1306_LCDWIDTH);
  // and offset x columns in
  pBuf += x;

  // do the first partial byte, if necessary - this requires some masking
  uint8_t mod = (y & 7);
  if (mod) {
    // mask off the high n bits we want to set
    mod = 8 - mod;

    // note - lookup table results in a nearly 10% performance improvement in fill* functions
    // register uint8_t mask = ~(0xFF >> (mod));
    static uint8_t premask[8] = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE };
    uint8_t mask = premask[mod];

    // adjust the mask if we're not going to reach the end of this byte
    if ( h < mod) {
      mask &= (0XFF >> (mod - h));
    }

    switch (color)
    {
      case WHITE:   *pBuf |=  mask;  break;
      case BLACK:   *pBuf &= ~mask;  break;
      case INVERSE: *pBuf ^=  mask;  break;
    }

    // fast exit if we're done here!
    if (h < mod) {
      return;
    }

    h -= mod;

    pBuf += SSD1306_LCDWIDTH;
  }


  // write solid bytes while we can - effectively doing 8 rows at a time
  if (h >= 8) {
    if (color == INVERSE)  {          // separate copy of the code so we don't impact performance of the black/white write version with an extra comparison per loop
      do  {
        *pBuf = ~(*pBuf);

        // adjust the buffer forward 8 rows worth of data
        pBuf += SSD1306_LCDWIDTH;

        // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
        h -= 8;
      } while (h >= 8);
    }
    else {
      // store a local value to work with
      uint8_t val = (color == WHITE) ? 255 : 0;

      do  {
        // write our value in
        *pBuf = val;

        // adjust the buffer forward 8 rows worth of data
        pBuf += SSD1306_LCDWIDTH;

        // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
        h -= 8;
      } while (h >= 8);
    }
  }

  // now do the final partial byte, if necessary
  if (h) {
    mod = h & 7;
    // this time we want to mask the low bits of the byte, vs the high bits we did above
    // register uint8_t mask = (1 << mod) - 1;
    // note - lookup table results in a nearly 10% performance improvement in fill* functions
    static uint8_t postmask[8] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F };
    uint8_t mask = postmask[mod];
    switch (color)
    {
      case WHITE:   *pBuf |=  mask;  break;
      case BLACK:   *pBuf &= ~mask;  break;
      case INVERSE: *pBuf ^=  mask;  break;
    }
  }
}
