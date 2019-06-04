#include <stdlib.h>
#include <stdio.h>

/***
Add in linux command:
gcc len.c -o len && sudo mv len /bin/len && cd
Have fun ! :)
***/

int strlen_function(char str[]){

    int i;
    for (i = 0; str[i] != '\0' ; i++);                                          //i = numbers of char in str[]
    return i;

}

int main(int argc, char *argv[]) {

    if (argc < 2) printf("Usage: %s <string>\n", argv[0]), exit(EXIT_FAILURE);  //If there are no arguments, exit
    printf("%d\n", strlen_function(argv[1]));                                   //Print the len
    return EXIT_SUCCESS;

}
