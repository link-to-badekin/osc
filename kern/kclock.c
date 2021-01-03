/* See COPYRIGHT for copyright information. */

#include <inc/x86.h>
#include <kern/kclock.h>

void
rtc_init(void) {
  nmi_disable();
  // LAB 4: Your code here
  uint8_t reg_a = 0,reg_b = 0;

  // меняем делитель частоты регистра часов А,
  outb(IO_RTC_CMND, RTC_AREG);
  reg_a = inb(IO_RTC_DATA);
  reg_a = reg_a | 0x0F; // биты 0-3 = 1 => 500 мс (2 Гц) 
  outb(IO_RTC_DATA, reg_a);
  // task1
  outb(IO_RTC_CMND, RTC_BREG);
  reg_b = inb(IO_RTC_DATA);
  reg_b = reg_b | RTC_PIE; 
  outb(IO_RTC_DATA, reg_b);

 
  // разрешить прерывания
  nmi_enable();

}

uint8_t
rtc_check_status(void) {
  uint8_t status = 0;
  // LAB 4: Your code here
  outb(IO_RTC_CMND, RTC_CREG);
  status = inb(IO_RTC_DATA);

  return status;
}
