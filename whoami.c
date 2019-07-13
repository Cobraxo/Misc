/***
Name = whoami.c
Author = Cobraxo
Date = 07/13/2019
download:
    git clone https://github.com/Cobraxo/Misc.git
 
 compile:
    gcc whoami.c -o whoami
set command:
    sudo cp whoami /bin/my_whoami
Now could you print your effective userid ? ^^
***/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <err.h>
#include <pwd.h>


typedef struct passwd passwd;

extern char * __progname;
static void usage(void);
static void cmp_argv1(char p_argv[]);
static void cmp_argv1_second(char p_argv[]);


int main(int argc, char *argv[]) {
    
    if (argc > 1)
        cmp_argv1(argv[1]);
    

    uid_t uid = -2;
    passwd *pw = NULL;
    
    //Get euid
    uid = geteuid();

    //If there are no errors, init pw with getpwuid(uid);
    pw = (errno || uid == -2 ? NULL : getpwuid(uid));   

    //If init pw failed
    if (!pw)
        err(EXIT_FAILURE, NULL);

    puts(pw->pw_name);
    return EXIT_SUCCESS;

}


static void usage(void) {

    printf("Usage: %s [OPTION]\n \
    --help for more information\n \
    --version for get the current version\n", \
    __progname);
    
    exit(EXIT_FAILURE);

}


static void cmp_argv1_second(char p_argv[]) {
    
    int  i;
    char help[] = "--help";

    //Compare each char of p_argv with --help
    for (i = 0; p_argv[i] != '\0'; i++) {

        //If the p_argv is not --help, exit with usage()
        if (p_argv[i] != help[i])
            usage(); 

    }

    //Print --help
    puts("whoami:\n \
    This program going to show the username associated with the current user id.");

    exit(EXIT_SUCCESS);

}


static void cmp_argv1(char p_argv[]) {
    
    int  i;
    char version[] = "--version";

    //Compare each character of p_argv with --version
    for (i = 0; p_argv[i] != '\0'; i++) {

        //If the p_argv is not --version, compare p_argv with --help
        if (p_argv[i] != version[i])
            cmp_argv1_second(p_argv);

    }

    //Print --version
    puts("whoami 2019:\n \
    https://github.com/Cobraxo/Misc\n \
    Made by Cobraxo");

    exit(EXIT_SUCCESS);

}
