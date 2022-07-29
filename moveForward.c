/* Shashwat Rao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeFiles.h"

/* moves the head pointer forward one after finding the folder that has the name */
void moveForward(Folder **head, char *token){
	int i = findFolder(*head, token);
	if(i != -1){
		*head = (*head)->folders[i];
	} else {
		printf("The directory called \"%s\" could not be found.\n", token);
	}
}
