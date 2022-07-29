/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* executes the command based on the user input */
void executeCommand(char *command, char **quit, char *rest, Folder **head) {
	Folder *newFolder;
	char *affirmative = "yes";
	/* Strcmp returns 0 if the strings are equal */
	if(strcmp(command, "quit") == 0) {
		*quit = affirmative;
	} else if(strcmp(command, "cd") == 0) { 
		changeDirectories(head, rest);
	} else if(strcmp(command, "ls") == 0) {
		listDirectoryContents(*head);
	} else if(strcmp(command, "pwd") == 0) {
		printWorkingDirectory(*head);
	} else if(strcmp(command, "cat") == 0) {
		printFile(head, rest);
	} else if(strcmp(command, "cpFolder") == 0) {
		copyFolder(head);
	} else if (strcmp(command, "cpFile") == 0) {
		copyFile(head);
	} else if (strcmp(command, "mvFolder") == 0) {
		moveFolder(head);
	} else if (strcmp(command, "mvFile") == 0) {
		moveFile(head);
	} else if (strcmp(command, "rm") == 0) {
		removeFiles(head, rest);
	} else if (strcmp(command, "mkdir") == 0) {
		makeFolders(head, rest);
	} else if (strcmp(command, "rmdir") == 0){
		removeFoldersIfEmpty(head, rest);
	} else if (strcmp(command, "file") == 0) {
		createFile(head, rest);
	} else if (strcmp(command, "help") == 0) {
		printCommandInfo();
	} else if (strcmp(command, "longestFolderName") == 0) {
		longestFolderName(*head);
	} else if (strcmp(command, "longestFileName") == 0) {
		longestFileName(*head);
	} else if (strcmp(command, "numberOfFilesAndFolders") == 0) {
		numberOfFilesAndFolders(*head);
	} else if (strcmp(command, "dirPrint") == 0) {
		dirPrint(*head);
	} else {
		printf("Please enter a valid command!\n");
	}
}
