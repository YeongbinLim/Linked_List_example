#include<stdio.h>

typedef struct _list {
	struct _node *head;
	int count;
}list;
typedef struct _node {
	int data;
	struct node* next;
}node;

void Insert(list* L, int value, int position)
{
	node *newnode = (node *)malloc(sizeof(int));
	newnode->data = value;
	if (position<1 || position>L->count)
		printf("insert out of range\n");
	else if (position == 1)
	{
		node* tmp_1;
		newnode->next = L->head;
		L->head = newnode;
		
	}
	else
	{
		node *search= L->head;
		int i;
		for (i = 0; i < position-2; i++)
		{
			search = search->next;
		}
		node* tmp=search->next;
		search->next = newnode;
		newnode->next= tmp;

		
	}
	L->count++;
	
}
void delete(list* L, int position)
{
	if (position<1 || position>L->count)
		printf("delete out of range\n");
	else if (position == 1)
	{
		L->head = L->head->next;
	}
	else
	{
		node *search = L->head;
		int i;
		for (i = 0; i < position - 2; i++)
		{
			search = search->next;
		}
		node *tmp= search->next;
		search->next = tmp->next;
	}

	L->count--;
}

void printNodes(list *L) {
	node *p = L->head;
	putchar('[');
	while (p != NULL) {
		printf("%d, ", p->data);
		p = p->next;
	}
	putchar(']');
	putchar('\n');
}

int main()
{
	list *L = (list *)malloc(sizeof(list));
	L->count = 1;
	L->head = NULL;



	Insert(L, 1,1);
	Insert(L, 2,2);
	Insert(L, 3,3);
	delete(L,3);
	Insert(L, 4,3);
	Insert(L, 5,3);
	Insert(L, 6,3);
	delete(L,3);
	delete(L,2);
	Insert(L, 7,2);
	printNodes(L);
	system("pause");
	return 0;

}
// 1754