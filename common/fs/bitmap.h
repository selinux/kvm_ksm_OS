#ifndef _BITMAP_COMMON_H_
#define _BITMAP_COMMON_H_

#include "../types.h"

typedef struct {
	uint_t count;      // number of bits in the bitmap
	uint_t size;       // size of the bits array in bytes
	uint8_t *bits;
} bitmap_t;

int bitmap_get(bitmap_t *bitmap, int index);
void bitmap_set(bitmap_t *bitmap, int index, int value);

int bitmap_reserve_first_available_bit(bitmap_t *bitmap);
uint_t bitmap_get_free_bits(bitmap_t *bitmap);

#endif
