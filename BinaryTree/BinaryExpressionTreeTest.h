#include"BinaryExpressionTree.h"

void testCreateExpressionTree(){
    int postfix[]={'A','B','*','C','+'};
    expressionNode* root=createExpressionTree(postfix,5);
    
    inOrderTraversalRecursive(root);
}