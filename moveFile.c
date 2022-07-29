/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* copies a file */
void moveFile(Folder **head) {
    char firstFilePath[64];
    char firstFilePathCopy[64];
    char secondFilePath[64];
    char currentDir[64];
    char firstFileName[64];
    char secondFileName[64];
    struct File *firstFile;
    struct File *secondFile;
    int index = -1;

    /* eventually put this code into different files to make it more modular, but right now we just gotta finish */

    /* First we get the first directory name. ->
        Store the current directory name. */
    printf("Enter the path of the current path (from root): ");
    fgets(currentDir, 64, stdin);
    currentDir[strcspn(currentDir, "\n")] = '\0'; /* Gets rid of the newline character in the string */
    printf("Enter the first path of the file (from the root) to be copied: ");
    fgets(firstFilePath, 64, stdin);
    firstFilePath[strcspn(firstFilePath, "\n")] = '\0'; /* Gets rid of the newline character in the string */
    strcpy(firstFilePathCopy, firstFilePath);
    printf("\nEnter the name of the file to be copied: ");
    fgets(firstFileName, 64, stdin);
    firstFileName[strcspn(firstFileName, "\n")] = '\0'; /* Gets rid of the newline character in the string */
    printf("\nEnter the second path (from the root) to be copied to: ");
    fgets(secondFilePath, 64, stdin);
    secondFilePath[strcspn(secondFilePath, "\n")] = '\0'; /* Gets rid of the newline character in the string */
    printf("\nEnter the name of the file to be copied: ");
    fgets(secondFileName, 64, stdin);
    secondFileName[strcspn(secondFileName, "\n")] = '\0'; /* Gets rid of the newline character in the string */

    /*Then change to the directory that contains it ->
        Make sure that the directory contains it ->*/
    moveBackToFolder(head, "~"); /* Go back to the start (allows to move folders anywhere)*/
    changeDirectories(head, firstFilePath);
    index = findFile(head, firstFileName);
    if(index == -1) {
        printf("Please enter the name of a folder that is in the specified folder path without \"/\"\n");
    } else {
        firstFile = (**head).files[index];  /*Get a pointer to the file should be easy because it is stored as a pointer ->*/
        (**head).files[index] = NULL;
        (*head)->fileNum--;
        moveBackToFolder(head, "~"); /* change back to the start -> */

        /* Then change to the directory that contains other file ->
        Make sure that the directory contains it ->*/
        changeDirectories(head, secondFilePath);
        index = findFile(head, secondFileName);
        if (index == -1){
            (**head).files[(*head)->fileNum] = firstFile;
            strcpy((**head).files[(*head)->fileNum]->name, secondFileName);
            (*head)->fileNum++;
        } else {
            secondFile = (**head).files[index];
            removeFile(head, secondFile->name);
            (**head).files[(*head)->fileNum] = firstFile;
            (*head)->fileNum++;
        }
    }
    moveBackToFolder(head, "~"); /* change back to the original directory -> */
    changeDirectories(head, currentDir);
}