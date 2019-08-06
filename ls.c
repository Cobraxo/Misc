/***
Name = ls.c
Author = Cobraxo
Date = 06/15/2019

download:
    git clone https://github.com/Cobraxo/Misc.git
 
 compile:
    gcc ls.c -o ls
set command:
    sudo cp ls /bin/my_ls
Enjoy ! :P
***/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define FALSE 0
#define TRUE 1


void print_files(int p_all_files, int p_perm_files);
char *return_perm_file(int p_mode);


int main(int argc, char *argv[]) {

    int opt;
    char all_files = FALSE, perm_files = FALSE;
    
    while((opt = getopt(argc, argv, "al")) != -1) {     //Get options

        switch (opt)
        {
        case 'a':                                       //ls -a or ls -al
            all_files = TRUE;
            break;
        case 'l':                                       //ls -l or ls -la
            perm_files = TRUE;
            break;
        }

    }

    //Update argc and argv
    argc -= optind;
    argv += optind;

    print_files(all_files, perm_files);

    return EXIT_SUCCESS;

}

void print_files(int p_all_files, int p_perm_files) {
    
    DIR *open = opendir(".");                           //Open . directory
    struct dirent *files = NULL;
    struct passwd *pwd = NULL;
    struct group *grp = NULL;
    struct stat perm_files;


    if (open == NULL)
        perror("Error, ");      //If opendir() failed, print the error

    while(files = readdir(open)) {                                            //Open each file

        if (p_perm_files)  {                                                //ls with -l option
            if ((stat(files->d_name, &perm_files)) == -1)                  //Open file to look perm
                perror("Error, ");                                        //If stat() failed, print the error

            char *perm_buff = return_perm_file(perm_files.st_mode);     //perm_buff egal perms of the file

            if ((pwd = getpwuid(perm_files.st_uid)) == NULL)    //Convert uid to string
                perror("getpwuid() : ");                       //If getpwuid() failed, print the error

            if ((grp = getgrgid(perm_files.st_gid)) == NULL)    //Convet gid to string
                perror("getgrgid() : ");                       //If getgrgid() failed, print the error

            if (p_all_files || files->d_name[0] != '.') {       //If p_all_files is TRUE print all files, else print file which begin without .

            //Out
            printf("%-s", perm_buff);                           //Perms
            printf("%3d ", (int)perm_files.st_nlink);           //Hard links
            printf("%-7s", pwd->pw_name);                       //User
            printf("%-8s ", grp->gr_name);                      //Group
            printf("%7ld ", perm_files.st_size);                //Size
            printf("%.12s  ", 4+ctime(&perm_files.st_mtime));   //Print just the month with day and hour
            printf("%2s\n", files->d_name);                     //Name of file

            }
        
        }

        else                                                    //ls without -l option
            if ((p_all_files|| files->d_name[0] != '.') && !p_perm_files)   //Print normal files and if p_all_files is true, print all files
                printf("%s\n", files->d_name);
    
    }

    if (closedir(open) == -1)   //If close failed, exit
        exit(EXIT_FAILURE);

}

char *return_perm_file(int p_mode) {

    static char buff_letter[10];
    strncpy(buff_letter, "----------", 10);     //Copy no perm for default file

    //Type file
    if (S_ISDIR(p_mode))        buff_letter[0] = 'd';
    if (S_ISLNK(p_mode))        buff_letter[0] = 'l';
    if (S_ISCHR(p_mode))        buff_letter[0] = 'c';
    if (S_ISBLK(p_mode))        buff_letter[0] = 'b';

    //User perms
    if (p_mode & S_IRUSR)       buff_letter[1] = 'r';
    if (p_mode & S_IWUSR)       buff_letter[2] = 'w';
    if (p_mode & S_IXUSR)       buff_letter[3] = 'x';

    //Group perms
    if (p_mode & S_IRGRP)       buff_letter[4] = 'r';
    if (p_mode & S_IWGRP)       buff_letter[5] = 'w';
    if (p_mode & S_IXGRP)       buff_letter[6] = 'x';

    //Other perms
    if (p_mode & S_IROTH)       buff_letter[7] = 'r';
    if (p_mode & S_IWOTH)       buff_letter[8] = 'w';
    if (p_mode & S_IXOTH)       buff_letter[9] = 'x';

    return buff_letter;
    
}
