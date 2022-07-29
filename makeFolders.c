/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* makes a lot of folders specified by the rest string and split by / within the string */
void makeFolders(Folder **head, char *rest){
	char *token = getNextDirName(rest, " "); /* Modularity, lets go. Could probably be more modular and send this as a fundtion pointer maybe to reduce the other file that does something similar to this, but that is too much work and I am tired. */
	Folder *newFolder;
	if(token == NULL) {
		printf("Please enter an actual directory name.\n");
	}
	while(token != NULL) {
		/* Just to make sure that there aren't the same folders that are going to be created */
		if(findFolder(*head, token) != -1){
			printf("Folder with the name \"%s\" has already been created in this directory, please, in the future, do not duplicate folder names.\n", token);
			token = getNextDirName(NULL, " ");
			continue;
		}
		newFolder = makeFolder(*head, token);
		if(newFolder != NULL) {
			(*head)->folderNum++;
			insertFolder(newFolder, head);
		}
		token = getNextDirName(NULL, " ");
	}
}
