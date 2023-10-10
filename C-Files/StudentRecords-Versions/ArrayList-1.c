#include <stdio.h> 
#include <string.h>
  
#define MAX 10 
  
typedef char String[30]; 
  
typedef struct studRec { 
     int year; 
     String fname, lname, program; 
     int courses[10]; 
 } StudRec; 
  
 typedef struct list { 
     StudRec studRecList[MAX]; 
     int count; 
 } StudList; 
  
 StudList initList(); 
 void display(StudList D); 
 void push(StudList *P, StudRec temp); 
 void pop(StudList *P); 
  
 int main () { 
  
     StudList mainList = initList(); 
  
     StudRec A = {2, "Lyan", "Jover", "BSIT", {2101, 2102, 2103, 2105, 2106, -1}}; 
     StudRec B = {3, "John", "Doe", "BSCS", {2101, 2102, 2103, 2104, 2105, 2106, -1}}; 
     StudRec C = {2, "Julianne", "Mary", "BSIS", {1201, 2105, 2106, -1}}; 
     StudRec D = {2, "Ariane", "Susan", "BSIT", {-1}}; 
  
     push(&mainList, A); 
     push(&mainList, B); 
     push(&mainList, C); 
     push(&mainList, D); 
  
     display(mainList); 
  
     return 0; 
 } 
  
 StudList initList() { 
     StudList start = {.count = 0}; 
     return start; 
 } 
  
 void push(StudList *P, StudRec temp) { 
     int ndx = P->count; 
     if (ndx != MAX) { 
         P->studRecList[ndx] = temp; 
         P->count++; 
     } else { 
         printf("\nStack is full!\n"); 
     } 
 } 
  
 void pop(StudList *P) { 
     P->count--; 
 } 
  
 void display(StudList D) { 
     StudList temp = {.count = 0};
     int cdx;
     
     while (D.count > 0) {
         push(&temp, D.studRecList[D.count-1]);
         printf("StudRec[%d]\nFirst Name: %s\nLast Name: %s\nProgram: %s\nCourses: ", temp.count, temp.studRecList[temp.count-1].fname, temp.studRecList[temp.count-1].lname, temp.studRecList[temp.count-1].program);
         
         if (temp.studRecList[temp.count-1].courses[0] != -1) {
             for (cdx = 0; temp.studRecList[temp.count-1].courses[cdx] != -1; cdx++) {
                 printf("%d ", temp.studRecList[temp.count-1].courses[cdx]);
             }
         } else {
             printf("[Not enrolled!]");
         }
         
         pop(&D);
         printf("\n\n");
     }
     
 }