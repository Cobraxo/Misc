/*** 

Name = auto.c
Author = Cobraxo
Date = 09/10/2019

download:
    git clone https://github.com/Cobraxo/Misc.git
 
 compile:
    gcc auto.h auto.c -o auto

set command:
    sudo cp auto /bin/auto

It's more faster with auto :P

***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include "auto.h"

static void usage(void);
static char *c, *cc, *html;


int main(int argc, char *argv[]) {

    if (argc < 3)
        usage();

    size_t buf_size_name = 256, buf_size_ext = 256, size_name = 0, size_extension = 0;  
    char *name_file = NULL, *extension = NULL;
    int i = 0;

    if (!( name_file = (char *)calloc(buf_size_name, sizeof(char)) ))
        err(1, "calloc");
    
    if (!( extension = (char *)calloc(buf_size_ext, sizeof(char)) ))
        err(1, "calloc");

    if (!( size_name = strlen(argv[1]) ))
        err(1, "strlen");

    if (!( size_extension = strlen(argv[2]) ))
        err(1, "strlen");

    for (i = 0; argv[1][i] != '\0'; i++) {

        name_file[i] = argv[1][i];

        if (size_name <= buf_size_name) {

            buf_size_name += 256;
            name_file = (char *)realloc(name_file, buf_size_name);

        }
    
    }

    extension[0] = '.';

    for (i = 0; argv[2][i] != '\0'; i++) {

        extension[i+1] = argv[2][i];

        if (size_extension <= buf_size_ext) {

            buf_size_ext += 256;
            extension = (char *)realloc(extension, buf_size_ext);

        }

    }

    name_file = strcat(name_file, extension);
    FILE *file = fopen(name_file, "w");
    
    free(name_file);
    free(extension);

    if (strcmp(argv[2], "py") == 0 || strcmp(argv[2], "css") == 0)
        return 0;

    else if (strcmp(argv[2], "cpp") == 0 || strcmp(argv[2], "cc") == 0) {

            if (!fprintf(file, "%s", cc))
                err(1, "fprintf");
 
            return 0;

    }

    else if (strcmp(argv[2], "html") == 0) {

            if (!fprintf(file, "%s", html))
                err(1, "fprintf");

            return 0;

    }
    
    if (!fprintf(file, "%s", c))
        err(1, "fprintf");

    return 0;

}

static void usage(void) {

    if (!fprintf(stderr, "usage: NAME_FILE TYPE_OF_FILE\nSuch as: auto main c\n"))
        err(1, "fprintf");
    exit(1);

}
