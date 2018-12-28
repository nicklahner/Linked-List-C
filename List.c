/*
 * Nick Lahner
 * CSE 109
 * Program 3
 * This program will use a struct pointer Node
 * which is declared in List.h to construct a linked
 * list. The user can add nodes, removes nodes, get the size of the list, 
 * and can create a new list. The program will print the list after
 * every command
 */
#include"List.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>


struct Node* constructList(int val) 
{
	struct Node *first= (struct Node*)malloc(sizeof(struct Node*));	
	first->var = val;
	first->ptr = NULL;	
	return first;	
}
struct Node* destroyList(struct Node* node) 
{
	if(!(node))
	{ 
		return NULL;
	}
	if (!(node -> ptr))
	{
		free(node);
		node = NULL;
	}
	else 
	{
		struct Node *temp = node -> ptr;
		destroyList(temp);
		free(node);
		node->ptr = NULL;
		node = NULL;
    }
	return NULL;
}

size_t size(struct Node* node) 
{
	if (!(node))
	{
		return 0;
	}
	else if (!(node->ptr)) 
	{	
		return 1;	
	}
	else if(node->ptr) 
	{		
		return 1 + size(node->ptr);
	} 
	return 0;
}

struct Node* insert(struct Node* node, int val)
{

	struct Node* first = node;	
	if (!(node))
	{
		return constructList(val);
	}

	while(node->ptr)
	{
		node = node->ptr;
	}	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	node->ptr = newNode;
	newNode->var = val;
	newNode->ptr = NULL;
	return first;	
	
}


int find(struct Node* node,int val) 
{
	if (node) 
	{
			if (node->var == val) 
			{
				return 1;
			}
			else 
			{
				find(node->ptr, val);
			}
	}	
	return 0;
}

int traverse(struct Node* node, char* string)
{
	char *word = (char*)calloc(1, sizeof(char*));		
	if (!(node)) 
	{
		return 0;	
	}

	while(node) 
	{		
		sprintf(word, "%d, ", node->var);
		strcat(string, word);
		node = node->ptr;
	}
	free(word);
	word = NULL;
	string[strlen(string)-2] = '\0';


	return 1;
}

struct Node* removeItem(struct Node* node, int val)
{
	struct Node *first;
	struct Node *temp;
	if (node)
	{
		first = node;
		while(node->var == val)
		{
			temp = node;
			node = node->ptr;
			first = node;
			free(temp);
			temp = NULL;
			if(!(node))
			{
				return NULL;
			}	
		}
		if (node->ptr)
		{
			while(node->ptr)
			{
				if (node ->ptr -> var == val)
				{	
					temp = node->ptr;
					node -> ptr = temp->ptr;
					free(temp);
					temp = NULL;
				}
				node = node->ptr;
				if(!(node))
				{
					return first;
				}
			}
		}
		return first;
	}
	else
	{
		return NULL;	
	}
}

char* traverse2(struct Node* node)
{
	if (!(node))
	{
		return "";		
	}		
	char *word = (char*)calloc(1, (13*size(node)) * sizeof(char*));
	traverse(node, word);	
	return word;
}

