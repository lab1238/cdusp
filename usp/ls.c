#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
int main(int argc,char* argv[]){
struct dirent *dir;
struct stat mystat;
DIR *dp;
dp = opendir(".");
if(dp)
{
while(dir = readdir(dp)){
stat(dir->d_name,&mystat);
// inode mode uid guid access_time
printf("%ld %o %d %d %s %s\n",
mystat.st_ino,mystat.st_mode,mystat.st_uid,mystat.st_gid,ctime(&mystat.st_atime),dir-
>d_name);
}
}
}