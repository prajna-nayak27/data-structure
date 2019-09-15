/*
 *	Author : Prajna Nayak
 *	Specification file for Single Linked List
 *	Contain test cases to test various functionalities
 *	of Single Linked List.
*/


#include<assert.h>
#include "slist.h"
#include<stdio.h>
/* test case to check creation of empty slist variable */
void test_empty_list()
{
	Slist s = slist_new();
	Slist *list = &s;
	assert (slist_length(list) == 0);
}
/*function to print the elememts in the list*/
int print_node(Slist *list)
{
Node *cur;
for(cur=list->head;cur!=NULL;cur=cur->next)
{
  printf("%d\n",cur->data);
}
return 0;
}

/*	test case to check various functions
*/
void test_conditions()
{

	Slist s = slist_new();
	Slist *list = &s;
	list = add_head(list, 10);
	assert (slist_length(list) == 1);
	list = add_head(list, 20);
	list = add_head(list, 30);
	list = add_head(list, 40);
	list = add_head(list, 50);
        
	assert(slist_length(list)== 5);
	assert(lookup(list,30));
      
        list=add_tail(list,60);
        assert(lookup(list,60));
        
        list=delete_head(list);
        
        assert(!lookup(list,50));
       
        list=delete_tail(list);
        assert(!lookup(list,60));
        
       assert(minimum(list)==10);
       assert(maximum(list)==40);
       
      list=add_element_after_specified(list,60,40);
      assert(lookup(list,60));
      
      list= delete_specified(list,10);
      assert(!lookup(list,10));
      
}

int main()
{
	test_empty_list();
	test_conditions();
	return 0;
}



/*
 *	Running programs. 
 *
 *	gcc slist.c slist_spec.c -o slist
 *
 *	If you get errors, fix them. Otherwise you have exe file
 *	with name 'slist' (due to -o slist option used during compilation)
 *	
 *	Running exe file:	./a.out slist
 *	If you don't get any message in terminal, code executed perfectly
 *	( No news good news!!!!!!!)
 *
*/
