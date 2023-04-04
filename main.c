#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(){

    int fd;
    fd = open("jojo.txt",O_RDONLY,777);

    char *p = get_next_line(fd);
    while (p){
        printf("%s",p);
        p = get_next_line(fd);
    }
   free(p);
}



