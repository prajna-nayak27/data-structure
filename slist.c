#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "slist.h"

//create a null list
Slist slist_new()
{
	Slist s={NULL,NULL,0};
	return s;
}

//add node to the list
static Node* slist_new_node(int32_t element)
{
	Node* new_node =(Node*) malloc(sizeof(Node));
	new_node->data=element;
	new_node->next=NULL;
	return new_node;
}
//adding header
Slist* slist_add_head(Slist *list,int32_t element)
{
	assert(list!=NULL);
	Node *new_node=slist_new_node(element);
	new_node->next=list->head;
	list->head=new_node;
	if (list->tail==NULL)
	{
		list->tail=new_node;
	}
	++list->length;
	assert((list->length==1 && list->head==list->tail) || (list->length>0 && list->head!=list->tail));
	return list;
}

uint32_t slist_length(const Slist *list) 
{
   return list->length;
}

void print_node(Slist *list)
{
	Node *current_node = list->head;
   	while ( current_node != NULL)
   	{
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
}


uint32_t slist_lookup(const Slist *list, int32_t key)
{
	assert(list!=NULL);
	Node *cur;
	for(cur=list->head;cur!=NULL;cur=cur->next)
	{
		if(cur->data==key)
			{break;}
	}
	return(cur!=NULL);
}

int main()
{
	Slist s = slist_new();
	Slist *list = &s;
	list = slist_add_head(list, 50);
	assert(slist_length(list) == 1);
	list = slist_add_head(list, 20);
	list = slist_add_head(list, 10);
	list = slist_add_head(list, 30);
	slist_lookup(list,10);
	print_node(list);
	return 0;
}
