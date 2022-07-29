/* Shashwat Rao */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fakeFiles.h"

/* copies a given folder and its contents */
void copyFolder(Folder **head) {
    char firstFolderPath[64];
    char firstFolderPathCopy[64];
    char secondFolderPath[64];
    char firstFolderName[64];
    char secondFolderName[64];
    char secondFolderOriginalName[64];
    char currentDir[64];
    Folder *firstFolder;
    Folder *secondFolder;
    int index = -1;
    memset(firstFolderName, 0, 64);
    memset(secondFolderName, 0, 64);
    memset(firstFolderPath, 0, 64);
    memset(secondFolderPath, 0, 64);

    moveBackToFolder(head, "~"); /* Go back to the start (allows to move folders anywhere)*/

    /* First we get the first directory name. ->
        Store the current directory name. */
    printf("Enter the path of the current folder (from the root directory): ");
    fgets(currentDir, 64, stdin);
    currentDir[strcspn(currentDir, "\n")] = '\0'; /* Gets rid of the newline character in the string */
    printf("Enter the first path of the folder (from the root directory) to be copied: ");
    fgets(firstFolderPath, 64, stdin);
    firstFolderPath[strcspn(firstFolderPath, "\n")] = '\0'; /* Gets rid of the newline character in the string */
    strcpy(firstFolderPathCopy, firstFolderPath);
    printf("\nEnter the name of the folder to be copied: ");
    fgets(firstFolderName, 64, stdin);
    firstFolderName[strcspn(firstFolderName, "\n")] = '\0'; /* Gets rid of the newline character in the string */
    printf("\nEnter the second path (from the root directory) to be copied to: ");
    fgets(secondFolderPath, 64, stdin);
    secondFolderPath[strcspn(secondFolderPath, "\n")] = '\0'; /* Gets rid of the newline character in the string */
    printf("\nEnter the name of the folder to be copied to : ");
    fgets(secondFolderName, 64, stdin);
    secondFolderName[strcspn(secondFolderName, "\n")] = '\0'; /* Gets rid of the newline character in the string */

    /*Then change to the directory that contains it ->
        Make sure that the directory contains it ->*/
    changeDirectories(head, firstFolderPath);
    index = findFolder(*head, firstFolderName);
    if(index == -1) {
        printf("Please enter the name of a folder that is in the specified folder path without \"/\"\n");
    } else {
        firstFolder = (**head).folders[index]; /* Get a pointer to the folder should be easy because it is stored as a folder -> */

        /*change back to the original directory ->
        Then change to the directory that contains other folder ->*/
        moveBackToFolder(head, "~"); /* go back to start (this allows folders to be copied anywhere)*/
        changeDirectories(head, secondFolderPath);
        index = findFolder(*head, secondFolderName);
        if (index == -1){
            secondFolder = makeFolder(*head, firstFolderName);
            (*head)->folders[(*head)->folderNum] = secondFolder;
            (*head)->folderNum++;
        } else {
            /* if there is another folder to overwrite */
            secondFolder = (**head).folders[index];
        }
        if(secondFolder != NULL) {
            /* recursivly copy the nodes */
            strcpy(secondFolderOriginalName, secondFolderName);
            copyNode(*head, firstFolder, secondFolder); /* don't need to allocate memory because we already did that */
            strcpy(secondFolder->name, secondFolderOriginalName); /* Because it copies that root directories name too */
        }
    }
    moveBackToFolder(head, "~");
    changeDirectories(head, currentDir);
}