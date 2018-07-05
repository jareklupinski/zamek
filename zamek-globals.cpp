#include "zamek-globals.h"

ZamekUtils zamekUtils;
ZamekSleep zamekSleep;
ZamekSecurity zamekSecurity;
ZamekEeprom zamekEeprom;
ZamekDisplay zamekDisplay( OLED_MOSI_PIN, OLED_CLK_PIN, OLED_DC_PIN, OLED_RESET_PIN, OLED_CS_PIN ); 
ZamekIo zamekIo;

int16_t batteryLevel;  //set batteryLevel gauge
int16_t maxLevel;    //intiialize maximum battery level tracker for determining remaining battery life
int16_t minLevel;    //intiialize minimum battery level tracker for determining remaining battery life

char currentSite[ 16 ] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char currentUser[ 16 ] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char currentPass[ 16 ] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
int8_t pinArray[ 16 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int8_t pinIndex = 0;      //set initial PIN index
int8_t numpadIndex = 0;   //set initial Numpad index
int8_t typeIndex = 0;     //set index tracker for currently editing information to known value
int8_t cursorIndex = 0;   //set index tracker for current screen cursor position to known value
int8_t pinArrayIndex = 0; //set index tracker for currently selected PIN digit to known value
int8_t selectorIndex = 0; //set index tracker for currently editing account information cursor to known value
int8_t keyboardIndex = 0; //set index tracker for currently selected keyboard entry to known value
int16_t siteIndex = 0;     //set index tracker for currently displayed account to known value
uint8_t programPosition;
uint64_t entropy;


