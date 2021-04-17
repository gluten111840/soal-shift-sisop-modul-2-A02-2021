#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

#define MKDIR_SLEEP 40
#define IMAGE_DOWNLOAD_SLEEP 5
#define IMAGE_PER_FOLDER 10

#define OUTPUTDIR "/home/ananda/Documents/output"

char *getTime() {
    time_t _time;
    struct tm *currTime;

    char *formattedTime = malloc(40 * sizeof(char));

    // Get current time 
    time(&_time);
    currTime = localtime(&_time);
    strftime(formattedTime, 40, "%Y-%m-%d_%H:%M:%S", currTime);

    return formattedTime;
}

void makeDir(char *folderTime) {

    printf("LOG: Making directory %s\n", folderTime);

    // Fork to make directory
    pid_t mkdirID = fork();

    if(mkdirID == 0) {
        char *args[] = {"mkdir", folderTime, NULL};
        execv("/bin/mkdir", args);
    }
}

void cipherAlg(char str[], int shift) {
    int stringLen = strlen(str);

    if(shift != 0) {
        for(int i = 0; i < stringLen; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = 'A' + ((str[i] - 'A' + shift) % 26);
            } else if(str[i] >= 'a' && str[i] <= 'z') {
                str[i] = 'a' + ((str[i] - 'a' + shift) % 26);
            }
        }
    }
}

void makeKiller(int mode, pid_t pid) {
    FILE *killer;
    killer = fopen("killer.sh", "w");

    if(mode == 1) {
        char *code = "#!/bin/bash\n\n"
                    "pkill -f \"./soal3\"\n"
                    "rm $0\n";
        
        fprintf(killer, "%s", code);
    } else if(mode == 2) {
        char *code = "#!/bin/bash\n\n"
                    "kill -9 %d\n"
                    "rm $0\n";
        
        fprintf(killer, code, pid);
    }

    fflush(killer);
    fclose(killer);
}

int main(int argc, char *argv[]) {
    int mode;

    if ((chdir(OUTPUTDIR)) < 0) {
        exit(EXIT_FAILURE);
    }

    if(argc > 1) {
        if(strcmp(argv[1], "-z") == 0) {
            mode = 1;
            makeKiller(mode, getpid());
        } else if(strcmp(argv[1], "-x") == 0) {
            mode = 2;
            makeKiller(mode, getpid());
        }
    }

    while(1) {
        time_t _time;
        struct tm *currTime;
        char *folderTime;

        folderTime = getTime();

        makeDir(folderTime);

        // Fork to download image
        pid_t downloaderID = fork();

        if(downloaderID == 0) {

            for(int i = 0; i < IMAGE_PER_FOLDER; i++) {
                pid_t downloadID = fork();

                if(downloadID == 0) {
                    char *downloadTime;
                    char folderPath[100], url[50];
                    
                    downloadTime = getTime();

                    sprintf(folderPath, "./%s/%s.jpg", folderTime, downloadTime);
                    sprintf(url, "https://picsum.photos/%ld", (_time%1000)+50);

                    char *args[] = {"wget", "-q", url, "-O", folderPath, NULL};
                    execv("/usr/bin/wget", args);
                }

                sleep(IMAGE_DOWNLOAD_SLEEP);
            }

            // status.txt file making
            char statusPath[50];
            sprintf(statusPath, "./%s/status.txt", folderTime);
            FILE *success;
            success = fopen(statusPath, "w+");
            
            char downloadMsg[] = "Download Success";
            cipherAlg(downloadMsg, 5);

            fprintf(success, "%s\n", downloadMsg);
            fflush(success);

            fclose(success);

            // Zipping
            char zipName[50];
            sprintf(zipName, "%s.zip", folderTime);
            
            char *args[] = {"zip", "-rm", zipName, folderTime, NULL};
            execv("/usr/bin/zip", args);
        }

        sleep(MKDIR_SLEEP);
    }

    char *args[] = {"rm", "killer.sh", NULL};
    execv("/usr/bin/rm", args);
}