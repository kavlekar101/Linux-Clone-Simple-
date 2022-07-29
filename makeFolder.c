/* Shashwat Rao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeFiles.h"

/* makes a folder using calloc or fails to */
Folder* makeFolder(Folder *head, char *rest) {
	Folder *newNode = calloc(1, sizeof(Folder));/* Use calloc because later implementations of functions depend on the contents of the file array to be null. */
	if(newNode != NULL){
		strcpy(newNode->name, rest);
		newNode->fileNum = 0;
		newNode->folderNum = 0;
		newNode->prev = head;
	} else {
		printf("Cannot make that folder as of now, please try again.");
	}
	return newNode;
}
