/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* Prints out the total number of files and folders in the directory. */
void numberOfFilesAndFolders(Folder *head) {
    printf("This folder has %d folders and files.\n", (head->fileNum) + (head->folderNum));
}