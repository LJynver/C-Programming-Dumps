#include <stdio.h>
#include <stdlib.h>

//user input version

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
void writeFile();

int main () {

    writeFile();

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

void writeFile() {
    StudType studInput[5];
    int ndx;

    FILE *fp;
    fp = fopen("test.dat", "wb");

    if (fp != NULL) {
        for (ndx = 0; ndx < 5; ++ndx) {
            printf("Enter student ID: ");
            scanf("%d", &studInput[ndx].ID);

            printf("Enter Last Name: ");
            scanf(" %s", &studInput[ndx].name.LN);

            printf("Enter First Name: ");
            scanf(" %s", &studInput[ndx].name.FN);

            printf("Enter Maiden Initial: ");
            scanf(" %c", &studInput[ndx].name.MI);

            printf("Enter Course: ");
            scanf(" %s", &studInput[ndx].course);

            printf("Enter Year Level: ");
            scanf("%d", &studInput[ndx].yrLevel);

            fwrite(&studInput[ndx], sizeof(StudType), 1, fp);

            system("pause");
            system("cls");
        }

        fclose(fp);

    } else {
        printf("\nSOMETHING WRONG!\n");
    }

}