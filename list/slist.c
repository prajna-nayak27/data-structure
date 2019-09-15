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

Slist* slist_delete_head(Slist *list)
{
	Node *temp;
	if (list->head!=NULL)
	{
		temp=list->head;
		list->head=list->head->next;
		if (list->head==NULL)
		{
			list->tail=NULL;
		}
		--list->length;
		free(temp);
	}
	return list;
}

Slist* slist_add_tail(Slist *list,int32_t element)
{
	assert(list!=NULL);
	Node *new_node=slist_new_node(element);
	if (list->tail!=NULL)
	{
		list->tail->next=new_node;
		list->tail=new_node;
	}
	else
	{
		list->tail=list->head=new_node;
	}
	++list->length;
	return list;
}

Slist* slist_delete_tail(Slist *list)
{
	Node *cur,*tail;
	assert(list!=NULL);
	if (list->tail==NULL)
	{
		return list;
	}
	else
	{
		
	    	tail=list->tail;
	    	if (list->length>1)
	    		{
	    			for (cur=list->head;cur->next!=tail;cur=cur->next);
	    				list->tail=cur;
	    				cur->next=NULL;
	    		}
	         else list->head=list->tail=NULL;

		--list->length;
		free(tail);
	}
	return list;
}

int32_t max_ele(Slist *list)
{
	Node *cur=list->head;
	int32_t max=0;
	assert(list!=NULL);
	if (list->length==1)
	{
		return cur->data;
	}
	else
	{
		for (cur=list->head;cur!=NULL;cur=cur->next)
		{
			if (max<cur->data)
			{
				max=cur->data;
			}
		}
	}
	return max;
}


int32_t min_ele(Slist *list)
{
	Node *cur=list->head;
	int32_t min=cur->data;
	assert(list!=NULL);
	if (list->length==1)
	{
		return cur->data;
	}
	else
	{
		for (cur=list->head;cur!=NULL;cur=cur->next)
		{
			if (min>cur->data)
			{
				min=cur->data;
			}
		}
	}
	return min;
}

Slist* add_element_after_specified(Slist *list,int32_t ele,int32_t spec)
{
	assert(list!=NULL);
	Node *cur, *temp;
	Node *new_node=slist_new_node(ele);
	if((list->head==spec)&&(list->head->next==NULL))
	{
		list->head->next=new_node;
		list->tail=new_node;
	}
	else if((list->tail==spec)&&(list->tail->next==NULL))
	{
		list->tail->next=new_node;
		list->tail=new_node;
		list->tail->next=NULL;
	}
	else
	{
		for(cur=list->head;cur!=NULL;cur=cur->next)
		{
			if(spec==cur->data)
			{
				new_node->next=cur->next;
				cur->next=new_node;
			}
		}
	}
	++list->length;
	return list;
}

SList* delete_specified_ele(Slist *list,int32_t ele)
{
	assert(list!=NULL)
	Node *cur=list->head,*temp;
	if(cur->data==ele)
	{
		list->head=cur->next;
		free(cur);
	}
	else
	{
		for(cur=list->head;cur!=NULL;cur=cur->next)
		{
			if(cur->data==ele)
			{
				temp=cur->next;
				break;
			}
		}	
	        cur->next=temp->next;
	        temp->next=NULL;
	        free(temp);
	}
	--list->length;
	return list;
}
	
				
	
	
