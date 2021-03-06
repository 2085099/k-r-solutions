/* Exercise 8-5
 * Modify the fsize program to print the other information 
 * contained in the inode entry
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

typedef struct dirent Dirent;

void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));

int main(int argc, char *argv[])
{
    if (argc == 1) /* default: current directory */
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}

void fsize(char *name){
	struct stat stbuf;
	
	time_t t;
	struct tm lt;
	char timebuf[200];
	
	if(stat(name, &stbuf) == -1){
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	
	if((stbuf.st_mode) & S_IFMT){
		dirwalk(name, fsize);
	}
	
	t = stbuf.st_mtime;
	localtime_r(&t, &lt);
	strftime(timebuf, sizeof(timebuf), "%c", &lt);
	
	printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024

/** dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    Dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0
            || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)) {
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
        } else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}