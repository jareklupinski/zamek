#ifndef _ZAMEK_GLOBALS_H
#define _ZAMEK_GLOBALS_H

#include <Arduino.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Keyboard.h>
#include <AESLib.h>
#include "zamek-font.h"
#include "zamek-display.h"
#include "zamek-security.h"
#include "zamek-eeprom.h"
#include "zamek-sleep.h"
#include "zamek-utils.h"
#include "zamek-io.h"

#define DEBOUNCEDELAY     15 //amount of ms to debounce buttons
#define MAXSITES          64 //maximum number of storable entries ( 64 Bytes are used per entry, allocate based on installed EEPROM )

#define BUTTON_CENTER_PIN 0  //Hardware pin mapping
#define BUTTON_UP_PIN     19
#define BUTTON_DOWN_PIN   21
#define BUTTON_LEFT_PIN   22
#define BUTTON_RIGHT_PIN  20
#define BAT_SENSE_PIN     A5
#define BAT_SENSE_EN_PIN  A0
#define BAT_STAT_PIN      5
#define EEPROM_WP_PIN     1
// #define ACC_EN_PIN        4
#define OLED_MOSI_PIN     10
#define OLED_CLK_PIN      9
#define OLED_DC_PIN       8
#define OLED_RESET_PIN    6
#define OLED_CS_PIN       12

#define SPLASHSCREEN 1
#define PIN_SCREEN 2
#define MAIN_INDEX 3
#define MAIN_SITE 4
#define MAIN_USER 5
#define MAIN_PASS 6
#define EDIT_LEFT_CURSOR 7
#define EDIT_RIGHT_CURSOR 8
#define EDIT_RAND 9
#define EDIT_BACK 10
#define EDIT_KB1 11
#define EDIT_KB2 12
#define EDIT_KB3 13
#define CATCH_ERROR 0 

#define GLOBAL_VARIABLES  extern PROGMEM const uint8_t battery[];   \
                          extern PROGMEM const uint8_t lock[];      \
                          extern PROGMEM const uint8_t pinFrame[];  \
                          extern PROGMEM const uint8_t arrows[];    \
                          extern PROGMEM const char randomValues[]; \
                          extern PROGMEM const char keyboard1[];    \
                          extern PROGMEM const char keyboard2[];    \
                          extern PROGMEM const char keyboard3[];    \
                          extern ZamekUtils zamekUtils;             \
                          extern ZamekSleep zamekSleep;             \
                          extern ZamekSecurity zamekSecurity;       \
                          extern ZamekEeprom zamekEeprom;           \
                          extern ZamekDisplay zamekDisplay;         \
                          extern ZamekIo zamekIo;                   \
                          extern char currentSite[ 16 ];            \
                          extern char currentUser[ 16 ];            \ 
                          extern char currentPass[ 16 ];            \
                          extern int8_t pinArray[ 16 ];             \
                          extern int8_t pinIndex;                   \
                          extern int8_t numpadIndex;                \
                          extern int8_t typeIndex;                  \
                          extern int8_t cursorIndex;                \            
                          extern int8_t pinArrayIndex;              \ 
                          extern int8_t selectorIndex;              \
                          extern int8_t keyboardIndex;              \
                          extern int16_t siteIndex;                 \
                          extern uint8_t programPosition;           \
                          extern int16_t batteryLevel;              \
                          extern int16_t minLevel;                  \
                          extern int16_t maxLevel;                  \
                          extern uint64_t entropy;

PROGMEM const uint8_t battery[]  = { 0x37, 0xBD, 0xEE, 0x37, 0xBD, 0xEE, 0x37, 0xBD, 0xEF, 0x37, 0xBD, 0xEF, 0x37, 0xBD, 0xEF, 0x37, 0xBD, 0xEF, 0x37, 0xBD, 0xEE, 0x37, 0xBD, 0xEE };
PROGMEM const uint8_t lock[]     = { 0x00, 0x07, 0xE0, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x01, 0xFC, 0x3F, 0x80, 0x03, 0xF0, 0x0F, 0xC0, 0x07, 0xC0, 0x03, 0xE0, 0x07, 0xC0, 0x03, 0xE0, 0x0F, 0x80, 0x01, 0xF0, 0x0F, 0x80, 0x01, 0xF0, 0x0F, 0x00, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xF8, 0x1F, 0xFF, 0xFF, 0xF8, 0x1F, 0xFF, 0xFF, 0xF0, 0x0F, 0xFF, 0xFF, 0xF0, 0x0F, 0xFF, 0xFF, 0xF8, 0x1F, 0xFF, 0xFF, 0xF8, 0x1F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0x7F, 0xFC, 0x3F, 0xFE, 0x7F, 0xFC, 0x3F, 0xFE, 0x3F, 0xFC, 0x3F, 0xFC, 0x1F, 0xF8, 0x1F, 0xF8, 0x0F, 0xFF, 0xFF, 0xF0, 0x01, 0xFF, 0xFF, 0x80 };
PROGMEM const uint8_t pinFrame[] = { 0x00, 0x07, 0xFF, 0x00, 0x7F, 0xFF, 0x03, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0x1F, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 0x1F, 0xFF, 0xFF, 0x07, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0x00, 0x07, 0xFF };
PROGMEM const uint8_t arrows[]   = { 0x07, 0xFF, 0xE0, 0x27, 0xFF, 0xE4, 0x67, 0xFF, 0xE6, 0xE7, 0xFF, 0xE7, 0xE7, 0xFF, 0xE7, 0x67, 0xFF, 0xE6, 0x27, 0xFF, 0xE4, 0x07, 0xFF, 0xE0 };

PROGMEM const char randomValues[ 94 ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '(', ')', '[', ']', '{', '}', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '<', '>', '|', '\\', '/', '?', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+', '!', '@', '#', '$', '%', '^', '&', '*', '_', '+', '`', '~', ';', ':', '"', '\'', ',', '.' };
PROGMEM const char keyboard1[ 32 ]    = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '(', ')', '[', ']', '{', '}' };
PROGMEM const char keyboard2[ 32 ]    = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '<', '>', '|', '\\', '/', '?' };
PROGMEM const char keyboard3[ 32 ]    = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+', '!', '@', '#', '$', '%', '^', '&', '*', '_', '+', '`', '~', ';', ':', '"', '\'', ',', '.', ' ', ' ' };


#endif /* _ZAMEK_GLOBALS_H */
