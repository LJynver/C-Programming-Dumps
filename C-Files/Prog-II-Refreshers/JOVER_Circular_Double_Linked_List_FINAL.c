#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
	char LName[30], FName[30], MI;
} studName ;

typedef struct {
	studName name;
	int ID;
	char course[5];
	int year;
} studData ;

typedef struct student {
	struct student *prev;
	studData data;
	struct student *next;
} studType, *studList ;

void enroll (studList *dcism_studs);
void printGraduatingStuds (studList dcism_studs);
void retrieveGraduatingDCISMStuds (studList *dcism_studs, studList *graduating_studs);
void circularList (studList *dcism_studs, studList *graduating_studs);

int main () {
	
	studList dcism_studs = NULL;
	studList grad_studs = NULL;
	int choice;
	
	do {
		printf("    =========================================    \n");
		printf("\t[0] Terminate this Prompt\n"); printf("\t[1] Enroll Students\n");
		printf("\t[2] Retrieve Graduating Students\n"); printf("\t[3] Printing Students\n");
		printf("    =========================================    \n");
		printf("\nEnter Function Number to Execute: "); scanf("%d", &choice);
		switch(choice) {
			case 0:
				printf("Terminating the prompt...\n");
				break;
			case 1:
				printf("\n!! ENROLL STUDENTS FUNCTION SELECTED !!\nPress any key to continue..."); getch(); system("cls");
				enroll(&dcism_studs); printGraduatingStuds(dcism_studs);
				break;
			case 2:
				printf("\n!! RETRIEVING STUDENTS FUNCTION SELECTED !!\nPress any key to continue..."); getch(); system("cls");
				retrieveGraduatingDCISMStuds(&dcism_studs, &grad_studs); printGraduatingStuds(grad_studs);
				break;
			case 3:
				printf("\n!! RETRIEVING STUDENTS FUNCTION SELECTED !!\nPress any key to continue..."); getch(); system("cls");
				printf("\nMAIN DCISM LIST:\n"); printGraduatingStuds(dcism_studs);
				printf("\nGRADUATING DCISM LIST:\n"); printGraduatingStuds(grad_studs);
				break;
			default:
				break;
		}
		if (choice != 0) {
			printf("\nPress any key to continue prompt..."); getch(); system("cls");
		}
	} while (choice != 0);
	
	return 0;
}

void enroll (studList *dcism_studs) {
	studList input = malloc(sizeof(studType));
	
	studList trav = *dcism_studs;
	
	if (input == NULL) {
		printf("\nAllocation failed!\n");
		return;
	} else {
		printf("Enter the student's first name: "); scanf(" %[^\n]s", input->data.name.FName); fflush(stdin);
		printf("Enter the student's last name: "); scanf(" %[^\n]s", input->data.name.LName); fflush(stdin);
		printf("Enter the student's middle initial: "); scanf(" %c", &input->data.name.MI); fflush(stdin);
		printf("\nEnter the student's course [in acronym]: "); scanf(" %[^\n]s", input->data.course); fflush(stdin);
		printf("Enter the student's ID: "); scanf("%d", &input->data.ID); fflush(stdin);
		printf("Enter the student's year: "); scanf("%d", &input->data.year); fflush(stdin);
	}
	
	if (*dcism_studs == NULL) { //checks if this is the first node for the list
		*dcism_studs = input;
		input->next = *dcism_studs;
		input->prev = input->next;
	} else {
		while (trav->next != *dcism_studs) {
			trav = trav->next;
		}
		input->next = trav->next;
		input->next->prev = input;
		trav->next = input;
		input->prev = trav;
	}
}

void printGraduatingStuds (studList dcism_studs) {
	
	studList head = dcism_studs;
	
	if (dcism_studs == NULL) {
		printf("\n!! The list is empty! !!\n"); return;
	} else if (dcism_studs->next == head) {
		printf("\n[%s, %s, %d] <<", dcism_studs->prev->data.name.FName, dcism_studs->prev->data.course, dcism_studs->prev->data.year);
		printf(">> [%s, %s, %d]\n\n", dcism_studs->data.name.FName, dcism_studs->data.course, dcism_studs->data.year);
		printf("It is highly suggested you add one more node!\n\n");
	} else {
		printf("\n");
		printf("[%s, %s, %d] << || ", dcism_studs->prev->data.name.FName, dcism_studs->prev->data.course, dcism_studs->prev->data.year);
		while (dcism_studs->next != head) {
			printf("== [%s, %s, %d] <<", dcism_studs->prev->data.name.FName, dcism_studs->prev->data.course, dcism_studs->prev->data.year);
			printf(">> [%s, %s, %d] == ", dcism_studs->data.name.FName, dcism_studs->data.course, dcism_studs->data.year);
			printf(" // ");
			dcism_studs = dcism_studs->next;
		}
		printf("|| [%s, %s, %d]\n", dcism_studs->data.name.FName, dcism_studs->data.course, dcism_studs->data.year);
	}
	
}

void retrieveGraduatingDCISMStuds (studList *dcism_studs, studList *graduating_studs) {
	studList current = *dcism_studs;
	studList previous = *dcism_studs;
	
	studList trav;

	if (current == NULL) {
		printf("\nThe DCISM List is empty/you reached to the last node!\n"); return;
	} else {
		printf("Extracting graduating students...\n");
		while (current != NULL) {
			if ((strcmp(current->data.course, "BSCS") == 0 || strcmp(current->data.course, "BSIT") == 0 || strcmp(current->data.course, "BSIS") == 0 ) && current->data.year >= 4) {
				studList newNode = (studList)malloc(sizeof(studType));
				trav = *graduating_studs;
				if (newNode != NULL) {
					newNode->data = current->data;
					if (*graduating_studs == NULL) {
						*graduating_studs = newNode;
						newNode->next = *graduating_studs;
						newNode->prev = newNode->next;
					} else {
						while (trav->next != *graduating_studs) {
							trav = trav->next;
						}
						newNode->next = trav->next;
						newNode->next->prev = newNode;
						trav->next = newNode;
						newNode->prev = trav;
					}
				} else {
					printf("\nAllocation failed!\n"); return;
				}
				trav = *dcism_studs;
				while (trav->next != *dcism_studs) {
					trav = trav->next;
				}
				if (current == previous) {
					if (current->next == trav->next) {
						free(trav);
						*dcism_studs = NULL; current = *dcism_studs;
					} else {
						previous->next->prev = trav;
						current = current->next;
						*dcism_studs = current;
						trav->next = *dcism_studs;
						previous->prev = NULL; previous->next = NULL;
						free(previous);
						previous = current;
					}
				} else {
					if (current->next == trav->next) {
						previous->next = *dcism_studs;
						previous->next->prev = previous;
						free(current); current = NULL;
					} else {
						previous->next = current->next;
						current->next->prev = previous;
						current->next = NULL; current->prev = NULL;
						free(current);
						current = previous->next;
					}
				}
			} else {
				if (current->next == *dcism_studs) { //a break code to stop current from traversing further if it points to dcism_studs
					current = NULL;
				} else { //padayon if wala pa ka abot sa last node
					previous = current;
					current = current->next;
				}
			}
		}	
	}
}

