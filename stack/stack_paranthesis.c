#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include "stack.h"

Stack* balance_paranthesis(char par[])
{
	Stack s= stack_new(10);
	Stack *stk= &s;
	StackResult res;
	for (int i = 0; i < strlen(par);i++)
	{
		if (par[i]=="{" || par[i]=="(" || par[i]=="[")
		{
			stk=stack_push(stk,par[i],&res);
			continue;
		}
		else if (stk->data[stk->top]=="{" && par[i]=="}")
		{
			stk=stack_pop(stk,&res);
			continue;
		}
		else if (stk->data[stk->top]=="(" && par[i]==")")
		{
			stk=stack_pop(stk,&res);
			continue;
		}
		else if (stk->data[stk->top]=="[" && par[i]=="]")
		{
			stk=stack_pop(stk,&res);
			continue;
		}
		else if (par[i]=="}" || par[i]=="}" || par[i]=="}")
		{
			break;
		}
		else
		{
			assert(stk->top==-1);
			return 0;
		}
	}
	assert(stk->top==-1);
	return 0;
}

int postfix(char par[])
{
	Stack s= stack_new(10);
	Stack *stk= &s;
	StackResult res;
	for (int i = 0; i < strlen(par); i++)
	{
		if (isdigit(par[i]))
		{
			stk=stack_push(stk,par[i],&res);
		}
	}
}

int main()
{
	char par[10];
	printf("Enter the expression:");
	scanf("%c",&par);
	balance_paranthesis(par);
	postfix(par);
	return 0;
}