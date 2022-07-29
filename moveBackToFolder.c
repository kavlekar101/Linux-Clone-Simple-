/* Shashwat Rao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeFiles.h"

/* moves the head pointer back to the specified folder */
void moveBackToFolder(Folder **head, char *folderName){
	while (strcmp(folderName, (*head)->name) != 0) {
		moveBackward(head);
	}
}
