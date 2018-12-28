#ifndef LIST_H
#define LIST_H

#include<stdio.h>

struct Node 
{
	int var;
	struct Node* ptr;
};

struct Node* constructList(int);
struct Node* destroyList(struct Node *);
size_t size(struct Node *);
struct Node* insert(struct Node *, int);
int find(struct Node *, int);
int traverse(struct Node *, char *);
struct Node* removeItem(struct Node *, int);
char* traverse2(struct Node *);

//include other methods
#endif




