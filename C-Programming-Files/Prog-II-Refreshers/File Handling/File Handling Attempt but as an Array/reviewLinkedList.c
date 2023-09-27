#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 4

typedef struct {
	char LName[30];
	char FName[30];
	char MI;
} name_t ;

typedef struct {
	name_t name;
	int ID;
	char course[5];
	int year;
} data_t ;

typedef struct studtype {
	data_t data;
	struct studtype *next;
} studType, *studList ;

void enroll(studList *dcism_studs);
void printStudents(studList dcism_studs);

int main () {
	
	studList head = NULL; 
	int i = 0;
	
	do {
		enroll(&head);
		printStudents(head);
		++i;
	} while (i<MAX);
	
	return 0;
}

void enroll(studList *dcism_studs) {
	
	studList newNode = (studList)malloc(sizeof(studType));
	studList trav = *dcism_studs;
	
	printf("Enter the first name: ");
	scanf(" %[^\n]s", newNode->data.name.FName);
	fflush(stdin);
	
	printf("Enter the last name: ");
	scanf(" %[^\n]s", newNode->data.name.LName);
	fflush(stdin);
	
	printf("Enter the maiden initial: ");
	scanf(" %c", &newNode->data.name.MI);
	fflush(stdin);
	
	printf("\nEnter the ID number: ");
	scanf("%d", &newNode->data.ID);
	fflush(stdin);
	
	printf("Enter the course (in acronyms): ");
	scanf(" %[^\n]s", newNode->data.course);
	fflush(stdin);
	
	printf("Enter the student's 'year: ");
	scanf("%d", &newNode->data.year);
	fflush(stdin);
	
	if (*dcism_studs == NULL) {
		newNode->next = *dcism_studs;
		*dcism_studs = newNode;
		newNode = NULL;
	} else {
		while (trav->next != NULL && newNode->data.year > trav->next->data.year) {
			trav = trav->next;
		}
		if (trav->next == NULL) {
			newNode->next = trav;
			
		} else {
			newNode->next = trav->next;
			trav->next = newNode;
		}
		
	}
}

void printStudents(studList dcism_studs) {
	
	printf("\n");
	while (dcism_studs != NULL) {
		printf("%s %s", dcism_studs->data.name.FName, dcism_studs->data.name.LName);
		if (dcism_studs->next != NULL) {
			printf(" -> ");
		} else {
			printf("\n");
		}
		dcism_studs = dcism_studs->next;
	}
	printf("\n\n");
	
}
