#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
 #include<string.h>
int main()
{
    int fd;
    char str[]="file was opening by system calls";
    char str1[50];
    fd=open("games.txt", O_CREAT | O_RDWR, 0644);
    write(fd,str,strlen(str));
    close(fd);
    int fp1;
    fp1=open("games.txt", O_RDWR, 0644);
    read(fp1,str1,sizeof(str1));
    printf("%s",str1);
    close(fp1);
}