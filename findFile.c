/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* finds the index of the file */
int findFile(Folder **head, char *fileName){
	int i;
	for(i = 0; i < (*head)->fileNum; i++) {
		if(strcmp((**head).files[i]->name, fileName) == 0) {
			return i;
		}
	}
	return -1;
}
