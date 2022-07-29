/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* Tries to allocate memory for a file, if it fails, returns a null pointer. */
struct File *createMemoryForFile(){
	return (struct File *) calloc(1, sizeof(struct File));
}
