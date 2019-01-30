#include "zamek-globals.h"                       //Include global header file

GLOBAL_VARIABLES                                //Declare list of global variables

//TODO List
// Set up WatchDog Timer ( dont forget to disable during sleep )
// Implement initialization feature which scrambles initial eeprom contents ( dont forget to add way to still dump contents in case of low-level corruption )
// Implement data integrity scanner ( use CRC32? )
// Re-enable sleep/lock on timeout
// Tighten up battery level thresholds
// ZamekDisplay class contains unused code

void setup() {
  Serial.begin( 9600 );                         //Initialize Serial Port
  analogReference( INTERNAL );                  //Measure ADC against internal reference
  pinMode( BUTTON_CENTER_PIN, INPUT_PULLUP );   //Set IO Pin Direction
  pinMode( BUTTON_LEFT_PIN,   INPUT_PULLUP );
  pinMode( BUTTON_RIGHT_PIN,  INPUT_PULLUP );
  pinMode( BUTTON_DOWN_PIN,   INPUT_PULLUP );
  pinMode( BUTTON_UP_PIN,     INPUT_PULLUP );
  pinMode( BAT_STAT_PIN,      INPUT_PULLUP );
  pinMode( BAT_SENSE_PIN,     INPUT );
  // pinMode( ACC_EN_PIN,        OUTPUT );
  pinMode( BAT_SENSE_EN_PIN,  OUTPUT );
  pinMode( EEPROM_WP_PIN,     OUTPUT );
  digitalWrite( BAT_SENSE_EN_PIN, HIGH );       //Set IO Pins to default states
  // digitalWrite( ACC_EN_PIN,       HIGH );
  zamekUtils.refreshBatteryLevel();             //Check battery level
  zamekDisplay.begin( SSD1306_SWITCHCAPVCC );   //Initialize OLED display
  zamekDisplay.display();
  while ( !digitalRead( BUTTON_CENTER_PIN ));   //Wait until center button is released
  Wire.begin();                                 //Initialize I2C
  //TODO evaluate ways of securely initializing the EEPROM
  //if ( EEPROM.read( 1023 ) != '*' ) initializeDevice();
  //TODO create an on-boot data integrity scanner
  EEPROM.update( 1023, 42 );
  attachInterrupt( 2, wakeInterrupt, FALLING ); //Set up center button to wake up from sleep
  programPosition = PIN_SCREEN;                 //Set program timeline to Pin Screen
  zamekDisplay.drawScreen();                    //Push data to screen and xhow it
}

void loop() {
  static unsigned long sleepTimer = 0;                        //Iniialize the timer used for going into timeout sleep mode
  while ( Serial.available() > 0 ) zamekUtils.handleSerial(); //Handle any Serial Communications
  if ( zamekIo.handleButtonChecker() ) {                      //Check the trackball and button for changes
    zamekUtils.refreshBatteryLevel();                         //Check battery status
    zamekDisplay.drawScreen();                                //Update Screen
    sleepTimer = millis();                                    //Reset timeout
  }
  //if (( sleepTimer + 60000 ) < millis() ) zamekSleep.start(); //No activity timeout
}

void wakeInterrupt() {}
