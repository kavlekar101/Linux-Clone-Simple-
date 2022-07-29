/* Shashwat Rao */

struct File {
	char name[64];
	char contents[4][64];
};
typedef struct Folder{
	char name[64];
	int fileNum;
	int folderNum;
	struct Folder *prev;
	struct File *files[64];
	/* If you wanna insert in order, consider making this a linked data structure that points to the next folder and points to its children, so each node has like 3 pointers, one to the parent, one tho the next one alphabetically, if it exists, and then the children, if they exisit */
	struct Folder *folders[64];
}Folder;

void readInCommand(char *userInput, char *command, char *rest);
Folder* makeFolder(Folder *head, char *rest);
void executeCommand(char *command, char **quit, char *rest, Folder **head);
void insertFolder(Folder *newFolder, Folder **head);
void listDirectoryContents(Folder *head);
void listFolders(Folder *head);
void listFiles(Folder *head);
void printCommandInfo();
void moveBackToFolder(Folder **head, char *folderName);
void changeDirectories(Folder **head, char *rest);
char *getNextDirName(char *rest, char *split);
void moveForward(Folder **head, char *token);
int findFolder(Folder *head, char *token);
void moveBackward(Folder **head);
void makeFolders(Folder **head, char *rest);
void removeFolderIfEmpty(Folder **head, char *rest);
void fillFolderInIndex(Folder **head, int index);
void createFile(Folder **head, char *rest);
void fileTheContents(struct File *newFile);
struct File *createMemoryForFile();
void readFullLine(char *output, char *store);
void printFile(Folder **head, char *rest);
int findFile(Folder **head, char *fileName);
void printFileContents(Folder **head, int index);
void printWorkingDirectory(Folder *head);
void removeFoldersIfEmpty(Folder **head, char *rest);
void removeFiles(Folder **head, char *rest);
void removeFile(Folder **head, char *rest);
void fillFileInIndex(Folder **head, int index);
char *getLastPart(char *path, char split);
void copyFolder(Folder **head);
void copyNode(Folder *head, Folder *firstFolder, Folder *secondFolder);
void copyFile(Folder **head);
void copyFileContents(struct File *firstFile, struct File *secondFile);
void moveFile(Folder **head);
void moveFolder(Folder **head);
void recursivlyRemoveFolder(Folder *head, Folder **p2ToRemove);
void longestFolderName(Folder *head);
void longestFileName(Folder *head);
void numberOfFilesAndFolders(Folder *head);
void dirPrint(Folder *head);
void commandLineArgsDirectory(Folder **head, char *path);