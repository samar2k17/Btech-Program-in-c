#include<stdio.h>
#include<conio.h>

//Create a basic structure for NODE from which new nodes can be created.
struct node
{
	int data;
	struct node *link;
};

//Initialize pointers as globals so that they do not need to be passed in functions.
struct node *header, *ptr, *ptr1, *temp;

//Prototypes for various user defined functions.
void insert_end();
void delete_front();
void delete_end();
void delete_any();
void display();

void main()
{
	int choice;
	int cont = 1;

	//Allocate memory for header node.
	header = (struct node *) malloc(sizeof(struct node));

	clrscr();

	//Set the content of header node
	header->data = NULL;
	header->link = NULL;

	while(cont == 1)
	{
		//Display menu to the user
		printf("\n1. Insert at end\n");
		printf("\n2. Delete from front\n");
		printf("\n3. Delete from end\n");
		printf("\n4. Delete from anywhere\n");
		printf("\n5. Display linked list\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				insert_end();
				break;
			case 2:
				delete_front();
				break;
			case 3:
				delete_end();
				break;
			case 4:
				delete_any();
				break;
			case 5:
				display();
				break;
		}

		printf("\n\nDo you want to continue? (1 / 0): ");
		scanf("%d", &cont);
	}

	getch();
}

//Function to insert a node at the end of a single linked list.
void insert_end()
{
	int data_value;

	printf("\nEnter data of the node: ");
	scanf("%d", &data_value);

	temp = (struct node *) malloc(sizeof(struct node));

	//Traverse to the end of the linked list.
	ptr = header;
	while(ptr->link != NULL)
	{
		ptr = ptr->link;
	}

	temp->data = data_value;
	temp->link = ptr->link;
	ptr->link = temp;
}

//Function to delete a node from the front of a linked list.
void delete_front()
{
	//If the list is already empty
	if(header->link == NULL)
	{
		printf("\nEmpty Linked List. Deletion not possible.\n");
	}
	else
	{
		ptr = header->link;
		header->link= ptr->link;
		free(ptr);
		printf("\nNode deleted from the front.\n");
	}	
}

//Function to delete a node from the end of a linked list.
void delete_end()
{
	if(header->link == NULL)
	{
		printf("\nEmpty Linked List. Deletion not possible.\n");
	}
	else
	{
		//Traverse to the end of the list.
		ptr = header;
		while(ptr->link != NULL)
		{
			ptr1 = ptr;
			ptr = ptr->link;
		}
		ptr1->link = ptr->link;
		free(ptr);
		printf("\nNode deleted from the end.\n");
	}
}

//Function to delete any node from linked list.
void delete_any()
{
	int key;

	if(header->link == NULL)
	{
		printf("\nEmpty Linked List. Deletion not possible.\n");
	}
	else
	{
		printf("\nEnter the data of the node to be deleted: ");
		scanf("%d", &key);

		ptr = header;
		while((ptr->link != NULL) && (ptr->data != key))
		{
			ptr1 = ptr;
			ptr = ptr->link;
		}
		if(ptr->data == key)
		{
			ptr1->link = ptr->link;
			free(ptr);
			printf("\nNode with data %d deleted.\n", key);
		}
		else
		{
			printf("\nValue %d not found. Deletion not possible.\n", key);
		}		
	}
}

//Function to display the contents of the linked list.
void display()
{
	printf("\nContents of the linked list are: \n");
	//Print the contents of the linked list starting from header
	ptr = header;
	while(ptr->link != NULL)
	{
		ptr = ptr->link;
		printf("%d ", ptr->data);
	}
}