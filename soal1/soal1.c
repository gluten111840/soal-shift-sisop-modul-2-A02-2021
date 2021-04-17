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
void delZipFilm();
void delZipMusik();
void delZipPhoto();
void delFoto();
void ngezip();

int main()
{
    pid_t pid, sid;        // Variabel untuk menyimpan PID

    pid = fork();     // Menyimpan PID dari Child Process

    /* Keluar saat fork gagal
    * (nilai variabel pid < 0) */
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    /* Keluar saat fork berhasil
    * (nilai variabel pid adalah PID dari child process) */
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        // Tulis program kalian di sini
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
        // while(strcmp(buffer, "04-09_22:22") != 0)
        // {
        //     sleep(2);
        //     rawtime = time(NULL);
        //     timeinfo = localtime(&rawtime);
        //     strftime (buffer, 80,"%m-%d_%H:%M",timeinfo);
        // }
        // ngezip();
            
        sleep(30);
    }
}

void donlotDanBuatFolder()
{
    pid_t buatFolder;
    int waitt;
    buatFolder = fork();
    // if(buatFolder < 0)
    //     exit(EXIT_FAILURE);
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
        // if(donlotF < 0)
        //     exit(EXIT_FAILURE);
        if(donlotF == 0)
            downloadFilm();
        else
        {
            while((wait(&waitt1)) > 0);
            pid_t donlotM;
            int waitt2;
            donlotM = fork();
            // if(donlotM < 0)
            //     exit(EXIT_FAILURE);
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
    // if(unzipF < 0)
    //     exit(EXIT_FAILURE);
    if(unzipF == 0)
        unzipFilm();
    else
    {
        while((wait(&wait1)) > 0);
        pid_t unzipM;
        int wait2;
        unzipM = fork();
        // if(unzipM < 0)
        //     exit(EXIT_FAILURE);
        if(unzipM == 0)
            unzipMusik();
        else
        {
            while((wait(&wait2)) > 0);
            pid_t unzipP;
            int wait3;
            unzipP = fork();
            // if(unzipP < 0)
            //     exit(EXIT_FAILURE);
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
    // if(moveF < 0)
    //     exit(EXIT_FAILURE);
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
                deleteZip();
            }
        }
    }
}

void deleteZip()
{
    pid_t delF;
    int pilm;
    delF = fork();
    if(delF < 0)
        exit(EXIT_FAILURE);
    if(delF == 0)
        delZipFilm();
    else
    {
        while((wait(&pilm)) > 0);
        pid_t delMP;
        int mp;
        delMP = fork();
        if(delMP < 0)
            exit(EXIT_FAILURE);
        if(delMP == 0)
            delZipMusik();
        else
        {
            while((wait(&mp)) > 0);
            pid_t delPn;
            int png;
            delPn = fork();
            if(delPn < 0)
                exit(EXIT_FAILURE);
            if(delPn == 0)
                delZipPhoto();
            else
            {
                while((wait(&png)) > 0);
                delFoto();
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
    char *argv[] = {"mv", "-T", "./FILM", "./Fylm", NULL};
    execv("/bin/mv", argv);
}

void moveMusik()
{
    char *argv[] = {"mv", "-T", "./MUSIK", "./Musyik", NULL};
    execv("/bin/mv", argv);
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

void delZipFilm()
{
    char *argv[] = {"rm", "-r", "./Film_for_Stevany.zip", NULL};
    execv("/bin/rm", argv);
}

void delZipMusik()
{
    char *argv[] = {"rm", "-r", "./Musik_for_Stevany.zip", NULL};
    execv("/bin/rm", argv);
}

void delZipPhoto()
{
    char *argv[] = {"rm", "-r", "./Photo_for_Stevany.zip", NULL};
    execv("/bin/rm", argv);
}

void delFoto()
{
    char *argv[] = {"rm", "-r", "FOTO", NULL};
    execv("/bin/rm", argv);
}

void ngezip()
{
    char *argv[] = {"zip", "-r", "Lopyu_Stevany.zip", "Fylm", "Musyik", "Pyoto", NULL};
    execv("/bin/zip", argv);
}