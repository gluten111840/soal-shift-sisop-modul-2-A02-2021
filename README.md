# Soal Shift Modul 2 Kelompok A02 2021

Nama Anggota Kelompok:
1. Bayu Eka Prawira         (05111940000042)
2. Putu Ananda Satria Adi   (05111940000113)

## Soal 1
### Narasi Soal
Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. 

### 1a
**Soal**</br>
Dikarenakan Stevany sangat menyukai huruf **Y**, Steven ingin nama folder-foldernya adalah **Musyik** untuk mp3, **Fylm** untuk mp4, dan **Pyoto** untuk jpg 
</br>

**Penjelasan**</br>

</br>

### 1b
**Soal**</br>
Untuk musik Steven **mendownloadnya** dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :).
</br>

**Penjelasan**</br>

</br>

### 1c
**Soal**</br>
Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu **meng-extract-nya** setelah didownload.
</br>

**Penjelasan**</br>

</br>

### 1d
**Soal**</br>
**Memindahkannya** ke dalam folder yang telah dibuat (hanya file yang dimasukkan).
</br>

**Penjelasan**</br>

</br>

### 1e
**Soal**</br>
Untuk memudahkan Steven, ia ingin semua hal di atas berjalan **otomatis** 6 jam sebelum waktu ulang tahun Stevany.
</br>

**Penjelasan**</br>

</br>

### 1f
**Soal**</br>
Setelah itu pada **waktu** ulang tahunnya Stevany, semua folder akan di zip dengan nama **Lopyu_Stevany.zip** dan semua folder akan di **delete**(sehingga hanya menyisakan .zip).
</br>

**Penjelasan**</br>

</br>

## Soal 2
### Narasi Soal
Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

### 2a
**Soal**</br>
Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.
</br>

**Penjelasan**</br>

</br>

### 2b
**Soal**</br>
Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip.  
*Contoh: Jenis peliharaan kucing akan disimpan dalam “`/petshop/cat`”, jenis peliharaan kura-kura akan disimpan dalam “`/petshop/turtle`”.*
</br>

**Penjelasan**</br>

</br>

### 2c
**Soal**</br>
Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.  
*Contoh: “`/petshop/cat/joni.jpg`”*. 
</br>

**Penjelasan**</br>

</br>

### 2d
**Soal**</br>
Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai.  
*Contoh: foto dengan nama “`dog;baro;1_cat;joni;2.jpg`” dipindah ke folder “`/petshop/cat/joni.jpg`” dan “`/petshop/dog/baro.jpg`”.*
</br>

**Penjelasan**</br>

</br>

### 2e
**Soal**</br>
Di setiap folder buatlah sebuah file "`keterangan.txt`" yang berisi nama dan umur semua peliharaan dalam folder tersebut. **Format harus sesuai contoh**.

>nama : joni  
umur  : 3 tahun</br></br>
nama : miko  
umur  : 2 tahun

</br>

**Penjelasan**</br>

</br>

## Soal 3
### Narasi Soal
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.
### 3a
**Soal**</br>
Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp `[YYYY-mm-dd_HH:ii:ss].`
</br>  

**Penjelasan**</br>
Pertama untuk mempermudah mendapatkan waktu saat folder dibuat, saya mendefinisikan terlebih dahulu sebuah fungsi `getTime` untuk mendapatkan waktu saat ini.
```c
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
```
</br>

Setelah membuat fungsi untuk mendapatkan waktu, saya juga membuat fungsi `makeDir` untuk membuat direktori dengan *path* sebagai parameter fungsi.
```c
void makeDir(char *folderTime) {

    printf("LOG: Making directory %s\n", folderTime);

    // Fork to make directory
    pid_t mkdirID = fork();

    if(mkdirID == 0) {
        char *args[] = {"mkdir", folderTime, NULL};
        execv("/bin/mkdir", args);
    }
}
```
</br>

Setelah kedua fungsi diatas selesai, untuk dapat membuat direktori, pada fungsi `main` perlu dipanggil kedua fungsi diatas.
```c
#define OUTPUTDIR "/home/ananda/Documents/output"

int main(int argc, char *argv[]) {

    if ((chdir(OUTPUTDIR)) < 0) {
        exit(EXIT_FAILURE);
    }
    ...
    while(1) {
        ...
        char *folderTime;

        folderTime = getTime();

        makeDir(folderTime);
        ...
    }
    ...
}

Note:
(...) bagian kode tidak ditunjukkan untuk mempersingkat
```
</br>

### 3b
**Soal**</br>
Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari `https://picsum.photos/`, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp `[YYYY-mm-dd_HH:ii:ss]` dan gambar tersebut berbentuk persegi dengan ukuran `(n%1000) + 50` pixel dimana n adalah detik ***Epoch Unix***.
</br>

**Penjelasan**</br>
Karena setiap folder memungkinkan untuk *overlapping download*, maka diperlukan *child process* untuk setiap folder agar setiap folder dapat melakukan *download* sendiri. Setelah itu *while loop* di-*sleep* selama 40 detik sebelum melakukan *fork* kembali. Di dalam *child process* dilakukan *for loop* sebanyak 10 kali, dan untuk setiap *for* di-*sleep* 5 detik. Selain itu setiap process *download* juga perlu di-*fork*.
```c
#define MKDIR_SLEEP 40
#define IMAGE_DOWNLOAD_SLEEP 5
#define IMAGE_PER_FOLDER 10

#define OUTPUTDIR "/home/ananda/Documents/output"

int main(int argc, char *argv[]) {

    if ((chdir(OUTPUTDIR)) < 0) {
        exit(EXIT_FAILURE);
    }
    ...
    while(1) {
        ...
        char *folderTime;

        folderTime = getTime();

        makeDir(folderTime);

        // Fork to download image
        pid_t downloaderID = fork();

        if(downloaderID == 0) {

            for(int i = 0; i < IMAGE_PER_FOLDER; i++) {
                pid_t downloadID = fork();

                if(downloadID == 0) {
                    ...
                }

                sleep(IMAGE_DOWNLOAD_SLEEP);
            }
            ...
        }
        sleep(MKDIR_SLEEP);
    }
}

Note:
(...) bagian kode tidak ditunjukkan untuk mempersingkat
```
</br>

Kemudian *concatenate* hasil dari `(n%1000)+50` dalam url. Selain itu juga kita menggunakan fungsi `getTime` yang di-*assign* ke `downloadTime` untuk merename file *download* nantinya.
```c
#define MKDIR_SLEEP 40
#define IMAGE_DOWNLOAD_SLEEP 5
#define IMAGE_PER_FOLDER 10

#define OUTPUTDIR "/home/ananda/Documents/output"

int main(int argc, char *argv[]) {

    if ((chdir(OUTPUTDIR)) < 0) {
        exit(EXIT_FAILURE);
    }
    ...
    while(1) {
        time_t _time;
        struct tm *currTime;
        ...
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
        ...
    }
}

Note:
(...) bagian kode tidak ditunjukkan untuk mempersingkat
```
</br>

### 3c
**Soal**</br>
Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “`status.txt`”, dimana didalamnya berisi pesan “`Download Success`” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.
</br>

**Penjelasan**</br>
Pertama, harus dibuat fungsi untuk *Caesar Cipher*. Nantinya string hasil *Caesar Cipher* akan di-*return* melalui argumennya.
```c
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
```
</br>

Setelah fungsi tersebut didefinisikan, kita dapat menggunakannya dalam fungsi `main`. Untuk *zip* folder yang sudah selesai melakukan download, dapat digunakan command `zip` dengan *option* `-rm` untuk melakukan *zip* semua file dalam folder tersebut, serta menghapus file original setelah file selesai di-*zip*.
```c
#define MKDIR_SLEEP 40
#define IMAGE_DOWNLOAD_SLEEP 5
#define IMAGE_PER_FOLDER 10

#define OUTPUTDIR "/home/ananda/Documents/output"

int main(int argc, char *argv[]) {

    if ((chdir(OUTPUTDIR)) < 0) {
        exit(EXIT_FAILURE);
    }
    ...
    while(1) {
        ...
        pid_t downloaderID = fork();

        if(downloaderID == 0) {
            ...

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
}

Note:
(...) bagian kode tidak ditunjukkan untuk mempersingkat
```
</br>

### 3d
**Soal**</br>
Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan **program bash**.
</br>

**Penjelasan**</br>
Untuk membuat "`killer`" program dibuat fungsi `makeKiller`, namun untuk snippet kode berikut sudah termasuk jawaban untuk (3e). Untuk dapat membunuh semua proses yang berhubungan dengan soal 3 saya menggunakan command `pkill -f soal3` dan untuk membunuh *parent process* menggunakan `kill -9 <pid>`. Serta untuk membuat program dapat menghapus dirinya sendiri, digunakan command `rm $0` karena variabel `$0` merujuk pada dirinya sendiri. Untuk membuat **program bash**, dilakukan `fopen` dengan nama file `killer.sh` kemudian dimasukkan command bersangkutan.
```c
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
```
</br>

### 3e
**Soal**</br>
Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dengan argumen `-z`, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen `-x`, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).
</br>

**Penjelasan**</br>
Untuk dapat mengecek apakah argumen yang dimasukkan adalah `-z` atau `-x` digunakan `strcmp(argv[1], "-z") || strcmp(argv[1], "-x")`. Setelah didapatkan argumen yang dimasukkan, mode diset sesuai dengan argumen yang di-*passing*. Mode adalah sebagai berikut:
- Mode 1 = `-z` (*Force close* program)
- Mode 2 = `-x` (*Kill parent* program)
```c
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
    ...
}

Note:
(...) bagian kode tidak ditunjukkan untuk mempersingkat
```
</br>

Melanjutkan dari (3d), ketika mode = 1, maka script yang dibuat adalah sebagai berikut:
```c
void makeKiller(int mode, pid_t pid) {
...
    if(mode == 1) {
        char *code = "#!/bin/bash\n\n"
                    "pkill -f \"./soal3\"\n"
                    "rm $0\n";
        
        fprintf(killer, "%s", code);
    }
...
}

Note:
(...) bagian kode tidak ditunjukkan untuk mempersingkat
```
dan ketika mode = 2, yang di-*kill* adalah parent-nya. Sehingga semua child process dapat melanjutkan process yang sedang dijalankan hingga semuanya diselesaikan hingga akhirnya nanti exit.
```c
void makeKiller(int mode, pid_t pid) {
...
    else if(mode == 2) {
        char *code = "#!/bin/bash\n\n"
                    "kill -9 %d\n"
                    "rm $0\n";
        
        fprintf(killer, code, pid);
    }
...
}

Note:
(...) bagian kode tidak ditunjukkan untuk mempersingkat
```