#include "bitmap.h"

/// Return a bit from the bitmap.
/// @param bitmap.
/// @param index at which to return a bit.
/// @return the bit at the specified index (0 or 1).
int bitmap_get(bitmap_t *bitmap, int index) {
	return bitmap->bits[index/8] & (1 << (index & 7));
}

/// Set a bit in the bitmap.
/// @param bitmap.
/// @param index at which to set the bit.
/// @param value of the bit (0 or 1).
void bitmap_set(bitmap_t *bitmap, int index, int value) {
	if (value)
		bitmap->bits[index/8] |= (1 << (index & 7));
	else
		bitmap->bits[index/8] &= ~(1 << (index & 7));
}

/// Locate the first free bit in the bitmap (0-indexed), set it to 1 and return its index.
/// @param bitmap.
/// @return return its index or -1 if the bitmap is full.
int bitmap_reserve_first_available_bit(bitmap_t *bitmap) {
	for (uint_t i = 0; i < bitmap->count; i++) {
		if (bitmap_get(bitmap, i) == 0) {
			bitmap_set(bitmap, i, 1);
			return i;
		}
	}
	return -1;
}

/// Return the total number of free bits in the bitmap.
/// @param bitmap.
/// @return number of free bits in the bitmap.
uint_t bitmap_get_free_bits(bitmap_t *bitmap) {
	uint_t count = 0;
	for (uint_t i = 0; i < bitmap->count; i++) {
		if (bitmap_get(bitmap, i) == 0)
			count++;
	}
	return count;
}
