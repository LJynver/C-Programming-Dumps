#include <stdio.h>
#include "student.h"
#include "student.c"
#include <string.h>

int main () {
	
	Array main = initList();
	Student testStud;
	
	testStud.id = 22103650;
	testStud.age = 20;
	strcpy(testStud.program, "BSIT");
	strcpy(testStud.name.FN, "Lyan");
	strcpy(testStud.name.LN, "Jover");
	testStud.name.MI = 'R';
	
	addStud(&main, testStud, 0);
	
	testStud.id = 22103789;
	addStud(&main, testStud, 5);
	testStud.id = 22103650;
	addStud(&main, testStud, 0);
	testStud.id = 22103446;
	addStud(&main, testStud, 1);
	printList(main);
	
	return 0;
}