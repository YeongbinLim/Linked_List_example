#include<stdio.h>
typedef struct _tree
{
	int count;
	struct _node* head;

}tree;

typedef struct _node {

	int data;
	int level;
	int child;
	struct node* parent;
	struct node* Lnext;
	struct node* Rnext;

}node;

node* Node(int value)
{
	node* node_2 = value;
	node_2 = (node *)malloc(sizeof(node));
	node_2->data = value;
	node_2->parent = node_2;
	node_2->Lnext = node_2->Rnext = 0;
	node_2->level = 0;
	return node_2;
}

getLeft(node* parent, node* left)
{
	left->parent = parent;

	parent->Lnext = left;
}

getRight(node* parent, node* right)
{
	right->parent = parent;
	parent->Rnext = right;
}

Insert(tree* Tree, int value)
{
	if (Tree->count == 1)
	{
		node* node_1 = (node *)malloc(sizeof(int));
		node_1->data = value;
		node_1->parent = node_1;
		node_1->Lnext = node_1->Rnext = 0;
		node_1->child = 1;
		Tree->head = node_1;
	}
	else if (Tree == NULL)
		printf("NULL tree");
	else
		Search(Tree, value);

/*	else if(Tree->head->Lnext==NULL && Tree->head->Rnext==NULL)
	{
		node* p = Tree->head;
		p->level = 0;
		p->child = 0;
		int i;
		int count = 0;
		p->parent = p;
	}*/
}
Search(tree *T, int value)
{
	node* node_1 = (node *)malloc(sizeof(int));
	node_1->data = value;
	node_1->parent = node_1;
	node_1->Lnext = 0;
	node_1->Rnext = 0;

}
Inorder_Traversal(tree* T)
{
	node* p = T;

	if (p != NULL)
	{

		
		if (p->Lnext != 0)
		{
			p = p->Lnext;
			Inorder_Traversal(p);
			if (p->level != 1)
			printf("%d ", p->data);
			p->level = 1;
			p = p->parent;
			if(p->level != 1)
			printf("%d ", p->data);
			p->level = 1;
		}

		if (p->Rnext != 0) {
			p = p->Rnext;
			Inorder_Traversal(p);
			
			if(p->level != 1)
			printf("%d ", p->data);
			p->level = 1;
		
		}
	}
}
Postorder_Traversal(tree* T)
{
	node* p = T;

	if (p != NULL)
	{

		if (p->Lnext != 0)
		{
			p = p->Lnext;
			Postorder_Traversal(p);
			printf("%d ", p->data);
			p = p->parent;
		

		}
		if (p->Rnext != 0) {

			p = p->Rnext;
			Postorder_Traversal(p);
			printf("%d ", p->data);
			p = p->parent;
		}
		if (p->parent == p)
			printf("%d ", p->data);

	}
}
Preorder_Traversal(node* T)
{
	node* p = T;
	
	if (p != NULL)
	{

		printf("%d ", p->data);
		if (p->Lnext != 0)
		{
			
			p = p->Lnext;
			Preorder_Traversal(p);
			p = p->parent;
		}
		if (p->Rnext != 0) {
			p = p->Rnext;
			Preorder_Traversal(p);
		}
	}
	

}
int main()
{
	tree *T = (tree *)malloc(sizeof(tree));
	T->count = 1;
	T->head = NULL;

	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = 0;
	newnode->parent = newnode;
	newnode->level = 0;
	T->head = newnode;
	newnode->Lnext = T->head->Lnext=0;
	newnode->Rnext = T->head->Rnext=0;



	node* node_1= Node(1);
	node* node_2= Node(2);
	node* node_3 = Node(3);
	node* node_4 = Node(4);
	node* node_5 = Node(5);
	node* node_6 = Node(6);
	node* node_7 = Node(7);
	node* node_8 = Node(8);
	node* node_9 = Node(9);
	node* node_a = Node(10);
	node* node_b = Node(11);
	getLeft(newnode, node_1);
	getRight(newnode, node_2);
	getLeft(node_1, node_3);
	getLeft(node_3, node_4);
	getRight(node_1, node_5);
	getRight(node_5, node_6);
	getLeft(node_2, node_7);
	getRight(node_2, node_8);
	getRight(node_8, node_9);
	printf("Preorder\n");
	Preorder_Traversal(newnode);
	printf("\nPostorder_Traversal\n");
	Postorder_Traversal(newnode);
	printf("\nInorder_Traversal\n");
	Inorder_Traversal(newnode);

	system("pause");
	return 0;
}