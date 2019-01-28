#include "zamek-io.h"

GLOBAL_VARIABLES

void ZamekIo::leftButtonPressed() {
  char cipherText[ 50 ];
  switch ( programPosition ) {
    case SPLASHSCREEN: break;
    case PIN_SCREEN:
      if ( pinIndex > 0 ) {
        pinArray[ pinIndex ] = 0;
        pinIndex--;
      }
      break;
    case MAIN_INDEX:
    case MAIN_SITE:
    case MAIN_USER:
    case MAIN_PASS:
      siteIndex = siteIndex - 1;
      if ( siteIndex < 0 ) siteIndex = MAXSITES - 1;
      zamekSecurity.unlock();
      break;
    case EDIT_LEFT_CURSOR: break;
    case EDIT_RIGHT_CURSOR:
      programPosition = EDIT_LEFT_CURSOR;
      break;
    case EDIT_RAND: break;
    case EDIT_BACK: break;
    case EDIT_KB1:
      if (( selectorIndex == 0 ) && ( keyboardIndex == 0 )) programPosition = EDIT_RIGHT_CURSOR;
      else if (( selectorIndex == 0 ) && ( keyboardIndex >= 0 )) keyboardIndex = keyboardIndex - 1;
      else selectorIndex = selectorIndex - 1;
      break;
    case EDIT_KB2:
      if (( selectorIndex == 0 ) && ( keyboardIndex == 0 )) programPosition = EDIT_RAND;
      else if (( selectorIndex == 0 ) && ( keyboardIndex >= 0 )) keyboardIndex = keyboardIndex - 1;
      else selectorIndex = selectorIndex - 1;
      break;
    case EDIT_KB3:
      if (( selectorIndex == 0 ) && ( keyboardIndex == 0 )) programPosition = EDIT_BACK;
      else if (( selectorIndex == 0 ) && ( keyboardIndex >= 0 )) keyboardIndex = keyboardIndex - 1;
      else selectorIndex = selectorIndex - 1;
      break;
    default: zamekUtils.throwErrorScreen(); break;
  }
}

void ZamekIo::rightButtonPressed() {
  switch ( programPosition ) {
    case SPLASHSCREEN: break;
    case PIN_SCREEN:
      if ( pinIndex > 0 ) {
        pinArray[ pinIndex ] = 0;
        pinIndex--;
      }
      break;
    case MAIN_INDEX:
    case MAIN_SITE:
    case MAIN_USER:
    case MAIN_PASS:
      siteIndex = siteIndex + 1;
      if ( siteIndex > ( MAXSITES - 1 )) siteIndex = 0;
      zamekSecurity.unlock();
      break;
    case EDIT_LEFT_CURSOR: programPosition = EDIT_RIGHT_CURSOR; break;
    case EDIT_RIGHT_CURSOR: programPosition = EDIT_KB1; break;
    case EDIT_RAND: programPosition = EDIT_KB2; break;
    case EDIT_BACK: programPosition = EDIT_KB3; break;
    case EDIT_KB1:
      if ( selectorIndex < 15 ) selectorIndex = selectorIndex + 1;
      else if ( keyboardIndex < 16 ) keyboardIndex = keyboardIndex + 1;
      break;
    case EDIT_KB2:
      if ( selectorIndex < 15 ) selectorIndex = selectorIndex + 1;
      else if ( keyboardIndex < 16 ) keyboardIndex = keyboardIndex + 1;
      break;
    case EDIT_KB3:
      if ( selectorIndex < 15 ) selectorIndex = selectorIndex + 1;
      else if ( keyboardIndex < 16 ) keyboardIndex = keyboardIndex + 1;
      break;
    default: zamekUtils.throwErrorScreen(); break;
  }
}

void ZamekIo::upButtonPressed() {
  switch ( programPosition ) {
    case SPLASHSCREEN: break;
    case PIN_SCREEN:
      if ( numpadIndex < 9 ) numpadIndex++;
      else numpadIndex = 0;
      break;
    case MAIN_INDEX: break;
    case MAIN_SITE: programPosition = MAIN_INDEX; break;
    case MAIN_USER: programPosition = MAIN_SITE; break;
    case MAIN_PASS: programPosition = MAIN_USER; break;
    case EDIT_LEFT_CURSOR: break;
    case EDIT_RIGHT_CURSOR: break;
    case EDIT_RAND: programPosition = EDIT_LEFT_CURSOR; break;
    case EDIT_BACK: programPosition = EDIT_RAND; break;
    case EDIT_KB1: break;
    case EDIT_KB2: programPosition = EDIT_KB1; break;
    case EDIT_KB3: programPosition = EDIT_KB2; break;
    default: zamekUtils.throwErrorScreen(); break;
  }
}

void ZamekIo::downButtonPressed() {
  switch ( programPosition ) {
    case SPLASHSCREEN: break;
    case PIN_SCREEN:
      if ( numpadIndex > 0 ) numpadIndex--;
      else numpadIndex = 9;
      break;
    case MAIN_INDEX: programPosition = MAIN_SITE; break;
    case MAIN_SITE: programPosition = MAIN_USER; break;
    case MAIN_USER: programPosition = MAIN_PASS; break;
    case MAIN_PASS: break;
    case EDIT_LEFT_CURSOR: programPosition = EDIT_RAND; break;
    case EDIT_RIGHT_CURSOR: programPosition = EDIT_RAND; break;
    case EDIT_RAND: programPosition = EDIT_BACK; break;
    case EDIT_BACK: break;
    case EDIT_KB1: programPosition = EDIT_KB2; break;
    case EDIT_KB2: programPosition = EDIT_KB3; break;
    case EDIT_KB3: break;
    default: zamekUtils.throwErrorScreen(); break;
  }
}

void ZamekIo::centerButtonPressed() {
  unsigned long lockCheckTimer = millis();
  entropy += micros();
  byte finish = 1;
  char cipherText[ 50 ];
  while ( !digitalRead( BUTTON_CENTER_PIN )) {
    if ( programPosition == PIN_SCREEN ) {
      zamekDisplay.wipeScreen();
      zamekDisplay.setTextSize( 3 );
      switch ( pinIndex ) {
        case 0: break;
        default:
          for ( int i = 0; i < pinIndex; i++ ) {
            if ( 82 - ( 17 * i ) > -4 ) {
              zamekDisplay.setCursor( 82 - ( 17 * i ), 6 );
              zamekDisplay.print( pinArray[ pinIndex - (i + 1) ] );
            }
          }
          break;
      }
      zamekDisplay.drawBitmap( 104, 0, pinFrame, 24, 32, WHITE );
      zamekDisplay.display();
    }
    if (( lockCheckTimer + 1000 ) <= millis() ) {
      if ( programPosition == PIN_SCREEN ) {
        programPosition = MAIN_INDEX;
        zamekSecurity.unlock();
        zamekDisplay.wipeScreen();
        zamekDisplay.renderMainScreen();
        zamekDisplay.display();
        while ( !digitalRead( BUTTON_CENTER_PIN ));
      }
      else zamekSleep.start();
      finish = 0;
      break;
    }
  }
  if ( finish ) {
    switch ( programPosition ) {
      case SPLASHSCREEN:
        programPosition = PIN_SCREEN;
        break;
      case PIN_SCREEN:
        if (pinIndex < 16) {
          pinArray[ pinIndex ] = numpadIndex;
          pinIndex++;
        }
        break;
      case MAIN_INDEX:
        zamekUtils.typePassword();
        break;
      case MAIN_SITE:
        programPosition = EDIT_RIGHT_CURSOR;
        cursorIndex = 0;
        typeIndex = 0;
        break;
      case MAIN_USER:
        programPosition = EDIT_RIGHT_CURSOR;
        cursorIndex = 0;
        typeIndex = 1;
        break;
      case MAIN_PASS:
        programPosition = EDIT_RIGHT_CURSOR;
        cursorIndex = 0;
        typeIndex = 2;
        break;
      case EDIT_LEFT_CURSOR:
        cursorIndex = cursorIndex - 1;
        if ( cursorIndex < 0 ) cursorIndex = 15;
        break;
      case EDIT_RIGHT_CURSOR:
        cursorIndex = cursorIndex + 1;
        if ( cursorIndex > 15 ) cursorIndex = 0;
        break;
      case EDIT_RAND:
        zamekUtils.randomEntry();
        break;
      case EDIT_BACK:
        programPosition = MAIN_SITE;
        zamekSecurity.lock();
        break;
      case EDIT_KB1:
        switch ( typeIndex ) {
          case 0: currentSite[ cursorIndex ] = char( pgm_read_byte_near( keyboard1 + keyboardIndex + selectorIndex )); break;
          case 1: currentUser[ cursorIndex ] = char( pgm_read_byte_near( keyboard1 + keyboardIndex + selectorIndex )); break;
          case 2: currentPass[ cursorIndex ] = char( pgm_read_byte_near( keyboard1 + keyboardIndex + selectorIndex )); break;
          default: break;
        }
        if ( cursorIndex < 15 ) cursorIndex = cursorIndex + 1;
        else cursorIndex = 0;
        break;
      case EDIT_KB2:
        switch (typeIndex) {
          case 0: currentSite[ cursorIndex ] = char( pgm_read_byte_near( keyboard2 + keyboardIndex + selectorIndex )); break;
          case 1: currentUser[ cursorIndex ] = char( pgm_read_byte_near( keyboard2 + keyboardIndex + selectorIndex )); break;
          case 2: currentPass[ cursorIndex ] = char( pgm_read_byte_near( keyboard2 + keyboardIndex + selectorIndex )); break;
          default: break;
        }
        if ( cursorIndex < 15 ) cursorIndex = cursorIndex + 1;
        else cursorIndex = 0;
        break;
      case EDIT_KB3:
        switch ( typeIndex ) {
          case 0: currentSite[ cursorIndex ] = char( pgm_read_byte_near( keyboard3 + keyboardIndex + selectorIndex )); break;
          case 1: currentUser[ cursorIndex ] = char( pgm_read_byte_near( keyboard3 + keyboardIndex + selectorIndex )); break;
          case 2: currentPass[ cursorIndex ] = char( pgm_read_byte_near( keyboard3 + keyboardIndex + selectorIndex )); break;
          default: break;
        }
        if ( cursorIndex < 15 ) cursorIndex = cursorIndex + 1;
        else cursorIndex = 0;
        break;
      default:
        zamekUtils.throwErrorScreen();
        break;
    }
  }
}

int ZamekIo::handleButtonChecker() {       
  /*
  static byte state1 = PINF & 0x72; //0x72 0b01110010
  byte state2 = PINF & 0x72; //0x72 0b01110010
   //handle trackball movements
  static byte upCounter = 0;
  static byte downCounter = 0;
  static byte leftCounter = 0;
  static byte rightCounter = 0;
  static unsigned long resetTimer = millis();
  byte deadoffset = 1;
  byte sideoffset = 0;
  if ( programPosition == PIN_SCREEN ) {
    sideoffset = 3;
    deadoffset = 0;
  }
  if ( (resetTimer + 100) < millis() ) {
    upCounter = 0;
    downCounter = 0;
    leftCounter = 0;
    rightCounter = 0;
  }
  if ( state2 != state1 ) {
    resetTimer = millis();
    if (( state1 & 0x02 ) != ( state2 & 0x02 )) {
      downCounter++;
      upCounter = 0;
      rightCounter = 0;
      leftCounter = 0;
    }
    else if (( state1 & 0x10 ) != ( state2 & 0x10 )) {
      leftCounter++;
      upCounter = 0;
      rightCounter = 0;
      downCounter = 0;
    }
    else if (( state1 & 0x20 ) != ( state2 & 0x20 )) {
      upCounter++;
      leftCounter = 0;
      rightCounter = 0;
      downCounter = 0;
    }
    else if (( state1 & 0x40 ) != ( state2 & 0x40 )) {
      rightCounter++;
      upCounter = 0;
      downCounter = 0;
      leftCounter = 0;
    }
    state1 = state2;
  }
  if ( downCounter >= DEADZONE ) {
    downCounter = deadoffset;
    downButtonPressed();
    return 1;
  }
  else if ( upCounter >= DEADZONE ) {
    upCounter = deadoffset;
    upButtonPressed();
    return 1;
  }
  else if ( leftCounter >= ( DEADZONE + sideoffset ) ) {
    leftCounter = deadoffset;
    leftButtonPressed();
    return 1;
  }
  else if ( rightCounter >= ( DEADZONE + sideoffset ) ) {
    rightCounter = deadoffset;
    rightButtonPressed();
    return 1;
  }
  */
  if ( !digitalRead( BUTTON_CENTER_PIN )) {
    /*
    // trackball code
    upCounter = 0;
    downCounter = 0;
    leftCounter = 0;
    rightCounter = 0;
    */
    delay( DEBOUNCEDELAY );
    if ( !digitalRead( BUTTON_CENTER_PIN )) {
      centerButtonPressed();
      return 1;
    }
  }
  if ( !digitalRead( BUTTON_RIGHT_PIN )) {
    delay( DEBOUNCEDELAY );
    if ( !digitalRead( BUTTON_RIGHT_PIN )) {
      rightButtonPressed();
      return 1;
    }
  }
  if ( !digitalRead( BUTTON_LEFT_PIN )) {
    delay( DEBOUNCEDELAY );
    if ( !digitalRead( BUTTON_LEFT_PIN )) {
      leftButtonPressed();
      return 1;
    }
  }
  if ( !digitalRead( BUTTON_UP_PIN )) {
    delay( DEBOUNCEDELAY );
    if ( !digitalRead( BUTTON_UP_PIN )) {
      upButtonPressed();
      return 1;
    }
  }
  if ( !digitalRead( BUTTON_DOWN_PIN )) {
    delay( DEBOUNCEDELAY );
    if ( !digitalRead( BUTTON_DOWN_PIN )) {
      downButtonPressed();
      return 1;
    }
  }
  return 0;
}
