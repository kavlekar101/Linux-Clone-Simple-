/* Shashwat Rao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeFiles.h"

/* gets the next name by 'splitting' the string based on the split string */
char* getNextDirName(char *rest, char *split) {
	/* The tokens string just has a null byte where the first / was */
	return strtok(rest, split);
}
