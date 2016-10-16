/* Exercise 7-7
 * Modify the pattern finding program of Chapter 5 to 
 * take its input from a set of named files or, if no 
 * files are named as arguments, from the standard input. 
 * Should the file name be printed when a matching line is found?
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100

void patternfind(char *, char *, FILE *);

int main(int argc, char *argv[]){
	int index;
	FILE *fp;
	
	if (argc < 2){
		fprintf(stderr, "At least 1 file required");
		exit(1);
	}
	
	if (argc == 2){
		patternfind(argv[1], "STDIN", stdin);
	}
	for (index = 2; index < argc; index++){
		if ((fp = fopen(argv[index], "r")) == NULL){
			fprintf(stderr, "Could not open file %s\n", argv[index]);
			exit(1);
		}
	
		patternfind(argv[1], argv[index], fp);
		fclose(fp);
	}
	
	exit(0);
}

void patternfind(char *pattern, char *filename, FILE *fp){
	char line[MAXLINE];
	
	int n = 0;
	int found = 0;
	while(fgets(line, MAXLINE, fp)){
		n++;
		if(strstr(line, pattern)){
			printf(" LINE NUMBER: %d \n FILE: %s \n LINE: %s", n, filename, line);
			found = 1;
		}
	}
	
	if (!found){
		printf("'%s' not found", pattern);
	}
	
	
}