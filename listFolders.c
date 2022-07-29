/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* None of the folder entries in the array should be null before the last folder entry because of the function that moves up to fill the null position */
/* Lists all of the folders in the current directory */
void listFolders(Folder *head) {
	int i = 0;
	printf("Folders:");
	for(; i < head->folderNum; i++) {
		printf(" %s,", head->folders[i]->name);
	}
}
