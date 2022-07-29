/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* assume that the head is pointing to a pointer that is pointing to the folder that is holding the file */
/* prints the contents of the file */
void printFileContents(Folder **head, int index) {
	printf("%s\n%s\n%s\n%s\n", (**head).files[index]->contents[0], (**head).files[index]->contents[1], (**head).files[index]->contents[2], (**head).files[index]->contents[3]);
}
