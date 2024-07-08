#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void){
    char *path,path1[10];
    struct stat *nfile;
    
    nfile=(struct stat*)malloc(sizeof(struct stat));

    printf("Enter the file whose statistics has to :");
    scanf("%s",path1);

    stat(path1,nfile);

    printf("User id :%d\n",nfile->st_uid);
    printf("Last access time %d\n",nfile->st_atime);
    printf("Production mode:%d\n",nfile->st_mode);
    printf("Size of file :%d\n",nfile->st_size);
    printf("number of links :%d\n",nfile->st_nlink);

}