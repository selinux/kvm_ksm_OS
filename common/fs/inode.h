#ifndef _INODE_COMMON_H_
#define _INODE_COMMON_H_

#include "../types.h"
#include "bitmap.h"

#define INODE_FILENAME_LENGTH  32

#define INODE_DIRECT_PTR_CNT    4
#define INODE_INDIRECT_PTR_CNT  9

// An inode's size is 64 bytes
typedef struct __attribute__ ((__packed__)) {
	uint16_t number;                                // inode number matching the index in the inode bitmap
	int8_t   name[INODE_FILENAME_LENGTH];           // file name including the trailing zero
	uint32_t size;                                  // file size in bytes
	uint16_t direct_ptr[INODE_DIRECT_PTR_CNT];      // pointers to direct data blocks
	uint16_t indirect_ptr[INODE_INDIRECT_PTR_CNT];  // pointers to indirect data blocks
} inode_t;

typedef struct {
	uint_t inode_count;   // number of inodes in the table
	uint_t size;          // size of the inode table in bytes
	inode_t *inodes;
} inode_table_t;

inode_t *inode_get(inode_table_t *itab, uint_t index);
inode_t *inode_reserve_first_available(inode_table_t *itab, bitmap_t *inode_bitmap);
inode_t *inode_get_from_inode(inode_table_t *itab, uint_t inode_number);
inode_t *inode_get_from_filename(inode_table_t *itab, char *filename);

#endif
