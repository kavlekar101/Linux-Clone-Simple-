/* Shashwat Rao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeFiles.h"

/* only removes the folder if it is empty */
void removeFolderIfEmpty(Folder **head, char *rest){
	int index = findFolder(*head, rest);
	Folder *toRemove;
	if(index != -1){
		/* remove the folder, free the pointer, reduce the number of folders in the parent directory, which is the current directory, and move a folder at the end to fill in the space in which it was taken out.*/
		if ((**head).folders[index]->fileNum == 0 && (**head).folders[index]->folderNum == 0) {
			/*toRemove = (**head).folders[index];
			free(toRemove);
			toRemove = NULL;*/
			free((**head).folders[index]);
			(**head).folders[index] = NULL;
			(**head).folderNum--;
			fillFolderInIndex(head, index);
		} else {
			printf("Don't remove folders that contain stuff. pls.\n");
		}
	} else {
		printf("Please enter the name of a folder that exists");
	}
}
