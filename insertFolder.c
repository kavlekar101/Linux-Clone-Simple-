/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* inserts the folder in the new location */
void insertFolder(Folder *newFolder, Folder **head) {
	(*head)->folders[(*head)->folderNum - 1] = newFolder;
}
