/* Exercise 7-6
 * Write a program to compare two files, printing the first line
 * where they differ
 */

 #define MAXLINE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filecomp(FILE *fp1, FILE *fp2);

char x[MAXLINE], y[MAXLINE];
char *f1, *f2;

int main(int argc, char *argv[])
{
	FILE *fp1;
	FILE *fp2;

    if (argc != 3){
        fprintf(stderr, "At least 2 files required");
		exit(1);
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "Can't open first file");
		exit(1);
	}
    if ((fp2 = fopen(argv[2], "r")) == NULL){
        fprintf(stderr, "Can't open second file");
		exit(1);
	}
	filecomp(fp1, fp2);
	fclose(fp1);
    fclose(fp2);
	
    exit(0);
}

void filecomp(FILE *fp1, FILE *fp2){
    

    int counter = 0;

    while (1){
		counter++;
		f1 = fgets(x, MAXLINE, fp1);
		f2 = fgets(y, MAXLINE, fp2);
	
        if (f1 == NULL && f2 == NULL){
            printf("Files match!");
            
            break;

        } else if ((f1 == NULL || f2 == NULL) && f1 != f2){
            printf("Files differ at line %d", counter);
            break;

        } else if(strcmp(x, y) != 0){
            printf("Files differ at line %d", counter);
            break;
        }

        
    }







}
