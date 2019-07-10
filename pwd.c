/*** 
Name = pwd.c
Author = Cobraxo
Date = 07/10/2019
download:
    git clone https://github.com/Cobraxo/Misc.git
 
 compile:
    gcc pwd.c -o pwd
set command:
    sudo cp pwd /bin/my_pwd

I bet your current directory is "." ;)
***/

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <err.h>

//Define Boolean
#define FALSE 0
#define TRUE 1


extern char *__progname;
static void usage(void);
static void logical_pwd(void);


int main(int argc, char *argv[]) {

    char logical_FLAG, *physical_directory = NULL;
    int opt;

    //If the program is call with the absolute way, option -P is enable/default
    if (strstr(argv[0], "/bin/"))
        logical_FLAG = FALSE;

    //Else the option -L is enable/default
    else logical_FLAG = TRUE;

    while ((opt = getopt(argc, argv, "LP")) != -1) {

        switch (opt) {

            case 'L':
                logical_FLAG = TRUE;
                break;
            case 'P':
                logical_FLAG = FALSE;
                break;
            default:
                usage();
                break;

        }

    }

    //Check : logical Flag is TRUE ?
    if (logical_FLAG)
        logical_pwd();

    //Check physical_directory isn't NULL
    if (physical_directory = getcwd(NULL, 0))
        puts(physical_directory);

    return EXIT_SUCCESS;

}

static void usage(void) {

    fprintf(stderr,"usage: %s [-LP]\n", __progname);
    exit(EXIT_FAILURE);

}

static void logical_pwd(void) {

    struct stat stat_logical_directory, stat_current_directory;
    char *logical_directory = getenv("PWD");

    //Safety (check declaration of logical_directory and if he begin by /)
    if (logical_directory && logical_directory[0] == '/') {

        //Check stat of logical_directory and current directory
        if (stat(logical_directory, &stat_logical_directory) == 0 && stat(".", &stat_current_directory) == 0) {

            //Check if stat_logical_directory is egal with stat_current_directory
            if (stat_logical_directory.st_dev == stat_current_directory.st_dev  && stat_logical_directory.st_size == stat_current_directory.st_size) {

            puts(logical_directory);
            exit(EXIT_SUCCESS);
            
            }
        }
    }

    err(EXIT_FAILURE, NULL);
      
}
