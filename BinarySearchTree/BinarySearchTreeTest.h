#include"BinarySearchTree.h"

bstNode* createBstForTest(){
    bstNode* newNode1=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode2=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode3=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode4=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode5=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode6=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode7=(bstNode*)malloc(sizeof(bstNode));
    
    newNode1->data=7;
    newNode1->left=newNode1->right=NULL;

    newNode2->data=4;
    newNode2->left=newNode2->right=NULL;
    
    newNode3->data=9;
    newNode3->left=newNode3->right=NULL;

    newNode4->data=2;
    newNode4->left=newNode4->right=NULL;
    
    newNode5->data=5;
    newNode5->left=newNode5->right=NULL;
    
    newNode6->data=8;
    newNode6->left=newNode6->right=NULL;
    
    newNode7->data=11;
    newNode7->left=newNode7->right=NULL;
    
    newNode1->left=newNode2;
    newNode1->right=newNode3;
    newNode2->left=newNode4;
    newNode2->right=newNode5;
    newNode3->left=newNode6;
    newNode3->right=newNode7;
    
    return newNode1;
}
void testFindAnElementRecursive(){
    bstNode* root=createBstForTest();
    bstNode* element=findAnElementRecursive(root,5);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementRecursive(root,2);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementRecursive(root,8);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementRecursive(root,11);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementRecursive(root,25);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
}

void testFindAnElementIterative(){
    bstNode* root=createBstForTest();
    bstNode* element=findAnElementIterative(root,5);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementIterative(root,2);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementIterative(root,8);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementIterative(root,11);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementIterative(root,25);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
}

void testFindMinimumElementRecursive(){
    bstNode* root=createBstForTest();
    bstNode* min=findMinimumElementRecursive(root);
    if(min==NULL)printf("Tree is empty\n");
    else printf("Min : %d \n",min->data);
}

void testFindMinimumElementIterative(){
    bstNode* root=createBstForTest();
    bstNode* min=findMinimumElementIterative(root);
    if(min==NULL)printf("Tree is empty\n");
    else printf("Min : %d \n",min->data);    
}

void testFindMaximumElementRecursive(){
    bstNode* root=createBstForTest();
    bstNode* min=findMaximumElementRecursive(root);
    if(min==NULL)printf("Tree is empty\n");
    else printf("Min : %d \n",min->data);
}

void testFindMaximumElementIterative(){
    bstNode* root=createBstForTest();
    bstNode* min=findMaximumElementIterative(root);
    if(min==NULL)printf("Tree is empty\n");
    else printf("Min : %d \n",min->data);
}

void testFindInorderPredecessor(){
    bstNode* root=createBstForTest();
    bstNode* predecessor=findInorderPredecessor(root,root);
    if(predecessor==NULL)printf("Not found\n");
    else printf("Predecessor : %d \n",predecessor->data);
}

void testFindInorderSuccessor(){
    bstNode* root=createBstForTest();
    bstNode* successor=findInorderSuccessor(root,root);
    if(successor==NULL)printf("Not found\n");
    else printf("Predecessor : %d \n",successor->data);
}

void testInsertAnElementRecursive(){
     bstNode* root=createBstForTest();
     insertAnElementRecursive(root,16);
     traverseInorder(root);
     printf("\n");
}

void testInsertAnElementIterative(){
     bstNode* root=createBstForTest();
     insertAnElementIterative(root,16);
     traverseInorder(root);
     printf("\n");
}

void testDeleteRecursive(){
    bstNode* root=createBstForTest();
    printf("Before Delete :   ");
    traverseInorder(root);
    printf("\n");
    deleteRecursive(root,4);
    printf("After   Delete :   ");
    traverseInorder(root);
    printf("\n");
}

void testDeleteIterative(){
    bstNode* root=createBstForTest();
    printf("Before Delete :   ");
    traverseInorder(root);
    printf("\n");
    deleteIterative(root,7);
    printf("After   Delete :   ");
    traverseInorder(root);
    printf("\n");
}

void testBuildBinarySearchTree(){
    int element[]={11,2,6,4,5,16,13,8,19,0};
    int length=10;
    bstNode* root=buildBinarySearchTree(element,length);
    traverseInorder(root);
    printf("\n");
}

void testLowestCommonAncestorIterative(){
    int element[]={11,2,6,4,5,16,13,8,19,0};
    int length=10;
    bstNode* root=buildBinarySearchTree(element,length);
    printf("Inorder : ");
    traverseInorder(root);
    printf("\n");
    printf("Preorder : ");
    traversePreorder(root);
    printf("\n");
    bstNode* ancestor=NULL;
    ancestor=lowestCommonAncestorIterative(root,0,19);
    printf("Ancestor (%d,%d): %d\n",0,19,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorIterative(root,5,13);
    printf("Ancestor (%d,%d): %d\n",5,13,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorIterative(root,5,8);
    printf("Ancestor (%d,%d): %d\n",5,8,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorIterative(root,4,6);
    printf("Ancestor (%d,%d): %d\n",4,6,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorIterative(root,16,19);
    printf("Ancestor (%d,%d): %d\n",16,19,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorIterative(root,0,21);
    printf("Ancestor (%d,%d): %d\n",0,21,(ancestor!=NULL)?ancestor->data:-1);
   }
   
   
   void testLowestCommonAncestorRecursive(){
    int element[]={11,2,6,4,5,16,13,8,19,0};
    int length=10;
    bstNode* root=buildBinarySearchTree(element,length);
    printf("Inorder : ");
    traverseInorder(root);
    printf("\n");
    printf("Preorder : ");
    traversePreorder(root);
    printf("\n");
    bstNode* ancestor=NULL;
    ancestor=lowestCommonAncestorRecursiveInterface(root,0,19);
    printf("Ancestor (%d,%d): %d\n",0,19,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorRecursiveInterface(root,5,13);
    printf("Ancestor (%d,%d): %d\n",5,13,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorRecursiveInterface(root,5,8);
    printf("Ancestor (%d,%d): %d\n",5,8,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorRecursiveInterface(root,4,6);
    printf("Ancestor (%d,%d): %d\n",4,6,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorRecursiveInterface(root,16,19);
    printf("Ancestor (%d,%d): %d\n",16,19,(ancestor!=NULL)?ancestor->data:-1);
    ancestor=lowestCommonAncestorRecursiveInterface(root,0,21);
    printf("Ancestor (%d,%d): %d\n",0,21,(ancestor!=NULL)?ancestor->data:-1);
}

void testIsBSTMaxMinStrategy(){
    int element[]={11,2,6,4,5,16,13,8,19,0};
    int length=10;
    bstNode* root=buildBinarySearchTree(element,length);
    printf("Inorder : ");
    traverseInorder(root);
    printf("\n");
    printf("Preorder : ");
    traversePreorder(root);
    printf("\n");
    printf("Is Binary Search Tree : %d\n",isBSTMaxMinStrategy(root));
    root->data=1;
    printf("Is Binary Search Tree : %d\n",isBSTMaxMinStrategy(root));
}

void testIsBSTSingleScanStrategy(){
    int element[]={11,2,6,4,5,16,13,8,19,0};
    int length=10;
    bstNode* root=buildBinarySearchTree(element,length);
    printf("Inorder : ");
    traverseInorder(root);
    printf("\n");
    printf("Preorder : ");
    traversePreorder(root);
    printf("\n");
    printf("Is Binary Search Tree : %d\n",isBSTSingleScanStrategy(root,-1000,1000));
    root->data=1;
    printf("Is Binary Search Tree : %d\n",isBSTSingleScanStrategy(root,-1000,1000));
}

void testIsBSTinorderStrategy(){
    int element[]={11,2,6,4,5,16,13,8,19,0};
    int length=10;
    bstNode* root=buildBinarySearchTree(element,length);
    printf("Inorder : ");
    traverseInorder(root);
    printf("\n");
    printf("Preorder : ");
    traversePreorder(root);
    printf("\n");
    printf("Is Binary Search Tree : %d\n",isBstInorderStartegy(root,-1000));
    root->data=1;
    printf("Is Binary Search Tree : %d\n",isBstInorderStartegy(root,-1000));
}


void testConvertBinarySearchTreeToCircularDoublyLinkedList(){
    int element[]={11,16,2};
    int length=3;
    bstNode* root=buildBinarySearchTree(element,length);
    printf("Inorder : ");
    traverseInorder(root);
    printf("\n");
    printf("Preorder : ");
    traversePreorder(root);
    printf("\n");
    
    bstNode* head=convertBinarySearchTreeToCircularDoublyLinkedList(root);
    bstNode* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->right;
    }while(temp!=head);
    printf("\n");
}


void testConvertBinarySearchTreeToCircularDoublyLinkedListDynamicProgramming(){
    int element[]={11,16,2};
    int length=3;
    bstNode* root=buildBinarySearchTree(element,length);
    printf("Inorder : ");
    traverseInorder(root);
    printf("\n");
    printf("Preorder : ");
    traversePreorder(root);
    printf("\n");
    
    bstNode* head=bstToCdllDp(root);
    bstNode* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->right;
    }while(temp!=head);
    printf("\n");
}


void testConvertDoubliLinkedListToBinarySearchTree(){
    bstNode* head=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode1=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode2=(bstNode*)malloc(sizeof(bstNode));
    
    newNode2->data=16;
    newNode2->right=NULL;
    newNode2->left=newNode1;
    
    newNode1->data=11;
    newNode1->right=newNode2;
    newNode1->left=head;
    
    head->data=2;
    head->left=NULL;
    head->right=newNode1;
    
     bstNode* root=convertDllToBst(head);
     printf("Inorder : ");
     traverseInorder(root);
     printf("\n");
     printf("Pre order : ");
     traversePreorder(root);
     printf("\n");
}

void testConvertSortedArrayToBst(){
    int array[]={1,2,3};
    bstNode* root=convertSortedArrayToBst(array,0,2);
     printf("Inorder : ");
     traverseInorder(root);
     printf("\n");
     printf("Pre order : ");
     traversePreorder(root);
     printf("\n");
}


