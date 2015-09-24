#include"ThreadedBinaryTree.h"

void testCreateInorderThreadedBinaryTree(){
    node* root=createBinaryTree(7);
    threaded_node* root1=createInorderThreadedBinaryTree(root);

}

void testFindInorderSuccesor(){
    node* root=createBinaryTree(7);
    threaded_node* root1=createInorderThreadedBinaryTree(root);
    threaded_node* succesor=findInorderSuccesor(root1->left);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left,root1->left->data,succesor,succesor->data);
    succesor=findInorderSuccesor(root1->left->left);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->left,root1->left->left->data,succesor,succesor->data);
    succesor=findInorderSuccesor(root1->left->right);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->right,root1->left->right->data,succesor,succesor->data);
    succesor=findInorderSuccesor(root1->left->left->left);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->left->left,root1->left->left->left->data,succesor,succesor->data);
    succesor=findInorderSuccesor(root1->left->left->right);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->left->right,root1->left->left->right->data,succesor,succesor->data);
    succesor=findInorderSuccesor(root1->left->right->left);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->right->left,root1->left->right->left->data,succesor,succesor->data);
    succesor=findInorderSuccesor(root1->left->right->right);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->right->right,root1->left->right->right->data,succesor,succesor->data);

}

void testInorderTraversal(){
    node* root=createBinaryTree(7);
    threaded_node* root1=createInorderThreadedBinaryTree(root);
    inorderTraversal(root1);
}

void testFindPreorderSuccesor(){
    node* root=createBinaryTree(7);
    threaded_node* root1=createInorderThreadedBinaryTree(root);
    threaded_node* succesor=findPreOrderSuccesor(root1->left);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left,root1->left->data,succesor,succesor->data);
    succesor=findPreOrderSuccesor(root1->left->left);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->left,root1->left->left->data,succesor,succesor->data);
    succesor=findPreOrderSuccesor(root1->left->right);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->right,root1->left->right->data,succesor,succesor->data);
    succesor=findPreOrderSuccesor(root1->left->left->left);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->left->left,root1->left->left->left->data,succesor,succesor->data);
    succesor=findPreOrderSuccesor(root1->left->left->right);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->left->right,root1->left->left->right->data,succesor,succesor->data);
    succesor=findPreOrderSuccesor(root1->left->right->left);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->right->left,root1->left->right->left->data,succesor,succesor->data);
    succesor=findPreOrderSuccesor(root1->left->right->right);
    printf("Node : %u->%d  Successor : %u->%d \n",root1->left->right->right,root1->left->right->right->data,succesor,succesor->data);

}

void testPreOrderTraversal(){
    node* root=createBinaryTree(7);
    threaded_node* root1=createInorderThreadedBinaryTree(root);
    preOrderTraversal(root1);
}