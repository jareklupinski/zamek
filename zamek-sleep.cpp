 #include "zamek-sleep.h"

GLOBAL_VARIABLES

void ZamekSleep::start() {               //enter Sleep Mode
  for ( int i = 0; i < 16; i++ ) pinArray[ i ] = 0;
  pinArrayIndex = 0;
  zamekDisplay.wipeScreen();
  zamekDisplay.drawBitmap( 48, 0, lock, 32, 32, WHITE );
  zamekDisplay.display();
  while ( !digitalRead( BUTTON_CENTER_PIN ));
  zamekDisplay.ssd1306_command( SSD1306_DISPLAYOFF );
  
  pinMode( BUTTON_UP_PIN     , INPUT_PULLUP );
  pinMode( BUTTON_DOWN_PIN   , INPUT_PULLUP );
  pinMode( BUTTON_LEFT_PIN   , INPUT_PULLUP );
  pinMode( BUTTON_RIGHT_PIN  , INPUT_PULLUP );
  pinMode( BAT_SENSE_PIN     , INPUT );
  pinMode( BAT_SENSE_EN_PIN  , INPUT );
  pinMode( BAT_STAT_PIN      , INPUT );
  pinMode( EEPROM_WP_PIN     , INPUT );
  // pinMode( ACC_EN_PIN        , INPUT );
  pinMode( OLED_MOSI_PIN     , INPUT );
  pinMode( OLED_CLK_PIN      , INPUT );
  pinMode( OLED_DC_PIN       , INPUT );
  pinMode( OLED_RESET_PIN    , INPUT );
  pinMode( OLED_CS_PIN       , INPUT );

  set_sleep_mode( SLEEP_MODE_PWR_DOWN ); // Set CPU Sleep Mode
  analogReference( DEFAULT ); // Power down internal reference
  PLLCSR &= ~( 1 << PLLE );   // Disable the USB Clock (PPL)
  USBCON &= ~( 1 << USBE );   // Disable the USB
  UDINT  &= ~( 1 << SUSPI );  // UDINT.SUSPI = 0; Usb_ack_suspend
  USBCON |=  ( 1 << FRZCLK ); // USBCON.FRZCLK = 1; Usb_freeze_clock
  ADCSRA = 0b00000000;        // Disable ADC
  power_adc_disable();
  wdt_disable();  
  sleep_enable();
  sleep_mode();
  //Current Sleep Power Consumption: 240uA
  //Atmega32u4 datasheet claims it can go as low as 15uA
  //Power Regulator's Iq is 65uA
  //TODO Evaluate other potential sources of current leaks
  //TODO Evaluate 'cleaner' methods for coming out of sleep and resetting
  sleep_disable();
  asm volatile ( "  jmp 0" );
}

