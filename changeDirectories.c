/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* Changes directories by moving the head pointer to pointer to the desired location specified by the string, which has / between directories*/
void changeDirectories(Folder **head, char *rest) {
	char *token = getNextDirName(rest, "/");
	if(token == NULL){
		/* We know the user entered the command 'cd' */
		moveBackToFolder(head, "~");
	}
	while(token != NULL) {
		if(strcmp(token, "..") == 0){
			if(strcmp((**head).name, "~") != 0){
				moveBackward(head); /* moves the pointer back one */
			} else {
				printf("Sorry you're trying to move out of the tree.\n");
				token = NULL;
				continue;
			}
		} else if (strcmp(token, ".") == 0){
			token = getNextDirName(NULL, "/");
			continue;
		} else if (token[0] == '~'){
			moveBackToFolder(head, "~"); /* moves back to start of the the tree*/
		} else if(token[0] == '-') {
			printWorkingDirectory(*head);
			printf("\n");
			moveBackToFolder(head, "~");
		} else {
			moveForward(head, token); /* have to implement cd - which prints */
		}
		token = getNextDirName(NULL, "/");
	}
}
