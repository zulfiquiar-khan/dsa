#include"AVLTree.h"

void testInsertAvlTree(){
    int dataArray[]={9,8,7,6,1,3,2,5,4};
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

void testCreateFullBalanceBst(){
    int count=0;
    avlNode* root=createFullBalanceBst(3,&count);
    printf("Done creating AVL Tree\n");
    traverseInorder(root);
    printf("\n");
    traversePreorder(root);
    printf("\n");
}

void testGenerateAVLTreeWithMinNodes(){
    int count=0;
    avlNode* root=generateAVLTreeWithMinNodes(3,&count);
    printf("Done creating AVL Tree\n");
    traverseInorder(root);
    printf("\n");
    traversePreorder(root);
    printf("\n");
}