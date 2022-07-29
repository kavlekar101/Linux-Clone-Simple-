/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* Moves the head pointer all the way to the home directory and prints the name of the folder along the way */
void printWorkingDirectory(Folder *head){
	if(strcmp(head->name, "~") != 0) {
		printWorkingDirectory(head->prev);
		printf("/%s", head->name);
	} else {
		printf("~");
	}
}
