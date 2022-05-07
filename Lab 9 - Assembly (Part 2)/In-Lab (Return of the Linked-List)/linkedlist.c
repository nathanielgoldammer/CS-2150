//Nathaniel Goldammer (wsn8pk) - April 12, 2022 - linkedlist.c
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define PUSH_FRONT 	0
#define PUSH_BACK 	1
#define POP_FRONT 	2
#define POP_BACK 	3
#define PRINT_LIST 	4
#define HELP 		5
#define QUIT 		6
#define INVALID 	7
#define BUFFER_SIZE 20

void printOptions();
int readInput(int* val);
int isNumber(const char* token);
int isEmpty(const char* input);

int main()
{
	//List node definition
	struct node
	{
		//Let data = the node's data
		int data;

		//The next = the next node in the list
		struct node* next;

		//Let previous = the previous node in the list
		struct node* previous;
	};

	//List definition
	struct list
	{
		//Let size = the number of nodes in the list
		int size;

		//Let head = the (dummy) head of the list
		struct node* head;

		//Let tail = the (dummy) tail of the list
		struct node* tail;
	};

	//Create a list and initialize it's fields
	struct list mylist;
	mylist.head = (struct list*)(malloc(sizeof(struct list)));
	mylist.tail = (struct list*)(malloc(sizeof(struct list)));
	mylist.head->previous = NULL;
	mylist.tail->next = NULL; 
	mylist.head->next = mylist.tail;
	mylist.tail->previous = mylist.head;
	mylist.size = 0;

	int option, val;
	printOptions();
	do 
	{
		option = readInput(&val);
		struct node* mynode;

		switch(option)
		{
			case PUSH_FRONT:

				//Initialize mynode and set mynode->data = val
				mynode = (struct node*)(malloc(sizeof(struct node)));
				mynode->data = val;

				//Initialize mynode->next and mynode->previous
				mynode->next = mylist.head->next;
				mynode->previous = mylist.head;

				//Update mylist.head->next->previous and mylist.head->next
				mylist.head->next->previous = mynode;
				mylist.head->next = mynode;

				//Increment mylist.size by 1
				mylist.size = mylist.size + 1;

				//Return control back to the do-while loop
				break;

			case PUSH_BACK: 

				//Initialize mynode and set mynode->data = val
				mynode = (struct node*)(malloc(sizeof(struct node)));
				mynode->data = val;

				//Initialize mynode->previous and newnode->next
				mynode->previous = mylist.tail->previous;
				mynode->next = mylist.tail;

				//Update mylist.tail->previous->next and mylist.tail->previous
				mylist.tail->previous->next = mynode;
				mylist.tail->previous = mynode;

				//Increment mylist.size by 1
				mylist.size = mylist.size + 1;

				//Return control back to the do-while loop
				break;

			case POP_FRONT: 

				//If mylist is not empty 
				if(mylist.size != 0)
				{
					//Let mynode = the node at the front of mylist
					mynode = mylist.head->next;

					//Update mylist.head->next->next->previous and mylist.head->next
					mylist.head->next->next->previous = mylist.head;
					mylist.head->next = mylist.head->next->next;

					//Delete mynode
					free(mynode);

					//Decrement mylist.size by 1
					mylist.size = mylist.size - 1; 
				}				

				//Return control back to the do-while loop
				break;

			case POP_BACK:	

				//If mylist is not empty			
				if(mylist.size != 0)
				{
					//Let mynode = mylist.tail->previous
					mynode = mylist.tail->previous;

					//Update mylist.tail->previous->previous->next and mylist.tail->previous
					mylist.tail->previous->previous->next = mylist.tail; 
					mylist.tail->previous = mylist.tail->previous->previous;

					//Delete mynode
					free(mynode);

					//Decrement mylist.size by 1
					mylist.size = mylist.size - 1; 
				}

				//Return control back to the do-while loop
				break;

			case PRINT_LIST:

				printf("Elements: ");

				//Set mynode = mylist.head->next 
				mynode = mylist.head->next;

				//While mynode->next != NULL
				while(mynode->next != NULL)
				{
					//Print mynode-data
					printf("%d ", mynode->data);

					//Set mynode = mynode->next
					mynode = mynode->next;
				}
				
				//End the current line of output
				printf("\n");

				//Return control back to the do-while loop
				break;

			case HELP: 

				//Print the menu						
				printOptions();

				//Return control back to the do-while loop
				break;

			case QUIT:

				//Return control back to the do-while loop 						
				break;

			case INVALID:

				//Print an error message
				fprintf(stderr,"Invalid command or operand, please input a valid command or help to see the list again.\n");

				//Return control back to the do-while loop
				break;
		}
	}while(option != QUIT);

	//For each node in mylist except mylist.head and mylist.tail
	for(struct node* temp = mylist.head->next->next; temp->next != NULL; temp = temp->next)
	{
		//Delete temp.previous
		free(temp->previous);

		//If temp->next = NULL
		if(temp->next == NULL)
		{
			//Delete mylist.head and mylist.tail
			free(mylist.head);
			free(mylist.tail);

			//End of main
			return 0;
		}
	}

	//End of main
	return 0;
}

//---------------------------------------
//NOTE: EVERYTHING BELOW THIS LINE SHOULD NOT BE TOUCHED. IT HANDLES INPUT AND SUCH FOR YOU
//---------------------------------------

int readInput(int* val){
	char input[BUFFER_SIZE]="";
	while(isEmpty(input)){
		printf("Enter command: ");
		fgets(input, BUFFER_SIZE, stdin);
		input[strcspn(input, "\n")] = 0;
	}

	char* token = strtok(input, " ");
	
	if ((strcmp(token, "af")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_FRONT;
		} else return INVALID;
	} else if ((strcmp(token, "ab")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_BACK;
		} else return INVALID;
	} else if ((strcmp(token, "rf")) == 0){
	 	return POP_FRONT;
	} else if ((strcmp(token, "rb")) == 0){
	 	return POP_BACK;
	} else if ((strcmp(token, "p")) == 0){
	 	return PRINT_LIST;
	} else if((strcmp(token, "help")) == 0){
	 	return HELP;
	} else if((strcmp(token, "-1")) == 0){
	 	return QUIT;
	} else {
		return INVALID;
	}
}

void printOptions(){
	printf("----------------------------------------------------\n");
	printf("This test harness operates with one linked list.\n");
	printf("Use any of the following options to manipulate it:\n");
	printf("\t* af <num> --- add integer to front\n");
	printf("\t* ab <num> --- add integer to back\n");
	printf("\t* rf       --- remove front element\n");
	printf("\t* rb       --- remove back element\n");
	printf("\t* p        --- print list forward\n");
	printf("\t* help     --- print off this list\n");
	printf("\t* -1       --- exit harness\n\n");
}

int isNumber(const char* token){
	int length, i = 0;
	if (token == NULL)	return 0;
	if(token[0] == '-') 	i = 1;
	length = strlen(token);
	for (; i < length; i++){
	    if (!isdigit(token[i]))
	    	return 0;
	}

	return 1;
}

int isEmpty(const char* input){
	while (*input != '\0'){
		if (!isspace((unsigned char)*input))
			return 0;
		input++;
	}

	return 1; 
}