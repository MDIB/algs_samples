#include "stdio.h"
#include "stdlib.h"


struct binary_three
{
	int data;
	struct binary_three *left,
					   *right;
};



struct binary_three * initialize_node()
{
	return malloc(sizeof(struct binary_three));
}

struct binary_three * getNode(struct binary_three *root,int data)
{

	if(root->data == data) return root;
	
	if(root->data>data)
	{
		if(root->right)
		{
			return getNode(root->right,data);
		}
		else
		{
			root->right = initialize_node();
			return root->right;
		}
	}
	else
	{
		if(root->left)
		{
			return getNode(root->left,data);
		}
		else
		{
			root->left = initialize_node();
			return root->left;
		}
	}
}

 int askQuestion(char * question,int opt)
{
   printf("%s\n",question);
   int p;	
   scanf("%d",&p);
	 
	return p;
}

void userInterface(struct binary_three * root)
{
	int data;
	data = askQuestion("Numero :",1);
	if(data!=-1)
	{
		insertNode(root,data);
		userInterface(root);	
	}
}


void printNode(struct binary_three * node)
{
	printf(" [%d] ",node->data);
}

void printAllNodes(struct binary_three * node)
{
	printNode(node);
	if(node->left)
	{
		printAllNodes(node->left);
	}
	if(node->right)
	{
		printAllNodes(node->right);
	}
}

void insertNode(struct binary_three * root,int data)
{
	struct binary_three * node = getNode(root,data);
	node->data=data;
		
}

int main(int argc,char** argv)
{
	struct binary_three * root=initialize_node();
	userInterface(root);
	printAllNodes(root);
	printf("\n","" );
	return 0;
}
