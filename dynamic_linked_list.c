#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*Library*/

struct node {
	int x;
	struct node *next;
	struct node *prev;
};
/*Struct constructor. Contains an int and a POINTER to a node.
Total reserved mem: int + pointer (Not infinitely recursive constructor call!)*/

void delete(struct node *conductor, struct node *root)
{
	puts("Delete operation called\r\n\n");
	/*input method which accepts a node pointer and calls it conductor*/
	int i = 0;
	//Variable which will contain the length of the node list
	int deletePoint;
	//Variable which will hold the index position of the node to be deleted
	conductor = root;
	while (conductor != NULL)
		{
			i++;
			conductor = conductor->next;
			/*Traverse to the last element in the list*/
			//get i value (max node in list)	
		}
	conductor = root;
	i--;
	//Reset conductor and find 0index number of nodes
	printf("\r\nPlease enter a positive integer less or equal to than %d (end) inclusive. The node will be deleted at this index point. \r\n", i);
	printf("PLEASE NOTE THAT THE ROOT NODE CANNOT BE DELETED UNLESS THERE ARE FURTHER NODES. THE DEFAULT VALUE OF ROOT NODE IS 0. THIS CAN BE AMENDED. THE MINIMUM AMOUNT OF NODES THAT CAN BE IN THE LIST AT ANY GIVEN POINT IS 1\r\n");
	printf("Press 'a' to abort\r\n\n");
	scanf("%d", &deletePoint);
	//Request and get user input and assign to deletePoint
	if (deletePoint != 97 && deletePoint != 65)
	{
		//Deals with C nuance
	int temp_x;
	/*Temp x value*/		
	if (deletePoint == i)
	{	
	/*If deleteing node to the end of the list*/
		int a = 0;
		struct node *temp_node;
		/*Temp node interface (yet permanent memory location on pointer*/
		temp_node = malloc(sizeof(struct node));
		/*Reserve node space*/
		while (conductor->next != NULL)
			{
				conductor = conductor->next;
				/*Traverse to the last element in the list*/	
			}
		temp_node = conductor;
		free(conductor);
		conductor = root;
		//Store conductor address. Free space at that address. Reset conductor
		while (conductor->next != NULL)
		{
			if (conductor->next == temp_node)
			{
				conductor->next = 0;
				printf("\r\nFinal node deleted\r\n");
				break;
				//Return back through nodes. The final nonnull node's next position is nulled
			}
			else
			{
			conductor = conductor->next;
			//If not last node, go through list
			}
			/*Traverse to the last element in the list*/	
		}
		conductor = root;
		//Reset conductor
	}
	else if(deletePoint == 0)
	{
		//If deleting first point
	int i = 0;
	struct node *temp_node;
		/*Temp node interface (yet permanent memory location on pointer*/
		temp_node = malloc(sizeof(struct node));
		/*Reserve node space*/
	while (conductor->next != NULL)
	//Go to last node...
		{
			conductor->x = conductor->next->x;
			//Each x value of conductor is assigned to next x value
			conductor = conductor->next;
			//Go through list	
		}
		temp_node = conductor;
		//Final node is temp stored
		free(conductor);
		conductor = root;
		//Last node is freed and conductor reser
		while (conductor->next != NULL)
		{
			if (conductor->next == temp_node)
			{
				conductor->next = 0;
				printf("\r\nFirst node deleted\r\n");
				//See above to confirm. Last node tied off
				break;
			}
			else
			{
			conductor = conductor->next;
			}
			/*Traverse to the last element in the list*/	
		}
		conductor = root;
		//Reset conductor
	}
	else
	{
		int a = 0;
		//Variable which will contain current index position in loop through node list
		while (conductor != NULL)
			{
				//Go through node list
				if (a == deletePoint -1)
				{
					//Get to node prior to target node (as it is the target node's position that is being taken)
					conductor->next = conductor->next->next;
					conductor->next->next->prev = conductor;
					//Get right address that skips the target address
					free(conductor->next);
					//Kill target node
					printf("\r\nNode Deleted\r\n");
					break;
					//Add the new node into the list
				}
				else
				{
					//Keep looking for target node
					a++;
					conductor = conductor->next;
				}
				/*Traverse to the last element in the list*/	
			}
		}
	}
}

void input(struct node *conductor, struct node *root)
{
	/*input method which accepts a node pointer and calls it conductor*/
	int i = 0;
	//Variable which will contain the length of the node list
	int insPoint;
	//Variable which will hold the position which the new node will be inserted	
	while (conductor != NULL)
		{
			i++;
			conductor = conductor->next;
			/*Traverse to the last element in the list*/
			//get i value	
		}
	conductor = root;
	printf("\r\nPlease enter a number between, 0 and %d (end) inclusive. The new node will be inserted at this point\r\n", i);
	scanf("%d", &insPoint);
	//Request and get user input and assign to insPoint
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
	
	if (insPoint == i)
	{	
	/*If adding node to the end of the list*/
		temp_node->x = temp_x;
		//Store value in node
		temp_node->next = 0;
		//Null point the end of the tempnode (soon to be end of list)
		/*Update temp node and fit with end of list value for next*/
		int a = 0;
		while (conductor->next != NULL)
			{
				conductor = conductor->next;
				/*Traverse to the last element in the list*/	
			}
		temp_node->prev = conductor;
		conductor->next = temp_node;
		//Update end of list
	}
	else if(insPoint == 0)
	{
		/*If adding node to the beginning of the list*/
		temp_node->x = conductor->x;
		temp_node->prev = conductor;
		//Beginning of list data is held
		conductor->x = temp_x;
		//Beginning of list data updated with current data
		while (conductor->next != NULL)
			{
				conductor = conductor->next;
				/*Traverse to the last element in the list*/	
			}
		conductor->next = temp_node;
		//Old root data added to the end of the list (but referenced properly)
	}
	else
	{
		int a = 0;
		//Variable which will contain current index position in loop through node list
		temp_node->x = temp_x;
		//update tempnode
		while (conductor != NULL)
			{
				//Go through node list
				if (a == insPoint -1)
				{
					//Get to node prior to target node (as it is the target node's position that is being taken)
					temp_node->next = conductor->next;
					temp_node->prev = conductor;
					conductor->next->prev = temp_node;
					//Temp node gets current nodes reference
					conductor->next = temp_node;
					break;
					//Add the new node into the list
				}
				else
				{
					//Keep looking for target node
					a++;
					conductor = conductor->next;
				}
				/*Traverse to the last element in the list*/	
			}
	}
}

void output(struct node *conductor)
{	
	puts("\r\nOutput operation called\r");
	int i = 0;
	while (conductor != NULL)
		{
			printf("\r\nNode Index Number: %d", i);
			printf( "\r\nNode Data: %d", conductor->x );
			printf( "\r\nNode Address: %p", conductor);
			printf( "\r\nNode Previous Address: %p", conductor->prev);
			printf( "\r\nNode Next Address: %p\n", conductor->next);
			conductor = conductor->next;	
			i++;
		}
/*Above code traverses root node and prints each x value in sequence*/
}

void amend(struct node *conductor, struct node *root)
{
	puts("Amend operation called\r\n\n");
	/*input method which accepts a node pointer and calls it conductor*/
	int i = 0;
	//Variable which will contain the length of the node list
	int amendPoint;
	//Variable which will hold the position which the new node will be inserted	
	while (conductor != NULL)
		{
			i++;
			conductor = conductor->next;
			/*Traverse to the last element in the list*/
			//get i value	
		}
	i--;
	conductor = root;
	printf("\r\nPlease enter a positive integer less or equal to than %d (end) inclusive. The node at this point will be amended\r\n", i);
	scanf("%d", &amendPoint);
	//Request and get user input and assign to amendPoint
	int temp_x;
	/*Temp x value*/	
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
int a = 0;
//Variable which will contain current index position in loop through node list
while (conductor != NULL)
	{;
		//Go through node list
		if (a == amendPoint)
		{
			//Get to node prior to target node (as it is the target node's position that is being adjusted)
			conductor->x = temp_x;
			break;
			//Add the new node into the list
		}
		else
		{
			//Keep looking for target node
			a++;
			conductor = conductor->next;
		}
		/*Traverse to the last element in the list if necessary*/	
	}
}

void navigate(struct node *conductor, struct node *root, int index)//, int index)
{
	puts("Navigation Operation Called\r");
	
	char input = '!';
	conductor = root;
	int a = 0;
	int end = 0;
	bool done = false;
	//Method vars
	
	while (conductor != NULL)
	{
		conductor = conductor->next;
		end++;
	}
	end--;
	//Find number of nodes in array
	
	conductor = root;
	while (conductor->next != NULL)
	{
		if (a != index)
		{
			a++;
			conductor = conductor->next;
		}
		else
		{
			break;
		}
	}
	//Find which node you are looking for
	//printf("\r\nInput = %d\r\n", input);
	getchar();
	if (input != 10)
	{
	printf("\r\nNode Index Number: %d", index);
	printf( "\r\nNode Data: %d", conductor->x );
	printf( "\r\nNode Address: %p", conductor);
	printf( "\r\nNode Previous Address: %p", conductor->prev);
	printf( "\r\nNode Next Address: %p\r\n", conductor->next);
	puts("\r\nPress 'n' to display next address. Press 'p' to see previous address. Press 'i' to view specific node using index. Press 'q' to quit to Main Menu\r\n");
	//Print instruction and get input as long as input other than newline entered
	}
	input = getchar();
	//printf("\r\nInput = %d\r\n", input);
	//Reset conductor
	while (done != true)
	{
		//As long as not declared finished...
	switch(input)
	{
		case 'p': 
		{
			//If p entered
			if	(conductor->prev != NULL)
			{
				conductor = conductor->prev;
				navigate(conductor, root, index -1);
				done = true;
				break;
				//Jump back one node (as long as one exists)
				//Pass new node position to method recursively
			}
			else
			{
				puts("Node contains no prev address. Action aborted\r\n");
				navigate(conductor, root, index);
				done = true;
				break;
				//Instruct and recall method with same index
				//Recursive method recall
			}
		}
		case 'n':
		{
			if	(conductor->next != NULL)
			{
				conductor = conductor->next;
				navigate(conductor, root, index + 1);
				done = true;
				break;
			}
			else
			{
				puts("Node contains no next address. Action aborted\r\n");
				navigate(conductor, root, index);
				done = true;
				break;
			}
			//See prev code (invert)
		}
		case 'i':
		{
			int viewpoint = 0;
			index = 0;
			printf("\r\nPlease enter desired node index number\r\nNOTE: NUMBER MUST BE POSITIVE INTEGER BETWEEN 0 AND %d (INCLUSIVE)\r\n", end);
			scanf("%d", &viewpoint);
			//Get index point from user
			conductor = root;
			while (conductor != NULL)
			{
				if (viewpoint == index)
				{
					//Find right node and pass the right node to the method recursively
					navigate(conductor, root, viewpoint);
					done = true;
					break;
				}
				else
				{
					index++;
					conductor = conductor->next;
				}
			}
		}
		case 'q':
		{
			done = true;
			break;
			//Method exits
		}
		case 10 : navigate(conductor, root, index); done = true; break;
		//Recall method (input is refreshed to other input or '!')
		default:
		{
			puts("Command not recognised.\r\n");
			navigate(conductor, root, index);
			done = true;
			break;
			//Instruct and recall (input refreshed)
		}
	}
	}
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
root->prev = NULL;
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
		if (operation != 10 && operation != 97)
		/*If operation is not a newline (fixes a nuance with getchar())*/
		{
			puts("Please choose an operation");
			puts("0 to Quit Application\r\n1 to Display Node data in pointer order\r\n2 to Input new data into node\r\n3 to Amend node\r\n4 to Delete Node\r\n5 to Navigate Nodes Manually");
			/*Display instructions*/
		}
		operation = getchar();	
		/*Get single character of user input*/
		switch(operation)
		{
			case '0' : tracker = 0;break;
			case 49 : conductor = root; output(conductor); break;
			case 50 : conductor = root; input(conductor, root); break;
			case 51 : conductor = root; amend(conductor, root); break;
			case 52 : conductor = root; delete(conductor, root); break;
			case 53 : conductor = root; navigate(conductor, root, 0); break;
			default : break;
			/*if operation flow is char0, quit. if char 1, display output, if char2, display input prompt, char3, amend nodes, char 4, delete nodes, char 5 navigate nodes, otherwise, restate menu*/
		}
	}
	free(root);
	/*Free root pointer from heap (thus removing process from OS control! VERY IMPORTANT!)*/
return 0;
}