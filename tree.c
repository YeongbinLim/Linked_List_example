#include<stdio.h>

typedef struct _tree
{
	int count;
	struct node* head;

}tree;

typedef struct _node {

	int data;
	int level;
	int child;
	struct node* parent;
	struct node* Lnext;
	struct node* Rnext;
	
}node;

Insert(tree* T, int value)
{
	node* newnode = (node *)malloc(sizeof(int));
	newnode->data = value;
	newnode->parent = newnode;
	if (T == NULL)
		printf("NULL tree");

	else 
	{
		node* tmp_1;
		newnode->Lnext = T->head;
		T->head = newnode;
		node* p = T->head;
		
		p->level = 0;
		p->child = 0;
		int i;
		int count=0;
		p->parent = p;

		while(!p->Lnext)
		{
			p->parent = p;
			p->data = newnode->data;
			p = p->Lnext;
			p->child++;
			printf("%d %d %d\n",p,p->level,p->child,p->parent);
		}

		while (!p->Rnext)
		{
			p->parent = p;
			p->data = 3;
			p = p->Rnext;
			p->child++;
			printf("%d %d %d\n", p, p->level, p->child, p->parent);
		} 
		

	}
}
Backtracking(tree* T)
{
	node* p = T->head;
	int i;
	while (!p)
	{
		p = p->Lnext;
		Backtracking(p);
		p = p->Rnext;
		Backtracking(p);
	}
	
}
Postorder_Traversal(tree* T)
{

}
Inorder_Traversal(tree* T)
{

}
Preorder_Traversal(tree* T)
{

}
int main()
{
	tree *T = (tree *)malloc(sizeof(int));
	T->count = 1;
	T->head = NULL;

	Insert(T, 9);

}