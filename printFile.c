/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* prints the contents of a specified file */
void printFile(Folder **head, char *rest){
	/* First make sure you have a copy of the path to the file that you are trying to cat 
		then make sure you have the name of the current folder, */
	char *fileName = getLastPart(rest, '/');
	char *folderName = (*head)->name;
	char currentDir[64];
	char folderPath[64];
	int index;
	if(fileName == NULL){
		if(rest[0] != '\0') {
			index = findFile(head, rest);
			if(index != -1){
				printFileContents(head, index);
			} else {
				printf("The file is not in the current directory, please try again. Or you may not have included a \"/\" before the name, please include that.\n");
			}
		} else {
			printf("Please enter the folder using the correct syntax.Or you may not have included a \"/\" before the name, please include that.\n");
		}
	} else {
		fileName++; /* Because it includes the '/' for the filename when splitting it from behind */
		memcpy(folderPath, rest, fileName - rest - 1); /* has to write to the destination string, so the string has to be a read write string */
		printf("Enter the path from the root directory to the current directory.");
		fgets(currentDir, 64, stdin);
		currentDir[strcspn(currentDir, "\n")] = '\0'; /* Gets rid of the newline character in the string */

		moveBackToFolder(head, "~");
		/* then change directories to that folder if you need to */
		changeDirectories(head, folderPath);
		index = findFile(head, fileName);
		if(index != -1){
			printFileContents(head, index);
		} else {
			printf("The file is not in the current directory, please try again. Or you may not have included a \"/\" before the name, please include that.\n");
		}
		moveBackToFolder(head, "~");
		changeDirectories(head, currentDir);
	}
}
