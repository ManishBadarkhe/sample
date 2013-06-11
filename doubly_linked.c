#include "stdlib.h"

typedef struct node
{
	int sample_data;
	struct node *prev;
	struct node *next;
}list;  

list *head = NULL;

void list_add(int data)
{
	list *add = NULL;
	static list *temp = NULL;
	/* get head of linked list */ 
	if (head == NULL){
		head = (list *)malloc(sizeof(list*));
		head->sample_data = data;
		head->next = NULL;
		temp = head;
	} else {
		/* go on add a node after head */
	//	temp = head;
		add = (list *)malloc(sizeof(list *));
	//	while(temp->next != NULL)
	//		temp = temp->next;
		add->sample_data = data;
		add->next = NULL;
		temp->next = add;
		temp = add;
	}
}

/*list_del*/

void show_list()
{
	while (head != NULL)
	{
		printf("%d ->", head->sample_data);
		head = head->next;	
	}
	printf("done\n");	
}

void main()
{
 	list_add(55);
	list_add(88);
	list_add(77);		
	show_list();	
}


