#include <stdlib.h>
#include <stdio.h>
/*Library*/

struct node {
	int x;
	struct node *next;
};
/*Struct constructor. Contains an int and a POINTER to a node.
Total reserved mem: int + pointer (Not infinitely recursive constructor call!)*/

void input(struct node *conductor)
{
	/*input method which accepts a node pointer and calls it conductor*/
	int temp_x;
	/*Temp x value*/
	struct node *temp_node;
	/*Temp node interface (yet permanent memory location on pointer*/
	temp_node = malloc(sizeof(struct node));
	/*Reserve node space*/
	puts("Input operation called\r\n\n");		
	while (temp_x < 48 || temp_x > 57)
	{
		if (temp_x != 10)
		{
			puts("Please enter a positive integer less than 10\r\n");
		}		
		temp_x = getchar();
		/*Accept the first int between 0 and 9 that user enters*/
	}
	temp_x = temp_x - 48;
	/*Deduct 48 to convert from ASCII to Denary*/
	temp_node->x = temp_x;
	temp_node->next = 0;
	/*Update temp node and fit with end of list value for next*/
	while (conductor->next != NULL)
		{
			conductor = conductor->next;
			/*Traverse to the last element in the list*/	
		}
	conductor->next = temp_node;
	/*Add the new element*/
	free(temp_node);
}

void output(struct node *conductor)
{	
	puts("\r\nOutput operation called\r\n");
	while (conductor != NULL)
		{
			printf( "\r\nNode Data: %d\n", conductor->x );
			conductor = conductor->next;	
		}

/*Above code traverses root node and prints each x value in sequence*/
}

int main()
{

struct node *root;
/*Create a new pointer to a node data type (compiler makes no distinction)*/
struct node *conductor;
/*Create a new pointer to a node data type (compiler makes no distinction)*/

root = malloc(sizeof(struct node));
/*Assign some memory to root*/
/*Pointer has the value of a pointer to a chunk of reserved memory which is
sized to contain a single node. Memory will NOT be contiguous to other nodes*/
root->next = NULL;
/*On the node that root is pointing to, get the next value and set it to NULL*/
root->x = 0;
/*The data chunk of the node that root is pointing to has the val of 0*/
conductor = root;
/*Conductor pointer has the same value has root pointer*/

int tracker = 1;
/*Value which tracks program's flow*/
char operation = '!';
/*Program which tracks programs operation*/

while (tracker != 0)
	{
		/*If program is not ending...*/
		if (operation != 10)
		/*If operation is not a newline (fixes a nuance with getchar())*/
		{
			puts("Please choose an operation");
			puts("0 to Quit Application\r\n1 to Display Node data in pointer order\r\n2 to Input new data into node.");
			/*Display instructions*/
		}
		operation = getchar();	
		/*Get single character of user input*/
		switch(operation)
		{
			case '0' : tracker = 0;break;
			case 49 : output(conductor); break;
			case 50 : input(conductor); break;
			default : break;
			/*if operation flow is char0, quit. if char 1, display output, if char2, display input prompt, otherwise, restate menu*/
		}
	}
	free(root);
	/*Free root pointer from heap (thus removing process from OS control! VERY IMPORTANT!)*/
return 0;
}