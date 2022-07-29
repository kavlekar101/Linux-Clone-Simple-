/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* None of the folder entries in the array should be null before the last folder entry because of the function that moves up to fill the null position */
/* Lists all of the files in the current directory */
void listFiles(Folder *head) {
	int i;
	printf("Files:");
	for(i = 0; i < head->fileNum; i++) {
		printf(" %s,", head->files[i]->name);
	}
}
