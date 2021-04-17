#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define USER_PATH "/home/ananda"
#define PETSHOP_PATH "/home/ananda/modul2/petshop"

void unzip(char *source, char *destination) {
    int status;

    printf("[!] UNZIPPING PETS.ZIP\n");
    
    pid_t unzipID = fork();

    if(unzipID == 0) {
        char *args[] = {"unzip", "-q", source, "-d", destination, NULL};
        execv("/usr/bin/unzip", args);
    }
    
    waitpid(unzipID, &status, 0);
}

void makeDir(char *path) {
    int status;

    pid_t makeDir = fork();
    if(makeDir == 0) {
        char *args[] = {"mkdir", "-p", path, NULL};
        execv("/usr/bin/mkdir", args);
    }
    waitpid(makeDir, &status, 0);
}

void delDir(char *path) {
    int status;

    pid_t delFile = fork();
    if(delFile == 0) {
        printf("[!] Deleting source >> %s <<\n", path);
        char *args[] = {"rm", "-rf", path, NULL};
        execv("/usr/bin/rm", args);
    }

    while(wait(&status) > 0);
}

void removeUnnecessaryFolder(char const *folderPath) {
    int status;

    struct dirent *item;
    DIR *petFolder;

    // Open folder
    if((petFolder = opendir(folderPath)) != NULL) {

        // Loops through the item entries in the folder
        while((item = readdir(petFolder)) != NULL) {
            if(strcmp(item->d_name, "..") && strcmp(item->d_name, ".")) {
                if(item->d_type == DT_DIR) {
                    char toRemovePath[512];
                    sprintf(toRemovePath, "%s%s", folderPath, item->d_name);

                    printf("[!] Removing %s Folder\n", item->d_name);

                    pid_t removeFolderItem = fork();

                    if(removeFolderItem == 0) {
                        char *args[] = {"rm", "-rf", toRemovePath, NULL};
                        execv("/bin/rm", args);
                    }

                    waitpid(removeFolderItem, &status, 0);
                }
            } else {
                continue;
            }
        }
    }
}

void categorizePhoto(char *sourcePhoto, char *filename) {
    int status;
    char *jenis, *nama, *umur;
    char pathJenis[512], pathKeterangan[512], newFilename[512];

    jenis = strtok(filename, ";");
    nama = strtok(NULL, ";");
    umur = strtok(NULL, ";");

    sprintf(pathJenis, "%s/%s", PETSHOP_PATH, jenis);
    sprintf(pathKeterangan, "%s/%s/keterangan.txt", PETSHOP_PATH, jenis);
    sprintf(newFilename, "%s/%s/%s.jpg", PETSHOP_PATH, jenis, nama);

    // Make the jenis directory
    makeDir(pathJenis);

    // Copy the original file to the directory and rename it to <nama>.jpg
    pid_t copyFile = fork();
    if(copyFile == 0) {
        char *args[] = {"cp", sourcePhoto, newFilename, NULL};
        execv("/usr/bin/cp", args);
    }
    waitpid(copyFile, &status, 0);

    // Insert the animal name to keterangan.txt
    char ketContent[128];
    sprintf(ketContent, "nama : %s \numur : %s\n\n", nama, umur);

    FILE *ketFile;
    ketFile = fopen(pathKeterangan, "a");

    if(ketFile) {
        fprintf(ketFile, "%s", ketContent);
        fclose(ketFile);
    }
}

void categorize(char const * folderPath) {
    int status;

    struct dirent *item;
    DIR *petFolder;

    // Open folder
    if((petFolder = opendir(folderPath)) != NULL) {

        // Loops through the item entries in the folder
        int loop = 0;
        while((item = readdir(petFolder)) != NULL) {
            if(strcmp(item->d_name, "..") && strcmp(item->d_name, ".")) {
                if(item->d_type == DT_REG) {
                    char fileName[256], sourcePath[512];

                    sprintf(sourcePath, "%s/%s", PETSHOP_PATH, item->d_name);

                    printf("[!] Processing >> %s <<\n", sourcePath);

                    sprintf(fileName, "%s", item->d_name);
                    fileName[strlen(fileName)-4] = '\0';

                    char *leftPet = strtok(fileName, "_");
                    char *rightPet = strtok(NULL, "_");

                    if(rightPet != NULL) {
                        categorizePhoto(sourcePath, rightPet);
                    }

                    categorizePhoto(sourcePath, leftPet);

                    pid_t delFile = fork();
                    if(delFile == 0) {
                        printf("[!] Deleting source >> %s <<\n", sourcePath);
                        char *args[] = {"rm", "-rf", sourcePath, NULL};
                        execv("/usr/bin/rm", args);
                    }

                    while(wait(&status) > 0);
                }
            }
        }
    }
}

int main() {
    int status;
    char petshopFolder[512];

    sprintf(petshopFolder, "%s/", PETSHOP_PATH);

    unzip("./pets.zip", PETSHOP_PATH);

    removeUnnecessaryFolder(petshopFolder);

    categorize(petshopFolder);
}