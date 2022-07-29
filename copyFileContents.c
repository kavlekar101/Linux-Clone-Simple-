/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* copies the file contents */
void copyFileContents(struct File *firstFile, struct File *secondFile) {
    strcpy(secondFile->name, firstFile->name);
    strcpy(secondFile->contents[0], firstFile->contents[0]);
    strcpy(secondFile->contents[1], firstFile->contents[1]);
    strcpy(secondFile->contents[2], firstFile->contents[2]);
    strcpy(secondFile->contents[3], firstFile->contents[3]);
}