/* Shashwat Rao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeFiles.h"

/* finds the index of the folder */
int findFolder(Folder *head, char *token) {
	int i = 0;
	int index = -1;
	for(; i < head->folderNum; i++) {
		/* The name should never point to null because the string is initialized with all zeros*/
		if(strcmp(token, head->folders[i]->name) == 0) {
			index = i;
			break;
		}
	}
	return index;
}
