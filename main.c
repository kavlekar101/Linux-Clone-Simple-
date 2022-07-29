/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* how the program starts up */
int main() {
	Folder home = {
		"~",
		0,
		0
	};
	Folder *head = &home;
	char userInput[64];
	char command[64];
	char rest[64];
	char *quit = "no";
	memset(command, 0, 64);
	memset(rest, 0, 64);
	printf("\nPrint any command. Whenever you want to quit enter the 'quit' command, the program will quit.\n");
	printf("Any directory names should not have spaces in them.\n");
	printf("All of the commands work like the linux commands. The commands that require spaces between the command and arguments do that, and those that don't, don't need spaces.\n");
	printf("No extra flags have been added to any of the commands.\n");
	printf("For cp and mv, you have to specify if you are going to copy or move a folder or file by doing cpfolder, cpfile, same for mv\n");
	while(1) {
		printf("[dummyUser %s]$ ", head->name);
		/* Reads in until the newline, then the %*c clears the newline character */
		readFullLine("", userInput);
		readInCommand(userInput, command, rest);
		executeCommand(command, &quit, rest, &head);
		if(strcmp(quit, "yes") == 0) {
			break;
		}
		memset(command, 0, 64);
		memset(userInput, 0, 64);
		memset(rest, 0, 64); /* clear all 64 bits just to make this easier and safer*/
	}
	return 0;
}
