#include "../x86_64/print.h"
#include "../version.h"
#include "../x86_64/boot/multiboot2.h"
#include "../x86_64/x86.h"

#include <stdint.h>


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
