#include "DNode.h"

void starline();

int main(){

    printf("Begin DLL Testing");
    starline();
    printf("Test 1: Creating & Deleting a Node");
    
    DNode_t *testNode1 = createDNode(10);
    printNode(testNode1);
    deleteNode(testNode1);

    starline();

    printf("Test 2: Creating & Deleting a DLL");
    DLL_t *dll1 = createDLL();
    DLL_Init(dll1, 0);
    for(int i = 0; i < 20; i++){
        insertAtFront(dll1,i);
    }
    printDLL(dll1);

    starline();
    printf("Test 3: Inserting at Front & End of DLL");
    for(int i = -5; i < 0; i++){
        insertAtFront(dll1,i);
    }

    starline();
    printf("Test 4: Inserting at K");
    
    
    return 0;
}

void starline(){
    printf("\n*******************************************************************************************\n");
}
