#include "../x86_64/print.h"
#include "../version.h"
#include "../x86_64/boot/multiboot2.h"

#include <stdint.h>

static __inline__ uint64_t rdtsc(void) {
  uint64_t lo, hi;
  __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
  return ( lo | (hi << 32) );
}

static inline void halt() {
	while (1) asm volatile("cli\nhlt");
}

static uint64_t *mbi;


void kernel_main(void * _mbi) {
    mbi = _mbi;
    uint64_t t;//, ts, te;
    print_clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    printf("Welcome to kvm ksm OS 64-bit kernel!\n\t(version : %s - %s)\n", __KERN_VERSION__, __BUILD_TIME__);

//    printf("mbi addr : 0x%x\n", mbi);

//    for(int i=0;i<10;i++) {
//        for (int j = 0; j < 10000000; j++);
//        t = rdtsc();
//        printf("%u\n", t);
//    }
    halt();
}
