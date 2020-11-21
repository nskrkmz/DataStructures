#include <stdio.h>
#include <stdlib.h>

int studentNumbers[] = {3463,36734,4732};
char *studentNames[] = {"AAAA","BBBB","CCCC"};

struct student {
char *studentName;
int studentNumber;
struct student *nextStudent;
};
typedef struct student Student;


void pushStudent (Student **headofStack, int studentNumber, char* studentName);
void printStack (Student *headofStack);
void popStudent ( Student **headofStack, Student *temporaryStudent);

int main (void) {
	Student * headofStack = NULL;
	Student * temporaryStudent = (Student* )malloc( sizeof( Student ) );
	// print an empty stack 
	printStack( headofStack );
	// print an empty stack
	
	//push Student to stack
	pushStudent( &headofStack, studentNumbers[0],studentNames[0] );
	pushStudent( &headofStack, studentNumbers[1],studentNames[1] );
	pushStudent( &headofStack, studentNumbers[2],studentNames[2] );
	printStack( headofStack );
	//push Student to stack
	
	//popStudent from Stack 
	//printf("\nPop Students from stack\n");
	//popStudent( &headofStack, temporaryStudent);
	//printStack( headofStack );
	//printf("Removed student from stack --> Number: %-6d Name:%-s\n", (*temporaryStudent).studentNumber, temporaryStudent->studentName);
	//popStudent from Stack
	
	//popStudent from Stack 
	//popStudent( &headofStack, temporaryStudent);
	//printStack( headofStack );
	//printf("Removed student from stack --> Number: %-6d Name:%-s\n", (*temporaryStudent).studentNumber, temporaryStudent->studentName);
	//popStudent from Stack
		 	
	return 0;
}
void popStudent ( Student ** headofStack, Student *temporaryStudent){
	Student * currentStudent = ( *headofStack);
	if (currentStudent == NULL) {
		printf("popStudent:There is no student in the stack...\n");
	}
	else {
	 temporaryStudent->studentName = currentStudent->studentName;
	 temporaryStudent->studentNumber = currentStudent->studentNumber;
	 
	 //set new headof Stack
	 ( *headofStack ) = currentStudent->nextStudent;  
	 //set new headof Stack
	
	//delete student from stack
	free(temporaryStudent); 
	//delete student from stack	
	}
}

void printQueue (Student *headofQueue){
	Student * currentStudent = headofQueue;
	if( currentStudent == NULL) {
		printf("There is no Student in stack...\n");
	}
	else{
		while( currentStudent != NULL ){
			printf("Number: %-6d Name:%-s\n",currentStudent->studentNumber,currentStudent->studentName);
			currentStudent = currentStudent->nextStudent;
		}
	}
}

void pushStudent (Student ** headofStack,int studentNumber,char* studentName){
 Student * newStudent = (Student* )malloc(sizeof(Student));
 if (newStudent == NULL){
 	printf("pushStudent: There is no space for new student...\n");
 	exit( EXIT_FAILURE );
 }
 else {
 	newStudent->studentName = studentName;
 	newStudent->studentNumber = studentNumber;
 	newStudent->nextStudent = ( *headofStack );
 	
 	// set new head of stack
	( *headofStack ) = newStudent;
	// set new head of stack
 }
}
	


