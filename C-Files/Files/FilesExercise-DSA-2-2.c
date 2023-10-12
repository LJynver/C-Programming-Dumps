#include <stdio.h>
#include <stdlib.h>

//hardcoded version

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
        
        StudType stud1 = {{"Lyan", 'R', "Jover"}, 22103650, "BSIT", 2};
        studInput[0] = stud1;

        StudType stud2 = {{"John", 'M', "Doe"}, 22206969, "BSCS", 3};
        studInput[1] = stud2;

        StudType stud3 = {{"Mary", 'A', "Lamb"}, 22109999, "BSIS", 1};
        studInput[2] = stud3;

        StudType stud4 = {{"Snowden", 'M', "Edward"}, 22209110, "BSCS", 4};
        studInput[3] = stud4;

        StudType stud5 = {{"Obama", 'H', "Barrack"}, 22101992, "BSIT", 2};
        studInput[4] = stud5;

        fwrite(&studInput, sizeof(StudType)*5, 1, fp);

        fclose(fp);

    } else {
        printf("\nSOMETHING WRONG!\n");
    }

}
