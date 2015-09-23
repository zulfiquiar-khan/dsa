#include"ThreadedBinaryTree.h"

void testCreateInorderThreadedBinaryTree(){
    node* root=createBinaryTree(7);
    threaded_node* root1=createInorderThreadedBinaryTree(root);
    printf("Created Threaded Binary Tree\n");
}