#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STACK
{
	char room[51];
	int top;
}stack;

void push(stack *s, char c);

char pop(stack *s);

int priority(char c);

int main()
{
	char ch;
	char midex[51];
	int k = 0, len;
	stack *op;

	op = (stack*)malloc(sizeof(stack));
	op->top = -1;

	scanf("%s",midex);

	len = strlen(midex);
	while(k<len)
	{
		ch = midex[k++];
		
		if(ch>='a' && ch<='z')
		{
			printf("%c",ch);
			continue;
		}

		else
		{
aa:
			if(priority(op->room[op->top])>priority(ch)||op->top>-1&&priority(op->room[op->top])==priority(ch))
			{
				if(ch==')')
				{
					char c = pop(op);
					while(c!='(')
					{
						printf("%c",c);
						c = pop(op);
					}
				}
				else if(op->room[op->top] == '(')
				{
					push(op,ch);
					continue;
				}
				else
				{
					printf("%c",pop(op));
					goto aa;
				}
			}
			if(ch!=')') push(op,ch);
		}
	}

	while((op->top) > -1)
	{
		printf("%c",pop(op));
	}

	printf("\n");

	return 0;
}

void push(stack *s, char c)
{
	s->room[++s->top] = c;
}
char pop(stack *s)
{
	return s->room[s->top--];
}
int priority(char c)
{
	if(c=='(') return 2;
	else if(c=='*' || c=='/') return 1;
	else if(c==')') return -1;
	else return 0;
}