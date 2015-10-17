#include"AVLTree.h"

void testInsertAvlTree(){
    int dataArray[]={1,2,3,4,5,6,7,8,9};
    int i=0;
    int data=0;
    avlNode* root=NULL;
    avlNode* parent=NULL;
    while(i<9){
        data=dataArray[i];
        root=insert(root,parent,data);
        i++;
    }
    
    printf("Done creating AVL Tree\n");
    traverseInorder(root);
    printf("\n");
    traversePreorder(root);
    printf("\n");
}