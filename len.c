/*** 
Name = len.c
Author = Cobraxo
Date = 06/04/2019
download:
    git clone https://github.com/Cobraxo/Misc.git
 
 comile:
    gcc len.c -o len
set command:
    sudo cp len /bin/my_len
Quality is more important than quantity. One home run is much better than two doubles. hihi xD
***/

#include <stdlib.h>
#include <stdio.h>


extern char *__progname;
static int strlen_function(char str[]);
static void usage(void);


int main(int argc, char *argv[]) {

    if (argc < 2) usage();  //If there are no arguments, exit
    (void)printf("%d\n", strlen_function(argv[1]));                             //Print the len
    return EXIT_SUCCESS;

}

static int strlen_function(char str[]){

    unsigned int i;
    for (i = 0; str[i] != '\0' ; i++);                                          //i = numbers of char in str[]
    return i;

}

static void usage(void) {

    fprintf(stderr, "usage: %s <string>\n", __progname);
    exit(EXIT_FAILURE);

}
