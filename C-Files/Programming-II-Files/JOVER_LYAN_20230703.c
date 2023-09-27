#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#define MAX 5

typedef struct {
	int prod_no;
	char prod_name[50];
	char desc[75];
	double price;
} prod_type ;

typedef struct {
	int sales_no;
	prod_type sales_prod;
	int qty;
} sales_type ;

typedef struct {
	sales_type list[MAX];
	int count;
} ADTList ;

void inputADT (sales_type *input);
void displayList (ADTList list);
void insertPos (ADTList *list, int pos);
void deletePos (ADTList *list, int pos);

int main () {
	
	ADTList list = {.count = 0};
	sales_type s1;
	int pos_list;
	char input_choice;
	
	do {
		inputADT(&s1);
		printf("\nNew entry [y/n]? "); scanf(" %c", &input_choice); fflush(stdin);
		(isupper(input_choice)) ? input_choice = tolower(input_choice) : printf("");
		if (input_choice == 'y') {
			list.list[list.count++] = s1;
			printf("Data for position [%d] is inputted!\n", list.count-1);
			printf("Press any key to continue..."); getch();
			system("cls");
		} else {
			printf("Ending the input function!\n");
			list.list[list.count++] = s1;
		}
	} while (input_choice != 'n');
	
	displayList(list);
	
	char function_choice, insert_choice, delete_choice;
	
	do {
		printf("Select function: "); scanf("%d", &function_choice);
		switch (function_choice) {
			case 1:
				printf("\n\tINSERT FUNCTION\n");
				printf("Press any key to get started!\n");
				getch();
				system("cls");
				do {
					printf("Enter the position you want to insert: "); scanf("%d", &pos_list); fflush(stdin);
					deletePos(&list, pos_list);
					printf("\nInsert another[y/n]? "); scanf(" %c", &insert_choice); fflush(stdin);
					(isupper(insert_choice)) ? insert_choice = tolower(insert_choice) : printf("") ;
				} while (insert_choice == 'y'); //false if either position is empty, full, or user wants to do it again
				break;
			case 2:
				printf("\n\tDELETE FUNCTION\n");
				printf("Press any key to get started!\n");
				getch();
				system("cls");
				do {
					printf("Enter the position you want to delete: "); scanf("%d", &pos_list); fflush(stdin);
					insertPos(&list, pos_list);
					printf("\nRemove another[y/n]? "); scanf(" %c", &delete_choice); fflush(stdin);
					(isupper(insert_choice)) ? delete_choice = tolower(delete_choice) : printf("") ;
				} while (insert_choice == 'y');
				break;
			case 0:
				printf("\n\tNO FUNCTION TO PERFORM...\n\tDISPLAYING THE RESULTS INSTEAD...\n\n");
				displayList(list);
				break;
			default:
				break;
		}
	} while (function_choice > 0);
	
	return 0;
}

void inputADT (sales_type *input) {
	
	printf("\t====================\n\tINPUT FOR SALES_TYPE\n\t====================\n\n");
	
	printf("Enter sales number: "); scanf("%d", &input->sales_no);
	printf("Enter quantity number: "); scanf("%d", &input->qty);
	
	printf("\n\t====================\n\tPRODUCT TYPE\n\t====================\n\n");
	
	printf("Enter product number: "); scanf("%d", &input->sales_prod.prod_no); fflush(stdin);
	printf("Enter product name: "); scanf(" %[^\n]", input->sales_prod.prod_name); fflush(stdin);
	printf("Enter product description: "); scanf(" %[^\n]", input->sales_prod.desc); fflush(stdin);
	printf("Enter product price: "); scanf("%lf", &input->sales_prod.price); 
	
}

void displayList (ADTList list) {
	unsigned int i;
	system("cls");
	printf("\n\t================================\n\tDISPLAYING THE PROUDCT INPUTTED\n\t================================\n\n");
	for (i = 0; i < list.count; ++i) {
		printf("[%d]\n", i);
		printf("Sales Number: %d\n", list.list[i].sales_no);
		printf("Quantity Number: %d\n\n\t==========\n", list.list[i].qty);
		
		printf("Product Number: %d\n", list.list[i].sales_prod.prod_no);
		printf("Product Name: %s\n", list.list[i].sales_prod.prod_name);
		printf("Product Description: %s\n", list.list[i].sales_prod.desc);
		printf("Product Price: %.2lf\n\n", list.list[i].sales_prod.price);
	}
}

void insertPos (ADTList *list, int pos) {
	
	sales_type insert, temp;
	
	if (pos < 0 || pos > MAX-1) {
		printf("Invalid bounds/spaces!\n");
		return;
	} else if (pos == MAX-1) {
		printf("The list is full/There is not enough space to insert!\n");
		return;
	} else {
		inputADT(&insert);
		temp = list->list[pos];
		list->list[pos] = insert;
		list->list[pos+1] = temp;
		list->count++;
	}
	
}

void deletePos (ADTList *list, int pos) {
	
	if (pos < 0 || pos > MAX-1) {
		printf("Invalid bounds/spaces!\n");
		return;
	} else {
		list->list[pos-1] = list->list[pos];
		list->count--;
	}
	
}