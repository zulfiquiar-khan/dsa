#include"ThreadedBinaryTree.h"

void testCreateInorderThreadedBinaryTree(){
    node* root=createBinaryTree(7);
    threaded_node* root1=createInorderThreadedBinaryTree(root);

}

void testFindInorderSuccesor(){
    node* root=createBinaryTree(7);
    threaded_node* root1=createInorderThreadedBinaryTree(root);
    threaded_node* succesor=findInorderSuccesor(root1->left);
    printf("Successor : %u->%d \n",succesor,succesor->data);
}