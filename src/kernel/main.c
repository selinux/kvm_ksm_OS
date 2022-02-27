#include "../x86_64/print.h"
#include "../version.h"
#include "../x86_64/boot/multiboot2.h"

#include <stdint.h>

//#ifdef __i386
//extern __inline__ uint64_t rdtsc(void) {
//  uint64_t x;
//  __asm__ volatile ("rdtsc" : "=A" (x));
//  return x;
//}
//#elif defined __amd64
static __inline__ uint64_t rdtsc(void) {
  uint64_t lo, hi;
  __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
  return ( lo | (hi << 32) );
    return ((uint64_t)lo) | (((uint64_t)hi) << 32);
  return  lo ;
}


static uint64_t *mbi;

//uint_t get_RAM_in_KB() {
//	return mbi->mem_lower + mbi->mem_upper;
//}

//multiboot_info_t* get_multiboot_info() {
//	return mbi;
//}

void kernel_main(void * _mbi) {
    mbi = _mbi;
    uint64_t t;//, ts, te;
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
//    ts = rdtsc_s();
//    printf("%u\n", t);
    print_str("Welcome to our 64-bit kernel!\n");
//    te = rdtsc_e();
//    printf("%u\n", t);
    printf("0x%x_%d_%s_%c\n0x%x\n\n", 0xFA, 50, "Hi", 'D', kernel_main);
    printf("mbi addr : 0x%x\n", mbi);

    for(int i=0;i<10;i++) {
        for (int j = 0; j < 10000000; j++);
//        ts = rdtsc_s();
//        for (int j = 0; j < 100000; j++);
        t = rdtsc();
//        t = te - ts;
        printf("%u\n", t);
    }
}
