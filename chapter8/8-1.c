/* Exercise 8-1
 * Rewrite the program cat from Chapter 7 using read, write,
 * open and close instead of their standard library equivalents.
 * Perform experiments to determine the relative speed of the
 * two versions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/file.h>

void error(char *);

/* cat: concatenate files */

int main(int argc, char *argv[])
{
	int fd;
	int n;
	void filecopy(FILE *, FILE *);
	char *prog = argv[0];
	char buf[BUFSIZ];
	
	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fd = open(*++argv, O_RDONLY)) == -1) {
				error("can't open file");
			} else {
				while ((n = read(fd, buf, BUFSIZ)) > 0){
					if (write(1, buf, n) != n){
						error("write error on file");
					}				
				}
			}

		exit(0); // Like close(), exit closes all open files
}
