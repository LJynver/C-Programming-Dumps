#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 5

typedef char String[20];

typedef struct studentInfo { //user input goes here
	String fName;
	String lName;
	String program;
	int ID;
	int year;
}studType;

typedef struct arrayList { //array list
	studType studRec[SIZE];
	int count; 
}List;

typedef struct nodeList { //linked list
	studType studProfile;
	struct nodeList *link;
}*NodeLink;

typedef struct list { //everything is here
	List *arrayPtr;
	NodeLink head;
}MainList;

MainList init();
studType initInput();
void insertFirst(MainList *head);
void deleteElement(MainList *head);
void displayAllList(MainList head);

int main () {
	
	MainList main = init();
	int select;
	do {
		printf("[1]: Insert First\n[2]: Delete First\n[3]: Display All List\n");
		printf("\nSelect your choice: ");
		scanf("%d", &select); system("cls");
		switch (select)  {
			case 1: //insert first
				insertFirst(&main);
				break;
			case 2: //delete element
				deleteElement(&main);
				break;
			case 3: //display list
				displayAllList(main);
				break;
			case 0: //exit
				break;
			default:
				printf("Invalid choice!");
				break;
		}
		getch();
		system("cls");
	} while (select != 0);
	
	return 0;
}

MainList init() {
	MainList start = {
		(List*)calloc(1, sizeof(List)),
		NULL
	};
	
	if (start.arrayPtr != NULL) {
		start.arrayPtr->count = 0;
	} else {
		printf("Failed to allocate!");
	}
	return start;
}

void insertFirst(MainList *head) {
	studType input;
	printf("Enter your First Name: ");
	scanf(" %s", input.fName);
	printf("Enter your Last Name: ");
	scanf(" %s", input.lName);
	printf("Enter your Program: ");
	scanf(" %s", input.program);
	printf("Enter your School ID: ");
	scanf("%d", &input.ID);
	printf("Enter your Student Year: ");
	scanf("%d", &input.year);
	
	if (strcmp(input.program, "BSIT") == 0) { //IT entries inside the array
		if (head->arrayPtr->count < SIZE) {
			int ndx = head->arrayPtr->count;
			for (; ndx > 0; head->arrayPtr->studRec[ndx] = head->arrayPtr->studRec[ndx-1], --ndx) {}
			head->arrayPtr->studRec[ndx] = input;
			++head->arrayPtr->count;
		} else {
			printf("Not enough array space!");
		}
	} else if (strcmp(input.program, "BSCS") == 0) { //CS entries in Linked List
		NodeLink *trav = &head->head;
		for (; *trav != NULL; trav = &(*trav)->link) {}
		NodeLink newNode = (NodeLink)malloc(sizeof(struct nodeList));
		if (newNode != NULL) {
			newNode->studProfile = input;
			newNode->link = *trav;
			*trav = newNode;
		}
	} else {
		printf("Program is not under DCISM. Please try again!");
	}
}

void deleteElement(MainList *head) { //delete once
	int ID;
	printf("Enter the ID number of the entry to delete: ");
	scanf("%d", &ID);
	
	int ndx = 0;
	for (; ndx < head->arrayPtr->count && head->arrayPtr->studRec[ndx].ID != ID; ++ndx) {}
	if (ndx < head->arrayPtr->count) {
		head->arrayPtr->count--;
		for (; ndx < head->arrayPtr->count; ++ndx) {
			head->arrayPtr->studRec[ndx] = head->arrayPtr->studRec[ndx+1];
		}
		printf("\nEntry is removed from the array!\n");
	} else {
		printf("\nEntry is not in the Array List\n");
	}
	
	NodeLink *trav = &head->head;
	for (; *trav != NULL && (*trav)->studProfile.ID != ID; trav = &(*trav)->link) {}
	if (*trav != NULL) {
		NodeLink temp = *trav;
		*trav = temp->link;
		free(temp);
		printf("\nEntry is removed from the Linked List!\n");
	} else {
		printf("\nEntry is not in the Linked List!\n");
	}
}

void displayAllList(MainList head) {
	int ndx;
	printf("\nPrinting the BSIT Arrays...\n"); getch(); system("cls");
	for (ndx = 0; ndx < head.arrayPtr->count; ++ndx) {
		printf("|| First Name\t: %s\n", head.arrayPtr->studRec[ndx].fName);
		printf("|| Last Name\t: %s\n", head.arrayPtr->studRec[ndx].lName);
		printf("|| Student Year\t: %d\n", head.arrayPtr->studRec[ndx].year);
		printf("|| Student ID\t: %d\n", head.arrayPtr->studRec[ndx].ID);
		printf("|| Program\t: %s\n", head.arrayPtr->studRec[ndx].program);
		printf("======================\n");
	}
	getch(); system("cls");
	printf("\nPrinting the BSCS Linked List...\n"); getch(); system("cls");
	while (head.head) {
		printf("First Name\t: %s\n", head.head->studProfile.fName);
		printf("Last Name\t: %s\n", head.head->studProfile.lName);
		printf("Student Year\t: %d\n", head.head->studProfile.year);
		printf("Student ID\t: %d\n", head.head->studProfile.ID);
		printf("Program\t: %s\n", head.head->studProfile.program);
		if (head.head->link != NULL) {
			printf("\t\t |\n");
			printf("\t\t |\n");
			printf("\t\t |\n");
			printf("\t\t V\n");
		}
		head.head = head.head->link;
	}
}
