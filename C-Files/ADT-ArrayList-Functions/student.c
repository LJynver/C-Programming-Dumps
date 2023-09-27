#include <stdio.h>
#include "student.h"

Array initList() {
	Array start;
	makeNull(&start);
	return start;
}

void makeNull(Array *course) {
	course->count = 0;
}

void addStud(Array *course, Student newStud, unsigned short pos) {
	int ndx;
	if (pos <= course->count) {
		for (ndx = 0; ndx < course->count && course->students[ndx].id != newStud.id; ++ndx) {}
		if (ndx == course->count) {
			course->students[pos] = newStud;
			++course->count;
		} else {
			printf("\n***** ID already exists! *****\n\n");
		}	
	} else {
		printf("\n***** Position is not available for insertion/Array is full! *****\n\n");
	}

}

void deleteStud(Array *course, unsigned long id) {
	int ndx;
	for (ndx = 0; ndx < course->count && course->students[ndx].id != id; ++ndx) {}
	if (ndx < course->count) {
		for (; ndx < course->count; course->students[ndx] = course->students[ndx+1], ++ndx) {}
		--course->count;
	}
}

void printList(Array course) {
	int ndx, cdx;
	for (ndx = 0; ndx < course.count; ++ndx) {
		printf(" || \tStudent's name\t\t: %s, %s %c\n", course.students[ndx].name.LN, course.students[ndx].name.FN, course.students[ndx].name.MI);
		printf(" || \tStudent's age\t\t: %d\n", course.students[ndx].age);
		printf(" || \tStudent's ID\t\t: %d\n", course.students[ndx].id);
		printf(" || \tStudent's program\t: %s\n", course.students[ndx].program);
		printf(" ==================================================\n");
	}
}