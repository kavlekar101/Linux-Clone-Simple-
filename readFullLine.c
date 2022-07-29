/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* Reads in until the \n and consumes that character as well */
void readFullLine(char *output, char *store){
	printf(output);
	/* Reads in until the newline, then the %*c clears the newline character */
	fgets(store, 64, stdin);
	store[strcspn(store, "\n")] = '\0'; /* Gets rid of the newline character in the string */
	/*getchar();*/ /* when I do cp command, I have to add this */
}
