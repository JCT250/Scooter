#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
//Board = Arduino Mega 2560 or Mega ADK
#define __AVR_ATmega2560__
#define ARDUINO 103
#define __AVR__
#define F_CPU 16000000L
#define __cplusplus
#define __attribute__(x)
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
#define prog_void
#define PGM_VOID_P int
#define NOINLINE __attribute__((noinline))

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
void serial_read_lock();

#include "C:\Arduino\hardware\arduino\variants\mega\pins_arduino.h" 
#include "C:\Arduino\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Users\prepress2\Documents\GitHub\Scooter\Arduino Code\Mega_Code\Mega_Code.ino"
#endif
