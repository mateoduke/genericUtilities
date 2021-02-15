#include "DNode.h"



//DNode Functions
DNode_t * createDNode(int data){
    DNode_t *head = (DNode_t*)malloc(sizeof(DNode_t));
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

void printNode(DNode_t *node){
    printf("%d ",node->data);
}

void deleteDNode(DNode_t *node){
    free(node);
}

//DLL Functions

DLL_t * createDLL(){
    DLL_t *newDLL = (DLL_t*)malloc(sizeof(DLL_t));
    newDLL->size = 0;
    newDLL->head = NULL;
    newDLL->tail = NULL;
}

void DLL_Init(DLL_t *dll, int data){
    dll->head = createDNode(data);
    dll->tail = dll->head;
    dll->size++;
}

void printDLL(DLL_t *dll){
    DNode_t *tmp = dll->head;
    while(tmp){
        printNode(tmp);
        tmp = tmp->next;
    }
    printf("| Size: %d\n", dll->size);
}

void printDLL_rev(DLL_t *dll){
    DNode_t *tmp = dll->tail;
    while(tmp){
        printNode(tmp);
        tmp = tmp->prev;
    }
    printf("| Size: %d\n", dll->size);
}



void insertAtEnd(DLL_t *dll, int data){
    DNode_t *newNode = createDNode(data);
    DNode_t *tmp = dll->tail;
    tmp->next = newNode;
    newNode->prev = tmp;
    dll->tail = newNode;
    dll->size++;
}

void insertAtFront(DLL_t *dll, int data){
    DNode_t *newNode = createDNode(data);
    DNode_t *tmp = dll->head;
    tmp->prev = newNode;
    newNode->next = tmp;
    dll->head = newNode;
    dll->size++;
}

int deleteAtFront(DLL_t *dll){
    DNode_t *tmp = dll->head;
    int data = tmp->data;
    tmp->next->prev = NULL;
    dll->head = tmp->next;
    deleteDNode(tmp);
    dll->size--;
    return data;
}

int deleteAtEnd(DLL_t *dll){
    DNode_t *tmp = dll->tail;
    DNode_t *newTail = dll->tail->prev;

    int data = tmp->data;
    dll->tail = newTail;
    dll->tail->next = NULL;
    deleteDNode(tmp);
    dll->size--;
    return data;
}

void insertAtK(DLL_t *dll, int k, int data){
    if(k < 0){
        printf("K value out of bounds, K must be greater than or equal to 0\n");
    }
    else if(k == 0){
        insertAtFront(dll,data);
    }
    else if(k > dll->size){
        printf("K value out of bounds, adding to the end of dll\n");
        insertAtEnd(dll,data);
    }
    else{
        DNode_t *tmp = dll->head;
        for(int i = 0; i < k; i++){
            tmp = tmp->next;
        }
        DNode_t *newNode = createDNode(data);
        tmp->prev->next = newNode;
        newNode->prev = tmp->prev;
        tmp->prev = newNode;
        newNode->next = tmp;
        dll->size++;
    }
}

void insertInOrder(DLL_t *dll, int data){
    DNode_t *tmp = dll->head;
    if(tmp->data > data){
        insertAtFront(dll,data);
        return;
    }
    int end = 0;
    while(tmp->next != NULL && !end){
        if(tmp->data <= data && tmp->next->data >= data){
            end = 1;
        }
        else{
            tmp = tmp->next;
        }
    }
    if(!end){
        insertAtEnd(dll,data);
    }
    else{
        DNode_t *newNode = createDNode(data);
        newNode->next = tmp->next;
        newNode->prev = tmp;
        tmp->next = newNode;
        newNode->next->prev = newNode;
        dll->size++;
    }
    
}

int deleteAtK(DLL_t *dll, int k){
    if(k < 0 || k >=dll->size){
        printf("K value out of bounds, [ 0>= K < %d] \n", dll->size);
    }
    else if(k == 0){
        return deleteAtFront(dll);
    }
    else if(k == dll->size-1){
        return deleteAtEnd(dll);
    }
    else{
        DNode_t *tmp = dll->head;
        for(int i = 0; i < k; i++){
            tmp = tmp->next;
        }
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        int data = tmp->data;
        deleteDNode(tmp);
        dll->size--;
        return data;
    }
}

int deleteFirstValue(DLL_t *dll, int val){
    int index = 0;
    DNode_t *tmp;
    tmp = dll->head;
    while(tmp){
        if(tmp->data == val){
            if(tmp == dll->head){
                deleteAtFront(dll);
                return 0;
            }
            else if(tmp == dll->tail){
                index = dll->size;
                deleteAtEnd(dll);
                return index;
            }
            else{
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                deleteDNode(tmp);
                dll->size--;
                return index;
            }
        }
        tmp = tmp->next;
        index++;
    }
    return -1;
}

int deleteAllValues(DLL_t *dll, int val){
    int num_deleted = 0;
    DNode_t *tmp, *tmp2;
    tmp = dll->head;
    while(tmp){
        if(tmp->data == val){
            if(dll->size == 1){
                deleteDNode(dll->head);
                dll->head = NULL;
                dll->tail = NULL;
                dll->size = 0;
                return ++num_deleted;
            }
            else if(tmp == dll->head){
                int y = deleteAtFront(dll);
                num_deleted++;
                tmp = dll->head;
            }
            else if(tmp == dll->tail){
                int x = deleteAtEnd(dll);
                return ++num_deleted;
            }
            else{
                tmp2 = tmp;
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                dll->size--;
                num_deleted++;
                tmp = tmp->next;
                deleteDNode(tmp2);
            }
        }
        if(tmp->data != val)
            tmp = tmp->next;
    }
    return num_deleted;
}

void emptyDLL(DLL_t *dll){
    DNode_t **tmp, *tmp2;
    tmp = &dll->head;
    tmp2 = dll->head;
    while(tmp2){
        *tmp = tmp2->next;
        deleteDNode(tmp2);
        tmp2= *tmp;
        dll->size--;
    }
}

void freeDLL(DLL_t *dll){
    emptyDLL(dll);
    free(dll);
}


