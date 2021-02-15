#include "stdlib.h"
#include <stdio.h>
#include <unistd.h>

typedef struct DNode{
    int data;
    struct DNode *next;
    struct DNode *prev;
}DNode_t;

typedef struct DLL{
    int size;
    struct DNode *head;
    struct DNode *tail;
}DLL_t;



DNode_t * createDNode(int data);
void printNode(DNode_t *node);
void deleteDNode(DNode_t *node);


DLL_t *createDLL();
void DLL_Init(DLL_t *dll, int data);

void printDLL(DLL_t *head);
void printDLL_rev(DLL_t *dll);

void insertAtEnd(DLL_t *dll ,int data);
void insertAtFront(DLL_t *dll, int data);
void insertAtK(DLL_t *dll, int k, int data);

void insertInOrder(DLL_t *dll, int data);

int deleteAtFront(DLL_t *dll);
int deleteAtK(DLL_t *dll, int k);
int deleteAtEnd(DLL_t *dll);

int deleteFirstValue(DLL_t *dll, int val);
int deleteAllValues(DLL_t *dll, int val);


void emptyDLL(DLL_t *dll);
void freeDLL(DLL_t* dll);

void mergeDLL();

