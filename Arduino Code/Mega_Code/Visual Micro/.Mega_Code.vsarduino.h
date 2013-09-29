#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
//Board = Arduino Mega 2560 or Mega ADK
#define __AVR_ATmega2560__
#define 
#define ARDUINO 105
#define ARDUINO_MAIN
#define __AVR__
#define F_CPU 16000000L
#define __cplusplus
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__

#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define __attribute__(x)
#define NOINLINE __attribute__((noinline))
#define prog_void
#define PGM_VOID_P int
            
typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}

//
//
void serialEvent();
void isr_Headlights();
void isr_ShiftUp();
void isr_ShiftDown();
void isr_IndicateLeft();
void isr_IndicateRight();
void lcd_clear();
void lcd_update();
void Msg(const char *message,  const byte column, const byte row);
void calibration_menu();
void isr_detach();
void isr_attach();
void scooter_lock_screen_key();
void scooter_lock_screen_remote();
void serial_check();
void serial_process();
void serial_write_buttons();
void serial_write_power();
void serial_read_state();
void serial_read_power();

#include "F:\Program Files\Arduino\hardware\arduino\variants\mega\pins_arduino.h" 
#include "F:\Program Files\Arduino\hardware\arduino\cores\arduino\arduino.h"
#include "F:\Users\James\Documents\GitHub\Scooter\Arduino Code\Mega_Code\Mega_Code.ino"
#endif
