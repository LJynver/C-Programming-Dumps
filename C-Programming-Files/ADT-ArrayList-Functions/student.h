#ifndef STUDENT_H
#define STUDENT_H

#define MAX 20

typedef struct { 
	unsigned long id;
	struct {
		char LN[30], FN[30], MI;
	} name;
	unsigned short age;
	char program[5];
} Student;

typedef struct { 
	Student students[MAX];
	unsigned short count;
} Array;

Array initList();
void addStud(Array *course, Student newStud, unsigned short pos);
void deleteStud(Array *course, unsigned long id);
unsigned short locateStud(Array *course, unsigned long id);
Student retrieveStud(Array *course, unsigned long id);
void makeNull(Array *course);
void printList(Array course);

#endif