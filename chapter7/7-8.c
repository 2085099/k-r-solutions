/* Exercise 7-8
 * Write a program to print a set of files, starting
 * each new one on a new page, with a title and a 
 * running page count for each file.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PAGEMAX 50
#define MAXLINE 100

void patternfind(char *, FILE *);

int main(int argc, char *argv[]){
	int index;
	FILE *fp;
	
	if (argc < 2){
		fprintf(stderr, "At least 1 file required");
		exit(1);
	}
	

	for (index = 1; index < argc; index++){
		if ((fp = fopen(argv[index], "r")) == NULL){
			fprintf(stderr, "Could not open file %s\n", argv[index]);
			exit(1);
		}
	
		patternfind(argv[1], fp);
		fclose(fp);
	}
	
	exit(0);
}

void patternfind(char *filename, FILE *fp){
	int page = 1, lines = -1;
	char line[MAXLINE];
		
	printf("--- %s: PAGE %d ---\n", filename, page);
	
	while(fgets(line, MAXLINE, fp)){
		if(++lines == PAGEMAX){
			printf("--- %s: PAGE %d ---\n", filename, ++page);
			lines = 0;
		}
		
		printf("%s", line);
	}
	
	
}