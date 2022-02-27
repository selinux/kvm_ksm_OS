#ifndef _SUPERBLOCK_COMMON_H_
#define _SUPERBLOCK_COMMON_H_

#include <stdint.h>

// FS_SIGNATURE_LENGTH includes the end of string character (0)
#define FS_SIGNATURE_LENGTH 4
#define FS_SIGNATURE "BFS"

#define VERSION_MAJOR 1
#define VERSION_MINOR 0

#define SUPERBLOCK_LABEL_LENGTH 32

// Superblock of the filesystem (must fit in a sector)
typedef struct __attribute__ ((__packed__)) {
	int8_t   signature[FS_SIGNATURE_LENGTH];
	uint8_t  version_major;
	uint8_t  version_minor;
	int8_t   label[SUPERBLOCK_LABEL_LENGTH];  // includes the end of string character (0)
	uint32_t block_size;                      // block size in bytes
	
	uint32_t inode_bitmap_start;              // at which block the inode bitmap starts
	uint32_t inode_bitmap_block_count;        // #blocks for the inode bitmap

	uint32_t datablock_bitmap_start;          // at which block the block bitmap starts
	uint32_t datablock_bitmap_block_count;    // #blocks for the block bitmap

	uint32_t inode_start;                     // at which block the inode table starts
	uint32_t inode_count;                     // inode count (1 inode = 64 bytes)
	uint32_t inode_block_count;               // #blocks for the inode table
	
	uint32_t datablocks_start;                // at which block the data blocks start
	uint32_t datablock_count;                 // #data blocks
} superblock_t;

#endif
