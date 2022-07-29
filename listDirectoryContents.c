/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* lists all of the folders and the files in the current directory */
void listDirectoryContents(Folder *head) {
	listFolders(head);
	printf("\n");
	listFiles(head);
	printf("\n");
}
