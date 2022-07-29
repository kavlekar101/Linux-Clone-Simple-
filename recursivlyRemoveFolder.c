/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

void recursivlyRemoveFolder(Folder *head, Folder **p2ToRemove) {
    int i, j;

    /* removes all of the files */
    for (j = 0; j < (*p2ToRemove)->fileNum; j++) {
        removeFile(&head, (*p2ToRemove)->files[i]->name);
    }

    /* if there are empty folders it removes those, or else it keeps going until there is an empty folder to delete */
    if((*p2ToRemove)->folderNum == 0) {
        free(*p2ToRemove);
        *p2ToRemove = NULL;
    } else {
        for (i = 0; i < (*p2ToRemove)->folderNum; i++) {
            recursivlyRemoveFolder(head, &((*p2ToRemove)->folders[i]));
        }
        (*p2ToRemove)->folderNum = 0;
    }
    return;
}