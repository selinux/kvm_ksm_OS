#include "../string.h"
#include "inode.h"

/// Retrieve an inode from the inode table.
/// @param *itab inode table.
/// @param index index of the inode to retrieve.
/// @return pointer to the inode at the specified index.
inode_t *inode_get(inode_table_t *itab, uint_t index) {
	return &itab->inodes[index];
}

/// Return the first free inode and mark it as used.
/// @param itab inode table.
/// @param inode_bitmap inodes' bitmap.
/// @return a pointer to the first available inode or NULL if the table is full.
inode_t *inode_reserve_first_available(inode_table_t *itab, bitmap_t *inode_bitmap) {
	int i = bitmap_reserve_first_available_bit(inode_bitmap);
	if (i < 0)
		return NULL;    // no more available inodes
	inode_t *inode = inode_get(itab, i);
	inode->number = i;  // alread set the inode number to the indice in the table
	return inode;
}

/// Return the file (inode) matching the specified inode number.
/// If there is no match, NULL is returned.
/// @param itab inode table.
/// @param inode_number the inode number.
/// @return a pointer to the matching inode or NULL if none found.
inode_t *inode_get_from_inode(inode_table_t *itab, uint_t inode_number) {
	for (uint_t i = 0; i < itab->inode_count; i++) {
		inode_t *inode = inode_get(itab, i);
		if (inode->number == inode_number)
			return inode;
	}
	return NULL;
}

/// Return the file (inode) matching the specified filename.
/// If there is no match, NULL is returned.
/// @param itab inode table.
/// @param filename the filename to look for.
/// @return a pointer to the matching inode or NULL if none found.
inode_t *inode_get_from_filename(inode_table_t *itab, char *filename) {
	for (uint_t i = 0; i < itab->inode_count; i++) {
		inode_t *inode = inode_get(itab, i);
		if (inode->number > 0) {  // inode numbers > 0 are in use
			if (strncmp(filename, (char *)inode->name, INODE_FILENAME_LENGTH-1) == 0)
				return inode;
		}
	}
	return NULL;
}
