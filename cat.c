/*** 

Name = cat.c
Author = Cobraxo
Date = 06/23/2019

download:
    git clone https://github.com/Cobraxo/Misc.git
 
 comile:
    gcc cat.c -o cat
set command:
    sudo cp cat /bin/my_cat

Do what you love, love what you do ! ^^

***/

#include <stdlib.h>
#include <stdio.h>

//Define booleans
#define TRUE 1
#define FALSE 0

//Define buffer size, to get newlines of file
#define BUFFER_SIZE 256


int print_file(char p_file_name[], char p_default);


int main(int argc, char *argv[]) {

    if (argc < 2)
        //Print stdin
        return print_file(NULL, TRUE);

    else
        //Show file
        return print_file(argv[1], FALSE);

}

int print_file(char p_file_name[], char p_default) {

    char buffer[BUFFER_SIZE] = {0};

    //If argc < 2, then print stdin
    if (p_default) {

        while (fgets(buffer, BUFFER_SIZE, stdin))   //Read each lines
            fprintf(stdout, "%s", buffer);          //Show it

        return EXIT_SUCCESS;

    }

    //If argc >= 2, then print the argument (file)
    else {
    
    FILE *file_open = NULL;

    //If the fopen() failed, print the error and exit
    if(!(file_open = fopen(p_file_name, "r"))) {
    
        perror(NULL);
        return EXIT_FAILURE;

    }

    //Print each newlines of file
    while (fgets(buffer, BUFFER_SIZE, file_open))
        fprintf(stdout, "%s", buffer);

    return EXIT_SUCCESS;

    }

    }
