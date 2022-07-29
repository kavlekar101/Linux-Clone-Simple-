/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* Returns the last part of the string, based on the given char to split on*/
char *getLastPart(char *path, char split) {
    return strrchr(path, split);
}