#include <stdio.h>
#include <string.h>

struct profile { 
	char name[30];
	int age;
};
//struct = keyword, profile = tagname of the struct
//this struct serves as your template when you declare it in main

typedef struct profile Info; 
//typedef = basically alias or rename
//rather than typing struct profile, you can declare a struct profile variable
//by just typing Info instead

typedef char String[30];
//rather than declaring a char array/string with 30 characters
//you can just call it String

int main () {
	
	char name[30]; 
	//this is the usual way of declaring a 30 letter string
	String name1; 
	//this is another way, see that String is an array of 30 char types
	
	struct profile Information1;
	//this is the default way of declaring a struct
	
	Info Information2;
	//this is the other way of declaring the struct with a typedef alias
	//there's no need now to make use of struct profile
	
	Information2.age = 20;
	//to access a member of a struct, use the dot operator
	//Notice that Information2 makes use of the typedef alias yet it still acts as a struct profile variable
	//Because...it is though, lmao
	
	strcpy(Information2.name, "Ethan");
	//when assigning/defining a string in a struct, use strcpy
	//take note that an array cannot be assigned directly after declaration
	//so after delcaring name[30]
	//the compiler won't accept Information2.name = "Ethan"
	//think of manually copying every letter from the given string to the Information2.name. Remember the manual for loop copy method
	
		
	struct profile *ptr = &Information2;
	//yes. pointers won't go away
	//you can declare pointers to a struct
	Info *ptr2 = &Information2;
	//woah! yes that is also possible!
	
	printf("%d", ptr2->age);
	//when accessing a member of a struct using a pointer to a struct
	//use the arrow operator instead
	//NOTE: THE ARROW OPERATOR ACTS AS A DEREFERENCE OPERATOR
	
	ptr2->age = 32;
	//just like this one
	//REMINDER: POINTERS ONLY GET THE ADDRESS AS A VALUE
	//WHEN DEREFERENCING, IT NOW GETS THE VALUE THAT THE ADDRESS HOLDS
	//Would like to reiterate it again since you are now doing Pointer Arithmetic
	//This is very important sd for Linked List traversals. There are two methods.
	
	return 0;
}
