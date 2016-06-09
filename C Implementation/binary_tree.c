#include "stdio.h"
#include "stdlib.h"

#define Idade 1
#define Nome 2


struct person{
	char* name;
	int age;
};
struct binary_tree
{
	struct person *item;
	struct binary_tree *left,
					   *right;
};



struct binary_tree * initialize_node()
{
	return malloc(sizeof(struct binary_tree));
}

struct person * initialize_data()
{
	return malloc(sizeof(struct person));
}

struct person * askQuestion(char * question,int opt)
{
	struct person * p = initialize_data();
	printf(question,"");
	p->name=malloc(sizeof(char)*50);	
	switch(opt)	
	{
		case Idade : scanf("%d",&(p->age));
				 break;
	    case Nome : scanf("%50s",p->name);
	    		 break;
	}
	return p;
}

struct person * userInterface()
{
	struct person *p = askQuestion("Nome da Pessoa :",Nome);
	p->age = askQuestion("Idade da Pessoa :",Idade)->age;
	return p;
}

int main(int argc,char** argv)
{
	struct binary_tree * root = initialize_node();

	while(1)
	{

	}

	return 0;
}
