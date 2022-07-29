#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* reads in the command as it is broken up by a space somethings i.e. cd home/something/folder */
void readInCommand(char *userInput, char *command, char *rest){
	int i;
	char ch;
	char *spacePosition;
	spacePosition = strchr(userInput, ' ');

	/* if there was no space in the command, just copy the user input into the command string */
	if(spacePosition == NULL) {
		for(;*userInput != '\0'; (command++, userInput++)) {
			*command = *userInput;
		}
	} else {
		/* if there is a space then copy everything after the space to the rest string and everything before it to the command string */
		memcpy(command, userInput, spacePosition - userInput);
		memcpy(rest, ++spacePosition, strlen(userInput) - (spacePosition - userInput + 1));
	}
}
