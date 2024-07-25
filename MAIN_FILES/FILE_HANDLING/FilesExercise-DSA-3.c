#include <stdio.h>
#include <stdlib.h>

//Require Task 2 to be made first

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
void readAppendFile();

int main () {

    readAppendFile();

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

void readAppendFile() {
    const char srcFile[30], destFile[30];
    printf("Enter the filename to read: ");
    scanf(" %s", &srcFile);

    printf("Enter the filename to append read file to: ");
    scanf(" %s", &destFile);

    StudType buffer;

    FILE *sfp, *dfp;

    sfp = fopen(srcFile, "rb");
    dfp = fopen(destFile, "ab");

    // displayHeader();
    if (sfp != NULL && dfp != NULL) {
        while (fread(&buffer, sizeof(StudType), 1, sfp) != 0) { //while this is doing on the background, fp moves to the beginning address of the next studRec
            // displayStudent(buffer);
            fwrite(&buffer, sizeof(StudType), 1, dfp);
        }
    }
}