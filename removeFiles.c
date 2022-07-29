/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* remove all of the files listed after the rm command */
void removeFiles(Folder **head, char *rest){
	char *token = getNextDirName(rest, " "); /* In this case it gets the next file name. A little misnomer, but I just wanna get this done. */
	if(token == NULL) {
		printf("Please enter an actual file name.\n");
	}
	while(token != NULL) {
		removeFile(head, token);
		token = getNextDirName(NULL, " "); /* Gets the next file name */
	}
}
