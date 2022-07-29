/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

void dirPrint(Folder *head) {
    /* do it recursivly, so keep calling it until the name is ~ then print */
    if(strcmp(head->name, "~") != 0) {
        dirPrint(head->prev);
        printf("%s contains [", head->name);
        listFolders(head);
        printf("]\n");
    } else {
        printf("~ contains [");
        listFolders(head);
        printf("]\n");
    }
    return;
}