#include "zamek-utils.h"

GLOBAL_VARIABLES

void ZamekUtils::refreshBatteryLevel() {      //update the battery level variable and min/max battery life bounds
  digitalWrite( BAT_SENSE_EN_PIN, LOW );
  delay( 10 );
  batteryLevel = analogRead( BAT_SENSE_PIN );
  delay( 10 );
  digitalWrite( BAT_SENSE_EN_PIN, HIGH );
  //Save min and max battery levels for debugging purposes
  //TODO consider removal
  if ( batteryLevel > maxLevel ) {
    maxLevel = batteryLevel;
    EEPROM.update( 1021, maxLevel >> 8 );
    EEPROM.update( 1022, maxLevel );
  }
  if (( batteryLevel < minLevel ) || minLevel < 100 ) {
    minLevel = batteryLevel;
    EEPROM.update( 1019, minLevel >> 8 );
    EEPROM.update( 1020, minLevel );
  }
}

uint8_t ZamekUtils::waitForPress() {              //freeze program until button is pressed
  while ( digitalRead( BUTTON_CENTER_PIN ));
  delay( DEBOUNCEDELAY );
  if ( !digitalRead( BUTTON_CENTER_PIN )) return 1;
  else return 0;
}

void ZamekUtils::typePassword() {             //type password when connected to USB port
  Keyboard.begin();
  int index = 16;
  while ( currentPass[ index - 1 ] == ' ') index--;
  for ( int i = 0; i < index; i++ ) {
    if ( Keyboard.write( currentPass[ i ] ) == 0 ) {
      zamekDisplay.wipeScreen();
      zamekDisplay.print("Not Connected");
      zamekDisplay.display();
      delay(5000);
      break;
    }
  }
  Keyboard.end();
}

void ZamekUtils::throwErrorScreen() {         //default exception catcher
  zamekDisplay.print("Error: Invalid Program State");
  zamekDisplay.display();
  delay( 2000 );
  programPosition = MAIN_INDEX;
}

void ZamekUtils::randomEntry() {              //create a random entry
  zamekDisplay.wipeScreen();
  zamekDisplay.println("Click joystick to");
  zamekDisplay.println("generate random");
  switch ( typeIndex ) {
    case 0: zamekDisplay.println("site name."); break;
    case 1: zamekDisplay.println("user name."); break;
    case 2: zamekDisplay.println("password."); break;
  }
  //TODO implement cancel method: zamekDisplay.println("Do something to cancel");
  zamekDisplay.display();
  //TODO evaluate better methods of generating random seeds
  unsigned long entropy = micros();// + batteryLevel;
  while ( waitForPress() == 0 );
  while ( !digitalRead( BUTTON_CENTER_PIN ));
  entropy = entropy - micros();
  randomSeed(entropy);
  switch ( typeIndex ) {
    case 0:
      for ( int i = 0; i < 16; i++ ) {
        int r = random( 94 );
        currentSite[ i ] = pgm_read_byte_near( randomValues + r );
      }
      break;
    case 1:
      for ( int i = 0; i < 16; i++ ) {
        int r = random( 94 );
        currentUser[ i ] = pgm_read_byte_near( randomValues + r );
      }
      break;
    case 2:
      for ( int i = 0; i < 16; i++ ) {
        int r = random( 94 );
        currentPass[ i ] = pgm_read_byte_near( randomValues + r );
      }
      break;
  }
  zamekSecurity.lock();
}

void ZamekUtils::clearAccount() {             //clear the currently selected account
  zamekDisplay.wipeScreen();
  zamekDisplay.println("Hold trackball down");
  zamekDisplay.println("to erase Account.");
  zamekDisplay.println("Click trackball quickly");
  zamekDisplay.println("to cancel.");
  //TODO implement cancel method: zamekDisplay.println("Do something to cancel");
  zamekDisplay.display();
  while ( waitForPress() == 0 );
  if ( !digitalRead( BUTTON_CENTER_PIN )) {
    delay( 500 );
    while ( waitForPress() == 0 );
    if ( !digitalRead( BUTTON_CENTER_PIN )) {
      for ( int i = 0; i < 16; i++ ) {
        currentSite[ i ] = ' ';
        currentUser[ i ] = ' ';
        currentPass[ i ] = ' ';
      }
    }
  }
  zamekSecurity.lock();
}

void ZamekUtils::handleSerial() {             //handle Serial commands
  //TODO implement crc-based error handling
  zamekDisplay.wipeScreen();
  char firstCheck = Serial.read();
  if (firstCheck == '*') {
    zamekDisplay.println("Serial Request: ");
    //TODO only allow Serial access after physical button press
    char function = Serial.read();
    byte entry[ 64 ];
    char toss;
    int oldIndex = siteIndex;
    int index;
    int j = 0;
    switch (function) {
      case 'v':
        zamekDisplay.print("Connection\r\nVerification");
        Serial.write('@');
        if ( programPosition == PIN_SCREEN ) Serial.write('L');
        else Serial.write('U');
        Serial.flush();
        break;
      case 'r':
        zamekDisplay.print("Read\r\nCredentials ");
        siteIndex = Serial.parseInt() - 1;
        zamekDisplay.print( siteIndex );
        zamekSecurity.unlock();
        index = 16;
        Serial.write('@');
        Serial.write('r');
        while ( currentSite[ index - 1 ] == ' ' ) index--;
        for ( int i = 0; i < index; i++ ) Serial.write( currentSite[ i ]);
        Serial.println();

        index = 16;
        while ( currentUser[ index - 1 ] == ' ' ) index--;
        for ( int i = 0; i < index; i++ ) Serial.write( currentUser[ i ]);
        Serial.println();

        index = 16;
        while ( currentPass[ index - 1 ] == ' ' ) index--;
        for ( int i = 0; i < index; i++ ) Serial.write( currentPass[ i ]);
        break;
      case 'w':
        zamekDisplay.print("Write\r\nCredentials ");
        siteIndex = Serial.parseInt() - 1;
        zamekDisplay.print( siteIndex );
        toss = Serial.read();
        for ( int i = 0; i < 16; i++ ) currentSite[ i ] = Serial.read();
        for ( int i = 0; i < 16; i++ ) currentUser[ i ] = Serial.read();
        for ( int i = 0; i < 16; i++ ) currentPass[ i ] = Serial.read();
        zamekSecurity.lock();

        Serial.write('@');
        Serial.write('w');
        index = 16;
        while ( currentSite[ index - 1 ] == ' ' ) index--;
        for ( int i = 0; i < index; i++ ) Serial.write( currentSite[ i ]);
        Serial.println();

        index = 16;
        while ( currentUser[ index - 1 ] == ' ' ) index--;
        for ( int i = 0; i < index; i++ ) Serial.write( currentUser[ i ]);
        Serial.println();

        index = 16;
        while ( currentPass[ index - 1 ] == ' ' ) index--;
        for ( int i = 0; i < index; i++ ) Serial.write( currentPass[ i ]);
        Serial.println();
        break;
      case 'd':
        zamekDisplay.println( "Dumping" );
        zamekDisplay.display();
        Serial.write( '@' );
        Serial.write( 'd' );
        for ( int i = 0; i < MAXSITES; i++ ) {
          zamekDisplay.wipeScreen();
          zamekDisplay.println( "Dumping " + String( i ) );
          zamekDisplay.display();
          siteIndex = i;
          zamekEeprom.readEntry( entry );
          for ( int j = 0; j < 64; j++ ) Serial.write( entry[ j ] );
        }
        zamekDisplay.print( "Finished Dumping" );
        break;
      case 'u':
        zamekDisplay.println("Restore");
        zamekDisplay.display();
        for ( int i = 0; i < MAXSITES; i++ ) {
          zamekDisplay.wipeScreen();
          zamekDisplay.println( "Restoring " + String( i ) );
          zamekDisplay.display();
          siteIndex = i;
          for ( int j = 0; j < 64; j++ ) entry[ j ] = Serial.read();
          zamekEeprom.writeEntry( entry );
        }
        break;
      default:
        //TODO throw error on invalid character?
        break;
    }
    Serial.println();
    Serial.flush();
    zamekDisplay.display();
    delay( 1000 );
    siteIndex = oldIndex;
    zamekSecurity.unlock();
    zamekDisplay.drawScreen();
  }
}

unsigned long ZamekUtils::calculateCrc() {  //implementation from https://www.arduino.cc/en/Tutorial/EEPROMCrc
  //TODO validate implementation by recreating it from source
  const unsigned long crc_table[16] = {
    0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
    0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
    0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
    0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
  };
  unsigned long crc = ~0L;
  for (int index = 0 ; index < EEPROM.length()  ; ++index) {
    crc = crc_table[(crc ^ EEPROM[index]) & 0x0f] ^ (crc >> 4);
    crc = crc_table[(crc ^ (EEPROM[index] >> 4)) & 0x0f] ^ (crc >> 4);
    crc = ~crc;
  }
  return crc;
}
