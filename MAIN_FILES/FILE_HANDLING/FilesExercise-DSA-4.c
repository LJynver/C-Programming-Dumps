#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Require Task 3 to be made first

typedef struct {
    char FN[24]; //First Name
    char MI; //Maiden Initial
    char LN[16]; //Last Name
} NameType;

typedef struct {
    NameType name;
    int ID;
    char course[8];
    int yrLevel;
} StudType;

void displayHeader();
void displayStudent(StudType S);
void updateFile(char oldCourse[], char newCourse[]);

int main () {

    updateFile("BSCS", "BSIT");

    return 0;
}

void displayHeader() {
    printf("\n\n");
    printf("%-10s", "ID No.");
    printf("%-16s", "Lastname");
    printf("%-24s", "Firstname");
    printf("%-3s", "MI");
    printf("%-8s", "Course");
    printf("%5s", "Year"); 
    printf("\n");
    printf("%-10s", "======");
    printf("%-16s", "========");
    printf("%-24s", "=========");
    printf("%-3s", "==");
    printf("%-8s", "======");
    printf("%5s", "====");
}

void displayStudent(StudType S) {
    printf("\n");
    printf("%-10d", S.ID);
    printf("%-16s", S.name.LN);
    printf("%-24s", S.name.FN);
    printf("%-3c", S.name.MI);
    printf("%-8s", S.course);
    printf("%5d", S.yrLevel); 
}

void updateFile(char oldCourse[], char newCourse[]) {
    const char srcFile[30];

    printf("Enter the source file to update: ");
    scanf(" %s", &srcFile);

    StudType buffer;

    FILE *fp = fopen(srcFile, "r+b"); //allows the mode to open the file for reading and writing
    if (fp != NULL) {
        while (fread(&buffer, sizeof(StudType), 1, fp) != 0) {
            if (strcmp(buffer.course, oldCourse) == 0) {
                strcpy(buffer.course, newCourse); 
                
                fseek(fp, -sizeof(StudType), SEEK_CUR); 

                fwrite(&buffer, sizeof(StudType), 1, fp);

                
                fseek(fp, 0, SEEK_CUR);
            }
        }
    }

}