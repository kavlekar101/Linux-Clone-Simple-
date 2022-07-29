/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* remove all of the folders listed after the rmdir command */
void removeFoldersIfEmpty(Folder **head, char *rest){
	char *token = getNextDirName(rest, " "); /* Modularity, lets go. Could probably be more modular and send this as a fundtion pointer maybe to reduce the other file that does something similar to this, but that is too much work and I am tired. */
	Folder *newFolder;
	if(token == NULL) {
		printf("Please enter an actual directory name.\n");
	}
	while(token != NULL) {
		if(findFolder(*head, token) == -1){
			printf("That folder doesn't exist, so we cannot remove it\n", token);
			token = getNextDirName(NULL, " ");
			continue;
		}
		removeFolderIfEmpty(head, token);
		token = getNextDirName(NULL, " ");
	}
}
