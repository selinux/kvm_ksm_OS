# kvm ksm OS

baemetal OS (64bits) to investigate KVM KSM memory pages deduplication resistance over 
side channel attack (cache-time driven attack).


## Build

Enter build environment:

```shell
make help

Available targets:
run      build the OS ISO image (+ filsystem) and run it in QEMU
iso      build the OS ISO image (+ filesystem)
kernel   build the kernel only
debug    build the OS ISO image (+ filsystem) and run it in QEMU for debugging
clean    clean up everything
```

