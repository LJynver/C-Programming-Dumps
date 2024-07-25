#include <stdio.h>
#include <stdlib.h>

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
void readFile();

int main () {

    readFile();

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

void readFile() {
    const char fileName[20];
    printf("Enter a file name: ");
    scanf(" %s", fileName);

    displayHeader();

    StudType studRec;
    FILE *fp;
    int rec = 0;
    fp = fopen(fileName, "rb");
    if (fp != NULL) {
        while (fread(&studRec, sizeof(studRec), 1, fp) != 0) {
            if (rec == 20) {
                printf("\n");
                system("pause");
                system("cls");
                displayHeader();
            }
            displayStudent(studRec);
            rec++;
        }
        fclose(fp);
    }
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