#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <wait.h>
#include <glob.h>
#include <time.h>

void donlotDanBuatFolder();
void unzipDuls();
void terusMove();
void finishing();
void deleteZip();
void makeFolder();
void downloadFilm();
void downloadMusik();
void downloadPhoto();
void unzipFilm();
void unzipMusik();
void unzipPhoto();
void moveFilm();
void moveMusik();
void movePhoto();
void delFoto();
void delMusik();
void delFilm();
void delPyoto();
void delMusyik();
void delFylm();
void bikinZip();
void ngezip();

int main()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer, 80,"%m-%d_%H:%M",timeinfo);
    while(strcmp(buffer, "04-09_16:22") != 0)
    {
        sleep(2);
        rawtime = time(NULL);
        timeinfo = localtime(&rawtime);
        strftime (buffer, 80,"%m-%d_%H:%M",timeinfo);
    }
    pid_t child_id;
    int status;
    child_id = fork();
    if(child_id == 0)
        donlotDanBuatFolder();
    else
    {
        while((wait(&status)) > 0);
        unzipDuls();
    }
}

void donlotDanBuatFolder()
{
    pid_t buatFolder;
    int waitt;
    buatFolder = fork();
    if(buatFolder < 0)
        exit(EXIT_FAILURE);
    if(buatFolder == 0)
    {
        makeFolder();
    }
    else
    {
        while((wait(&waitt)) > 0);
        pid_t donlotF;
        int waitt1;
        donlotF = fork();
        if(donlotF < 0)
            exit(EXIT_FAILURE);
        if(donlotF == 0)
            downloadFilm();
        else
        {
            while((wait(&waitt1)) > 0);
            pid_t donlotM;
            int waitt2;
            donlotM = fork();
            if(donlotM < 0)
                exit(EXIT_FAILURE);
            if(donlotM == 0)
                downloadMusik();
            else
            {
                while((wait(&waitt2)) > 0);
                downloadPhoto();
            }
        }
    }
}

void unzipDuls()
{
    pid_t unzipF;
    int wait1;
    unzipF = fork();
    if(unzipF < 0)
        exit(EXIT_FAILURE);
    if(unzipF == 0)
        unzipFilm();
    else
    {
        while((wait(&wait1)) > 0);
        pid_t unzipM;
        int wait2;
        unzipM = fork();
        if(unzipM < 0)
            exit(EXIT_FAILURE);
        if(unzipM == 0)
            unzipMusik();
        else
        {
            while((wait(&wait2)) > 0);
            pid_t unzipP;
            int wait3;
            unzipP = fork();
            if(unzipP < 0)
                exit(EXIT_FAILURE);
            if(unzipP == 0)
                unzipPhoto();
            else
            {
                while((wait(&wait3)) > 0);
                terusMove();
            }
        }
    }
}

void terusMove()
{
    pid_t moveF;
    int film;
    moveF = fork();
    if(moveF < 0)
        exit(EXIT_FAILURE);
    if(moveF == 0)
        moveFilm();
    else
    {
        while((wait(&film)) > 0);
        pid_t moveM;
        int musik;
        moveM = fork();
        if(moveM < 0)
            exit(EXIT_FAILURE);
        if(moveM == 0)
            moveMusik();
        else
        {
            while((wait(&musik)) > 0);
            pid_t moveP;
            int photo;
            moveP = fork();
            if(moveP < 0)
                exit(EXIT_FAILURE);
            if(moveP == 0)
                movePhoto();
                        
            else
            {
                while((wait(&photo)) > 0);
                finishing();
            }
        }
    }
}

void finishing()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer, 80,"%m-%d_%H:%M",timeinfo);
    while(strcmp(buffer, "04-09_22:22") != 0)
    {
        sleep(2);
        rawtime = time(NULL);
        timeinfo = localtime(&rawtime);
        strftime (buffer, 80,"%m-%d_%H:%M",timeinfo);
    }
    pid_t tutup1;
    int yah1;
    tutup1 = fork();
    if(tutup1 < 0)
        exit(EXIT_FAILURE);
    if(tutup1 == 0)
        delFilm();
    else
    {
        while((wait(&yah1)) > 0);
        pid_t tutup2;
        int yah2;
        tutup2 = fork();
        if(tutup2 < 0)
            exit(EXIT_FAILURE);
        if(tutup2 == 0)
            delFoto();
        else
        {
            while((wait(&yah2)) > 0);
            pid_t tutup3;
            int yah3;
            tutup3 = fork();
            if(tutup3 < 0)
                exit(EXIT_FAILURE);
            if(tutup3 == 0)
                delMusik();
            else
            {
                while((wait(&yah3)) > 0);
                bikinZip();
            }
        }
    }
}

void bikinZip()
{
    pid_t zi1;
    int yi1;
    zi1 = fork();
    if(zi1 < 0)
        exit(EXIT_FAILURE);
    if(zi1 == 0)
        ngezip();
    else
    {
        while((wait(&yi1)) > 0);
        pid_t zi2;
        int yi2;
        zi2 = fork();
        if(zi2 < 0)
            exit(EXIT_FAILURE);
        if(zi2 == 0)
            delFylm();
        else
        {
            while((wait(&yi2)) > 0);
            pid_t zi3;
            int yi3;
            zi3 = fork();
            if(zi3 < 0)
                exit(EXIT_FAILURE);
            if(zi3 == 0)
                delMusyik();
            else
            {
                while((wait(&yi3)) > 0);
                delPyoto();
            }
        }
    }
}

void makeFolder()
{
    char *argv[] = {"mkdir", "-p", "Musyik", "Fylm", "Pyoto", NULL};
        execv("/bin/mkdir", argv);
}

void downloadFilm()
{
    execl("/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", 
            "-O", "Film_for_Stevany.zip", (char *)NULL);
}

void downloadMusik()
{
    execl("/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", 
            "-O", "Musik_for_Stevany.zip", (char *)NULL);
}

void downloadPhoto()
{  
    execl("/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", 
            "-O", "Photo_for_Stevany.zip", (char *)NULL);
}

void unzipFilm()
{
    char *argv[] = {"unzip", "./Film_for_Stevany.zip", NULL};
    execv("/bin/unzip", argv);
}

void unzipMusik()
{
    char *argv[] = {"unzip", "./Musik_for_Stevany.zip", NULL};
    execv("/bin/unzip", argv);
}

void unzipPhoto()
{
    char *argv[] = {"unzip", "./Photo_for_Stevany.zip", NULL};
    execv("/bin/unzip", argv);
}

void moveFilm()
{
    char *argv[] = {"cp", "-r", "./FILM/", "./Fylm", NULL};
    execv("/bin/cp", argv);
}

void moveMusik()
{
    char *argv[] = {"cp", "-r", "./MUSIK/", "./Musyik", NULL};
    execv("/bin/cp", argv);
}

void movePhoto()
{            
    glob_t globbuf;

    globbuf.gl_offs = 2;
    glob("./FOTO/*.jpg", GLOB_DOOFFS, NULL, &globbuf);
    glob("./Pyoto", GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf);
    globbuf.gl_pathv[0] = "cp";
    globbuf.gl_pathv[1] = "-r";
    execvp("cp", &globbuf.gl_pathv[0]); 
}

void delFoto()
{
    char *argv[] = {"rm", "-r", "FOTO", NULL};
    execv("/bin/rm", argv);
}

void delMusik()
{
    char *argv[] = {"rm", "-r", "MUSIK", NULL};
    execv("/bin/rm", argv);
}

void delFilm()
{
    char *argv[] = {"rm", "-r", "FILM", NULL};
    execv("/bin/rm", argv);
}

void ngezip()
{
    char *argv[] = {"zip", "-r", "Lopyu_Stevany.zip", "Fylm", "Musyik", "Pyoto", NULL};
    execv("/bin/zip", argv);
}

void delPyoto()
{
    char *argv[] = {"rm", "-r", "Pyoto", NULL};
    execv("/bin/rm", argv);
}

void delMusyik()
{
    char *argv[] = {"rm", "-r", "Musyik", NULL};
    execv("/bin/rm", argv);
}

void delFylm()
{
    char *argv[] = {"rm", "-r", "Fylm", NULL};
    execv("/bin/rm", argv);
}