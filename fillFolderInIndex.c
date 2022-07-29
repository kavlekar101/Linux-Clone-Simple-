/* Shashwat Rao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeFiles.h"

/* moves the end folder to fill in the space left by the deleted folder, if the folder was removed from the middle of the array */
void fillFolderInIndex(Folder **head, int index){
    /* we already decreased the number of Folders in the array, so if the index is equal to the folderNum, then no need to move */
    if(index != (*head)->folderNum){
        /* So if the file wasn't removed from the right end, there is a spot we have to fill in
            ,so we take a folder from the end and fill it in the spot from which the folder was taken.
            This is so that the folders are continuous. */
        (*head)->folders[index] = (*head)->folders[((*head)->folderNum)];
        (*head)->folders[((*head)->folderNum)] = NULL; /* Set to null after transferred so that nothing weird happens*/
    }
}
