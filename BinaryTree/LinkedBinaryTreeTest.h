#include"LinkedBinaryTree.h"

void testCreateBinaryTree(){
    	node* binaryTree=createBinaryTree(7);
}

void testPreOrderTraversalRecursive(){
    node* root=createBinaryTree(7);
    printf("PreOrder : ");
    preOrderTraversalRecursive(root);
    printf("\n");
}

void testPreOrderTraversalIterative(){
    node* root=createBinaryTree(7);
    printf("PreOrder : ");
    preOrderTraversalIterative(root);
    printf("\n");
}

void testInOrderTraversalRecursive(){
    node* root=createBinaryTree(7);
    printf("InOrder : ");
   inOrderTraversalRecursive(root);
    printf("\n");
}

void testInOrderTraversalIterative(){
    node* root=createBinaryTree(7);
    printf("InOrder : ");
    inOrderTraversalIterative(root);
    printf("\n");
}

void testPostOrderTraversalRecursive(){
    node* root=createBinaryTree(7);
    printf("PostOrder : ");
    postOrderTraversalRecursive(root);
    printf("\n");
}

void testPostOrderTraversalIterative(){
    node* root=createBinaryTree(7);
    printf("PostOrder : ");
    postOrderTraversalIterative(root);
    printf("\n");
}

void testLevelOrderTraversalIteartive(){
    node* root=createBinaryTree(7);
    printf("Level Order : ");
    levelOrderTraversalIteartive(root);
    printf("\n");
}

void testFindMaxInBinaryTree(){
    node* root=createBinaryTree(7);
    printf("Max : %d\n",findMaxInBinaryTree(root));
}

void testFindMaxInBinaryTreeIterative(){
    node* root=createBinaryTree(7);
    printf("Max : %d\n",findMaxInBinaryTreeIterative(root));
}

void testSearchInBinaryTreeRecursive(){
    node* root=createBinaryTree(7);
    int data=7;
    node* found=NULL;
    printf("Trying to find %d\n",data);
    found=searchInBinaryTreeRecursive(root,data);
    (found==NULL)?printf("Not found\n"):printf("Found : %u->%d\n",found,found->data);
    data=10;
    printf("Trying to find %d\n",data);
    found=searchInBinaryTreeRecursive(root,data);
    (found==NULL)?printf("Not found\n"):printf("Found : %u->%d\n",found,found->data);
}


void testSearchInBinaryTreeIterative(){
    node* root=createBinaryTree(7);
    int data=7;
    node* found=NULL;
    printf("Trying to find %d\n",data);
    found=searchInBinaryTreeIterative(root,data);
    (found==NULL)?printf("Not found\n"):printf("Found : %u->%d\n",found,found->data);
    data=10;
    printf("Trying to find %d\n",data);
    found=searchInBinaryTreeIterative(root,data);
    (found==NULL)?printf("Not found\n"):printf("Found : %u->%d\n",found,found->data);
}

void testInsertNodeIntoBinaryTree(){
    node* root=createBinaryTree(7);
    printf("\n");
    levelOrderTraversalIteartive(root);
 printf("\n");   
 insertNodeIntoBinaryTree(root,8);
    levelOrderTraversalIteartive(root);
     printf("\n");
}

void testSizeOfBinaryTreeRecursive(){
    node* root=createBinaryTree(7);
    printf("\n");
    levelOrderTraversalIteartive(root);
    printf("\n");
    printf("Size : %d ",sizeOfBinaryTreeRecursive(root));
}

void testSizeOfBinaryTreeIterative(){
    node* root=createBinaryTree(7);
    printf("\n");
    levelOrderTraversalIteartive(root);
    printf("\n");
    printf("Size : %d ",sizeOfBinaryTreeIterative(root));
}

void testLevelOrderTraversalInReverse(){
    node* root=createBinaryTree(7);
    levelOrderTraversalInReverse(root);
}

void testDeleteBinaryTree(){
    node* root=createBinaryTree(7);
    deleteBinaryTree(root);
}

void testHeightOfBinaryTreeRecursive(){
    node* root=createBinaryTree(7);
    printf("Height : %d\n",heightOfBinaryTreeRecursive(root));
}

void testHeightOfBinaryTreeIterative(){
    node* root=createBinaryTree(9);
    printf("Height : %d\n",heightOfBinaryTreeIterative(root));
}

void testDeepestNodeInBinaryTree(){
    node* root=createBinaryTree(9);
    node* deepestNode=deepestNodeInBinaryTree(root);
    printf("Deepest Node : %d\n",deepestNode->data);
}

void testNoOfLeafNodesInBinaryTree(){
    node* root=createBinaryTree(7);
    printf("No Of Leaf Nodes : %d ",noOfLeafNodesInBinaryTree(root));
}

void testNoOfFullNodesInBinaryTree(){
    node* root=createBinaryTree(7);
    printf("No Of Full Nodes : %d ",noOfFullNodesInBinaryTree(root));
}

void testNoOfHalfNodesInBinaryTree(){
    node* root=createBinaryTree(5);
    printf("No Of Half Nodes : %d ",noOfHalfNodesInBinaryTree(root));
}

void testIsStructurallyIdentical(){
    node* root1=createBinaryTree(7);
    node* root2=createBinaryTree(7);
    node* root3=createBinaryTree(5);
    
    printf("Is Structurally Identical : %d\n",isStructurallyIdentical(root1,root2));
    printf("Is Structurally Identical : %d\n",isStructurallyIdentical(root1,root3));
    
}

void testDiameterOfBinaryTree(){
    node* root1=createBinaryTree(7);
    int ptr=0;
    printf("return  : %d  ptr : %d \n",diameterOfBinaryTree(root1,&ptr));
}

void testMaxSumLevelOfBinaryTree(){
    node* root1=createBinaryTree(7);
    printf("Max Sum Level  : %d \n",maxSumLevelOfBinaryTree(root1));

   root1=createBinaryTree(10);
    printf("Max Sum Level  : %d \n",maxSumLevelOfBinaryTree(root1));
    
       root1=createBinaryTree(1);
    printf("Max Sum Level  : %d \n",maxSumLevelOfBinaryTree(root1));

}

void testPrintAllRootToLeafPath(){
    node* root1=createBinaryTree(20);
    int path [30];
    printAllRootToLeafPath(root1,0,path);
}

void testHasPathSum(){
    node* root1=createBinaryTree(7);
    printf("Has Path Sum : %d\n",hasPathSum(root1,33));
    printf("Has Path Sum : %d\n",hasPathSum(root1,11));
}

void  testSumOfAllElements(){
    node* root1=createBinaryTree(7);
    
    printf("Sum of all elements : %d\n",sumOfAllElements(root1));

}

void  testSumOfAllElementsIterative(){
    node* root1=createBinaryTree(7);
    printf("Sum of all elements : %d\n",sumOfAllElementsIterative(root1));

}

void testMirrorABinaryTreeRecursive(){
        node* root=createBinaryTree(7);
        levelOrderTraversalIteartive(root);
        printf("\n");
        root=mirrorABinaryTreeRecursive(root);
        levelOrderTraversalIteartive(root);
        printf("\n");
}

void testAreMirrors(){
    node * root1=createBinaryTree(7);
    node*  root2=createBinaryTree(7);
    printf("Are mirrors : %d\n",areMirrors(root1,root2));
    root2=mirrorABinaryTreeRecursive(root2);
    printf("Are mirrors : %d\n",areMirrors(root1,root2));
}

void testLowestCommonAncestor(){
    node* root=createBinaryTree(7);
    int a=0;
    int b=0;
    node* lca=lowestCommonAncestor(root,4,5,&a,&b);
    if(a==1&&b==1){
        printf("LCA found : %d\n",lca->data);
    }
    else{
        printf("LCA not found\n");
    }
    
    a=0;b=0;
    lca=lowestCommonAncestor(root,4,2,&a,&b);
    if(a==1&&b==1){
        printf("LCA found : %d\n",lca->data);
    }
    else{
        printf("LCA not found\n");
    }
    
    a=0;b=0;
    lca=lowestCommonAncestor(root,4,10,&a,&b);
    if(a==1&&b==1){
        printf("LCA found : %d\n",lca->data);
    }
    else{
        printf("LCA not found\n");
    }
}


void testCreateBinaryTreeFromInorderAndPreOrderArray(){
    int in[]={4,2,5,1,6,3,7};
    int pre[]={1,2,4,5,3,6,7};
    int pre1=0;
    printf("Going to create tree\n");
    node* root=createBinaryTreeFromInorderAndPreOrderArray(pre,in,0,6,&pre1);
    printf("Created tree .. Below is the level order traversal of tree\n");
    levelOrderTraversalIteartive(root);
    printf("\n");
}

void testPrintAllAcestorOfANode(){
    node* root=createBinaryTree(7);
    printAllAcestorOfANode(root,4);
    printf("\n");
    printAllAcestorOfANode(root,7);
    printf("\n");
}

void testZigZagTraversal(){
    node* root=createBinaryTree(7);
    printf("\n");
    zigZagTraversal(root);
    printf("\n");
}

void testCreateBinaryTreeWithPreOrder(){
    int A[]={'I','L','I','L','L'};
    int i=0;
    node* root=createBinaryTreeWithPreOrder(A,&i);
    preOrderTraversalRecursive(root);
    printf("\n");
}

void testFillSibling(){
    /*struct BinarySiblingNode* root=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode*));
    root->left=NULL;
    root->right=NULL;
    root->sibling=NULL;
    struct BinarySiblingNode* newNode1=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode*));
    newNode1->left=NULL;
    newNode1->right=NULL;
    newNode1->sibling=NULL;
    struct BinarySiblingNode* newNode2=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode*));
    newNode2->left=NULL;
    newNode2->right=NULL;
    newNode2->sibling=NULL;
    struct BinarySiblingNode* newNode3=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode*));
    newNode3->left=NULL;
    newNode3->right=NULL;
    newNode3->sibling=NULL;
    struct BinarySiblingNode* newNode4=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode*));
    newNode4->left=NULL;
    newNode4->right=NULL;
    newNode4->sibling=NULL; 
   struct BinarySiblingNode* newNode5=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode*));
    newNode5->left=NULL;
    newNode5->right=NULL;
    newNode5->sibling=NULL;
    struct BinarySiblingNode* newNode6=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode*));
    newNode6->left=NULL;
    newNode6->right=NULL;
    newNode6->sibling=NULL;
    
    root->data=1;
    newNode1->data=2;
    newNode2->data=3;
    newNode3->data=4;
    newNode4->data=5;
    newNode5->data=6;
    newNode6->data=7;
    
    root->left=newNode1;
    root->right=newNode2;
    newNode1->left=newNode3;
    newNode1->right=newNode4;
    newNode2->left=newNode5;
    newNode2->right=newNode6;

    fillSibling(root);*/
}

void testIsIsomorphicBinaryTree(){
    node* root1=createBinaryTree(7);
    node* root2=createBinaryTree(7);
    node* root3=createBinaryTree(5);
    printf("Is isomorphic : %d\n",isIsomorphicBinaryTree(root1,root2));
    printf("Is isomorphic : %d\n",isIsomorphicBinaryTree(root1,root3));
}

void testIsQuasiIsomorphicBinaryTree(){
    node* root1=createBinaryTree(7);
    node* root2=createBinaryTree(7);
    node* root3=createBinaryTree(5);
    printf("Is Quasi isomorphic : %d\n",isQuasiIsomorphicBinaryTree(root1,root2));
    printf("Is Quasi isomorphic : %d\n",isQuasiIsomorphicBinaryTree(root1,root3));
}