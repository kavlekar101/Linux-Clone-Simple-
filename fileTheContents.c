/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* Gets the contents of the new file line by line.*/
void fileTheContents(struct File *newFile){
	printf("Enter the contents line by line. Each line is limited to 64 characters. If you don't want to enter more text, just press enter until it stops telling you enter input.\n");
	readFullLine("Enter the first line: ", newFile->contents[0]);
	readFullLine("Enter the second line: ", newFile->contents[1]);
	readFullLine("Enter the third line: ", newFile->contents[2]);
	readFullLine("Enter the fourth line: ", newFile->contents[3]);
}
