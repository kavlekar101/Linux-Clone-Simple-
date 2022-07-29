/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* Creates the file, gives it the specified name, and gets the contents of the file from the user. */
void createFile(Folder **head, char *rest){
	/* Create a file using malloc, set it's name, and ask for the contents of the file. */
	struct File *newFile = createMemoryForFile();
	int index = findFile(head, rest);
	/* Because the createMemoryForFile function can fail to allocate memory for the file, we have to check to make sure that it is not NULL */
	if(index == -1) {
		if(newFile != NULL) {
			strcpy(newFile->name, rest);
			fileTheContents(newFile);
			(*head)->files[(*head)->fileNum] = newFile;
			(*head)->fileNum++;
		} else {
			printf("Failed to create a file for the file name \"%s\". Please try again\n", rest);
		}
	} else {
		printf("You are now editing the file. Congrats!\n");
		fileTheContents((*head)->files[index]);
	}
}
